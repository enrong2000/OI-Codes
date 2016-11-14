//NOIP 2012 Ìá¸ß×é
//CODEVS 1197 Vigenere ÃÜÂë
//Time Limit : 1000 MS
//Memory Limit : 128000 KB
//Enrong
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
string ky,a;
int main()
{
	cin>>ky>>a;
	for(int i=0;i<ky.length();i++)
		if(ky[i]>='A'&&ky[i]<='Z')ky[i]=ky[i]-'A'+'a'; 
	for(int i=0;i<a.length();i+=ky.length())
		for(int j=0;j<ky.length();j++)
			if(a[i+j]>='A'&&a[i+j]<='Z')a[i+j]='A'+(a[i+j]-'A'-(ky[j]-'a')+26)%26;
			else a[i+j]='a'+(a[i+j]-ky[j]+26)%26;
	cout<<a<<endl;
	return 0;
}
//A-65
//a-97

