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
	Element *element;//������
	Node * next;//ָ������һ��ָ��
} Node , *LinkList;

STATUS initNode(LinkList &L);//��ʼ������

STATUS GetLinkList(LinkList L,int j ,Element & e);//��ȡָ��������ֵ

Node * LocateLinkList(LinkList L,Element e);//��λ����Ԫ��e�Ľڵ�Node 

bool CompareElement(Element e1,Element e2);//�Ƚ�����Ԫ�����

STATUS InsertElement (Element e,LinkList &L,int i);//�ڵ�j��λ�ò���Ԫ��e

void showElement(LinkList L);//��ӡ��������нڵ�

STATUS CreateLinkList_fromt(LinkList &L,int n);//ǰ�巨��������

STATUS CreateLinkList_last(LinkList &L,int n);//��巨��������

STATUS DeleteElement(LinkList &L,int i);//ɾ��ָ��λ�õ�Ԫ��
	

int main ()
{
	LinkList L;
	STATUS status=initNode(L);
	if(status==OK) {
		printf("��ʼ���ɹ�!\nԪ��->ID:%d \t Ԫ��->ID:%s",L->element->ID,L->element->name);
	}
	return 0;
}


STATUS initNode (LinkList &L)//��ʼ����������
{
	L = new  Node;
//	L->element=new Element;
//	L->element->ID=0;
//	memset(L->element->name,'\0',50);
	L->next=NULL;
	return OK;
}


STATUS GetLinkList(LinkList L,int j ,Element &e)//��ȡָ��������ֵ
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

Node * LocateLinkList(LinkList L,Element e)//��λ����Ԫ��e�Ľڵ�Node 
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

STATUS InsertElement (Element e,LinkList &L,int i)//�ڵ�j��λ�ò���Ԫ��e
{
	//1.�ҵ���i-1��Ԫ��
	//2.�½�һ��Ԫ��S
	//S��ֵ������ΪԪ��e
	//3.��Sָ����ָ��i��Ԫ��
	//4.����i-1��ָ����ָ��S
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


STATUS CreateLinkList_fromt(LinkList &L,int n)//ǰ�巨
{
	L->next=NULL;
	Node *p ;
	p=L;
	for(int i=0;i<n;i++)
	{
		Node *s=new Node;
		s->element=new Element ;
		s->element->ID=(i+1);
		cout<<"�����"<<(i+1)<<"��Ԫ�ص�ֵ:";
		cin>>s->element->name;
		s->next=p->next;
		p->next=s;				
	}
	return OK;
}

STATUS CreateLinkList_last(LinkList &L,int n)//��巨
{
	L->next=NULL;
	Node *p;
	p=L;
	for(int j=0;j<n;j++)
	{
		Node *s =new Node;
		s->element=new Element;
		s->element->ID=(j+1);
		cout<<"�����"<<(j+1)<<"��Ԫ�� Name :";
		cin>>s->element->name;
		s->next=NULL;
		p->next=s;
		p=s;
	}
	return OK;
}

STATUS   DeleteElement(LinkList &L,int i)//ɾ��ָ��λ�õ�Ԫ��
{

	Node * p;
	p=L;
	int j=0;
	while((p->next)&&(j<i-1))//��λ����i-1��Ԫ��
	{
		p=p->next;
		j++;	
	}
	if((!p->next)||(j>(i-1))) return ERRO;
	
 	Node *s =new Node;
	s=p->next;//��λ��i��Ԫ��
	p->next=s->next;//i-1��next���i+1
	delete s;//ɾ������i��Ԫ��
	
	return OK;
}
