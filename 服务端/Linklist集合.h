#ifndef LINKLISTJH_H
#define LINKLISTJH_H
#include"LinkList.h"

void ClrearStruct(unsigned char *pta,int size);


struct net_net
{
	int  ID;				//ID
	char num_z[10];			//要发送的目标
	char text[512];			//发送的信息
	char num_z1[10];		//发送者账号
};

struct Node_Message	
{
	int	 ID;
	char num_z1[10];
	char text[512];
	Node_Message*next;
};
struct Node_Num		//双重链表
{
	//Node_Message*head;
	char num_z[10];
	char name[16];
	//char num_z1[10];
	Node_Message *NodeMessage;	//文本链表
	Node_Num * next;			
};



Node_Num*Search(char num_z[10]);								//要发送的账号
int add_message(char num_z1[10], char num_z[10], char text[512], int ID, char name[16] = { 0 });	//发送者,要发送,消息,ID
bool Delete(char number_z[10]);									//要发送的账号
int Length(Node_Num*Node);										//Node_Num *Node


struct num_friend
{
	char num_frd[10];
	num_friend *next;
};
struct num_msg
{
	HBITMAP hbmap1;
	char name[16];
	char num_z[10];
	int age;
	int sex;
	char tel[12];
	num_msg* next;
	num_friend *frd_head;
};
num_msg* search_msg(char num_z[10]);
int add_msg_num_z(char num_z[10]);
int add_msg_num_all(char num_z[10],char name[16],char tel[12],int age,int sex);
int add_msg_frd_z(char num_z[10],char num_frd[10]);
bool delete_msg(char num_z[10]);
void init_msg(num_msg*p);
//存入文件
int Unum_msgToFile();
//导入信息
int FileToUnum_msg();
//创建文件夹及空文件usermsg.txt,userMessage.txt

void InitDirAndFiles();



#endif