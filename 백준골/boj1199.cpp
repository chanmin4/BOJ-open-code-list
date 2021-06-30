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
//오일러 기본 연습코드
struct edge {
    ll to, cnt;
    edge* reverse;
    edge(ll to,ll cnt) {
        
        this->to = to;
        this->cnt = cnt;
    }
};
int degree[1000];
vector<edge*> adj[1000];
bool visited[1000];
ll comp(ll cur) {
    ll result = 1;
    visited[cur] = true;
    for (edge*e:adj[cur]) {
        ll next = e->to;
        if (!visited[next])result += comp(next);
    }
    return result;
}
void eulerian(ll cur) {
    for (edge* e : adj[cur]) {
        if (e->cnt > 0) {
            e->cnt--;
            e->reverse->cnt--;
            eulerian(e->to);
        }
    }
    cout << cur + 1 << " ";
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll num;
            cin >> num;
            if (j > i && num > 0) {
                edge* e1 = new edge(j, num);
                edge* e2 = new edge(i, num);
                e1->reverse = e2;
                e2->reverse = e1;
                adj[i].push_back(e1);
                adj[j].push_back(e2);
                degree[i] += num;
                degree[j] += num;
            }
        }
    }
    //무향 차수홀수 정점2개일때 오일러 경로 0개 오일러 회로
    //유향 모든정점에대해 indegree outdegree 같으면 회로존재 경로는 
    //이조건만족하면서 indegree 1적은 정점 (시작점) outdegree 1적은 정점 (끝점)
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 == 1) {
            cout << -1;
            return 0;
        }
    }
    bool check = false;
    ll start = -1;
    //컴포넌트 크기2 2개이상 불가능
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ll compsize = comp(i);
            if (compsize > 1) {
                if (check) {
                    cout << -1;
                    return 0;
                }
                else {
                    check = true;
                    start = i;
                }
            }
        }
    }
    if (start == -1)start = 0;//전부 size=1
    eulerian(start);
}