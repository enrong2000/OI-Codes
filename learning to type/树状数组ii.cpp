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
#define N 111000
using namespace std;
int c[111][111];
int lowbit (int x)
{
	return x&(-x);
}
void modify(int x,int y,int delta)
{
	int i, j;
	for (i = x; i <=N; i=i+lowbit(i))
	{
		for (j = y; j <=N; j=j+lowbit(j))
		{
			c[i][j]=c[i][j]+delta;
		}
	}
}
int sum(int x,int y)
{
	int res=0,i,j;
	for (i=x; i>0; i=i-lowbit(i))
	{
		for (j=y; j>0; j=j-lowbit(j))
		{
			res=res+c[i][j];
		}
	}
	return res;
}
int main()
{
	return 0;
}
