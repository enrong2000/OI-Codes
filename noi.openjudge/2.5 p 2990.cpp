//OPENJUDGE 2990
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
int n,num[25]={0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,8222299};
int main()
{
	while (scanf ("%d",&n)==1)
	{
		if (n==0)	break;
		printf ("%d %d\n",n,num[n]);
	}
	return 0;
}
