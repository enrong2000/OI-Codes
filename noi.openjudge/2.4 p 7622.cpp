//OPENJUDGE 7622
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
#define MAX 1000001
int a[MAX],b[MAX],cnt,n,m;
void Merge(int a[],int sta,int mid,int en)
{
	int i=sta,j=mid+1,k=sta;
	while (i<=mid&&j<=en)
	{
		if (a[i]<=a[j])	b[k++]=a[i++];
		else			cnt+=j-k,b[k++]=a[j++];
	}
	while(i<=mid)			b[k++]=a[i++];
	while(j<=en)			b[k++]=a[j++];
	for (i=sta;i<=en;i++)	a[i]=b[i];
}
void MergeSort(int a[],int sta,int en)
{
	if (sta<en)
	{
		int mid=(sta+en)/2;
		MergeSort(a,sta,mid);MergeSort(a,mid+1,en);Merge(a,sta,mid,en);
	}
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
	m=in(),cnt=0;
	for (long long i=0;i<m;i++)	a[i]=in();
	MergeSort(a,0,m-1);
	printf ("%lld\n",cnt);
	return 0;
}
