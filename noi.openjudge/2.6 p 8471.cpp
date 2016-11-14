//OPENJUDGE 8471
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
bool abcba(int i,int j,char s[])
{
	while(i<j)
	{
		if(s[i]!=s[j]) return 0;
		i++;j--;
	}
	return 1;
}
int judge(int len,char s[])
{
	int i,j,f[1001];
	memset(f,0,sizeof(f));
	f[0]=0;
	for(i=1;i<len;i++)
	{
		int l=0x7fffffff;
		if(!abcba(0,i,s))
			for(j=1;j<=i;j++)
				if(abcba(j,i,s) && f[j-1]<l)	l=f[j-1];
		if(l!=0x7fffffff) f[i]=l+1;
		else f[i]=0;
	}
	return f[len-1];
}
int main()
{
	char s[1001];
	int A,i;
	cin>>A;
	for(i=1;i<=A;i++)
	{
		scanf("%s",&s);
		cout<<judge(strlen(s),s)<<endl;
	}
return 0;
}
