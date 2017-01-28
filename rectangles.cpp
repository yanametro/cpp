#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// True, если p1 < p2,
// False, иначе
bool myComp(pair<long long, long long> p1,
            pair<long long, long long> p2) {
    long long s1 = p1.first * p1.second;
    long long s2 = p2.first * p2.second;
    if (s1 == s2) {
        return p1.first < p2.first;
    }
    return s1 < s2;
}

int main() {
    //std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<long long, long long> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.rbegin(), v.rend(), myComp);
    
    for (int i = 0; i < n; ++i) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}
