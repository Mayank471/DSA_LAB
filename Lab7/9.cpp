#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pokemons(n);
    for(int i = 0; i < n; i++) cin >> pokemons[i];

    int rounds = 1;
    for(int i = 1; i < n; i++) {
        if(pokemons[i] < pokemons[i-1]) rounds++;
    }
    cout << rounds << endl;
    return 0;
}
