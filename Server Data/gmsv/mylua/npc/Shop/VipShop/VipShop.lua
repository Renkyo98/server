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
	local point = char.getInt(talkerindex,"AMPOINT")
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
	local point = char.getInt(charaindex,"AMPOINT")
	local token = "1\n"
				.."        VIP POINTS: [style c=4]"..point.."[/style]\n"
				.."                   1. 其  飘\n"
				.."                   2. 酒捞袍\n"
				.."                   3. 捞亥飘 \n"
				.."                   4. 霖厚吝 "
	lssproto.windows(charaindex, 200, 2, 500, char.getWorkInt( npcindex, "WORKOBJINDEX"), token);
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
	
	if(_seqno==500)then
		local chose = other.atoi(_data);
		local token = ""
		local point = char.getInt(_talkerindex,"AMPOINT");
		if chose == 1 then
			token = "1\n"
				.."        VIP POINTS: [style c=4]"..point.."[/style]\n"
				.."                   1. 硅撇龋府捍\n"
				.."                   2. 啪铰龋府捍\n"
				.."                   3. 其飘酒捞袍\n"
				.."                   4. 霖厚吝"
		elseif chose == 2 then
			token = "1\n"
				.."        VIP POINTS: [style c=4]"..point.."[/style]\n"
				.."                   1. 某腐磐菩靛\n"
				.."                   2. 家葛酒捞袍\n"
				.."                   3. 犁丰酒捞袍\n"
				.."                   4. 厘馒酒捞袍"
		elseif chose == 3 then
			token = "1\n"
				.."        VIP POINTS: [style c=4]"..point.."[/style]\n"
				.."                   1. 捻迄\n"
				.."                   2. VIP巩辑\n"
				.."                   3. 霖厚吝\n"
				.."                   4. 霖厚吝"
		elseif chose == 4 then
			token = "1\n"
				.."        VIP POINTS: [style c=4]"..point.."[/style]\n"
				.."                   1. 霖厚吝\n"
				.."                   2. 霖厚吝\n"
				.."                   3. 霖厚吝\n"
				.."                   4. 霖厚吝"
		end
		
		lssproto.windows(_talkerindex, 200, 2, 600+chose, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
		return;
	elseif(_seqno==601)then
		local token = ShopZLFS(_talkerindex,other.atoi(_data),1);
		lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
		return;
	elseif(_seqno==602)then
		local token = ShopZLFS(_talkerindex,4+other.atoi(_data),1);
		lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
		return;
	elseif(_seqno==603)then
		local token = ShopZLFS(_talkerindex,8+other.atoi(_data),1);
		lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
		return;
	elseif(_seqno==604)then
		local token = ShopZLFS(_talkerindex,12+other.atoi(_data),1);
		lssproto.windows(_talkerindex, 1013, 8, 0, char.getWorkInt( _meindex, "WORKOBJINDEX"), token);
		return;
	end
	
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
										.."\n啊拜篮:"..sellpoint.. costtype .."涝聪促！"
										.."\n\n备概甫 盔窍矫搁 OK甫 喘矾林技夸 !";
										
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
			local point = char.getInt(_talkerindex,"AMPOINT");
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
				local petnum = char.GetEmptyPetNum(_talkerindex);--取得宠物栏数量
				if petnum < sellnum then
					char.TalkToCli(_talkerindex, _meindex, "NO PET SPACE", "RED");
					return ;
				end
			end
			if itemid[sellindex][sellidindex][1] == 1 then--给道具
				for i=1,sellnum do
					local itemindex = char.Additem( _talkerindex, itemid[sellindex][sellidindex][2]);
					--item.setInt(itemindex,"绑定",1);
				end
			elseif itemid[sellindex][sellidindex][1] == 2 then--给宠物
				for i=1,sellnum do
					local petindex = char.AddPet( _talkerindex, itemid[sellindex][sellidindex][2],1);
					--char.setInt(petindex,"绑定",1);
				end
			end
			char.setInt(_talkerindex,"AMPOINT",point-sellpoint);
			char.TalkToCli(_talkerindex, _meindex, "酒捞袍捞抚 [".. itemid[sellindex][sellidindex][5].." x".. sellnum .." ] ITEM", "RED");
			char.TalkToCli(_talkerindex, _meindex, "啊拜 ".. sellpoint.." ".. costtype.." POINT", "RED");
			local logstr = os.date("%Y-%m-%d %X",os.time())
						.."|"..char.getChar(_talkerindex, "账号")
						.."|"..char.getChar(_talkerindex, "名字")
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
	char.setFunctionPointer(npcindex, "对话事件", "Talked", "");
	char.setFunctionPointer(npcindex, "窗口事件", "WindowTalked", "");
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
	costtype = "VIP";
	--蜡屈,ID,啊拜,捞固瘤,捞抚,汲疙
	itemid = {
				{
					--LIST 1 硅撇其飘
					 {1,40110,6900,-1,"",""}
					,{1,40111,6900,-1,"",""}
					,{1,40112,6900,-1,"",""}
					,{1,40113,6900,-1,"",""}
					,{1,40114,6900,-1,"",""}
					,{1,40115,6900,-1,"",""}
					,{1,40116,6900,-1,"",""}
					,{1,40117,6900,-1,"",""}
					,{1,40118,6900,-1,"",""}
					,{1,40119,6900,-1,"",""}
					,{1,40120,6900,-1,"",""}
					,{1,40121,6900,-1,"",""}
					,{1,40122,6900,-1,"",""}
					,{1,40123,6900,-1,"",""}
					,{1,40124,6900,-1,"",""}
					,{1,40125,6900,-1,"",""}
					,{1,40126,6900,-1,"",""}
					,{1,40188,6900,-1,"",""}
					,{1,40189,6900,-1,"",""}
					,{1,40200,6900,-1,"",""}
				},
				{
					--LIST 1 啪铰其飘
					 {1,40130,6900,-1,"",""}
					,{1,40131,6900,-1,"",""}
					,{1,40132,6900,-1,"",""}
					,{1,40134,6900,-1,"",""}
					,{1,40135,6900,-1,"",""}
					,{1,40136,6900,-1,"",""}
					,{1,40137,6900,-1,"",""}
					,{1,40138,6900,-1,"",""}
					,{1,40139,6900,-1,"",""}
					,{1,40140,6900,-1,"",""}
					,{1,40141,6900,-1,"",""}
					,{1,40142,6900,-1,"",""}
					,{1,40143,6900,-1,"",""}
					,{1,40144,6900,-1,"",""}
					,{1,40145,6900,-1,"",""}
					,{1,40146,6900,-1,"",""}
					,{1,40147,6900,-1,"",""}
					,{1,40148,6900,-1,"",""}
					,{1,40149,6900,-1,"",""}
					,{1,40186,6900,-1,"",""}
					,{1,40187,6900,-1,"",""}
					,{1,40199,6900,-1,"",""}

				},
			    {
					--LIST 1 C 其飘酒捞袍
					 {1,25150,1000,-1,"",""}
					,{1,25152,4000,-1,"",""}
					,{1,46017,5000,-1,"",""}
					,{1,46018,5000,-1,"",""}
					,{1,46019,5000,-1,"",""}
					,{1,46020,5000,-1,"",""}
					,{1,46021,8000,-1,"",""}
					,{1,46022,8000,-1,"",""}
					,{1,45009,15000,-1,"",""}
			    },
			    {
					--LIST 1 D 霖厚吝
					 {1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
			    },
				{
					--LIST 2 某腐磐菩靛
					 {1,22118,6900,-1,"",""}
					,{1,22119,6900,-1,"",""}
					,{1,22120,6900,-1,"",""}
					,{1,22121,6900,-1,"",""}
					,{1,22122,4900,-1,"",""}
					,{1,22123,4900,-1,"",""}
				},
				{
					--LIST 2 家葛酒捞袍
					 {1,100507,2000,-1,"",""}
					,{1,25151,15000,-1,"",""}
					,{1,40039,1000,-1,"",""}
					,{1,40040,3000,-1,"",""}
					,{1,40054,5000,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
				},
			    {
					--LIST 2 犁丰酒捞袍
					 {1,100103,1000,-1,"",""}
					,{1,100104,2000,-1,"",""}
					,{1,100105,2500,-1,"",""}
					,{1,100106,3000,-1,"",""}
					,{1,100107,4000,-1,"",""}
					,{1,100108,5000,-1,"",""}
					,{1,100109,8000,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
					,{1,-1,0,-1,"",""}
			    },
			    {
					--LIST 2 D 厘馒酒捞袍
					 {1,94000,20000,-1,"",""}--
					,{1,94001,30000,-1,"",""}--
					,{1,47000,40000,-1,"",""}
					,{1,47001,40000,-1,"",""}
					,{1,47002,40000,-1,"",""}
					,{1,47003,60000,-1,"",""}
					,{1,47004,60000,-1,"",""}
					,{1,47005,60000,-1,"",""}
					,{1,98000,20000,-1,"",""}
					,{1,98001,15000,-1,"",""}
					,{1,98002,15000,-1,"",""}
			    },
				{
					--LIST 3 A 捻迄
					 {1,40050,4900,-1,"",""}
					 ,{1,57722,8900,-1,"",""}
				},
				{
					--LIST 3 B 瑚巩辑
					 {1,21111,1000,-1,"",""}
					 ,{1,21112,3000,-1,"",""}
					 ,{1,21113,5000,-1,"",""}
					 ,{1,21114,10000,-1,"",""}
					 ,{1,21115,30000,-1,"",""}
					 ,{1,21116,50000,-1,"",""}
					 ,{1,21117,100000,-1,"",""}


					},
			    {
					--LIST 3 C 霖厚吝
					 {1,-1,0,-1,"",""}--阂
			    },
			    {
					--LIST 3 D 霖厚吝
					 {1,-1,0,-1,"",""}--
			    },
				{
					--LIST 4 A 霖厚吝
					 {1,-1,0,-1,"",""}
				},
				{
					--LIST 4 B 霖厚吝
					 {1,-1,0,-1,"",""}
				},
			    {
					--LIST 4 C 霖厚吝
					 {2,-1,0,-1,"",""}
			    },
			    {
					--LIST 4 D 霖厚吝
					 {1,-1,0,-1,"",""}--
			    }
				
			 };
	shoptype = {
				 "硅撇","啪铰","其飘酒捞袍","霖厚吝"
				,"某腐磐菩靛","家葛酒捞袍","犁丰酒捞袍","厘馒酒捞袍"
				,"捻迄","霖厚吝","霖厚吝","霖厚吝"
				,"霖厚吝","霖厚吝","霖厚吝","霖厚吝"
	};
	ShopSetData();--补足说明
	
	npcdata = {"VIP SHOP",100000,777,32,24,6,"VipShop"};
end

function reload(_charaindex, _data)
	local mytype = other.getString(_data, " ", 1);
	if mytype == "促矫佬扁" then
		mydata();
		char.setChar(npcindex, "捞抚",npcdata[1]);
		char.setInt(npcindex, "捞固瘤锅龋", npcdata[2]);
		char.setInt(npcindex, "盔夯捞固瘤锅龋", npcdata[2]);
		char.WarpToSpecificPoint(npcindex, npcdata[3], npcdata[4], npcdata[5]);
		char.setInt(npcindex, "规氢", npcdata[6]);
		char.ToAroundChar(npcindex);
		char.TalkToCli(_charaindex, -1, "促矫佬扁NPC["..char.getChar(npcindex, "捞抚").."]荐青窍促", 6);
	end
end


function main()
	mydata();
	Create(npcdata[1], npcdata[2], npcdata[3], npcdata[4], npcdata[5], npcdata[6]);
	magic.addLUAListFunction(npcdata[7], "reload", "", 3, "["..npcdata[7].."]");
end
