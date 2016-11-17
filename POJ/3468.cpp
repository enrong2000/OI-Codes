//XGYZ WDMC SCFY TRAINING
//POJ 3468 A Simple Problem with Integers
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
#define N 100010
#define lson ((id)<<1)
#define rson ((id)<<1|1)
#define mid ((l+r)>>1)
int A[N], Sum[N << 2], Add[N << 2];
int n, ask, CMD, stp, enp, va;

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
	Sum[id] = Sum[lson] + Sum[rson];
}

void PushDown(int ln, int rn, int id)
{
	if (Add[id])
	{
		Add[lson] += Add[id];
		Add[rson] += Add[id];
		Sum[lson] += ln * Add[id];
		Sum[rson] += rn * Add[id];
		Add[id] = 0;
	}
}

void Build(int l, int r, int id)
{
	if (l == r)
	{
		Sum[id] = A[l];
		return;
	}
	Build(l, mid, lson);
	Build(mid + 1, r, rson);
	PushUp(id);
}

void Update(int L, int R, int val, int l, int r, int id)
{
	if (L <= l && r <= R)
	{
		Sum[id] += val * (l - r + 1);
		Add[id] += val;
		return;
	}
	PushDown(mid - l + 1, r - mid, id);
	if (L <= mid) Update(L, R, val, l, mid, lson);
	if (R > mid) Update(L, R, val, mid + 1, r, rson);
	PushUp(id);
}

int Query(int L, int R, int l, int r, int id)
{
	if (L <= l && r <= R)
		return Sum[id];
	PushDown(mid - l + 1, r - mid, id);
	int ANS = 0;
	if (L <= mid) ANS += Query(L, R, l, mid, lson);
	if (R > mid) ANS += Query(L, R, mid + 1, r, rson);
	PushUp(id);
	return ANS;
}
#undef int

int main()
{
#define int long long
	while (scanf("%lld %lld", &n, &ask) != EOF)
	{
		for (int i = 1; i <= n; ++i)
			A[i] = in();
		Build(1, n, 1);
		for (int j = 0; j < ask; ++j)
		{
			do CMD = getchar(); while (CMD != 'Q' && CMD != 'C');
			if (CMD == 'Q')
			{
				stp = in(), enp = in();
				printf("%lld\n", Query(stp, enp, 1, n, 1));
			}
			if (CMD == 'C')
			{
				stp = in(), enp = in(), va = in();
				Update(stp, enp, va, 1, n, 1);
			}
		}
	}
	return 0;
#undef int
}
