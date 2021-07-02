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
vector<vector<bool>>visit;
vector<string>a;
ll xpos[4] = { 1,-1,0,0 };
ll ypos[4] = { 0,0,-1,1 };
ll bfs(ll y, ll x) {
    ll check = false;
    if (a[y][x] == 'W') {
        check = true;// w만처리
    }
    else check = false; //b만처리
    queue<P>q;
    ll cnt = 1;
    q.push(P(y, x));
    visit[y][x] = true;
    while (!q.empty()) {
        P cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            ll ny = cur.first + ypos[k];
            ll nx = cur.second + xpos[k];
            if (ny >= 0 && ny <= n - 1 && nx >= 0 && nx <= m - 1) {
                if (!visit[ny][nx]) {
                    if (check&&a[ny][nx]=='W') {
                        visit[ny][nx] = true;
                        q.push(P(ny, nx));
                        cnt++;
                    }
                    else if(!check&&a[ny][nx]=='B'){
                        visit[ny][nx] = true;
                        q.push(P(ny, nx));
                        cnt++;
                    }
                }
               
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    a=vector<string>(n);
    visit = vector<vector<bool>>(n, vector<bool>(m));
    //w 우리편 b상대편
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll wcnt = 0;
    ll bcnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) {
                if (a[i][j] == 'W') {
                    wcnt += pow(bfs(i, j),2);
                }
                else {
                    bcnt += pow(bfs(i, j),2);
                }
            }
        }
    }
    cout << wcnt << " " << bcnt;
}