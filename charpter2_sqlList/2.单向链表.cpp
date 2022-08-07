# include <stdio.h>
# define  ERROR -100
# define OK 1 
# define OverFlow -10
typedef int Status;
/*
	单链表的六大基础操作(套路):
	1.初始化
		Status initNode(LinkList & L);
	2.取元素值
		Status getElement(LinkList L,int i,Elemenet &e);
	3.查找固定的节点
		Node *  LocateElement(LinkList L,Element e)
	4.插入元素
		Status insertElement(LinkList &L,int i,Element e);
	5.删除元素
		Status DeleteElement(LinkList &L,int i);
	6.创建定长单链表
		Status CreateNode (LinkList  &L,int length);//原型
        Status CreateNodeByInfort (LinkList  &L,int length);//前插法
        Status CreateNodeByEnd (LinkList  &L,int length);//后插法
*/


typedef struct Element 
{	
	int ID;
} Element;

typedef struct LNode
{	
	Element e;//数据域
	LNode * next;//指针域指向下一个元素
} LNode,* LinkList ;//LinkList 为指向Node类型节点的指针

Status initNode(LinkList &L);

Status getElement(LinkList L,int i,Element &e);

LNode *  LocateElement(LinkList L,Element e);

Status  Commpet(Element a,Element b);

Status CreateNodeByInfort (LinkList  &L,int length);//前插法创建链表

Status CreateNodeByEnd (LinkList  &L,int length);//后插法创建链表

void ShowLinkedList (LinkList &L,int length);

int main ()
{
	LinkList L;
	Status sta =initNode(L);
	if(sta==OK)
		printf("单链表初始化成功!\n");
    // sta = CreateNodeByInfort(L,10);
    // if(sta == OK )
    //     ShowLinkedList(L,10);
	sta = CreateNodeByEnd(L,10);
    if(sta == OK )
        ShowLinkedList(L,10);
	return 0;
}

Status initNode(LinkList &L)//头节点初始化,无中生有
{

	//构建一个空的单链表L
	L=new LNode;//使用新生成的节点作为头节点,头指针指向新生成的节点.
	L->next=NULL;//头节点指针域指向为空
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
	if((!p)||(count>i)){//防止i小于0或者i>o 在[1,i]之间出现空节点的情况
		printf("未能定位到该元素,失败! \n");
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
	return p;//没有找到就会返回NULL,找到就会返回要的Node.
}

Status  Commpet(Element a,Element b)
{
	if(a.ID==b.ID) return OK;
	return ERROR;
}

Status insertElement(LinkList &L,int i,Element e)
{ 
	LNode *p=L;//注意此处为L 头节点 不是首元节点,详细见后面p=L与p=L->next的区分
	int count =0;//注意此处的count 参数为0
		
	//取得i-1个  结点位置的值
	while(p&&(count<(i-1)))
	{
		p=p->next;
		count++;
	}
	if((!p)||(count>(i-1))) return ERROR;//超过了i-1的长度或者i-1小于0
	LNode *s=new LNode;//要插入的结点s
	s->e=e;
	s->next=p->next;
	p->next=s;
	return OK;
}


Status DeleteElement(LinkList &L,int i)
{
	LNode *p=L;//注意此处为L 头节点 不是首元节点,详细见后面p=L与p=L->next的区分
	int count =0;//注意此处的count 参数为0
	
	while((p->next)&&(count<(i-1)))//查找到第i个结点
	{
		p=p->next;
		count++;
	}
	
	if((!p->next)||(count>(i-1))) return ERROR;
	
	LNode * s= p->next;
	p->next=s->next;
	delete s;//释放第i个结点的内存
	
	return OK;
}

Status CreateNodeByInfort (LinkList  &L,int length)//前插法
{
    LNode * p =L; 
    for(int i=0;i<length;i++)
    {
        Element e = * new  Element;
        e.ID=i;
        LNode * s = new LNode;//新插入的元素为s
 
        s->e=e;
        s->next=p->next;
        p->next=s;
    }
	printf("前插法创建!\n");
    return OK;
}

Status CreateNodeByEnd (LinkList  &L,int length)//后插法
{
	
	LNode * N=L;	
	Element e = * new  Element;	
	for(int i=0;i<length;i++)
	{
		e.ID=(i+1);
		LNode * s= new LNode;
		s->e=e;

		s->next=NULL;
		N->next=s;
		N=s;

	}
	printf("后插法创建!\n");
	return  OK;
}

void ShowLinkedList (LinkList &L,int length)
{
    LNode *p=L;
    for(int i= 0 ;i<length;i++)
    {
        p=p->next;
        printf("第%d个元素ID:%d \n",i+1,p->e.ID);
    }
}
