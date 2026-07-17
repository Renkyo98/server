function Loop(meindex)

	if char.getWorkInt( meindex, "WORKBATTLEMODE") == 0 then
		
		--Dont Battle when no party
		if char.getWorkInt( meindex, "WORKPARTYMODE" ) ~= 0 then
		
			local all_battle_none = 1;
			
			for i = 1, 5 do
				local other_index = char.getWorkInt( meindex, "WORKPARTYINDEX"..i )
				
				if char.check(other_index) == 1 then
					
					local battle_index = char.getWorkInt( other_index, "WORKBATTLEINDEX")
					
					if battle.checkindex(battle_index) == 0 then
						all_battle_none = 1
						break
					end
					
					if char.getWorkInt( other_index, "WORKBATTLEMODE") ~= 0 then
						all_battle_none = 0
						battle.Exit( other_index, battle_index )
					end
				end
				
			end
			
			print("all_battle_none: ".. all_battle_none);
			
			if all_battle_none == 1 then
				char.BattleStayLoop(meindex)
			end
		end
		
	elseif char.getWorkInt(meindex, "WORKBATTLEMODE") == 2 then
	
		char.setInt( meindex, "HP", char.getWorkInt( meindex, "WORKMAXHP" ) );
		char.setInt( meindex, "EXP", 0 );
		char.SendCharAttack( meindex )
		
		local petindex = char.getCharPet(meindex, 0 );
		if char.check( petindex ) == 1 then
			char.setInt( petindex, "HP", char.getWorkInt( petindex, "WORKMAXHP" ) );
			char.setInt( petindex, "EXP", 0 );
			char.SendPetAttack( meindex )
		end
		
	end
end

function CreateBot()
	for i = 1, table.getn(LeaderBot) do
		print("Creating bot~\n")
		
		npcindex = char.MakeLeaderBot(
					LeaderBot[i][1],LeaderBot[i][2],
					LeaderBot[i][3],LeaderBot[i][4],LeaderBot[i][5],LeaderBot[i][6],
					LeaderBot[i][7],LeaderBot[i][8],
					LeaderBot[i][9],LeaderBot[i][10],
					LeaderBot[i][11],LeaderBot[i][12],LeaderBot[i][13],LeaderBot[i][14],
					LeaderBot[i][15],LeaderBot[i][16],
					LeaderBot[i][17],LeaderBot[i][18], LeaderBot[i][19], LeaderBot[i][20]
					)
		
		if npcindex > 0 then	
			print("Done Creating bot "..LeaderBot[i][1].."\n")
			char.setInt(npcindex, "LOOPINTERVAL", 10000);
			char.setFunctionPointer(npcindex, "LOOPFUNC", "Loop", "");		
			char.ToAroundChar(npcindex);
		else
			print("Failed Creating bot "..LeaderBot[i][1].."\n")
		end
	end
end

function reload()

end

function mydata()

	_Bot1	={	"1BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				100, 635	,	490	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				121	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				121	, 7	, 10	, 10, 121	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	_Bot2	={	"2BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				50000, 15	,	12	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				60000	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				60000	, 7	, 10	, 10, 60000	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	_Bot3	={	"3BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				50000, 13	,	12	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				60000	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				60000	, 7	, 10	, 10, 60000	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	_Bot4	={	"4BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				100, 631	,	493	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				60000	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				60000	, 7	, 10	, 10, 60000	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	_Bot5	={	"5BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				50000, 13	,	15	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				60000	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				60000	, 7	, 10	, 10, 60000	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	_Bot6	={	"6BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				50000, 7	,	7	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				60000	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				60000	, 7	, 10	, 10, 60000	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	_Bot7	={	"7BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				50000, 7	,	8	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				60000	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				60000	, 7	, 10	, 10, 60000	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	_Bot8	={	"8BOT" ,	100000 ,		 --[1]Name, [2]Metamo
				50000, 7	,	9	,  6	,--[3]Floor, [4]X, [5]Y, [6]dir
				60000	, 140	,				 --[7]Enemy Id(Base Stats), [8] Level
				-99999	, 99999	,				 --[9]Party Low Dex, [10] Party High Dex	
				50	, 50	, 50	, 10	,--[11]VITAL, [12] STR, [13]TOUGH, [14]DEX,
				110000	, -1	,				 --[15] WEAPON, [16] ARMOR
				60000	, 7	, 10	, 10, 60000	 --[17]Pet Id, [18]Pet Level, [19]Pet Dex
			}
	--Wrapper for all leaderbot
	LeaderBot = {
		_Bot1,
		_Bot2,
		_Bot3,
		_Bot4,
		_Bot5,
		_Bot6,
		_Bot7,
		_Bot8
	}
end

function main()
	mydata()
	CreateBot()
end
