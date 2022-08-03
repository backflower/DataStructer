# include <stdio.h>
# define SUCCESS 100
# define ERRO  -10
# define OK 1
# define OverFlow -100
# define Maxsize 1000

//顺序表的五大基本操作(套路)
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

/*
	1.初始化
	2.取值
	3.查找
	4.插入
	5.删除
*/

Status  InitSqlList(SqlList &L);
Status  GetElement(SqlList &L,int i,Element &e);
Status  Commpet(Element a,Element b);


int main ()
{
	SqlList s;
	Status sta=InitSqlList(s);
	if(sta!=OK)
		printf("初始化失败!\n");
	else 
		printf("初始化成功!\n");
	printf("%d\n",s.e[0].ID);
	return 0;
}
Status  InitSqlList(SqlList &L)//1，初始化
{
	//本质上是将顺序表的数组指针初始化,且将长度设置为0.完成初始化
	L.e=new Element;
	if(!L.e) return ERRO;
	L.length=0;
	return OK;
}

Status  Commpet(Element a,Element b)
{
	if(a.ID==b.ID) return OK;
	return ERRO;
}
Status  GetElement(SqlList &L,int i,Element &e)//2.取值
{
	if((i>L.length)||(i<1)) return OverFlow;
	e=L.e[i-1];
	return OK;
}

