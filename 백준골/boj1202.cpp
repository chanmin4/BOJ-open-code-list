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
vector<ll>we;
vector<P>jewel;
struct comp{
    bool operator()(P a,P b) {
        return a.second < b.second;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll k;
    cin >> n >> k;
    we = vector<ll>(k);
    jewel = vector<P>(n);
    priority_queue<P, vector<P>, comp>pq;
    for (int i = 0; i < n; i++) {
        ll v;
        cin >> m >> v;
        jewel[i] = P(m, v);
    }
    for (int i = 0; i < k; i++) {
        cin >> we[i];
    }
    sort(jewel.begin(), jewel.end());
    sort(we.begin(), we.end());
    ll cnt = 0;
    ll result = 0;
    for (int i = 0; i < k; i++) {
        while(cnt < n&&jewel[cnt].first <= we[i]) {
            pq.push(jewel[cnt]);
            cnt++;
        }
        if (!pq.empty()) {
            result += pq.top().second;
            pq.pop();
        }
    }
    cout << result;
}