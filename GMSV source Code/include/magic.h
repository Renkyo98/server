#ifndef __MAGIC_H__
#define __MAGIC_H__

/* ÈÈÖî */
int MAGIC_Use( int charaindex, int haveitemindex, int toindex);

int MAGIC_Recovery( int charaindex, int toindex,int marray, int mp );
int MAGIC_OtherRecovery( int charaindex, int toindex, int marray, int mp );
int	MAGIC_FieldAttChange( int charaindex, int toindex, int marray, int mp );
int	MAGIC_StatusChange( int charaindex, int toindex, int marray, int mp );
#ifdef _MAGIC_DEEPPOISON
int	MAGIC_StatusChange2( int charaindex, int toindex, int marray, int mp );
#endif
int	MAGIC_StatusRecovery( int charaindex, int toindex, int marray, int mp );
int	MAGIC_MagicDef( int charaindex, int toindex, int marray, int mp );
int	MAGIC_Ressurect( int charaindex, int toindex, int marray, int mp );
int	MAGIC_AttReverse( int charaindex, int toindex, int marray, int mp );
int	MAGIC_ResAndDef( int charaindex, int toindex, int marray, int mp );
#ifdef _OTHER_MAGICSTAUTS
int	MAGIC_MagicStatusChange( int charaindex, int toindex, int marray, int mp );
#endif
#ifdef _ATTACK_MAGIC
int     MAGIC_AttMagic( int charaindex , int toindex , int marray , int mp );
#endif
#ifdef _ITEM_METAMO
int MAGIC_Metamo( int charaindex, int toindex,int marray, int mp );
#endif

#ifdef _ITEM_ATTSKILLMAGIC
int MAGIC_AttSkill( int charaindex, int toindex,int marray, int mp );
#endif
#ifdef _MAGIC_WEAKEN// vincent  ¾«Áé:ĞéÈõ
int	MAGIC_Weaken( int charaindex, int toindex, int marray, int mp );
#endif
#ifdef _MAGIC_BARRIER// vincent  ¾«Áé:Ä§ÕÏ
int	MAGIC_Barrier( int charaindex, int toindex, int marray, int mp );
#endif
#ifdef _MAGIC_NOCAST// vincent  ¾«Áé:³ÁÄ¬
int	MAGIC_Nocast( int charaindex, int toindex, int marray, int mp );
#endif
#ifdef _MAGIC_TOCALL
int MAGIC_ToCallDragon( int charaindex, int toindex,int marray, int mp );
#endif

//----------------------------------------------------------------------
// Ê§ÄÌ  Ø©¼°ŞË  ¾®ÈÕÈÈÖî  Ä¯Ã«ß¯ÔÊ
//
int MAGIC_GetArrayNo(
	int charaindex, 	// Æ½ÅÒ·ÂÛÍÕıÄÌ¼ş·¸ÓÀÛÍµ©
	int haveitemindex   //    ÔÈ»¯ÔÂÊ§ÄÌ  Ø©¼°ŞË  
);
//
//----------------------------------------------------------------------
//-------------------------------------------------------------------
//
//  ÈÈÖîÃ«  ÌÎÒøµ¤
//
int MAGIC_DirectUse(
	int charaindex, // Òøµ¤Æ½ÅÒ·Â¼°ÄÌ¼ş·¸ÓÀÛÍµ©
	int marray, 	// Òøµ¤ÈÈÖî¼°ÄÌ¼ş·¸ÓÀÛÍµ©
	int toindex, 	// ²¾±åÒøµ¤£¢
	int itemnum
);
//
//-------------------------------------------------------------------

#endif 

