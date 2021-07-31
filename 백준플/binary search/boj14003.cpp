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
vector<ll>b;
vector<ll>PP;
vector<ll>arr;
void lis(ll idx, ll num) {
	if (idx == 0) {
		return;
	}
	else if (PP[idx] == num) {
		lis(idx - 1, num - 1);
		cout << arr[idx] << " ";
	}
	else {
		lis(idx - 1, num);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	b=vector<ll>(n + 1);
	arr=vector<ll>(n + 1);
	PP=vector<ll>(n + 1);
	ll len = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		auto pos = lower_bound(b.begin() + 1, b.begin() + 1 + len, arr[i]);
		*pos = arr[i];
		PP[i] = distance(b.begin(), pos);
		if (pos == b.begin() + 1 + len) {
			len++;
		}
	}
	cout << len << "\n";
	lis(n, len);
}