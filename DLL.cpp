#include <iostream>
#include <vector>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* back;
    public:
    node(int val1,node* next1,node* back1) {
        val=val1;
        next=next1;
        back=back1;
    }
    public:
    node(int val1) {
        val=val1;
        next=nullptr;
        back=nullptr;
    }
};
node* convertarr2LL(vector<int> v) {
    node* head=new node(v[0]);
    node* mover=head;
    for(int i=1;i<v.size();i++){
        node* temp=new node(v[i]);
        mover->next=temp;
        temp->back=mover;
        mover=temp;
    }
    return head;
}
void travesal(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->val<<"\n";
        temp=temp->next;
    }
}
int main() {
    vector<int> v={1,2,3,4,5};
    node* head=convertarr2LL(v);
    travesal(head);
    

    return 0;
}