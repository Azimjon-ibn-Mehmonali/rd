#include "split.h"
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<int> find_split(int n, int a, int b, int c, vector<int> p, vector<int> q) {
	int m = p.size();
	vector<vi> g(n, vi());

	for (int i = 0; i < m; i++) {
		g[p[i]].push_back(q[i]);
		g[q[i]].push_back(p[i]);
	}

	vi jv(n, 0);

	
	return jv;
}
