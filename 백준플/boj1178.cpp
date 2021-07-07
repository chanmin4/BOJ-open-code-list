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
#include<cassert>
#define fup(i,a,b,c) for(int i=a;i<=b;i+=c)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, m, t, l, c;
vector<vector<ll>>adj;
vector<bool>visit;
vector<ll>degree;
ll dfs(ll cur) {
    ll temp = degree[cur] % 2;
    visit[cur] = true;
    for (ll next : adj[cur]) {
        if (!visit[next]) {

            temp+=dfs(next);
        }
    }
    return temp;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll v, e;
    cin >> v >> e;
    adj = vector<vector<ll>>(v + 1);
    visit = vector<bool>(v + 1);
    degree = vector<ll>(v + 1);
    priority_queue<ll>connect;
    for (int i = 0; i < e; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    
    for (int i = 1; i <= v; i++) {
        if (!visit[i]) {
            ll temp=dfs(i);
            connect.push(temp);
        }
    }
    //최소 간선연결 (컴포넌트끼리 합침)
    ll result = 0;
    while (connect.size() >= 2) {
        ll first = connect.top();
        connect.pop();
        ll second = connect.top();
        connect.pop();
        ll check = 0;
        if (first > 0 && second > 0)check = first + second - 2;
        else if (first > 0 && second == 0)check = first; //second 컴포넌트 냅둠
        else if (first == 0 && second == 0)check = 2;//연결함으로써 홀수 2개생김
        result++;
        connect.push(check);
    }
    //최종 한그룹내 간선연결해서 홀수 정점2개이하로
    if (connect.top() > 2)result += (connect.top() - 2) / 2;
    cout << result;
}