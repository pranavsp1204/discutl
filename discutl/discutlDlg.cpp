
// discutlDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "discutl.h"
#include "discutlDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "atlstr.h"
#include <string.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "atlconv.h"
#include <vector>
#include <array>
#include <variant>
#include <boost/variant.hpp>
#include <afxtempl.h>
#include <boost/lexical_cast.hpp>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
namespace js = boost::property_tree;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdiscutlDlg dialog



CdiscutlDlg::CdiscutlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DISCUTL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdiscutlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit1);
	DDX_Control(pDX, IDC_EDIT2, edit2);
	DDX_Control(pDX, IDC_EDIT3, edit3);
	DDX_Control(pDX, IDC_EDIT4, edit4);
	DDX_Control(pDX, IDC_EDIT5, edit5);
	DDX_Control(pDX, IDC_EDIT6, edit6);
	DDX_Control(pDX, IDC_EDIT7, edit7);
	DDX_Control(pDX, IDC_EDIT8, edit8);
}

BEGIN_MESSAGE_MAP(CdiscutlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SAVEJSON, &CdiscutlDlg::OnBnClickedSavejson)
END_MESSAGE_MAP()


// CdiscutlDlg message handlers

BOOL CdiscutlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here
	SetWindowPos(NULL, 0, 0, 400, 300, SWP_NOMOVE | SWP_NOZORDER);
	ModifyStyle(WS_THICKFRAME, 0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CdiscutlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CdiscutlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CdiscutlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdiscutlDlg::OnBnClickedSavejson()
{
	// TODO: Add your control notification handler code here
	savejson();
	
	
}

CString CdiscutlDlg::getwintxt(CEdit& x)
{
	CString val;
	x.GetWindowText(val);
	return val;
}

void CdiscutlDlg::savejson()
{
	updatevalarr();
	ifstream file("C:/Users/prana/Desktop/dsccontent.json");
	
	js::read_json(file, pt);

	js::ptree& val = pt.get_child("discovryList");

	
	objcreate(1, objkey);
	objcreate(2, objkey);
	objcreate(3, objkey);
	objcreate(4, objkey);
	objcreate(5, objkey);
	
	
	pagecontentarr.push_back(make_pair("", pagecontent));
	moreinfoarr.push_back(make_pair("", moreinfo));
	page.add_child("pageContent", pagecontentarr);
	page.add_child("moreInfo", moreinfoarr);
	discoverylist.put(objkey[1], 1);
	discoverylist.add_child("cue", cue);
	discoverylist.add_child("page", page);
	discoverylist.add_child("trial", trial);

	int j = valarr.GetSize();
	CString message;
	message.Format(_T("The value is: %d"), j);

	val.push_front(make_pair("", discoverylist));

	try {
		js::write_json("C:/Users/prana/Desktop/dsccontent.json", pt);
		
		AfxMessageBox(message);
	}
	catch (const std::exception& e) {
		std::cerr << "Error creating or writing JSON file: " << e.what() << std::endl;
	}
}

void CdiscutlDlg::objcreate(int count, std::string arr[])
{
	boost::property_tree::ptree obj;

	if (count == 1) {
		for (int i = 5; i < 10; i++) {
			obj.put(arr[i], CT2A(valarr.GetAt(i)));
		}
		cue = obj;
		obj.clear();
		AfxMessageBox(_T("1"));
	}
	if (count == 2) {
		for (int i = 10; i < 16; i++) {
			obj.put(arr[i], CT2A(valarr.GetAt(i)));
		}
		pagecontent = obj;
		obj.clear();
		AfxMessageBox(_T("2"));
	}
	if (count == 3) {
		for (int i = 16; i < 21; i++) {
			obj.put(arr[i], CT2A(valarr.GetAt(i)));
		}
		moreinfo = obj;
		obj.clear();
		AfxMessageBox(_T("3"));
	}
	if (count == 4) {
		for (int i = 21; i < 26; i++) {
			obj.put(arr[i], CT2A(valarr.GetAt(i)));
		}
		trial = obj;
		obj.clear();
		AfxMessageBox(_T("4"));
	}
	if (count == 5) {
		for (int i = 0; i < 5; i++) {
			obj.put(arr[i], CT2A(valarr.GetAt(i)));
		}
		discoverylist = obj;
		obj.clear();
		AfxMessageBox(_T("5"));
	}
		
	
}

void CdiscutlDlg::updatevalarr()
{
	
	
	for (int i = 0; i < 26; i++) {
		int flag = 0;
		int valid_values[] = { 0, 2, 5, 6, 10, 11, 12, 14, 16, 19 };
		for (int value : valid_values) {
			if (i == value) {
				flag = 1;
				switch (i) {
				case 0:valarr.Add(getwintxt(edit1));
					break;
				case 2:valarr.Add(getwintxt(edit2));
					break;
				case 5:valarr.Add(getwintxt(edit3));
					break;
				case 6:valarr.Add(getwintxt(edit4));
					break;
				case 10:valarr.Add(getwintxt(edit5));
					break;
				case 11:valarr.Add(nullptr);
					break;
				case 12:valarr.Add(getwintxt(edit6));
					break;
				case 14:valarr.Add(nullptr);
					break;
				case 16:valarr.Add(getwintxt(edit7));
					break;
				case 19:valarr.Add(getwintxt(edit8));
					break;
				}
				break;
			}

		}
		if (flag == 0) {
			valarr.Add(nullptr);
			flag = 0;
		}
	}
}

