/*
Navicat MySQL Data Transfer

Source Server         : shiqimax
Source Server Version : 50095
Source Host           : sa85.shiqimax.com:3306
Source Database       : sa85

Target Server Type    : MYSQL
Target Server Version : 50095
File Encoding         : 65001

Date: 2019-03-05 23:53:22
*/

CREATE DATABASE `sa` CHARACTER SET euckr COLLATE euckr_korean_ci;
USE `sa`;
SET NAMES 'euckr';

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for CostCard
-- ----------------------------
DROP TABLE IF EXISTS `CostCard`;
CREATE TABLE `CostCard` (
  `Card` char(255) NOT NULL,
  `CardCf` int(11) default '0',
  `CardData` int(11) NOT NULL default '0',
  `CardType` int(11) NOT NULL default '0',
  `CardAccount` char(255) character set gb2312 NOT NULL,
  `CardName` char(255) character set gb2312 NOT NULL,
  `CardTime` int(255) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for CSA_Email
-- ----------------------------
DROP TABLE IF EXISTS `CSA_Email`;
CREATE TABLE `CSA_Email` (
  `Id` bigint(14) NOT NULL,
  `Title` varchar(255) character set gb2312 default NULL COMMENT '邮件标题',
  `Content` varchar(255) character set gb2312 default NULL COMMENT '邮件文本内容',
  `Account` varchar(255) default NULL,
  `SaveIndex` int(11) default NULL,
  `FJ1` varchar(255) character set gb2312 default NULL COMMENT '附件1名称',
  `FJ2` varchar(255) character set gb2312 default NULL COMMENT '附件2名称',
  `FJ3` varchar(255) character set gb2312 default NULL,
  `FJ4` varchar(255) character set gb2312 default NULL,
  `FJ5` varchar(255) character set gb2312 default NULL,
  `Type1` int(11) default '0',
  `Type2` int(11) default '0',
  `Type3` int(11) default '0',
  `Type4` int(11) default '0',
  `Type5` int(11) default '0',
  `FJId1` int(11) default '-1',
  `FJId2` int(11) default '-1',
  `FJId3` int(11) default '-1',
  `FJId4` int(11) default '-1',
  `FJId5` int(11) default '-1',
  `FJLock1` int(11) default '0',
  `FJLock2` int(11) default '0',
  `FJLock3` int(11) default '0',
  `FJLock4` int(11) default '0',
  `FJLock5` int(11) default '0',
  `Point1` int(11) default '0',
  `Point2` int(11) default '0',
  `Point3` int(11) default '0',
  `Point4` int(11) default '0'
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for CSA_Halo
-- ----------------------------
DROP TABLE IF EXISTS `CSA_Halo`;
CREATE TABLE `CSA_Halo` (
  `id` int(11) NOT NULL auto_increment,
  `Account` varchar(255) default NULL,
  `SaveIndex` int(11) default NULL,
  `Data01` int(11) default '0',
  `Data02` int(11) default '0',
  `Data03` int(11) default '0',
  `Data04` int(11) default '0',
  `Data05` int(11) default '0',
  `Data06` int(11) default '0',
  `Data07` int(11) default '0',
  `Data08` int(11) default '0',
  `Data09` int(11) default '0',
  `Data10` int(11) default '0',
  `Data11` int(11) default '0',
  `Data12` int(11) default '0',
  `Data13` int(11) default '0',
  `Data14` int(11) default '0',
  `Data15` int(11) default '0',
  `Data16` int(11) default '0',
  `Data17` int(11) default '0',
  `Data18` int(11) default '0',
  `Data19` int(11) default '0',
  `Data20` int(11) default '0',
  `Data21` int(11) default '0',
  `Data22` int(11) default '0',
  `Data23` int(11) default '0',
  `Data24` int(11) default '0',
  `Data25` int(11) default '0',
  `Data26` int(11) default '0',
  `Data27` int(11) default '0',
  `Data28` int(11) default '0',
  `Data29` int(11) default '0',
  `Data30` int(11) default '0',
  `Data31` int(11) default '0',
  `Data32` int(11) default '0',
  `Data33` int(11) default '0',
  `Data34` int(11) default '0',
  `Data35` int(11) default '0',
  `Data36` int(11) default '0',
  `Data37` int(11) default '0',
  `Data38` int(11) default '0',
  `Data39` int(11) default '0',
  `Data40` int(11) default '0',
  `Data41` int(11) default '0',
  `Data42` int(11) default '0',
  `Data43` int(11) default '0',
  `Data44` int(11) default '0',
  `Data45` int(11) default '0',
  `Data46` int(11) default '0',
  `Data47` int(11) default '0',
  `Data48` int(11) default '0',
  `Data49` int(11) default '0',
  `Data50` int(11) default '0',
  `Time01` int(32) default '0',
  `Time02` int(32) default '0',
  `Time03` int(32) default '0',
  `Time04` int(32) default '0',
  `Time05` int(32) default '0',
  `Time06` int(32) default '0',
  `Time07` int(32) default '0',
  `Time08` int(32) default '0',
  `Time09` int(32) default '0',
  `Time10` int(32) default '0',
  `Time11` int(32) default '0',
  `Time12` int(32) default '0',
  `Time13` int(32) default '0',
  `Time14` int(32) default '0',
  `Time15` int(32) default '0',
  `Time16` int(32) default '0',
  `Time17` int(32) default '0',
  `Time18` int(32) default '0',
  `Time19` int(32) default '0',
  `Time20` int(32) default '0',
  `Time21` int(32) default '0',
  `Time22` int(32) default '0',
  `Time23` int(32) default '0',
  `Time24` int(32) default '0',
  `Time25` int(32) default '0',
  `Time26` int(32) default '0',
  `Time27` int(32) default '0',
  `Time28` int(32) default '0',
  `Time29` int(32) default '0',
  `Time30` int(32) default '0',
  `Time31` int(32) default '0',
  `Time32` int(32) default '0',
  `Time33` int(32) default '0',
  `Time34` int(32) default '0',
  `Time35` int(32) default '0',
  `Time36` int(32) default '0',
  `Time37` int(32) default '0',
  `Time38` int(32) default '0',
  `Time39` int(32) default '0',
  `Time40` int(32) default '0',
  `Time41` int(32) default '0',
  `Time42` int(32) default '0',
  `Time43` int(32) default '0',
  `Time44` int(32) default '0',
  `Time45` int(32) default '0',
  `Time46` int(32) default '0',
  `Time47` int(32) default '0',
  `Time48` int(32) default '0',
  `Time49` int(32) default '0',
  `Time50` int(32) default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=285 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for CSA_Login
-- ----------------------------
DROP TABLE IF EXISTS `CSA_Login`;
CREATE TABLE `CSA_Login` (
  `Name` varchar(16) character set euckr collate euckr_korean_ci NOT NULL,
  `PassWord` varchar(40) NOT NULL default '',
  `SafePasswd` varchar(40) NOT NULL default '',
  `JFPoint` int(11) default '0',
  `RMBPoint` int(11) default '0',
  `VipPoint` int(11) NOT NULL default '0',
  `IP` varchar(16) character set euckr NOT NULL default '',
  `MAC1` varchar(255) NOT NULL default '',
  `MAC2` varchar(255) NOT NULL default '',
  `MAC3` varchar(255) NOT NULL default '',
  `Path` varchar(1024) NOT NULL default '',
  `RightChar` varchar(128) character set euckr NOT NULL default '',
  `LeftChar` varchar(128) character set euckr NOT NULL default '',
  `Online` int(11) default '0',
  `Offline` int(11) default '0',
  `LoginTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `RegTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `Qq` varchar(24) character set euckr collate euckr_korean_ci default NULL,
  `E_Mail` varchar(64) NOT NULL default '',
  `IPhone` varchar(255) default NULL,
  `FuLi` int(11) default '0',
  `Lock` int(11) default '0',
  PRIMARY KEY  (`Name`)
) ENGINE=MyISAM DEFAULT CHARSET=euckr;

-- ----------------------------
-- Table structure for CSA_Mac
-- ----------------------------
DROP TABLE IF EXISTS `CSA_Mac`;
CREATE TABLE `CSA_Mac` (
  `Forbidden` varchar(128) character set gb2312 NOT NULL default '',
  PRIMARY KEY  (`Forbidden`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for CSA_MaxIp
-- ----------------------------
DROP TABLE IF EXISTS `CSA_MaxIp`;
CREATE TABLE `CSA_MaxIp` (
  `Account` varchar(255) default NULL,
  `IP` varchar(255) default NULL,
  `MacId` varchar(255) default NULL,
  `CpuId` varchar(255) default NULL,
  `ServerId` int(11) default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for CSA_RedBox
-- ----------------------------
DROP TABLE IF EXISTS `CSA_RedBox`;
CREATE TABLE `CSA_RedBox` (
  `Account` varchar(255) default NULL,
  `Name` varchar(255) character set gb2312 default NULL,
  `MaxPoint` int(11) default '0',
  `Point` int(11) default '0',
  `MaxShare` int(11) default '0',
  `Share` int(11) default '0',
  `Mode` int(11) default '1',
  `Type` int(11) default '0',
  `FaliyId` int(11) default '0',
  `Time` varchar(13) default '',
  `Data` varchar(2048) character set gb2312 default '0',
  `FaliyName` varchar(255) character set gb2312 default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for CSA_Skin
-- ----------------------------
DROP TABLE IF EXISTS `CSA_Skin`;
CREATE TABLE `CSA_Skin` (
  `id` int(11) NOT NULL auto_increment,
  `Account` varchar(255) default NULL,
  `SaveIndex` int(11) default NULL,
  `Data01` int(11) default '0',
  `Data02` int(11) default '0',
  `Data03` int(11) default '0',
  `Data04` int(11) default '0',
  `Data05` int(11) default '0',
  `Data06` int(11) default '0',
  `Data07` int(11) default '0',
  `Data08` int(11) default '0',
  `Data09` int(11) default '0',
  `Data10` int(11) default '0',
  `Data11` int(11) default '0',
  `Data12` int(11) default '0',
  `Data13` int(11) default '0',
  `Data14` int(11) default '0',
  `Data15` int(11) default '0',
  `Data16` int(11) default '0',
  `Data17` int(11) default '0',
  `Data18` int(11) default '0',
  `Data19` int(11) default '0',
  `Data20` int(11) default '0',
  `Data21` int(11) default '0',
  `Data22` int(11) default '0',
  `Data23` int(11) default '0',
  `Data24` int(11) default '0',
  `Data25` int(11) default '0',
  `Data26` int(11) default '0',
  `Data27` int(11) default '0',
  `Data28` int(11) default '0',
  `Data29` int(11) default '0',
  `Data30` int(11) default '0',
  `Data31` int(11) default '0',
  `Data32` int(11) default '0',
  `Data33` int(11) default '0',
  `Data34` int(11) default '0',
  `Data35` int(11) default '0',
  `Data36` int(11) default '0',
  `Data37` int(11) default '0',
  `Data38` int(11) default '0',
  `Data39` int(11) default '0',
  `Data40` int(11) default '0',
  `Data41` int(11) default '0',
  `Data42` int(11) default '0',
  `Data43` int(11) default '0',
  `Data44` int(11) default '0',
  `Data45` int(11) default '0',
  `Data46` int(11) default '0',
  `Data47` int(11) default '0',
  `Data48` int(11) default '0',
  `Data49` int(11) default '0',
  `Data50` int(11) default '0',
  `Time01` int(32) default '0',
  `Time02` int(32) default '0',
  `Time03` int(32) default '0',
  `Time04` int(32) default '0',
  `Time05` int(32) default '0',
  `Time06` int(32) default '0',
  `Time07` int(32) default '0',
  `Time08` int(32) default '0',
  `Time09` int(32) default '0',
  `Time10` int(32) default '0',
  `Time11` int(32) default '0',
  `Time12` int(32) default '0',
  `Time13` int(32) default '0',
  `Time14` int(32) default '0',
  `Time15` int(32) default '0',
  `Time16` int(32) default '0',
  `Time17` int(32) default '0',
  `Time18` int(32) default '0',
  `Time19` int(32) default '0',
  `Time20` int(32) default '0',
  `Time21` int(32) default '0',
  `Time22` int(32) default '0',
  `Time23` int(32) default '0',
  `Time24` int(32) default '0',
  `Time25` int(32) default '0',
  `Time26` int(32) default '0',
  `Time27` int(32) default '0',
  `Time28` int(32) default '0',
  `Time29` int(32) default '0',
  `Time30` int(32) default '0',
  `Time31` int(32) default '0',
  `Time32` int(32) default '0',
  `Time33` int(32) default '0',
  `Time34` int(32) default '0',
  `Time35` int(32) default '0',
  `Time36` int(32) default '0',
  `Time37` int(32) default '0',
  `Time38` int(32) default '0',
  `Time39` int(32) default '0',
  `Time40` int(32) default '0',
  `Time41` int(32) default '0',
  `Time42` int(32) default '0',
  `Time43` int(32) default '0',
  `Time44` int(32) default '0',
  `Time45` int(32) default '0',
  `Time46` int(32) default '0',
  `Time47` int(32) default '0',
  `Time48` int(32) default '0',
  `Time49` int(32) default '0',
  `Time50` int(32) default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=172 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for CSA_Title
-- ----------------------------
DROP TABLE IF EXISTS `CSA_Title`;
CREATE TABLE `CSA_Title` (
  `id` int(11) NOT NULL auto_increment,
  `Account` varchar(255) default NULL,
  `SaveIndex` int(11) default NULL,
  `Data01` int(11) default '0',
  `Data02` int(11) default '0',
  `Data03` int(11) default '0',
  `Data04` int(11) default '0',
  `Data05` int(11) default '0',
  `Data06` int(11) default '0',
  `Data07` int(11) default '0',
  `Data08` int(11) default '0',
  `Data09` int(11) default '0',
  `Data10` int(11) default '0',
  `Data11` int(11) default '0',
  `Data12` int(11) default '0',
  `Data13` int(11) default '0',
  `Data14` int(11) default '0',
  `Data15` int(11) default '0',
  `Data16` int(11) default '0',
  `Data17` int(11) default '0',
  `Data18` int(11) default '0',
  `Data19` int(11) default '0',
  `Data20` int(11) default '0',
  `Data21` int(11) default '0',
  `Data22` int(11) default '0',
  `Data23` int(11) default '0',
  `Data24` int(11) default '0',
  `Data25` int(11) default '0',
  `Data26` int(11) default '0',
  `Data27` int(11) default '0',
  `Data28` int(11) default '0',
  `Data29` int(11) default '0',
  `Data30` int(11) default '0',
  `Data31` int(11) default '0',
  `Data32` int(11) default '0',
  `Data33` int(11) default '0',
  `Data34` int(11) default '0',
  `Data35` int(11) default '0',
  `Data36` int(11) default '0',
  `Data37` int(11) default '0',
  `Data38` int(11) default '0',
  `Data39` int(11) default '0',
  `Data40` int(11) default '0',
  `Data41` int(11) default '0',
  `Data42` int(11) default '0',
  `Data43` int(11) default '0',
  `Data44` int(11) default '0',
  `Data45` int(11) default '0',
  `Data46` int(11) default '0',
  `Data47` int(11) default '0',
  `Data48` int(11) default '0',
  `Data49` int(11) default '0',
  `Data50` int(11) default '0',
  `Time01` int(32) default '0',
  `Time02` int(32) default '0',
  `Time03` int(32) default '0',
  `Time04` int(32) default '0',
  `Time05` int(32) default '0',
  `Time06` int(32) default '0',
  `Time07` int(32) default '0',
  `Time08` int(32) default '0',
  `Time09` int(32) default '0',
  `Time10` int(32) default '0',
  `Time11` int(32) default '0',
  `Time12` int(32) default '0',
  `Time13` int(32) default '0',
  `Time14` int(32) default '0',
  `Time15` int(32) default '0',
  `Time16` int(32) default '0',
  `Time17` int(32) default '0',
  `Time18` int(32) default '0',
  `Time19` int(32) default '0',
  `Time20` int(32) default '0',
  `Time21` int(32) default '0',
  `Time22` int(32) default '0',
  `Time23` int(32) default '0',
  `Time24` int(32) default '0',
  `Time25` int(32) default '0',
  `Time26` int(32) default '0',
  `Time27` int(32) default '0',
  `Time28` int(32) default '0',
  `Time29` int(32) default '0',
  `Time30` int(32) default '0',
  `Time31` int(32) default '0',
  `Time32` int(32) default '0',
  `Time33` int(32) default '0',
  `Time34` int(32) default '0',
  `Time35` int(32) default '0',
  `Time36` int(32) default '0',
  `Time37` int(32) default '0',
  `Time38` int(32) default '0',
  `Time39` int(32) default '0',
  `Time40` int(32) default '0',
  `Time41` int(32) default '0',
  `Time42` int(32) default '0',
  `Time43` int(32) default '0',
  `Time44` int(32) default '0',
  `Time45` int(32) default '0',
  `Time46` int(32) default '0',
  `Time47` int(32) default '0',
  `Time48` int(32) default '0',
  `Time49` int(32) default '0',
  `Time50` int(32) default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4623 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Data_Enemy
-- ----------------------------
DROP TABLE IF EXISTS `Data_Enemy`;
CREATE TABLE `Data_Enemy` (
  `Name` varchar(255) character set gb2312 default NULL,
  `EnemyId` int(255) default NULL,
  `EnemyBaseId` int(255) default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Data_Halo
-- ----------------------------
DROP TABLE IF EXISTS `Data_Halo`;
CREATE TABLE `Data_Halo` (
  `ID` int(11) NOT NULL,
  `NAME` varchar(255) character set gb2312 default NULL,
  `HP` int(11) default '0',
  `STR` int(11) default '0',
  `TGH` int(11) default '0',
  `DEX` int(11) default '0',
  `IMAGE` int(11) default NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Data_Itemset
-- ----------------------------
DROP TABLE IF EXISTS `Data_Itemset`;
CREATE TABLE `Data_Itemset` (
  `Name` varchar(255) character set gb2312 default NULL,
  `Id` int(11) default NULL,
  `Title` varchar(255) character set gb2312 default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Data_LianChong
-- ----------------------------
DROP TABLE IF EXISTS `Data_LianChong`;
CREATE TABLE `Data_LianChong` (
  `Account` varchar(255) default NULL,
  `SaveIndex` int(11) default NULL,
  `Name` varchar(255) character set gb2312 default NULL,
  `Base1` int(11) default NULL,
  `Base2` int(11) default NULL,
  `Base3` int(11) default NULL,
  `Base4` int(11) default NULL,
  `GrowUp` float(11,5) default NULL,
  `Power` int(11) default NULL,
  `Unicode` varchar(255) NOT NULL,
  `Time` int(11) default NULL,
  `Jiang` int(11) default '0',
  `Id` int(11) NOT NULL auto_increment,
  `Att1` int(11) default NULL,
  `Att2` int(11) default NULL,
  `Att3` int(11) default NULL,
  `Att4` int(11) default NULL,
  PRIMARY KEY  (`Id`,`Unicode`)
) ENGINE=MyISAM AUTO_INCREMENT=2090 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Data_Skin
-- ----------------------------
DROP TABLE IF EXISTS `Data_Skin`;
CREATE TABLE `Data_Skin` (
  `ID` int(11) NOT NULL,
  `NAME` varchar(255) character set gb2312 default NULL,
  `HP` int(11) default NULL,
  `STR` int(11) default NULL,
  `TGH` int(11) default NULL,
  `DEX` int(11) default NULL,
  `IMAGE1` int(11) default NULL,
  `IMAGE2` int(11) default NULL,
  `IMAGE3` int(11) default NULL,
  `IMAGE4` int(11) default NULL,
  `IMAGE5` int(11) default NULL,
  `IMAGE6` int(11) default NULL,
  `IMAGE7` int(11) default NULL,
  `IMAGE8` int(11) default NULL,
  `IMAGE9` int(11) default NULL,
  `IMAGE10` int(11) default NULL,
  `IMAGE11` int(11) default NULL,
  `IMAGE12` int(11) default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Data_Title
-- ----------------------------
DROP TABLE IF EXISTS `Data_Title`;
CREATE TABLE `Data_Title` (
  `ID` int(11) NOT NULL,
  `NAME` varchar(255) character set gb2312 default NULL,
  `HP` int(11) default '0',
  `STR` int(11) default '0',
  `TGH` int(11) default '0',
  `DEX` int(11) default '0',
  `IMAGE` int(11) default NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for fmpointdata
-- ----------------------------
DROP TABLE IF EXISTS `fmpointdata`;
CREATE TABLE `fmpointdata` (
  `id` int(11) NOT NULL,
  `num` int(11) default '0',
  `time` int(11) default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Pet_RanKing
-- ----------------------------
DROP TABLE IF EXISTS `Pet_RanKing`;
CREATE TABLE `Pet_RanKing` (
  `PetName` varchar(255) character set gb2312 default NULL COMMENT '宠物名字',
  `PlayerName` varchar(255) character set gb2312 default NULL COMMENT '人物名',
  `PlayerAccount` varchar(255) default NULL COMMENT '玩家帐号',
  `EnemyBaseId` int(11) default '0' COMMENT '宠物编号',
  `Image` int(11) default '0' COMMENT '宠物图像',
  `InitLv` int(11) default '0' COMMENT '初始等级',
  `InitAtt1` int(11) default '0' COMMENT '初始血',
  `InitAtt2` int(11) default '0' COMMENT '初始攻',
  `InitAtt3` int(11) default '0' COMMENT '初始防',
  `InitAtt4` int(11) default '0' COMMENT '初始敏',
  `Lv` int(11) default '0' COMMENT '现在等级',
  `Att1` int(11) default '0' COMMENT '现在血',
  `Att2` int(11) default '0' COMMENT '现在攻',
  `Att3` int(11) default '0' COMMENT '现在防',
  `Att4` int(11) default '0' COMMENT '现在敏',
  `Land` int(11) default '0' COMMENT '地属性',
  `Water` int(11) default '0' COMMENT '水属性',
  `Fire` int(11) default '0' COMMENT '火属性',
  `Wind` int(11) default '0' COMMENT '风属性',
  `GrowUp` float(11,5) default NULL COMMENT '成长率',
  `Score` int(11) default '0' COMMENT '战斗力',
  `Trans` int(11) default '0' COMMENT '转生',
  `Unicode` varchar(255) NOT NULL COMMENT '唯一码',
  PRIMARY KEY  (`Unicode`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for PetHuiLu
-- ----------------------------
DROP TABLE IF EXISTS `PetHuiLu`;
CREATE TABLE `PetHuiLu` (
  `EnemyBase` int(11) default NULL,
  `Enemy` int(11) default NULL,
  `Point` int(11) default NULL,
  `Name` varchar(255) character set gb2312 default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;



DROP TABLE IF EXISTS `PET_Rank`;
CREATE TABLE `PET_Rank` (
  `id` varchar(255) NOT NULL,
  `enemybase_id` int(11) NOT NULL,
  `enemy_id` int(11) NOT NULL,
  `owner_name` varchar(45) NOT NULL,
  `level` int(11) NOT NULL,
  `reincarnate` int(11) NOT NULL,
  `stats_hp` int(11) NOT NULL,
  `stats_atk` int(11) NOT NULL,
  `stats_def` int(11) NOT NULL,
  `stats_spd` int(11) NOT NULL,
  `stats_total` int(11) NOT NULL,
  `growth_hp` float NOT NULL,
  `growth_atk` float NOT NULL,
  `growth_def` float NOT NULL,
  `growth_spd` float NOT NULL,
  `growth_total` float NOT NULL,
  `updated_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=euckr;

DELIMITER $$
CREATE DEFINER=`root`@`%` PROCEDURE `sp_PetRank`(IN p_UID VARCHAR(255),
	IN P_OWNER VARCHAR( 33 ),
	IN p_EBID INT(11),
	IN p_EID INT(11),
	IN p_LV INT(11),
	IN p_RB INT(11),
	IN p_HP INT(11),
	IN p_ATK INT(11),
	IN p_DEF INT(11),
	IN p_SPD INT(11),
	IN p_TOTAL INT(11),
	IN p_GHP FLOAT,
	IN p_GATK FLOAT,
	IN p_GDEF FLOAT,
	IN p_GSPD FLOAT,
	IN p_GTOTAL FLOAT
)
BEGIN
DECLARE ID VARCHAR(256);
INSERT INTO `sa`.`PET_Rank`
(`id`,
`enemybase_id`,
`enemy_id`,
`owner_name`,
`level`,
`reincarnate`,
`stats_hp`,
`stats_atk`,
`stats_def`,
`stats_spd`,
`stats_total`,
`growth_hp`,
`growth_atk`,
`growth_def`,
`growth_spd`,
`growth_total`
) 
VALUES 
(p_UID,
p_EBID,
p_EID,
P_OWNER,
p_LV,
p_RB,
p_HP,
p_ATK,
p_DEF,
p_SPD,
p_TOTAL,
p_GHP,
p_GATK,
p_GDEF,
p_GSPD,
p_GTOTAL) 
ON DUPLICATE KEY UPDATE 
`owner_name`=p_OWNER,
`level`=p_LV, 
`reincarnate`=p_RB, 
`stats_hp`=p_HP, 
`stats_atk`=p_ATK, 
`stats_def`=p_DEF, 
`stats_spd`=p_SPD, 
`stats_total`=p_TOTAL, 
`growth_hp`=p_GHP,
`growth_atk`=p_GATK, 
`growth_def`=p_GDEF,
`growth_spd`=p_GSPD,
`growth_total`=p_GTOTAL, 
`updated_time`= CURRENT_TIMESTAMP;

SELECT `id` INTO ID FROM `PET_Rank` WHERE `enemybase_id` = p_EBID ORDER BY `stats_total` DESC, `growth_total` DESC, `updated_time` ASC LIMIT 1 OFFSET 10;
IF( ID IS NOT NULL ) THEN
	DELETE FROM `PET_Rank` WHERE `id` = ID;
END IF;
END$$
DELIMITER ;





