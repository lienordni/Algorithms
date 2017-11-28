#include <bits/stdc++.h>

using namespace std;

pair <int, int> reduce_frac(int x, int y) {
	while (__gcd(x, y) != 1) {
		int g = __gcd(x, y);
		x /= g;
		y /= g;
	}
	return make_pair(x, y);
}

pair <pair <int, int>, pair <int, int> > make_line(pair <int, int> p1, pair <int, int> p2) {
	int x1 = p1.first, y1 = p1.second;
	int x2 = p2.first, y2 = p2.second;

	pair <pair <int, int>, pair <int, int> > ans;

	if (x1 == x2) {
		ans.first = {1, 0};	//x = c
		ans.second = {x1, 1};	//this is the x-intercept not y-intercept
	}
	else if (y1 == y2) {
		ans.first = {0, 1};	//y = c;
		ans.second = {y1, 1};
	}
	else {
		ans.first = reduce_frac(y2 - y1, x2 - x1);
		int num = ans.first.first, den = ans.first.second;
		ans.second = reduce_frac(den*y1 - num*x1, den);
	}

	return ans;
}

int main() {
	auto line = make_line({2,5}, {7,-1});
	pair <int, int> m = line.first, c = line.second;
	
	if (m == make_pair(1, 0))
		cout<<"x = "<<c.first<<endl;
	else {
		cout<<"y = ("<<m.first<<"/"<<m.second<<")*x + ("<<c.first<<"/"<<c.second<<")"<<endl;
	}
}