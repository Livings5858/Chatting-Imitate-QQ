#pragma once
#include"Linklist集合.h"
//#include"LinkList.h"
#include<iostream>
#include<fstream>
#include"windows.h"
#include <direct.h>
#include<io.h>
using namespace std;

//Node_Message *head_message=NULL;
Node_Num	*head_num=NULL;
num_msg     *head_msg=NULL;

//清空结构体
void ClrearStruct(unsigned char *pta,int size)
{
	while(size>0)
	{
		*pta++='\0';
		size--;
	}
}

//int add_message(char text[512])
//{
//	Node_Message *p=head_message,*NewNode;
//	
//	NewNode = new Node_Message;
//	strcpy_s(NewNode->text,text);
//	NewNode->next=NULL;
//	if(p==NULL)
//	{
//		head_message=NewNode;
//	}
//	else
//	{
//		while(p->next!=NULL)
//			p=p->next;
//		p->next=NewNode;
//	}
//	return 0;
//}
//int add_Num(char num_z[10],Node_Message *Node)
//{
//	Node_Num *p=head_num,*NewNode;
//	
//	NewNode = new Node_Num;
//	NewNode->NodeMessage=Node;
//	strcpy_s(NewNode->num_z,num_z);
//	NewNode->next=NULL;
//	if(p==NULL)
//	{
//		head_num=NewNode;
//	}
//	else
//	{
//		while(p->next!=NULL)
//			p=p->next;
//		p->next=NewNode;
//	}
//	return 0;
//}

//返回账号下指针
 Node_Num*Search(char num_z[10])
{
	Node_Num*p=head_num;
	int flag=0;
	while(1)
	{
		if(p==NULL)	break;
		flag=1;
		//if(p==NULL)	break;
		for(int i=0;i<10;i++)
		{
			if(num_z[i]!=p->num_z[i])
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
 //添加待发送信息
//int add_message(char num_z[10],char num_z1[10],char text[512])
//{
//	
//	Node_Message*NewNode;
//	Node_Num*Newnode=NULL;
//	Node_Num *p1=head_num;
//	Node_Num*p=Search(num_z);
//	NewNode = new Node_Message;
//	strcpy_s(NewNode->text,text);
//	NewNode->next=NULL;
//	if(p!=NULL)
//	{
//		if(p->NodeMessage==NULL)
//		{
//		p->NodeMessage=NewNode;
//		}
//		else
//		{
//		while(p->NodeMessage->next!=NULL)
//			p->NodeMessage=p->NodeMessage->next;
//		p->NodeMessage->next=NewNode;
//		}
//	}
//	else
//	{
//		strcpy_s(Newnode->num_z,num_z);
//		strcpy_s(Newnode->num_z1,num_z1);
//		Newnode->next=NULL;
//		Newnode->NodeMessage=NewNode;
//		if(p1==NULL)
//		{
//		head_num=Newnode;
//		}
//		else
//		{
//		while(p1->next!=NULL)
//			p=p1->next;
//		p1->next=Newnode;
//		}
//	}
//	return 0;
//
//}
//删除待发送账号

 //添加消息
 int add_message(char num_z1[10],char num_z[10],char text[512],int ID,char name[16])
 {
	 int flag,i;
	Node_Num*p=head_num,*NewNode1;//大
	NewNode1=new Node_Num;
	Node_Message* p1,*NewNode;	//小
	NewNode= new Node_Message;
	strcpy_s(NewNode->text,text);
	strcpy_s(NewNode->num_z1,num_z1);		//send账号
	NewNode->ID=ID;
	NewNode->next=NULL;
	while(1)
	{
		if(p==NULL)break;
		flag=1;
		for(i=0;i<10;i++)
		if(p->num_z[i]!=num_z[i])
		{
			flag=0;
			break;
		}
		if(flag==1)
		{
			p1=p->NodeMessage;
			//strcpy_s(NewNode->text,text);
			//strcpy_s(NewNode->num_z1,num_z1);		//send账号
			//NewNode->ID=ID;
			//NewNode->next=NULL;
			if(p1==NULL)
			{
				p->NodeMessage=NewNode;
			}
			else
			{
				while(p1->next!=NULL)
					p1=p1->next;
				p1->next=NewNode;
			}
				return 1;//加入成功
		}
		p=p->next;
	}

	//strcpy_s(NewNode->text,text);
	//NewNode->ID=ID;
	//strcpy_s(NewNode->num_z1,num_z1);		//send账号
	//NewNode->next=NULL;
	p=head_num;
	NewNode1->next=NULL;
	NewNode1->NodeMessage=NewNode;
	strcpy_s(NewNode1->num_z,num_z);		//recv账号
	strcpy_s(NewNode1->name,name);
	if(p==NULL)
	{
		head_num=NewNode1;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=NewNode1;
	}

	return 2;				//添加了一个recv 账号

 }
bool Delete(char number_z[10])
{
	Node_Num*p=head_num,*Del;
	int flag;
	if(p==NULL)	return false;
	if(strcmp(head_num->num_z,number_z)==0)
	{
		head_num=p->next;
		delete p;
		return true;
	}
	while(p->next!=NULL)
	{
		 flag=1;
		for(int i=0;i<10;i++)
		{
			if(number_z[i]!=p->next->num_z[i])
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
//获取当前文本列表长度
int Length(Node_Num*Node)
{
	Node_Message *p = Node->NodeMessage;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

/********************************************************************************/
//初始化个人信息
void init_msg(num_msg*p)
{
	p->frd_head=NULL;
	p->age=0;
	p->sex=0;
	p->next=NULL;
	memset(p->name,'\0',16);
	memset(p->tel,'\0',16);
}
//添加个人信息
int add_msg_num_z(char num_z[10])
{
	int i;
	num_msg *p=head_msg,*NewNode;
	NewNode=new num_msg;
	ClrearStruct((unsigned char*)NewNode,sizeof(num_msg));
	for(i=0;i<10;i++)
	{
		NewNode->num_z[i]=num_z[i];
	}
	init_msg(NewNode);
	if(head_msg==NULL)
		head_msg=NewNode;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=NewNode;
	}
	return 0;
}
int add_msg_num_all(char num_z[10],char name[16],char tel[12],int age,int sex)
{
	int i=0;
	num_msg *p=head_msg,*NewNode;
	NewNode=new num_msg;
	init_msg(NewNode);
	/*strcpy_s(NewNode->num_z,strlen(name)+1,name);
	strcpy_s(NewNode->name,strlen(num_z)+1,num_z);
	strcpy_s(NewNode->tel,strlen(tel)+1,tel);*/
	for(i=0;i<10;i++)
	{
		NewNode->num_z[i]=num_z[i];
	}
	for(i=0;i<16;i++)
	{
		NewNode->name[i]=name[i];
	}
	for(i=0;i<12;i++)
	{
		NewNode->tel[i]=tel[i];
	}
	NewNode->age=age;
	NewNode->sex=sex;
	NewNode->next=NULL;
	if(head_msg==NULL)
		head_msg=NewNode;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=NewNode;
	}
	return 0;
}
//返回个人信息
num_msg* search_msg(char num_z[10])
{
	int flag,i;
	num_msg*p=head_msg;
	while(1)
	{
		if(p==NULL)break;
		flag=1;
		for(i=0;i<10;i++)
		if(p->num_z[i]!=num_z[i])
		{
			flag=0;
			break;
		}
		if(flag==1)return p;
		p=p->next;
	}
	return NULL;
}
//添加好友账号
int add_msg_frd_z(char num_z[10],char num_frd[10])
{
	int flag,i,j;
	num_msg*p=head_msg;
	num_friend* p1,*NewNode;
	NewNode=new num_friend;
	while(1)
	{
		if(p==NULL)break;
		flag=1;
		for(i=0;i<10;i++)
		if(p->num_z[i]!=num_z[i])
		{
			flag=0;
			break;
		}
		if(flag==1)
		{
			p1=p->frd_head;
			//strcpy_s(NewNode->num_frd,strlen(num_frd)+1,num_frd);
			for(j=0;j<10;j++)
			{
				NewNode->num_frd[j]=num_frd[j];
			}
			NewNode->next=NULL;
			if(p1==NULL)
			{
				p->frd_head=NewNode;
			}
			else
			{
				while(p1->next!=NULL)
					p1=p1->next;
				p1->next=NewNode;
			}
				return 1;//加入成功
		}
		p=p->next;
	}
	return -1;//没有账号
}
//删除该条目(不常用)
bool delete_msg(char num_z[10])
{
	/*num_msg*p=head_msg,*Del;
	int flag;
	while(1)
	{
		if(p==NULL)	break;
		if(strcmp(head_msg->num_z,num_z)==0)
			{
				head_num=p->next;
				return true;
			}
		 flag=1;
		for(int i=0;i<10;i++)
		{
			if(num_z[i]!=p->next->num_z[i])
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
	return false;*/
	return true;
}

struct Filebag
{
	int age;
	char name[16];
	char num_z[10];
	char tel[12];
	int sex;
};

////存出文件
//int Unum_msgToFile()
//{
//	
//	FILE* pFile;
//	/*int err=fopen_s(&pFile,"用户信息1.txt","w");*/
//	char name[30];
//	//char* add=".txt";
//	num_msg *p=head_msg;
//	num_friend *p1;
//	char num_z1[10];
//	while(1)
//	{
//		if(p==NULL)break;
//		memset(name,'\0',30);
//		sprintf_s(name,".\\res\\%s.txt",p->num_z);
//		int err=fopen_s(&pFile,name,"w");
//		if(err!=0)
//			MessageBox(NULL,("Error"),"error",MB_OK);
//		int i=0;
//		Filebag msg1;
//		strcpy_s(msg1.name,p->name);
//		strcpy_s(msg1.num_z,p->num_z);
//		strcpy_s(msg1.tel,p->tel);
//		msg1.age=p->age;
//		msg1.sex=p->sex;
//		fwrite(&msg1,sizeof(Filebag),1,pFile);
//		p1=p->frd_head;
//		while(p1!=NULL)
//		{
//			strcpy_s(num_z1,p1->num_frd);
//			fwrite(&num_z1,sizeof(num_z1),1,pFile);
//			p1=p1->next;
//		}
//		fclose(pFile);
//		p=p->next;
//
//	}
//	
//	return 0;
//}
////导入信息
//int FileToUnum_msg(LinkList LI_1)
//{
//	NODE*p=LI_1.Gethead();
//	FILE* pFile;
//	char name[30];
//	char num_z1[10];
//	while(1)
//	{
//		if(p==NULL)break;
//		memset(name,'\0',30);
//		sprintf_s(name,"./res/%s.txt",p->number_z);
//		int err=fopen_s(&pFile,name,"r");
//		if(err!=0)
//			MessageBox(NULL,("Error"),"error",MB_OK);
//		Filebag msg2;
//		fread(&msg2,sizeof(Filebag),1,pFile);
//		add_msg_num_all(msg2.num_z,msg2.name,msg2.tel,msg2.age,msg2.sex);
//		while(1)
//		{
//			fread(&num_z1,sizeof(num_z1),1,pFile);
//			add_msg_frd_z(p->number_z,num_z1);
//			if(feof(pFile))break;
//		}
//		fclose(pFile);
//		p=p->next;
//	}
//	return 0;
//}


//存出文件
int Unum_msgToFile()
{

	int i;
	FILE* pFile;
	FILE* pFile1;
	/*int err=fopen_s(&pFile,"用户信息1.txt","w");*/
	//char name[30];
	//char* add=".txt";
	num_msg *p=head_msg;
	num_friend *p1;
	char num_z1[10];
	int err1=fopen_s(&pFile1, ".\\res\\userMsg\\usermsg.txt","w");
	if(err1!=0)
			MessageBox(NULL,("Error1"),"error",MB_OK);
	while(1)
	{
		if(p==NULL)break;
		Filebag msg1;
		/*strcpy_s(msg1.name,strlen(p->name)+1,p->name);
		strcpy_s(msg1.num_z,strlen(p->num_z)+1,p->num_z);
		strcpy_s(msg1.tel,strlen(p->tel)+1,p->tel);*/

		strcpy_s(msg1.name,p->name);
		strcpy_s(msg1.num_z,p->num_z);
		strcpy_s(msg1.tel,p->tel);
		msg1.age=p->age;
		msg1.sex=p->sex;
		fwrite(&msg1,sizeof(Filebag),1,pFile1);
		/*char name[30];
		sprintf_s(name,".\\res\\%s.txt",p->num_z);*/
		char *name=new char[30];
		char head_h_p[]= ".\\res\\";
		char* head_h = head_h_p;
		char add_a_p[]=".txt";
		char* add_a = add_a_p;
		for(i=0;*head_h!='\0';i++)
		{
			name[i]=*(head_h++);
		}
		for(int j=0;p->num_z[j]!='\0';j++,i++)
		{
			name[i]=p->num_z[j];
		}
		for(;*add_a!='\0';i++)
		{
			name[i]=*(add_a++);
		}
		name[i]='\0';
		int err=fopen_s(&pFile,name,"w");
		if(err!=0)
			MessageBox(NULL,("Error"),"error",MB_OK);

		p1=p->frd_head;
		while(p1!=NULL)
		{
			strcpy_s(num_z1,p1->num_frd);
			fwrite(&num_z1,sizeof(num_z1),1,pFile);
			p1=p1->next;
		}
		fclose(pFile);
		p=p->next;

	}
	fclose(pFile1);
	return 0;
}
//导入信息
int FileToUnum_msg()
{
	//NODE*p=LI_1.Gethead();
	FILE* pFile,*pFile1;
	int i;
	//char name[30];
	char num_z1[10];
	int err1=fopen_s(&pFile1,".\\res\\userMsg\\usermsg.txt","r");
	if(err1!=0)
			MessageBox(NULL,("Error1"),"error",MB_OK);
	while(1)
	{
		Filebag msg2;
		fread(&msg2,sizeof(Filebag),1,pFile1);
		if(feof(pFile1))break;
		add_msg_num_all(msg2.num_z,msg2.name,msg2.tel,msg2.age,msg2.sex);
		char *name=new char[30];
		char head_h_p[]=".\\res\\";
		char* head_h = head_h_p;
		char add_a_p[]=".txt";
		char* add_a = add_a_p;
		for(i=0;*head_h!='\0';i++)
		{
			name[i]=*(head_h++);
		}
		for(int j=0;msg2.num_z[j]!='\0';j++,i++)
		{
			name[i]=msg2.num_z[j];
		}
		for(;*add_a!='\0';i++)
		{
			name[i]=*(add_a++);
		}
		name[i]='\0';
		//sprintf_s(name,".\\res\\%s.txt",msg2.num_z);
		int err=fopen_s(&pFile,name,"r");
		if(err!=0)
			MessageBox(NULL,("Error"),"error",MB_OK);
		else
		{
			while (1)
			{

				fread(&num_z1, sizeof(num_z1), 1, pFile);
				if (feof(pFile))break;
				add_msg_frd_z(msg2.num_z, num_z1);
			}
			fclose(pFile);
		}
			
	}
	fclose(pFile1);
	return 0;
}


//创建文件夹及空文件usermsg.txt,userMessage.txt

void InitDirAndFiles()
{
	if (0 != _access(".\\res", 0))
	{
		// if this folder not exist, create a new one.
		_mkdir(".\\res");   // 返回 0 表示创建成功，-1 表示失败
		//换成 ::_mkdir  ::_access 也行，不知道什么意思
	}
	if (0 != _access(".\\res\\userMsg", 0))
	{
		// if this folder not exist, create a new one.
		_mkdir(".\\res\\userMsg");   // 返回 0 表示创建成功，-1 表示失败
		//换成 ::_mkdir  ::_access 也行，不知道什么意思
	}
	FILE* pFile1=NULL, *pFile2 = NULL;
	fopen_s(&pFile1, ".\\res\\userMsg\\usermsg.txt", "a+");
	fopen_s(&pFile2, ".\\res\\userMsg\\userMessage.txt", "a+");
	if (pFile1 != NULL)
		fclose(pFile1);
	if (pFile2 != NULL)
		fclose(pFile2);
}