//OPENJUDGE
//Time Limit : 1000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m;
char s1[1000005]; 
int main()
{
	cin>>n>>m>>s1;
	for (int i=1;i<=m;i++)
		next_permutation(s1,s1+n);
	cout<<s1<<endl;
	return 0;
}
