# include <stdio.h>
# define SUCCESS 100
# define ERRO  -10
# define OK 1
# define OverFlow -100
# define Maxsize 1000



/*
顺序表的五大基本操作(套路)
	1.初始化
	2.取值
	3.查找
	4.插入
	5.删除
*/

typedef int Status;
typedef  struct 
{
	int ID;
}Element;

typedef struct 
{
	Element * e;//一维数组指针
	int length ;//长度
}SqlList;

Status  InitSqlList(SqlList &L);//	1.初始化
Status  GetElement(SqlList L,int i,Element &e);//2.取值
Status  Commpet(Element a,Element b);
int LocateElement(SqlList L,Element e);//3.查找
Status InsertElement(SqlList &L ,int i,Element e);//	4.插入
Status DeleteElement(SqlList &L,int i);//	5.删除
void ShowAll(SqlList L);

int main ()
{
	SqlList s;
	Status sta=InitSqlList(s);//1.初始化
	
	if(sta!=OK)
		printf("初始化失败!\n");
	else 
		printf("初始化成功!\n");
	
	for(int i=0;i<10;i++)
	{
		Element e={};
		e.ID=i;
		sta =InsertElement(s,i+1,e);
		if(sta==OK)
			printf("第%d个插入成功!\n",i+1);
		else
			printf("第%d个插入失败!\n",i+1);
	}
	ShowAll(s);
	
	Element get_e={};
	
	sta=GetElement(s,9,get_e);//2.取值
	if(sta==OK) 
			printf("取值成功! ID: %d \n",get_e.ID);
	else 
		printf("取值失败!\n");
	
	int get_index = LocateElement(s,get_e);//3.查找	
	printf("定位索引:%d \n",get_index);
	
	sta = InsertElement(s,get_index,get_e); //4.插入
	if(sta==OK) 
			printf("插入成功!\n");
	else 
			printf("插入失败!\n");
	ShowAll(s);
	
	sta= DeleteElement(s,get_index);//5.删除	
	if(sta==OK) 
			printf("删除成功!\n");
	else 
			printf("删除失败!\n");
	ShowAll(s);
	
		return 0;
}

Status  InitSqlList(SqlList &L)//1，初始化
{
	//本质上是将顺序表的数组指针初始化长度限定为Max,且将长度设置为0.完成初始化
	L.e=new Element[Maxsize];
	if(!L.e) return ERRO;
	L.length=0;
	return OK;
}

Status  GetElement(SqlList L,int i,Element &e)//2.取值
{
	if((i>L.length)||(i<1)) return OverFlow;
	e=L.e[i-1];
	return OK;
}

int LocateElement(SqlList L,Element e) //3.查找
{
	for(int i=0;i<L.length;i++)
	{
		if(Commpet(e,L.e[i])==OK) 
			return i+1;		
	}
	return 0;
}

Status  Commpet(Element a,Element b)
{
	if(a.ID==b.ID) return OK;
	return ERRO;
}

Status InsertElement(SqlList &L ,int i,Element e)//4.插入数据
{
	if((i<1)||(i>L.length+1)) return OverFlow;
	if(L.length>=Maxsize) return OverFlow;//检查存储空间是否已满
	for(int j=L.length-1;j>=(i-1);j--)
	{
		L.e[j+1]=L.e[j];
	}
	L.e[i-1]=e;
	L.length++;//通过之前的检测已满防止内存溢出
	return OK;
}

Status DeleteElement(SqlList &L,int i) //5.删除数据
{
	if((i<1)||(i>L.length)) return OverFlow;
	for(int j=i;j<=L.length-1;j++)
	{
		L.e[j-1]=L.e[j];
	}
	L.length--;
	return OK;
}

void ShowAll(SqlList L)
{
	for(int i=0;i<L.length;i++)
	{
		printf("ID: %d\t",L.e[i].ID);
	}
	putchar('\n');
}
