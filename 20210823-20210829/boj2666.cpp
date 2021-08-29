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
vector<int>v;
vector<vector<vector<int>>>b;
int num1 = 0, num2 = 0;
int length_B = 0;
int num_of_B = 0;
int dp(int order, int open1, int open2) {
	if (order >= length_B)return 0;
	if (b[open1][open2][order] != -1)return b[open1][open2][order];
	b[open1][open2][order] = min(abs(v[order] - open1) + dp(order + 1, v[order], open2), abs(v[order] - open2) + dp(order + 1, open1, v[order]));

	return b[open1][open2][order];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> num_of_B;
	cin >> num1 >> num2;
	cin >> length_B;
	v.resize(length_B + 1);
	b.resize(num_of_B + 1, vector<vector<int>>(num_of_B + 1, vector<int>(length_B + 1, -1)));
	for (int i = 0; i < length_B; i++) {
		cin >> v[i];
	}
	cout << dp(0, num1, num2);
}