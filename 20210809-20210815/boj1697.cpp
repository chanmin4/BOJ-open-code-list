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
vector<bool>visit;
queue<ll>a;
vector<ll>b;
ll count = 1;
ll point = 0;
void bfs(ll n) {
	visit[n] = true;
	while (!a.empty()) {
		ll tmp = a.front();
		a.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				if (0 <= tmp - 1) {
					b[tmp - 1] = min(b[tmp - 1], b[tmp] + 1);
					point = tmp - 1;
				}
			}
			else if (i == 1) {
				if (tmp + 1 <= 100000) {
					b[tmp + 1] = min(b[tmp + 1], b[tmp] + 1);
					point = tmp + 1;
				}
			}
			else if (i == 2) {
				if (tmp * 2 <= 100000) {
					b[tmp * 2] = min(b[tmp * 2], b[tmp] + 1);
					point = tmp * 2;
				}
			}
			if (!visit[point]) {
				visit[point] = true;
				a.push(point);
			}
		}
	}
	cout << b[k];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	visit=vector<bool>(100001, false);
	b=vector<ll>(100001, 100000000);
	b[n] = 0;
	a.push(n);
	bfs(n);

}