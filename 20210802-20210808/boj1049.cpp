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
	ld num1 = 0, num2 = 0;
	ll min1 = 0, min2 = 0;
	cin >> n >> t;
	ll b[3] = { 0 };
	//패키지로만 1낱개로만2 패키지낱개섞어서3
	vector<P>arr(t);
	for (int i = 0; i < t; i++) {
		cin >> num1 >> num2;
		arr[i] = P(num1, num2);
	}
	min1 = arr[0].first;
	for (int i = 0; i < t; i++) {
		if (arr[i].first < min1) {
			min1 = arr[i].first;
		}
	}
	min2 = arr[0].second;
	for (int i = 0; i < t; i++) {
		if (arr[i].second < min2) {
			min2 = arr[i].second;
		}
	}
	if (n % 6 == 0)b[0] = (n / 6) * min1;
	else b[0] = ((n / 6) + 1) * min1;
	b[1] = min2 * n;
	b[2] = (n / 6) * min1 + (n % 6) * min2;
	cout << *min_element(b, b + 3);
}