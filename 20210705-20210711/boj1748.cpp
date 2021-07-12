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
    cin >> n;
    ll startnum = 9;//9,90,900 ... 각자릿수별 숫자개수
    ll result = 0;//결과
    ll checklong = 1;//자릿수길이
    ll check2 = 9;
    while (1) {
        if (n > check2) {
            result += startnum*checklong;
            startnum *= 10;
            checklong++;
            check2 += startnum;
        }
        else {
            break;
        }
    }
    ll check = 1;
    for (ll i = 0; i < checklong-1; i++) {
        check *= 10;
    }
    result += (n - check + 1) * checklong;
    cout << result;
}