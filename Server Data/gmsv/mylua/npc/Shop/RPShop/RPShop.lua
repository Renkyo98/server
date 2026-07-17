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

--整理发送
function ShopZLFS(talkerindex,_Num1,_Num2)--Num1 类型选择 Num2商品选择页数
	local point = char.getInt(talkerindex,"RAIDPOINT")
	local itemnum = char.GetEmptyItemNum(talkerindex);--取得道具栏数量
	local petnum = char.GetEmptyPetNum(talkerindex);--取得宠物栏数量
	
	local maxpage = 0;
	if _Num1 > 0 then
		maxpage = math.ceil(table.getn(itemid[_Num1])/8);--总页数
	end
	local retoken = shoptype[_Num1].." SHOP|"..costtype.."|"..point.."|"..itemnum.."|"..petnum.."|".._Num1.."|".._Num2.."|"..maxpage;
	--print(retoken);
	for i=1,5 do
		if shoptype[i] ~= nil then
			retoken = retoken .. "\n".. shoptype[i];
		else
			retoken = retoken .. "\n暂无选项";
		end
	end
	--商品信息整理
	if _Num1 > 0 then
		local maxpage = _Num2 * 8;--商品结束索引
		local idindex1 = maxpage-7;--商品开始索引
		local retoken2 = "";--商品开始索引
		for i=idindex1,maxpage do
			--1商品类型(1道具,2宠物,0点数),2商品编号,3商品价格，4商品图号，5商品名字，6商品说明
			--商品名字|商品类型|商品价格|商品图号|商品说明
			if itemid[_Num1][i] ~= nil then
				retoken2 = 			      itemid[_Num1][i][5]--名字
								.. "|" .. itemid[_Num1][i][1]--辆幅
								.. "|" .. itemid[_Num1][i][3]--价格
								.. "|" .. itemid[_Num1][i][4]--图号
								.. "|" .. itemid[_Num1][i][6];--说明
				retoken = retoken .. "\n" .. retoken2;
			end
		end
	end
	--print(retoken);
	return retoken;
end

function FreeShopVip(charaindex)
	if npc.isFaceToFace(meindex, talkerindex) == 1 then
		local token = ShopZLFS(talkerindex,1,1);
		lssproto.windows(talkerindex, 1013, 8, 0, char.getWorkInt( npcindex, "WORKOBJINDEX"), token);
	end
end

--NPC对话事件(NPC索引)
function Talked(meindex, talkerindex , szMes, color )
	if npc.isFaceToFace(meindex, talkerindex) == 1 then
		local token = ShopZLFS(talkerindex,1,1);
		lssproto.windows(talkerindex, 1013, 8, 0, char.getWorkInt( npcindex, "WORKOBJINDEX"), token);
	end
end

--NPC窗口事件(NPC索引)
function WindowTalked ( _meindex, _talkerindex, _seqno, _select, _data)
	if _select==8 or ( _seqno>=500 and _select == 2 ) then
		return ;
	end
	print( _meindex, _talkerindex, _seqno, _select, _data)
	
	
	if(_seqno==0)then
		local shopdata = StringSplit(_data, "|");--分割客户端传递信息
		if shopdata[1] == "类型选择" then
			if table.getn(shopdata) >= 2 then--该操作需要2个函数
				local token = ShopZLFS(_talkerindex,other.atoi(shopdata[2]),1);
				lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
			end
		elseif shopdata[1] == "页数选择" then
			if table.getn(shopdata) >= 3 then--该操作需要3个函数
				local token = ShopZLFS(_talkerindex,other.atoi(shopdata[2]),other.atoi(shopdata[3]));
				lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
			end
		elseif shopdata[1] == "购买商品" then
			if table.getn(shopdata) >= 5 then--该操作需要5个函数
				local sellindex = other.atoi(shopdata[2]);--项目索引
				local sellpage = other.atoi(shopdata[3]);--选择页数
				local sellid = other.atoi(shopdata[4]);--选择项目
				local sellnum = other.atoi(shopdata[5]);--购买数量
				local sellidindex = sellid + ((sellpage-1)*8);--计算出选择物品索引
				if sellnum <= 0 then
					char.TalkToCli(_talkerindex, _meindex, "HACK 0 num！", "RED");
					return ;
				end
				local sellpoint = itemid[sellindex][sellidindex][3] * sellnum;--计算出总价格
				local token = "10\n\n\n"
										.."["..itemid[sellindex][sellidindex][5].." x" .. sellnum.." ]"
										.."\nCOST:"..sellpoint.. costtype .."！！"
										.."\n\nARE YOU SURE?";
										
				lssproto.windows(_talkerindex, 2, 1+2, 1, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
				char.setWorkChar(_talkerindex, "NBWORKCHAR1" , _data);
			end
		end
	elseif(_seqno==1)then
		local shopdata = StringSplit(char.getWorkChar(_talkerindex, "NBWORKCHAR1"), "|");--分割客户端传递信息
		
		if table.getn(shopdata) >= 5 then--该操作需要5个函数
			local sellindex = other.atoi(shopdata[2]);--项目索引
			local sellpage = other.atoi(shopdata[3]);--选择页数
			local sellid = other.atoi(shopdata[4]);--选择项目
			local sellnum = other.atoi(shopdata[5]);--购买数量
			local sellidindex = sellid + ((sellpage-1)*8);--计算出选择物品索引
			if _select == 2 then
				local token_ = ShopZLFS(_talkerindex,sellindex,sellpage);
				lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token_);
				return;
			end
			if sellnum <= 0 then
				char.TalkToCli(_talkerindex, _meindex, "HACK 0 num！", "RED");
				return ;
			end
			local sellpoint = itemid[sellindex][sellidindex][3] * sellnum;--计算出总价格
			local point = char.getInt(_talkerindex,"RAIDPOINT");
			if point < sellpoint then
				char.TalkToCli(_talkerindex, _meindex, "NOT ENOUGH ".. costtype .." POINTS！", "RED");
				return ;
			end
			if itemid[sellindex][sellidindex][1] == 1 then
				local itemnum = char.GetEmptyItemNum(_talkerindex);--取得道具栏数量
				if itemnum < sellnum then
					char.TalkToCli(_talkerindex, _meindex, "NO BAG SPACE", "RED");
					return ;
				end
			elseif itemid[sellindex][sellidindex][1] == 2 then
				local petnum = char.GetEmptyPetNum(_talkerindex);
				if petnum < sellnum then
					char.TalkToCli(_talkerindex, _meindex, "NO PET SPACE", "RED");
					return ;
				end
			end
			if itemid[sellindex][sellidindex][1] == 1 then
				for i=1,sellnum do
					local itemindex = char.Additem( _talkerindex, itemid[sellindex][sellidindex][2]);
				end
			elseif itemid[sellindex][sellidindex][1] == 2 then
				for i=1,sellnum do
					local petindex = char.AddPet( _talkerindex, itemid[sellindex][sellidindex][2],1);
				end
			end
			char.setInt(_talkerindex,"RAIDPOINT",point-sellpoint);
			char.TalkToCli(_talkerindex, _meindex, "BOUGHT [".. itemid[sellindex][sellidindex][5].." x".. sellnum .." ] ITEM", "RED");
			char.TalkToCli(_talkerindex, _meindex, "COST ".. sellpoint.." ".. costtype.." POINT", "RED");
			local logstr = os.date("%Y-%m-%d %X",os.time())
						.."|"..char.getChar(_talkerindex, "?俚")
						.."|"..char.getChar(_talkerindex, "?俚")
						.."|"..itemid[sellindex][sellidindex][5].."("..itemid[sellindex][sellidindex][2]..")"
						.."|"..sellnum--荐樊
						.."|"..sellpoint--器牢飘
						.."|"..tostring(point-sellpoint)--剩余
						.."\n";
			local f = assert(io.open("./mylua/log/VipShop/"..os.date("%Y%m%d",os.time())..".log", "a"));
				f:write( logstr);
				f:close();
				
				
			local token__ = ShopZLFS(_talkerindex,sellindex,sellpage);
			lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token__);
		end
	end
end


function Create(_name, _metamo, _floor, _x, _y, _dir)
	npcindex = npc.CreateNpc(_name, _metamo, _floor, _x, _y, _dir);
	char.setFunctionPointer(npcindex, "TALKEDFUNC", "Talked", "");
	char.setFunctionPointer(npcindex, "WINDOWTALKEDFUNC", "WindowTalked", "");
end

function ShopSetData()
	for i=1,table.getn(itemid) do
		for j=1,table.getn(itemid[i]) do
			if itemid[i][j][1] == 1 then--道具说明
				local myitemid = itemid[i][j][2];
				itemid[i][j][4] = item.getgraNoFromITEMtabl(myitemid);--获取图像
				itemid[i][j][5] = item.getNameFromNumber(myitemid);--获取名字
				itemid[i][j][6] = item.getItemInfoFromNumber(myitemid);--获取说明
			elseif itemid[i][j][1] == 2 then--宠物说明
				local enemybaseid = pet.getEnemyBaseIdFromEnemyId(itemid[i][j][2]);--取得enemybaseid
				local TM_DSX = pet.getDataInt(enemybaseid, "地");
				local TM_SSX = pet.getDataInt(enemybaseid, "水");
				local TM_HSX = pet.getDataInt(enemybaseid, "火");
				local TM_FSX = pet.getDataInt(enemybaseid, "风");
				local TM_SKName = {"无","无","无","无","无","无","无"};
				local TM_SKML = {"技能1","技能2","技能3","技能4","技能5","技能6","技能7"};
				for t=1,table.getn(TM_SKML) do
					local TM_SKId = pet.getDataInt(enemybaseid, TM_SKML[t]);
					if TM_SKId >= 0 then
						TM_SKName[t] = petskill.getChar(TM_SKId,"名称");
					end
				end
				itemid[i][j][4] = pet.getDataInt(enemybaseid, "形象");
				itemid[i][j][5] = pet.getDataChar(enemybaseid, "名字");
				itemid[i][j][6] = string.format( "%d-%d-%d-%d-%s-%s-%s-%s-%s-%s-%s",TM_DSX,TM_SSX,TM_HSX,TM_FSX,TM_SKName[1],TM_SKName[2],TM_SKName[3],TM_SKName[4],TM_SKName[5],TM_SKName[6],TM_SKName[7]);
			end
		end
	end
end

function mydata()
	costtype = "RP";
	--蜡屈,ID,啊拜,捞固瘤,捞抚,汲疙
	itemid = {
				{
					--LIST 1 A
					 {1,100508,5,-1,"",""}
					,{1,100508,5,-1,"",""}
					,{1,67000,30,-1,"",""}
					,{1,67001,50,-1,"",""}
				}
			 };
	shoptype = {
				 "RAID POINT"
	};
	ShopSetData();--补足说明
	
	npcdata = {"RAID SHOP",16210,61000,7,23,6,"VipShop"};
end


function main()
	mydata();
	Create(npcdata[1], npcdata[2], npcdata[3], npcdata[4], npcdata[5], npcdata[6]);
end
