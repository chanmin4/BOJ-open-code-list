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
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, m, t;
int N = 0;
vector<vector<int>>dist;
int INF = 1000000000;
void floid() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] == INF ? cout << "0 " : cout << "1 ";
		}
		cout << "\n";
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	dist.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
			if (dist[i][j] == 0)dist[i][j] = INF;
		}
	}
	floid();

}