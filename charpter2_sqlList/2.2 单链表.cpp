# include <stdio.h>
# define  ERROR -100
# define OK 1 
# define OverFlow -10
typedef int Status;
/*
	������������������(��·):
	1.��ʼ��
		Status initNode(LinkList & L);
	2.ȡԪ��ֵ
		Status getElement(LinkList L,int i,Elemenet &e);
	3.���ҹ̶��Ľڵ�
		Node *  LocateElement(LinkList L,Element e)
	4.����Ԫ��
		Status insertElement(LinkList &L,int i,Element e);
	5.ɾ��Ԫ��
		Status DeleteElement(LinkList &L,int i);
	6.��������������
		Status CreateNode (LinkList  &L,int length);
*/


typedef struct Element 
{	
	int ID;
} Element;

typedef struct LNode
{	
	Element e;//������
	LNode * next;//ָ����ָ����һ��Ԫ��
} LNode,* LinkList ;//LinkList Ϊָ��Node���ͽڵ��ָ��

Status initNode(LinkList &L);

Status getElement(LinkList L,int i,Element &e);

LNode *  LocateElement(LinkList L,Element e);

Status  Commpet(Element a,Element b);

int main ()
{
	LinkList L;
	Status sta =initNode(L);
	if(sta==OK)
		printf("�������ʼ���ɹ�!\n");	
	return 0;
}

Status initNode(LinkList &L)//ͷ�ڵ��ʼ��,��������
{

	//����һ���յĵ�����L
	L=new LNode;//ʹ�������ɵĽڵ���Ϊͷ�ڵ�,ͷָ��ָ�������ɵĽڵ�.
	L->next=NULL;//ͷ�ڵ�ָ����ָ��Ϊ��
	return OK;
}

Status getElement(LinkList L , int i,Element &e)
{
	LNode *p=L->next;
	int count =1;
	while(p&&(count<i))
	{
		p=p->next;
		count++;
	}
	if((!p)||(count>i)){//��ֹiС��0����i>o ��[1,i]֮����ֿսڵ�����
		printf("δ�ܶ�λ����Ԫ��,ʧ��! \n");
		return ERROR;
	}
	e=p->e;
	return OK;
}


LNode *  LocateElement(LinkList L,Element e)
{
	LNode *p;
	p=L->next;

	while(p&&(Commpet(p->e,e)==ERROR))
	{
		p=p->next;
	}
	return p;//û���ҵ��ͻ᷵��NULL,�ҵ��ͻ᷵��Ҫ��Node.
}

Status  Commpet(Element a,Element b)
{
	if(a.ID==b.ID) return OK;
	return ERROR;
}

Status insertElement(LinkList &L,int i,Element e)
{ 
	LNode *p=L;//ע��˴�ΪL ͷ�ڵ� ������Ԫ�ڵ�,��ϸ������p=L��p=L->next������
	int count =0;//ע��˴���count ����Ϊ0
		
	//ȡ��i-1��  ���λ�õ�ֵ
	while(p&&(count<(i-1)))
	{
		p=p->next;
		count++;
	}
	if((!p)||(count>(i-1))) return ERROR;//������i-1�ĳ��Ȼ���i-1С��0
	LNode *s=new LNode;//Ҫ����Ľ��s
	s->e=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status DeleteElement(LinkList &L,int i)
{
	LNode *p=L;//ע��˴�ΪL ͷ�ڵ� ������Ԫ�ڵ�,��ϸ������p=L��p=L->next������
	int count =0;//ע��˴���count ����Ϊ0
	
	while((p->next)&&(count<(i-1)))//���ҵ���i�����
	{
		p=p->next;
		count++;
	}
	
	if((!p->next)||(count>(i-1))) return ERROR;
	
	LNode * s= p->next;
	p->next=s->next;
	delete s;//�ͷŵ�i�������ڴ�
	
	return OK;
}
