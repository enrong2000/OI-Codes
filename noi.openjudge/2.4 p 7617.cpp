//OPENJUDGE 7617
//Time Limit of All : 10000 MS
//Time Limit of Each : 1000 MS
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
int a[100005],n,o,i,p,m;
void quicksort (int left,int right)
{
	if (left>right)	return;
	int ii=left,jj=right,tt,temp=a[left];
	while (ii!=jj)
	{
		while (a[jj]<=temp&&ii<jj)	jj--;
		while (a[ii]>=temp&&ii<jj)	ii++;
		if (ii<jj)
		{
			tt=a[ii],a[ii]=a[jj],a[jj]=tt;
		}
	}
	a[left]=a[ii],a[ii]=temp;
	quicksort(left,ii-1);quicksort(ii+1,right);
}
int main()
{
	scanf ("%d",&n);
	for (i=1;i<=n;i++)	scanf ("%d",&a[i]);
	quicksort (1,n);
	scanf ("%d",&m);
	for (i=1;i<=m;i++)	printf ("%d\n",a[i]);
	return 0;
}
