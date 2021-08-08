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
	deque<ll>q;
	ll result = 0;
	ll k = 0;
	ll temp = 0;
	ll position = 0;
	cin >> n >> m;
	vector<ll>a(m);
	for (int i = 0; i < n; i++) {
		q.push_back(i + 1);
	}
	for (int i = 0; i < m; i++) {
		k = 0;
		cin >> a[i];
		//위치정보만입력하면끝
		while (1) {
			if (q.at(k) == a[i]) {
				position = k + 1;
				break;
			}
			k++;
		}
		if (round(double(q.size()) / 2) >= position) {//왼쪽진행
			while (1) {
				if (q.at(0) == a[i]) {
					q.pop_front();
					break;
				}
				temp = q.front();
				q.pop_front();
				q.push_back(temp);
				result++;
			}
		}
		else if (round(double(q.size()) / 2) + 1 <= position) {//오른쪽으로진행
			while (1) {
				if (q.at(0) == a[i]) {
					q.pop_front();
					break;
				}
				temp = q.back();
				q.pop_back();
				q.push_front(temp);
				result++;
			}
		}
	}
	cout << result;
}