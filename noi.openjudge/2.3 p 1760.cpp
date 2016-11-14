//OPENJUDGE 1760
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
#define MOD 1000
using namespace std;
int a[1000005]={0,1,1},n,o,i,p;
int main()
{
	for (i=3;i<=1000000;i++)
		a[i]=(a[i-1]+a[i-2])%MOD;
	scanf ("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf ("%d",&o);
		printf ("%d\n",a[o]);
	}
	return 0;
}
