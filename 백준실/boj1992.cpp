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
ll n, m, t, l;
vector<string>v;
bool can = true;
void quadTree(ll x, ll y, ll size) {
	can = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (v[y][x] != v[i][j]) {
				can = false;
				break;
			}
		}
		if (can == false)break;
	}
	if (can == true) {
		cout << v[y][x];
		return;
	}
	ll half = size / 2;
	cout << "(";
	quadTree(x, y, half);
	quadTree(x + half, y, half);
	quadTree(x, y + half, half);
	quadTree(x + half, y + half, half);
	cout << ")";
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	v = vector<string>(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	quadTree(0, 0, n);
}