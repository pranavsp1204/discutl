
// discutlDlg.h : header file
//

#pragma once
#include <vector>
#include <string>
#include "atlstr.h"
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "atlconv.h"
#include <array>
#include <variant>
#include <boost/variant.hpp>
#include <afxtempl.h>

// CdiscutlDlg dialog
class CdiscutlDlg : public CDialogEx
{
// Construction
public:
	CdiscutlDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DISCUTL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit edit1;
	CEdit edit2;
	CEdit edit3;
	CEdit edit4;
	CEdit edit5;
	CEdit edit6;
	CEdit edit7;
	CEdit edit8;
	CString empty;
	afx_msg void OnBnClickedSavejson();
	//CString valarr[26];
	afx_msg CString getwintxt(CEdit& x);
	afx_msg void savejson();
	std::string objkey[26] = { "id","state","category","activeDate","bookmark", "title","description","icon","environment","version","title","image","description","environment","video","audio","id","state","expiryDate","link","onboardinglink","id","state","expiryDate","link","onboardinglink" };
	//std::string objcue[5] = { "title","description","icon","environment","version", };
	//std::string objpagecontent[6] = { "title","image","description","environment","video","audio" };
	//std::string objmoreinfo[5] = {"id","state","expiryDate","link","onboardingLink"};
	//std::string objtrial[5] = { "id","state","expiryDate","link","onboardingLink" };
	//std::string objmi[5] = { "id","state","expiryDate","link","onboardinglink" };

	afx_msg void objcreate(int count, std::string arr[]);
	
	
	//typedef boost::variant<int, CString, std::string> MyVariant;
	CArray<CString> valarr;
	afx_msg void updatevalarr();

	boost::property_tree::ptree pt;
	boost::property_tree::ptree cue;
	boost::property_tree::ptree pagecontent;
	boost::property_tree::ptree moreinfo;
	boost::property_tree::ptree page;
	boost::property_tree::ptree discoverylist;
	boost::property_tree::ptree pagecontentarr;
	boost::property_tree::ptree moreinfoarr;
	boost::property_tree::ptree trial;

};


