#include <iostream>
#include <stdlib.h>

typedef long long lien;

lien extended_euclidean_algorithm(lien b, lien c) {
	lien r0=b;
	lien r1=c;

	lien x0=1;
	lien x1=0;

	lien y0=0;
	lien y1=1;

	lien r,x,y;
	lien q;

	while(true) {
		q=r0/r1;
		r=r0%r1;

		if(r==0)
			break;

		x=x0-q*x1;
		y=y0-q*y1;

		x0=x1;
		x1=x;

		y0=y1;
		y1=y;

		r0=r1;
		r1=r;
	}

	std::cout<<"Greatest Common Divisor : "<<r1<<std::endl;
	std::cout<<"Bezout Coefficients : "<<x<<" , "<<y<<std::endl;

} 

void solve(lien a, lien b, lien c) { // Solutions for the linear diophantine equation ax+by=c
	lien r0=a;
	lien r1=b;

	lien x0=1;
	lien x1=0;

	lien y0=0;
	lien y1=1;

	lien r,x,y;
	lien q;

	while(true) {
		q=r0/r1;
		r=r0%r1;

		if(r==0)
			break;

		x=x0-q*x1;
		y=y0-q*y1;

		x0=x1;
		x1=x;

		y0=y1;
		y1=y;

		r0=r1;
		r1=r;
	}

	if(c%r1!=0) {
		std::cout<<"No solutions exist for the equation."<<std::endl;
		return;
	}

	std::cout<<"x = "<<x*(c/r1)<<std::endl;
	std::cout<<"y = "<<y*(c/r1)<<std::endl;

	std::cout<<"Error = "<<a*x*(c/r1)+b*y*(c/r1)-c<<std::endl;

	return;

}

int main(){
	solve(-423,198,9);
}