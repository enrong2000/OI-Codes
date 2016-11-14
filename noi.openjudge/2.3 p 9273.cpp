//OPENJUDGE 9273
//Time Limit of All : 2000 MS
//Time Limit of Each : 1000 MS
//Memory Limit : 131072 KB
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
#define MAX (5000)
int n,a[251][MAX+1];
void mult(int t)
{
	int i;
	for(i=1;i<=a[t-1][0]+2;i++)
	a[t][i]=a[t-1][i]+2*a[t-2][i];
	for(i=1;i<=a[t-1][0]+2;i++)
		if(a[t][i]>=10)
		{
			a[t][i+1]+=a[t][i]/10;
			a[t][i]%=10;
		}
	for(a[t][0]=a[t-1][0]+2;a[t][a[t][0]]==0;a[t][0]--);
}
int main()
{
	int i,j;
	a[1][1]=a[1][0]=a[2][0]=1;
	a[2][1]=3;
	for(i=3;i<=250;i++)
	{
	mult(i);
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		for(i=a[n][0];i>=1;i--)
			printf("%d",a[n][i]);
		printf("\n");
	}
	return 0;
}
