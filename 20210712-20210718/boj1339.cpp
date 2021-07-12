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
bool comp(ll a, ll b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<string>a(n);
    vector<ll>alp(26);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        ll checknum = 1;
        for (int j = a[i].length() - 1; j >= 0; j--) {
            ll num = a[i][j] - 'A';
            alp[num] = alp[num] + checknum;
            checknum *= 10;
        }
    }
    sort(alp.begin(), alp.end(),comp);
    ll result = 0;
    ll num = 9;
    for (int i = 0; i < 26; i++) {
        result += alp[i] * num;
        num--;
    }
    cout << result;
}