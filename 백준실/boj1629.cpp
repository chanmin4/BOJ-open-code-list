﻿#include<iostream>
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
lli solve(lli a, lli b) {
    if (b == 1)
        return a;
    else {
        ll result = solve(a, b / 2);
        if (b % 2 == 1)
            return((result * result) % c * a) % c;
        else return (result * result) % c;
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    lli a, b;
    cin >> a >> b >> c;
    cout << solve(a%c, b) % c;
}