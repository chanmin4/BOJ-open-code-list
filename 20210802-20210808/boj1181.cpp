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
bool compare(string & a, string & b) {
	if (a.length() < b.length())
		return true;//길이가 짧은것부터
	else if (a.length() > b.length())
		return false;
	else if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				return a[i] < b[i];
			}
		}
		return false;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >>t;
	string a;
	vector<string>A;
	for (int i = 0; i < t; i++) {
		cin >> a;
		if (find(A.begin(), A.end(), a) == A.end()) {
			A.push_back(a);
		}
	}
	sort(A.begin(), A.end(), compare);
	for (int i = 0; i < A.size(); i++) {
		cout << A.at(i) << "\n";
	}
}