﻿#include<iostream>
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
ll n, t, m, k, test;
ll gcd(ll a, ll b) {
    ll c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
ll lcd(ll a,ll b) {
    return a * b / gcd(a, b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	int test = 0;
	cin >> test;
	int* a = new int[test];
	for (int i = 0; i < test; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < test; i++) {
		cout << (a[0] / gcd(a[i], a[0])) << "/" << (a[i] / gcd(a[i], a[0])) << "\n";
	}
	delete[]a;

}