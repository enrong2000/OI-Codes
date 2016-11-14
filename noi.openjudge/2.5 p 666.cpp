//OPENJUDGE 666
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
int t,m,n;
int search (int a,int b,int c)
{
	int g=0,i=1;
	if (b==1) g=1;
	else for (i=c;i<=a/b;++i)
		g+=search(a-i,b-1,i);
	return g; 
}
int main ()
{
	cin>>t;
	for (int i=1;i<=t;++i)
	{
		cin>>m>>n;
		cout<<search(m,n,0)<<endl;
	}
	return 0; 
}
