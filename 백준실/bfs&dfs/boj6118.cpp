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
ll n, t, m, k, test;
int maximum;
vector<bool>check;
queue<int>hi;
vector<int>coun;
vector<vector<int>>adj;
int countmaximum;
void bfs(int num) {
	while (!hi.empty()) {
		int now = hi.front();
		hi.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			if (!check[adj[now].at(i)]) {
				hi.push(adj[now].at(i));
				check[adj[now].at(i)] = true;
				coun[adj[now].at(i)] = coun[now] + 1;
				if (maximum < coun[adj[now].at(i)])maximum = coun[adj[now].at(i)];
			}
		}
	}


}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num1 = 0, num2 = 0;
	cin >> n >> m;
	adj.resize(n + 1);
	check.resize(n + 1);
	coun.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		adj[num1].push_back(num2);
		adj[num2].push_back(num1);
	}
	check[1] = true;
	maximum = 0;
	hi.push(1);
	bfs(1);
	int cur = 0;
	bool firsttime = false;
	for (int i = 1; i <= n; i++) {
		if (maximum == coun[i]) {
			if (firsttime == false) {
				firsttime = true;
				cur = i;
			}
			countmaximum++;
		}
	}
	cout << cur << " " << maximum << " " << countmaximum;
}

