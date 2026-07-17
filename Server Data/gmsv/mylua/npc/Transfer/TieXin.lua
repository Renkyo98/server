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
				.."                       [style c=5]〖 酒颇飘捞悼 〗[/style]\n"
				.."                       [style c=5]〖 扁鸥捞悼 〗[/style]";
	lssproto.windows(charaindex, 2, 8, 0, char.getWorkInt( npcindex, "对象"), token);
end

--NPC对话事件(NPC索引)
function Talked(_meindex, _talkerindex, _szMes, _color )
	local token = "2\n绢蠢 镑栏肺 傈价秦临鳖？\n\n"
				.."                       [style c=5]〖 荤成磐 〗[/style]\n"
				.."                       [style c=5]〖 酒颇飘捞悼 〗[/style]\n"
				.."                       [style c=5]〖 扁鸥捞悼 〗[/style]";
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
			if LianJiList[num][6] > 0 then
				if char.getInt(_talkerindex, "等级") < LianJiList[num][6] then
				char.TalkToCli(_talkerindex, _meindex, "lv ↓", 6);
				return;
				end
			end
			
			if LianJiList[num][7] > 0 then  -- 府胶飘 蔼捞 0焊促 努锭
				if npc.CheckEvent(_talkerindex, LianJiList[num][7]) == 0 then -- 府胶飘 蔼狼 捞亥飘甫 眉农窃 0老锭 府畔
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
			if ChengList[num][6] > 0 then
				if char.getInt(_talkerindex, "等级") < ChengList[num][6] then
				char.TalkToCli(_talkerindex, _meindex, "lv ↓", 6);
				return;
				end
			end
			
			if ChengList[num][7] > 0 then  -- 府胶飘 蔼捞 0焊促 努锭
				if npc.CheckEvent(_talkerindex, ChengList[num][7]) == 0 then -- 府胶飘 蔼狼 捞亥飘甫 眉农窃 0老锭 府畔
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
			if ZhuanYList[num][6] > 0 then
				if char.getInt(_talkerindex, "等级") < ZhuanYList[num][6] then
				char.TalkToCli(_talkerindex, _meindex, "lv ↓", 6);
				return;
				end
			end
			--npc.EvEnd(charaindex, evendlist182[i])
			--if npc.EvEnd ~= ZhuanYList[num][7] then
			
			if ZhuanYList[num][7] > 0 then  -- 府胶飘 蔼捞 0焊促 努锭
				if npc.CheckEvent(_talkerindex, ZhuanYList[num][7]) == 0 then -- 府胶飘 蔼狼 捞亥飘甫 眉农窃 0老锭 府畔
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
	LianJiList = {{"荤成磐", 50000, 11, 8,false, 0, 0}
				,{"荤成磐", 50001, 9, 6,false, 30, 0}
				,{"荤成磐", 50002, 22, 9,false, 50, 0}
				,{"荤成磐", 50003, 11,8,false, 70, 0}
				,{"荤成磐", 50004, 10,9,false, 90, 0}
				,{"荤成磐", 50005, 7,3,false, 110, 0}
				,{"荤成磐", 50006, 8,7,false, 130, 0}
				,{"荤成磐", 50007, 7,7,false, 150, 0}
				,{"荤成磐", 50008, 8,7,false, 170, 0}
				,{"荤成磐", 50009, 6,6,false, 190, 0}
				};
	ZhuanYList = {{"酒颇飘 1摸", 61000,1,26,true, 0, 0}
				,{"酒颇飘 2摸", 61001, 1, 26,false, 0, 0}
				,{"酒颇飘 3摸", 61002, 1, 26,false, 0, 0}
				,{"酒颇飘 4摸", 61003, 1, 26,false, 0, 0}
				,{"VIP  shop", 54000, 7, 0,false, 0, 0}
				 };
	ChengList = {{"捞悼阂啊", 40001, 7, 5, false, 0, 999}
				,{"付拱", 40000, 104, 94, false, 0, 0}
				,{"阂己", 40000, 91, 116, false, 0, 0}
				,{"扁己", 60020, 37, 7, false, 0, 0}
				,{"父葛", 40000, 76, 37, false, 0, 0}
				,{"绊烹", 60050, 29,4, false, 0, 0}
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

