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
bool isprime[10001];
void findprime(int M, int N) {
	int result = 0;
	int firsttime = 0;
	int min = 0;
	for (int i = 2; i <= N; i++) {
		if (isprime[i] == false) {
			if (M <= i) {
				if (firsttime == 0) {
					firsttime++;
					min = i;
				}
				result += i;
			}
			for (int j = i * 2; j <= N; j += i)isprime[j] = true;
		}
	}
	if (firsttime == 0) {
		cout << -1;

	}
	else {
		cout << result << "\n" << min;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	int M, N = 0;
	cin >> M >> N;
	findprime(M, N);
}