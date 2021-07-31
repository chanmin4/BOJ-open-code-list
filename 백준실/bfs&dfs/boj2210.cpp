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
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n = 0;
	ll result = 0;
	cin >> n;
	vector<ll>v(n);
	vector<ll>hi;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	result = v[1] - v[0];
	for (int i = 1; i < n - 1; i++) {
		result = gcd(v[i + 1] - v[i], result);
	}
	for (int i = 2; i * i <= result; i++) {
		if (result % i == 0) {
			hi.push_back(i);
			if (result > i * i) {
				hi.push_back(result / i);
			}
		}
	}
	hi.push_back(result);
	sort(hi.begin(), hi.end());
	for (int i = 0; i < hi.size(); i++) {
		cout << hi.at(i) << " ";
	}
}