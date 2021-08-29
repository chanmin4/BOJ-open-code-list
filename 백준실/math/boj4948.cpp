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
bool isprime[123456 * 2 + 1];
void findprime(int num) {
	int result = 0;
	for (int i = 2; i <= num * 2; i++) {
		if (isprime[i] == false) {
			if (i > num)result++;
			for (int j = i * 2; j <= num * 2; j += i)isprime[j] = true;
		}
	}
	printf("%d\n", result);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num = 0;
	while (1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		findprime(num);
	}
}