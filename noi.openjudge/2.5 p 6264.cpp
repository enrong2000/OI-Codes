//OPENJUDGE 6264
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
}ma[1000005];
int head,tail,k,n,o,i,p,six,siy,stx,sty,tx,ty,tax,tay,flag,book[1005][1005],nex[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char c[1005][1005];
int main()
{
	memset (book,0,sizeof(book));
	scanf ("%d %d",&six,&siy);
	for (i=0;i<six;i++)	scanf ("%s",c[i]);
	for (i=0;i<six;i++)
		for (o=0;o<siy;o++)
		{
			if (c[i][o]=='S')	stx=i,sty=o;
			if (c[i][o]=='T')	tax=i,tay=o;
		}
	head=1,tail=1,ma[tail].x=stx,ma[tail].y=sty,ma[tail].step=0,tail=tail+1,flag=0;
	while (head<tail)
	{
		for (k=0;k<4;k++)
		{
			tx=ma[head].x+nex[k][0],ty=ma[head].y+nex[k][1];
			if (tx<0||ty<0||tx>=six||tx>=siy)	continue;
			if (book[tx][ty]==0&&c[tx][ty]=='.')ma[tail].x=tx,ma[tail].y=ty,ma[tail].step=ma[head].step+1,book[tx][ty]=1,tail=tail+1;
			if (tx==tax && ty==tay)
			{
				flag=1;goto out;
			}
		}
		head=head+1;
	}
out:	;
	printf ("%d\n",ma[tail-1].step+1);
	return 0;
}
