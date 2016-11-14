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
int n,ji,tu,asmi,asma;
int main()
{
	scanf ("%d",&n);
	if (n%2==1)
		printf ("0 0\n");
	else
	{
		asma=n/2;
		asmi=(n-(n/4)*4)/2+n/4;
		printf ("%d %d\n",asmi,asma);
	}
	return 0;
}
