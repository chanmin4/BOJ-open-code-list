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
vector<int>uf;
int find(int a) {
	if (uf[a] < 0)return a;
	return uf[a] = find(uf[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return true;//연결되었다면
	uf[b] = a;
	return false;
}
class Edge {
public:
	int u, v, w;
	Edge() {}
	Edge(int a, int b, int c) {
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
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		Edge* e = new Edge[200000];
		uf.resize(n + 1, -1);
		int resultw = 0;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			e[i] = Edge(x, y, z);
			resultw += z;
		}
		sort(e, e + m);
		int resultspaning = 0, cnt = 0;
		for (int i = 0;; i++) {
			if (!merge(e[i].u, e[i].v)) {
				resultspaning += e[i].w;
				cnt++;
				if (cnt == n - 1)break;
			}
		}
		cout << resultw - resultspaning << "\n";
		uf.clear();
		delete[]e;
	}
}

