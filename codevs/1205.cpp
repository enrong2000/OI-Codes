#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	vector<string>vs;
	string str;
	while (cin>>str)
		vs.push_back(str);
	for (vector<string>::reverse_iterator b=vs.rbegin(),e=vs.rend();b!=e;b++)
	cout<<*b<<" ";
	printf ("\n");
	return 0;
}
