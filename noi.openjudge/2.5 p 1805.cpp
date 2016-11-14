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
		temp = temp*10+t[i]-'0';//temp提取出每个拆出来的数
		if(j<d && i+1 == res[j])
		{
			num += temp;//num是此种拆分的加和
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
		for(i = 0;i<=d;i++)//记录结果
			ans[i] = a[i];
	}
	else if(num == ma)
		flag = 1;
}
void dfs(int n,int end,int d,int now)
{//求组合Cn,d，end是组合数的个数
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
		{//不拆分的情况
			printf("%s %s\n",s,t);
			continue;	
		}
		n = atoi(s);
		len = strlen(t);
		for(i = 0;i<len;i++)
		{//i从0开始，贡献了一次wa。（由101 100这组数据得到的启发）
			memset(used,0,sizeof(used));
			dfs(len-1,i,0,0);//暴搜
		}
		if(ma == 0)//最大值没有更新，也就是无法拆分
			printf("error\n");
		else if(flag)//最大值多于1个
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
