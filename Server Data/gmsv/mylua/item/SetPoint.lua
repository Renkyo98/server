function StringSplit(_data, _splitint)-- ·Ö¸î´¦Àíº¯Êý£¨·µ»ØÊý×é£©
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

function SetPoint(itemindex, charaindex, toindex, haveitemindex)
	local itemdata = item.getChar(itemindex, "×Ö¶Î");
	local field = other.getString(itemdata, "|", 1);
	local pointmin = other.atoi(other.getString(itemdata, "|", 2));
	local pointmax = other.atoi(other.getString(itemdata, "|", 3));
	local getpoint = 0;
	if pointmax == 0 then
		getpoint = pointmin;
	else
		getpoint = math.random(pointmin,pointmax);
	end
	if field == "Áö¿ø" then
		local mypoint = sasql.getVipPoint(charaindex);
		sasql.setVipPoint(charaindex,mypoint+getpoint);
		char.TalkToCli(charaindex, -1, "ÃæÀü¿Ï·á" .. getpoint.."Áö¿ø Æ÷ÀÎÆ®£¡", "»ÆÉ«");
	elseif field == "¸í¼º" then
		local mypoint = char.getInt(charaindex, "¸í¼º");
		char.setInt(charaindex, "¸í¼º",mypoint+(getpoint*100));
		char.TalkToCli(charaindex, -1, "ÃæÀü¿Ï·á" .. getpoint.."¸í¼º Æ÷ÀÎÆ®£¡", "»ÆÉ«");
	else
		return ;
	end
	
	char.DelItem(charaindex, haveitemindex);
end

function main()
	item.addLUAListFunction( "ITEM_SetPoint", "SetPoint", "");
end
