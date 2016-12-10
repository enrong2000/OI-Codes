//Self - Writing XGYZ WDMC SCFY
//CODEVS 1081
//Time Limit : 1000 MS
//Memory Limit : 128 MB
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
#define N 100010
#define lson ((id)<<1)
#define rson ((id)<<1|1)
#define mid ((l+r)>>1)
int A[N], Sum[N << 2], Add[N << 2];//Add stores lazy
int n, ask, xx, yy, va, cmd;

#define int long long

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

#undef int

void PushUp(int id)
{
	Sum[id] = Sum[lson] + Sum[rson];
}

void PushDown(int id, int ln, int rn)
{
	if (Add[id])
	{
		Add[lson] += Add[id];
		Add[rson] += Add[id];
		Sum[lson] += Add[id] * ln;
		Sum[rson] += Add[id] * rn;
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

void Update1(int L, int val, int l, int r, int id)
{
	if (l == r)
	{
		Sum[id] += val;
		return;
	}
	if (L <= mid) Update1(L, val, l, mid, lson);
	if (L > mid) Update1(L, val, mid + 1, r, rson);
	PushUp(id);
}

void Update2(int L, int R, int val, int l, int r, int id)
{
	if (L <= l && r <= R)
	{
		Sum[id] += val * (r - l + 1);
		Add[id] += val;
		return;
	}
	PushDown(id, mid - l + 1, r - mid);
	if (L <= mid) Update2(L, R, val, l, mid, lson);
	if (R > mid) Update2(L, R, val, mid + 1, r, rson);
	PushUp(id);
}

int Query(int L, int R, int l, int r, int id)
{
	if (L <= l && r <= R)
		return Sum[id];
	PushDown(id, mid - l + 1, r - mid);
	int ANS = 0; 
	if (L <= mid) ANS += Query(L, R, l, mid, lson);
	if (R > mid) ANS += Query(L, R, mid + 1, r, rson);
	return ANS;
}

int main()
{
	n = in();
	for (int i = 1; i <= n; ++i)
		A[i] = in();
	ask = in();
	Build(1,n,1);
	for (int j = 0; j < ask; ++j)
	{
		cmd = in();
		if (cmd == 1)
		{
			xx = in(), yy = in(), va = in();
			Update2(xx, yy, va, 1, n, 1);
			for (int i = xx; i <= yy; ++i)
				A[i]+=va;
		}
		if (cmd==2)
		{
			xx=in();
			printf("%d\n",A[xx]);
		}
	}
	return 0;
}
