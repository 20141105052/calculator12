
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_str = _T("");
	
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEC, &CcalculatorDlg::OnBnClickedDec)
	ON_BN_CLICKED(IDC_MUL, &CcalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_CHU, &CcalculatorDlg::OnBnClickedChu)
	ON_BN_CLICKED(IDC_calculator, &CcalculatorDlg::OnBnClickedcalculator)
	ON_BN_CLICKED(IDC_CLEAR, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_pingfang, &CcalculatorDlg::OnBnClickedpingfang)
	ON_BN_CLICKED(IDC_kaifang, &CcalculatorDlg::OnBnClickedkaifang)
	ON_BN_CLICKED(IDC_baifen, &CcalculatorDlg::OnBnClickedbaifen)
	ON_BN_CLICKED(IDC_BACK, &CcalculatorDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_ABOUT, &CcalculatorDlg::OnBnClickedAbout)
	ON_BN_CLICKED(IDC_yuanzhoulv, &CcalculatorDlg::OnBnClickedyuanzhoulv)
	ON_BN_CLICKED(IDC_SIN, &CcalculatorDlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_COS, &CcalculatorDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_TAN, &CcalculatorDlg::OnBnClickedTan)
	ON_BN_CLICKED(IDC_DAO, &CcalculatorDlg::OnBnClickedDao)
	ON_BN_CLICKED(IDC_LOG, &CcalculatorDlg::OnBnClickedLog)
	ON_BN_CLICKED(IDC_LN, &CcalculatorDlg::OnBnClickedLn)
	ON_BN_CLICKED(IDC_ZF, &CcalculatorDlg::OnBnClickedZf)
	ON_BN_CLICKED(IDC_EXIT, &CcalculatorDlg::OnBnClickedExit)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);
	secag=-0.05;
	minag=-0.5;
	hag=3;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_str.Find(L".")==-1)
	m_str=m_str+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDec()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedChu()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedcalculator()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
	}
	
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
	}
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
	}
	if(flag==4)
	{
		temp=temp/_ttof(m_str);
		if(temp==0||_ttof(m_str)==0)
	{
		//OnBnClickedclear();
		MessageBox(L"error");
	}
	}

	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedpingfang()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp = _ttof(m_str);
	double f = temp * temp;
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedkaifang()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp = _ttof(m_str);
	if(temp<=0)
	{
		MessageBox(L"error");
	}
	double f=sqrt(temp);
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedbaifen()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	temp = _ttof(m_str);
	double f = temp/100;
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (!m_str.IsEmpty())
	{
		m_str = m_str.Left(m_str.GetLength()-1);
	}
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg dlg;
	dlg.DoModal();
}


void CcalculatorDlg::OnBnClickedyuanzhoulv()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	temp=temp*3.1415926535;
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedSin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	double f=sin(temp*3.1415926/180);
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedCos()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	double f=cos(temp*3.1415926/180);
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedTan()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	double f=tan(temp*3.1415926/180);
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDao()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp = _ttof(m_str);
	double f = 1/temp;
	if(temp==0)
	{
		MessageBox(L"error");
	}
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedLog()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp = _ttof(m_str);
	if(temp==0)
	{
		//OnBnClickedclear();
		MessageBox(L"error");
	}
	double f=log(temp);
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedLn()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp = _ttof(m_str);
	if(temp==0)
	{
		//OnBnClickedclear();
		MessageBox(L"error");
	}
	double f=log10(temp);
	if(f - int(f) <= 1e-5)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedZf()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	// 正负处理
	temp = - _ttof(m_str) ;
	// 转化为字符串
	m_str.Format( _T("%lf"), temp );
	GetDlgItem( IDC_EDIT1 )->SetWindowText( m_str ) ;
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	exit(0);
	UpdateData(false);
}




void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    CDC *pDC;
	pDC=GetDC();
	pDC->SetWindowOrg(-530,-220);
	CPen *oldpen;
	CPen groundpen(PS_SOLID,4,RGB(255,255,255));
	CPen pen(PS_SOLID,2,RGB(0,0,0));
	oldpen=pDC->SelectObject(&pen);
	pDC->Ellipse(-100,100,100,-100);
	pDC->Ellipse(-1,-1,1,1);
	pDC->TextOutW(90,-8,L"3");
	pDC->TextOutW(-98,-8,L"9");
	pDC->TextOutW(-8,-99.5,L"12");
	pDC->TextOutW(-2,83,L"6");
	


    double L1=80,L2=70,L3=60;         
	oldpen=pDC->SelectObject(&groundpen);
	x=L1*sin(secag);
	y=-L1*cos(secag);
	pDC->MoveTo(0,0);
	pDC->LineTo(x,y);
	CPen secpen(PS_SOLID,1,RGB(150,150,150));
	oldpen=pDC->SelectObject(&secpen);
	secag=secag+3.1415926/30;
	x=L1*sin(secag);
	y=-L1*cos(secag);
	pDC->MoveTo(0,0);
	pDC->LineTo(x,y);



	oldpen=pDC->SelectObject(&groundpen);
	x=L2*sin(minag);
	y=-L2*cos(minag);
	pDC->MoveTo(0,0);
	pDC->LineTo(x,y);
	CPen minpen(PS_SOLID,1.5,RGB(255,110,0));
	oldpen=pDC->SelectObject(&minpen);
	minag=minag+3.1415926/1800;
	x=L2*sin(minag);
	y=-L2*cos(minag);
	pDC->MoveTo(0,0);
	pDC->LineTo(x,y);

	oldpen=pDC->SelectObject(&groundpen);
	x=L3*sin(hag);
	y=-L3*cos(hag);
	pDC->MoveTo(0,0);
	pDC->LineTo(x,y);
	CPen hpen(PS_SOLID,2,RGB(255,0,255));
	oldpen=pDC->SelectObject(&hpen);
	hag=hag+3.1415926/21600;
	x=L3*sin(hag);
	y=-L3*cos(hag);
	pDC->MoveTo(0,0);
	pDC->LineTo(x,y);

	CDialogEx::OnTimer(nIDEvent);
}
