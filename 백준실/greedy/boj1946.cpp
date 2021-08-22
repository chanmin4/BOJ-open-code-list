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
vector<P>v;
bool compare(P v1, P v2) {
	return v1.first < v2.first;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll num1 = 0, num2 = 0;
	ll result = 0;
	cin >> t;
	for(int i = 0; i < t; i++) {
		result = 1;
		cin >> n;
		v.clear();
		for (int j = 0; j < n; j++) {
			cin >> num1 >> num2;
			v.push_back(make_pair(num1, num2));
		}
		sort(v.begin(), v.end(), compare);
		ll minimum = v.at(0).second;
		for (int k = 1; k < n; k++) {
			if (v.at(k).second < minimum) {
				minimum = v.at(k).second;
				result++;
			}
		}
		cout << result << "\n";
	}
}