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
	cin >> a;
	stack<string>s;
	int num = 0;
	int result = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(') {
			if (a[i + 1] == ')' && !s.empty()) {
				result += num;
				i++;
			}
			else if (a[i + 1] == ')' && s.empty()) {
				i++;
			}
			else {
				s.push("(");
				num++;
				result++;
			}
		}
		else if (a[i] == ')') {
			num--;
			s.pop();
		}
	}
	cout << result;
}

