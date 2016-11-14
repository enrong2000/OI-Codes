//NOIP 2011 
//我也不知道这是不是DAY1T1
//CODEVS - 1134 铺地毯 
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
struct node
{
	int a,b,x,y;
}ca[10005];
int main()
{
	int n,i,x,y;
	scanf ("%d",&n);
	for (i=0;i<n;i++)	scanf ("%d %d %d %d",&ca[i].a,&ca[i].b,&ca[i].x,&ca[i].y);
	scanf ("%d %d",&x,&y);
	for (i=n-1;i>=0;i--)
	{
		if (ca[i].a<=x && (ca[i].a+ca[i].x)>=x && (ca[i].b+ca[i].y)>=y && ca[i].b<=y)
		{
			printf ("%d\n",i+1);
			goto out;
		}
	}
	printf ("-1\n");
out:	;
	return 0;
}
