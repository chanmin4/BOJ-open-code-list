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
vector<ll>parent;
ll find(ll a) {
    if (parent[a] < 0)return a;
    return parent[a] = find(parent[a]);
}
void merge(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b)return;
    parent[b] = a;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll g, p;
    cin >> g >> p;
    vector<ll>plane(p + 1);
    parent=vector<ll>(g + 1,-1);
    for (int i = 0; i < p; i++) {
        cin >> plane[i];
    }
    ll result = 0;
    for (int i = 0; i < p; i++) {
        ll num = find(plane[i]);
        if (num != 0) {
            merge(num - 1,num);
            result++;
        }
        else break;
    }
    cout << result;
}