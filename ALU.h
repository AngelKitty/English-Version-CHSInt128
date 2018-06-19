// ALU.h: interface for the CALU class. 
// 
////////////////////////////////////////////////////////////////////// 
 
#if !defined(AFX_ALU_H__1B2838C0_9CDB_11D6_879C_A66C3336830C__INCLUDED_) 
#define AFX_ALU_H__1B2838C0_9CDB_11D6_879C_A66C3336830C__INCLUDED_ 
 
#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000 
 
#define			OF			0X0800 
#define			DF			0X0400 
#define			IF			0X0200 
#define			TF			0X0100 
#define			SF			0X0080 
#define			ZF			0X0040 
#define			AF			0X0010 
#define			PF			0X0004 
#define			CF			0X0001 
 
//	 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0    
//	+-----------------------------------------------+ 
//	|  |  |  |  |OF|DF|IF|TF|SF|ZF|  |AF|  |PF|  |CF|       
//	+-----------------------------------------------+ 
 
//#define			LO32 ( (nn_Temp) )		( (unsigned long)( ( (nn_Temp) & ( (unsigned __int64)(0X00000000FFFFFFFF))		 ) )   ) 
//#define			HI32 ( (nn_Temp) )		( (unsigned long)( ( (nn_Temp) & (((unsigned __int64)(0XFFFFFFFF00000000)) >> 32 ) ) ) ) 
 
#define			NOFLAG		0 
#define			MAX			0XFFFFFFFF 
 
typedef unsigned __int64	UINT64; 
 
class CALU   
{ 
public: 
	void MUL( UINT64& DST, DWORD SRC1, DWORD SRC2 ); 
	inline void ADD ( DWORD& DST, DWORD SRC ); 
	inline void ADC ( DWORD& DST, DWORD SRC ); 
		   void ADD ( DWORD& DST, DWORD SRC1, DWORD SRC2 ); 
		   void ADC ( DWORD& DST, DWORD SRC1, DWORD SRC2 ); 
 
	inline void SUB ( DWORD& DST, DWORD SRC ); 
	inline void SBB ( DWORD& DST, DWORD SRC ); 
		   void SUB ( DWORD& DST, DWORD SRC1, DWORD SRC2 ); 
		   void SBB ( DWORD& DST, DWORD SRC1, DWORD SRC2 ); 
 
		   void AND ( DWORD& DST, const DWORD SRC ); 
		   void OR  ( DWORD& DST, const DWORD SRC ); 
		   void NOT ( DWORD& DST ); 
		   void XOR ( DWORD& DST, DWORD SRC ); 
		   void TEST( const DWORD OPR1, const DWORD OPR2 ); 
 
		   void SHL	( DWORD& OPR, const UINT CNT ); 
		   void SHL	( DWORD& DST, DWORD& SRC, const UINT CNT ); 
		   void SHL	( DWORD& DSTH,DWORD& DSTL,DWORD SRC, const UINT CNT ); 
 
		   void SHR	( DWORD& OPR, const UINT CNT ); 
	   	   void SHR	( DWORD& SRC, DWORD& DST, const UINT CNT ); 
		   void SHR	( DWORD  SRC, DWORD& DSTH,DWORD& DSTL, const UINT CNT); 
 
		   void STC	( void ); 
		   void CMC	( void ); 
		   void CLC	( void ); 
 
		   DWORD HI32( const UINT64& nnTemp ); 
		   DWORD LO32( const UINT64& nnTemp ); 
 
private: 
	 
	inline void ClearPSW( const unsigned short Flag ); 
	inline void SetPSW	( const unsigned short Flag ); 
	inline bool GetPSW	( const unsigned short Flag ) const; 
	inline void SetPSW	( unsigned short Flag, const DWORD& Set ); 
 
protected: 
	 
	CALU(); 
	virtual ~CALU(); 
 
private: 
 
 
	unsigned short	PSW; 
}; 
 
#endif // !defined(AFX_ALU_H__1B2838C0_9CDB_11D6_879C_A66C3336830C__INCLUDED_) 