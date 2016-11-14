#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
//1 d  Ê÷×´Êý×é 
#define size 100111
int c[size],n;
int lowbit(int k)
{
	return (k&-k);
}
void update(int pos,int num)
{
	while (pos<=size)
	{
		c[pos]=c[pos]+num;
		pos=pos+lowbit(pos);
	}
}
int sum(int pos)
{
	int s=0;
	while (pos>0)
	{
		s=s+c[pos];
		pos=pos-lowbit(pos);
	}
	return s;
}
int main()
{
	int i,j,s;
	while (scanf ("%d",&n)!=EOF)
	{
		memset (c,0,sizeof(c));
		for (i=1; i<=n; i++)
		{
			scanf ("%d",&s);
			update(s,1);
		}
		for (i=1; i<=n; i++)
			printf ("%d ",c[i]);
		printf ("\n");
	}
	return 0;
}
