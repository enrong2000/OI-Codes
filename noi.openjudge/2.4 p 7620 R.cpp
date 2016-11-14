//OPENJUDGE 7620 Rewrite
//Time Limit of All: 1000 MS
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
#define INF 0x3f3f3f3f
using namespace std;
int a[10005],n,o,i,p,sta,en,ma,mi=INF;
inline int in()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9')	ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
	n=in();
	for (i=1;i<=n;i++)
	{
		scanf ("%d%d",&sta,&en);
		ma=max(ma,en),mi=min(mi,sta);
		for (o=sta;o<=en;o++)
			a[o]=1;
	}
	for (o=mi;o<=ma;o++)
		if (a[o]==0)
		{
			printf ("no\n");
			goto out;
		}
		else
			continue;
	printf ("%d %d\n",mi,ma);
out:	;
	return 0;
}
