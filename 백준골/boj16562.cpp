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
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, m, t, l;
vector<ll>p;
vector<ll>money;
ll find(ll n) {
    if (p[n] == n)return n;
    return p[n] = find(p[n]);
}
void merge(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (money[a] <= money[b]) {
        p[b] = a;
    }
    else {
        p[a] = b;
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll k;
    cin >> n >> m >> k;
    money = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> money[i];
    }
    p = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        merge(a, b);

    }
    ll temp = 0;
    vector<ll>visit(n + 1);
    for (int i = 1; i <= n; i++) {
        ll checking = find(i);
        if (!visit[checking]) {
            temp += money[checking];
            visit[checking] = true;

        }
    }
    if (temp > k)cout << "Oh no";
    else cout << temp;
}