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
ll n, m, t, l, c;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll k;
    cin >> n >> k;
    ll l=1, h = k;
    ll result = 0;
    while (l <= h) {
        ll cnt = 0;
        ll mid = (l + h) / 2;
        for (int i = 1; i <= n; i++) {
            cnt += min((mid / i),n);
        }
        if (cnt < k) {
            l = mid + 1;
        }
        else {
            result = mid;
            h = mid - 1;
        }
    }
    cout << result;
}