//��ͨ���鼯 
#define MAX_SIZE 100005
int pa[MAX_SIZE];//�洢����ͼ�ı� 
void init ()//��ʼ��   �ú������Ը����������ͳ�ʼ����Ҫ������
{
	for (int i=0;i<MAX_SIZE;i++)
	{
		pa[i]=i;
	}
}
int findset (int a)//����·��ѹ��
{
	while (pa[a]!=a)
	{
		a=pa[a];
	}
	return a;
}
void union_nodes(int a,int b)//���Ϻϲ�
{
	int a1=findset(a);
	int b1=findset(b);
	if (a1!=b1)//����ж�������ѡ����Ҫ��Ϊ�˷�ֹfindset·��ѹ����ʱ�������ѭ��
	{
		pa[a1]=b1;//������������ͼ����������ʱ������Ԫ�ص�˳�����Ҫ�����ܺ��ԣ���ô����Ӧ����pa[a]=b; 
	}
} 

