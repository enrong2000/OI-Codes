//OPENJUDGE 1808
//Time Limit in Total : 1000 MS
//Memory Limit : 65536 KB
//Enrong 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
string a,b;
int dp[220][220];
int lcs(string a,string b)
{
	memset (dp,0,sizeof(dp));
	int lena=a.size(),lenb=b.size();
	for (int i=1;i<=lena;i++)	for (int j=1;j<=lenb;j++)
	{
		if (a[i-1]==b[j-1])	dp[i][j]=dp[i-1][j-1]+1;
		else 	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	}
	return dp[lena][lenb];
}
int main()
{
	while (cin>>a>>b)
	{
		printf ("%d\n",lcs(a,b));
	}
	return 0;
}
