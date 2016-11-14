//OPENJUDGE 7084
//Time Limit in All : 1000 MS
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
	int x,y,fat,step;
}ma[35];
int maze[6][6],k,m,n,o,i,p,head,tail,en,stx=0,sty=0,tax=4,tay=4,tx,ty,flag=0,book[6][6],nex[4][2]={{-1,0},{0,-1},{1,0},{0,1}},ansx[30],ansy[30];
int main()
{
	memset(book,0,sizeof(book));memset(maze,0,sizeof(maze));
	for (i=0;i<5;i++)
		for (o=0;o<5;o++)
			scanf ("%d",&maze[i][o]);
	head=1,tail=2,ma[head].x=stx,ma[head].y=sty,ma[head].fat=0,ma[head].step=1;
	while (head<tail)
	{
		for (k=0;k<4;k++)
		{
			tx=ma[head].x+nex[k][0],ty=ma[head].y+nex[k][1];
			if (tx<0||ty<0||tx>=5||ty>=5)	continue;
			if (maze[tx][ty]==0&&book[tx][ty]==0)ma[tail].x=tx,ma[tail].y=ty,ma[tail].fat=head,ma[tail].step=ma[head].step+1,tail=tail+1,book[tx][ty]=1;
			if (tx==tax && ty==tay)
			{
				flag=1;goto out;
			}
		}
		head=head+1;
	}
out:	;
	ansx[0]=ma[tail-1].x,ansy[0]=ma[tail-1].y,tail--,en=tail;
	for (i=ma[tail].step+1;i>=1;i--)
	{
		ansx[i]=ma[ma[tail].fat].x,ansy[i]=ma[ma[tail].fat].y,tail=ma[tail].fat;
		if (ansx[i]==0 && ansy[i]==0)	break;
	}
	for (o=i;o<=ma[en].step+1;o++)
		printf ("(%d, %d)\n",ansx[o],ansy[o]);
	printf ("(%d, %d)\n",ansx[0],ansy[0]);
	return 0;
}
