#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void print(vector<ll> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<"  ";
	cout<<endl;
}

vector<ll> v;

struct node {
	ll value;
	int l;
	int r;
	node* right;
	node* left;
	bool assigned;
	
	node();
	void set(int L, int R);
};

node::node(){
		right=NULL;
		left=NULL;
		l=0;
		r=0;
		value=0;
		assigned=false;	
}

void node::set(int L, int R){
		right=NULL;
		left=NULL;
		l=L;
		r=R;
		value=0;
		assigned=false;
}

void print_tree(node* x){
	if(!x)
		return;
	cout<<x->l<<" - "<<x->r<<" : "<<x->value<<endl;
	print_tree(x->left);
	print_tree(x->right);
}

void print(node* x){
	if(!x)
		return;
	cout<<"$$  "<<x->l<<" - "<<x->r<<" : "<<x->value<<endl;
}

node* make_blue_print(int l, int r){
	 node* root=new node;
	 root->set(l,r);

	 if(l==r)
	 	return root;
	 int mid=((r+1-l)%2)?(l+(r+1-l)/2):(l+((r+1-l)/2)-1);
	 root->left=make_blue_print(l,mid);
	 root->right=make_blue_print(mid+1,r);	
	 return root;
}

ll combine(ll a, ll b){
	return a+b; //CHANGE
}

void merge(node* ptr, node* left, node* right){
	if(!left)
		ptr->value=right->value;

	else if(!right)
		ptr->value=left->value;

	else
		ptr->value=combine(left->value,right->value);

	return ;
}

void assign(node* ptr){
	if(!ptr)
		return;
	
	if(!ptr->left && !ptr->right){
		ptr->value=v[ptr->l];
		ptr->assigned=true;
		return;
	}

	if(ptr->left){
		if(!ptr->left->assigned){
			assign(ptr->left);
		}
	}

	if(ptr->right){
		if(!ptr->right->assigned){
			assign(ptr->right);
		}
	}

	merge(ptr,ptr->left,ptr->right);
	ptr->assigned=true;
	return;
}

node* make_tree(vector<ll> v){
	node* root=make_blue_print(0,v.size()-1);
	assign(root);
	return root;
}

ll range_query(node* root, int x, int y){
	if(x==y)
		return v[x];

	if(x<=root->l && y>=root->r)
		return root->value;

	if(x>(root->r) || y<(root->l))
		return 0; // CHANGE	

	return combine(range_query(root->left,x,y),range_query(root->right,x,y));
}

void update_value(node* root,int index, ll newval){
	if(!root)
		return;

	ll diff=newval-v[index];
	if(diff==0)
		return;

	if(root->l==root->r){
		root->value+=diff; //change
		v[index]+=diff; //change
		return;
	}

	int mid=(((root->r)+1-(root->l))%2)?((root->l)+((root->r)+1-(root->l))/2):((root->l)+(((root->r)+1-(root->l))/2)-1);


	if(index>=root->l && index<=mid){
		update_value(root->left,index,newval);
	}

	else {
		update_value(root->right,index,newval);
	}

	root->value=root->left->value+root->right->value; // CHANGE
}

int main(){
	v={73,27,51,99,46,3,17,93,91,40};
	node* tree;

	tree=make_tree(v);
	cout<<range_query(tree,3,7)<<endl;;
	print(v);

	update_value(tree,3,200);

	cout<<range_query(tree,3,7)<<endl;;
	print(v);


}

