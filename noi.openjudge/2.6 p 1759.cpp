//OPENJUDGE 1759
//Time Limit in Total : 2000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int a[1005],d[1005];
int main()
{
	int n,maxn=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	d[0]=1;
	for(int i=1;i<n;i++)
	{
		d[i]=1;
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<a[i])
			d[i]=max(d[j]+1,d[i]);
		}
		maxn=max(maxn,d[i]);
	}
	cout<<maxn<<endl;
	return 0;
}
