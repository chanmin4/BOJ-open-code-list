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
ll maxi = -2000;
vector<ll>arr;
ll dp() {
	b[0] = arr[0];
	maxi = b[0];
	for (int i = 1; i < n; i++) {
		b[i] = max(b[i - 1] + arr[i], arr[i]);
		maxi = max(maxi, b[i]);
	}
	return maxi;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	b.resize(n + 1);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << dp();
}