//OPENJUDGE 2753
//Time Limit of All : 1000 MS
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
}ma[1610];
int six,siy,stx,sty,tax,tay,tx,ty,head,tail,k,n,o,i,p,flag=0,nex[4][2]={{0,-1},{-1,0},{1,0},{0,1}},book[45][45];
char c[45][45];
int main()
{
	scanf ("%d %d",&six,&siy);
	for (i=0;i<six;i++)	scanf("%s",c[i]);
	stx=0,sty=0,tax=six-1,tay=siy-1,head=1,tail=2,ma[tail].x=stx,ma[tail].y=sty,ma[tail].step=1;
	while (head<tail)
	{
		for (k=0;k<4;k++)
		{
			tx=ma[head].x+nex[k][0],ty=ma[head].y+nex[k][1];
			if (tx<0||ty<0||tx>=six||ty>=siy)	continue;
			if (c[tx][ty]=='.'&&book[tx][ty]==0)
			{
				book[tx][ty]=1,ma[tail].x=tx,ma[tail].y=ty,ma[tail].step=ma[head].step+1;
				tail++;
			}
			if (tx==tax && ty==tay)
			{
				flag=1;
				goto out;
			}
		}
		head++;
	}
out:	;
	printf ("%d\n",ma[tail-1].step+1);
	return 0;
}
