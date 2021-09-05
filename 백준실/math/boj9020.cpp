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
void findprime(int num) {
	vector<int>prime;
	vector<int>same;
	int result = num;
	int finalp[2] = { 0 };
	for (int i = 2; i <= num; i++) {
		if (isprime[i] == false) {
			prime.push_back(i);
			for (int j = i * 2; j <= num; j += i)isprime[j] = true;
		}
	}
	for (int i = 0; i < prime.size(); i++) {
		for (int j = i; j < prime.size(); j++) {
			if (num - prime.at(i) == prime.at(j)) {
				same.push_back(prime.at(i));
				same.push_back(prime.at(j));
			}
		}
	}
	int min = abs(same.at(0) - same.at(1));
	finalp[0] = same.at(0);
	finalp[1] = same.at(1);
	for (int i = 0; i < same.size() / 2; i++) {
		if (min > abs(same.at(2 * i) - same.at(2 * i + 1))) {
			finalp[0] = same.at(2 * i);
			finalp[1] = same.at(2 * i + 1);
		}
	}
	cout << finalp[0] << " " << finalp[1] << "\n";
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num = 0;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> num;
		findprime(num);
	}
}

