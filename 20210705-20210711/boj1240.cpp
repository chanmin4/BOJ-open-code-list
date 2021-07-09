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
vector<vector<P>>adj;
vector<bool>visit;
ll result = 0;
void dfs(ll a,ll b,ll cur) {
    if (a == b) {
        result = cur;
        return;
    }
    visit[a] = true;
    for (P next : adj[a]) {
        if (!visit[next.first]) {
            dfs(next.first, b, cur + next.second);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    adj = vector<vector<P>>(n + 1);
    ll a, b, c;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(P(b,c));
        adj[b].push_back(P(a,c));
    }
    for (int i = 0; i < m; i++) {
        visit = vector<bool>(n + 1);
        cin >> a >> b;
        dfs(a, b,0);
        cout << result << "\n";
    }
    
}