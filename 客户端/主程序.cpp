#pragma once;
#include<windows.h>
#include"tchar.h"
#pragma comment(lib,"WS2_32.lib")
#include<iostream>
#include"net_id.h"
#include"resource.h"
#include"Linklist集合.h"
using namespace std;

#define IP "192.122.3.105"		//服务器IP地址

#define IDC_TEXT_WRITE	  5501
#define IDC_TEXT_WRITE_1  5502
#define IDC_TEXT_WRITE_2  5503
#define IDC_TEXT_WRITE_3  5504
#define IDC_TEXT_WRITE_4  5505
#define IDC_TEXT_STATIC_1 5506
#define IDC_TEXT_STATIC_2 5507
#define IDC_TEXT_STATIC_3 5508
#define IDC_BTN_OK		  5509
#define IDC_BTN_CANCEL	  5510
#define IDC_LIST		  5511
#define IDC_ADD_FRIEND	  5512
#define IDC_TEXT_WRITE_5  5513
#define IDC_BTN_SEARCH_FRIEND	  5514
#define IDC_LIST_2_CHILD  5515
#define IDC_TEXT_WRITE_6  5516
#define IDC_BTN_SEND_TO_FRIEND	  5517
#define IDC_TEXT_WRITE_7  5518
#define IDC_TEXT_WRITE_8  5519
#define IDC_TEXT_WRITE_9  5520
#define IDC_CHECKBOX_1	  5521
#define IDC_CHECKBOX_2	  5522
#define IDC_2_2_OK		  5523
#define IDC_CHECKBOX_3	  5524
//#define IDC_BTN_CHAT	  5513

/***************************************************************************************/
static HMENU hMenu;
TRACKMOUSEEVENT tme/*,tme1,tme2,tme3*/;

//密码加密相关变量
int length_num_m;
char num_z_locked[10];
char num_m_locked[16];
char num_z_unlocked[10];
char num_m_unlocked[16];
//各种变量
int flag_window_display = 1;
int flag_in_out_window=1;
int index_2=0;//消息行数
char num_send[10]={"\0\0\0\0\0\0\0\0\0"};//全局变量
int index=0;//列表行数
struct Cnode//验证信息
{
	SOCKET sock;
	char num_z[10];
	char name[16];
	char num_z1[10];
	char text[512];
};
struct fnode
{
	int f;
	//char zzzz[10];
	char num_z[10];
	char num_m[16];

}num;
pMsg *p_pMsg;
extern pMsg*head_pmsg;
char text[512];
personalmsg local_msg;
char num_local[10];
HINSTANCE happ;
char num_sys[] = "012345678";
int Flag_destory_window = 0,File_Flag_1=0;
HWND hWnd_Win_1_Main=NULL;
HWND hWnd_Win_2_Main=NULL;
HWND hWnd_Win_2_Child=NULL;
HWND hWnd_Win_2_Child_2=NULL;
HWND hWnd_Win_2_Child_3;
HWND hWnd_NULL=NULL;
TCHAR szNumBtnClass[]=TEXT("NumBtn");     //子窗口类名
FILE* pFile;
HINSTANCE hInstance_a;
HDC hdc,hdc1/*,bdc*/,mdc,mdc1,mdc2;	//三个句柄
static SOCKET sock_c;
TCHAR* szpSendBuf,*szpSendBuf_1,*recvBuf;
HWND hWnd_1;
int flag = 1;			//能否执行注册操作
//int flag_open_window=1;			//能否打开查找窗口
int timeout=0;			//线程时间
HBITMAP p1,p2,p3,p4;				//图片一,图片二
/*******************************************************************/
//回调函数变量(Win_2_Main)
HWND hWrite_2,hWrite_3,hWrite_4,hWrite_10,hWrite_11;
HWND hBtn_1,hBtn_2,hBtn_3,hBtn_4;
HWND hWrite_5;
HWND hListBox_2_Child,HListBox_2_1,HListBox_2_2;
char num_m0[16];
HWND hWrite_6,hWrite_7,hWrite_8,hWrite_9;
HWND hCbox_1,hCbox_2,hCbox_frist;
/********************************************************************/
//回调函数变量(Win_1_Main)
	int x,y;
	HWND hWrite,hWrite_1;
	char num_z[10];
	char num_m[16];
	char Name[16];
	packet pack_1,pack_2;
	packet pack_check;			//处理验证信息
/******************************************************************************************************/
HRGN BitmapToRegion (HBITMAP hBmp, COLORREF cTransparentColor = 0, COLORREF cTolerance = 0x101010);
//处理验证信息
int add_friend_or_not(Cnode msg);
//主菜单子窗口函数
void Create_Win_2_Child();
//主菜单窗口函数
void Create_Win_2_Main();
//登录窗口函数
void Create_Win_1_Main();
//主菜单子窗口函数2
void Create_Win_2_Child_2();
void Create_Win_2_Child_3();
//注册页面窗口
int CRWND(HINSTANCE hInstance);
//消息处理函数 
int deal_with_packet();
////线程计时
//void ThreadTime(int i);
//创建字体
void MakeFont(HDC hdc);
//绘图初始化函数
BOOL PicInit(HWND hWnd,HINSTANCE hInstance);
//绘图函数
BOOL Picpaint(HWND hWnd);
//鼠标函数
void Curser_1(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
	);
//连接服务器，注册
void connect_server();
//回调函数声明
LRESULT CALLBACK WinProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam);
LRESULT CALLBACK WinProc_1(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam);
LRESULT CALLBACK WndNumBtnProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK Wnd_2_2_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK Wnd_2_3_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK Wnd_edit_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
/*****************************************************************************************************/

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	)
{
	
	hInstance_a=hInstance;
	connect_server();
	CRWND(hInstance);		//注册窗口
	deal_with_packet();		//线程消息处理
	Create_Win_1_Main();	//登录窗口
	DeleteObject(p1);
	DeleteDC(mdc);
	if(Flag_destory_window==1)return 0;
	Create_Win_2_Main();
	
	
	DeleteObject(p2);
	DeleteDC(mdc);
	DeleteDC(mdc1);
	DeleteDC(mdc2);


	ClearStruct((unsigned char*)&pack_1,sizeof(packet));
	pack_1.commend=1;
	pack_1.upacket.info1.ID=CONNECT_BREAK;
	send(sock_c, (char*)&pack_1, sizeof(packet), 0);
	closesocket(sock_c);
	WSACleanup();
	return 0;
}



/************************************************************************************************/
//登录窗口函数
void Create_Win_1_Main()
{
	hWnd_Win_1_Main = CreateWindow(_T("win_c"),_T("win_c窗口"),WS_POPUP/*WS_OVERLAPPEDWINDOW*/,
									350,150,600,400,NULL,NULL,hInstance_a,NULL);//创建窗口
	

	PicInit(hWnd_Win_1_Main,hInstance_a);
	//Picpaint(hWnd_Win_1_Main);
	MoveWindow(hWnd_Win_1_Main,350,150,600,0,true);
	ShowWindow(hWnd_Win_1_Main,SW_SHOWNORMAL);//显示窗口
	UpdateWindow(hWnd_Win_1_Main);	//更新窗口

	for(int i=3;i<400;i=i+5)
	{
	MoveWindow(hWnd_Win_1_Main,350,150,600,i,true);
	Picpaint(hWnd_Win_1_Main);
	}
	MoveWindow(hWnd_Win_1_Main,350,150,600,400,true);
	UpdateWindow(hWnd_Win_1_Main);	//更新窗口
	//PicInit(hWnd_Win_1_Main,hInstance_a);
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		if (WM_KEYFIRST <= msg.message && msg.message <= WM_KEYLAST)
		{
			if(msg.wParam==VK_ESCAPE)
			{
				Flag_destory_window=1;
				SendMessage(hWnd_Win_1_Main,WM_CLOSE,0,0);
			}
			else if(msg.wParam==VK_TAB)
			{
				HWND hWnd_666=::GetFocus();
				int iID=::GetDlgCtrlID(hWnd_666);
				if(iID==5501)
					::SetFocus(hWrite_1);
			}
			else if(msg.wParam==VK_RETURN)
			{
				HWND hWnd_666=::GetFocus();
				int iID=::GetDlgCtrlID(hWnd_666);
				if(iID==5502||iID==5501)
				{
					ClearStruct((unsigned char*)&pack_1,sizeof(packet));
					memset(num_z,'\0',10);
					memset(num_m,'\0',16);
					SendMessage(hWrite, WM_GETTEXT,  10,(LPARAM)num_z);
					SendMessage(hWrite_1, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_1)+1),(LPARAM)num_m);
					if(9 != GetWindowTextLength(hWrite))
					{
						MessageBox(NULL, TEXT("9位数字"), TEXT("账号"), MB_ICONWARNING|MB_SYSTEMMODAL);
						::SetFocus(hWrite);
						continue;
					}
					if((0 == GetWindowTextLength(hWrite_1))||(GetWindowTextLength(hWrite_1)>15))
					{
						MessageBox(NULL, TEXT("15个字符以内"), TEXT("密码"), MB_ICONWARNING|MB_SYSTEMMODAL);
						::SetFocus(hWrite_1);
						continue;
					}
					if((GetWindowTextLength(hWrite)==9)&&(GetWindowTextLength(hWrite_1)>0&&GetWindowTextLength(hWrite_1)<=15))
					{
						ClearStruct((unsigned char*)&pack_1,sizeof(packet));
						pack_1.commend=1;
						pack_1.upacket.info1.ID=LOG_IN;
						strcpy_s(pack_1.upacket.info1.num_z,num_z);
						strcpy_s(pack_1.upacket.info1.num_m,num_m);
						send(sock_c, (char*)&pack_1, sizeof(packet), 0);
					}
				}
			}
			else
			{
				TranslateMessage(&msg);	//发送消息到消息队列
				DispatchMessage(&msg);	//发送消息到窗口程序
			}
		}
		else
		{
			TranslateMessage(&msg);	//发送消息到消息队列
			DispatchMessage(&msg);	//发送消息到窗口程序
		}
	}
}
//主菜单窗口函数
void Create_Win_2_Main()
{
	char text_send[512];
	char*buff;
	hWnd_Win_2_Main = CreateWindow(_T("页面"),_T("乙醛科技"),WS_POPUP/*|WS_POPUPWINDOW*/,
		300,0,800,600,NULL,NULL,hInstance_a,NULL);//创建窗口

	/*::SetWindowLong(hWnd_Win_2_Main,GWL_EXSTYLE,GetWindowLong(hWnd_Win_2_Main,GWL_EXSTYLE)|WS_EX_LAYERED);   
SetLayeredWindowAttributes(hWnd_Win_2_Main,0,(255*70)/150,LWA_ALPHA); */ 
	
	MoveWindow(hWnd_Win_2_Main,300,0,800,0,true);
	ShowWindow(hWnd_Win_2_Main,SW_SHOWNORMAL);//显示窗口
	UpdateWindow(hWnd_Win_2_Main);	//更新窗口
	//初始化图片
	
	hdc=GetDC(hWnd_Win_2_Main);
	mdc=CreateCompatibleDC(hdc);
	mdc1=CreateCompatibleDC(hdc);
	mdc2=CreateCompatibleDC(hdc);
	HBITMAP bmp = CreateCompatibleBitmap(hdc,800,600);
	SelectObject(mdc,bmp);
	//加载图片
	p2 = LoadBitmap(hInstance_a,MAKEINTRESOURCE(IDB_BITMAP1));
	/*p2=(HBITMAP)LoadImage(NULL,"./res/1.bmp",IMAGE_BITMAP,800,
		600,LR_LOADFROMFILE|LR_CREATEDIBSECTION);*/
	

	
	
	HRGN hrgn=BitmapToRegion(p2,RGB(0,0,0));
	SetWindowRgn(hWnd_Win_2_Main,hrgn,TRUE);
	/*p3=(HBITMAP)LoadImage(NULL,"./res/主页2.bmp",IMAGE_BITMAP,800,
		600,LR_LOADFROMFILE);
	p4=(HBITMAP)LoadImage(NULL,"./res/主页3.bmp",IMAGE_BITMAP,800,
		600,LR_LOADFROMFILE);*/
	SelectObject(mdc,p2);
	
	/*SelectObject(mdc1,p3);
	SelectObject(mdc2,p4);*/
	for(int i=3;i<600;i=i+5)
	{
		MoveWindow(hWnd_Win_2_Main,300,0,800,i,true);
		BitBlt(hdc,0,0,800,600,mdc,0,0,SRCCOPY);
	}
	MoveWindow(hWnd_Win_2_Main,300,0,800,600,true);
	/**/
	//BitBlt(hdc,0,0,800,600,mdc,0,0,SRCCOPY);
	BitBlt(hdc, 0, 0, 800, 55, mdc, 0, 0, SRCCOPY);
	BitBlt(hdc, 201, 414, 598, 186, mdc, 201, 414, SRCCOPY);
	BitBlt(hdc, 201, 55, 2, 545, mdc, 201, 55, SRCCOPY);
	UpdateWindow(hWnd_Win_2_Main);	//更新窗口
	/**/
	//MSG msg;
	//while(GetMessage(&msg,NULL,0,0))
	//{
	//	TranslateMessage(&msg);	//发送消息到消息队列
	//	DispatchMessage(&msg);	//发送消息到窗口程序
	//}
	MSG msg;
	/*POINT pt1;*/
	RECT Rect;
	int i;
	//SetCapture(hWnd_Win_2_Main);
	while(GetMessage(&msg,NULL,0,0))
	{
		//TranslateMessage(&msg);	//发送消息到消息队列
		if(msg.message==WM_MOUSEMOVE)
		{
			GetWindowRect(hWnd_Win_2_Main,&Rect);
			tme.cbSize = sizeof (tme);
			tme.dwFlags = TME_LEAVE;
			tme.dwHoverTime = HOVER_DEFAULT;
			tme.hwndTrack = hWnd_Win_2_Main;
			TrackMouseEvent(&tme);
			
		
			if((Rect.bottom-Rect.top)<=5)
			{
				for(i=3;i<600;i=i+6)
				MoveWindow(hWnd_Win_2_Main,Rect.left,0,800,i,true);
				MoveWindow(hWnd_Win_2_Main,Rect.left,0,800,600,true);
				BitBlt(hdc,0,0,800,55,mdc,0,0,SRCCOPY);
				BitBlt(hdc,202,414,598,186,mdc,202,414,SRCCOPY);
				BitBlt(hdc,201,55,2,545,mdc,201,55,SRCCOPY);
				::SetFocus(hWrite_11);
			}
			/*tme1.cbSize = sizeof (tme1);
			tme1.dwFlags = TME_LEAVE;
			tme1.dwHoverTime = HOVER_DEFAULT;
			tme1.hwndTrack = HListBox_2_1;
			TrackMouseEvent(&tme1);
			tme2.cbSize = sizeof (tme2);
			tme2.dwFlags = TME_LEAVE;
			tme2.dwHoverTime = HOVER_DEFAULT;
			tme2.hwndTrack = HListBox_2_2;
			TrackMouseEvent(&tme2);
			tme3.cbSize = sizeof (tme3);
			tme3.dwFlags = TME_LEAVE;
			tme3.dwHoverTime = HOVER_DEFAULT;
			tme3.hwndTrack = hWrite_11;
			TrackMouseEvent(&tme3);*/
		}
		if(msg.wParam==VK_RBUTTON)
		{
			HWND hWnd_666=::GetFocus();
			int iID=::GetDlgCtrlID(hWnd_666);
			RECT Rect,Rect1;
			if(iID!=3)
			{
			GetWindowRect(hWnd_Win_2_Main,&Rect);
			/*Rect1.left=Rect.left+699;
			Rect1.right=Rect.right;
			Rect1.top=Rect.top+55;
			Rect1.bottom=Rect.top+220;*/
			POINT P;
			GetCursorPos(&P);
			TrackPopupMenu(hMenu,TPM_LEFTALIGN,P.x,P.y,0,hWnd_Win_2_Main,&Rect1);
			continue;
			}
			else
			{
				TranslateMessage(&msg);	//发送消息到消息队列
				DispatchMessage(&msg);	//发送消息到窗口程序
			}
		}
		if (WM_KEYFIRST <= msg.message && msg.message <= WM_KEYLAST) 
	{
		if(msg.wParam==VK_ESCAPE)
			SendMessage(hWnd_Win_2_Main,WM_CLOSE,0,0);
		
		else if(msg.wParam==VK_RETURN)
		{
			HWND hWnd_666=::GetFocus();
			int iID=::GetDlgCtrlID(hWnd_666);
			if(iID==3)
			{
				SendMessage(hWrite_11, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_11)+1),(LPARAM)text_send);
			if(0== GetWindowTextLength(hWrite_11))
			{
					//MessageBox(NULL, TEXT("发送消息不能为空"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
				MessageBeep(NULL);
					continue;
			}
			else if(num_send[0]=='\0')
			{
				MessageBox(NULL, TEXT("未选择发送对象\n（左侧双击选择对象）"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					continue;
			}
			else
			{
				ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			pack_1.commend=2;
			pack_1.upacket.info2.ID=GENERALMSG;
			strcpy_s(pack_1.upacket.info2.num_z,num_send);
			strcpy_s(pack_1.upacket.info2.num_z1,num_local);
			strcpy_s(pack_1.upacket.info2.text,text_send);
			send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			buff = new char[530];
			if((local_msg.name!=NULL)&&(local_msg.name[0]!='\0'))
			sprintf_s(buff,530,"%s(本机)：  %s",local_msg.name,text_send);
			else
				sprintf_s(buff,530,"%s(本机)：  %s",num_local,text_send);
			SetWindowText(hWrite_11,NULL);
			SendMessage(HListBox_2_2,LB_ADDSTRING,0,(LPARAM)buff);
			SendMessage(HListBox_2_2,LB_SETTOPINDEX,index_2++,0);
			}
		}
		}
		else 
		{
			TranslateMessage(&msg);	//发送消息到消息队列
			DispatchMessage(&msg);	//发送消息到窗口程序
		}
	}
		else
		{
			TranslateMessage(&msg);	//发送消息到消息队列
			DispatchMessage(&msg);	//发送消息到窗口程序
		}
	}
}
//主菜单子窗口函数
void Create_Win_2_Child()
{
	hWnd_Win_2_Child=CreateWindow(szNumBtnClass,_T("添加好友"),
				WS_OVERLAPPEDWINDOW/*|WS_CHILD*//*|WS_VISIBLE*/,450,100,450,400,/*hWnd_Win_2_Main*/NULL,/*HMENU(IDC_ADD_FRIEND)*/NULL,hInstance_a,NULL);
	/*hWnd_Win_2_Child=CreateWindow(szNumBtnClass,_T("添加好友"),
				WS_OVERLAPPEDWINDOW|WS_CHILD|WS_VISIBLE,50,100,450,400,hWnd_Win_2_Main,HMENU(IDC_ADD_FRIEND),hInstance_a,NULL);*/
	ShowWindow(hWnd_Win_2_Child,/*SW_NORMAL*/SW_SHOW);
	UpdateWindow(hWnd_Win_2_Child);
	CreateWindow(_T("EDIT"),NULL /*_T("201632025")*/, WS_VISIBLE|WS_CHILD | WS_BORDER|ES_NUMBER/*|ES_MULTILINE*/, 
									88,32,157, 23, hWnd_Win_2_Child, HMENU(IDC_TEXT_WRITE_5), happ, NULL);
				
	CreateWindow(_T("Button"), _T("查找好友"), BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE,
									260, 30 ,100, 27, hWnd_Win_2_Child, HMENU(IDC_BTN_SEARCH_FRIEND), happ, NULL);
	CreateWindow(_T("ListBox"),_T("好友列表"),WS_CHILD|WS_VISIBLE|ES_LEFT|WS_BORDER| ES_READONLY|WS_VSCROLL|LBS_NOTIFY,
			88,90,272,250,hWnd_Win_2_Child,HMENU(IDC_LIST_2_CHILD),hInstance_a,NULL);
		UpdateWindow(hWnd_Win_2_Child);
		hWrite_5 = GetDlgItem(hWnd_Win_2_Child, IDC_TEXT_WRITE_5);
		hListBox_2_Child=GetDlgItem(hWnd_Win_2_Child, IDC_LIST_2_CHILD);
		hBtn_3=GetDlgItem(hWnd_Win_2_Child, IDC_BTN_SEARCH_FRIEND);

	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);	//发送消息到消息队列
		DispatchMessage(&msg);	//发送消息到窗口程序
	}
}
//主菜单子窗口函数2
void Create_Win_2_Child_2()
{
	char age[4];
	hWnd_Win_2_Child_2=CreateWindow(_T("win_2_child_2"),_T("个人信息"),
				WS_OVERLAPPEDWINDOW,450,200,300,300,NULL,NULL,hInstance_a,NULL);
			ShowWindow(hWnd_Win_2_Child_2,/*SW_NORMAL*/SW_SHOW);
			UpdateWindow(hWnd_Win_2_Child_2);
			hWrite_7=
			CreateWindow(_T("EDIT"),NULL /*_T("201632025")*/, WS_VISIBLE|WS_CHILD | WS_BORDER/*|ES_MULTILINE*/, 
									88,35,157, 23, hWnd_Win_2_Child_2, HMENU(IDC_TEXT_WRITE_7), happ, NULL);
			hWrite_8=
			CreateWindow(_T("EDIT"),NULL /*_T("201632025")*/, WS_VISIBLE|WS_CHILD | WS_BORDER|ES_NUMBER/*|ES_MULTILINE*/, 
									88,115,157, 23, hWnd_Win_2_Child_2, HMENU(IDC_TEXT_WRITE_8), happ, NULL);
			hWrite_9=
			CreateWindow(_T("EDIT"),NULL /*_T("201632025")*/, WS_VISIBLE|WS_CHILD | WS_BORDER|ES_NUMBER/*|ES_MULTILINE*/, 
									88,155,157, 23, hWnd_Win_2_Child_2, HMENU(IDC_TEXT_WRITE_9), happ, NULL);
			hCbox_1=
			CreateWindow("button","男",WS_CHILD|WS_VISIBLE/*|BS_RADIOBUTTON*/|BS_CHECKBOX
									 ,90,75,50,25,hWnd_Win_2_Child_2, HMENU(IDC_CHECKBOX_1),NULL,NULL); 
			hCbox_2=
			CreateWindow("button","女",WS_CHILD|WS_VISIBLE/*|BS_RADIOBUTTON*/|BS_CHECKBOX
									 ,180,75,50,25,hWnd_Win_2_Child_2, HMENU(IDC_CHECKBOX_2),NULL,NULL); 

			CreateWindow("button","保存",WS_CHILD|WS_VISIBLE/*|BS_RADIOBUTTON*/|BS_PUSHBUTTON
									 ,140,195,105,25,hWnd_Win_2_Child_2, HMENU(IDC_2_2_OK),NULL,NULL);
			if(File_Flag_1==1)
			{
			SendMessage(hWrite_7, EM_REPLACESEL, true, (LPARAM)local_msg.name);
			_itoa_s(local_msg.age,age,10);
			if(local_msg.age>0)
			SendMessage(hWrite_8, EM_REPLACESEL, true, (LPARAM)age);
			SendMessage(hWrite_9, EM_REPLACESEL, true, (LPARAM)local_msg.tel);
			if(local_msg.sex==1)SendMessage(hCbox_1, BM_SETCHECK, BST_CHECKED, 0);//打勾
			if(local_msg.sex==2)SendMessage(hCbox_2, BM_SETCHECK, BST_CHECKED, 0);//打勾
			}
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);	//发送消息到消息队列
		DispatchMessage(&msg);	//发送消息到窗口程序
	}
}
void Create_Win_2_Child_3()
{
	hWnd_Win_2_Child_3=CreateWindow(_T("win_2_child_3"),_T("更改密码"),
				WS_OVERLAPPEDWINDOW/*|WS_CHILD|WS_VISIBLE*/,500,200,280,290,NULL/*hWnd_Win_2_Main*/,/*HMENU(IDC_ADD_FRIEND)*/NULL,hInstance_a,NULL);
	

	ShowWindow(hWnd_Win_2_Child_3,/*SW_NORMAL*/SW_SHOW);
			UpdateWindow(hWnd_Win_2_Child_3);
			CreateWindow(_T("EDIT"),NULL /*_T("201632025")*/, WS_VISIBLE|WS_CHILD | WS_BORDER|ES_NUMBER/*|ES_MULTILINE*/, 

									88,32,157, 23, hWnd_Win_2_Child_3, HMENU(IDC_TEXT_WRITE_2), happ, NULL);
			CreateWindow(_T("EDIT"), NULL/*_T("201632025")*/, WS_VISIBLE|WS_CHILD | WS_BORDER|ES_PASSWORD/*|ES_MULTILINE*/, 

									88,72,157, 23, hWnd_Win_2_Child_3, HMENU(IDC_TEXT_WRITE_3), happ, NULL);
			CreateWindow(_T("EDIT"), NULL/*_T("201632025")*/, WS_VISIBLE|WS_CHILD | WS_BORDER|ES_PASSWORD/*|ES_MULTILINE*/, 

									88,112,157, 23, hWnd_Win_2_Child_3, HMENU(IDC_TEXT_WRITE_4), happ, NULL);
			CreateWindow(_T("Button"), _T("确认更改"), BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE,

									10, 150 ,235, 31, hWnd_Win_2_Child_3, HMENU(IDC_BTN_OK), happ, NULL);
			CreateWindow(_T("Button"), _T("取消更改"), BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE,

									10, 190 ,235, 31, hWnd_Win_2_Child_3, HMENU(IDC_BTN_CANCEL), happ, NULL);
			hWrite_2 = GetDlgItem(hWnd_Win_2_Child_3, IDC_TEXT_WRITE_2);
			hWrite_3=GetDlgItem(hWnd_Win_2_Child_3,IDC_TEXT_WRITE_3);
			hWrite_4=GetDlgItem(hWnd_Win_2_Child_3,IDC_TEXT_WRITE_4);
			hBtn_1=GetDlgItem(hWnd_Win_2_Child_3,IDC_BTN_OK);
			hBtn_2=GetDlgItem(hWnd_Win_2_Child_3,IDC_BTN_CANCEL);
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		if (WM_KEYFIRST <= msg.message && msg.message <= WM_KEYLAST)
		{
		HWND hWnd_666=::GetFocus();
		int iID=::GetDlgCtrlID(hWnd_666);
		if(iID==5504||iID==5505)
		{
			if(msg.wParam>=0x41&&msg.wParam<=0x5a||msg.wParam>=0x30&&msg.
				wParam<=0x39||msg.wParam>=0x60||msg.wParam<=0x69||msg.wParam>=0x01&&msg.wParam<=0x10||msg.wParam==0x14)
			{
				TranslateMessage(&msg);	//发送消息到消息队列
				DispatchMessage(&msg);	//发送消息到窗口程序
			}
			else
				continue;
		}
		else
			{
				TranslateMessage(&msg);	//发送消息到消息队列
				DispatchMessage(&msg);	//发送消息到窗口程序
			}
		}
		else
		{
		TranslateMessage(&msg);	//发送消息到消息队列
		DispatchMessage(&msg);	//发送消息到窗口程序
		}
	}
}

/********************************************************************************************/
////回调函数变量(Win_1_Main)
//	int File_Flag=0,err,x,y;
//	HWND hWrite,hWrite_1;
//	char num_z[10];
//	char num_m[16];
//	packet pack_1,pack_2;
//	//int i;
/**********************************************************************************************/
LRESULT CALLBACK WinProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	 x=LOWORD(lParam);
	 y=HIWORD(lParam);
	 PAINTSTRUCT ps;
	 RECT Rect;
	 int i;
	switch(uMsg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_CHECKBOX_3:
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				if (SendMessage((HWND)lParam, BM_GETCHECK, 0, 0) == TRUE)//是否打勾了
					SendMessage((HWND)lParam, BM_SETCHECK, BST_UNCHECKED, 0);//取消打勾
				else 
					SendMessage((HWND)lParam, BM_SETCHECK, BST_CHECKED, 0);//打勾
				break;
			}
			break;
		}
		break;
	case WM_CREATE:
	{
		int File_Flag = 0;
		int err = 0;
		err = fopen_s(&pFile, ".\\用户信息.txt", "r");
		if (err == 0)
		{
			ClearStruct((unsigned char*)&num, sizeof(fnode));
			if (!feof(pFile))
			{
				fread(&num, sizeof(fnode), 1, pFile);
				File_Flag++;
			}
			fclose(pFile);
		}

		CreateWindow(_T("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER/*|ES_MULTILINE*/,

			/*368,148,157, 30,*/367, 152, 158, 26, hWnd, HMENU(IDC_TEXT_WRITE), happ, NULL);
		CreateWindow(_T("EDIT"), NULL/*_T("201632025")*/, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD/*|ES_MULTILINE*/,

			/*369,201,157, 32,*/368, 205, 158, 26, hWnd, HMENU(IDC_TEXT_WRITE_1), happ, NULL);
		hCbox_frist =
			CreateWindow("button", NULL, WS_CHILD | WS_VISIBLE/*|BS_RADIOBUTTON*/ | BS_CHECKBOX
				, 368, 245, 12, 12, hWnd, HMENU(IDC_CHECKBOX_3), NULL, NULL);



		hWrite = GetDlgItem(hWnd, IDC_TEXT_WRITE);
		hWrite_1 = GetDlgItem(hWnd, IDC_TEXT_WRITE_1);
		::SetFocus(hWrite);
		if (File_Flag == 1)
		{
			
			memset(num_z_unlocked, '\0', 10);
			memset(num_m_unlocked, '\0', 16);
			for (int i = 0; i < 9; i++)
			{
				num_z_unlocked[i] = num.num_z[i] + 10;
			}
			for (int i = 0; i < strlen(num.num_m); i++)
			{
				if (i < 10)
				{

					if (num.num_m[i] >= 'a' && num.num_m[i] <= 'z')
					{
						if ((num_m[i] - num_z_unlocked[i]) > 'a')
							num_m_unlocked[i] = num.num_m[i] - num_z_unlocked[i];
						else
							num_m_unlocked[i] = num.num_m[i] - num_z_unlocked[i] + 26;
					}
					else if (num.num_m[i] >= 'A' && num.num_m[i] <= 'Z')
					{
						if ((num_m[i] - num_z_unlocked[i]) > 'A')
							num_m_unlocked[i] = num.num_m[i] - num_z_unlocked[i];
						else
							num_m_unlocked[i] = num.num_m[i] - num_z_unlocked[i] + 26;
					}
					else/*(num.num_m[i]>=48&&num.num_m[i]<=57)*/
					{
						num_m_unlocked[i] = num.num_m[i] + 18 - (num_z_unlocked[i] - 47);
					}
				}
				else
				{

					num_m_unlocked[i] = num.num_m[i] + 8;

				}
			}
			if (strlen(num.num_z) != 0)
				SendMessage(hWrite, EM_REPLACESEL, true, (LPARAM)num_z_unlocked);
			if (strlen(num.num_m) != 0)
				SendMessage(hWrite_1, EM_REPLACESEL, true, (LPARAM)num_m_unlocked);
			if (num.f == 1)
			{
				SendMessage(hCbox_frist, BM_SETCHECK, BST_CHECKED, 0);
			}
			else if (num.f == 0)
			{

				if (SendMessage(hCbox_frist, BM_GETCHECK, 0, 0) == TRUE)
					SendMessage(hCbox_frist, BM_SETCHECK, BST_UNCHECKED, 0);//取消打勾
			}
		}
	}
		
		break;
	case WM_MOUSEMOVE:
	 if((((x>=371)&&(x<=428))&&((y>=269)&&(y<=300)))||(((x>=570)&&(x<=600))&&((y>=0)&&(y<=30)))||(((x>=472)&&(x<=520))&&((y>=269)&&(y<=300))))
	{
		::SetCursor(::LoadCursor(NULL,IDC_HAND));//手型
	}
	else
	{
		::SetCursor(::LoadCursor(NULL,IDC_ARROW));//箭头
	}
	break;
	
	case WM_LBUTTONDOWN:
		if(((x>=570)&&(x<=600))&&((y>=0)&&(y<=30)))
		{
				Flag_destory_window=1;
				SendMessage(hWnd,WM_CLOSE,0,0);	
		}
		else if(((x>=371)&&(x<=428))&&((y>=269)&&(y<=300)))
		{
			ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			memset(num_z,'\0',10);
			memset(num_m,'\0',16);
			SendMessage(hWrite, WM_GETTEXT,  10,(LPARAM)num_z);
			SendMessage(hWrite_1, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_1)+1),(LPARAM)num_m);
			if(9 != GetWindowTextLength(hWrite))
			{
					MessageBox(NULL, TEXT("请输入账号"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
			}
			if((0 == GetWindowTextLength(hWrite_1))||(GetWindowTextLength(hWrite_1)>15))
			{
				MessageBox(NULL, TEXT("请输入密码"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
				break;
			}
			if((GetWindowTextLength(hWrite)==9)&&(GetWindowTextLength(hWrite_1)>0&&GetWindowTextLength(hWrite_1)<=15))
				{
					ClearStruct((unsigned char*)&pack_1,sizeof(packet));
					pack_1.commend=1;
					pack_1.upacket.info1.ID=LOG_IN;
					strcpy_s(pack_1.upacket.info1.num_z,num_z);
					strcpy_s(pack_1.upacket.info1.num_m,num_m);
					send(sock_c, (char*)&pack_1, sizeof(packet), 0);

				}
		}
			else if((((x>=472)&&(x<=520))&&((y>=269)&&(y<=300)))&&(flag==1))
		{
			ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			pack_1.commend=1;
			pack_1.upacket.info1.ID=REGISTER;
			send(sock_c, (char*)&pack_1, sizeof(packet), 0);
		}
		if((x>0&&x<570&&y>0&&y<20)||(x>0&&x<40&&y>0&&y<400)||(x>0&&x<600&&y>380&&y<400)||(x>560&&x<600&&y>30&&y<400))
		PostMessage(hWnd, WM_SYSCOMMAND,61458, 0);
		break;
	case WM_PAINT:
	{
		BeginPaint(hWnd, &ps);

		hdc = GetDC(hWnd);
		Picpaint(hWnd);
		HFONT hFont;    //字体句柄
		hFont = CreateFont
		(
			12, 0,    //高度20, 宽取0表示由系统选择最佳值
			0, 0,    //文本倾斜，与字体倾斜都为0
			0/*FW_HEAVY*/,    //粗体
			0, 0, 0,        //非斜体，无下划线，无中划线
			GB2312_CHARSET,    //字符集
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,        //一系列的默认值
			DEFAULT_PITCH | FF_DONTCARE,
			(TCHAR*)"隶书"    //字体名称
		);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);

		SelectObject(hdc, hFont);
		TextOut(hdc, 382, 245, "记住密码", 8);
		HWND hWnd_temp = ::GetFocus();
		::SetFocus(hWrite);
		::SetFocus(hWrite_1);
		::SetFocus(hWnd_temp);

		EndPaint(hWnd, &ps);

		
	
	}
		
		break;
	/*case WM_CHAR:
		if(wParam==27)
		{
			Flag_destory_window=1;
			PostQuitMessage(0);
		}
		break;*/
	case WM_CLOSE:
		GetWindowRect(hWnd,&Rect);
		for(i=0;i<=600;i=i+3)
		{
			MoveWindow(hWnd,Rect.left+i,Rect.top,600-i,400,true);
		Picpaint(hWnd_Win_1_Main);
		}
		for(i=0;i<200;i=i+2)
		{
			MoveWindow(hWnd,Rect.right-1,Rect.top+i,1,Rect.bottom-Rect.top-i,true);
			Picpaint(hWnd_Win_1_Main);
		}
			DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}
	//return 0;
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}
/****************************************************************************************/
BOOL PicInit(HWND hWnd,HINSTANCE hInstance)
{
	hdc=GetDC(hWnd);
	mdc=CreateCompatibleDC(hdc);
	//bdc=CreateCompatibleDC(hdc);
	HBITMAP bmp = CreateCompatibleBitmap(hdc,600,400);
	SelectObject(mdc,bmp);
	//加载图片
	p1 = LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP2));
	/*p1=(HBITMAP)LoadImage(NULL,"./res/p4.bmp",IMAGE_BITMAP,600,
		400,LR_LOADFROMFILE);*/
	/*p2=(HBITMAP)LoadImage(NULL,"./res/主页.bmp",IMAGE_BITMAP,600,
		400,LR_LOADFROMFILE);*/
	SelectObject(mdc,p1);
	/*BitBlt(hdc,0,0,600,400,mdc,0,0,SRCCOPY);
	DeleteObject(p1);
	DeleteDC(mdc);*/
	return true;
}

BOOL Picpaint(HWND hWnd)
{
	//SelectObject(mdc,p1);
	//BitBlt(bdc,0,0,600,400,mdc,0,0,SRCCOPY);
	BitBlt(hdc,0,0,600,400,mdc,0,0,SRCCOPY);
	//DeleteObject(p1);
	//DeleteDC(mdc);
	return true;
}
/**********************************************************************************************/
void connect_server()
{
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
	{
		return;
	}
	sockaddr_in addr_c;
	sock_c=socket(AF_INET,SOCK_STREAM,0);
	addr_c.sin_family = AF_INET;
	addr_c.sin_port=htons(5000);
	addr_c.sin_addr.s_addr=inet_addr(IP);
	connect(sock_c,(SOCKADDR*)&addr_c,sizeof(SOCKADDR));
}

/******************************************************************************************************/
//页面注册窗口
int CRWND(HINSTANCE hInstance)
{
/*********************************************************************************************/
//1.
	WNDCLASS wndclass;	//创建一个窗口类
	wndclass.cbClsExtra = 0;	//窗口类无扩展
	wndclass.cbWndExtra = 0;	//窗口实例无扩展
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//窗口白色
	wndclass.hCursor = LoadCursor(NULL,/*IDC_HAND*//*IDC_ARROW*/NULL);	//手型	//箭头
	wndclass.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));	//默认最小化图标
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WinProc;	//定义窗口处理函数
	wndclass.lpszClassName =_T("win_c");	//窗口类名
	wndclass.lpszMenuName = NULL;	//窗口无菜单
	wndclass.style = CS_HREDRAW|CS_PARENTDC;	//设置窗口类型
	//注册窗口类
	if(!RegisterClass(&wndclass))  //判断窗口是否注册成功
		return FALSE;
/*********************************************************************************************/
//2.
	wndclass.cbClsExtra = 0;	//窗口类无扩展
	wndclass.cbWndExtra = 0;	//窗口实例无扩展
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//窗口白色
	wndclass.hCursor = LoadCursor(NULL,IDC_HAND/*IDC_ARROW*//*NULL*/);	//手型	//箭头
	//wndclass.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));	//最小化图标
	wndclass.hIcon =  (HICON)::LoadImage (NULL,"./res/X2.ico",IMAGE_ICON,0,0,
		LR_DEFAULTSIZE| LR_LOADFROMFILE);  //图标
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WinProc_1;	//定义窗口处理函数
	wndclass.lpszClassName =_T("页面");	//窗口类名
	wndclass.lpszMenuName = NULL;/*MAKEINTRESOURCE(IDR_MENU1);	*///窗口菜单
	wndclass.style = CS_HREDRAW|CS_PARENTDC;	//设置窗口类型
	//注册窗口类
	if(!RegisterClass(&wndclass))  //判断子窗口是否注册成功
		return FALSE;
/****************x注册子窗口************************************************************/
//2.1
	
	wndclass.lpszClassName=szNumBtnClass;
	wndclass.lpszMenuName=NULL;
	wndclass.lpfnWndProc=WndNumBtnProc;
	wndclass.cbWndExtra=8;
	if(!RegisterClass(&wndclass))  //判断子窗口是否注册成功
		return FALSE;
/***************************************************************************************/
//2.2
	wndclass.lpszClassName=_T("win_2_child_2");
	wndclass.lpszMenuName=NULL;
	wndclass.lpfnWndProc=Wnd_2_2_Proc;
	wndclass.cbWndExtra=0;
	if(!RegisterClass(&wndclass))  //判断子窗口是否注册成功
		return FALSE;
//2.3
	wndclass.lpszClassName=_T("win_2_child_3");
	wndclass.lpszMenuName=NULL;
	wndclass.lpfnWndProc=Wnd_2_3_Proc;
	if(!RegisterClass(&wndclass))  //判断子窗口是否注册成功
		return FALSE;

	return 0;
}

/*主菜单响应窗口****************************************************************************************/
LRESULT CALLBACK WinProc_1(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	//int i,j;
	//msg_list *p;
	char *pbuff=NULL;
	int i;
	char*buff;
	int index_s;
	char*name;
	char text_send[512];
	
	//char num_now[10],text[512],buffer[20];
	
	 x=LOWORD(lParam);
	 y=HIWORD(lParam);
	ClearStruct((unsigned char*)&pack_1,sizeof(packet));
	PAINTSTRUCT ps;
	POINT pt1;
	RECT Rect,Rect1;
	//MessageBox(NULL,"666","666",MB_OK);
	
//TRACKMOUSEEVENT tme;

	switch(uMsg)
	{

	case WM_MOUSELEAVE:
		GetWindowRect(hWnd,&Rect);
		GetCursorPos(&pt1);
		if(!(pt1.x>(Rect.left+5)&&pt1.x<(Rect.right-5)&&pt1.y>(Rect.top-10)&&pt1.y<(Rect.bottom)))
			if(Rect.top<=5&&(Rect.bottom-Rect.top)==600)
			{
				for(i=600;i>6;i=i-7)
				MoveWindow(hWnd,Rect.left,-4,800,i,true);
				MoveWindow(hWnd,Rect.left,-4,800,5,true);
				
			}
		break;
	case WM_MOUSEMOVE:
	
	break;






	//case WM_MOUSELEAVE:
	//	/*GetWindowRect(hWnd,&Rect);
	//	GetCursorPos(&pt1);
	//	if(flag_window_display==1)
	//	{
	//		if(Rect.top<=5)
	//		{
	//			for(i=600;i>6;i=i-5)
	//			MoveWindow(hWnd,Rect.left,0,800,i,true);
	//			MoveWindow(hWnd,Rect.left,0,800,5,true);
	//		}
	//	}*/
	//	MessageBox(NULL,"666","666",MB_OK);
	//	break;
	//	
	//case WM_MOUSEMOVE:
	//	GetWindowRect(hWnd,&Rect);
	//	GetCursorPos(&pt1);
	//	if((Rect.top)<=5)
	//	{
	//		if(pt1.x>=Rect.left&&pt1.x<=Rect.right&&pt1.y>=Rect.top&&pt1.y<=Rect.bottom)
	//			MoveWindow(hWnd,Rect.left,0,800,600,true);
	//	}


	/*	GetWindowRect(hWnd,&Rect);
		GetCursorPos(&pt1);
		if(flag_window_display==1)
		{

		}*/

		////MessageBox(NULL,"666","666",MB_OK);
		//if(flag_window_display==1||flag_window_display==3)
		//{
		//	if(flag_window_display==1)
		//	if(Rect.top<=5)
		//	{
		//		for(i=600;i>6;i=i-5)
		//		MoveWindow(hWnd,Rect.left,0,800,i,true);
		//		MoveWindow(hWnd,Rect.left,0,800,5,true);
		//		flag_window_display=2;
		//	}
		//	if(flag_window_display==3)
		//		if((pt1.x<Rect.left||pt1.x>Rect.right||pt1.y<Rect.top||pt1.y>Rect.bottom))
		//		if(Rect.top<=5)
		//	{
		//		for(i=600;i>6;i=i-5)
		//		MoveWindow(hWnd,Rect.left,0,800,i,true);
		//		MoveWindow(hWnd,Rect.left,0,800,5,true);
		//		flag_window_display=2;
		//	}
		//		else
		//			flag_window_display=1;
		//	
		//}
		//if(flag_window_display==2)
		//{
		//	
		//	if(pt1.x>=Rect.left&&pt1.x<=Rect.right&&pt1.y>=Rect.top&&pt1.y<=Rect.top+5)
		//	{
		//		MoveWindow(hWnd,Rect.left,0,800,600,true);
		//		flag_window_display=3;
		//	}
		//	
		//	
		//}
		//if((pt1.x<Rect.left||pt1.x>Rect.right||pt1.y<Rect.top||pt1.y>Rect.bottom))
		//		flag_window_display=0;
		break;
	case WM_LBUTTONUP:
		////if((x>0&&x<330&&y>0&&y<50)||(x>500&&x<700&&y>0&&y<50))
		//{
		//	GetWindowRect(hWnd,&Rect);
		//	//if(Rect.top<=20)
		//		MoveWindow(hWnd,Rect.left,0,800,2,true);
		//}
		//MessageBox(NULL,"666","666",MB_OK);
		break;
	case WM_LBUTTONDOWN:
		/*if(x>330&&x<400&&y>0&&y<50)
			BitBlt(hdc,0,0,800,600,mdc,0,0,SRCCOPY);
		if(x>400&&x<450&&y>0&&y<50)
			BitBlt(hdc,0,0,800,600,mdc1,0,0,SRCCOPY);
		if(x>450&&x<500&&y>0&&y<50)
			BitBlt(hdc,0,0,800,600,mdc2,0,0,SRCCOPY);*/
		if(x>726&&x<746&&y>10&&y<40)
			SendMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
			//SendMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		else if(x>690&&x<719&&y>10&&y<40)
		{
			GetWindowRect(hWnd,&Rect);
			Rect1.left=Rect.left+699;
			Rect1.right=Rect.right;
			Rect1.top=Rect.top+55;
			Rect1.bottom=Rect.top+220;
			//TrackPopupMenu(hMenu,TPM_LEFTALIGN,Rect.left+699,Rect.top+55,0,hWnd,&Rect1);
			TrackPopupMenu(hMenu, TPM_LEFTALIGN, Rect.left + 650, Rect.top + 55, 0, hWnd, &Rect1);
		}
		else if(x>770&&x<790&&y>0&&y<50)
		{
			SendMessage(hWnd,WM_CLOSE,0,0);
		}
		else if((x>0&&x<330&&y>0&&y<50)||(x>500&&x<700&&y>0&&y<50))
		{
			GetWindowRect(hWnd,&Rect);
			if((Rect.bottom-Rect.top)==600)
			PostMessage(hWnd, WM_SYSCOMMAND,61458, 0);
		}
		else if(x>725&&x<793&&y>543&&y<571)
		{
			SendMessage(hWrite_11, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_11)+1),(LPARAM)text_send);
			if(0== GetWindowTextLength(hWrite_11))
			{
					//MessageBox(NULL, TEXT("发送消息不能为空"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
			}
			else if(num_send[0]=='\0')
			{
				MessageBox(NULL, TEXT("未选择发送对象\n（左侧双击选择对象）"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
			}
			else
			{
				ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			pack_1.commend=2;
			pack_1.upacket.info2.ID=GENERALMSG;
			strcpy_s(pack_1.upacket.info2.num_z,num_send);
			strcpy_s(pack_1.upacket.info2.num_z1,num_local);
			strcpy_s(pack_1.upacket.info2.text,text_send);
			send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			buff = new char[530];
			if((local_msg.name!=NULL)&&(local_msg.name[0]!='\0'))
			sprintf_s(buff,530,"%s(本机)：  %s",local_msg.name,text_send);
			else
				sprintf_s(buff,530,"%s(本机)：  %s",num_local,text_send);
			SetWindowText(hWrite_11,NULL);
			SendMessage(HListBox_2_2,LB_ADDSTRING,0,(LPARAM)buff);
			SendMessage(HListBox_2_2,LB_SETTOPINDEX,index_2++,0);
			}
		}
		
		break;
	case WM_CREATE:
		//创建弹出菜单
		hMenu= CreatePopupMenu(); 
		AppendMenu(hMenu,MFT_STRING,ID_NUMCTRL,"本机账号");
		AppendMenu(hMenu,MFT_STRING,ID_PMSG,"个人信息");
		AppendMenu(hMenu,MFT_STRING,ID_CHANGENUM_M,"更改密码");
		AppendMenu(hMenu,MFT_STRING,ID_ADD_FRD,"添加好友");
		AppendMenu(hMenu,MFT_STRING,ID_QUIT,"退出");
		HListBox_2_1=
		CreateWindow(_T("ListBox"),_T("NULL"),
				WS_CHILD|WS_VISIBLE|ES_LEFT/*|WS_BORDER*/| ES_READONLY|WS_VSCROLL|LBS_NOTIFY,0,52,201,562,hWnd,HMENU(IDC_LIST),hInstance_a,NULL);
		HListBox_2_2=
		CreateWindow(_T("ListBox"),_T("NULL"),
				WS_CHILD|WS_VISIBLE|ES_LEFT/*|WS_BORDER*/| ES_READONLY|WS_VSCROLL|LBS_NOTIFY,205,52,595,370,hWnd,HMENU(2),hInstance_a,NULL);
		hWrite_11=
		CreateWindow(_T("EDIT"),NULL /*_T("201632025")*/, WS_VISIBLE|WS_CHILD /*| WS_BORDER*/|ES_MULTILINE|ES_WANTRETURN, 

									205,/*400*//*414*/420,598, 100, hWnd, HMENU(3), happ, NULL);
		p_pMsg=head_pmsg;
		SendMessage(HListBox_2_1, LB_SETITEMHEIGHT,0,50); 
		while(p_pMsg!=NULL)
		{
			buff=new char[30];
			if((p_pMsg->Name!=NULL)&&(p_pMsg->Name[0]!='\0'))
			sprintf_s(buff,30,"%s",/*head_pmsg->Num_z,*/p_pMsg->Name);
			else
			{
				sprintf_s(buff,30,"%s",p_pMsg->Num_z);
			}
			add_search_for(index,p_pMsg->Num_z);
			SendMessage(HListBox_2_1,LB_INSERTSTRING,index++,(LPARAM)buff);
			delete[] buff;
			p_pMsg=p_pMsg->next;
		}
		
		while(1)
		{
			pbuff=out_out_msg();
			if(pbuff==NULL)break;
			SendMessage(HListBox_2_2,LB_ADDSTRING,0,(LPARAM)pbuff);
			SendMessage(HListBox_2_2,LB_SETTOPINDEX,index_2++,0);
		}

		HFONT hFont;    //字体句柄
			 hFont = CreateFont
                        (

                            20,0,    //高度20, 宽取0表示由系统选择最佳值

                            0, 0,    //文本倾斜，与字体倾斜都为0

                            0/*FW_HEAVY*/,    //粗体

                            0,0,0,        //非斜体，无下划线，无中划线

                            GB2312_CHARSET,    //字符集

                            OUT_DEFAULT_PRECIS,        

                            CLIP_DEFAULT_PRECIS,        

                            DEFAULT_QUALITY,        //一系列的默认值

                            DEFAULT_PITCH | FF_DONTCARE,    

                           (TCHAR*)"楷体"    //字体名称
                        );
       SendMessage(hWrite_11, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE,0));
	   SendMessage(HListBox_2_2, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE,0));
	   hFont = CreateFont
                        (

                            30,0,    //高度20, 宽取0表示由系统选择最佳值

                            0, 0,    //文本倾斜，与字体倾斜都为0

                            0/*FW_HEAVY*/,    //粗体

                            0,0,0,        //非斜体，无下划线，无中划线

                            GB2312_CHARSET,    //字符集

                            OUT_DEFAULT_PRECIS,        

                            CLIP_DEFAULT_PRECIS,        

                            DEFAULT_QUALITY,        //一系列的默认值

                            DEFAULT_PITCH | FF_DONTCARE,    

                           (TCHAR*)"隶书"    //字体名称
                        );
		SendMessage(HListBox_2_1, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE,0));
		break;
	/*case WM_SIZE:
		BitBlt(hdc,0,0,800,600,mdc,0,0,SRCCOPY);
		break;*/
	case WM_PAINT:
	{
		hdc1 = BeginPaint(hWnd, &ps);
		/*BitBlt(hdc,0,0,800,55,mdc,0,0,SRCCOPY);
		BitBlt(hdc,201,414,598,186,mdc,201,414,SRCCOPY);
		BitBlt(hdc,201,55,2,545,mdc,201,55,SRCCOPY);*/
		BitBlt(hdc, 0, 0, 800, 600, mdc, 0, 0, SRCCOPY);
		/*HWND hWnd_temp = ::GetFocus();
		::SetFocus(HListBox_2_1);
		::SetFocus(HListBox_2_2);
		::SetFocus(hWrite_11);
		::SetFocus(hWnd_temp);*/
		ShowWindow(HListBox_2_1, SW_HIDE);
		ShowWindow(HListBox_2_2, SW_HIDE);
		ShowWindow(hWrite_11, SW_HIDE);
		ShowWindow(HListBox_2_1, SW_SHOW);
		ShowWindow(HListBox_2_2, SW_SHOW);
		ShowWindow(hWrite_11, SW_SHOW);

		EndPaint(hWnd, &ps);
	}
		
		break;
	case WM_CLOSE:
		GetWindowRect(hWnd,&Rect);
		for(i=0;i<=800;i=i+5)
		{
			MoveWindow(hWnd,Rect.left+i,Rect.top,800-i,600,true);
			BitBlt(hdc,0,0,800,600,mdc,0,0,SRCCOPY);
		}
	/*	for(i=0;i<=18;i=i+1)
		{
		BitBlt(hdc,0,0,2,600,mdc1,i,0,SRCCOPY);
		UpdateWindow(hWnd);
		Sleep(100);
		}*/
		for(i=0;i<300;i=i+6)
		{
			
			MoveWindow(hWnd,Rect.right-2,Rect.top+i,2,600-i,true);
			BitBlt(hdc,0,0,2,600,mdc1,0,0,SRCCOPY);
		}
		DestroyMenu(hMenu);
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		ClearStruct((unsigned char*)&pack_1,sizeof(packet));
		pack_1.commend=1;
		pack_1.upacket.info1.ID=CONNECT_BREAK;
		send(sock_c, (char*)&pack_1, sizeof(packet), 0);
		closesocket(sock_c);
		WSACleanup();
		PostQuitMessage(0);
		//Flag_destory_window=1;
		
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_CHAT:
			//SendMessage(HListBox_2_1,LB_ADDSTRING,0,(LPARAM)"系统消息");
			MessageBox(NULL,"  哈哈哈\n你一直在聊天界面啊","error",MB_OK);
			break;
		case IDC_LIST:
			switch(HIWORD(wParam))
			{
			case LBN_DBLCLK:
				/*for(i=0;i<SendMessage(HListBox_2_1,LB_GETCOUNT,0,0);i++)
				{

				}*/
				index_s=SendMessage(HListBox_2_1,LB_GETCURSEL,0,0);
				buff=new char[40];
				name=new char[16];
				if(search_pMsg(Search_for(index_s))->Name!=NULL)
					{
						sprintf_s(name,16,"%s",search_pMsg(Search_for(index_s))->Name);
						strcpy_s(num_send,Search_for(index_s));
				
				sprintf_s(buff,30,"%s  %s 开始通信",Search_for(index_s),name);
				}
				else
				{
					strcpy_s(num_send,Search_for(index_s));
					sprintf_s(buff,30,"%s  开始通信",Search_for(index_s));
				}
				SendMessage(HListBox_2_2,LB_ADDSTRING,0,(LPARAM)buff);
				SendMessage(HListBox_2_2,LB_SETTOPINDEX,index_2++,0);
				break;
			}
			break;
		case ID_ADD_FRD:
				Create_Win_2_Child();
			break;
		case ID_NUMCTRL:
			MessageBox(NULL,num_local,"本机账号",MB_OK);
			break;
		case ID_PMSG:
			Create_Win_2_Child_2();
			break;
		case ID_CHANGENUM_M:
			Create_Win_2_Child_3();
			
			break;
		case ID_QUIT:
			ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			pack_1.commend=1;
			pack_1.upacket.info1.ID=CONNECT_BREAK;
			send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			closesocket(sock_c);
			WSACleanup();
			Flag_destory_window=1;
			PostQuitMessage(0);
			break;
		case 2:
			break;
		case 3:
			/*GetWindowText(hWrite_11,text_send,530);
			if(text[strlen(text_send)]=='\n')
			{
				text[strlen(text_send)]='\0';
			ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			pack_1.commend=2;
			pack_1.upacket.info2.ID=GENERALMSG;
			strcpy_s(pack_1.upacket.info2.num_z,num_send);
			strcpy_s(pack_1.upacket.info2.num_z1,num_local);
			strcpy_s(pack_1.upacket.info2.text,text_send);
			send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			buff = new char[530];
			if((local_msg.name!=NULL)&&(local_msg.name[0]!='\0'))
			sprintf_s(buff,530,"%s(本机)：  %s",local_msg.name,text_send);
			else
				sprintf_s(buff,530,"%s(本机)：  %s",num_local,text_send);
			SetWindowText(hWrite_11,NULL);
			SendMessage(HListBox_2_2,LB_ADDSTRING,0,(LPARAM)buff);
			SendMessage(HListBox_2_2,LB_SETTOPINDEX,index_2++,0);
			}*/
			
			break;
		}
		break;
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);

	}
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}
/********************************************************************************************/
//子窗口响应函数(Win_2_Child)
LRESULT CALLBACK WndNumBtnProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	int index,length;
	int flag_sf=0;
	switch(uMsg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_BTN_SEARCH_FRIEND:
			memset(num_z,'\0',10);
			if(9 != GetWindowTextLength(hWrite_5))
				MessageBox(NULL, TEXT("请输入账号（9个数字）"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
			else
			{
				SendMessage(hWrite_5, WM_GETTEXT,  10,(LPARAM)num_z);
				if(strcmp(num_z,num_local)==0)
				{
					MessageBox(NULL,"不能添加自己为好友","warning",MB_OK);
					break;
				}
				p_pMsg=head_pmsg;
			while(p_pMsg!=NULL)
			{
				
			
				if(strcmp(head_pmsg->Num_z,num_z)==0)
					{
						flag_sf=1;
						break;
					}
				p_pMsg=p_pMsg->next;
			}
			if(flag_sf==1)
			{
					MessageBox(NULL,"该用户已经是您的好友了","warning",MB_OK);
					break;
			}
				ClearStruct((unsigned char*)&pack_1,sizeof(packet));
				pack_1.commend=1;
				pack_1.upacket.info1.ID=SEARCHFRIEND;
				strcpy_s(pack_1.upacket.info1.num_z,num_z);
				send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			}
			break;
		case IDC_LIST_2_CHILD:
				switch(HIWORD(wParam))
			{
				
				case LBN_DBLCLK:
				index=SendMessage(hListBox_2_Child,LB_GETCURSEL,0,0);
				length=SendMessage(hListBox_2_Child,LB_GETTEXTLEN,index,0);
				if(length!=strlen(_T("账号不存在")))
				{
				SendMessage(hBtn_3,WM_CLOSE,0,0);
				SendMessage(hWrite_5,WM_CLOSE,0,0);
				SendMessage(hListBox_2_Child,WM_CLOSE,0,0);
				hWrite_6=
				CreateWindow(_T("EDIT"), _T("验证信息"), WS_VISIBLE|WS_CHILD | WS_BORDER/*|ES_NUMBER*/|ES_MULTILINE/*|ES_TITLE*/, 
									75,82,272,150, hWnd_Win_2_Child, HMENU(IDC_TEXT_WRITE_6), happ, NULL);
				
				CreateWindow(_T("Button"), _T("SEND"), BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE,
									247, 250 ,100, 27, hWnd_Win_2_Child, HMENU(IDC_BTN_SEND_TO_FRIEND), happ, NULL);
				SendMessage(hWrite_6,EM_LIMITTEXT,50,0L);
				}
				break;

			}
			break;
		case IDC_BTN_SEND_TO_FRIEND:
			if((GetWindowTextLength(hWrite_6)>0))
				SendMessage(hWrite_6,WM_GETTEXT,(WPARAM)(GetWindowTextLength(hWrite_6)+1),(LPARAM)pack_check.upacket.info2.text);
			send(sock_c, (char*)&pack_check, sizeof(packet), 0);
			SendMessage(hWnd_Win_2_Child,WM_CLOSE,0,0);
			MessageBox(NULL,"验证信息已发送","通知",MB_OK);
			break;
		}
		break;
		
	case WM_CREATE:
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}
/***********************************************************************************************/
LRESULT CALLBACK Wnd_2_2_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	//FILE *pfile;
	int sex;
	int age;
	char agec [4];
	char tel[12];
	char name[16];
	PAINTSTRUCT ps;
	//RECT nRect;
	switch(uMsg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_CHECKBOX_1:
			switch(HIWORD(wParam))
			{
			case BN_CLICKED:
				if (SendMessage((HWND)lParam, BM_GETCHECK, 0, 0) == TRUE)//是否打勾了

					SendMessage((HWND)lParam, BM_SETCHECK, BST_UNCHECKED, 0);//取消打勾

				else 
				{
					if(SendMessage(hCbox_2, BM_GETCHECK, 0, 0) == TRUE)
						SendMessage(hCbox_2, BM_SETCHECK, BST_UNCHECKED, 0);//取消打勾
						SendMessage((HWND)lParam, BM_SETCHECK, BST_CHECKED, 0);//打勾
				}
				break;
			}
		break;
		case IDC_CHECKBOX_2:
			switch(HIWORD(wParam))
			{
				case BN_CLICKED:
				if (SendMessage((HWND)lParam, BM_GETCHECK, 0, 0) == TRUE)//是否打勾了

					SendMessage((HWND)lParam, BM_SETCHECK, BST_UNCHECKED, 0);//取消打勾

				else 
				{
					if(SendMessage(hCbox_1, BM_GETCHECK, 0, 0) == TRUE)
						SendMessage(hCbox_1, BM_SETCHECK, BST_UNCHECKED, 0);//取消打勾
						SendMessage((HWND)lParam, BM_SETCHECK, BST_CHECKED, 0);//打勾
				}
				break;
			}
		case IDC_TEXT_WRITE_7:
			break;
		case IDC_TEXT_WRITE_8:
			break;
		case IDC_TEXT_WRITE_9:
			break;
		case IDC_2_2_OK:
			if(0== GetWindowTextLength(hWrite_7)||GetWindowTextLength(hWrite_7)>15)
				{
					MessageBox(NULL, TEXT("请输入姓名（7个字以下）"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
				}
			if((SendMessage(hCbox_1, BM_GETCHECK, 0, 0) == FALSE)&&(SendMessage(hCbox_2, BM_GETCHECK, 0, 0) == FALSE))
				{
					MessageBox(NULL, TEXT("请选择性别"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
				}
			if(1!= GetWindowTextLength(hWrite_8)&&GetWindowTextLength(hWrite_8)!=2&&GetWindowTextLength(hWrite_8)!=3)
				{
					MessageBox(NULL, TEXT("请输入年龄（1-999）"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
				}
			if(11!= GetWindowTextLength(hWrite_9))
				{
					MessageBox(NULL, TEXT("请输入电话号码（11位）"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
				}
			SendMessage(hWrite_7, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_7)+1),(LPARAM)name);
			SendMessage(hWrite_8, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_8)+1),(LPARAM)agec);
			SendMessage(hWrite_9, WM_GETTEXT,  12,(LPARAM)tel);
			if(SendMessage(hCbox_1, BM_GETCHECK, 0, 0) == TRUE)sex=1;//男
			if(SendMessage(hCbox_2, BM_GETCHECK, 0, 0) == TRUE)sex=2;//女
			age=atoi(agec);
			ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			pack_1.commend=3;
			pack_1.upacket.info3.ID=LOCALMSG;
			pack_1.upacket.info3.age=age;
			pack_1.upacket.info3.sex=sex;
			strcpy_s(pack_1.upacket.info3.num_z,num_local);
			strcpy_s(pack_1.upacket.info3.name,name);
			strcpy_s(pack_1.upacket.info3.tel,tel);
			send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			local_msg.age=age;
			local_msg.sex=sex;
			strcpy_s(local_msg.num_z,num_z);
			strcpy_s(local_msg.name,name);
			strcpy_s(local_msg.tel,tel);
			/*err=fopen_s(&pfile,".\\res\\个人信息.txt","w");
					if(err==0)
					{
						fwrite(&local_msg,sizeof(personalmsg),1,pFile);
						fclose(pfile);
					}*/
					MessageBox(NULL,"保存成功","提示",MB_OK);
					SendMessage(hWnd_Win_2_Child_2,WM_CLOSE,0,0);
			break;
		}
	break;
		
	case WM_CREATE:
		/*err=fopen_s(&pfile,".\\res\\个人信息.txt","r");
		if(err==0)
			{
				if(!feof(pfile))
				{
					fread(&local_msg,sizeof(personalmsg),1,pFile);
				File_Flag_1=1;
				}
				fclose(pFile);
			}*/
		break;
	case WM_PAINT:
		BeginPaint(hWnd,&ps);
		hdc=GetDC(hWnd_Win_2_Child_2);
			//MakeFont(hdc);
			 HFONT hFont;    //字体句柄
			 hFont = CreateFont
                        (

                            20,0,    //高度20, 宽取0表示由系统选择最佳值

                            0, 0,    //文本倾斜，与字体倾斜都为0

                            0/*FW_HEAVY*/,    //粗体

                            0,0,0,        //非斜体，无下划线，无中划线

                            GB2312_CHARSET,    //字符集

                            OUT_DEFAULT_PRECIS,        

                            CLIP_DEFAULT_PRECIS,        

                            DEFAULT_QUALITY,        //一系列的默认值

                            DEFAULT_PITCH | FF_DONTCARE,    

                           (TCHAR*)"隶书"    //字体名称
                        );
				SetTextColor(hdc, RGB(0,0,0));
				SetBkMode(hdc, TRANSPARENT);

			 SelectObject(hdc, hFont);
			TextOut(hdc,10,35,"姓名",4);
			TextOut(hdc,10,75,"性别",4);
			TextOut(hdc,10,115,"年龄",4);
			TextOut(hdc,10,155,"电话",4);
			EndPaint(hWnd,&ps);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}
/***********************************************************************************************/
LRESULT CALLBACK Wnd_2_3_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	//RECT nRect;
	switch(uMsg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
			case IDC_BTN_OK:
			memset(num_z,'\0',10);
			memset(num_m,'\0',16);
			memset(num_m0,'\0',16);
			if(9 != GetWindowTextLength(hWrite_2))
				{
					MessageBox(NULL, TEXT("请输入账号（9个数字）"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
				}
			if((0 == GetWindowTextLength(hWrite_3))||(GetWindowTextLength(hWrite_1)>15))
				{
					MessageBox(NULL, TEXT("原密码在1-15位"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
				}
			if((0 == GetWindowTextLength(hWrite_4))||(GetWindowTextLength(hWrite_2)>15))
				{
					MessageBox(NULL, TEXT("新密码应在1-15位"), TEXT("Error"), MB_ICONWARNING|MB_SYSTEMMODAL);
					break;
				}
			SendMessage(hWrite_2, WM_GETTEXT,  10,(LPARAM)num_z);
			SendMessage(hWrite_3, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_3)+1),(LPARAM)num_m0);
			SendMessage(hWrite_4, WM_GETTEXT,  (WPARAM)(GetWindowTextLength(hWrite_4)+1),(LPARAM)num_m);
			ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			pack_1.commend=1;
			pack_1.upacket.info1.ID=CHANGENUMM;
			strcpy_s(pack_1.upacket.info1.num_z,num_z);
			strcpy_s(pack_1.upacket.info1.num_m,num_m0);
			strcpy_s(pack_1.upacket.info1.num_mm,num_m);
			send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			break;
			case IDC_BTN_CANCEL:
				SendMessage(hWnd_Win_2_Child_3,WM_CLOSE,0,0);
			break;

		}
		break;
	case WM_CREATE:
		break;
	case WM_PAINT:
	BeginPaint(hWnd,&ps);
		hdc=GetDC(hWnd);
			HFONT hFont;    //字体句柄
			 hFont = CreateFont
                        (

                            20,0,    //高度20, 宽取0表示由系统选择最佳值

                            0, 0,    //文本倾斜，与字体倾斜都为0

                            0/*FW_HEAVY*/,    //粗体

                            0,0,0,        //非斜体，无下划线，无中划线

                            GB2312_CHARSET,    //字符集

                            OUT_DEFAULT_PRECIS,        

                            CLIP_DEFAULT_PRECIS,        

                            DEFAULT_QUALITY,        //一系列的默认值

                            DEFAULT_PITCH | FF_DONTCARE,    

                           (TCHAR*)"隶书"    //字体名称
                        );
				SetTextColor(hdc, RGB(0,0,0));
				SetBkMode(hdc, TRANSPARENT);

			 SelectObject(hdc, hFont);
			TextOut(hdc,10,35,"账号",4);
			TextOut(hdc,10,75,"原密码",6);
			TextOut(hdc,10,115,"新密码",6);
			EndPaint(hWnd,&ps);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

//自定义字体
void MakeFont(HDC hdc)
		{

			 HFONT hFont;    //字体句柄

			 hFont = CreateFont

                        (

                            20,0,    //高度20, 宽取0表示由系统选择最佳值

                            0, 0,    //文本倾斜，与字体倾斜都为0

                            FW_HEAVY,    //粗体

                            0,0,0,        //非斜体，无下划线，无中划线

                            GB2312_CHARSET,    //字符集

                            OUT_DEFAULT_PRECIS,        

                            CLIP_DEFAULT_PRECIS,        

                            DEFAULT_QUALITY,        //一系列的默认值

                            DEFAULT_PITCH | FF_DONTCARE,    

                           (TCHAR*)"华文细黑"    //字体名称

						   //(TCHAR*)"黑体"
                        );
				SetTextColor(hdc, RGB(0,0,0));
				SetBkMode(hdc, TRANSPARENT);

			 SelectObject(hdc, hFont);

		}
/*********************************************************************************************/
////线程计时线程部分
//DWORD WINAPI Time(LPVOID lParameter)
//{
//	struct msg
//	{
//		int i;
//		HWND hWnd;
//	};
//	msg*msg1=(msg*)(lParameter);
//	Sleep((*msg1).i);
//	DestroyWindow((*msg1).hWnd);
//	return 0;
//}
//
////线程计时
//void ThreadTime(int i)
//{
//	struct msg
//	{
//		int i;
//		HWND hWnd;
//	}msg1;
//	CreateThread(NULL,0,Time,&msg1,0,NULL);
//}
//消息处理线程函数 

/**********************************************************************************************/
DWORD WINAPI deal_with_packet_thread(LPVOID lParameter)
{
	char pch[]="  通过了您的请求。";
	char pch1[]="  拒绝了您的请求。";
	int i,count;
	while(1)
	{
		ClearStruct((unsigned char*)&pack_2,sizeof(packet));
		recv(sock_c,(char*)&pack_2,sizeof(packet),0);
		switch(pack_2.commend)
		{
		case 1:
			switch(pack_2.upacket.info1.ID)
			{
				
			case LOG_SUCCEED:
			{
				strcpy_s(num_local, num_z);
				hdc = GetDC(hWnd_Win_1_Main);
				SetTextColor(hdc, RGB(0, 255, 0));
				SetBkMode(hdc, TRANSPARENT);
				TextOut(hdc, 250, 80, _T("登陆成功！"), strlen(_T("登陆成功！")));
				UpdateWindow(hWnd_Win_1_Main);
				
				ClearStruct((unsigned char*)&num, sizeof(fnode));
				memset(num_m_locked, '\0', 16);
				memset(num_z_locked, '\0', 10);
				for (i = 0; i < 9; i++)
				{
					num_z_locked[i] = num_z[i] - 10;
				}
				strcpy_s(num.num_z, num_z_locked);
				if (SendMessage(hCbox_frist, BM_GETCHECK, 0, 0) == TRUE)//是否打勾了
				{
					//strcpy_s(num.num_m,num_m);
					/*加密*/
					length_num_m = strlen(num_m);
					for (i = 0; i < length_num_m; i++)
					{
						if (i < 10)
						{

							if (num_m[i] >= 'a' && num_m[i] <= 'z')
							{
								if ((num_z[i] + num_m[i]) < 'z')
									num_m_locked[i] = num_z[i] + num_m[i];
								else
									num_m_locked[i] = num_z[i] + num_m[i] - 26;
							}
							else if (num_m[i] >= 'A' && num_m[i] <= 'Z')
							{
								if ((num_z[i] + num_m[i]) < 'Z')
									num_m_locked[i] = num_z[i] + num_m[i];
								else
									num_m_locked[i] = num_z[i] + num_m[i] - 26;
							}
							else
							{
								{
									num_m_locked[i] = num_m[i] - 18 + (num_z[i] - 47);
								}
							}
						}
						else
						{

							num_m_locked[i] = num_m[i] - 8;

						}

					}


					strcpy_s(num.num_m, num_m_locked);
					num.f = 1;
					
				}
				else
				{
					num.f = 0;
				}
				int err = fopen_s(&pFile, ".\\用户信息.txt", "w");
				if (err == 0)
				{
					fwrite(&num, sizeof(fnode), 1, pFile);
					fclose(pFile);
					SetFileAttributes(".\\用户信息.txt", FILE_ATTRIBUTE_HIDDEN);
				}
				
				SendMessage(hWnd_Win_1_Main, WM_CLOSE, 0, 0);
			}
					
				break;
			case LOG_FAIL:
					hdc=GetDC(hWnd_Win_1_Main);
					SetTextColor(hdc, RGB(255, 170, 0));
					SetBkMode(hdc, TRANSPARENT);
					TextOut(hdc,250,50,_T("账号或密码错误！"),strlen(_T("账号或密码错误！")));
					UpdateWindow(hWnd_Win_1_Main);
				break;
			case REGISTER_RETURN:
					hdc=GetDC(hWnd_Win_1_Main);
					SetTextColor(hdc, RGB(0, 0, 255));
					SetBkMode(hdc, TRANSPARENT);
					SetWindowText(hWrite,NULL);
					SetWindowText(hWrite_1,NULL);
					SendMessage(hWrite, EM_REPLACESEL, true, (LPARAM)pack_2.upacket.info1.num_z);
					SendMessage(hWrite_1, EM_REPLACESEL, true, (LPARAM)pack_2.upacket.info1.num_m);
					TextOut(hdc,150,210,_T("初始密码为123456"),strlen(_T("初始密码为123456")));
					UpdateWindow(hWnd_Win_1_Main);
					flag=0;				//已执行注册操作，不能继续注册
				break;
			case CHANGESUCCEED:
					SendMessage(hWnd_Win_2_Child_3,WM_CLOSE,0,0);
					MessageBox(NULL, TEXT("密码更改成功，请重新登录"), TEXT("提示"), MB_OK);
					SendMessage(hWnd_Win_2_Main,WM_CLOSE,0,0);
				break;
			case CHANGEFAIL:
					MessageBox(NULL, TEXT("账号或密码错误"), TEXT("提示"), MB_OK);
				break;
			case FRIENDEXIT:
					ClearStruct((unsigned char*)&pack_check,sizeof(packet));
					pack_check.commend=2;
					pack_check.upacket.info2.ID=CHECKMSG;
					strcpy_s(pack_check.upacket.info2.num_z,pack_2.upacket.info1.num_z);
					strcpy_s(pack_check.upacket.info2.num_z1,num_local);
					char buff[30];
					memset(Name,'\0',16);
					memset(num_z,'\0',10);
					strcpy_s(Name,pack_2.upacket.info1.num_mm);
					strcpy_s(num_z,pack_2.upacket.info1.num_z);
					sprintf_s(buff,"账号%s   昵称 %s",num_z,Name);
					count=SendMessage(hListBox_2_Child,LB_GETCOUNT,0,0);
					for(i=0;i<count;i++)
					SendMessage(hListBox_2_Child,LB_DELETESTRING,0,0);
					SendMessage(hListBox_2_Child,LB_ADDSTRING,0,(LPARAM)(buff));
					SendMessage(hListBox_2_Child, LB_SETITEMHEIGHT,0,50); 
				break;
			case FRIENDNULL:
					SendMessage(hListBox_2_Child,LB_ADDSTRING,0,(LPARAM)_T("账号不存在"));
					SendMessage(hListBox_2_Child, LB_SETITEMHEIGHT,0,50); 
				break;
			}
			break;
		case 2:
			switch(pack_2.upacket.info2.ID)
			{
				/*case CM_AGREE:
				memset(text,'\0',512);
				for(i=0;pack_2.upacket.info2.num_z[i]!='\0';i++)
				{
					text[i]=pack_2.upacket.info2.num_z1[i];
				}
				for(j=0;pack_2.upacket.info2.name[j]!='\0';j++,i++)
				{
					text[i]=pack_2.upacket.info2.name[j];
				}
				for(j=0;pch[j]!='\0';j++,i++)
				{
					text[i]=pch[j];
				}
				text[i]='\0';
				add_pMsg(pack_2.upacket.info2.num_z1,pack_2.upacket.info2.name);
				buff=new char[30];
				sprintf_s(buff,30,"%s  %s",msg.num_z,msg.name);
				add_search_for(index,msg.num_z);
				SendMessage(HListBox_2_1,LB_INSERTSTRING,index++,(LPARAM)buff);
				break;*/
			//case CM_REFUSE:
			//	memset(text,'\0',512);
			//	for(i=0;pack_2.upacket.info1.num_z[i]!='\0';i++)
			//	{
			//		text[i]=pack_2.upacket.info1.num_z[i];
			//	}
			//	for(j=0;pack_2.upacket.info1.num_mm[j]!='\0';j++,i++)
			//	{
			//		text[i]=pack_2.upacket.info1.num_mm[j];
			//	}
			//	for(j=0;pch[j]!='\0';j++,i++)
			//	{
			//		text[i]=pch1[j];
			//	}
			//	text[i]='\0';
			//	add_msg(num_sys,NULL,2,text);
			//	break;

			case CM_AGREE:
			{
				MessageBox(NULL, "对方已同意", pack_2.upacket.info2.num_z, MB_OK | MB_SYSTEMMODAL);
				if (search_pMsg(pack_2.upacket.info2.num_z) == NULL)
				{
					add_pMsg(pack_2.upacket.info2.num_z, pack_2.upacket.info2.name);
					char* buff = new char[30];
					if (/*(pack_2.upacket.info2.name != NULL) && */(strlen(pack_2.upacket.info2.name) != 0))
						sprintf_s(buff, 30, "%s",/*head_pmsg->Num_z,*/pack_2.upacket.info2.name);
					else
					{
						sprintf_s(buff, 30, "%s", pack_2.upacket.info2.num_z);
					}
					add_search_for(index, pack_2.upacket.info2.num_z);
					SendMessage(HListBox_2_1, LB_INSERTSTRING, index++, (LPARAM)buff);
					delete[] buff;
				}
			}
				
				break;
			case CM_REFUSE:
				MessageBox(NULL,"对方拒绝了您的好友请求",pack_2.upacket.info2.num_z1,MB_OK|MB_SYSTEMMODAL);
				break;
			case GENERALMSG:
			{
				char* buff = new char[530];
				if (pack_2.upacket.info2.name != NULL && pack_2.upacket.info2.name[0] != '\0')
					sprintf_s(buff, 530, "%s (%s)  :%s", pack_2.upacket.info2.num_z1, pack_2.upacket.info2.name, pack_2.upacket.info2.text);
				else
					sprintf_s(buff, 530, "%s (未设置)  :%s", pack_2.upacket.info2.num_z1, pack_2.upacket.info2.text);
				add_out_msg(buff);
				SendMessage(HListBox_2_2, LB_ADDSTRING, 0, (LPARAM)buff);
				SendMessage(HListBox_2_2, LB_SETTOPINDEX, index_2++, 0);
				delete[] buff;
			}
				
				break;
			case CHECKMSG:
			{
				if (search_check_num(pack_2.upacket.info2.num_z1) == NULL)
				{
					add_check_num(pack_2.upacket.info2.num_z1);
					Cnode msg = { 0 };
					strcpy_s(msg.num_z, pack_2.upacket.info2.num_z);
					strcpy_s(msg.num_z1, pack_2.upacket.info2.num_z1);
					strcpy_s(msg.text, pack_2.upacket.info2.text);
					strcpy_s(msg.name, pack_2.upacket.info2.name);
					msg.sock = sock_c;
					add_friend_or_not(msg);
				}
			}

			//	add_msg(pack_2.upacket.info2.num_z1,&pack_2.upacket.info2.t,2,pack_2.upacket.info2.text);
			//	MessageBox(NULL,pack_2.upacket.info2.text,pack_2.upacket.info2.num_z1,MB_OK);
			//	if(Search_for(num_sys)==NULL)
			//	{
			//		add_search_for(index++,num_sys,1);
			//		memset(buffer,'\0',20);
			//		sprintf_s(buffer,"系统消息（%d）条",Search_for(num_sys)->line);
			//		SendMessage(HListBox_2_1,LB_INSERTSTRING,index,(LPARAM)buffer);
			//	}
			//	else
			//	{
			//		Search_for(num_sys)->line++;
			//		memset(buffer,'\0',20);
			//		sprintf_s(buffer,"系统消息（%d）条",Search_for(num_sys)->line);
			//		SendMessage(HListBox_2_1,LB_DELETESTRING,index,0);
			//		SendMessage(HListBox_2_1,LB_INSERTSTRING,index,(LPARAM)buffer);
			//	}
			//	/************************/
			//ClearStruct((unsigned char*)&pack_1,sizeof(packet));
			//pack_1.commend=2;
			//pack_1.upacket.info2.ID=CM_AGREE;
			//strcpy_s(pack_1.upacket.info2.num_z,pack_2.upacket.info2.num_z);
			//strcpy_s(pack_1.upacket.info2.num_z1,pack_2.upacket.info2.num_z1);
			//send(sock_c, (char*)&pack_1, sizeof(packet), 0);
			/****************************************/
				break;
			case SYSMSG:
				//add_msg(num_sys,&pack_2.upacket.info2.t,2,pack_2.upacket.info2.text);
				break;
			}
			break;
		case 3:
			switch(pack_2.upacket.info3.ID)
			{
				
			case LOCALMSG:
				ClearStruct((unsigned char*)&local_msg,sizeof(personalmsg));
					local_msg.age=pack_2.upacket.info3.age;
					local_msg.sex=pack_2.upacket.info3.sex;
					strcpy_s(local_msg.name,pack_2.upacket.info3.name);
					strcpy_s(local_msg.num_z,pack_2.upacket.info3.num_z);
					strcpy_s(local_msg.tel,pack_2.upacket.info3.tel);
					File_Flag_1=1;
				break;
			case FRDMSG:
				add_pMsg(pack_2.upacket.info3.num_z,pack_2.upacket.info3.name
					,pack_2.upacket.info3.sex,pack_2.upacket.info3.age,pack_2.upacket.info3.tel);
				break;
			}
			break;
		}
	}
}
//消息处理函数 
int deal_with_packet()
{
	CreateThread(NULL,0,deal_with_packet_thread,NULL,0,NULL);
	return 0;
}

DWORD WINAPI add_friend_thread(LPVOID lpParameter)
{
	packet pack;
	
	Cnode msg=*(Cnode*)lpParameter;
	int yn=MessageBox(NULL,msg.text,msg.num_z1,MB_YESNO|MB_SYSTEMMODAL);
	switch(yn)
	{
	case IDYES:
	{
		ClearStruct((unsigned char*)&pack, sizeof(packet));
		pack.commend = 2;
		pack.upacket.info2.ID = CM_AGREE;
		strcpy_s(pack.upacket.info2.num_z, msg.num_z);
		strcpy_s(pack.upacket.info2.num_z1, msg.num_z1);
		add_pMsg(msg.num_z1, msg.name);
		char* buff = new char[30];
		//if ((msg.name != NULL) && (msg.name[0] != '\0'))
		if (strlen(msg.name) != 0)
			sprintf_s(buff, 30, "%s",/*head_pmsg->Num_z,*/msg.name);
		else
			sprintf_s(buff, 30, "%s", msg.num_z1);
		add_search_for(index, msg.num_z1);
		delete_check_num(msg.num_z1);
		SendMessage(HListBox_2_1, LB_INSERTSTRING, index++, (LPARAM)buff);	
		send(msg.sock, (char*)&pack, sizeof(packet), 0);
		delete[] buff;
	}
     
        break;
    case IDNO:
        ClearStruct((unsigned char*)&pack,sizeof(packet));
			pack.commend=2;
			pack.upacket.info2.ID=CM_REFUSE;
			strcpy_s(pack.upacket.info2.num_z,msg.num_z);
			strcpy_s(pack.upacket.info2.num_z1,msg.num_z1);
			send(msg.sock, (char*)&pack, sizeof(packet), 0);
			delete_check_num(msg.num_z1);
        break;

	}
	return 0;
}
int add_friend_or_not(Cnode msg)
{
	CreateThread(NULL,0,add_friend_thread,&msg,0,NULL);
	return 0;
}

/***************************************************************************************************/
/****************************************************************************************************/

/**

**作用：将bitmap中指定部分转化成region

**参数：hBmp是位图资源句柄

**      cTransparentColor是位图中要隐藏的部分的颜色（默认为黑色）

**      cTolerance是其中显示的部分，非必要

**返回值：位图中指定部分的region

**/

HRGN BitmapToRegion (HBITMAP hBmp, COLORREF cTransparentColor, COLORREF cTolerance)

{

    HRGN hRgn = NULL;

 

    if (hBmp)

    {

        // Create a memory DC inside which we will scan the bitmap content

        HDC hMemDC = CreateCompatibleDC(NULL);

        if (hMemDC)

        {

            // Get bitmap size

            BITMAP bm;

            GetObject(hBmp, sizeof(bm), &bm);

 

            // Create a 32 bits depth bitmap and select it into the memory DC

            BITMAPINFOHEADER RGB32BITSBITMAPINFO = {

                    sizeof(BITMAPINFOHEADER),   // biSize

                    bm.bmWidth,                 // biWidth;

                    bm.bmHeight,                // biHeight;

                    1,                          // biPlanes;

                    32,                         // biBitCount

                    BI_RGB,                     // biCompression;

                    0,                          // biSizeImage;

                    0,                          // biXPelsPerMeter;

                    0,                          // biYPelsPerMeter;

                    0,                          // biClrUsed;

                    0                           // biClrImportant;

            };

            VOID * pbits32;

            HBITMAP hbm32 = CreateDIBSection(hMemDC, (BITMAPINFO *)&RGB32BITSBITMAPINFO, DIB_RGB_COLORS, &pbits32, NULL, 0);

            if (hbm32)

            {

                HBITMAP holdBmp = (HBITMAP)SelectObject(hMemDC, hbm32);

 

                // Create a DC just to copy the bitmap into the memory DC

                HDC hDC = CreateCompatibleDC(hMemDC);

                if (hDC)

                {

                    // Get how many bytes per row we have for the bitmap bits (rounded up to 32 bits)

                    BITMAP bm32;

                    GetObject(hbm32, sizeof(bm32), &bm32);

                    while (bm32.bmWidthBytes % 4)

                        bm32.bmWidthBytes++;

 

                    // Copy the bitmap into the memory DC

                    HBITMAP holdBmp = (HBITMAP)SelectObject(hDC, hBmp);

                    BitBlt(hMemDC, 0, 0, bm.bmWidth, bm.bmHeight, hDC, 0, 0, SRCCOPY);

 

                    // For better performances, we will use the ExtCreateRegion() function to create the

                    // region. This function take a RGNDATA structure on entry. We will add rectangles by

                    // amount of ALLOC_UNIT number in this structure.

                    #define ALLOC_UNIT  100

                    DWORD maxRects = ALLOC_UNIT;

                    HANDLE hData = GlobalAlloc(GMEM_MOVEABLE, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects));

                    RGNDATA *pData = (RGNDATA *)GlobalLock(hData);

                    pData->rdh.dwSize = sizeof(RGNDATAHEADER);

                    pData->rdh.iType = RDH_RECTANGLES;

                    pData->rdh.nCount = pData->rdh.nRgnSize = 0;

                    SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);

 

                    // Keep on hand highest and lowest values for the "transparent" pixels

                    BYTE lr = GetRValue(cTransparentColor);

                    BYTE lg = GetGValue(cTransparentColor);

                    BYTE lb = GetBValue(cTransparentColor);

                    BYTE hr = min(0xff, lr + GetRValue(cTolerance));

                    BYTE hg = min(0xff, lg + GetGValue(cTolerance));

                    BYTE hb = min(0xff, lb + GetBValue(cTolerance));

 

                    // Scan each bitmap row from bottom to top (the bitmap is inverted vertically)

                    BYTE *p32 = (BYTE *)bm32.bmBits + (bm32.bmHeight - 1) * bm32.bmWidthBytes;

                    for (int y = 0; y < bm.bmHeight; y++)

                    {

                        // Scan each bitmap pixel from left to right

                        for (int x = 0; x < bm.bmWidth; x++)

                        {

                            // Search for a continuous range of "non transparent pixels"

                            int x0 = x;

                            LONG *p = (LONG *)p32 + x;

                            while (x < bm.bmWidth)

                            {

                                BYTE b = GetRValue(*p);

                                if (b >= lr && b <= hr)

                                {

                                    b = GetGValue(*p);

                                    if (b >= lg && b <= hg)

                                    {

                                        b = GetBValue(*p);

                                        if (b >= lb && b <= hb)

                                            // This pixel is "transparent"

                                            break;

                                    }

                                }

                                p++;

                                x++;

                            }

 

                            if (x > x0)

                            {

                                // Add the pixels (x0, y) to (x, y+1) as a new rectangle in the region

                                if (pData->rdh.nCount >= maxRects)

                                {

                                    GlobalUnlock(hData);

                                    maxRects += ALLOC_UNIT;

                                    hData = GlobalReAlloc(hData, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), GMEM_MOVEABLE);

                                    pData = (RGNDATA *)GlobalLock(hData);

                                }

                                RECT *pr = (RECT *)&pData->Buffer;

                                SetRect(&pr[pData->rdh.nCount], x0, y, x, y+1);

                                if (x0 < pData->rdh.rcBound.left)

                                    pData->rdh.rcBound.left = x0;

                                if (y < pData->rdh.rcBound.top)

                                    pData->rdh.rcBound.top = y;

                                if (x > pData->rdh.rcBound.right)

                                    pData->rdh.rcBound.right = x;

                                if (y+1 > pData->rdh.rcBound.bottom)

                                    pData->rdh.rcBound.bottom = y+1;

                                pData->rdh.nCount++;

 

                                // On Windows98, ExtCreateRegion() may fail if the number of rectangles is too

                                // large (ie: > 4000). Therefore, we have to create the region by multiple steps.

                                if (pData->rdh.nCount == 2000)

                                {

                                    HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), pData);

                                    if (hRgn)

                                    {

                                        CombineRgn(hRgn, hRgn, h, RGN_OR);

                                        DeleteObject(h);

                                    }

                                    else

                                        hRgn = h;

                                    pData->rdh.nCount = 0;

                                    SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);

                                }

                            }

                        }

 

                        // Go to next row (remember, the bitmap is inverted vertically)

                        p32 -= bm32.bmWidthBytes;

                    }

 

                    // Create or extend the region with the remaining rectangles

                    HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), pData);

                    if (hRgn)

                    {

                        CombineRgn(hRgn, hRgn, h, RGN_OR);

                        DeleteObject(h);

                    }

                    else

                        hRgn = h;

 

                    // Clean up

                    SelectObject(hDC, holdBmp);

                    DeleteDC(hDC);

                }

 

                DeleteObject(SelectObject(hMemDC, holdBmp));

            }

 

            DeleteDC(hMemDC);

        }

    }

 

    return hRgn;

}
