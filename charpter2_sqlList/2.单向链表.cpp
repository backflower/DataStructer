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
	Element *element;//数据域
	Node * next;//指针域下一个指针
} Node , *LinkList;

STATUS initNode(LinkList &L);//初始化单向

STATUS GetLinkList(LinkList L,int j ,Element & e);//获取指定索引的值

Node * LocateLinkList(LinkList L,Element e);//定位包含元素e的节点Node 

bool CompareElement(Element e1,Element e2);//比较两个元素相等

STATUS InsertElement (Element e,LinkList &L,int i);//在第j个位置插入元素e

void showElement(LinkList L);//打印链表的所有节点

STATUS CreateLinkList_fromt(LinkList &L,int n);//前插法创建链表

STATUS CreateLinkList_last(LinkList &L,int n);//后插法创建链表

STATUS DeleteElement(LinkList &L,int i);//删除指定位置的元素
	

int main ()
{
	LinkList L;
	STATUS status=initNode(L);
	if(status==OK) {
		printf("初始化成功!\n元素->ID:%d \t 元素->ID:%s",L->element->ID,L->element->name);
	}
	return 0;
}


STATUS initNode (LinkList &L)//初始化单向链表
{
	L = new  Node;
//	L->element=new Element;
//	L->element->ID=0;
//	memset(L->element->name,'\0',50);
	L->next=NULL;
	return OK;
}


STATUS GetLinkList(LinkList L,int j ,Element &e)//获取指定索引的值
{
	Node * p;
	p=L->next;
	int i=1;
	while(p&&(i<j))
	{
		p=p->next;
		i++;
	}
	if((i>j)||!p) return ERRO;
	e = * p->element;
	return OK;
}

Node * LocateLinkList(LinkList L,Element e)//定位包含元素e的节点Node 
{
		Node * p;
		p=L->next;
		while(p&&(CompareElement(*p->element,e)))
		{
			p=p->next;
		}
		return p;
		
}

bool CompareElement(Element e1,Element e2)
{
			if(((e1.ID==e2.ID))&&(strcmp(e1.name,e2.name)))	return true;
			return false;
}

STATUS InsertElement (Element e,LinkList &L,int i)//在第j个位置插入元素e
{
	//1.找到第i-1个元素
	//2.新建一个元素S
	//S的值域设置为元素e
	//3.将S指针域指向i个元素
	//4.将第i-1个指针域指向S
	Node *p;
	p=L;
	int j=0;
	while(p&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if((!p)||(j>(i-1))) return ERRO;
	Node * s=new Node;
	* s->element=e;
	s->next=p->next;
	p->next=s;
	return OK;
}


void showElement(LinkList L)
{
	Node * p ;
	p=L->next;
	while(p)
	{
		cout<<"ID:"<<p->element->ID<<" Name:"<<p->element->name<<"\t";	
		p=p->next;
	}
	cout<<"\n";
}


STATUS CreateLinkList_fromt(LinkList &L,int n)//前插法
{
	L->next=NULL;
	Node *p ;
	p=L;
	for(int i=0;i<n;i++)
	{
		Node *s=new Node;
		s->element=new Element ;
		s->element->ID=(i+1);
		cout<<"输入第"<<(i+1)<<"个元素的值:";
		cin>>s->element->name;
		s->next=p->next;
		p->next=s;				
	}
	return OK;
}

STATUS CreateLinkList_last(LinkList &L,int n)//后插法
{
	L->next=NULL;
	Node *p;
	p=L;
	for(int j=0;j<n;j++)
	{
		Node *s =new Node;
		s->element=new Element;
		s->element->ID=(j+1);
		cout<<"输入第"<<(j+1)<<"个元素 Name :";
		cin>>s->element->name;
		s->next=NULL;
		p->next=s;
		p=s;
	}
	return OK;
}

STATUS   DeleteElement(LinkList &L,int i)//删除指定位置的元素
{

	Node * p;
	p=L;
	int j=0;
	while((p->next)&&(j<i-1))//定位到第i-1个元素
	{
		p=p->next;
		j++;	
	}
	if((!p->next)||(j>(i-1))) return ERRO;
	
 	Node *s =new Node;
	s=p->next;//定位到i个元素
	p->next=s->next;//i-1的next变成i+1
	delete s;//删除掉第i个元素
	
	return OK;
}
