--丢弃道具事件，返回0为不可丢弃，返回1为可丢弃
function FreeDropItem( charaindex, itemindex )
	--print("调试输出:",charaindex,itemindex);
	return 1;
end

--丢弃宠物事件
function FreeDropPet( charaindex, havepetindex )
	local PetIndex = char.getCharPet(charaindex, havepetindex);--索引
	if char.getInt(PetIndex,"绑定") == 1 then
		local token = "蓖加辆幅狼 其飘涝聪促！\n"
					.."犬牢阑 穿福矫搁 "..char.getChar(PetIndex,"名字").." 其飘绰 家戈邓聪促.";
		lssproto.windows(charaindex, 0, 12, havepetindex, char.getWorkInt( npcindex, "对象"), token);
		return 0;
	end
	return 1;
end

function WindowTalked ( meindex, talkerindex, seqno, select, data)
	if seqno >= 0 and seqno <= 4 then
		if select == 4 then
			local petindex = char.getCharPet(talkerindex,seqno);
			if char.check(petindex) ~= 1 then
				return ;
			end
			if char.getInt(petindex,"绑定") == 1 then
				char.TalkToCli(talkerindex, -1, "滚府脚 ["..char.getChar(petindex,"名字").."]["..char.getInt(petindex,"等级").."](家戈 登菌嚼聪促)", 4);
				char.DelPet(talkerindex, petindex);
				
			else
				char.DropPet(talkerindex,seqno);
			end
		end
	end
end

function mydata()
					 
end

function main()
	mydata();
	npcindex = npc.CreateNpc("checkdrop窗口", 100001, 777, 32, 16, 6);
	char.setFunctionPointer(npcindex, "窗口事件", "WindowTalked", "");
	
end
