//OPENJUDGE 4982
//Time Limit in Total : 1000 MS
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
#include <iostream>
using namespace std;
int i,n,f[2000];
int main()
{
	scanf("%d",&n);
	f[1]=3;f[2]=7;
	for(i=3;i<=n;i++)
		f[i]=2*f[i-1]+f[i-2];
	printf("%d",f[n]);
	return 0;
}
