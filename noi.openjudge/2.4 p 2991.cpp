//OPENJUDGE 2991
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
int n=500,o,i,p;
int cas,a[505]={0,2011},length,x;
char c[205];
int main()
{
	for (i=2;i<=n;i++)
	{
		a[i]=(a[i-1]*2011)%10000;
	}
	scanf ("%d",&cas);
	for (i=1;i<=cas;i++)
	{
		memset (c,0,sizeof(c));
		x=0;
		scanf ("%s",c);
		length=strlen(c);
		if (length>=3)
		{
			for (o=length-3;o<=length-1;o++)
				x=x*10+c[o]-'0';
		}
		else
			x=(int)atof(c);
		if (x<=500)
			printf ("%d\n",a[x]);
		else
			printf ("%d\n",a[x-500]);
	}
	return 0;
}
