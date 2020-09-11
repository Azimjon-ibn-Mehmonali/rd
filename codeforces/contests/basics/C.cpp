
// Problem : C. The Number of Products
// Contest : Codeforces - OCS - Round 1 (Basics)
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define sqr(x) (x) * (x)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define sc scanf
#define pr printf
#define debug(a) cerr << #a << " = " << a << endl;
#define jsatr debug(__LINE__)
#define INF 1000000000
#define mod 1000000007

int main() {
	int n;
	sc("%d", &n);

	vi a(n);
	for (int &i : a)
		sc("%d", &i), i = i > 0 ? 1 : -1;

	int jv1, jv2;
	jv1 = jv2 = 0;

	int i, j;
	i = 0;
	j = find(ALL(a), -1) - a.begin() + 1;
	// jv1 += j;

	for (int k = j; k < n; k++) {
		if (a[k] == -1) {
			jv1 += k - i;
			i = j;
			j = k + 1;
		}
	}

	cout << jv1 << " ";

	return 0;
}
