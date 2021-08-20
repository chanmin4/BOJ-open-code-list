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
ll ccw(P vec,ll x,ll y) {

	ll num= vec.first * y - vec.second * x;
	if (num > 0)return 1;
	else if (num == 0)return 0;
	else return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	P one = { x1,y1 };
	P two = { x2,y2 };
	P three = { x3,y3 };
	P four = { x4,y4 };
	P vec1 = { x2-x1,y2-y1 };//1->2 
	P vec2 = { x4 - x3,y4 - y3 };  // 3->4
	ll first = ccw(vec1, x3 - x1, y3 - y1);
	ll second = ccw(vec1, x4 - x1, y4 - y1);
	ll third = ccw(vec2, x1 - x3, y1 - y3); 
	ll fourth=ccw(vec2, x2 - x3, y2 - y3);
	if (first == 0 && second == 0 && third == 0 && fourth == 0) {
		if (one > two)swap(one, two);
		if (three > four)swap(three, four);
		if (three <= two && one <= four) {
			cout << 1;
		}
		else cout << 0;
	}
	else if (first * second <= 0 && third * fourth <= 0) {
		cout << 1;
	}
	else cout << 0;
}