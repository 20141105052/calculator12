
// calculatorDlg.h : ͷ�ļ�
//

#pragma once


// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialogEx
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void check(CString &ts);
public:
	afx_msg void OnClicked1();
	CString m_str;
	int flag;
	double x,y,secag,minag,hag;
	double temp;
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDec();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedChu();
	afx_msg void OnBnClickedcalculator();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedpingfang();
	afx_msg void OnBnClickedkaifang();
	afx_msg void OnBnClickedbaifen();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedyuanzhoulv();
	afx_msg void OnBnClickedSin();
	afx_msg void OnBnClickedCos();
	afx_msg void OnBnClickedTan();
	afx_msg void OnBnClickedDao();
	afx_msg void OnBnClickedLog();
	afx_msg void OnBnClickedLn();
	afx_msg void OnBnClickedZf();
	afx_msg void OnBnClickedExit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
