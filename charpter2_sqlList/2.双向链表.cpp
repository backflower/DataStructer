# include <stdio.h>
# include <string.h>
# include <iostream>
# define  OK 100
# define ERRO -100
using namespace std;


typedef int STATUS;

//����������
typedef struct Element 
{
	int ID;
	char name[50];
}Element ;

typedef struct Node
{
	Element element;//������
	Node * prior;//ָ������һ��ָ��
	Node * next;//ָ������һ��ָ��
	
} Node , *LinkList;

STATUS InitLinkList(LinkList &L);

int main ()
{
	LinkList L;
	STATUS s= InitLinkList(L);
	if(s==OK)
	{
		printf("��ʼ��˫����ɹ�!\n");
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
