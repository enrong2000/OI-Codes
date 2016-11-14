//OPENJUDGE 7627
//Time Limit in Total : 1000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int n,m,i,j,k,f[110][110];
int main()
{
	while (scanf("%d %d",&n,&m)!=EOF)
	{
		for (i=1;i<=n;i++)	for (j=1;j<=m;j++)	f[i][j]=i;
		for (i=1;i<=n;i++)	for (j=1;j<=i;j++)	for (k=2;k<=m;k++)	f[i][k]=min(f[i][k],max(f[j-1][k-1],f[i-j][k])+1);
		printf ("%d\n",f[n][m]);
	}
}
/*
f[j][i]表示有j个硬度范围值，i个鸡蛋时，在最坏情况下要扔的最少鸡蛋次数
边界条件:f[j][1]=j f[0][i]=0
状态转移方程：f[j][i]=min(k=1 to j,max(f[k-1][i-1],f[j-k][i])+1)
解释：f[k-1][i-1]表示鸡蛋破，f[j-k][i]表示鸡蛋木有破
*/
