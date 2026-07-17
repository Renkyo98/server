function StringSplit(_data, _splitint)-- 分割处理函数（返回数组）
	local StartIndex = 1;
	local SplitIndex = 1;
	local SplitArray = {};
	while true do
		local FindLastIndex = string.find(_data, _splitint, StartIndex);
		if not FindLastIndex then
			SplitArray[SplitIndex] = string.sub(_data, StartIndex, string.len(_data));
			break ;
		end
		SplitArray[SplitIndex] = string.sub(_data, StartIndex, FindLastIndex - 1);
		StartIndex = FindLastIndex + string.len(_splitint);
		SplitIndex = SplitIndex + 1;
	end
	return SplitArray;
end

function ItemOverlapFunction(charindex,fromitemindex,toitemindex,fromid,toid)
	local ItemUse = item.getChar(fromitemindex,"USEFUNC");--取得强化石使用函数名
	if ItemUse == "ITEM_UPITEM" then
		local parameter = {charindex,fromitemindex,toitemindex,fromid,toid};
		other.CallFunction("ItemUpLevelFunction", "mylua/item/ItemUpLevel.lua", parameter);
		return 1;
	elseif ItemUse == "ITEM_RandBoxLua" then
		local parameter = {charindex,fromitemindex,toitemindex,fromid,toid};
		other.CallFunction("RandBoxFunction", "mylua/item/RandBox.lua", parameter);
		return 1;
	elseif ItemUse == "ITEM_ChangeAuraArg" then
		ChangeAuraArg( charindex,fromitemindex,toitemindex,fromid,toid )
		return 1;
	end
	return 0;
end

function ChangeAuraArg( charindex,fromitemindex,toitemindex,fromid,toid )
	local new_aura_img = item.getChar( fromitemindex, "ARGUMENT" )
	
	item.setChar( toitemindex, "ARGUMENT", new_aura_img )
	item.setChar( toitemindex, "ATTACHFUNC", "ITEM_AttachAura" )
	item.setChar( toitemindex, "DETACHFUNC", "ITEM_DetachAura" )
	
	
	print("\n\n\n******************\n");
	print("\nARG:".. item.getChar( toitemindex, "ARGUMENT" ) )
	print("\nATT:".. item.getChar( toitemindex, "ATTACHFUNC" ) )
	print("\nDEA:".. item.getChar( toitemindex, "DETACHFUNC" ) )
	print("******************\n\n\n");
	
	item.constructFunctable(toitemindex)
	
	char.DelItem( charindex, fromid )
end



function mydata()
	
end

function main()
	mydata();
end

