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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll kim = 0;
	cin >> n >> m >> kim;
	ll round = 1;
	//임한수나 김지민이 마지막번호면 -1
	while (1) {
		if (n % 2 == 0) {
			if (m % 2 == 1)m++;
			if (kim % 2 == 1)kim++;
			if (kim == m) {
				cout << round;
				break;
			}
			m /= 2;
			kim /= 2;
			round++;
			n /= 2;
		}
		else {
			if (m % 2 == 1)m++;
			if (kim % 2 == 1)kim++;
			if (kim == m) {
				cout << round;
				break;
			}
			m /= 2;
			kim /= 2;
			round++;
			n = n / 2 + 1;
		}


	}

}