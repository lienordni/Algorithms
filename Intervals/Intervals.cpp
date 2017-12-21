#include <bits/stdc++.h>

using namespace std;

struct node{
	long double leftend;
	long double rightend;
	int value;
	node* left;
	node* right;

	node();
	node(long double,long double,int);
	bool operator<(node);
	bool operator>(node);
	void operator=(node);

	void cutleft(long double);
	void cutright(long double);
} *spam=new node(-123123,-123123,-123123);

node::node(){
	leftend=-123123;
	rightend=-123123;
	value=-123123;
	left=NULL;
	right=NULL;
}

node::node(long double ll, long double rr, int val){
	leftend=ll;
	rightend=rr;
	value=val;
	left=NULL;
	right=NULL;
}

class intervals{
	node* root;
	int def;

	public:

	intervals();
	void clear();
	void insert(long double, long double, int);
	void setdefault(int);
	int getdefault();
	node* getinterval(long double);
	int value(long double);
};

intervals::intervals(){
	root=NULL;
	def=-1;
}

void intervals::clear(){
	root=NULL;
	def=-1;
}

void intervals::insert(long double ll, long double rr, int value){

}

int main(){
	return 0;
}