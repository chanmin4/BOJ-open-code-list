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
bool compare(P a, P b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	ll num1 = 0, num2 = 0;
	ll result = 0;
	ll check = 0;
	vector<P>v(t);
	for (int i = 0; i < t; i++) {
		cin >> num1 >> num2;
		v[i] = make_pair(num1, num2);
	}
	sort(v.begin(), v.end(), compare);
	ll endposition = 0;
	ll temp = 1;
	result++;
	for (int i = 1; i < t; i++) {
		if (v[i].first >= v[endposition].second) {
			endposition = temp;
			result++;
		}
		temp++;
	}
	cout << result;
}