// CalcDlg.cpp : implementation file   
//   
   
#include "stdafx.h"   
#include "Calc.h"   
#include "CalcDlg.h"   
#include "int128.h"   
   
#ifdef _DEBUG   
#define new DEBUG_NEW   
#undef THIS_FILE   
static char THIS_FILE[] = __FILE__;   
#endif   
   
/////////////////////////////////////////////////////////////////////////////   
// CAboutDlg dialog used for App About   
   
class CAboutDlg : public CDialog   
{   
public:   
    CAboutDlg();   
   
// Dialog Data   
    //{{AFX_DATA(CAboutDlg)   
    enum { IDD = IDD_ABOUTBOX };   
    //}}AFX_DATA   
   
    // ClassWizard generated virtual function overrides   
    //{{AFX_VIRTUAL(CAboutDlg)   
    protected:   
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support   
    //}}AFX_VIRTUAL   
   
// Implementation   
protected:   
    //{{AFX_MSG(CAboutDlg)   
    //}}AFX_MSG   
    DECLARE_MESSAGE_MAP()   
};   
   
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)   
{   
    //{{AFX_DATA_INIT(CAboutDlg)   
    //}}AFX_DATA_INIT   
}   
   
void CAboutDlg::DoDataExchange(CDataExchange* pDX)   
{   
    CDialog::DoDataExchange(pDX);   
    //{{AFX_DATA_MAP(CAboutDlg)   
    //}}AFX_DATA_MAP   
}   
   
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)   
    //{{AFX_MSG_MAP(CAboutDlg)   
        // No message handlers   
    //}}AFX_MSG_MAP   
END_MESSAGE_MAP()   
   
/////////////////////////////////////////////////////////////////////////////   
// CCalcDlg dialog   
   
CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)   
    : CDialog(CCalcDlg::IDD, pParent)   
{   
    //{{AFX_DATA_INIT(CCalcDlg)   
    m_strDisplay = _T(" 0");   
    m_strAbout = _T("×÷Õß: º«ËÉ EMail : hs_china@yahoo.com.cn");   
    //}}AFX_DATA_INIT   
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32   
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);   
   
    m_cOperator = ' ';   
}   
   
void CCalcDlg::DoDataExchange(CDataExchange* pDX)   
{   
    CDialog::DoDataExchange(pDX);   
    //{{AFX_DATA_MAP(CCalcDlg)   
    DDX_Text(pDX, IDC_DISPLAY, m_strDisplay);   
    DDX_Text(pDX, IDC_EDIT1, m_strAbout);   
    //}}AFX_DATA_MAP   
}   
   
BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)   
    //{{AFX_MSG_MAP(CCalcDlg)   
    ON_WM_SYSCOMMAND()   
    ON_WM_PAINT()   
    ON_WM_QUERYDRAGICON()   
    ON_WM_CTLCOLOR()   
    //}}AFX_MSG_MAP   
END_MESSAGE_MAP()   
   
/////////////////////////////////////////////////////////////////////////////   
// CCalcDlg message handlers   
   
BOOL CCalcDlg::OnInitDialog()   
{   
    CDialog::OnInitDialog();   
   
    // Add "About..." menu item to system menu.   
   
    // IDM_ABOUTBOX must be in the system command range.   
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);   
    ASSERT(IDM_ABOUTBOX < 0xF000);   
   
    CMenu* pSysMenu = GetSystemMenu(FALSE);   
    if (pSysMenu != NULL)   
    {   
        CString strAboutMenu;   
        strAboutMenu.LoadString(IDS_ABOUTBOX);   
        if (!strAboutMenu.IsEmpty())   
        {   
            pSysMenu->AppendMenu(MF_SEPARATOR);   
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);   
        }   
    }   
   
    SetIcon(m_hIcon, TRUE);         // Set big icon   
    SetIcon(m_hIcon, FALSE);        // Set small icon   
       
    // TODO: Add extra initialization here   
       
    return TRUE;  // return TRUE  unless you set the focus to a control   
}   
   
void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)   
{   
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)   
    {   
        CAboutDlg dlgAbout;   
        dlgAbout.DoModal();   
    }   
    else   
    {   
        CDialog::OnSysCommand(nID, lParam);   
    }   
}   
   
void CCalcDlg::OnPaint()    
{   
    if (IsIconic())   
    {   
        CPaintDC dc(this);   
   
        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);   
   
        // Center icon in client rectangle   
        int cxIcon = GetSystemMetrics(SM_CXICON);   
        int cyIcon = GetSystemMetrics(SM_CYICON);   
        CRect rect;   
        GetClientRect(&rect);   
        int x = (rect.Width() - cxIcon + 1) / 2;   
        int y = (rect.Height() - cyIcon + 1) / 2;   
   
        // Draw the icon   
        dc.DrawIcon(x, y, m_hIcon);   
    }   
    else   
    {   
        CDialog::OnPaint();   
    }   
}   
   
HCURSOR CCalcDlg::OnQueryDragIcon()   
{   
    return (HCURSOR) m_hIcon;   
}   
   
LRESULT CCalcDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)    
{   
    switch ( message )   
    {   
        case WM_COMMAND:   
            TranslateInfo( LOWORD( wParam ) );   
            break;   
    }   
       
    return CDialog::WindowProc(message, wParam, lParam);   
}   
   
void CCalcDlg::TranslateInfo(UINT uID)   
{   
    switch ( uID )   
    {   
        case IDC_NUM0:  UpdateDisp( '0' );  break;   
        case IDC_NUM1:  UpdateDisp( '1' );  break;   
        case IDC_NUM2:  UpdateDisp( '2' );  break;   
        case IDC_NUM3:  UpdateDisp( '3' );  break;   
        case IDC_NUM4:  UpdateDisp( '4' );  break;   
        case IDC_NUM5:  UpdateDisp( '5' );  break;   
        case IDC_NUM6:  UpdateDisp( '6' );  break;   
        case IDC_NUM7:  UpdateDisp( '7' );  break;   
        case IDC_NUM8:  UpdateDisp( '8' );  break;   
        case IDC_NUM9:  UpdateDisp( '9' );  break;   
   
        case IDC_CLEAR:   
        case IDC_FLAG:   
        case IDC_BACK:   
        case IDC_RESULT:   
        case IDC_MAX:   
        case IDC_MIN:   
            TranslateManage( uID );   
            break;   
   
        case IDC_ADD:   
        case IDC_SUB:   
        case IDC_MUL:   
        case IDC_DIV:   
        case IDC_MOD:   
            TranslateOperator( uID );   
            break;   
    }   
}   
   
// Update Display    
void CCalcDlg::UpdateDisp(char cAppNum, UINT uFlag)   
{   
    if ( GetState( STA_FIRSTOK ) )   
    {   
        SetState( STA_FIRSTOK, false );   
        UpdateDisp( 0, UD_CLEAR );   
    }   
   
    switch ( uFlag )   
    {   
        case UD_APPEND:   
            {   
                int nLength = m_strDisplay.GetLength();   
   
                if ( nLength > 39 )  return;   
   
                if ( nLength == 2 && m_strDisplay[1] == '0' )   
                {   
                    m_strDisplay.SetAt( 1, cAppNum );   
                }   
                else    m_strDisplay += cAppNum;   
            }   
            break;   
   
        case UD_CLEAR:   
            m_strDisplay = _T(" 0");   
            break;   
   
        case UD_FLAG:   
            if ( m_strDisplay[0] == '-' )   
                 m_strDisplay.SetAt( 0, ' ' );   
            else m_strDisplay.SetAt( 0, '-' );   
            break;   
   
        case UD_BACK:   
            {   
                int nLength = m_strDisplay.GetLength();   
                if ( nLength == 2 )   
                     UpdateDisp( 0, UD_CLEAR );   
                else m_strDisplay = m_strDisplay.Left( nLength - 1 );   
            }   
            break;   
   
        case UD_RESULT:   
            m_iTarget.ToStr( m_strDisplay );   
            break;   
   
        case UD_MAX:   
            m_iTarget.Max();   
            m_iTarget.ToStr( m_strDisplay );   
            m_iTarget.Zero();   
            break;   
   
        case UD_MIN:   
            m_iTarget.Min();   
            m_iTarget.ToStr( m_strDisplay );   
            m_iTarget.Zero();   
            break;   
    }   
   
    UpdateData( false );   
}   
   
void CCalcDlg::TranslateManage(UINT uID)   
{   
    switch ( uID )   
    {   
        case IDC_CLEAR:   
            m_cOperator = ' ';   
            m_iSource.Zero();   
            m_iTarget.Zero();   
            SetState( STA_FIRSTOK, false );   
            UpdateDisp( 0, UD_CLEAR );   
            break;   
   
        case IDC_FLAG:   
            UpdateDisp( 0, UD_FLAG );   
            break;   
   
        case IDC_BACK:   
            UpdateDisp( 0, UD_BACK );   
            break;   
   
        case IDC_RESULT:   
            StartCalc();   
            m_cOperator = ' ';   
            UpdateDisp( 0, UD_RESULT );   
            break;   
   
        case IDC_MAX:   
            UpdateDisp( 0, UD_MAX );   
            break;   
   
        case IDC_MIN:   
            UpdateDisp( 0, UD_MIN );   
            break;   
    }   
}   
   
// Set Operator and others Informatrion   
// Compute( if Need )      
void CCalcDlg::TranslateOperator(UINT uID)   
{   
    if ( !GetState( STA_FIRSTOK ) )   
    {   
        StartCalc();   
        m_iSource.FromStr( m_strDisplay.GetBuffer( 0 ) );   
        SetState( STA_FIRSTOK, true );   
    }   
   
    switch ( uID )   
    {   
        case IDC_ADD:   
            m_cOperator = '+';   
            break;   
   
        case IDC_SUB:   
            m_cOperator = '-';   
            break;   
   
        case IDC_MUL:   
            m_cOperator = '*';   
            break;   
   
        case IDC_DIV:   
            m_cOperator = '/';   
            break;   
   
        case IDC_MOD:   
            m_cOperator = '%';   
            break;   
    }   
}   
   
// Start Compute    
bool CCalcDlg::StartCalc()   
{   
    // Get the Second Source    
    m_iTarget.FromStr( m_strDisplay.GetBuffer( 0 ) );   
   
    switch ( m_cOperator )   
    {   
        case '+':   
            m_iTarget += m_iSource;   
            break;   
   
        case '-':   
            m_iTarget = ( m_iSource - m_iTarget );   
            break;   
   
        case '*':   
            m_iTarget *= m_iSource;   
            break;   
   
        case '/':   
            if ( m_iTarget.IsZero() )      
            {   
                MessageBox( "³ýÊý²»ÄÜÎªÁã !", "´íÎó", MB_ICONERROR );   
                return false;   
            }   
                   
            m_iTarget = ( m_iSource / m_iTarget );   
            break;   
   
        case '%':   
            if ( m_iTarget.IsZero() )      
            {   
                MessageBox( "³ýÊý²»ÄÜÎªÁã !", "´íÎó", MB_ICONERROR );   
                return false;   
            }   
   
            m_iTarget = ( m_iSource % m_iTarget );   
            break;   
   
        default:   
            return false;   
    }   
   
    // Output Result   
    UpdateDisp( 0, UD_RESULT );   
   
    return true;   
}   
   
inline void CCalcDlg::SetState(UINT uState, bool bSet)   
{   
    if ( bSet )   
         m_uState |= uState;   
    else m_uState &= ~uState;   
}   
   
inline bool CCalcDlg::GetState(UINT uState)   
{   
    return ( ( m_uState & uState ) != 0 );   
}   
   
HBRUSH CCalcDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)    
{   
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);   
       
    if ( *pWnd == *GetDlgItem( IDC_DISPLAY ) )   
        pDC->SetTextColor( RGB( 0, 138, 204 ) );   
       
    return hbr;   
}   

 