#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int id; node* next;

    node(int ai){
        id = ai; next = NULL;
    }
} node;

class LinkedList{
public:
    node* head; node* last;

    LinkedList(node* h){
        head = h;
        last = h;
    }

    void insert(node* ln){
        last->next = ln;
        last = last->next;
    }

    void DisplayList(){
        for(node* c=head;c;c=c->next) cout << c->id << ' ';
        cout << '\n';
    }

    bool find(node* n){
        for(node* c=head;c;c=c->next)
            if(c==n) return true;
        return false;
    }
};

void printHitForkApart(vector<LinkedList>& L){
    int n = L.size();
    int hitCount=0,forkCount=0,apartCount=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++){
            bool hit=false,fork=false;
            if(L[i].find(L[j].head)||L[j].find(L[i].head)) hit = true;
            if(!hit){
                for(node* c=L[i].head; c !=nullptr;c=c->next){
                    if(c !=L[i].head&&L[j].find(c)){
                        fork=true;
                        break;
                    }
                }
                if(!fork){
                    for(node* c=L[j].head;c!=nullptr;c=c->next){
                        if(c!=L[j].head&&L[i].find(c)){
                            fork=true;
                            break;
                        }
                    }
                }
            }

            if(hit) hitCount++;
            else if (fork) forkCount++;
                else apartCount++;
        
        }
    }

    // Output the results
    cout << hitCount << endl;
    cout << forkCount << endl;
    cout << apartCount << endl;
}

    // for(auto x : L) x.DisplayList();

    // Complete the function now
    // Hint : Use the find method of Linked List


// DO NOT ALTER THE CODE BELOW

int main(){
    int n; cin >> n;

    vector<LinkedList> LL;
    map<int,node*> mp;

    for(int i=0;i<n;i++){
        int m; cin >> m;
        int hid; cin >> hid; m--;
 
        if(mp.find(hid)==mp.end()) mp[hid] = new node(hid);
            LL.push_back(LinkedList(mp[hid]));
    
        while(m--){
            int ai; cin >> ai;
            if(mp.find(ai)==mp.end()) mp[ai] = new node(ai);
            LL[i].insert(mp[ai]);
        }
    }

    printHitForkApart(LL);
    return 0;
}