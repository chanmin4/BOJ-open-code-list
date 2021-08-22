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
ll n, t, m, k, test;
vector<vector<ll>>b;
ll dp(ll n) {
	//b[i][첫자리수]
	//b[i-1]의 첫자리가 1이아니여야됨
	//b[i][0]의 경우도 저장해놔야됨

	//b[1][1] 1 b[1][0] 0  b[2][1] 10 b[2][0]=01,00
	//b[3][1]=101,100  

	b[1][1] = 1;
	b[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		b[i][1] = b[i - 1][0];
		b[i][0] = b[i - 1][1] + b[i - 1][0];

	}
	return b[n][1];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	b=vector<vector<ll>>(n + 1, vector<ll>(2));
	cout << dp(n);

}