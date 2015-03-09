; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewGame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SixRenju.h"

ClassCount=4
Class1=CSixRenjuApp
Class2=CSixRenjuDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SIXRENJU_DIALOG
Class4=CNewGame
Resource4=IDD_NEWGAME

[CLS:CSixRenjuApp]
Type=0
HeaderFile=SixRenju.h
ImplementationFile=SixRenju.cpp
Filter=N

[CLS:CSixRenjuDlg]
Type=0
HeaderFile=SixRenjuDlg.h
ImplementationFile=SixRenjuDlg.cpp
Filter=D
LastObject=CSixRenjuDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=SixRenjuDlg.h
ImplementationFile=SixRenjuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SIXRENJU_DIALOG]
Type=1
Class=CSixRenjuDlg
ControlCount=3
Control1=IDC_NEWGAME,button,1342242816
Control2=IDC_NODECOUNT,static,1342312448
Control3=IDC_THINKPRG,msctls_progress32,1350565889

[DLG:IDD_NEWGAME]
Type=1
Class=CNewGame
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_BLACKSTONE,button,1342177289
Control3=IDC_WHITESTONE,button,1342177289
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_PLY,msctls_updown32,1342177334
Control7=IDOK,button,1342242817

[CLS:CNewGame]
Type=0
HeaderFile=NewGame.h
ImplementationFile=NewGame.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PLY

