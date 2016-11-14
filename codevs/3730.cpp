//NOIP 2014 RJGH YMKF XEGZ
//wireless.cpp/c/pas
//Time Limit : 1000 MS
//Memory Limit : 128000 KB
//LDNU IPWK - Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
#define INF 0x3f3f3f3f


int d, n, x, y, k, max_ = -0x3f3f3f3f, ans;
int m[200][200];

int main()
{
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &x, &y, &k);
		m[y][x] = k;
	}
	for (int i = 0; i <= 128; i++)
	{
		for (int j = 0; j <= 128; j++)
		{
			int tot = 0;
			for (int a = max(i - d, 0); a <= min(i + d, 130); a++)
			{
				for (int b = max(j - d, 0); b <= min(j + d, 130); b++)
				{
					tot += m[a][b];
				}
			}
			if (max_ < tot)
			{
				max_ = tot;
				ans = 1;
			} else if (max_ == tot)ans++;
		}
	}
	printf("%d %d\n", ans, max_);
}