#include"Linklist集合.h"
#include<iostream>
#include<fstream>
#include<time.h>
#include"windows.h"
using namespace std;

//Node_Message*head_message=NULL;
//Node_Num	*head_num=NULL;
pMsg		*head_pmsg=NULL;//好友
//trans_msg	*head_msg;
//check_msg *check_msg_head=NULL;
check_num*	check_num_head=NULL;//验证信息号码

//清空结构体
void ClearStruct(unsigned char *pta,int size)
{
	while(size>0)
	{
		*pta++=0;
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
/*****************************************************************************************************************/
/***********************************消息链表**********************************************************************/
////返回账号下指针
// Node_Num*Search(char num_z[10])
//{
//	Node_Num*p=head_num;
//	int flag=0;
//	while(1)
//	{
//		if(p==NULL)	break;
//		flag=1;
//		//if(p==NULL)	break;
//		for(int i=0;i<10;i++)
//		{
//			if(num_z[i]!=p->num_z[i])
//			{
//				flag=0;
//				break;
//			}
//		}
//		if (flag==1)return p;
//		p=p->next;
//	}
//	return NULL;
//}
// //添加待发送信息
////int add_message(char num_z[10],char num_z1[10],char text[512])
////{
////	
////	Node_Message*NewNode;
////	Node_Num*Newnode=NULL;
////	Node_Num *p1=head_num;
////	Node_Num*p=Search(num_z);
////	NewNode = new Node_Message;
////	strcpy_s(NewNode->text,text);
////	NewNode->next=NULL;
////	if(p!=NULL)
////	{
////		if(p->NodeMessage==NULL)
////		{
////		p->NodeMessage=NewNode;
////		}
////		else
////		{
////		while(p->NodeMessage->next!=NULL)
////			p->NodeMessage=p->NodeMessage->next;
////		p->NodeMessage->next=NewNode;
////		}
////	}
////	else
////	{
////		strcpy_s(Newnode->num_z,num_z);
////		strcpy_s(Newnode->num_z1,num_z1);
////		Newnode->next=NULL;
////		Newnode->NodeMessage=NewNode;
////		if(p1==NULL)
////		{
////		head_num=Newnode;
////		}
////		else
////		{
////		while(p1->next!=NULL)
////			p=p1->next;
////		p1->next=Newnode;
////		}
////	}
////	return 0;
////
////}
////删除待发送账号
//
// //添加消息
// int add_message(char num_z1[10],char num_z[10],char text[512])
// {
//	 int flag,i;
//	 Node_Num*p=head_num,*NewNode1;
//	NewNode1=new Node_Num;
//	Node_Message* p1,*NewNode;
//	NewNode= new Node_Message;
//	while(1)
//	{
//		if(p==NULL)break;
//		flag=1;
//		for(i=0;i<10;i++)
//		if(p->num_z[i]!=num_z[i])
//		{
//			flag=0;
//			break;
//		}
//		if(flag==1)
//		{
//			p1=p->NodeMessage;
//			strcpy_s(NewNode->text,text);
//			NewNode->next=NULL;
//			if(p1==NULL)
//			{
//				p->NodeMessage=NewNode;
//			}
//			else
//			{
//				while(p1->next!=NULL)
//					p1=p1->next;
//				p1->next=NewNode;
//			}
//				return 1;//加入成功
//		}
//		p=p->next;
//	}
//
//	strcpy_s(NewNode->text,text);
//	NewNode->next=NULL;
//	NewNode1->next=NULL;
//	NewNode1->NodeMessage=NewNode;
//	strcpy_s(NewNode1->num_z,num_z);		//recv账号
//	strcpy_s(NewNode1->num_z1,num_z1);		//send账号
//	if(p==NULL)
//	{
//		head_num=NewNode1;
//	}
//	else
//	{
//		while(p->next!=NULL)
//			p=p->next;
//		p->next=NewNode1;
//	}
//
//	return 2;				//添加了一个recv 账号
//
//
//	//return -1;//没有账号
// }
//bool Delete(char number_z[10])
//{
//	Node_Num*p=head_num,*Del;
//	int flag;
//	while(1)
//	{
//		if(p==NULL)	break;
//		if(p->next==NULL)
//			{
//				head_num=NULL;
//				return true;
//			}
//		 flag=1;
//		for(int i=0;i<10;i++)
//		{
//			if(number_z[i]!=p->next->num_z[i])
//				{
//					flag=0;
//					break;
//				}
//		}
//		if(flag==1)
//		{
//			Del=p->next;
//			p->next=Del->next;
//			delete Del;
//			return true;
//		}
//		p=p->next;
//	}
//	return false;
//}
////获取当前文本列表长度
//int Length(Node_Num*Node)
//{
//	Node_Message *p = Node->NodeMessage;
//    int len = 0;
//    while (p != NULL)
//    {
//        len++;
//        p = p->next;
//    }
//    return len;
//}





/***************************************************************************************************************/
/***************************************好友列表****************************************************************/


//添加好友
int add_pMsg(char num_z[10], char Name[16], int sex, int age, char tel[12], char Remark[16])
{
	pMsg* p = head_pmsg, * NewNode = new pMsg{0};
	//NewNode=new pMsg;
	//ClearStruct((unsigned char*)NewNode,sizeof(pMsg));
	strcpy_s(NewNode->Num_z,num_z);
	if (strlen(tel) != 0)
	{
		
		strcpy_s(NewNode->tel, tel);
		
	}
	if (strlen(Name) != 0)
	strcpy_s(NewNode->Name,Name);
	if (strlen(Remark) != 0)
	strcpy_s(NewNode->Remark,Remark);
	NewNode->age=age;
	NewNode->sex=sex;
	NewNode->next = NULL;
	
	if(head_pmsg==NULL)
	{
		head_pmsg=NewNode;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=NewNode;
	}
	return 0;
}
int add_pMsg(char num_z[10], char Name[16], int sex, int age, char tel[12])
{
	pMsg* p = head_pmsg, * NewNode = new pMsg{ 0 };
	//NewNode=new pMsg;
	//ClearStruct((unsigned char*)NewNode,sizeof(pMsg));
	strcpy_s(NewNode->Num_z, num_z);
	if (strlen(tel) != 0)
	{
		strcpy_s(NewNode->tel, tel);
	}

	if (strlen(Name) != 0)
		strcpy_s(NewNode->Name, Name);
	NewNode->age = age;
	NewNode->sex = sex;
	NewNode->next = NULL;

	if (head_pmsg == NULL)
	{
		head_pmsg = NewNode;
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = NewNode;
	}
	return 0;
}

int add_pMsg(char num_z[10], char Name[16])
{
	pMsg* p = head_pmsg, * NewNode = new pMsg{ 0 };
	//NewNode=new pMsg;
	//ClearStruct((unsigned char*)NewNode,sizeof(pMsg));
	strcpy_s(NewNode->Num_z, num_z);

	if (strlen(Name) != 0)
		strcpy_s(NewNode->Name, Name);

	NewNode->next = NULL;

	if (head_pmsg == NULL)
	{
		head_pmsg = NewNode;
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = NewNode;
	}
	return 0;
}

//删除好友
bool delete_pMsg(char num_z[10])
{
	pMsg *p=head_pmsg,*Del;
	
	int flag;
	
		if(p==NULL)	return false;
		if(strcmp(head_pmsg->Num_z,num_z)==0)
			{
				head_pmsg=p->next;
				delete p;
				return true;
			}
	while(p->next!=NULL)
	{
		 flag=1;
		for(int i=0;i<10;i++)
		{
			if(num_z[i]!=p->next->Num_z[i])
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
//查找好友
pMsg *search_pMsg(char num_z[10])
{
	pMsg *p=head_pmsg;
	int flag=0;
	while(1)
	{
		if(p==NULL)	break;
		flag=1;
		for(int i=0;i<10;i++)
		{
			if(num_z[i]!=p->Num_z[i])
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
//更改备注
int change_pMsg_Remark(char num_z[10],char name[16])
{
	pMsg *p=head_pmsg;
	int flag=0;
	while(1)
	{
		if(p==NULL)	break;
		flag=1;
		for(int i=0;i<10;i++)
		{
			if(num_z[i]!=p->Num_z[i])
			{
				flag=0;
				break;
			}
		}
		if (flag==1)
			{
				memset(p->Remark,16,'\0');
				strcpy_s(p->Remark,name);
				return 1;
			}
	}
	return 0;
}


/**************************************************************************************************************/

//time_t tt = time(NULL);//这句返回的只是一个时间cuo
// tm* t= localtime(&tt);

////添加消息
//int add_msg(char num_z[10],tm*time,int to_or_from,char text[512])
//{
//	 int flag,i;
//	trans_msg*p=head_msg,*NewNode1;
//	NewNode1=new trans_msg;
//	msg_list* p1,*NewNode;
//	NewNode= new msg_list;
//	while(1)
//	{
//		if(p==NULL)break;
//		flag=1;
//		for(i=0;i<10;i++)
//		if(p->num_z[i]!=num_z[i])
//		{
//			flag=0;
//			break;
//		}
//		if(flag==1)
//		{
//			p1=p->msg_head;
//			strcpy_s(NewNode->text,text);
//			NewNode->t=time;
//			NewNode->to_or_from=to_or_from;
//			NewNode->next=NULL;
//			if(p1==NULL)
//			{
//				p->msg_head=NewNode;
//			}
//			else
//			{
//				while(p1->next!=NULL)
//					p1=p1->next;
//				p1->next=NewNode;
//			}
//				return 1;//加入成功
//		}
//		p=p->next;
//	}
//
//	strcpy_s(NewNode->text,text);
//	NewNode->next=NULL;
//	NewNode->t=time;
//	NewNode->to_or_from=to_or_from;
//	NewNode1->next=NULL;
//	NewNode1->msg_head=NewNode;
//	strcpy_s(NewNode1->num_z,num_z);		//recv账号
//	if(p==NULL)
//	{
//		head_msg=NewNode1;
//	}
//	else
//	{
//		while(p->next!=NULL)
//			p=p->next;
//		p->next=NewNode1;
//	}
//
//	return 2;				//添加了一个账号
//}
////清空消息
//bool delete_msg(char num_z[10])
//{
//	trans_msg *p=head_msg,*Del;
//	if(p==NULL)return false;
//		if(strcmp(head_pmsg->Num_z,num_z)==0)
//			{
//				head_pmsg=p->next;
//				return true;
//			}
//		else
//			return false;
//	int flag;
//	while(1)
//	{
//		 flag=1;
//		for(int i=0;i<10;i++)
//		{
//			if(num_z[i]!=p->next->num_z[i])
//				{
//					flag=0;
//					break;
//				}
//		}
//		if(flag==1)
//		{
//			Del=p->next;
//			p->next=Del->next;
//			delete Del;
//			return true;
//		}
//		p=p->next;
//	}
//	return false;
//}
////返回消息队列头指针
//msg_list *search_msg(char num_z[10])
//{
//	trans_msg *p=head_msg;
//	int flag=0;
//	while(1)
//	{
//		if(p==NULL)	break;
//		flag=1;
//		for(int i=0;i<10;i++)
//		{
//			if(num_z[i]!=p->num_z[i])
//			{
//				flag=0;
//				break;
//			}
//		}
//		if ((flag==1)&&(p->msg_head!=NULL))
//			return p->msg_head;
//		p=p->next;
//	}
//	return NULL;
//}


/**********************************************************/
//listbox索引
search_for *head_search_for=NULL;
void add_search_for(int index,char num_z_search[10],int line)
{
	search_for*p=head_search_for,*NewNode;
	NewNode=new search_for;
	NewNode->index=index;
	NewNode->line=line;
	strcpy_s(NewNode->num_z,num_z_search);
	NewNode->next=NULL;
	if(p==NULL)
	{
		head_search_for=NewNode;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=NewNode;
	}
}
char*Search_for(int index)
{
	search_for*p=head_search_for;
	while(p!=NULL)
	{
		if(p->index==index)
			return p->num_z;
		p=p->next;
	}
	return NULL;
}
search_for* Search_for(char num_z_search[10])
{
	search_for*p=head_search_for;
	int flag_search=1;
	while(p!=NULL)
	{
		for(int i=0;i<10;i++)
		{
			if(p->num_z[i]!=num_z_search[i])
			

				flag_search=0;
		}
		if(flag_search==1)return p;
		p=p->next;
	}
	return NULL;
}
bool Delete_search(int index)
{
	search_for*p=head_search_for,*Del=NULL;
	if(p==NULL)return false;
		if(head_search_for->index==index)
		{	
			head_search_for=p->next;
			delete p;
			return true;
		}
	while(p->next!=NULL)
	{
		if(p->next->index==index)
			Del=p->next;
		p->next=Del->next;
		delete Del;
		p=p->next;
	}
	return true;
}
bool Delete_search(char num_z_search[10])
{
	search_for *p=head_search_for,*Del;
	
	int flag;
	while(1)
	{
		if(p==NULL)	break;
		if(strcmp(head_search_for->num_z,num_z_search)==0)
			{
				head_search_for=p->next;
				delete p;
				return true;
			}
		 flag=1;
		for(int i=0;i<10;i++)
		{
			if(num_z_search[i]!=p->next->num_z[i])
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

//验证消息
//int add_check_msg(char num_z[10],char text[512])
//{
//	check_msg*p=check_msg_head,*NewNode;
//	while(p!=NULL)
//	{
//		if(strcmp(num_z,p->num_z)==0)
//		{
//			memset(p->text,'\0',512);
//			strcmp(p->text,text);
//			return 1;
//		}
//
//		p=p->next;
//	}
//	p=check_msg_head;
//	NewNode=new check_msg;
//	NewNode->next=NULL;
//	strcpy_s(NewNode->num_z,num_z);
//	strcpy_s(NewNode->text,text);
//	if(p==NULL)
//	{
//		check_msg_head=NewNode;
//		return 2;
//	}
//	else
//	{
//		while(p->next!=NULL)
//			p=p->next;
//		p->next=NewNode;
//		return 2;
//	}
//	return 0;
//}
//void delete_check_msg(char num_z[10])
//{
//	check_msg*p=check_msg_head,*Del;
//	if(p==NULL)return;
//	if(p->next==NULL)
//	if(strcmp(num_z,check_msg_head->num_z)==0)
//	{
//		check_msg_head=NULL;
//		return;
//	}
//	while(p->next!=NULL)
//	{
//		if(strcmp(num_z,p->next->num_z)==0)
//		{
//			Del=p->next;
//			p->next=Del->next;
//			delete Del;
//			return;
//		}
//
//		p=p->next;
//	}
//}

//验证号码
int add_check_num(char num_z[10])
{
	check_num*p=check_num_head,*NewNode;
	NewNode=new check_num;
	strcpy_s(NewNode->num_z,num_z);
	NewNode->next=NULL;
	if(p==NULL)
	{
		check_num_head=NewNode;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=NewNode;
	}
	return 0;
}
int delete_check_num(char num_z[10])
{
	check_num*p=check_num_head,*Del;
	if(p==NULL)return 0;
	if(strcmp(p->num_z,num_z)==0)
	{
		check_num_head=p->next;
		delete p;
		return 0;
	}
	while(p->next!=NULL)
	{
		if(strcmp(p->next->num_z,num_z)==0)
		{
			Del=p->next;
			p->next=Del->next;
			delete Del;
			return 0;
		}
		p=p->next;
	}
	return 0;
}
check_num*search_check_num(char num_z[10])
{
	check_num*p=check_num_head;
	while(p!=NULL)
	{
		if(strcmp(p->num_z,num_z)==0)
			return p;
	}
	return NULL;
}

//离线消息
out_msg *head_out_msg=NULL,*rear_out_msg=NULL;
char buff_out[530];
//判空
int Empty()//判空
{
	if(head_out_msg==NULL&&rear_out_msg==NULL)
		return 1;
	else
		return 0;
}
int add_out_msg(char buff[530])//入队
{
	out_msg*p=head_out_msg,*NewNode;
	NewNode=new out_msg;
	memset(NewNode->buff,'\0',530);
	strcpy_s(NewNode->buff,buff);
	NewNode->next=NULL;
	if(head_out_msg==NULL&&rear_out_msg==NULL)
	{
		head_out_msg=rear_out_msg=NewNode;
	}
	else
	{
		rear_out_msg->next=NewNode;
		rear_out_msg=NewNode;
	}
	return 0;
}
char* out_out_msg()//出队
{
	out_msg*p;
	if(Empty())return NULL;
	else
	{
		if(rear_out_msg==head_out_msg)
		{
			p=head_out_msg;
			head_out_msg=rear_out_msg=NULL;
			memset(buff_out,'\0',530);
			strcpy_s(buff_out,p->buff);
			delete p;
			return buff_out;
		}
		else
		{
			p=head_out_msg;
			head_out_msg=head_out_msg->next;
			strcpy_s(buff_out,p->buff);
			delete p;
			return buff_out;
		}
	}
}

