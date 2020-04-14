#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdio.h>
#include"windows.h"
typedef struct node {
	SOCKET sock_c;
    int data;
    struct node *next;
	char number_z[10];
	char number_m[16];
}NODE;
//类定义
class LinkList
{
private:
    NODE *head;
public:
    LinkList() { head = NULL; }
    ~LinkList();
    bool clearSqList();
    bool isEmpty() { return head == NULL; }
    int Length();
    bool Delete(char*);//删除,成功返回true；
	bool add(char*,char*);//在链表末尾添加元素
	int check_ex(char*,char*,char number_m1[]);//账号，原密码，新密码。,账号不存在返回0，原密码错误返回1,更改成功返回2。
	int check(char*,char number_m[16]='\0');//核对账号密码  全对返回2，账号存在密码错误返回1，账号不存在返回0；
	int UmsgToFile();
	int FileToUmsg();
    NODE * Reverse();
	void out(HWND hWnd,UINT Msg,WPARAM wParam=0);
	int number_create(char*);//生成不重复9位账号
	char*return_nuber_m(char*);//返回密码
	NODE*Search(char number_z[]);//返回指针
	int add_sock(NODE *Node,SOCKET sock_c);//添加sock		成功返回1，失败返回-1
	NODE* Gethead();//返回head
};


#endif