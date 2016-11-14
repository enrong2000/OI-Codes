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
int main()
{
	int i,j,k,l,n;	
	scanf("%d",&n);
	for(i=2;i<=n;i++)
		for(j=2;j<=n;j++)
			for(k=j+1;k<=n;k++)
				for(l=k+1;l<=n;l++)
					if(i*i*i==l*l*l+j*j*j+k*k*k)
	printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
}
