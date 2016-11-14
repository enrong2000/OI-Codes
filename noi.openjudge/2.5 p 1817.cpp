//OPENJUDGE 1817
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
int a[55][55],book[55][55];
int recur(int m,int n,int x,int y)
{
	if (book[x][y]==1)	return 0;
	book[x][y]=1;
	int p=a[x][y],sum=1;
	if (p==0)
	{
		if (y-1>0)	sum=sum+recur(m,n,x,y-1);
		if (y+1<=n)	sum=sum+recur(m,n,x,y+1);
		if (x+1<=m)	sum=sum+recur(m,n,x+1,y);
		if (x-1>0)	sum=sum+recur(m,n,x-1,y);
		return sum;
	}
	if (p>=8)	p=p-8;
	else if (x+1<=m)	sum=sum+recur(m,n,x+1,y);
	if (p>=4)	p=p-4;
	else if (y+1<=n)	sum=sum+recur(m,n,x,y+1);
	if (p>=2)	p=p-2;
	else if (x-1>0)		sum=sum+recur(m,n,x-1,y);
	if (p>=1)	p=p-1;
	else if (y-1>0)		sum=sum+recur(m,n,x,y-1);
	return sum;
}
int main()
{
	memset(book,1,sizeof(book));
	int m=0,n=0;
	scanf ("%d %d",&m,&n);
	int i,o;
	for (i=1;i<=m;i++)
		for (o=1;o<=n;o++)
			scanf ("%d",&a[i][o]);
	int sum=0,ma=0,x=0;
	for (i=1;i<=m;i++)
		for (o=1;o<=n;o++)
		{
			x=recur(m,n,i,o);
			if (x>0)	sum++;
			ma=max(ma,x);
		}
	printf ("%d\n%d\n",sum,ma);
	return 0;
}
