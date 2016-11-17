//XGYZ WDMC SCFY TRAINING
//HDU 1754 I HATE IT
//Time Limit : 3000 MS (For C++)
//Meomry Limit : 32768 kb (For C++)
//LDNU IPWK - Enrong
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
#define int long long
#define N 200020
#define lson ((id)<<1)
#define rson ((id)<<1|1)
#define mid ((l+r)>>1)
int A[N], ma[N << 2], n;
int ask, stp, enp, va;
int CMD;

int in()
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
	return x * f;
}

void PushUp(int id)
{
	ma[id] = max(ma[lson], ma[rson]);
}

void Build(int l, int r, int id)
{
	if (l == r)
	{
		ma[id] = A[l];
		return;
	}
	Build(l, mid, lson);
	Build(mid + 1, r, rson);
	PushUp(id);
}

void Update(int L, int val, int l, int r, int id)
{
	if (l == r)
	{
		ma[id] = val;
		return;
	}
	if (L <= mid) Update(L, val, l, mid, lson);
	else Update(L, val, mid + 1, r, rson);
	PushUp(id);
}

int Query(int L, int R, int l, int r, int id)
{
	if (L <= l && r <= R)
		return ma[id];
	int ANS = 0;
	if (L <= mid) ANS = max(ANS, Query(L, R, l, mid, lson));
	if (R > mid) ANS = max(ANS, Query(L, R, mid + 1, r, rson));
	return ANS;
}
#undef int

int main()
{
#define int long long
	while (scanf("%lld%lld", &n, &ask) == 2)
	{
		for (int i = 1; i <= n; ++i)
			A[i] = in();
		Build(1, n, 1);
		for (int j = 0; j < ask; ++j)
		{
			do CMD = getchar(); while (CMD != 'Q' && CMD != 'U');
			if (CMD == 'Q')
			{
				stp = in();
				enp = in();
				printf("%lld\n", Query(stp, enp, 1, n, 1));
			}
			if (CMD == 'U')
			{
				stp = in();
				va = in();
				Update(stp, va, 1, n, 1);
			}
		}
	}
	return 0;
#undef int
}