
// Problem : C. Calculus
// Contest : Yandex - Finals
// Memory Limit : 512 MB
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

int main()
{
	string s;
	cin >> s;
	
	int i;
	while (i = s.find("sin"), i != -1)
		s.erase(i, 3);
	while (i = s.find("cos"), i != -1)
		s.erase(i, 3);
	
	debug(s)
	
	set<char> ol;
	
	for (char c: s)
		if ('a' <= c && c <= 'z')
			ol.insert(c);
			
	cout << ol.size() << endl;
	
    return 0;
}
