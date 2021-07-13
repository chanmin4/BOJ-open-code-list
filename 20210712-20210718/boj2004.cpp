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
ll solve2(ll num) {
    ll numtwo = 0;
    for (ll i = 2; i <= num; i *= 2) {
        numtwo += num / i;
    }
    return numtwo;
}
ll solve5(ll num) {
    ll numfive = 0;
    for (ll i = 5; i <= num; i *= 5) {
        numfive += num / i;
    }
    return numfive;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cout << min(solve2(n) - solve2(m) - solve2(n - m), solve5(n) - solve5(m) - solve5(n - m));
}