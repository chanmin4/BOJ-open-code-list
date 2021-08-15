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
ll keyfound = 0;
ll mx[4] = { -1,1,0,0 };
ll my[4] = { 0,0,-1,1 };
vector<vector<bool>>check;
vector<vector<ll>>b;
vector<ll>uf;
vector<vector<char>>mapp;
struct Edge {
	ll u, v, w;
};
vector<Edge>e;
bool compare(Edge & a, Edge & b) {
	return a.w < b.w;
}
ll find(ll a) {
	if (uf[a] < 0)return a;
	return uf[a] = find(uf[a]);
}
bool merge(ll a,ll b) {
	a = find(a);
	b = find(b);
	if (a == b)return true;
	uf[b] = a;
	return false;
}
void bfs(ll x, ll y) {
	queue<P>q;
	q.push({ x, y });
	check[y][x] = true;
	b[y][x] = 0;
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextx = mx[k] + curx;
			int nexty = my[k] + cury;
			if (0 <= nextx && nextx < n && 0 <= nexty && nexty < n) {
				if (!check[nexty][nextx] && mapp[nexty][nextx] != '1') {
					if (mapp[nexty][nextx] == 'K' || mapp[nexty][nextx] == 'S') {
						keyfound++;

					}
					check[nexty][nextx] = true;
					q.push({ nextx, nexty });
					b[nexty][nextx] = min(b[nexty][nextx], b[cury][curx] + 1);
					if (keyfound == m)return;
				}
			}
		}
	}
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
			b[i][j] = 1000000;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	mapp=vector<vector<char>>(n, vector<char>(n));
	check=vector<vector<bool>>(n, vector<bool>(n));
	b=vector<vector<ll>>(n, vector<ll>(n, 1000000));
	ll s = 0;
	vector<P>v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapp[i][j];
			if (mapp[i][j] == 'S') {
				v.push_back({ j, i });
			}
			else if (mapp[i][j] == 'K') {
				v.push_back({ j, i });
			}
		}
	}

	for (int i = 0; i < m; i++) {
		keyfound = 0;
		bfs(v.at(i).first, v.at(i).second);
		if (keyfound != m) {
			cout << -1;
			return 0;
		}
		for (int j = i + 1; j <= m; j++) {
			e.push_back({ i, j, b[v.at(j).second][v.at(j).first] });
		}
		init();
	}
	uf.resize(m + 1, -1);
	sort(e.begin(), e.end(), compare);
	int result = 0, cnt = 0;
	for (int i = 0;; i++) {
		if (!merge(e[i].u, e[i].v)) {
			result += e[i].w;
			cnt++;
			if (cnt == m) {
				break;
			}
		}
	}
	cout << result;
}