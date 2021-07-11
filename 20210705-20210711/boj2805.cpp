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
    cin >> n >> m;
    vector<ll>a(n);
    ll maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    ll l = 0, r = maxi;
    ll maxiresult = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll temp = 0;
        for (int i = 0; i < n; i++) {
            if (mid < a[i]) {
                temp += a[i] - mid;
            }
        }
        if (temp >= m) {
            maxiresult = max(maxiresult, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << maxiresult;
}