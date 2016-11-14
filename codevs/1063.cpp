//CODEVS 1063
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
priority_queue<int>q;
inline int in()
{
	char ch=getchar();
	int x=0;
	while (ch<'0'||ch>'9')
		ch=getchar();
	while (ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main()
{
	int n;
	n=in();
	for (int i=1;i<=n;i++)
	{
		int x;
		x=in();
		q.push(-x);
	}
	int result =0;
	for (int i=1;i<=n-1;i++)
	{
		int x=q.top();
		result=result-q.top();
		q.pop();
		x=x+q.top();
		result=result-q.top();
		q.pop();
		q.push(x);
	}
	printf ("%d\n",result);
	return 0;
}
