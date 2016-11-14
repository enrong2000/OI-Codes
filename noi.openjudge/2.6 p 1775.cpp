//OPENJUDGE 1775
//Time Limit in Total: 1000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int w[101],v[101],dp[1001],m,t,i,j,n=-1;
inline int in()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9')	ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
	t=in(),m=in();
	for (i=0;i<m;i++)	w[i]=in(),v[i]=in();
	for (i=0;i<m;i++)	for (j=t;j>=w[i];j--)	
	{
		dp[j]=max(dp[j],dp[j-w[i]]+v[i]);	if (dp[j]>n)	n=dp[j];
	}
	printf ("%d\n",n);
	return 0;
}
