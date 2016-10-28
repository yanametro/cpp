#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i; j < v.size(); ++j) {
            if (v[i] > v[j]) {
                swap(v[i], v[j]);
            }
        }
    }
}

void print(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> v;
    
    int a;
    while (cin >> a) {
        v.push_back(a);
    }
    
    sort(v);
    print(v);
    
    return 0;
}
