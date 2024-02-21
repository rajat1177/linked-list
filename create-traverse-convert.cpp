#include <iostream>
#include <vector>
using namespace std;
class node{
    public:
    int data;
    node* link;
    public:
    node(int data1,node* link1) {
        data=data1;
        link=link1;
    }
    public:
    node(int data1) {
        data=data1;
        link=nullptr;
    }
};
node* convertarr2LL(vector<int> v) {
    node* head=new node(v[0]);
    node* mover=head;
    for(int i=1;i<v.size();i++){
        node* temp=new node(v[i]);
        mover->link=temp;
        mover=temp;
    }
    return head;
}
void travesal(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"\n";
        temp=temp->link;
    }
}
int main() {
    vector<int> v={1,2,3,4,5};
    node* head=convertarr2LL(v);
    travesal(head);
    

    return 0;
}