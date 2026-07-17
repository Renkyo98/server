function lua_string_split(str, split_char)
    local sub_str_tab = {};
    while (true) do
        local pos = string.find(str, split_char);
        if (not pos) then
            sub_str_tab[#sub_str_tab + 1] = str;
            break;
        end
        local sub_str = string.sub(str, 1, pos - 1);
        sub_str_tab[#sub_str_tab + 1] = sub_str;
        str = string.sub(str, pos + 1, #str);
    end

    return sub_str_tab;
end

--真·打乱排序
function RandItemList(itemlist)
	local TmItemList={};
	while table.getn(itemlist) > 0 do
		local n = math.random(1,table.getn(itemlist));
		if itemlist[n] ~= nil then
			table.insert(TmItemList,itemlist[n]);
			table.remove(itemlist,n);
		end
	end
	return TmItemList;
end

function ItemBoxCf(itemindex, charaindex, toindex, haveitemindex)
	local strdata = item.getChar(itemindex, "字段");
	local itemnum = char.GetEmptyItemNum(charaindex);--取得道具栏数量
	local petnum = char.GetEmptyPetNum(charaindex);--取得宠物栏数量
	local BoxData = lua_string_split(strdata,"|");
	local BoxTime = item.getInt(itemindex,"HP");
	if table.getn(BoxData) <= 0 then
		char.TalkToCli(charaindex, -1, "该礼包有问题！", 6);
		return ;
	end
	if BoxData[1] == "练宠活动" then
		local itemlist = {};
		if BoxTime == 20190130 then
			itemlist = {{{1,4503},{1,4502},{2,5030}}--战斗力1 2 3 奖品
					   ,{{1,4503},{1,4502},{2,5030}}--耐久力1 2 3 奖品
					   ,{{1,4503},{1,4502},{2,5030}}--攻击力1 2 3 奖品
					   ,{{1,4503},{1,4502},{2,5030}}--防御力1 2 3 奖品
					   ,{{1,4503},{1,4502},{2,5030}}--敏捷力1 2 3 奖品
					   };
		end
		if table.getn(itemlist) <= 0 then
			char.TalkToCli(charaindex, -1, "该礼包暂未开放！", 6);
			return ;
		end
		local BoxNum1 = other.atoi(BoxData[2]);
		local BoxNum2 = other.atoi(BoxData[3]);
		local GetName = "";
		if itemlist[BoxNum1][BoxNum2][1] == 1 then
			if itemnum < 1 then
				char.TalkToCli(charaindex, -1, "请先空出1个道具栏位！", 6);
				return ;
			end
			local GetIndex = char.Additem( charaindex, itemlist[BoxNum1][BoxNum2][2]);
			GetName = item.getChar(GetIndex,"名称");
			
		elseif itemlist[BoxNum1][BoxNum2][1] == 2 then
			if petnum < 1 then
				char.TalkToCli(charaindex, -1, "请先空出1个宠物栏位！", 6);
				return ;
			end
			local GetIndex = char.AddPet( charaindex, itemlist[BoxNum1][BoxNum2][2],1);
			GetName = char.getChar(GetIndex,"名字");
		end
		char.TalkToCli(charaindex, -1, "获得 ".. GetName .."！", 4);				
		char.DelItem(charaindex, haveitemindex);
	else
		char.TalkToCli(charaindex, -1, "该礼包暂未开放！", 6);
		return ;
	end
	
end

function data()
end

function main()
	item.addLUAListFunction( "ITEM_BOXCF", "ItemBoxCf", "");
end
