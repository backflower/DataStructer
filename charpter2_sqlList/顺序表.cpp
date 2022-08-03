# include <stdio.h>
# define SUCCESS 100
# define ERRO  -10
# define OK 1
# define OverFlow -100
# define Maxsize 1000

//˳��������������(��·)
typedef int Status;
typedef  struct 
{
	int ID;
}Element;
typedef struct 
{
	Element * e;//һά����ָ��
	int length ;//����
}SqlList;

/*
	1.��ʼ��
	2.ȡֵ
	3.����
	4.����
	5.ɾ��
*/

Status  InitSqlList(SqlList &L);
Status  GetElement(SqlList &L,int i,Element &e);
Status  Commpet(Element a,Element b);


int main ()
{
	SqlList s;
	Status sta=InitSqlList(s);
	if(sta!=OK)
		printf("��ʼ��ʧ��!\n");
	else 
		printf("��ʼ���ɹ�!\n");
	printf("%d\n",s.e[0].ID);
	return 0;
}
Status  InitSqlList(SqlList &L)//1����ʼ��
{
	//�������ǽ�˳��������ָ���ʼ��,�ҽ���������Ϊ0.��ɳ�ʼ��
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
Status  GetElement(SqlList &L,int i,Element &e)//2.ȡֵ
{
	if((i>L.length)||(i<1)) return OverFlow;
	e=L.e[i-1];
	return OK;
}

