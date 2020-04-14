#ifndef LINKLISTJH_H
#define LINKLISTJH_H
/*****************************************************************************************/
#include<time.h>

//struct net_net
//{
//	char num_z[10];			//要发送的目标
//	char text[512];			//发送的信息
//	char num_z1[10];		//发送者账号
//};
//
//struct Node_Message	
//{
//	char text[512];
//	Node_Message*next;
//};
//struct Node_Num		//双重链表
//{
//	//Node_Message*head;
//	char num_z[10];
//	char num_z1[10];
//	Node_Message *NodeMessage;	//文本链表
//	Node_Num * next;			
//};
//
//Node_Num*Search(char num_z[10]);
//int add_message(char num_z[10],char num_z1[10],char text[512]);
//bool Delete(char number_z[10]);
//int Length(Node_Num*Node);

//清空结构体
void ClearStruct(unsigned char *pta,int size);

/************************************************************************************************/


//好友列表
struct pMsg
{
	//HBITMAP hbmp1;			//头像
	int  sex;
	int  age;
	char tel[12];
	int	 Ynat;				//是否在线
	char Name[16];			//昵称
	char Remark[16];		//备注
	char Num_z[10];			//账号
	pMsg*next;
};

//添加好友
int add_pMsg(char num_z[10], char Name[16], int sex, int age, char tel[12], char Remark[16]);
int add_pMsg(char num_z[10], char Name[16]);
int add_pMsg(char num_z[10], char Name[16], int sex, int age, char tel[12]);
//int add_pMsg(char num_z[10], char Name[16] = { 0 }, int sex = 0, int age = 0,
//	char tel[12] = { 0 }, char Remark[16] = { 0 });
//int add_pMsg(char num_z[10], char Name[16], int sex, int age,char tel[12], char Remark[16]);
//int add_pMsg(char num_z[10],char Name[16]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",int sex=0,int age=0,
//			 char tel[12]="\0\0\0\0\0\0\0\0\0\0\0\0",char Remark[16]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
//删除好友（成功返回true，失败返回false）
bool delete_pMsg(char num_z[10]);
//查找好友（返回pMsg指针）
pMsg *search_pMsg(char num_z[10]);
//更改备注(成功返回1，失败返回0)
int change_pMsg_Remark(char num_z[10],char name[16]);

/**********************************************************************************************/
////消息列表
//struct msg_list
//{
//	tm* t;					//时间
//	int	 to_or_from;		//1.本机发送，2.发送到本机
//	char text[512];			//文本信息
//	msg_list*next;
//};
//
////消息队列
//struct trans_msg
//{
//	char num_z[10];			//账号
//	msg_list* msg_head;		//消息列表头指针
//	trans_msg*next;
//};
//
////添加消息
//int add_msg(char num_z[10],tm*time,int to_or_from,char text[512]);
////清空消息
//bool delete_msg(char num_z[10]);
////返回消息队列头指针
//msg_list *search_msg(char num_z[10]);

/**************************************************************************/
//个人信息
struct personalmsg
{
			int ID;
			char num_z[10];
			char name[16];
			char tel[12];
			int  sex;
			int  age;
};
/******************************************************************************/
struct search_for
{
	int line;//未读消息
	int index;
	char num_z[10];
	search_for*next;
};
void add_search_for(int index,char num_z_search[10],int line=0);
char*Search_for(int index);
search_for*Search_for(char num_z_search[10]);
bool Delete_search(int index);
bool Delete_search(char num_z_search[10]);


////验证消息
//struct check_msg
//{
//	char num_z[10];
//	char text[512];
//	check_msg *next;
//};
//int add_check_msg(char num_z[10],char text[512]);
//void delete_check_msg(char num_z[10]);


//验证号码
struct check_num
{
	char num_z[10];
	check_num*next;
};
int add_check_num(char num_z[10]);
int delete_check_num(char num_z[10]);
check_num*search_check_num(char num_z[10]);


//离线信息
struct out_msg
{
	char buff[530];
	out_msg *next;
};
int Empty();
int add_out_msg(char buff[530]);
char* out_out_msg();
#endif