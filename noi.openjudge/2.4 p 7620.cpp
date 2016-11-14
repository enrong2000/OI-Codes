//OPENJUDGE 7620
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
struct node
{
	int sta,en;
}se[100005];
void quicksort (int left,int right)
{
	if (left>right)	return;
	int ii=left,jj=right,tt,temp=se[left].sta;
	while (ii!=jj)
	{
		while(se[jj].sta>=temp&&ii<jj)	jj--;
		while(se[ii].sta<=temp&&ii<jj)	ii++;
		if(ii<jj)
		{
			tt=se[ii].sta,se[ii].sta=se[jj].sta,se[jj].sta=tt;
			tt=se[ii].en,se[ii].en=se[jj].en;se[jj].en=tt;
		}
	}
	se[left].sta=se[ii].sta,se[ii].sta=temp;
	tt=se[left].en,se[left].en=se[ii].en,se[ii].en=tt;
	quicksort(left,ii-1);quicksort(ii+1,right);
}
int n,o,i,p,head,tail,mi=INF,ma;
int main()
{
	scanf ("%d",&n);
	for (o=1;o<=n;o++)
	{
		scanf ("%d %d",&se[o].sta,&se[o].en);mi=min(mi,se[o].sta),ma=max(ma,se[o].en);
	}
	quicksort(1,n);
	head=se[1].sta;
	for (o=1;o<=n-1;o++)
	{
		if (se[o].en>=se[o+1].sta&&se[o+1].en>tail)	tail=se[o+1].en;
		if (se[o].en>=se[o+1].sta&&se[o+1].en<=tail)continue;
		else
		{
			printf ("no\n");goto out;
		}
	}
	if (head==mi&&tail==ma)	printf("%d %d\n",head,tail);
out:	;
	return 0;
}
