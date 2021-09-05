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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num = 0;
	int result = 0;
	int temp = 0;
	stack<int>s;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> num;
		if (num == 0) { s.pop(); }
		else s.push(num);
	}
	temp = s.size();
	for (int i = 0; i < temp; i++) {
		result += s.top();
		s.pop();
	}
	cout << result;
}

