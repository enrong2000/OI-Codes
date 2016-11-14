#include <stdio.h>
#include<iostream>
using namespace std;
int mod(int k,int n)
{
	if(k==0)return 1;
	int b = mod(k/2,n);
	long long ans = b*b%n;
	if(k%2==1)ans=ans*10%n;
	return (int)ans;
}
int main()
{
	int n,m,k,x;
	cin>>n>>m>>k>>x;
	int a = mod(k,n);
	while(a--)x = (x+m)%n;
	cout<<x<<endl;
	return 0;
}
