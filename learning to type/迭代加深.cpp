#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int INF=~0U>>1;
const int N=10;
int dep,flag;
int ans[N],d[N];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void dfs(int a,int b,int k)
{
	if (k==dep+1)
		return;
	if (b%a==0 && b/a > d[k-1])
	{
		d[k]=b/a;
		if (!flag||d[k]<ans[k])
			memcpy(ans,d,sizeof(d));
		flag=1;
		return;
	}
	int s=b/a;
	if (s<=d[k-1])
		s=d[k-1]+1;
		int t=(dep-k+1)*b/a;
	if (t>INF /b)
		t=INF/b;
	if (flag && t >= ans[dep])
		t=ans[dep]-1;
	for (int i=s;i<t;i++)
	{
		d[k]=i;
		int m=gcd(i*a-b,b*i);
		dfs(i*a-b/m,b*i/m,k+1);
	}
}
void Work(int a,int b)
{
	d[0]=1;
	flag=0;
	for (dep=1;dep<=N;dep++)
	{
		dfs(a,b,1);
		if (flag)
		{
			printf ("1/%d",ans[1]);
			for (int i=2;i<=dep;i++)
				printf ("+1/%d",ans[i]);
			printf ("\n");
			break;
		}
	}
}
int main()
{
	int a,b;
	while (printf ("%d %d",&a,&b)==2)
	{
		printf ("%d/%d=",a,b);
		Work(a,b);
	}
	return 0;
}
