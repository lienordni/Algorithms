#include <vector>

std::vector<int> lienordni(long long n) { // Awesome Lienordni Function (ALF)
	if(n<2047) {
		std::vector<int> v;
		v.push_back(2);
		return v;
	};
	if(n<1373653) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(3);
		return v;
	}
	if(n<9080191) {
		std::vector<int> v;
		v.push_back(31);
		v.push_back(73);
		return v;
	}
	if(n<25326001) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(3);
		v.push_back(5);
		return v;
	}
	if(n<4759123141) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(7);
		v.push_back(61);
		return v;
	}
	if(n<1122004669633) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(13);
		v.push_back(23);
		v.push_back(1662803);
		return v;
	}
	if(n<2152302898747) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(3);
		v.push_back(5);
		v.push_back(7);
		v.push_back(11);
		return v;
	}
	if(n<3474749660383) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(3);
		v.push_back(5);
		v.push_back(7);
		v.push_back(11);
		v.push_back(13);
		return v;
	}
	if(n<341550071728321) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(3);
		v.push_back(5);
		v.push_back(7);
		v.push_back(11);
		v.push_back(13);
		v.push_back(17);
		return v;
	}
}

long long power_modulo(long long x,long long y,long long n) {
	long long z;
	if(y==0)
		return 1;
	if(y==1)
		return x%n;
	if(y%2==0){
		long long z=power_modulo(x,y/2,n);
		return (z*z)%n;
	}
	return (x*power_modulo(x,y-1,n))%n;
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