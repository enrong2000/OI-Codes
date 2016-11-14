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
int n,o,i,p;
int a,b,c;
int ma;
int main()
{
	scanf ("%d",&n);
	for (a=n;a>=0;a--)
		for (b=n;b>=0;b--)
			for (c=n;c>=0;c--)
			{
				if ((a+b)%2==0 && (b+c)%3==0 && (a+b+c)%5==0)
					ma=max(a+b+c,ma);
			}
	printf ("%d\n",ma);
	return 0;
}
