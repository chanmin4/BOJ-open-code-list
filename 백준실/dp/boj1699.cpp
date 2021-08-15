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
ll dp() {
	//각 제곱수 1로초기화
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k * k <= i; k++) {
			b[i] = min(b[k * k] + b[i - k * k], b[i]);
		}
	}
	return b[n];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	b=vector<ll>(n + 1, 100000000);
	for (int i = 1; i * i <= n; i++) {
		b[i * i] = 1;
	}
	cout << dp();

}