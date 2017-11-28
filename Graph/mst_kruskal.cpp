/*
Maximum Vertex Count = M-1

*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll M=1000000000;

vector<vector<ll>> adj;
vector<pair<ll,ll>> ew;
vector<ll> parent;
ll m,n;

ll Hash(ll u, ll v){
	return (u<=v)?(M*u+v):(v*M+u);
}

pair<ll,ll> unHash(ll h){
	return make_pair(h/M,h%M);
}

ll find_parent(ll x){
	ll p=x;
	while(p!=parent[p])
		p=parent[p];
	parent[x]=p;
	return p;
}

bool set_union(ll x, ll y){
	ll a=find_parent(x);
	ll b=find_parent(y);

	if(a==b)
		return false;

	parent[a]=b;
	return true;
}

ll kruskal(){
	std::sort(ew.begin(),ew.end());

	parent.resize(n+1);

	ll i;
	for(i=1;i<=n;++i)
		parent[i]=i;

	// for(i=0;i<m;++i){
	// 	swap(ew[i].first,ew[i].second);
	// }

	pair<ll,ll> edge;

	ll total_weight=0;

	ll count=0;

	for(i=0;i<m;++i){
		edge=unHash(ew[i].second);
		if(set_union(edge.first,edge.second)){
			cout<<(edge.first)<<"  "<<(edge.second)<<"  "<<(ew[i].first)<<endl;
			total_weight+=ew[i].first;
			count++;
			if(count==n-1)
				return total_weight;
		}
	}	

	return total_weight;
}

int main(){
	int u,v,w,i,j;

	cin>>n>>m;

	adj.resize(n+1);

	for(i=0;i<m;++i){
		cin>>u>>v>>w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		ew.push_back(make_pair(w,Hash(u,v)));
	}

	cout<<kruskal()<<endl;

}