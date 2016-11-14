//NOIP2011
//我是真的不知道这是不是D2T1
//计算系数 
//Time Limit : 1000 MS
//Memory Limit : 128000 KB
//Enrong
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int a,b,k,n,m;
long long  f[1000+100][1000+100];
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	f[1][0]=b;
  	f[1][1]=a;
	for (int i=2;i<=k;i++)
		for (int j=0;j<=k;j++)
			f[i][j]=(f[i-1][j]*b+f[i-1][j-1]*a) % 10007;
	printf ("%lld\n",f[k][n]);
}
