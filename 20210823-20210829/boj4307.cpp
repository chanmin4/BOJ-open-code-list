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
ll n, t, m, k, test;
void fibo(int num, int l, int a[]) {
	vector<int>hi;
	int center = l / 2;
	int max = -1;
	int min = l + 1;
	for (int i = 0; i < num; i++) {
		if (a[i] < center) {
			hi.push_back(a[i]);
			if (l - a[i] > max) {
				max = l - a[i];
			}
		}
		else if (a[i] >= center) {
			hi.push_back(l - a[i]);
			if (a[i] >= max) {
				max = a[i];
			}
		}
	}
	cout << *max_element(hi.begin(), hi.end()) << " " << max << "\n";
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	int test = 0;
	cin >> test;
	int l = 0, num = 0;
	for (int i = 0; i < test; i++) {
		cin >> l >> num;
		int* a = new int[num];
		for (int j = 0; j < num; j++) {
			cin >> a[j];
		}
		fibo(num, l, a);
		delete[]a;
	}
}