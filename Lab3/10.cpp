#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    void push(int value) {
        elements.push_back(value);
    }

    void pop() {
        if (!empty()) {
            elements.pop_back();
        }
    }

    int top() const {
        if (!empty()) {
            return elements.back();
        }
        return 0;
    }

    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }

    vector<int> getElements() const {
        return elements;
    }
};

class Collisions {
private:
    vector<int> arr;
    Stack stack;

public:
    Collisions(vector<int>& arr) {
        this->arr = arr;
    }
    vector<int> solve() {
        for (int i=0;i<arr.size();i++) {
            int current=arr[i];
            bool destroyed=false;

            while(!stack.empty()&&stack.top()>0&&current<0){
                if(stack.top()<-current) {
                    stack.pop();
                    continue;
                } else if (stack.top()==-current) {
                    stack.pop();
                    destroyed=true;
                    break;
                } else {
                    destroyed=true;
                    break;
                }
            }
         if (!destroyed) {
                stack.push(current);
            }
        }
        return stack.getElements();
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Collisions collide(arr);
    vector<int> result = collide.solve();

    for (int value : result) {
        cout << value << " ";
    }
    
    return 0;
}
