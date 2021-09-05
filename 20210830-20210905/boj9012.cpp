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
	string a = "";
	stack<string>s;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> a;
		while (!s.empty())s.pop();
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == '(') {
				s.push("(");
			}
			else if (a[j] == ')') {
				if (s.empty()) {
					cout << "NO\n";
					break;
				}
				s.pop();
			}
			if (s.empty() && j == a.length() - 1) {
				cout << "YES\n";
			}
			if (!s.empty() && j == a.length() - 1) {
				cout << "NO\n";
			}
		}
	}
}

