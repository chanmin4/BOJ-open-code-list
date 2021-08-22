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
vector<ll>b;
ll fibo(ll n,ll a[],ll k) {
	b[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= k; j++) {
			b[j] = min(b[j], b[j - a[i]] + 1);
		}
	}
	if (b[k] == k + 1)return -1;
	return b[k];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n >> k;
	ll* a = new ll[n];
	b.resize(k + 1, k + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << fibo(n, a, k);
	delete[]a;

}