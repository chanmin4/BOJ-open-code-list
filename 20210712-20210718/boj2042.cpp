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
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//순환이 반복되면 -1
	int test = 0;
	int M, N, x, y = 0;
	int x1, y1 = 0;
	int Num = 0;
	int firsttime = 0;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> M >> N >> x >> y;
		firsttime = 0;
		x1 = 0;
		y1 = 0;
		Num = 0;
		while (1) {
			if (firsttime == 0) {
				x1 = x;
				firsttime++;
				Num += x1;
				if (x1 % N != 0)
					y1 = x1 % N;
				else {
					y1 = N;
				}

				if (Num > lcm(M, N)) {
					cout << -1 << endl;
					break;
				}
				if (y == y1) {
					cout << Num << endl;
					break;
				}
			}
			else {
				if ((y1 + M) % N != 0)
					y1 = (y1 + M) % N;
				else {
					y1 = N;
				}
				Num += M;

				if (Num > lcm(M, N)) {
					cout << -1 << endl;
					break;
				}
				if (y == y1) {
					cout << Num << endl;
					break;
				}
			}
		}//while
	}
}