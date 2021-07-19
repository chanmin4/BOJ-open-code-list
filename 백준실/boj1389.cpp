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
ll INF = 1e9;
int a = 0, b = 0;
bool check = false;
vector<vector<ll>>dist;
vector<ll>arr;
ll position = 1;
void floid() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF)
				arr[i] += dist[i][j];
		}
	}
	ll min = arr[1];
	for (int i = 1; i <= n; i++) {
		if (min > arr[i]) {
			min = arr[i];
			position = i;
		}
	}
	cout << position;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	arr = vector<ll>(n + 1);
	dist=vector<vector<ll>>(n + 1, vector<ll>(n + 1, INF));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}
	floid();

}