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
int main()
{
	int i,n,f[105];
	f[0]=0;
	f[1]=1;
	f[2]=2;
	f[3]=4;
	for(i=4;i<=100;i++)
		f[i]=f[i-1]+f[i-2]+f[i-3];
	scanf("%d",&n);
	while(n!=0)
	{
	printf("%d\n",f[n]);
	scanf("%d",&n);
	}
return 0;
}
