ItemRecordTable={};


function WindowTalked ( meindex, charaindex, seqno, select, data)
	if seqno == 1 then
		local petSlot = other.atoi(data);
		if petSlot >=1 and petSlot<=4 then
			local petIndex = char.getCharPet(charaindex, petSlot-1);
			if char.check(petIndex) == 1 then
				ItemRecordTable[charaindex][3] = petIndex;
				local dialogText = "是否让 "..char.getChar(petIndex,"名字") .." 学习该特效！"
				lssproto.windows(charaindex, "对话框", "确定|取消", 2,  char.getWorkInt( npcindex, "对象"),dialogText )
			end
		end
	elseif seqno == 2 then
		if select == 1 then
			local attackEffectId = other.atoi(item.getChar(ItemRecordTable[charaindex][1], "字段"))
			char.setInt(ItemRecordTable[charaindex][3],"攻击特效",attackEffectId);
			char.DelItem(charaindex, ItemRecordTable[charaindex][2]);
			char.TalkToCli(charaindex, -1, "您的宠物"..char.getChar(ItemRecordTable[charaindex][3],"名字").."习得攻击特效,快去体验吧！", "红色")
			ItemRecordTable[charaindex]=nil;
		end
	end
end

function attackeffect(itemindex, charaindex, toindex, haveitemindex)
	ItemRecordTable[charaindex]={};
	ItemRecordTable[charaindex][1]=itemindex;
	ItemRecordTable[charaindex][2]=haveitemindex;
	lssproto.windows(charaindex, "宠物框", "确定", 1,  char.getWorkInt( npcindex, "对象"), "")
end

function Create(name, metamo, floor, x, y, dir)
	--创建NPC(NPC名字，图像号，地图号，坐标X，坐标Y，方向号)将返回一个NPC索引
	npcindex = npc.CreateNpc(name, metamo, floor, x, y, dir)
	char.setFunctionPointer(npcindex, "窗口事件", "WindowTalked", "")
end


function data()
end

function main()
	Create("攻击特效NPC",100000,777,20,20,3);

	item.addLUAListFunction( "ITEM_ATTACKEFFECT", "attackeffect", "")
end
