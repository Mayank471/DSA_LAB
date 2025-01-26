#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void RollingDice(int n, vector<int> diceRolls){
        vector<int> players;
        for (int i=0;i<n;i++) players.push_back(i+1);
        int currentPlayer= 0;

        for(int i=0;i<diceRolls.size();i++){
            int roll=diceRolls[i];
            currentPlayer = (currentPlayer + roll) % players.size();
            
            cout << roll << " " << players[currentPlayer] << endl;
            
            players.erase(players.begin() + currentPlayer);
            if(currentPlayer==players.size())currentPlayer=0;
        }
        cout<<players.front()<<endl;
    }
};

int main() {
    int n;
    cin>>n;

    // The array to store the dice rolls
    vector<int> diceRolls(n - 1);

    // Input dice rolls
    for (int i = 0; i < n - 1; i++) {
        cin>>diceRolls[i];
    }

    Solution s;
    s.RollingDice(n,diceRolls);



    return 0;
}
