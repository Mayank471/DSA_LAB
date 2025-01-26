#include <iostream>
using namespace std;

class Game {
private:
    int x; // Number of students
    int n; // Initial student who gets the paper
    int p; // Steps to pass the paper

public:
    Game(int x, int n, int p) : x(x), n(n), p(p) {}

    int findwinner() {
        int lastPosition = 0;
        for (int i=2;i<=x;i++){
            lastPosition=(lastPosition+p)%i;
        }
        return (lastPosition+n)%x+1;
        //code here
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x, n, p;
        cin >> x >> n >> p;
        Game game(x, n, p);
        cout << game.findwinner() << endl;
    }

    return 0;
}
