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
ll check(queue<ll>imp) {
	ll temp = 0;
	temp = imp.front();
	while (!imp.empty()) {
		if (temp < imp.front())return 1;
		imp.pop();
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	queue<ll>imp;
	cin >> t;
	ll last = 0;
	ll result = 0;
	ll num = 0;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		last = 0;
		result = m;
		for (int j = 0; j < n; j++) {
			cin >> num;
			imp.push(num);
		}
		while (1) {
			if (check(imp) == 1) {//큰게존재
				imp.push(imp.front());
				imp.pop();
				if (result <= 0)result = imp.size() - 1;
				else result--;

			}
			else {
				imp.pop();
				last++;
				if (result <= 0)break;
				else result--;
			}

		}
		while (!imp.empty())imp.pop();
		cout << last << "\n";
	}
}