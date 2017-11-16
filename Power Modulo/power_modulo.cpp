#include <bits/stdc++.h>

using namespace std;

#define mod (long long) (1e9 + 7)

long long power(long long x, long long a) {
	long long ans = 1, current = x;
	while (a > 0) {
		if (a%2 == 1)
			ans = (ans*current)%mod;
		a /= 2;
		current = (current*current)%mod;
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	long long x, a;
	cin>>x>>a;
	cout<<power(x, a)<<endl;
	return 0;
}