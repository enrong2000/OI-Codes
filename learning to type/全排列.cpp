//È«ÅÅÁÐÄ£°å
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int pd[11],used[11];
void print()
{
	for (int i=1;i<=n;i++)
		printf ("%d ",used[i]);
	printf ("\n");
}
void search(int k)
{
	if (k==n){print();return;}
	for (int i=1;i<=n;i++)
	{
		if (!pd[i]){pd[i]=1;used[k+1]=i;search(k+1);pd[1];}
	}
}
int main()
{
	cin>>n;
	search(0);
	return 0;
}
