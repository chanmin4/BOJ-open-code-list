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
ll n, m, t, l;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a = "";
	stack<string>s;
	while (1) {
		getline(cin, a, '.');
		if (a == "") { break; }
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '(') {
				s.push("(");
			}
			else if (a[i] == ')') {
				if (s.empty() || s.top() == "[") {
					cout << "no\n";
					break;
				}
				s.pop();
			}
			else if (a[i] == '[') {
				s.push("[");
			}
			else if (a[i] == ']') {
				if (s.empty() || s.top() == "(") {
					cout << "no\n";
					break;
				}
				s.pop();
			}
			if (s.empty() && i == a.length() - 1)cout << "yes\n";
			else if (!s.empty() && i == a.length() - 1)cout << "no\n";
		}
		while (!s.empty())s.pop();
		cin.ignore();
	}

}