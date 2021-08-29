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
struct planet {
	int x, y, z, num;
	planet() {}
	planet(int a, int b, int c, int d) {
		x = a;
		y = b;
		z = c;
		num = d;
	}
};
struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int a, int b, int c) {
		u = a;
		v = b;
		w = c;
	}
	bool operator<(const Edge& b) {
		return w < b.w;
	}
};
int find(int a) {
	if (uf[a] < 0)return a;
	return uf[a] = find(uf[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return true;
	uf[b] = a;
	return false;
}
bool comx(planet & a, planet & b) {
	return a.x < b.x;
}
bool comy(planet & a, planet & b) {
	return a.y < b.y;
}
bool comz(planet & a, planet & b) {
	return a.z < b.z;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	planet* p = new planet[n];
	vector<Edge>e;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		p[i] = planet(x, y, z, i);
	}
	sort(p, p + n, comx);
	for (int i = 0; i < n - 1; i++) {
		e.push_back(Edge(p[i].num, p[i + 1].num, abs(p[i].x - p[i + 1].x)));
	}
	sort(p, p + n, comy);
	for (int i = 0; i < n - 1; i++) {
		e.push_back(Edge(p[i].num, p[i + 1].num, abs(p[i].y - p[i + 1].y)));
	}
	sort(p, p + n, comz);
	for (int i = 0; i < n - 1; i++) {
		e.push_back(Edge(p[i].num, p[i + 1].num, abs(p[i].z - p[i + 1].z)));
	}
	sort(e.begin(), e.end());
	int result = 0, cnt = 0;
	uf.resize(n + 1, -1);
	for (int i = 0;; i++) {
		if (!merge(e[i].u, e[i].v)) {
			result += e[i].w;
			cnt++;
			if (cnt == n - 1)break;
		}
	}
	cout << result;
}