# include <stdio.h>
# include <string.h>
# include <iostream>
# define  OK 100
# define ERRO -100
using namespace std;


typedef int STATUS;

//声明数据域
typedef struct Element 
{
	int ID;
	char name[50];
}Element ;

typedef struct Node
{
	Element element;//数据域
	Node * prior;//指针域上一个指针
	Node * next;//指针域下一个指针
	
} Node , *LinkList;

STATUS InitLinkList(LinkList &L);

int main ()
{
	LinkList L;
	STATUS s= InitLinkList(L);
	if(s==OK)
	{
		printf("初始化双链表成功!\n");
	}
	return 0;
}

STATUS InitLinkList(LinkList &L)
{
	L=new Node;
	L->element=* new Element;
	L->next=NULL;
	return OK;
}
