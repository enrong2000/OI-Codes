//OPENJUDGE 1805
//Time Limit in Total : 1000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
#define N 10
char s[8],t[8];
int used[N],res[N],n,ma,mad,ans[8],flag,len;
void update(int d)
{
	int i,j,num,temp,a[8];
	num = temp = 0;
	for(i=0,j=0;i<len;i++)
	{
		temp = temp*10+t[i]-'0';//temp��ȡ��ÿ�����������
		if(j<d && i+1 == res[j])
		{
			num += temp;//num�Ǵ��ֲ�ֵļӺ�
			if(num > n)
				return ;
			a[j] = temp;
			temp = 0;
			j++;
		}
	}
	a[d] = temp;
	num += temp;
	if(num<=n && num > ma)
	{
		ma = num;
		mad = d;
		flag = 0;
		for(i = 0;i<=d;i++)//��¼���
			ans[i] = a[i];
	}
	else if(num == ma)
		flag = 1;
}
void dfs(int n,int end,int d,int now)
{//�����Cn,d��end��������ĸ���
	int i;
	if(d == end)
	{
		update(d);
		return ;
	}
	for(i = now+1;i<=n;i++)
		if(!used[i])
		{
			res[d] = i;
			used[i] = 1;
			dfs(n,end,d+1,i);
			used[i] = 0;
		}
}
int main()
{
	while(scanf("%s %s",s,t) && strcmp(s,"0"))
	{
		int i,j;
		flag = ma = 0;
		if(!strcmp(s,t))
		{//����ֵ����
			printf("%s %s\n",s,t);
			continue;	
		}
		n = atoi(s);
		len = strlen(t);
		for(i = 0;i<len;i++)
		{//i��0��ʼ��������һ��wa������101 100�������ݵõ���������
			memset(used,0,sizeof(used));
			dfs(len-1,i,0,0);//����
		}
		if(ma == 0)//���ֵû�и��£�Ҳ�����޷����
			printf("error\n");
		else if(flag)//���ֵ����1��
			printf("rejected\n");
		else
		{
			printf("%d",ma);
			for(i = 0;i<=mad;i++)
				printf(" %d",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
