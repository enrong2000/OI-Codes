//OPENJUDGE 2971
//Time Limit in Total : 2000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int ans,n,k,head,tail,que[100010],vis[100010];
int main()
{
	memset(vis,-1,sizeof(vis));
	scanf ("%d %d",&n,&k);
	que[0]=n,vis[n]=0,head=0,tail=1;
	while(vis[k]<0)
	{
		if(que[head]-1>=0 && vis[que[head]-1]<0)	que[tail]=que[head]-1,vis[que[head]-1]=vis[que[head]]+1,tail=tail+1;
		if(vis[que[head]+1]<0)	que[tail]=que[head]+1,vis[que[head]+1]=vis[que[head]]+1,tail=tail+1;
		if(que[head]*2<=100000 && vis[que[head]*2]<0)	que[tail]=que[head]*2,vis[que[head]*2]=vis[que[head]]+1,tail=tail+1;
		head++;
	}
	printf("%d\n",vis[k]);
	return 0;
}
