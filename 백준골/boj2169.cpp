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
ll n, m, t;
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
vector<vector<vector<ll>>>dp;
vector<vector<ll>>a;
vector<vector<bool>>visit;
ll solve(ll ypos,ll xpos,ll direct) {
    if (ypos == n - 1 && xpos == m - 1) {
        return a[ypos][xpos];
    }
    if (dp[ypos][xpos][direct] != -2e9) {
        return dp[ypos][xpos][direct];
    }
    visit[ypos][xpos] = true;
    ll result[3];
    for (int i = 0; i < 3; i++) {
        result[i] = -2e9;
    }
    for (int i = 0; i < 3; i++) {
        ll ny = ypos + y[i];
        ll nx = xpos + x[i];
        if (ny >= 0 && ny <= n - 1 && nx >= 0 && nx <= m - 1) {
            if (!visit[ny][nx]) {
                result[i] = solve(ny, nx,i);
            }
        }
    }
    visit[ypos][xpos] = false;
    return dp[ypos][xpos][direct] = a[ypos][xpos] + max(result[0], max(result[1], result[2]));
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a = vector<vector<ll>>(n, vector<ll>(m));
    dp = vector<vector<vector<ll>>>(n, vector<vector<ll>>(m,vector<ll>(3,-2e9)));
    visit = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << solve(0, 0,0);

}