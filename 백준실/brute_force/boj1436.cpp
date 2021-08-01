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
ll INF = 100000000;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	ll count = 666;
	ll cur = 0;
	string s = "";
	while (cur < n) {
		s = to_string(count);
		if (s.find("666") != -1)cur++;
		count++;
	}
	cout << s;
}