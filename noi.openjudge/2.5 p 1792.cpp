//OPENJUDGE 1792
//Time Limit of All : 3000 MS
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
	int x,y,d;
}p[10010];
char s[110][110];
int fx[4]={-1,1,0,0};
int fy[4]={0,0,-1,1};
int n,m;
bool tf;
int x,y,tax,tay;
void bfs()
{
	p[1].x=x;p[1].y=y;
	if (s[x][y]=='#' || s[tax][tay]=='#')
	{
		tf=false;
		return;
	}
	int st=1,ed=2;
	while (st!=ed)
	{
		for (int i=0;i<4;i++)
		{
			int xx=p[st].x+fx[i],yy=p[st].y+fy[i];
			if (xx<0 || xx>=n || yy<0 || yy>=n) continue;
			if (s[xx][yy]=='.')
			{
				s[xx][yy]='#';
				p[ed].x=xx;
				p[ed].y=yy;
				ed++;
			}
			if (xx==tax && yy==tay)
			{	
				tf=true;
				return;
			}
		}
		st++;
	}
}

int main()
{
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d",&n);
		tf=false;
		for (int i=0;i<n;i++)
			scanf("%s",s[i]);
		scanf("%d %d %d %d",&x,&y,&tax,&tay);
		bfs();
		if (tf==true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
