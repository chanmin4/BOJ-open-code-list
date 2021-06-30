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
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //n-정렬된수-1 보다 s남은양크면 정렬됨
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll s;
    cin >> s;
    ll sortednum = 0;
    vector<ll>result(n);
    bool check = false;
    while (s>0) {
        ll maxi = 0;
        ll maxipos = 0;
        for (int i = sortednum; i <=sortednum+s; i++) {
            if (i >= n)break;
            if (maxi < a[i]){
                maxi = a[i];
                maxipos = i;
            }
        
        }
        result[sortednum] = a[maxipos];
        if (maxipos - sortednum <= s) {
            s -= maxipos - sortednum;
            for (int i = maxipos; i >=sortednum+1; i--) {
                swap(a[i], a[i - 1]);
            }
        }
        else {
            check = true;//일부만정렬됨
            break;
        }
        sortednum++;
        if (sortednum == n) {
            break;
        }
    }
    if (check) {
        ll maxipos = sortednum;
        ll maxi = a[sortednum];
        for (int i = sortednum+1; i <=sortednum+s; i++) {
            if (maxi < a[i]) {
                maxi = a[i];
                maxipos = i;
            }
        }
        result[sortednum] =a[maxipos];
        for (int i = maxipos; i >= sortednum + 1; i--) {
            swap(a[i], a[i - 1]);
        }
        sortednum++;
        
    }
    for (int i = sortednum; i < n; i++) {
        result[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
}