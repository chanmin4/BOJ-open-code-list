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
vector<int>p;
int find(int n) {
	if (p[n] == n)return n;
	p[n] = find(p[n]);
	return find(p[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int l;
	cin >> n >> l;
	vector<bool>check(l + 1);
	p.resize(l + 1);
	int a, b;
	for (int i = 1; i <= l; i++) {
		p[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (!check[find(a)]) {
			check[find(a)] = true;
			merge(a, b);
			cout << "LADICA" << "\n";
		}
		else if (!check[find(b)]) {
			check[find(b)] = true;
			merge(b, a);
			cout << "LADICA" << "\n";
		}
		else {
			cout << "SMECE" << "\n";
		}
	}
}

