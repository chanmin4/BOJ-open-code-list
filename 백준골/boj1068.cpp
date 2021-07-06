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
vector<vector<ll>>child;
ll sizenode = 0;
vector<bool>visit;
void inorder(ll index) {
    visit[index] = true;
    for (int i = 0; i < child[index].size(); i++) {
        inorder(child[index][i]);
    }
}
void inorder2(ll index) {
    if (child[index].size() == 0 && !visit[index])sizenode++;
    for (int i = 0; i < child[index].size(); i++) {
        inorder2(child[index][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll root = 0;
    vector<ll>p(n + 1);
    child = vector<vector<ll>>(n + 1);
    visit=vector<bool>(n, false);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        p[i] = x;
        if(x!=-1)
        child[x].push_back(i);
        if (x == -1) {
            root = i;
        }
    }
    ll num = 0;
    cin >> num;
    inorder(num);
    if (num != root) {
        if (child[p[num]].size() == 1)sizenode++;
    }
    inorder2(root);
    cout << sizenode;
}