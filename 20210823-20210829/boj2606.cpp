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
int com = 0;
int a = 0, b = 0;
vector<vector<int>>dist;
vector<bool>visit;
queue<int>hi;
int result = 0;
int floid(int start) {
	visit[start] = true;
	hi.push(start);
	while (!hi.empty()) {
		int fro = hi.front();
		hi.pop();
		for (int i = 0; i < dist[fro].size(); i++) {
			if (!visit[dist[fro].at(i)]) {
				hi.push(dist[fro].at(i));
				visit[dist[fro].at(i)] = true;
				result++;
			}
		}
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> com >> m;
	dist.resize(com + 1);
	visit.resize(com + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dist[a].push_back(b);
		dist[b].push_back(a);
	}
	cout << floid(1);
}