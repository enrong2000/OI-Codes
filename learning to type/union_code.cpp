//普通并查集 
#define MAX_SIZE 100005
int pa[MAX_SIZE];//存储有向图的边 
void init ()//初始化   该函数可以根据情况保存和初始化需要的内容
{
	for (int i=0;i<MAX_SIZE;i++)
	{
		pa[i]=i;
	}
}
int findset (int a)//不带路径压缩
{
	while (pa[a]!=a)
	{
		a=pa[a];
	}
	return a;
}
void union_nodes(int a,int b)//集合合并
{
	int a1=findset(a);
	int b1=findset(b);
	if (a1!=b1)//这个判定条件可选，主要是为了防止findset路径压缩的时候出现死循环
	{
		pa[a1]=b1;//如果存的是有向图，并且做题时集合中元素的顺序很重要，不能忽略，那么这里应该用pa[a]=b; 
	}
} 

