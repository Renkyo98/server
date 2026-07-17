function ShowDlg(_meindex, _talkerindex, _page,_transdata,_seqno)
	local _maxpage = math.ceil(table.getn(_transdata) / 7);
	local token = "1\n\n";
	local topselect = (_page-_seqno) * 7;
	for i = 1, 7 do
		if (i + topselect) > table.getn(_transdata) then
			break;
		end
		if _transdata[i + topselect][7] > 0 then
			token = token .. string.format("%-25s %-18s %s S\n", _transdata[i + topselect][1], _transdata[i + topselect][9], _transdata[i + topselect][8]);
		else
			token = token .. string.format("%-25s Lv. %-14s %s S\n", _transdata[i + topselect][1], _transdata[i + topselect][6], _transdata[i + topselect][8]);
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
	lssproto.windows(_talkerindex, 202, button, _page, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
end


function FreeTieXin(charaindex)
	local token = "3\n"
				.."\n"
				.."    [style c=2 s=20]CHAOS[/style]\n"
				.."\n"
				.." 1. 사냥터[下]\n"
				.." 2. 사냥터[上]\n"
				.." 3. 퀘스트\n"
				.." 4. 특수이동";
	lssproto.windows(charaindex, 201, 8, 0, char.getWorkInt( npcindex, "WORKOBJINDEX"), token);
end

--NPC뚤뺐慤숭(NPC乞多)
function Talked(_meindex, _talkerindex, _szMes, _color )
	local token = "3\n"
				.."\n"
				.."    [style c=2 s=20]CHAOS[/style]\n"
				.."\n"
				.." 1. 사냥터[下]\n"
				.." 2. 사냥터[上]\n"
				.." 3. 퀘스트\n"
				.." 4. 특수이동";
				
	lssproto.windows(_talkerindex, 201, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
end

function ShowPetType(_meindex, _talkerindex, _page)
	local _maxpage = math.ceil(table.getn(PetList) / 7);
	local topselect = (_page-10) * 7;

	local token = "1 TELEPORT MAP:\n";
	for i = 1, 7 do
		if (i + topselect) > table.getn(PetList) then
			break;
		end
		token = token .. string.format("  %s\n", PetList[i + topselect][1]);
	end
			
	local mypage = _page - 10 + 1;
	if _maxpage == 1 then
		button = 8;
	elseif mypage == 1 and mypage < _maxpage then
		button = 8+32
	elseif mypage > 1 and mypage < _maxpage then
		button = 8+16+32;
	elseif mypage == _maxpage then
		button = 8+16;
	end
	lssproto.windows(_talkerindex, 202, button, _page, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
end

--NPC눗왯慤숭(NPC乞多)
function WindowTalked (_meindex, _talkerindex, _seqno, _select, _data)
	print(_meindex, _talkerindex, _seqno, _select, _data)
	if _seqno == 0 then
		local setid = other.atoi(_data);
		if setid == 1 then
			ShowDlg(_meindex, _talkerindex, 100,LianJiList,100);
		elseif setid == 2 then
			ShowDlg(_meindex, _talkerindex, 300,ZhuanYList,300);
		elseif setid == 3 then
			ShowDlg(_meindex, _talkerindex, 200,ChengList,200);
		elseif setid == 4 then
			ShowDlg(_meindex, _talkerindex, 400,List4,400);
		end
	elseif _seqno >= 100 and _seqno < 200 then
		if _select == 0 then
			local num = other.atoi(_data) + ((_seqno - 100) * 7);
			if num > table.getn(LianJiList) then--렝岺淚놔
				return ;
			end
			
			local price = LianJiList[num][8]
			local cGold = char.getInt(_talkerindex, "GOLD");
			if price > cGold then
				char.TalkToCli(_talkerindex, _meindex, "돈이 부족합니다!", 6);
				return;
			end
			char.setInt(_talkerindex, "GOLD", cGold - price )
			char.Updata(_talkerindex, "GOLD" )
			
			if LianJiList[num][5] == false then
				if char.getWorkInt(_talkerindex,"WORKPARTYMODE") > 0 then
					char.TalkToCli(_talkerindex, _meindex, "파티상태로는 이용 할 수 없습니다!", 6);
					return;
				end
			end
			if LianJiList[num][6] > 0 then
				if char.getInt(_talkerindex, "LV") < LianJiList[num][6] then
				char.TalkToCli(_talkerindex, _meindex, "레벨이 부족합니다 ".. LianJiList[num][6], 6);
				return;
				end
			end
			
			if LianJiList[num][7] > 0 then  -- 리스트 값이 0보다 클때
				if npc.CheckEvent(_talkerindex, LianJiList[num][7]) == 0 then -- 리스트 값의 이벤트를 체크함 0일때 리턴
					char.TalkToCli(_talkerindex, _meindex, "퀘스트 조건이 부족합니다 ".. LianJiList[num][9], 6);
					return;
				end
			end
			
			char.AllWarpToSpecificPoint(_talkerindex, LianJiList[num][2], LianJiList[num][3], LianJiList[num][4]);
		elseif _select == 16 then
			ShowDlg(_meindex, _talkerindex, _seqno - 1, LianJiList,100);
		elseif _select == 32 then
			ShowDlg(_meindex, _talkerindex, _seqno + 1, LianJiList,100);
		end
	elseif _seqno >= 200 and _seqno < 300 then
		if _select == 0 then
			local num = other.atoi(_data) + ((_seqno - 200) * 7);
			if num > table.getn(ChengList) then--렝岺淚놔
				return ;
			end
			
			local price = ChengList[num][8]
			local cGold = char.getInt(_talkerindex, "GOLD");
			if price > cGold then
				char.TalkToCli(_talkerindex, _meindex, "돈이 부족합니다!", 6);
				return;
			end
			char.setInt(_talkerindex, "GOLD", cGold - price )
			char.Updata(_talkerindex, "GOLD" )
			
			if ChengList[num][5] == false then
				if char.getWorkInt(_talkerindex,"WORKPARTYMODE") > 0 then
					char.TalkToCli(_talkerindex, _meindex, "파티상태로는 이용 할 수 없습니다!", 6);
					return;
				end
			end
			if ChengList[num][6] > 0 then
				if char.getInt(_talkerindex, "LV") < ChengList[num][6] then
				char.TalkToCli(_talkerindex, _meindex, "레벨이 부족합니다 ".. ChengList[num][6], 6);
				return;
				end
			end
			
			if ChengList[num][7] > 0 then  -- 리스트 값이 0보다 클때
				if npc.CheckEvent(_talkerindex, ChengList[num][7]) == 0 then -- 리스트 값의 이벤트를 체크함 0일때 리턴
					char.TalkToCli(_talkerindex, _meindex, "퀘스트 조건이 부족합니다 ".. ChengList[num][9], 6);
				return;
				end
			end
				
			char.AllWarpToSpecificPoint(_talkerindex, ChengList[num][2], ChengList[num][3], ChengList[num][4]);
		elseif _select == 16 then
			ShowDlg(_meindex, _talkerindex, _seqno - 1, ChengList,200);
		elseif _select == 32 then
			ShowDlg(_meindex, _talkerindex, _seqno + 1, ChengList,200);
		end
	elseif _seqno >= 300 and _seqno < 400 then
		if _select == 0 then
			local num = other.atoi(_data) + ((_seqno - 300) * 7);
			if num > table.getn(ZhuanYList) then--렝岺淚놔
				return ;
			end
			
			local price = ZhuanYList[num][8]
			local cGold = char.getInt(_talkerindex, "GOLD");
			if price > cGold then
				char.TalkToCli(_talkerindex, _meindex, "돈이 부족합니다!", 6);
				return;
			end
			char.setInt(_talkerindex, "GOLD", cGold - price )
			char.Updata(_talkerindex, "GOLD" )
			
			if ZhuanYList[num][5] == false then
				if char.getWorkInt(_talkerindex,"WORKPARTYMODE") > 0 then
					char.TalkToCli(_talkerindex, _meindex, "파티상태로는 이용 할 수 없습니다!", 6);
					return;
				end
			end
			if ZhuanYList[num][6] > 0 then
				if char.getInt(_talkerindex, "LV") < ZhuanYList[num][6] then
				char.TalkToCli(_talkerindex, _meindex, "레벨이 부족합니다 ".. ZhuanYList[num][6], 6);
				return;
				end
			end
			--npc.EvEnd(charaindex, evendlist182[i])
			--if npc.EvEnd ~= ZhuanYList[num][7] then
			
			if ZhuanYList[num][7] > 0 then  -- 리스트 값이 0보다 클때
				if npc.CheckEvent(_talkerindex, ZhuanYList[num][7]) == 0 then -- 리스트 값의 이벤트를 체크함 0일때 리턴
					char.TalkToCli(_talkerindex, _meindex, "퀘스트 조건이 부족합니다 ".. ZhuanYList[num][9], 6);
				return;
				end
			end
			
			char.AllWarpToSpecificPoint(_talkerindex, ZhuanYList[num][2], ZhuanYList[num][3], ZhuanYList[num][4]);
		elseif _select == 16 then
			ShowDlg(_meindex, _talkerindex, _seqno - 1, ZhuanYList,300);
		elseif _select == 32 then
			ShowDlg(_meindex, _talkerindex, _seqno + 1, ZhuanYList,300);
		end
	elseif _seqno >= 400 and _seqno < 500 then
		if _select == 0 then
			local num = other.atoi(_data) + ((_seqno - 400) * 7);
			if num > table.getn(List4) then--렝岺淚놔
				return ;
			end
			
			local price = List4[num][8]
			local cGold = char.getInt(_talkerindex, "GOLD");
			if price > cGold then
				char.TalkToCli(_talkerindex, _meindex, "돈이 부족합니다!", 6);
				return;
			end
			char.setInt(_talkerindex, "GOLD", cGold - price )
			char.Updata(_talkerindex, "GOLD" )
			
			if List4[num][5] == false then
				if char.getWorkInt(_talkerindex,"WORKPARTYMODE") > 0 then
					char.TalkToCli(_talkerindex, _meindex, "파티상태로 이용 할 수 없습니다!", 6);
					return;
				end
			end
			if List4[num][6] > 0 then
				if char.getInt(_talkerindex, "LV") < List4[num][6] then
				char.TalkToCli(_talkerindex, _meindex, "레벨이 부족합니다 ".. List4[num][6], 6);
				return;
				end
			end
			--npc.EvEnd(charaindex, evendlist182[i])
			--if npc.EvEnd ~= ZhuanYList[num][7] then
			
			if List4[num][7] > 0 then  -- 리스트 값이 0보다 클때
				if npc.CheckEvent(_talkerindex, List4[num][7]) == 0 then -- 리스트 값의 이벤트를 체크함 0일때 리턴
					char.TalkToCli(_talkerindex, _meindex, "퀘스트 조건이 부족합니다 ".. List4[num][9], 6);
				return;
				end
			end
			
			char.AllWarpToSpecificPoint(_talkerindex, List4[num][2], List4[num][3], List4[num][4]);
		elseif _select == 16 then
			ShowDlg(_meindex, _talkerindex, _seqno - 1, List4,400);
		elseif _select == 32 then
			ShowDlg(_meindex, _talkerindex, _seqno + 1, List4,400);
		end
	end
end

function Create(_name, _metamo, _floor, _x, _y, _dir)
	npcindex = npc.CreateNpc(_name, _metamo, _floor, _x, _y, _dir);
	char.setFunctionPointer(npcindex, "TALKEDFUNC", "Talked", "");
	char.setFunctionPointer(npcindex, "WINDOWTALKEDFUNC", "WindowTalked", "");
end

function mydata()
	--綱츠,뒈暠,X,Y,옵뤠莉뚠
	LianJiList = {
				 {"사냥터 1~30",		50000,	10	,	8,	false, 	1, 	0,	0,	"QUEST NAME"}
				,{"사냥터 30~50",	50001,	8	,	6,	false, 	30, 	0,	0,	"QUEST NAME"}
				,{"사냥터 50~70",	50002,	21	,	9,	false, 	50, 	0,	0,	"QUEST NAME"}
				,{"사냥터 70~90",	50003,	10	,	8,	false, 	70, 	0,	0,	"QUEST NAME"}
				,{"사냥터 90~110",	50004,	9	,	9,	false, 	90, 	0,	0,	"QUEST NAME"}
						};
	ZhuanYList = {
				 {"사냥터 110~130",	50005,	6	,	3,	false, 	110, 	0,	0,	"QUEST NAME"}
				,{"사냥터 130~150",	50006,	7	,	7,	false, 	130, 	0,	0,	"QUEST NAME "}
				,{"사냥터 150~170",	50007,	6	,	7,	false, 	150, 	0,	0,	"QUEST NAME"}
				,{"사냥터 170~190",	50008,	7	,	7,	false, 	170, 	0,	0,	"QUEST NAME"}
				,{"사냥터 190~199",	50009,	5	,	6,	false, 	190, 	0,	0,	"QUEST NAME"}
				};
	ChengList = {
				 {"성인식",	1006,	20	,	17,	false, 	0, 	0,	10000,	"QUEST NAME"}
				,{"미쥬",	40000,	81	,	81,	false, 	0, 	4,	10000,	"성인식"}
				,{"일란",	40000,	75	,	95,	false, 	0, 	4,	10000,	"성인식"}
				,{"유나",	40000,	83	,	53,	false, 	0, 	4,	10000,	"성인식"}
				,{"비실이",	40000,	102	,	60,	false, 	0, 	4,	10000,	"성인식"}
				,{"달의반지",	40000,	127	,	101,	false, 	0, 	4,	10000,	"성인식"}
				,{"A코스",	40000,	105	,	29,	false, 	0, 	4,	10000,	"성인식"}
				,{"갈푸스",	40000,	105	,	65,	false, 	0, 	4,	10000,	"성인식"}
				,{"헤티아",	40000,	112	,	102,	false, 	0, 	4,	10000,	"성인식"}
				,{"제시카",	40000,	86	,	50,	false, 	0, 	4,	10000,	"성인식"}
				};
				
	List4 = {
				 {"강화소",	40004,	5	,	23,	false, 	30, 	4,	10000,	"성인식"}
				,{"칠흑20층",	32020,	31	,	22,	false, 	30, 	4,	500000,	"성인식"}
				,{"아파트",	61000,	1	,	27,	false, 	30, 	4,	10000,	"성인식"}
				,{"이동석",	40000,	96	,	38,	false, 	30, 	0,	0,	"성인식"}
				,{"천지레이드",	12201,	29	,	79,	false, 	30, 	0,	0,	"성인식"}
				,{"대지레이드",	21001,	8	,	8,	false, 	30, 	0,	0,	"성인식"}
				,{"벽청레이드",	21201,	60	,	54,	false, 	30, 	0,	0,	"성인식"}
				,{"진홍레이드",	30001,	27	,	19,	false, 	30, 	0,	0,	"성인식"}
					};
	npcdata = {"WARP NPC",100000,777,37,33,6,"TieXin"};								
end

------------------------------- GM츱즈변鑒 -------------------------------
function reload(_charaindex,_data)
	local mytype = other.getString(_data, " ", 1);
	if mytype == "路뗍" then
		mydata();
		char.setChar(npcindex, "츰俚",npcdata[1]);
		char.setInt(npcindex, "暠獗뵀", npcdata[2]);
		char.setInt(npcindex, "覩暠獗뵀", npcdata[2]);
		char.WarpToSpecificPoint(npcindex, npcdata[3], npcdata[4], npcdata[5]);
		char.setInt(npcindex, "렘蕨", npcdata[6]);
		char.ToAroundChar(npcindex);
		char.TalkToCli(_charaindex, -1, "路뗍NPC["..char.getChar(npcindex, "츰俚").."]供냥", 6);
	end
end

function main()
	mydata();
	Create(npcdata[1], npcdata[2], npcdata[3], npcdata[4], npcdata[5], npcdata[6]);
	magic.addLUAListFunction(npcdata[7], "reload", "", 1, "["..npcdata[7].."]");
end

