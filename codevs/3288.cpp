//NOIP 2013 提高组
//CODEVS 3288 积木大赛
//Time Limit : 1000 MS
//Memory Limit : 128000 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int a[100050],n,o,i,p,ans;
#define int long long
inline int in()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9')	ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
#undef int
int main()
{
	n=in();
	for (i=1;i<=n;i++)	a[i]=in();
	ans=a[1];
	for (i=2;i<=n;i++)
	{
		ans+=a[i];
		ans-=min(a[i],a[i-1]);
	}
	printf ("%d\n",ans);
	return 0;
}
