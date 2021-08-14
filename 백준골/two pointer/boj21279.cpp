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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll c;
	cin >> n >> c;
	vector<vector<P>>x(100000+1);
	vector<vector<P>>y(100000+1);
	vector<ll>value(n);
	for (int i = 0; i < n; i++) {
		ll num1, x1, y1;
		cin >> x1 >> y1 >> num1;
		value[i] = num1;
		x[x1].push_back(P(y1,i));
		y[y1].push_back(P(x1,i));
	}
	ll checkx = 100000; ll checky = 0; ll checkc = 0;
	ll result = 0;
	ll sum = 0;
	// 가능한 직사각형 모두검사
	while (checky <= 100000 && checkx >= 0) {
		if (checkc <= c) {//직사각형 범위안 초과x
			for (P a : y[checky]) {
				if (a.first <= checkx) {
					checkc += 1;
					sum += value[a.second];
				}
			}
			checky++;
		}
		else {
			for (P a : x[checkx]) {//범위안 초과경우
				if (a.first <= checky) {
					checkc -= 1;
					sum -= value[a.second];
				}
			}
			checkx--;
		}
		if (checkc <= c) {
			result = max(result, sum);
		}
	}
	cout << result;
}