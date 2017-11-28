#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

vector <int> adj[N];
int n, m;
bool vis[N];

void dfs_rec(int u) {
	for (int v: adj[u])
		if (!vis[v])
			vis[v] = 1, dfs_rec(v);
}

void dfs() {
	for (int u = 1; u <= n; u++)
		if (!vis[u])
			vis[u] = 1, dfs_rec(u);
}

int main() {
	ios::sync_with_stdio(false);
	int u, v;
	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs();
	return 0;
}