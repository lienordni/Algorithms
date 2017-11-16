#include <bits/stdc++.h>

using namespace std;

#define mod (long long)(1e9 + 7)

const int N = 1234567;

long long fac[N];

void precompute() {
	fac[0] = 1;
	for (int i = 1; i <= N; i++)
		fac[i] = (fac[i - 1]*i)%mod;
}

long long fast_exp_mod(long long x, long long a) {
	long long ans = 1, current = x;
	while (a > 0) {
		if (a%2 == 1)
			ans = (ans*current)%mod;
		a /= 2;
		current = (current*current)%mod;
	}
	
	return ans;
}

long long ncr_mod(long long n, long long k) {
	long long num = fac[n];
	long long den = (fac[n - k]*fac[k])%mod;
	
	return (num*fast_exp_mod(den, mod - 2))%mod;
}

int main() {
	ios::sync_with_stdio(false);
	precompute();
	return 0;
}
