//NOIP 2011 提高组
//CODEVS 1135 选择客栈
//Time Limit : 1000 MS
//Memory limit : 128000 KB
//Enrong
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
#define int long long
inline int in()
{
	char ch=getchar();int x = 0;
	while (ch<'0'||ch>'9')ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
#undef int
struct node
{
	int col,pri;
}hot[200005];
int nh,nc,mac,o,i,p,mic,head,tail;
queue <int > colo[60];
int main()
{
	nh=in(),nc=in(),mac=in();
	for (i=0;i<nh;i++)
	{
		hot[i].col=in(),hot[i].pri=in();
		colo[hot[i].col].push(i);
	}
	for (i=0;i<=nc;i++)
	{
		
	}
	return 0;
}
