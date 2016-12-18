pair<int, int> partition(vector<int>& v, int l, int r) {
    int i = l, j = r - 1;
    int p = v[i + rand() % (r - l)];
    while (j >= i) {
        while (v[i] < p) {
            ++i;
        }
        while (v[j] > p) {
            --j;
        }
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    return make_pair(i, j);
}

void qSort(vector<int>& v, int l, int r) {
    pair<int, int> m = partition(v, l, r);
    
	if (m.first < r) {qSort(v, m.first, r);}
	if (m.second > l) {qSort(v, l, m.first);}
}
