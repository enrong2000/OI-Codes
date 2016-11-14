//NOIP 2012 Ìá¸ß×é
//CODEVS  1200
//Time Limit : 1000 MS
//Memory Limit : 128000 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
void exgcd (long long a,long long b,long long &x,long long &y)
{
	if (!b)
	{
		x=1;y=0;return;
	}
	exgcd(b,a%b,x,y);
	long long k=y;
	y=x-(a/b)*y;
	x=k;
}
int main()
{
	long long a,b,x,y;
	scanf ("%lld %lld",&a,&b);
	exgcd(a,b,x,y);
	if(x<0)	x+=(1+(-x)/b)*b;
	printf ("%lld\n",x%b);
	return 0;
} 
