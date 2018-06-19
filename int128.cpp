// int128.cpp: implementation of the CHSInt128 class.   
//   
//////////////////////////////////////////////////////////////////////   
   
#include "stdafx.h"   
#include "int128.h"   
#include "alu.h"   
   
#ifdef _DEBUG   
#undef THIS_FILE   
static char THIS_FILE[]=__FILE__;   
#define new DEBUG_NEW   
#endif   
   
//////////////////////////////////////////////////////////////////////   
// Construction/Destruction   
//////////////////////////////////////////////////////////////////////   
   
// Default   
CHSInt128::CHSInt128()   
{   
    m_A = m_B = m_C = m_D = 0;   
}   
   
CHSInt128::~CHSInt128()   
{   
   
}   
   
// unsigned int   
CHSInt128::CHSInt128(const UINT uValue)   
{      
    *this = CHSInt128( (DWORD)uValue );   
}   
   
// int   
CHSInt128::CHSInt128(const int nValue)   
{   
    if ( nValue < 0 )   
    {   
        *this = CHSInt128( DWORD( -nValue ) );   
        Complement();   
    }   
    else   
    {   
        *this = CHSInt128( (DWORD)nValue );   
    }   
}   
   
// unsigned long   
CHSInt128::CHSInt128(const DWORD dwValue)   
{   
    m_D = m_B = m_C = 0;       
   
    m_A = dwValue;   
}   
   
// long   
CHSInt128::CHSInt128(const long lValue)   
{   
    if ( lValue < 0 )   
    {   
        *this = CHSInt128( (DWORD)( -lValue ) );   
        Complement();   
    }   
    else   
    {   
        *this = CHSInt128( (DWORD)lValue );   
    }   
}   
   
// unsigned __int64   
CHSInt128::CHSInt128(const UINT64 &nnValue)   
{   
    m_D = m_C = 0;   
   
    m_B = HI32( nnValue );   
    m_A = LO32( nnValue );     
}          
                                                   
// __int64   
CHSInt128::CHSInt128(const __int64 &nnValue)   
{   
    if ( nnValue < 0 )   
    {   
        *this = CHSInt128( (UINT64)(-nnValue) );   
        Complement();   
    }   
    else   
    {   
        *this = CHSInt128( (UINT64)nnValue );   
    }   
}   
   
// CHSInt128   
CHSInt128::CHSInt128(const CHSInt128 &iValue)   
{   
    m_A = iValue.m_A;   
    m_B = iValue.m_B;   
    m_C = iValue.m_C;   
    m_D = iValue.m_D;   
}   
   
// Operator =   
CHSInt128& CHSInt128::operator =(const CHSInt128& iValue)   
{   
    m_A = iValue.m_A;   
    m_B = iValue.m_B;   
    m_C = iValue.m_C;   
    m_D = iValue.m_D;   
   
    return *this;   
}   
   
// Operator +   
CHSInt128 CHSInt128::operator +(const CHSInt128 &iValue)   
{   
    CHSInt128  iTemp;   
   
    ADD( iTemp.m_A, m_A, iValue.m_A );   
    ADC( iTemp.m_B, m_B, iValue.m_B );   
    ADC( iTemp.m_C, m_C, iValue.m_C );   
    ADC( iTemp.m_D, m_D, iValue.m_D );   
   
    return iTemp;   
}   
   
// Operator ++n   
CHSInt128& CHSInt128::operator ++()   
{   
    *this = *this + CHSInt128( 1 );   
   
    return  *this;   
}   
   
// Operator n++   
CHSInt128 CHSInt128::operator ++( int )   
{   
    CHSInt128    iTemp( *this );   
   
    *this = *this + CHSInt128( 1 );   
   
    return  iTemp;   
}   
   
// Operator +=   
CHSInt128& CHSInt128::operator +=(const CHSInt128 &iValue)   
{   
    *this = *this + iValue;   
   
    return *this;   
}   
   
// Operator -   
CHSInt128 CHSInt128::operator -(const CHSInt128 &iValue)   
{   
    CHSInt128   iTemp;   
   
    SUB( iTemp.m_A, m_A, iValue.m_A );   
    SBB( iTemp.m_B, m_B, iValue.m_B );   
    SBB( iTemp.m_C, m_C, iValue.m_B );   
    SBB( iTemp.m_D, m_D, iValue.m_B );   
   
    return iTemp;   
}   
   
// Operator --n   
CHSInt128& CHSInt128::operator --()   
{   
    *this = *this - CHSInt128( 1 );   
   
    return *this;   
}   
   
// Operator n--   
CHSInt128 CHSInt128::operator --( int )   
{   
    CHSInt128    iTemp( *this );   
   
    *this = *this - CHSInt128( 1 );   
   
    return  iTemp;   
}   
   
// Operator -=   
CHSInt128& CHSInt128::operator -=(const CHSInt128 &iValue)   
{   
    *this = *this - iValue;   
   
    return *this;   
}   
   
// Operator &   
CHSInt128 CHSInt128::operator &(const CHSInt128 &iValue) const   
{   
    CHSInt128    iTemp;   
   
    iTemp.m_A  = m_A & iValue.m_A;   
    iTemp.m_B  = m_B & iValue.m_B;   
    iTemp.m_C  = m_C & iValue.m_C;   
    iTemp.m_D  = m_D & iValue.m_D;   
   
    return iTemp;   
}   
   
// Operator &=   
CHSInt128& CHSInt128::operator &=(const CHSInt128 &iValue)   
{   
    *this = *this & iValue;   
       
    return *this;   
}   
   
// Operator |   
CHSInt128 CHSInt128::operator |(const CHSInt128 &iValue) const   
{   
    CHSInt128    iTemp;   
   
    iTemp.m_A  = m_A | iValue.m_A;   
    iTemp.m_B  = m_B | iValue.m_B;   
    iTemp.m_C  = m_C | iValue.m_C;   
    iTemp.m_D  = m_D | iValue.m_D;   
   
    return iTemp;   
}   
   
// Operator |=   
CHSInt128& CHSInt128::operator |=(const CHSInt128 &iValue)   
{   
    *this = *this | iValue;   
   
    return *this;   
}   
   
// Operator ^   
CHSInt128 CHSInt128::operator ^(const CHSInt128 &iValue) const   
{   
    CHSInt128    iTemp;   
   
    iTemp.m_A  = m_A ^ iValue.m_A;   
    iTemp.m_B  = m_B ^ iValue.m_B;   
    iTemp.m_C  = m_C ^ iValue.m_C;   
    iTemp.m_D  = m_D ^ iValue.m_D;   
   
    return iTemp;   
}   
   
// Operator ^=   
CHSInt128& CHSInt128::operator ^=(const CHSInt128 &iValue)   
{   
    *this = *this ^ iValue;   
   
    return *this;   
}   
   
// Operator ~   
CHSInt128 CHSInt128::operator ~() const   
{   
    CHSInt128    iTemp;   
   
    iTemp.m_A  = ~m_A;   
    iTemp.m_B  = ~m_B;   
    iTemp.m_C  = ~m_C;   
    iTemp.m_D  = ~m_D;   
   
    return iTemp;   
}   
   
// Operator <<   
CHSInt128 CHSInt128::operator <<( const UINT uShift)   
{   
    CHSInt128   iTemp( *this );   
   
    UINT    uShiftN = ( uShift / 32 );   
    UINT    uShiftL = ( uShift % 32 );   
   
    for ( UINT iN=0; iN<uShiftN; iN++ )   
    {   
        SHL( iTemp.m_D, 32 );   
        SHL( iTemp.m_D, iTemp.m_C, 32 );   
        SHL( iTemp.m_C, iTemp.m_B, 32 );   
        SHL( iTemp.m_B, iTemp.m_A, 32 );   
    }   
   
    if ( uShiftL > 0 )   
    {   
        SHL( iTemp.m_D, uShiftL );   
        SHL( iTemp.m_D, iTemp.m_C, uShiftL );   
        SHL( iTemp.m_C, iTemp.m_B, uShiftL );   
        SHL( iTemp.m_B, iTemp.m_A, uShiftL );   
    }          
   
    return iTemp;   
}   
   
// Operator <<=   
CHSInt128& CHSInt128::operator <<=( const UINT uShift )   
{   
    *this = ( *this << uShift );   
   
    return *this;   
}   
   
// Operator >>    
CHSInt128 CHSInt128::operator >>(const UINT uShift)   
{   
    CHSInt128    iTemp( *this );   
   
    UINT    uShiftN = ( uShift / 32 );   
    UINT    uShiftL = ( uShift % 32 );   
   
    for ( UINT iN=0; iN<uShiftN; iN++ )   
    {   
        SHR( iTemp.m_A, 32 );   
        SHR( iTemp.m_B, iTemp.m_A, 32 );   
        SHR( iTemp.m_C, iTemp.m_B, 32 );   
        SHR( iTemp.m_D, iTemp.m_C, 32 );   
    }   
   
    if ( uShiftL > 0 )   
    {   
        SHR( iTemp.m_A, uShiftL );   
        SHR( iTemp.m_B, iTemp.m_A, uShiftL );   
        SHR( iTemp.m_C, iTemp.m_B, uShiftL );   
        SHR( iTemp.m_D, iTemp.m_C, uShiftL );   
    }   
   
    return iTemp;   
}   
   
// Operator >>=   
CHSInt128& CHSInt128::operator >>=(const UINT uShift)   
{   
    *this = ( *this >> uShift );   
   
    return *this;   
}   
   
// Operator ==   
bool CHSInt128::operator ==(const CHSInt128 &iValue) const   
{   
    return ( ( m_A == iValue.m_A ) &&   
             ( m_B == iValue.m_B ) &&   
             ( m_C == iValue.m_C ) &&   
             ( m_D == iValue.m_D )    
            );   
}   
   
// Operator !=   
bool CHSInt128::operator !=(const CHSInt128 &iValue) const   
{   
    return ( ( m_A != iValue.m_A ) ||   
             ( m_B != iValue.m_B ) ||   
             ( m_C != iValue.m_C ) ||   
             ( m_D != iValue.m_D )    
            );   
}   
   
// Operator >   
bool CHSInt128::operator >(const CHSInt128& iValue ) const   
{   
    if ( m_D > iValue.m_D ) return true;   
    if ( m_D < iValue.m_D ) return false;   
   
    if ( m_C > iValue.m_C )  return true;   
    if ( m_C < iValue.m_C ) return false;   
   
    if ( m_B > iValue.m_B )  return true;   
    if ( m_B < iValue.m_B )  return false;   
   
    if ( m_A > iValue.m_A )  return true;   
    if ( m_A < iValue.m_A )  return false;   
   
    return false;   
}   
   
// Operator >=   
bool CHSInt128::operator >=(const CHSInt128& iValue ) const   
{   
    return ( ( *this > iValue )  || ( *this == iValue ) );   
}   
   
// Operator <   
bool CHSInt128::operator <(const CHSInt128& iValue ) const   
{   
    if ( m_D < iValue.m_D ) return true;   
    if ( m_D > iValue.m_D ) return false;   
   
    if ( m_C < iValue.m_C )  return true;   
    if ( m_C > iValue.m_C ) return false;   
   
    if ( m_B < iValue.m_B )  return true;   
    if ( m_B > iValue.m_B )  return false;   
   
    if ( m_A < iValue.m_A )  return true;   
    if ( m_A > iValue.m_A )  return false;   
   
    return false;   
}   
   
// Operator <=   
bool CHSInt128::operator <=(const CHSInt128& iValue ) const   
{   
    return ( ( *this < iValue )  || ( *this == iValue ) );   
}   
   
// Operator *   
CHSInt128 CHSInt128::operator *(const CHSInt128 &iValue) const   
{   
    CHSInt128   iResult;   
   
    CHSInt128 iT1( ((UINT64)m_A)*((UINT64)iValue.m_A) );   
    CHSInt128 iT2( ((UINT64)m_B)*((UINT64)iValue.m_A) );   
    CHSInt128 iT3( ((UINT64)m_C)*((UINT64)iValue.m_A) );   
    CHSInt128 iT4( ((UINT64)m_D)*((UINT64)iValue.m_A) );   
       
    iResult += iT1;    
    iResult += ( iT2 << 32 );   
    iResult += ( iT3 << 64 );   
    iResult += ( iT4 << 96 );   
   
    CHSInt128 iT5( ((UINT64)m_A)*((UINT64)iValue.m_B) );   
    CHSInt128 iT6( ((UINT64)m_B)*((UINT64)iValue.m_B) );   
    CHSInt128 iT7( ((UINT64)m_C)*((UINT64)iValue.m_B) );   
       
    iResult += ( iT5 << 32 );   
    iResult += ( iT6 << 64 );   
    iResult += ( iT7 << 96 );   
   
    CHSInt128 iT8( ((UINT64)m_A)*((UINT64)iValue.m_C) );   
    CHSInt128 iT9( ((UINT64)m_B)*((UINT64)iValue.m_C) );   
       
    iResult += ( iT8 << 64 );   
    iResult += ( iT9 << 96 );   
   
    CHSInt128 iT0( ((UINT64)m_A)*((UINT64)iValue.m_D) );   
       
    iResult += ( iT0 << 96 );   
   
    return iResult;   
}   
   
// Operator *=   
CHSInt128& CHSInt128::operator *=(const CHSInt128 &iValue)   
{   
    *this = *this * iValue;   
   
    return *this;   
}   
   
// Operator /   
CHSInt128 CHSInt128::operator /(const CHSInt128 &iValue) const   
{   
    CHSInt128 iQuotient;   
    CHSInt128 iRemainder;   
   
    Division( iValue, iQuotient,iRemainder );      
   
    return iQuotient;   
}   
   
// Operator /=   
CHSInt128& CHSInt128::operator /=(const CHSInt128 &iValue)   
{   
    *this = *this / iValue;   
   
    return *this;   
}   
   
// Operator %   
CHSInt128 CHSInt128::operator %(const CHSInt128 &iValue) const   
{   
    CHSInt128 iQuotient;   
    CHSInt128 iRemainder;   
   
    Division( iValue, iQuotient, iRemainder );   
   
    return iRemainder;   
}   
   
// Operator %=   
CHSInt128& CHSInt128::operator %=(const CHSInt128 &iValue)   
{   
    *this = *this % iValue;   
       
    return *this;   
}   
   
// Complement   
void CHSInt128::Complement( void )   
{   
    NOT( m_A  );   
    NOT( m_B );   
    NOT( m_C );   
    NOT( m_D  );   
   
    *this = *this + CHSInt128( 1 );;   
}   
   
// Inverse Complement   
void CHSInt128::ComplementInverse( void )   
{   
    *this = *this - CHSInt128( 1 );;   
   
    NOT( m_A  );   
    NOT( m_B );   
    NOT( m_C );   
    NOT( m_D  );   
}   
   
// If Value is Positive return true   
bool CHSInt128::IsPositive( void ) const   
{   
    return ( ( m_D & 0X80000000 ) == 0X00000000 );   
}   
   
// Return true, If its Negative   
bool CHSInt128::IsNegative( void ) const   
{   
    return ( ( m_D & 0X80000000 ) == 0X80000000 );   
}   
   
// Set Negative Flag   
void CHSInt128::SetNegativeFlag( void )   
{   
    OR ( m_D, 0X80000000 );    
}   
   
// Set Positive Flag   
void CHSInt128::SetPositiveFlag( void )   
{   
    AND( m_D, 0X7FFFFFFF );   
}   
   
// Division   
void CHSInt128::Division(const CHSInt128 &iDivisor, CHSInt128 &iQuotient, CHSInt128 &iRemainder) const   
{   
    if ( iDivisor == CHSInt128( 0 ) )   
    {   
        __asm   
        {   
            mov eax, 0   
            div eax   
        }   
    }   
   
    iQuotient.Zero();   
    iRemainder.Zero();   
   
    // 原码加减交替法计算 X/Y   
    CHSInt128 iTempR0;                  // R0 : Remainder   
    CHSInt128 iTempR1 ( *this );            // R1 : Quotient   
    CHSInt128 iTempR2 ( iDivisor );     // R2 : Divisor   
   
    // if Dividend is Zero, No Need Calc   
    if ( iTempR1.IsZero() ) return;   
   
    bool    bDivrNegative = false, bDivdNegative = false;   
   
    // 将补码转换为原码   
    if ( iTempR1.IsNegative() )   
    {   
        iTempR1.ComplementInverse();   
        bDivdNegative = true;   
    }   
    else iTempR1.SetAt( 127, 0 );   
   
    // 将补码转换为原码   
    if ( iDivisor.IsNegative() )   
    {   
        iTempR2.ComplementInverse();   
        bDivrNegative = true;   
    }   
    else iTempR2.SetAt( 127, 0 );   
   
    iTempR0 -= iTempR2;   
   
    for ( UINT iN = 0; iN < 128; iN++ )   
    {   
        iTempR0 <<= 1;   
   
        // Move iTempR1(High Bit) to iTempR0(Low Bit)   
        if ( iTempR1.GetAt( 127 ) )    
             iTempR0.SetAt( 0, 1 );   
   
        iTempR1 <<= 1;   
   
        if ( iTempR0.GetAt( 127 ) )   
        {   
            iTempR0 += iTempR2;   
        }   
        else   
        {   
            iTempR1.SetAt( 0, 1 );   
            iTempR0 -= iTempR2;   
        }   
    }              
   
    iTempR1 <<= 1;   
   
    if ( !iTempR0.GetAt( 127 ) )   
    {   
        iTempR1.SetAt( 0, 1 );   
    }   
    else iTempR0 += iTempR2;   
   
    if ( bDivrNegative ^ bDivdNegative )   
    {   
        iTempR1.Complement();   
    }   
   
    iQuotient  = iTempR1;   
    iRemainder = iTempR0;   
}   
   
// Set or Clear one bit where you want   
void CHSInt128::SetAt(UINT uIndex, bool bSet)   
{   
    DWORD   dwBitAt = ( 0X00000001 << (uIndex % 32 ) );   
   
    if ( bSet )   
    {   
        if ( uIndex < 32 )   
            m_A |= dwBitAt;   
        else   
        if ( uIndex < 64 )   
            m_B |= dwBitAt;   
        else   
        if ( uIndex < 96 )   
            m_C |= dwBitAt;   
        else   
            m_D |= dwBitAt;   
    }   
    else   
    {   
        if ( uIndex < 32 )   
            m_A &= ~dwBitAt;   
        else   
        if ( uIndex < 64 )   
            m_B &= ~dwBitAt;   
        else   
        if ( uIndex < 96 )   
            m_C &= ~dwBitAt;   
        else   
            m_D &= ~dwBitAt;   
    }   
}   
   
// Get Bit At ...   
bool CHSInt128::GetAt(UINT uIndex) const   
{   
    DWORD   dwBitAt = ( 0X00000001 << (uIndex % 32 ) );   
   
    if ( uIndex < 32 )   return ( ( m_A & dwBitAt ) != 0 );   
    else   
    if ( uIndex < 64 )   return ( ( m_B & dwBitAt ) != 0 );   
    else   
    if ( uIndex < 96 )   return ( ( m_C & dwBitAt ) != 0 );   
    else   
                        return ( ( m_D & dwBitAt ) != 0 );   
}   
   
// Is Me Zero ?   
bool CHSInt128::IsZero() const   
{   
    return ( m_D == 0 &&   
             m_C == 0 &&   
             m_B == 0 &&   
             m_A == 0    
            );   
}   
   
// Set Me Zero   
void CHSInt128::Zero()   
{   
    m_A = m_B = m_C = m_D = 0;   
}   
   
// Get CHSInt128 Left   
CHSInt128 CHSInt128::GetLeft(UINT uCount) const   
{   
    CHSInt128 iTemp( *this );   
   
    iTemp >>= ( 128 - uCount );   
   
    return iTemp;   
}   
   
// Get Right uCount bit   
CHSInt128 CHSInt128::GetRight(UINT uCount) const   
{   
    CHSInt128 iTemp( *this );   
   
    iTemp <<= ( 128 - uCount );   
    iTemp >>= ( 128 - uCount );   
   
    return iTemp;   
}   
   
// Set Me Max   
void CHSInt128::Max()   
{   
    m_D = 0X7FFFFFFF;   
   
    m_C = m_B = m_A = 0XFFFFFFFF;   
}   
   
// Set Me Min   
void CHSInt128::Min()   
{   
    m_D = 0X80000000;   
   
    m_C = m_B = m_A = 0X00000000;      
}   
   
   
// Change From String Integer to CHSInt128   
bool CHSInt128::FromStr(LPCTSTR lpszValue)   
{   
    CHSInt128   iTemp;   
    CString strSrc = lpszValue;   
    int     nLength, nIndex = 0;   
    bool    bNegative = false;   
    char    cSrc;   
           
    strSrc.TrimLeft();   
    strSrc.TrimRight();   
   
    if ( strSrc[0] == '-' )   
    {   
        bNegative = true;   
        nIndex = 1;   
    }   
   
    if ( ( nLength = strSrc.GetLength() ) > 40 )    
        nLength = 40;   
       
    while ( nIndex < nLength )   
    {   
        cSrc = strSrc[nIndex];   
   
        if (  cSrc < _T('0') || cSrc > _T('9') )  return false;   
   
        iTemp *= 10;   
        iTemp += CHSInt128( (int)( cSrc - _T('0') ) );   
   
        nIndex++;   
    }   
   
    *this = iTemp;   
   
    if ( bNegative )    Complement();   
   
    return true;   
}   
   
// Translate from CHSInt128 to CString   
bool CHSInt128::ToStr(CString &strValue)   
{   
    CHSInt128   iTemp( *this );   
    char    cTarget;   
   
    strValue = _T("");   
   
    do   
    {   
        cTarget = ( (char)((int)( ( iTemp % 10 ).m_A )) + _T('0') );   
   
        strValue += cTarget;   
   
        iTemp /= 10;   
   
    } while( !iTemp.IsZero() );   
   
    strValue += ' ';   
    strValue.MakeReverse();   
   
    if ( IsNegative() )        
         strValue.SetAt( 0, '-' );   
   
    return true;   
}   
/*  
CHSInt128::operator int()  
{  
    return ( (int)m_A );  
}  
  
CHSInt128::operator unsigned int()  
{  
    return ( (unsigned int)m_A );  
}  
  
CHSInt128::operator long()  
{  
    return ( (long)m_A );  
}  
  
CHSInt128::operator unsigned long()  
{  
    return ( (unsigned long)m_A );  
}  
  
CHSInt128::operator __int64()  
{  
    return ( ( ((__int64)(m_B))<<32 ) + (__int64)m_A );  
}  
  
CHSInt128::operator unsigned __int64()  
{  
    return ( ( ((unsigned __int64)(m_B))<<32 ) + (unsigned __int64)m_A );  
}  
*/  