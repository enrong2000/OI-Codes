//OPENJUDGE
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
int fib(int i)
{
	if (i==1||i==2)
		return 1;
	return fib(i-1)+fib(i-2);
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int m;
		scanf ("%d",&m);
		printf ("%d\n",fib(m));
	}
	return 0;
}
