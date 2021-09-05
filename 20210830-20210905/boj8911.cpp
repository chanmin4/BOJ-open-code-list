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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> test;
	string A;
	for (int i = 0; i < test; i++) {
		cin >> A;
		int temp = 0, directx = 0, directy = 1;
		int minx = 0, miny = 0, maxx = 0, maxy = 0;
		int x = 0, y = 0;
		for (int j = 0; j < A.length(); j++) {
			if (A[j] == 'F') {
				x += directx;
				y += directy;
			}
			else if (A[j] == 'L') {
				temp = directx;
				directx = -directy;
				directy = temp;
			}
			else if (A[j] == 'R') {
				temp = directy;
				directy = -directx;
				directx = temp;
			}
			else {
				x -= directx;
				y -= directy;
			}
			if (x < minx)minx = x;
			if (y < miny)miny = y;
			if (x > maxx)maxx = x;
			if (y > maxy)maxy = y;
		}
		cout << (maxx - minx) * (maxy - miny) << "\n";
	}
}

