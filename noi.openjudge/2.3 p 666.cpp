//OPENJUDGE 666
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
int cas,m,n,o,i,p;
int fun(int x,int y)
{
	if (x==0||y==1)
		return 1;
	if (y>x)
		return fun(x,x);
	else
		return fun(x,y-1)+fun(x-y,y);
}
int main()
{
	scanf ("%d",&cas);
	for (i=1;i<=cas;i++)
	{
		scanf ("%d%d",&m,&n);
		printf ("%d\n",fun(m,n));
	}
	return 0;
}
