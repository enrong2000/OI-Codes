//NOIP 2014 Higher
//CODEVS 3716
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
int n, na, nb, mi, o, i, p, r, cishu, sca, scb;
int a[100010], b[100010];
int cmp[5][5] = {{0, 0, 1, 1, 0},
                 {1, 0, 0, 1, 0},
                 {0, 1, 0, 0, 1},
                 {0, 0, 1, 0, 1},
                 {1, 1, 0, 0, 0}};

int gcd (int x,int y)
{
	return x==0?y:gcd(y%x,x);
}
int zxgbs(int aa, int bb)
{
	if (aa > bb)
		return zxgbs(bb, aa);
	return aa * bb / Gcd(aa, bb);
}

int main()
{
	scanf("%d %d %d", &n, &na, &nb);
	for (i = 1; i <= na; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= nb; i++)
		scanf("%d", &b[i]);
	for (i = na + 1; i <= zxgbs(na, nb); i++)
		a[i] = a[i - na];
	for (i = nb + 1; i <= zxgbs(na, nb); i++)
		b[i] = b[i - nb];
	cishu = n / zxgbs(na, nb);
	if (cishu == 0)
	{
		for (i = 1; i <= n; i++)
			sca += cmp[a[i]][b[i]], scb += cmp[b[i]][a[i]];
	} else
	{
		for (i = 1; i <= zxgbs(na, nb); i++)
			sca += cmp[a[i]][b[i]], scb += cmp[b[i]][a[i]];
		sca *= cishu, scb *= cishu;
		n = n % zxgbs(na, nb);
		for (i = 1; i <= zxgbs(na, nb); i++)
			sca += cmp[a[i]][b[i]], scb += cmp[b[i]][a[i]];
	}
	printf("%d %d\n", sca, scb);
	return 0;
}

