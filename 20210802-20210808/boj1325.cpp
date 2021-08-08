#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<list>
#include<unordered_set>
#include<time.h>
#define fup(i,a,b,c) for(int i=a;i<=b;i+=c)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, t, m, k;
ll num1 = 0, num2 = 0;
vector<vector<ll>>adj;
vector<bool>check;
vector<ll>lastresult;
ll maximum = 1;
ll result = 1;
void dfs(ll n) {
	for (int i = 0; i < adj[n].size(); i++) {
		if (!check[adj[n].at(i)]) {
			check[adj[n].at(i)] = true;
			result++;
			if (maximum < result)maximum = result;
			dfs(adj[n].at(i));
		}
	}
}
void init() {
	maximum = 1;
	result = 1;
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	adj=vector<vector<ll>>(n + 1);
	check=vector<bool>(n + 1);
	lastresult=vector<ll>(n+ 1);
	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		adj[num2].push_back(num1);
	}
	for (int i = 1; i <= n; i++) {
		check[i] = true;
		dfs(i);
		lastresult[i] = maximum;
		init();
	}
	int checkmax = *max_element(lastresult.begin(), lastresult.end());
	for (int i = 1; i <= n; i++) {
		if (lastresult[i] == checkmax)cout << i << " ";
	}
}