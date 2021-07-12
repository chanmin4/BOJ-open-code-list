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
ll gcd(ll a,ll b) {
    ll temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    ll up = a * d + b * c;
    ll down = b * d;
    ll num = gcd(up, down);
    cout << up / num << " " << down / num;
}