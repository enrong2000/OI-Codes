//OPENJUDGE 2727 F using bfs
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
struct node
{
	int x,y,step;
}ma[450];
char c[25][25];
int head,tail,k,m,n,o,i,p,flag,six,siy,stx,sty,tax,tay,tx,ty,book[25][25],nex[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
int main()
{
	while (scanf ("%d %d",&six,&siy)==2)
	{
		if (six==0 && siy==0)	break;
		memset(c,0,sizeof(c));
		memset(book,0,sizeof(book));
		for (i=0;i<six;i++)	scanf ("%s",c[i]);
		for (i=0;i<six;i++)
			for (o=0;o<siy;o++)
			{
				if (c[i][o]=='@')	stx=i,sty=o;
				if (c[i][o]=='*')	tax=i,tay=o;
			}
		flag=0,head=1,tail=1,ma[tail].x=stx,ma[tail].y=sty,ma[tail].step=1,tail=tail+1,book[stx][sty]=1;
		while (head<tail)
		{
			for (k=0;k<4;k++)
			{
				tx=ma[head].x+nex[k][0],ty=ma[head].y+nex[k][1];
				if (tx<0||ty<0||tx>=six||ty>=siy)	continue;
				if (c[tx][ty]=='.'&&book[tx][ty]==0)ma[tail].x=tx,ma[tail].y=ty,ma[tail].step=ma[head].step+1,book[tx][ty]=1,tail=tail+1;
				if (tx==tax&&ty==tay)
				{
					flag=1;break;
				}
			}
			if (flag==1)break;
			head=head+1;	
		}
		if (flag==1)printf ("%d\n",ma[tail-1].step-1);
		if (flag==0)printf ("-1\n");
		for (i=1;i<=tail-1;i++)	ma[i].x=0,ma[i].y=0,ma[i].step=0;
	}
	return 0;
}
