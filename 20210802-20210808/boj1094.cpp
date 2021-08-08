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
ll maker(ll x) {
	ll n = 64;
	ll result = 1;
	ll sum = n;
	while (x < sum) {
		n /= 2;
		result++;
		if (sum - n >= x) {
			sum -= n;
			result--;
		}
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll x = 0;
	cin >> x;
	cout << maker(x);
}