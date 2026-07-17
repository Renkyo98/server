function ShowDlg(_meindex, _talkerindex, _page,_transdata,_seqno)
	local _maxpage = math.ceil(table.getn(_transdata) / 7);
	local token = "1 绢蠢 镑栏肺 捞悼窍矫摆嚼聪鳖?？\n";
	local topselect = (_page-_seqno) * 7;
	for i = 1, 7 do
		if (i + topselect) > table.getn(_transdata) then
			break;
		end
		if _transdata[i + topselect][6] ~= nil then
			token = token .. string.format("  %-18s%s\n", _transdata[i + topselect][1], _transdata[i + topselect][6]);
		else
			token = token .. string.format("  %-18s%s\n", _transdata[i + topselect][1], map.getFloorName(_transdata[i + topselect][2]));
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
	lssproto.windows(_talkerindex, 2, button, _page, char.getWorkInt( _meindex, "对象"), token);
end


function FreeTieXin(charaindex)
	local token = "2\n绢蠢 镑栏肺 傈价秦临鳖？\n\n"
				.."                       [style c=5]〖 荤成磐 〗[/style]\n"
				.."                       [style c=5]〖 何遏捞悼 〗[/style]\n"
				.."                       [style c=5]〖 付阑捞悼 〗[/style]";
	lssproto.windows(charaindex, 2, 8, 0, char.getWorkInt( npcindex, "对象"), token);
end

--NPC对话事件(NPC索引)
function Talked(_meindex, _talkerindex, _szMes, _color )
	local token = "2\n绢蠢 镑栏肺 傈价秦临鳖？\n\n"
				.."                       [style c=5]〖 荤成磐 〗[/style]\n"
				.."                       [style c=5]〖 何遏捞悼 〗[/style]\n"
				.."                       [style c=5]〖 付阑捞悼 〗[/style]";
	lssproto.windows(_talkerindex, 2, 8, 0, char.getWorkInt( _meindex, "对象"), token);
end

function ShowPetType(_meindex, _talkerindex, _page)
	local _maxpage = math.ceil(table.getn(PetList) / 7);
	local topselect = (_page-10) * 7;

	local token = "1 请选择你要抓的宠物类型:\n";
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
	lssproto.windows(_talkerindex, 2, button, _page, char.getWorkInt( _meindex, "对象"), token);
end

--NPC窗口事件(NPC索引)
function WindowTalked (_meindex, _talkerindex, _seqno, _select, _data)
	--print(_meindex, _talkerindex, _seqno, _select, _data)
	if _seqno == 0 then
		local setid = other.atoi(_data);
		if setid == 1 then
			ShowDlg(_meindex, _talkerindex, 100,LianJiList,100);
		elseif setid == 2 then
			ShowDlg(_meindex, _talkerindex, 300,ZhuanYList,300);
		elseif setid == 3 then
			ShowDlg(_meindex, _talkerindex, 200,ChengList,200);
		end
	elseif _seqno >= 100 and _seqno < 200 then
		if _select == 0 then
			local num = other.atoi(_data) + ((_seqno - 100) * 7);
			if num > table.getn(LianJiList) then--防止溢出
				return ;
			end
			if LianJiList[num][5] == false then
				if char.getWorkInt(_talkerindex,"组队") > 0 then
					char.TalkToCli(_talkerindex, _meindex, "不可组队传送！", 6);
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
			if num > table.getn(ChengList) then--防止溢出
				return ;
			end
			if ChengList[num][5] == false then
				if char.getWorkInt(_talkerindex,"组队") > 0 then
					char.TalkToCli(_talkerindex, _meindex, "不可组队传送！", 6);
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
			if num > table.getn(ZhuanYList) then--防止溢出
				return ;
			end
			if ZhuanYList[num][5] == false then
				if char.getWorkInt(_talkerindex,"组队") > 0 then
					char.TalkToCli(_talkerindex, _meindex, "不可组队传送！", 6);
					return;
				end
			end
			char.AllWarpToSpecificPoint(_talkerindex, ZhuanYList[num][2], ZhuanYList[num][3], ZhuanYList[num][4]);
		elseif _select == 16 then
			ShowDlg(_meindex, _talkerindex, _seqno - 1, ZhuanYList,300);
		elseif _select == 32 then
			ShowDlg(_meindex, _talkerindex, _seqno + 1, ZhuanYList,300);
		end
	end
end

function Create(_name, _metamo, _floor, _x, _y, _dir)
	npcindex = npc.CreateNpc(_name, _metamo, _floor, _x, _y, _dir);
	char.setFunctionPointer(npcindex, "对话事件", "Talked", "");
	char.setFunctionPointer(npcindex, "窗口事件", "WindowTalked", "");
end

function mydata()
	--说明,地图,X,Y,可否组队
	LianJiList = {{"2 0级乌　龟", 10001, 40, 3,false}
				 ,{"4 0级海主人", 31401, 92, 27,false}
				 ,{"6 0级布伊区", 31705, 26, 29,false}
				 ,{"8 0级大象区", 300, 81, 270,false}
				 ,{"100级蓝雷区", 32018, 12, 34,false}
				 ,{"120级雷　龙", 7402, 155,75,false}
				 ,{"140级地雷区", 60050, 15, 18,false}
				 ,{"140级金暴区", 60054, 42, 50,false}
				 ,{"160级泪之海", 817, 24,116,false}
				 ,{"阿布洞挂技能", 10007, 29, 38,false}
				 ,{"120级英雄岛",	 500, 212, 342,false}
				 };
	ZhuanYList = {{"萨姆吉尔庄园", 1040,46,29,true}
				 ,{"玛丽娜丝庄园", 2030,59,41,true}
				 ,{"加  加  庄园", 3030,59,36,true}
				 ,{"卡鲁它那庄园", 4030,29,18,true}
				 };
	ChengList = {{"荤捞呈胶", 1000, 92, 99, false}
				,{"荤捞呈胶", 2000, 65, 58, false}
				,{"荤捞呈胶", 1100, 48, 91, false}
				,{"荤捞呈胶", 1200, 61, 46, false}
				,{"荤捞呈胶", 1300, 27, 23, false}
				,{"荤捞呈胶", 1400, 74,104, false}
				,{"鲤风", 3000, 94, 97, false}
				,{"鲤风", 4000, 66, 55, false}
				,{"鲤风", 3100, 81, 70, false}
				,{"鲤风", 3200, 47, 60, false}
				,{"鲤风", 3300, 69, 51, false}
				,{"鲤风", 3400, 63, 48, false}
				,{"技福畴胶", 6000, 44, 73, false}
				,{"啊快赴", 5000, 45, 53, false}
				,{"啊快赴", 5106, 20, 36, false}
				,{"器风",  500,274,369, false}
				,{"器风", 5543, 22, 22, false}
				};
	npcdata = {"贴心传送",100000,777,37,33,6,"TieXin"};								
end

------------------------------- GM命令函数 -------------------------------
function reload(_charaindex,_data)
	local mytype = other.getString(_data, " ", 1);
	if mytype == "重读" then
		mydata();
		char.setChar(npcindex, "名字",npcdata[1]);
		char.setInt(npcindex, "图像号", npcdata[2]);
		char.setInt(npcindex, "原图像号", npcdata[2]);
		char.WarpToSpecificPoint(npcindex, npcdata[3], npcdata[4], npcdata[5]);
		char.setInt(npcindex, "方向", npcdata[6]);
		char.ToAroundChar(npcindex);
		char.TalkToCli(_charaindex, -1, "重读NPC["..char.getChar(npcindex, "名字").."]完成", 6);
	end
end

function main()
	mydata();
	Create(npcdata[1], npcdata[2], npcdata[3], npcdata[4], npcdata[5], npcdata[6]);
	magic.addLUAListFunction(npcdata[7], "reload", "", 1, "["..npcdata[7].."]");
end

