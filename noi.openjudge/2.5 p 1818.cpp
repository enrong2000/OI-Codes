//OPENJUDGE 1818
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
char a[101][101];
int z[101];
int m,n,s=1;
void search(int,int);
int x[4]={1,0,0,-1},y[4]={0,1,-1,0};
int main()
{
	memset(a,'#',sizeof(a));
	int b,c;
	while(cin>>n>>m&&m!=0&&n!=0)
	{
		if(s!=0) s=1;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j]; 
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]=='@')
				{
					b=i;
					c=j;
				}
			} 
	search(b,c);
	cout<<s<<endl;
	}
return 0;
} 
void search(int l,int r) 
{
	for(int i=0;i<4;i++)
	{ 
		if(r+x[i]>=1&&r+x[i]<=n&&l+y[i]>=1&&l+y[i]<=m&&a[l+y[i]][r+x[i]]=='.')
		{	
			s++;
			a[l+y[i]][r+x[i]]='#';
			search(l+y[i],r+x[i]);
		}
	} 
}
