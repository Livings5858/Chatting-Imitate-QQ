#pragma once
#include"LinkList.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include"windows.h"
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;


//数据包
struct msg_zm
{
	char msg_z[10];
	char msg_m[16];
};
//析构函数
LinkList::~LinkList()//和清空一样
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
//清空函数，和析构一样
bool LinkList::clearSqList()
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
	return true;
}
//获取链表长度
int LinkList::Length()
{
    NODE *p = head;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
//反转链表
NODE* LinkList::Reverse()
{
    if (head == NULL || head->next == NULL) return head;
    NODE *p = head,*q=head->next,*r;
    head->next = NULL;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}
//删除账号
bool LinkList::Delete(char number_z[])
{
	NODE*p=head,*Del;
	int flag;
	if(p==NULL)	return false;
	if(strcmp(p->number_z,number_z)==0)
	{
		head=p->next;
		delete p;
		return true;
	}
		while(p->next!=NULL)
	{
		 flag=1;
		for(int i=0;i<10;i++)
		{
			if(number_z[i]!=p->next->number_z[i])
				{
					flag=0;
					break;
				}
		}
		if(flag==1)
		{
			Del=p->next;
			p->next=Del->next;
			delete Del;
			return true;
		}
		p=p->next;
	}
	return false;
}
//插入到队尾
bool LinkList::add(char number_z[],char number_m[])
{
   /* NODE *p = head,*NewNode;
	int i=0;
	if(head==NULL)
	{   NewNode = new NODE;
		NewNode->next=NULL;
		for(i=0;number_z[i]!='\0';i++)
	{
		NewNode->number_z[i]=number_z[i];
	}
		NewNode->number_z[i]='\0';
		for(i=0;number_m[i]!='\0';i++)
	{
		
		NewNode->number_m[i]=number_m[i];
	}
		NewNode->number_m[i]='\0';
	head=NewNode;
	}
	else
	{
    while(p->next!=NULL)
		p=p->next;
	NewNode = new NODE;
	NewNode->next=NULL;
	for(i=0;number_z[i]!='\0';i++)
	{
		NewNode->number_z[i]=number_z[i];
	}
		NewNode->number_z[i]='\0';
	for(i=0;number_m[i]!='\0';i++)
	{
		NewNode->number_m[i]=number_m[i];
	}
		NewNode->number_m[i]='\0';

	p->next=NewNode;
	}
    return true;*/


	 NODE *p = head,*NewNode;
	int i=0;
	if(head==NULL)
	{   NewNode = new NODE;
		NewNode->next=NULL;
		for(i=0;i<10;i++)
	{
		NewNode->number_z[i]=number_z[i];
	}
		
		for(i=0;i<16;i++)
	{
		
		NewNode->number_m[i]=number_m[i];
	}
		
	head=NewNode;
	}
	else
	{
    while(p->next!=NULL)
		p=p->next;
	NewNode = new NODE;
	NewNode->next=NULL;
	for(i=0;i<10;i++)
	{
		NewNode->number_z[i]=number_z[i];
	}
		
		for(i=0;i<16;i++)
	{
		
		NewNode->number_m[i]=number_m[i];
	}
	p->next=NewNode;
	}
    return true;
}
//更改帐号或改密码
int LinkList::check_ex(char number_z[],char number_m0[],char number_m1[])
{
	NODE*p = head;
	int flag_1;
	int flag;
	while(1)
	{
		flag_1=1;
		flag=1;
		if(p==NULL)	break;
		for(int i=0;i<10;i++)
		{
			if(number_z[i]!=p->number_z[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			if(strlen(number_m0)!=strlen(p->number_m))
				return 1;
			for(int i=0;number_m0[i]!='\0';i++)
			{
				if(number_m0[i]!=p->number_m[i])
				{
					flag_1=0;
					break;
				}
			}
			if(flag_1==0)	return 1;
			if(flag_1==1)
			{
				strcpy_s(p->number_m,number_m1);
				return 2;
			}
		}
		p=p->next;
	}
	return 0;
	//while(p!=NULL)
	//{
	//	for(int i=0;i<10;i++)
	//	{
	//		if(p->number_z[i]!=number_z[i])
	//		{
	//			flag=false;
	//			break;
	//		}
	//	}
	//	if(flag==true)
	//		break;
	//	else
	//		p=p->next;
	//}
	//if(p==NULL)
	//{
	//	return -1;//账号不存在
	//}
	//if(p!=NULL)
	//{
	//	for(int i=0;i<16;i++)
	//	{
	//		if(p->number_m[i]!=number_m0[i])
	//			return -2;//账号存在密码错误
	//	}
	//	if(number_m1[0]=='\0'&&number_m1[1]=='\0')return 1;	//账号密码正确且不改密码
	//	for(int i=0;i<16;i++)
	//	{
	//		
	//		p->number_m[i]=number_m1[i];
	//	}
	//	return 0;	//密码更改成功
	//}
}
//核对帐号密码
int LinkList::check(char number_z[],char number_m[])
{
	NODE*p = head;
	int flag_1;
	int flag;
	while(1)
	{
		flag_1=1;
		flag=1;
		if(p==NULL)	break;
		for(int i=0;i<10;i++)
		{
			if(number_z[i]!=p->number_z[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			if(strlen(number_m)!=strlen(p->number_m))
				return 1;

			for(int i=0;number_m[i]!='\0';i++)
			{
				if(number_m[i]!=p->number_m[i])
				{
					flag_1=0;
					break;
				}
			}
			if(flag_1==0)	return 1;//账号存在密码错误
			if(flag_1==1)	return 2;//账号密码全对
		}
		p=p->next;
	}
	return 0;						//账号不存在
}
//存出文件
int LinkList::UmsgToFile()
{
	FILE* pFile;
	int err=fopen_s(&pFile, ".\\res\\userMsg\\userMessage.txt","w");
	NODE *p=head;
	while(p!=NULL)
	{
		
		int i=0;
		msg_zm msg1;
		strcpy_s(msg1.msg_z,p->number_z);
		strcpy_s(msg1.msg_m,p->number_m);

		fwrite(&msg1,sizeof(msg_zm),1,pFile);
		p=p->next;

	}
	fclose(pFile);
	return 0;
}
//导入信息
int LinkList::FileToUmsg()
{
	FILE* pFile;
	int err=fopen_s(&pFile, ".\\res\\userMsg\\userMessage.txt","r");
	int i=1;
	while(1)
	{
		msg_zm msg2;
		fread(&msg2,sizeof(msg_zm),1,pFile);
		if(feof(pFile))break;
		add(msg2.msg_z,msg2.msg_m);
		//add_msg_num_z(msg2.msg_z);//添加到个人信息数组
		
	}
	fclose(pFile);
	return 0;
}
//输出信息		（待修改）
void LinkList::out(HWND hWnd,UINT Msg,WPARAM wParam)
{
	NODE*p=head;
	int j=0,i=1;
	char buff[30];
	j=Length();
	sprintf_s(buff,"共有成员：%d  个",j);
	SendMessage(hWnd,Msg,wParam,(WPARAM)buff);
	while(p!=NULL)
	{
		memset(buff,'\0',30);
		sprintf_s(buff,"%d:%s  %s",i++,p->number_z,p->number_m);
		SendMessage(hWnd,Msg,wParam,(WPARAM)buff);
		p=p->next;
	}
}
//不重复账号生成
int LinkList::number_create(char number_z[10])
{
	while(1)
	{
	memset(number_z,'\0',10);
    srand((unsigned)time(NULL));
	number_z[0]=random(1,9)+'0';
    for(int i=1;i<9;i++)
    number_z[i]=random(0,9)+'0';
	if(!check(number_z))
		break;
	}
	return 0;
}
//返回密码
char* LinkList::return_nuber_m(char number_z[])
{
	NODE*p = head;
	int flag_1;
	int flag;
	while(1)
	{
		flag_1=1;
		flag=1;
		if(p==NULL)	break;
		for(int i=0;i<10;i++)
		{
			if(number_z[i]!=p->number_z[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			return p->number_m;			//账号存在返回密码
		}
		p=p->next;
	}
	return NULL;						//账号不存在
}
//查找账号返回指针
NODE*LinkList::Search(char number_z[])
{
	NODE*p=head;
	int flag=0;
	while(1)
	{
		if(p==NULL)	break;
		flag=1;
		//if(p==NULL)	break;
		for(int i=0;i<10;i++)
		{
			if(number_z[i]!=p->number_z[i])
			{
				flag=0;
				break;
			}
		}
		if (flag==1)return p;
		p=p->next;
	}
	return NULL;
}
//添加sock
int LinkList::add_sock(NODE *Node,SOCKET sock_c)
{
	if(Node!=NULL)
	{
		Node->sock_c=sock_c;
		return 1;
	}
	else
		return -1;
}
NODE* LinkList::Gethead()
{
	return head;
}