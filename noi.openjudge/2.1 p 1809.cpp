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
int n,o,i,p,a[20],ans;
void quicksort (int left,int right)
{
	if (left>right)
		return;
	int i,m,t,temp;
	i=left;
	m=right;
	temp=a[left];
	while (i!=m)
	{
		while (a[m]>=temp && i<m)
			m--;
		while (a[i]<=temp && i<m)
			i++;
		if (i<m)
		{
			t=a[i];
			a[i]=a[m];
			a[m]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	quicksort (left,i-1);
	quicksort (i+1,right);
}
int main()
{
	i=1;
	while (scanf ("%d",&a[i]))
	{
		if (a[i]==0)
			break;
		else
			i++;
	}
	quicksort (1,i-1);
	for (o=1;o<=i-1;o++)
		for (p=o+1;p<=i-1;p++)
		{
			if (a[p]==2*a[o])
				ans++;
			if (a[p]>2*a[o])
				continue;
		}
	printf ("%d\n",ans);
	return 0;
}
