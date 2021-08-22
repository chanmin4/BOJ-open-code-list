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
bool isprime[1001];
ll findprime(ll max, ll A[], ll test) {
	vector<ll>prime;
	ll result = 0;
	for (int i = 2; i <= max; i++) {
		if (isprime[i] == false) {
			prime.push_back(i);

			for (int j = i * 2; j <= max; j += i)isprime[j] = true;
		}
	}
	for (int i = 0; i < test; i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (A[i] == prime.at(j)) {
				result++;
				continue;
			}
		}
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> t;
	ll* A = new ll[t];
	for (int i = 0; i < t; i++) {
		cin >> A[i];
	}
	ll maximum = *max_element(A, A + t);
	cout << findprime(maximum, A, t);
	delete[]A;
}