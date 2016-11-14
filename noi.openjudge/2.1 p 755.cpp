//OPENJUDGE
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
bool map[6][6],fid=false;
char c;
int next[5][2]={{1,0},{0,1},{0,0},{-1,0},{0,-1}},step;
int n,o,p;
bool isgoal ()
{
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			if (map[i][j]!=map[0][0])
				return false;
	return true;
}
void flip(int x,int y)
{
	for (int a=0;a<5;a++)
	{
		int tx=x+next[a][0];int ty=y+next[a][1];
		if (tx<0||ty<0||tx>3||ty>3)
			continue;
		map[tx][ty]=!map[tx][ty];
	}
}
void dfs(int x,int y,int dep)
{
	if (dep==step)
	{
		fid=isgoal();
		return;
	}
	if (fid||x==4)	return;
	flip(x,y);
	if (y!=3)	dfs(x,y++,dep++);
	else	dfs(x++,1,dep++);
	flip(x,y);
	if (y!=3)	dfs(x,y++,dep);
	else	dfs(x++,1,dep);
}
int main()
{
	memset(map,false,sizeof(map));
	for (n=0;n<4;n++)
	{
		for (o=0;o<4;o++)
		{
			scanf ("%c",&c);
			if (c=='b')	map[n][o]=true;
		}
		scanf ("%c",&c);
	}
	for (step=1;step<=16;step++)
	{
		dfs(0,0,0);
		if (fid)
		{
			printf ("%d\n",step);
			return 0;
		}
	}
	printf ("Impossible\n");
	return 0;
}
