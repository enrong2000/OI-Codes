//OPENJUDGE 7099
//Time Limit : 1000 MS
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
#define int long long
int a[200005],n,o=0,i,p,tim;
void quicksort(int left,int right)
{
	if (left>right)	return;
	int ii=left,jj=right,tt,temp=a[left];
	while (ii!=jj)
	{
		while (a[jj]>=temp&&ii<jj)	jj--;
		while (a[ii]<=temp&&ii<jj)	ii++;
		if (ii<jj)	tt=a[ii],a[ii]=a[jj],a[jj]=tt;
	}
	a[left]=a[ii],a[ii]=temp;
	quicksort(left,ii-1);quicksort(ii+1,right);
}
inline int in()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9')	ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
#undef int
int main()
{
	n=in();
	for (i=0;i<n;i++)	a[i]=in();
	quicksort(0,n-1);
	for (i=0;i<n;i++)
	{
		if (a[i]!=a[i-1])	tim=1;
		if (a[i]==a[i-1])	tim++;
		if (a[i]!=a[i+1])	printf ("%lld %lld\n",a[i],tim);
		
	}
	return 0;
}

