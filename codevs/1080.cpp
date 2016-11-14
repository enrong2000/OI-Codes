//LEARNING TO DO
//CODEVS 1080 XGYZ WDMC SCFY XANY NUIZ
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
#define N 100010
#define lson ((rt)<<1)
#define rson (((rt)<<1)|1)
#define mid ((l+r)>>1)
int A[N];
int Sum[N << 2], n, cmd, ask, xx, ad, ans;
#define int long long

inline int in()
{
	int ch = getchar(), x = 0, f = 1;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return (x * f);
}

#undef int

void PushUp(int rt)
{
	Sum[rt] = Sum[lson] + Sum[rson];
}

void Build(int l, int r, int id)
{
	if (l == r)
	{
		Sum[id] = A[l];
		return;
	}
	Build(l, mid, id << 1);
	Build(mid + 1, r, (id << 1) | 1);
	PushUp(id);
}

void Update(int L, int val, int l, int r, int id)
{
	if (l == r)
	{
		Sum[id] += val;
		return;
	}
	if (L <= mid) Update(L, val, l, mid, id << 1);
	if (L > mid) Update(L, val, mid + 1, r, (id << 1) | 1);
	PushUp(id);
}

int Query(int L, int R, int l, int r, int id)
{
	if (L <= l && r <= R)
	{
		return Sum[id];
	}
	int ANS = 0;
	if (L <= mid) ANS += Query(L, R, l, mid, id << 1);
	if (R > mid) ANS += Query(L, R, mid + 1, r, (id << 1) | 1);
	return ANS;
}

int main()
{
	n = in();
	for (int j = 1; j <= n; ++j)
		A[j] = in();
	Build(1, n, 1);
	ask = in();
	for (int k = 0; k < ask; ++k)
	{
		cmd = in(), xx = in(), ad = in();
		if (cmd == 1)
		{
			Update(xx, ad, 1, n, 1);
		}
		if (cmd == 2)
		{
			ans = Query(xx, ad, 1, n, 1);
			printf("%d\n", ans);
		}
	}
	return 0;
}
