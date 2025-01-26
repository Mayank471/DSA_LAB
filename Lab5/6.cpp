#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL){}
};

class linkedList{
    public:
    ListNode * head;
    linkedList(){
        head=NULL;
    }
    void append(int val){
        ListNode * temp=head;
        ListNode * current= new ListNode(val);
        if(!temp){
            head =current;
        }
        else{
            while(temp -> next){
                temp =temp -> next;
            }
            temp -> next= current;
        }
    }
};

ListNode* sort(ListNode* head) {
    vector<int> arr;
    while(head){
        arr.push_back(head-> val);
        head= head -> next;
    }
    sort(arr.begin(), arr.end());
    arr.push_back(INT_MAX);
    for(int j=0; j<arr.size(); j++){
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i]==arr[i+1]){
            int k=1;
            while(1){
                if(arr[i]==arr[i+k+1])k++;
                else break;
            }
            arr.erase(arr.begin()+i ,arr.begin()+i +k+1);
        }
    }
    }
    int i=0;
    linkedList answer;
    if(arr.size()>1){
        arr.pop_back();
    while(i<arr.size()){
        answer.append(arr[i++]);
    }
    return answer.head;}
    else{
        return NULL;
    }
}

// Function to print the elements of a singly-linked list
void print(ListNode* head) {
// Implement this function to print the elements of the linked list.
    ListNode * temp= head;
    while(temp){
        cout<<temp ->val<<" ";
        temp = temp -> next;
    }
   }

int main() {

// Declare necessary variables.
    string s;
    cin>>s;
    linkedList L;
    int i=0;
    while(i<s.length()){
        L.append(s[i++]-'0');
    }
    print(L.head);
    ListNode * temp =sort(L.head);
    cout<<endl;
    print(temp);
    return 0;

}