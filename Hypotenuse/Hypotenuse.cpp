#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

typedef long long lien;

lien limit;
lien sum;
int count=1;

using namespace std;

class node {

public:

	lien key;
	unsigned char height;
	node* left;
	node* right;

	node (lien);

};

node* root;

node::node (lien k) {
	key=k;
	height=1;
	left=NULL;
	right=NULL;
}

unsigned char height(node* p)
{
	return p?p->height:0;
}

int bfactor(node* p)
{
	return height(p->right)-height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

node* rotateright(node* p)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q)
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // balancing the p node
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // balancing is not required
}

node* insert(node* p, lien k) // insert k key in a tree with p root
{
	if( !p ) {
		// cout<<"lien"<<endl;
		return new node(k);
	}
	if( k<p->key )
		p->left = insert(p->left,k);
	else
		p->right = insert(p->right,k);
	return balance(p);
}

node* findmin(node* p) // find a node with minimal key in a p tree 
{
	return p->left?findmin(p->left):p;
}

node* removemin(node* p) // deleting a node with minimal key from a p tree
{
	if( p->left==0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}


node* remove(node* p, lien k) {
	if(!p)
		return 0;

	if(k < p->key)
		p->left = remove( p->left , k );

	if(k > p->key)
		p->right = remove( p->right , k );

	else {
		node* q = p->left;
		node* r = p->right;
		delete p;
		if(!r)
			return q;

		node* min = findmin(r);
		min->right = removemin(r);
		min->left=q;
		return balance(min);

	}

	return balance(p);
}

bool search(node* p, lien k) {
	if(!p)
		return false;

	if(p->key<k)
		return search(p->right,k);

	else if(p->key>k)
		return search(p->left,k);

	return true;
}

void print(node* p) {
	if(!p)
		return;

	print(p->left);
	// cout<<count++<<" : "<<p->key<<endl;
	sum+=p->key;
	print(p->right);
}

class triple {
	lien a;
	lien b;
	lien c;

public:
	triple();
	triple(lien, lien, lien);
	void set(lien, lien, lien);
	lien getA();
	lien getB();
	lien getC();
	void disp(int);
	bool big();
	lien dot(int*);
	void operator=(triple);
};

triple::triple() {
	a=0;
	b=0;
	c=0;
}

triple::triple(lien x, lien y, lien z) {
	a=x;
	b=y;
	c=z;
}

void triple::set(lien x, lien y, lien z){
	a=x;
	b=y;
	c=z;
}

lien triple::getA(){
	return a;
}

lien triple::getB(){
	return b;
}

lien triple::getC(){
	return c;
}

void triple::disp(int q) {

	if(search(root,c))
		return;

	root=insert(root,c);

	// cout<<q<<"  :  "<<c<<endl;
	// count++;
}

bool triple::big() {
	return c>limit;
}

lien triple::dot(int* array) {
	return a*(array[0])+b*(array[1])+c*(array[2]);
}

void triple::operator=(triple x) {
	a=x.getA();
	b=x.getB();
	c=x.getC();
}

triple transform(triple x, int a){
	if(a==1) {
		int r1[3]={1,-2,2};
		int r2[3]={2,-1,2};
		int r3[3]={2,-2,3};
		return triple(x.dot(r1), x.dot(r2), x.dot(r3));
	}

	else if(a==2) {
		int r1[3]={1,2,2};
		int r2[3]={2,1,2};
		int r3[3]={2,2,3};
		return triple(x.dot(r1), x.dot(r2), x.dot(r3));
	}

	else {
		int r1[3]={-1,2,2};
		int r2[3]={-2,1,2};
		int r3[3]={-2,2,3};
		return triple(x.dot(r1), x.dot(r2), x.dot(r3));
	}

}

triple multiply(triple x, int n) {
	return triple((x.getA())*n,(x.getB())*n,(x.getC())*n);
}

void print(triple x){
	if(x.big())
		return;
	
	x.disp(count);

	int i=2;
	triple z;
	while(true) {
		z=multiply(x,i);
		if(z.big())
			break;

		z.disp(count);
		i++;
	}

	print(transform(x,1));
	print(transform(x,2));
	print(transform(x,3));
}

int main(int argc, char* argv[]){
	sum=0;
	triple h(3,4,5);
	limit=atoi(argv[1]);
	print(h);
	print(root);
	cout<<sum<<endl;
}