//OPENJUDGE 2727 R using dfs
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
int ans,k,m,n,o,i,p,six,siy,stx,sty,tax,tay,tx,ty,nex[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char c[25][25];
bool book[25][25],flag=false;
void dfs(int x,int y,int step)
{
	if (x==tax&&y==tay)
	{
		ans=step,flag=true;return;
	}
	for (k=0;k<4;k++)
	{
		tx=x+nex[k][0],ty=y+nex[k][1];
		if (tx<0||ty<0||tx>=six||ty>=siy)continue;
		if (book[tx][ty]==true && c[tx][ty]=='.')
		{
			book[tx][ty]=false;dfs(tx,ty,step+1);book[tx][ty]=true;
		}
	}
	return;
}
int main()
{
	freopen ("input.txt","r",stdin);
	while (scanf ("%d %d",&six,&siy)==2)
	{
		memset(book,true,sizeof(book));memset(c,0,sizeof(c));
		ans=-1;
		if (six==0 && siy==0)	break;
		for (i=0;i<six;i++)	scanf("%s",c[i]);
		for (i=0;i<six;i++)
			for (o=0;o<siy;o++)
			{
				if (c[i][o]=='@')stx=i,sty=o;
				if (c[i][o]=='*')tax=i,tay=o;
			}
		book[stx][sty]=false;
		dfs (stx,sty,0);
		if (flag==true)	printf ("%d\n",ans);
		else	printf("-1\n");
	}
	return 0;
}
