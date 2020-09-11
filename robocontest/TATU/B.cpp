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
#define debug(a) cout << #a << " = " << a << endl;
#define jsatr debug(__LINE__)
#define INF 1000000000
#define mod 1000000007


int n, k;

bool mos(int a) {
	for (int i = 1; i <= n; i++) {
		if (a % n == k) {
			a -= k;
			a -= a / n;
		}
		else
			return 0;
	}
	
	return 1;
}


int main()
{
	int n, k;
	cin >> n >> k;
	
	int b = n * n + 1;
	
	for (int i = 1; i <= n - 1; i++) {
		b = b * n / (n - 1) + 1;
	}
	
	cout << b << endl;
	
    return 0;
}
