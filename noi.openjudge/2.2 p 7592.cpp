//OPENJUDGE 7592
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
int m,n;
int gcd(int x,int y)
{
	if (y==0)	return x;
	if (x<y)	return gcd(y,x);
	else	return gcd(y,x%y);
}
int main()
{
	scanf ("%d %d",&m,&n);
	printf ("%d\n",gcd(m,n));
	return 0;
}
