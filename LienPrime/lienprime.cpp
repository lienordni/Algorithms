#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<int> lienordni(long long n) { // Awesome Lienordni Function (ALF)
	if(n<2047) {
		std::vector<int> v={2};
		return v;
	};
	if(n<1373653) {
		std::vector<int> v={2,3};
		return v;
	}
	if(n<9080191) {
		std::vector<int> v={31,73};
		return v;
	}
	if(n<25326001) {
		std::vector<int> v={2,3,5};
		return v;
	}
	if(n<4759123141) {
		std::vector<int> v={2,7,61};
		return v;
	}
	if(n<1122004669633) {
		std::vector<int> v={2,13,23,1662803};
		return v;
	}
	if(n<2152302898747) {
		std::vector<int> v={2,3,5,7,11};
		return v;
	}
	if(n<3474749660383) {
		std::vector<int> v={2,3,5,7,11,13};
		return v;
	}
	if(n<341550071728321) {
		std::vector<int> v={2,3,5,7,11,13,17};
		return v;
	}
}

long long power_modulo(long long x,long long y,long long n) {
	if(y==0)
		return 1;
	if(y==1)
		return x%n;
	long long z=power_modulo(x,y/2,n);
	if(y%2==0)
		return (z*z)%n;
	return (x*((z*z)%n))%n;
}

bool lienprime(long long n) {
	if(n<2)
		return false;

	if(n==2)
		return true;

	long long d=n-1;
	int s=0;
	while(d%2==0){
		d/=2;
		s++;
	}
	
	long long x;
	bool over;
	std::vector<int> list=lienordni(n);
	
	for(int i=0;i<list.size();++i) {
		x=power_modulo(list[i],d,n);
		if(x==1)
			continue;
		over=false;
		for(int r=0;r<s;++r) {
			if(x==n-1){
				over=true;
				break;
			}
			x=(x*x)%n;
			// std::cout<<x<<std::endl;
		}

		if(over)
			continue;

		return false;
	}

	return true;
}

int main(int argc, char* argv[]){
	long long x;
		
	if(argc==1)
		std::cin>>x;

	else
		x=atoll(argv[1]);

	std::cout<<((lienprime(x))?("YES"):("NO"))<<std::endl;
}