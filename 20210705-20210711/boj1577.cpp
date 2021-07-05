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
vector<vector<ll>>dp;
ll x[2] = {1,0 };
ll y[2] = { 0,1 };
ll visit[101][101][2];
ll solve(ll ypos, ll xpos) {
    if (ypos == m && xpos == n)return 1;
    if (dp[ypos][xpos] != -1)return dp[ypos][xpos];
    dp[ypos][xpos] = 0;
    for (int i = 0; i < 2; i++) {
        ll ny = ypos + y[i];
        ll nx = xpos + x[i];
        if (!visit[ypos][xpos][i]) {
            if (ny <= m && nx <= n) {
                dp[ypos][xpos] += solve(ny, nx);
            }
        }
    }
    return dp[ypos][xpos];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;  //m이 세로 n이가로 주의
    ll k;
    cin >> k;
   dp= vector<vector<ll>>(m + 1, vector<ll>(n+ 1,-1));
   memset(visit, false, sizeof(visit));
    for (int i = 0; i < k; i++) {
        ll a, b, c, d;//x,y순
        cin >> a >> b >> c >> d;
        //x->x+1  0 표시   y->y+1 1표시 
        if (a != c) {
            if (a > c)swap(a, c);  //a->c;
            visit[b][a][0] = true;
        }
        else {
            if (b > d)swap(b, d);//b->d;
            visit[b][a][1] = true;
        }
    }
    cout<<solve(0, 0);
}