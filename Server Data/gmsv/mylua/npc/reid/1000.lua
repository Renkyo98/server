function Talked(meindex, talkerindex, message, color)
	if char.getWorkInt(meindex, "WORKBATTLEMODE") == 0 and char.getInt(talkerindex,"WHICHTYPE") == 1 then
		battle.CreateVsEnemy(talkerindex,meindex, raid_helpcompany)
	end
end

function Loop(meindex)

	if raid_next == -1 then

		char.RandRandWalk(meindex)

	elseif other.time() >= raid_next then
		
		char.WarpToSpecificPoint( meindex, raid_map[1],raid_map[2],raid_map[3])
		char.talkToServer( -1, raid_go_msg, "RED")
		raid_next = -1
	end

end

function BattleOver(meindex, battleindex, winside)
	if winside == 1 then
		raid_next = other.time() + raid_interval * 60
		char.WarpToSpecificPoint( meindex, 10000, 10, 10)
		char.talkToServer( -1, raid_ok_msg, "RED")
	else
		char.talkToServer( -1, raid_faild_msg, "RED")
	end
end

function Create()
	
	raid_index = npc.CreateNpc(raid_name, raid_image, raid_map[1],raid_map[2],raid_map[3], 6)

	char.setFunctionPointer(raid_index, "LOOPFUNC", "Loop", "")
	char.setFunctionPointer(raid_index, "TALKEDFUNC", "Talked", "")
	char.setFunctionPointer(raid_index, "BATTLEOVERDFUNC", "BattleOver", "")

	char.setInt( raid_index, "LOOPINTERVAL", 2000)
end

function awake(index, data)
	raid_next = 0
	local f = other.getString(data, " ", 1 )
	local x = other.getString(data, " ", 2 )
	local y = other.getString(data, " ", 3 )
	raid_map[1] = tonumber(f)
	raid_map[2] = tonumber(x)
	raid_map[3] = tonumber(y)
	raid_go_msg = raid_name .. " 필드레이드가 나타났습니다 MAP: " ..map.getFloorName(raid_map[1]).. " " .. raid_map[2].. " " .. raid_map[3]
end

function mydata()
	raid_name = "필드 보스"
	raid_image = 100000 -- enemy image
	raid_map = { 10000, 10, 10} -- enemy map respawn
	
	raid_helpcompany ={ 9555, 9556, 9557, 9558, 9559} -- enemy table

	raid_interval = 60 --60 MINUTE = 1hour
	raid_next = -1

	raid_go_msg = raid_name .. " 가 나타났습니다 MAP: " ..map.getFloorName(raid_map[1]).. " " .. raid_map[2].. " " .. raid_map[3]
	raid_faild_msg = raid_name .. " 를 누군가 처치하지 못했습니다."
	raid_ok_msg = raid_name .. " 를 누군가 클리어 했습니다"
end

function loc_( index )
	if raid_next == -1 then
		local f = char.getInt(raid_index, "뒈暠뵀")
		local x = char.getInt(raid_index, "麟깃X")
		local y = char.getInt(raid_index, "麟깃Y")
		local msg = raid_name .. " : " .. map.getFloorName(f).. " " .. x .. " " .. y
		char.TalkToCli(index, -1, msg, "RED")
	else
		char.TalkToCli(index, -1, raid_name .. " : DEAD" , "RED")
	end

end

function main()
	mydata()
	Create()
	magic.addLUAListFunction( "raid100", "awake", "", 3, "reload")
end