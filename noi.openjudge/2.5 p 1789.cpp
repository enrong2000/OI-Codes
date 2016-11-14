//OPENJUDGE 1789
//Time Limit in Total : 3000 MS
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
double a,b,c,d;
bool pd;
double Abs(double a)
{
	if (a<0)return -a;
	else	return a;
}
bool check(double a,double b,double c,double d)
{
	if(a==-1&&b==-1&&c==-1&&Abs(d-24.0)<0.01)return true;
	if(a==-1&&b==-1&&d==-1&&Abs(c-24.0)<0.01)return true;
	if(a==-1&&c==-1&&d==-1&&Abs(b-24.0)<0.01)return true;
	if(d==-1&&b==-1&&c==-1&&Abs(a-24.0)<0.01)return true;
	return false;
}

void dfs(double a,double b,double c,double d)
{
	if(pd)return;
	if(check(a,b,c,d)){pd=true;return;}
	if(a!=-1)
	{
		if(b!=-1)
		{
			dfs(-1,a*b,c,d);
			dfs(-1,a+b,c,d);
			dfs(-1,a-b,c,d);
			dfs(-1,b-a,c,d);
			dfs(-1,a/b,c,d);
			dfs(-1,b/a,c,d);
		}
		if(c!=-1)
		{
			dfs(-1,b,c+a,d);
			dfs(-1,b,c-a,d);
			dfs(-1,b,a-c,d);
			dfs(-1,b,c*a,d);
			dfs(-1,b,c/a,d);
			dfs(-1,b,a/c,d);
		}
		if(d!=-1)
		{
			dfs(-1,b,c,d+a);
			dfs(-1,b,c,d-a);
			dfs(-1,b,c,a-d);
			dfs(-1,b,c,d*a);
			dfs(-1,b,c,d/a);
			dfs(-1,b,c,a/d);
		}
	}
	if(b!=-1)
	{
		if(c!=-1)
		{
			dfs(a,-1,b+c,d);
			dfs(a,-1,b-c,d);
			dfs(a,-1,c-b,d);
			dfs(a,-1,b*c,d);
			dfs(a,-1,b/c,d);
			dfs(a,-1,c/b,d);
		}
		if(d!=-1)
		{
			dfs(a,-1,c,d+b);
			dfs(a,-1,c,d-b);
			dfs(a,-1,c,b-d);
			dfs(a,-1,c,d*b);
			dfs(a,-1,c,d/b);
			dfs(a,-1,c,b/d);
		}
	}
	if(c!=-1)
	{
		if(d!=-1)
		{
			dfs(a,b,-1,d+c);
			dfs(a,b,-1,d-c);
			dfs(a,b,-1,c-d);
			dfs(a,b,-1,d*c);
			dfs(a,b,-1,d/c);
			dfs(a,b,-1,c/d);
		}
	}
}

int main()
{
	while(~scanf("%lf%lf%lf%lf",&a,&b,&c,&d)&&a!=0)
	{
		pd=false;
		dfs(a,b,c,d);
		if(pd)printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}
