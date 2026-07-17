function ShowDlg(_meindex, _talkerindex, _page,_transdata,_seqno)
	local _maxpage = math.ceil(table.getn(_transdata) / 7);
	local count = 0
	for i = 1, table.getn(trans_quest) do
		if npc.CheckEvent(_talkerindex, trans_quest[i]) == 1 then
			count = count + 1
		end
	end
	
	local token = "1퀘스트 목록 :"..count.."\n";
	local topselect = (_page-_seqno) * 7;
	for i = 1, 7 do
		if (i + topselect) > table.getn(_transdata) then
			break;
		end
		local done =  npc.CheckEvent(_talkerindex, _transdata[i + topselect][1])
		if done == 1 then
			token = token .. string.format("%-32s 완료\n", _transdata[i + topselect][2]);
		else
			token = token .. string.format("%-32s 미완료\n", _transdata[i + topselect][2]);
		end
	end
	local mypage = _page - _seqno + 1;
	if _maxpage == 1 then
		button = 8;
	elseif mypage == 1 and mypage < _maxpage then
		button = 8+32
	elseif mypage > 1 and mypage < _maxpage then
		button = 8+16+32;
	elseif mypage == _maxpage then
		button = 8+16;
	end
	lssproto.windows(_talkerindex, 2, button, _page, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
end


function TalkToMe(charaindex)
	local token = "10\n"
				.."       CHAOSE\n"
				.."\n"
				.."안녕하세요 카오스 서버 퀘스트 도우미입니다A\n"
				.."해당 퀘스트를 누르면 웹페이지로 이동합니다\n"
				.."\n"
				.."[C] 표시가 되어있는 퀘스트는 반복이 불가능합니다.";
				print(token);
	lssproto.windows(charaindex, 2, 1, 0, char.getWorkInt( npcindex, "WORKOBJINDEX"), token);
end

function Talked(_meindex, _talkerindex, _szMes, _color )
	local token = "10\n"
				.."       CHAOS\n"
				.."\n"
				.."안녕하세요 카오스서버 퀘스트 도우미입니다\n"
				.."해당 퀘스트를 누르면 웹페이지로 이동됩니다\n"
				.."\n"
				.."[C] 표시가 되어있는 퀘스트는 반복이 불가능합니다.";
	lssproto.windows(_talkerindex, 2, 1, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
end

function WindowTalked (_meindex, _talkerindex, _seqno, _select, _data)
	print(_meindex, _talkerindex, _seqno, _select, _data)
	if _seqno == 0 then
		if _select == 1 then
			ShowDlg(_meindex, _talkerindex, 100,QuestList,100);
		end
	elseif _seqno >= 100 and _seqno < 200 then
		if _select == 0 then
			local num = other.atoi(_data) + ((_seqno - 100) * 7);
			if num > table.getn(QuestList) then
				return ;
			end
			local token = "10\n"
				.."       CHAOS\n"
				.."\n"
				.."확인을 누르면 해당 정보 웹사이트로 이동합니다\n"
				.."확인 또는 ESC 키를눌러주세요\n"
				.."\n"
				.."[C] 표시가 되어있는 퀘스트는 반복이 불가능합니다.";
			lssproto.windows(_talkerindex, 2, 3, 200 + num, char.getWorkInt( _meindex, "WORKOBJINDEX"), token)
		elseif _select == 8 then
			TalkToMe(_talkerindex);
		elseif _select == 16 then
			ShowDlg(_meindex, _talkerindex, _seqno - 1, QuestList,100);
		elseif _select == 32 then
			ShowDlg(_meindex, _talkerindex, _seqno + 1, QuestList,100);
		end
		
	elseif _seqno >= 200 then
		if _select == 1 then
			local num = _seqno - 200;
			print("\n\n"..num.."\n\n");
			lssproto.SaMenu(_talkerindex, QuestList[num][3]);
		elseif _select == 2 then
			local _maxpage = math.ceil((_seqno - 200) / 7) - 1;
			ShowDlg(_meindex, _talkerindex, 100 + _maxpage, QuestList,100);
		end
	end
end

function Create(_name, _metamo, _floor, _x, _y, _dir)
	npcindex = npc.CreateNpc(_name, _metamo, _floor, _x, _y, _dir);
	char.setFunctionPointer(npcindex, "TALKEDFUNC", "Talked", "");
	char.setFunctionPointer(npcindex, "WINDOWTALKEDFUNC", "WindowTalked", "");
end

function mydata()
	QuestList = {
				 {4,  "1, [C]성인식",	"https://cafe.daum.net/CHAOS./CaeJ/1"}
				,{41,  "2, [C]미쥬",	"https://cafe.daum.net/CHAOS./CaeF/1"}
				,{45,  "3, [C]일란",	"https://cafe.daum.net/CHAOS./CaeF/2"}
				,{52,  "4, [C]유나",	"https://cafe.daum.net/CHAOS./CaeF/3"}
				,{99,  "5, 비실이",	"https://cafe.daum.net/CHAOS./CaeF/7"}
				,{99,  "6, 달의 반지",	"https://cafe.daum.net/CHAOS./CaeF/8"}
				,{99,  "7, A코스",	"https://cafe.daum.net/CHAOS./CaeF/4"}
				,{99,  "8, 갈푸스 퀘스트",	"https://cafe.daum.net/CHAOS./CaeF/5"}
				,{99,  "9, 얼음굴 퀘스트",	"https://cafe.daum.net/CHAOS./CaeF/6"}
				,{99, "10, 제시카 퀘스트",	"https://cafe.daum.net/CHAOS./CaeF/9"}
				,{11, "11,비어있음",	""}
				,{12, "12,비어있음",	""}
				,{13, "13,비어있음",	""}
				,{14, "14,비어있음",	""}
				,{15, "15,비어있음",	""}
				,{16, "16,비어있음",	""}
				,{17, "17,비어있음",	""}
				,{18, "18,비어있음",	""}
				,{19, "19,비어있음",	""}
				,{20, "20,비어있음",	""}
				,{21, "21,비어있음",	""}
				,{22, "22,비어있음",	""}
				,{23, "23,비어있음",	""}
				,{24, "24,비어있음",	""}
				,{25, "25,비어있음",	""}
				,{26, "26,비어있음",	""}
				,{27, "27,비어있음",	""}
				,{28, "28,비어있음",	""}
				,{29, "29,비어있음",	""}
				,{30, "30,비어있음",	""}
			};
			
	trans_quest = { 1,2,3,4,8,9,12,15,16,17,20,26,28,31,34,35,36,38,45,47 };
				
	npcdata = {"quest NPC",100000,777,37,31,6,"TieXin"};								
end

function main()
	mydata();
	Create(npcdata[1], npcdata[2], npcdata[3], npcdata[4], npcdata[5], npcdata[6]);
end

