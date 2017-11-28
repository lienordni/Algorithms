#include <bits/stdc++.h>

using namespace std;

#define mod ((long long) (1e9+7))

vector<long long> fibmat={1,1,1,0};

vector<long long> product(vector<long long> a, vector<long long> b, long long m=mod){
	vector<long long> ans={(((long long) a[0]*b[0])%m+((long long) a[1]*b[2])%m)%m,(((long long) a[0]*b[1])%m+((long long) a[1]*b[3])%m)%m,(((long long) a[2]*b[0])%m+((long long) a[3]*b[2])%m)%m,(((long long) a[2]*b[1])%m+((long long) a[3]*b[3])%m)%m};
	return ans;
}

vector<long long> power(vector<long long> x, long long n, long long m=mod) {
	if(n==0){
		vector<long long> I={1,0,0,1};
		return I;
	}

	if(n==1){
		vector<long long> a(4);
		for(int i=0;i<4;++i)
			a[i]=x[i]%m;
		return a;
	}

	vector<long long> s=power(x,n/2,m);

	if(n%2==0)
		return product(s,s,m);

	return product(x,product(s,s,m),m);
}

long long fibonacci(long long n, long long m=mod){
	vector<long long> matrix=power(fibmat,n,m);
	return matrix[1];
}

int main(int argc,char* argv[]){
	ios::sync_with_stdio();

	long long n,m=mod;

	if(argc==1)
		std::cin>>n;

	else
		n=atoll(argv[1]);

	if(argc==3)
		m=atoll(argv[2]);

	cout<<fibonacci(n,m)<<endl;

	return 0;

}