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
vector<bool>check;
ll maximum = 0;
ll minimum = 10000000;
ll can(ll count) {
	ll length = 0;
	if (count == 0) {
		return check[0] ? 0 : 1;
	}
	while (count != 0) {
		length++;
		if (check[count % 10] == true)return 0;
		count /= 10;
	}
	return length;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> m;
	check = vector<bool>(10);
	ll num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		check[num] = true;
	}
	ll first = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		ll now = can(i);
		if (now != 0) {
			ll k = abs(n - i);
			if (minimum > now + k) {
				minimum = now + k;
			}
		}
	}
	cout << min(minimum, first);
}