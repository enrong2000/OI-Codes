#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
struct node 
{
	friend bool operater < (node n1,node n2)
	{
		return n1.priority<n2.priority;
	}
	int priority;
	int value;
};
int main()
{
	const int len=5;
	int i;
	int a[len]={3,5,9,6,2};
	//示例1
	priority_queue<int >qi;
	for (i=0;i<len;i++)
		qi.push(a[i]);
	for (i=0;i<len;i++)
	{
		printf ("%d ",qi.top());
		qi.pop();
	}
	printf ("\n");
	//示例2
	priority_queue<int,vector<int>,greater<int>>qi2;
	for (i=0;i<len;i++)
		qi2.push(a[i]);
	for (i=0;i<len;i++)
	{
		printf ("%d ",qi2.top());
		qi2.pop();
	}
	printf ("\n");
	//示例3
	priority_queue<node> qn;
	node b[len];
	b[0].priority=6;b[0].value=1;
	b[1].priority=9;b[1].value=5;
	b[2].priority=2;b[2].value=3;
	b[3].priority=8;b[3].value=2;
	b[4].priority=1;b[1].value=4;
	for (i=0;i<len;i++)
		qn.push(b[i]);
	printf ("优先级\t值\n");
	for (i=0;i<len;i++)
	{
		printf ("%d\t%d\n",qn.top().priority,qn.top().value);
		qn.pop();
	}
	return 0;
}
