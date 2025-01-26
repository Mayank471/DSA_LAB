#include <bits/stdc++.h>
using namespace std;

class AliceAndBobTwo {
public:
    void gameSolver() {
        int t;
        cin >> t; 
        while (t--) {
            int n;
            cin >> n; 
            vector<int> arr(n); 
            for (int i = 0; i < n; i++) cin >> arr[i];
            
            sort(arr.begin(), arr.end());
            
            if (n % 2 == 0) {
                int mid_index = n / 2; 
                cout << arr[mid_index] << endl; 
            } else {
                int mid_index = (n - 1) / 2; 
                cout << arr[mid_index] << endl; 
            }
        }
    }
};

int main() {
    AliceAndBobTwo game;
    game.gameSolver();
    return 0;
}