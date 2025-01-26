#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class SubListFinder {
public:
    SubListFinder(const T* arr) : arr(arr), n(strlen(arr)) {}

    void findSublists() const {
        bool found=false;
        for (int i=0;i< n-1; i++) {
            if(arr[i]==arr[i+1]){
                cout<<arr[i]<<arr[i+1]<<", ";
                found=true;
            }
            if (i<n-2&&arr[i]==arr[i+2]){
                cout<<arr[i]<<arr[i+1]<<arr[i+2]<<", ";
                found=true;
            }
        }
        if (found) {
            cout << endl;
        } 
    }

private:
    const T* arr;
    int n;
};

int main() {
    char input[100001];
    cin >> input;
    SubListFinder<char> finder(input);
    finder.findSublists();

    return 0;
}
