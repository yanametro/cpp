int lower_bound(const vector<int>& v, int x) {
    int l = -1;
    int r = v.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (v[m] >= x) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

