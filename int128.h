// int128.h: interface for the CHSInt128 class. 
// 
////////////////////////////////////////////////////////////////////// 
 
 
#if !defined(AFX_INT100_H__44379E2E_9CCE_11D6_879C_D4EFB1FC566C__INCLUDED_) 
#define AFX_INT100_H__44379E2E_9CCE_11D6_879C_D4EFB1FC566C__INCLUDED_ 
 
#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000 
 
#include "alu.h" 
//////////////////////////////////////////////////////////////////////// 
 
/* 
 127				 0 
+-----------------------+ 
| m_D | m_C | m_B | m_A | 
+-----------------------+ 
*/ 
 
 
 
class CHSInt128  : private CALU 
{ 
public: 
	DWORD	m_A;												// Low 32 Bit 
	DWORD	m_B; 
	DWORD	m_C;	 
	DWORD	m_D;												// Heigh 32 Bit 
 
public: 
	CHSInt128		( const int		 nValue  ); 
	CHSInt128		( const long	 lValue  ); 
	CHSInt128		( const __int64& nnValue ); 
	CHSInt128		( const UINT	 uValue  ); 
	CHSInt128		( const DWORD	 dwValue ); 
	CHSInt128		( const UINT64&	 nnValue ); 
	CHSInt128		( const CHSInt128& iValue  ); 
	CHSInt128		(); 
	virtual			~CHSInt128(); 
 
	bool			ToStr		( CString& strValue ); 
	bool			FromStr		( LPCTSTR lpszValue ); 
	CHSInt128&		operator=	( const CHSInt128& iValue ); 
	 
	CHSInt128		operator-	( const CHSInt128& iValue );	// const; 
	CHSInt128&		operator-=	( const CHSInt128& iValue ); 
	CHSInt128		operator+	( const CHSInt128& iValue );	// const; 
	CHSInt128&		operator+=	( const CHSInt128& iValue ); 
	CHSInt128		operator*	( const CHSInt128& iValue ) const; 
	CHSInt128&		operator*=	( const CHSInt128& iValue ); 
	CHSInt128		operator/	( const CHSInt128& iValue ) const; 
	CHSInt128&		operator/=	( const CHSInt128& iValue ); 
	CHSInt128		operator%	( const CHSInt128& iValue ) const; 
	CHSInt128&		operator%=	( const CHSInt128& iValue ); 
 
	CHSInt128&		operator++	( void );						// ++n		 
	CHSInt128&		operator--	( void );						// --n	 
	CHSInt128		operator++	( int );						// n++			 
	CHSInt128		operator--	( int );						// n-- 
 
	CHSInt128		operator^	( const CHSInt128& iValue ) const; 
	CHSInt128		operator&	( const CHSInt128& iValue ) const; 
	CHSInt128		operator|	( const CHSInt128& iValue ) const; 
	CHSInt128		operator~	( void ) const; 
 
	CHSInt128&		operator^=	( const CHSInt128& iValue ); 
	CHSInt128&		operator&=	( const CHSInt128& iValue ); 
	CHSInt128&		operator|=	( const CHSInt128& iValue ); 
 
	CHSInt128		operator<< 	( const UINT nShift ); 
	CHSInt128&		operator<<= ( const UINT nShift ); 
	CHSInt128		operator>>  ( const UINT nShift ); 
	CHSInt128&		operator>>= ( const UINT nShift ); 
 
	bool			operator==	( const CHSInt128& iValue ) const; 
	bool			operator!=	( const CHSInt128& iValue ) const; 
	bool			operator>	( const CHSInt128& iValue ) const; 
	bool			operator<	( const CHSInt128& iValue ) const; 
	bool			operator>=	( const CHSInt128& iValue ) const; 
	bool			operator<=	( const CHSInt128& iValue ) const; 
/* 
	operator	int(); 
	operator	unsigned int(); 
	operator	long(); 
	operator	unsigned long(); 
	operator	__int64(); 
	operator	unsigned __int64(); 
*/ 
 
	void			SetPositiveFlag	 ( void ); 
	void			SetNegativeFlag	 ( void ); 
	void			Complement		 ( void ); 
	void			ComplementInverse( void ); 
	void			Min				 ( void ); 
	void			Max				 ( void ); 
	void			Zero			 ( void ); 
	void			SetAt			 ( UINT uIndex, bool bSet ); 
 
	bool			IsZero			 ( void ) const; 
	bool			IsNegative		 ( void ) const; 
	bool			IsPositive		 ( void ) const; 
	bool			GetAt			 ( UINT uIndex ) const; 
	CHSInt128		GetRight		 ( UINT uCount ) const; 
	CHSInt128		GetLeft			 ( UINT uCount ) const; 
 
	void		Division			 ( const CHSInt128& iDivisor, CHSInt128& iQuotient, CHSInt128& iRemainder) const; 
 
}; 
 
#endif // !defined(AFX_INT100_H__44379E2E_9CCE_11D6_879C_D4EFB1FC566C__INCLUDED_) 