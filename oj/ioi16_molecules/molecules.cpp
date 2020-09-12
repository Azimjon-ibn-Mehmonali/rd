#include "molecules.h"
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<long long> vi;
typedef vector<pair<long long, long long>>  vii;
 
std::vector<int> find_subset(int l, int r, std::vector<int> w) {
    int n = w.size();
    vii a(n);
    for (int i = 0; i < n; i++)
        a[i] = {w[i], i};
    
    sort(a.begin(), a.end());
 
    ll tl, tr, yi;
    tl = tr = yi = 0;
 
    for (;tr < n; tr++) {
        yi += a[tr].first;
        while (yi > r) {
            yi -= a[tl++].first;
        }
        if (yi >= l) {
            vector<int> jv;
            for (int k = tl; k <= tr; k++)
                jv.push_back(a[k].second);
            return jv;
        }
    }
 
    return vector<int>();
}