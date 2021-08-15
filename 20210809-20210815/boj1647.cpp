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
vector<ll>uf;
ll find(ll a) {
	if (uf[a] < 0)return a;
	return uf[a] = find(uf[a]);
}
bool merge(ll a,ll b) {
	a = find(a);
	b = find(b);
	if (a == b)return true;//연결되었다면
	uf[b] = a;
	return false;
}
class Edge {
public:
	ll u, v, w;
	Edge() {}
	Edge(ll a, ll b, ll c) {
		u = a;
		v = b;
		w = c;
	}
	bool operator <(Edge& e) {
		return w < e.w;
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	Edge* e = new Edge[m];
	uf=vector<ll>(n + 1, -1);
	for (ll i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[i] = Edge(x, y, z);
	}
	sort(e, e + m);
	ll resultspaning = 0, cnt = 0;
	for (int i = 0;; i++) {
		if (!merge(e[i].u, e[i].v)) {
			resultspaning += e[i].w;
			cnt++;
			if (cnt == n - 2)break;
		}
	}
	cout << resultspaning << "\n";
	delete[]e;

}