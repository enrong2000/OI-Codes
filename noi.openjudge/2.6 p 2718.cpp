//OPENJUDGE 8785
//Time Limit in Total : 1000 MS
//Memory Limit : 65536 KB
//Enrong
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
#define INF 0x3f3f3f3f
using namespace std;
int f[20001],w,n,i,j,a[31];
int main()
{
	scanf("%d%d",&w,&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=w;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
	printf("%d",w-f[w]);
	return 0;
}
