//OPENJUDGE 6264 R
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
#include <functional>
#include <iostream>
using namespace std;
int n,m,map[101][101];
char ch[101];
int way[101][101];
int ans,sum;
int x,y,s,t;
void search(int a,int b)
{
	if(map[a][b]==1||sum+abs(s-a)+abs(t-b)>=ans||a==0||b==0||a>n||b>m||way[a][b]<=sum)
		return ;
	if(a==s&&b==t)
	{
	if(sum<ans)
		{
			ans=sum;
			way[a][b]=sum;
		}
		return;
	}	
	if(way[a][b]>sum)
		way[a][b]=sum;	
	else
		return ;
	map[a][b]=1;
	sum++;
	search(a,b-1);
	search(a-1,b);
	search(a,b+1);
	search(a+1,b);
	sum--;
	map[a][b]=0; 
}
int main()
{ 
	ans=99999999;
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			way[i][j]=99999999;
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		for(j=0;j<=m-1;j++)
		{
			if(ch[j]=='#')
				map[i][j+1]=1;
			else
			{
				if(ch[j]=='S')
				{
					s=i;
					t=j+1;
				}
				if(ch[j]=='T')
				{
					x=i;
					y=j+1;
				}
			}			
		}
	}
	search(x,y);
	printf("%d\n",ans);
	return 0;
}
