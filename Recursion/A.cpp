
#include <iostream>
#include <vector>

using namespace std;


void func(int start, int k, vector<int>& combination) {

    if (combination.size() == k) {
        for(int i=0;i<k;i++){
            if(i==k-1) cout<<combination[i];
            else cout<<combination[i]<<" ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i >= 0; --i) {
        combination.push_back(i);
        func(i - 1, k, combination);
        combination.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> combination;
    func(n-1, k, combination);
    return 0;
}
