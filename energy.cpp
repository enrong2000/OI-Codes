#include<map>    
#include<set>    
#include<list>    
#include<stack>    
#include<queue>    
#include<vector>    
#include<cmath>    
#include<cstdio>    
#include<cstring>    
#include<iostream>    
#include<algorithm>    
    
using namespace std; 

double ener[10010];

int cmp(double a, double b)
{
	return a > b;
}

int main()
{
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);

	int n, k;
	while(~scanf("%d%d", &n ,&k))
	{
		bool flag = false;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf", &ener[i]);
			if(i >= 1)
			{
				if(ener[i] != ener[i - 1])
				{
					flag = true;
				}
			}
		}
		if(n == 1 || !flag )
		{
			printf("%.9f\n", ener[0]);
			continue;
		}
		sort(ener, ener + n,cmp);
		double l = ener[n - 1];
		double r = ener[0];
		double mid;
		double ans;
		while( r - l > 1e-11 )
		{
			bool flag = true;
			double cur_ener = 0;
			mid = (l + r) / 2;
			for(int i = 0; i < n; i++)
			{
				if(ener[i] - mid >= 1e-11)
					cur_ener += (ener[i] - mid);
				else
				{
					double dis = 1.0 * (mid - ener[i]) * 100 / (100 - k);
					if(dis - cur_ener > 1e-11)
					{
						flag = false;
						break;
					}
					else
						cur_ener -= dis;
				}
			}
			if(flag)
			{
				ans = mid;
				l = mid;
			}
			else
				r = mid;
		}
		printf("%.9f\n", ans);
	}
	return 0;
}
