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
vector<P>arr;
ld cross_product(ld x1, ld y1, ld x2, ld y2) {
	return (x1 * y2 - x2 * y1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	arr=vector<P>(n + 1);
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		arr[i] = P(x, y);
	}

	P start = arr[0];
	ld result = 0;
	for (int i = 2; i <= n - 1; i++) {
		P first = P(arr[i - 1].first - start.first, arr[i - 1].second - start.second);
		P second = P(arr[i].first - start.first, arr[i].second - start.second);
		result += cross_product(first.first, first.second, second.first, second.second) / 2.0;
	}
	cout.precision(1);
	cout << fixed << abs(round(result * 10) / 10);
}