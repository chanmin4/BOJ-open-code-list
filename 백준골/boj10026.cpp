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
vector<vector<ll>>a;
vector<vector<bool>>d_visit;
vector<vector<bool>>visit;
ll bfs(ll ypos, ll xpos, bool check,ll curcolor) {
    if (!check)
        visit[ypos][xpos] = true;
    else d_visit[ypos][xpos] = true;
    queue<P>q;
    q.push(P(ypos, xpos));
    while (!q.empty()) {
        P cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ll ny = cur.first + y[i];
            ll nx = cur.second + x[i];
            if (ny >= 0 && ny <= n - 1 && nx >= 0 && nx <= n - 1) {
                if (check) {
                    if (!d_visit[ny][nx]) {
                        if ((curcolor == 1 || curcolor == 2)&&a[ny][nx]!=3) {
                            //R,G끼리
                            d_visit[ny][nx] = true;
                            q.push(P(ny, nx));
                        }
                        else if(curcolor==3&&a[ny][nx]==3) {
                            //B끼리
                            d_visit[ny][nx] = true;
                            q.push(P(ny, nx));
                        }
                    }
                }
                else {
                    if (!visit[ny][nx]) {
                        if (curcolor == 1&&a[ny][nx]==1) {
                            visit[ny][nx] = true;
                            q.push(P(ny, nx));
                        }
                        else if (curcolor == 2 && a[ny][nx] == 2) {
                            visit[ny][nx] = true;
                            q.push(P(ny, nx));
                        }
                        else if (curcolor == 3 && a[ny][nx] == 3) {
                            visit[ny][nx] = true;
                            q.push(P(ny, nx));
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    visit = vector<vector<bool>>(n, vector<bool>(n));
    d_visit = vector<vector<bool>>(n, vector<bool>(n));
    a = vector<vector<ll>>(n,vector<ll>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'R') {
                a[i][j] = 1;
            }
            else if (s[j] == 'B') {
                a[i][j] = 3;

            }
            else a[i][j] = 2;//G
        }
    }
    ll disease_result = 0;
    ll result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll curcolor = a[i][j];
            if (!d_visit[i][j]) {
                bfs(i, j, true, curcolor);
                disease_result += 1;
            }
            if (!visit[i][j]) {
               bfs(i, j, false, curcolor);
               result += 1;
            }
        }
    }
    cout << result << " " << disease_result;
}