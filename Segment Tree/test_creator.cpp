#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll random(ll a, ll b){
	// srand(time(0));
	return a+rand()%(b-a+1);
}

int main(){
	srand(time(0));
	ll n=random(1,100000);
	ll q=random(1,100000);
	int i,x,z,l,r;
	cout<<n<<" "<<q<<endl;
	for(i=0;i<n;++i){
		x=random(10000,1000000);
		cout<<x<<" ";
	}

	for(i=0;i<q;++i){
		z=random(0,1);
		if(z==0){
			cout<<"Q ";
			l=random(0,(n*2)/3);
			r=random(l,n-1);
			cout<<l<<" "<<r<<" "<<endl;
		}
		if(z==1){
			cout<<"M ";
			l=random(0,n-1);
			r=random(10000,1000000);
			cout<<l<<" "<<r<<" "<<endl;
		}
	}
}
