# 알려진 문제 (미해결, 추후 처리 예정)

## 1. 부팅 시 "BOT failed" / ITEM_CHECKITEMTABLE(-1) / MAP_addNewObj 오류 (데이터 누락)

**증상**: `gmsv64` 부팅 중 `LoadAllbluesLUA("mylua")` 단계(main.c "초기화 LUA 스크립트..." 직후)에서
아래 오류들이 한 번에 몰아서 발생 (약 65건):

```
********[No Enemy Id]BOT failed.
ITEM_CHECKITEMTABLE() number:-1 ITEM_tblen:140001 !!
Can't Get ItemTable for:-1! - itembase.c:265
Can't makeItem for itemid:-1!!
object.c:69 MAP_addNewObj error
```

**원인**: `mylua/` 하위 어떤 스크립트가 boot 시점(top-level 코드)에서 `char.CreateBot(...)`류의
함수(내부적으로 `mylua/charbase.c`의 봇 생성 로직, ~3078번째 줄 `[No Enemy Id]BOT failed`)를
호출하는데, 이때 넘기는 `enemy.txt`의 ID가 현재 우리 데이터셋에 없어서 실패. 이게 연쇄적으로
아이템/오브젝트 생성 실패로 이어짐.

**코드 버그 아님** — 데이터 누락 문제. 나중에 외부 데이터(펫/아이템/enemy.txt) 보강 작업 때
같이 해결 예정.

**다음에 할 일**: 정확히 어느 `.lua` 파일이 어떤 enemy ID로 `CreateBot`을 호출하는지 특정
(현재는 C 쪽 원인 함수만 확인, 호출부 lua 스크립트는 미확인 — mylua/ 전체에서
`CreateBot` 계열 호출부 검색 필요).

**확인 완료 사항 (참고)**:
- 이 오류는 **부팅 시 1회성**이며, 정상 틱 루프 진입 후에는 재발하지 않음 (반복적 런타임 문제 아님).
- Lua 스크립트 자체의 문법 오류(`attcteffect.lua`, `Accompany.lua`)와는 무관한 별개 문제 —
  그 둘은 이미 수정 완료 (커밋 `ae8719a`).

---

## 2. 외부 데이터(펫 도감) 미완성 항목 — 나중으로 미룸

- 첨부된 `enemybase1.txt` 순서 기준, **714종 중 401종이 아직 미이식** (커밋 `2f384f8` 시점)
- 반대로 현재 데이터에는 있지만 첨부 파일 순서엔 없는 240종은 파일 끝에 별도 보관 중
- 진행 방식은 사용자 확인 후 진행 예정 (일단 보류 상태)
