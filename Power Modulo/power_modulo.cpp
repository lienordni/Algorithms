#include <bits/stdc++.h>

using namespace std;

#define mod (long long) (1e9 + 7)

long long power(long long x, long long n) {
	if(n==0)
		return 1;

	if(n==1)
		return x%mod;

	long long s=power(x,n/2);

	if(n%2==0)
		return (s*s)%mod;

	return (x*((s*s)%mod))%mod;
}

int main() {
	ios::sync_with_stdio(false);
	long long x,n;
	cin>>x>>n;
	cout<<power(x,n)<<endl;
	return 0;
}