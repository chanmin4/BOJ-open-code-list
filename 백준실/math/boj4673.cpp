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
int selfn(int);
int plusmaker(int);
int plusmaker(int A) {
	int sum = 0;
	while (A != 0) {
		sum += A % 10;
		A = A / 10;
	}
	return sum;
}
int selfn(int B) {
	int c = 0;
	for (int i = 0; i < 10000; i++) {//검산
		if ((B + 1) == (plusmaker(i + 1) + i + 1)) {//생성자존재
			c++;
		}
		if (B + 1 < i + 1) {
			break;
		}
	}
	if (c == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<int>A(10000);
	int j = 0;
	int c = 0;
	int size = 0;
	for (int i = 0; i < 10000; i++) {

		if (selfn(i) == 1) {
			A[j] = i + 1;
			j++;
		}
	}
	while (A[c] != NULL) {
		c++;

	}
	size = c;
	for (int i = 0; i < size; i++) {
		cout << A[i] << endl;
	}
}