//XGYZ WDMC SCFY TRAINING
//HDU 1166 TDTY RGWU DMHJ BLHZ
//Time Limit : 1000 MS (For C++)
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
#define N 50010
#define lson ((id)<<1)
#define rson ((id)<<1|1)
#define mid ((l+r)>>1)
int a[N], Sum[N << 2], Add[N << 2];
int n, ask, nC, pos, va;
char cmd[6];

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
		Add[lson] = Add[id];
		Add[rson] = Add[id];
		Sum[lson] += Add[id] * ln;
		Sum[rson] += Add[id] * rn;
		Add[id] = 0;
	}
}

void Build(int l, int r, int id)
{
	if (l == r)
	{
		Sum[id] = a[l];
		return;
	}
	Build(l, mid, lson);
	Build(mid + 1, r, rson);
	PushUp(id);
}

void Update1(int L, int val, int l, int r, int id, int CMD)
{
	if (l == r)
	{
		switch (CMD)
		{
			case 1:
				Sum[id] += val;
				return;
			default:
				Sum[id] -= val;
				return;
		}
	}
	if (L <= mid) Update1(L, val, l, mid, lson, CMD);
	if (L > mid) Update1(L, val, mid + 1, r, rson, CMD);
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
	return ANS;
}
#undef int

int main()
{
	nC = in();
	for (int i = 1; i <= nC; ++i)
	{
		printf("Case %lld:\n", i);
		n = in();
		for (int j = 1; j <= n; ++j)
			a[j] = in();
		Build(1, n, 1);
		while (scanf("%s", cmd))
		{
			switch (cmd[0])
			{
				case 'Q':
					goto s1;
				case 'A':
					goto s2;
				case 'S':
					goto s3;
				default:
					goto out;
			}
			s1:;
			pos = in(), va = in();
			printf("%lld\n", Query(pos, va, 1, n, 1));
			continue;
			s2:;
			pos = in(), va = in();
			Update1(pos, va, 1, n, 1, 1);
			continue;
			s3:;
			pos = in(), va = in();
			Update1(pos, va, 1, n, 1, 2);
			continue;
		}
		out:;
	}
	return 0;
}
