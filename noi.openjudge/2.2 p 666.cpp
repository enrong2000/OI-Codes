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
int k,n,m,i,j,f[20][20];
int main()
{
	scanf ("%d",&k);
	for (int l=1;l<=k;l++)
	{
		scanf ("%d %d",&n,&m);
		memset(f,0,sizeof(f));
		f[1][1]=1;
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				if (i!=1 || j!=1)
				{
					f[i][j]=f[i-1][j-1];
					if (i-j>=0)
						f[i][j]=f[i-j][j];
				}
	int ans;
	for (i=1;i<=m;i++)
		ans+=f[n][i];
	printf("%d\n",ans);
	}
	return 0;
}
