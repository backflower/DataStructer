# include <stdio.h>
# define SUCCESS 100
# define ERRO  -10
# define OK 1
# define OverFlow -100
# define Maxsize 1000



/*
˳��������������(��·)
	1.��ʼ��
	2.ȡֵ
	3.����
	4.����
	5.ɾ��
*/

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

Status  InitSqlList(SqlList &L);//	1.��ʼ��
Status  GetElement(SqlList L,int i,Element &e);//2.ȡֵ
Status  Commpet(Element a,Element b);
int LocateElement(SqlList L,Element e);//3.����
Status InsertElement(SqlList &L ,int i,Element e);//	4.����
Status DeleteElement(SqlList &L,int i);//	5.ɾ��
void ShowAll(SqlList L);

int main ()
{
	SqlList s;
	Status sta=InitSqlList(s);//1.��ʼ��
	
	if(sta!=OK)
		printf("��ʼ��ʧ��!\n");
	else 
		printf("��ʼ���ɹ�!\n");
	
	for(int i=0;i<10;i++)
	{
		Element e={};
		e.ID=i;
		sta =InsertElement(s,i+1,e);
		if(sta==OK)
			printf("��%d������ɹ�!\n",i+1);
		else
			printf("��%d������ʧ��!\n",i+1);
	}
	ShowAll(s);
	
	Element get_e={};
	
	sta=GetElement(s,9,get_e);//2.ȡֵ
	if(sta==OK) 
			printf("ȡֵ�ɹ�! ID: %d \n",get_e.ID);
	else 
		printf("ȡֵʧ��!\n");
	
	int get_index = LocateElement(s,get_e);//3.����	
	printf("��λ����:%d \n",get_index);
	
	sta = InsertElement(s,get_index,get_e); //4.����
	if(sta==OK) 
			printf("����ɹ�!\n");
	else 
			printf("����ʧ��!\n");
	ShowAll(s);
	
	sta= DeleteElement(s,get_index);//5.ɾ��	
	if(sta==OK) 
			printf("ɾ���ɹ�!\n");
	else 
			printf("ɾ��ʧ��!\n");
	ShowAll(s);
	
		return 0;
}

Status  InitSqlList(SqlList &L)//1����ʼ��
{
	//�������ǽ�˳��������ָ���ʼ�������޶�ΪMax,�ҽ���������Ϊ0.��ɳ�ʼ��
	L.e=new Element[Maxsize];
	if(!L.e) return ERRO;
	L.length=0;
	return OK;
}

Status  GetElement(SqlList L,int i,Element &e)//2.ȡֵ
{
	if((i>L.length)||(i<1)) return OverFlow;
	e=L.e[i-1];
	return OK;
}

int LocateElement(SqlList L,Element e) //3.����
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

Status InsertElement(SqlList &L ,int i,Element e)//4.��������
{
	if((i<1)||(i>L.length+1)) return OverFlow;
	if(L.length>=Maxsize) return OverFlow;//���洢�ռ��Ƿ�����
	for(int j=L.length-1;j>=(i-1);j--)
	{
		L.e[j+1]=L.e[j];
	}
	L.e[i-1]=e;
	L.length++;//ͨ��֮ǰ�ļ��������ֹ�ڴ����
	return OK;
}

Status DeleteElement(SqlList &L,int i) //5.ɾ������
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
