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
ll x[4] = { 1,-1,0,0 };
ll y[4] = { 0,0,-1,1 };
vector<vector<ll>>dp;
vector<string>a;
vector<vector<bool>>visit;
ll dfs(ll ypos,ll xpos) {
    if (ypos < 0 || ypos >= n || xpos < 0 || xpos >= m)return 0;
    if (a[ypos][xpos] == 'H')return 0;
    if (visit[ypos][xpos]) {
        cout << -1 << endl;
        exit(0);
    }
    if (dp[ypos][xpos]) {
        return dp[ypos][xpos];
    }
    visit[ypos][xpos] = true;
    for (int i = 0; i < 4; i++) {
        ll ny = ypos + y[i] * (a[ypos][xpos]-'0');
        ll nx = xpos + x[i]*(a[ypos][xpos]-'0');
        dp[ypos][xpos] = max(dp[ypos][xpos], dfs(ny,nx)+1);
    }
    visit[ypos][xpos] = false;
    return dp[ypos][xpos];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a = vector<string>(n);
    visit = vector<vector<bool>>(n, vector<bool>(m));
    dp = vector<vector<ll>>(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dfs(0, 0);

}