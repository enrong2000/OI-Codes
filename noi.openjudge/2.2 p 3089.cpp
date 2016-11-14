//OPENJUDGE 3089
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
int n,o,i,p,a[35]={0,1,2};
int main()
{
	for (i=3;i<=30;i++)
		a[i]=a[i-1]+a[i-2];
	while (scanf ("%d",&n)==1)
	{
		printf ("%d\n",a[n]);
	}
	return 0;
}
