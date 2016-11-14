//learning to write
//Longest Increasing Subsequence
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

#define N 41000
using namespace std;
int a[N], d[N];

int BinSearch(int key, int *d, int low, int high)
{
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (key > d[mid] && key <= d[mid + 1])
			return mid;
		else if (key > d[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;
}

int LIS(int *a, int n, int *d)
{
	int i, j;
	d[1] = a[1];
	int len = 1;
	for (i = 2; i <= n; i++)
	{
		if (d[len] < a[i])
			j = len++;
		else
			j = BinSearch(a[i], d, 1, len) + 1;
		d[j] = a[i];
	}
	return len;
}

int main()
{
	int t, p;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &p);
		for (int i = 1; i <= p; i++)
			scanf("%d", &a[i]);
		printf("%d\n", LIS(a, p, d));
	}
	return 0;
}