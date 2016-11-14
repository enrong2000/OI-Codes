//OPENJUDGE 6262
//Time Limit : 1000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
char c[105][105];
int ans=0,n,o,i,p,k,m,nex[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
bool book[105][105];
int tx,ty;
int main()
{
	freopen ("input.txt","r",stdin);
	scanf ("%d",&n);
	for (i=0;i<n;i++)
		scanf ("%s",c[i]);
	scanf ("%d",&m);
	for (i=0;i<m;i++)
	{
		memset(book,true,sizeof(book));
		for (o=0;o<n;o++)
			for (p=0;p<n;p++)
			{
				if (c[o][p]=='@')
				{
					if (book[o+1][p+1]==false)
						continue;
					for (k=0;k<4;k++)
					{
						tx=o+nex[k][0];ty=p+nex[k][1];
						if (tx<0||ty<0||tx>n||ty>n)
							continue;
						if (c[tx][ty]=='.')
						{
							c[tx][ty]='@';
							book[tx+1][ty+1]=false;
						}
					}
					book[o+1][p+1]=false;
				}
			}
	}
	for (i=0;i<n;i++)
		for (o=0;o<n;o++)
			if (c[i][o]=='@')
				ans++;
	printf ("%d\n",ans);
	return 0;
}
