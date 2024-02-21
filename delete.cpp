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
void travesal(node* &head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}
node* deletebeg(node*head){
    if(head==nullptr) return head;
    node*temp=head;
    head=temp->link;
    delete temp;
    return head;
}
node* deletetail(node*head){
    if(head==nullptr||head->link==nullptr) return nullptr; //2 conditions
    node*temp=head;
    while(temp->link->link){
        temp=temp->link; 
    }
    temp->link=nullptr;
    temp=temp->link;
    delete temp;
    return head;
}
node* deletefromkthposition(node*head,int k){
    if(head==nullptr) return head;
    if(k==1){
        node*temp=head;
        head=temp->link;
        delete temp;
        return head;
    }
    int count=0;
    node* temp=head;
    node* prev=nullptr;
    while(temp){
        count++;
        if(count==k){
            prev->link=temp->link;
            break;
        }
        prev=temp;
        temp=temp->link; 
    }
    delete temp;
    return head;
}
node* deletebyvalue(node*head,int value){
    if(head==nullptr) return head;
    if(head->data==value){
        node*temp=head;
        head=temp->link;
        delete temp;
        return head;
    }
    
    node* temp=head;
    node* prev=nullptr;
    while(temp){
        
        if(temp->data==value){
            prev->link=temp->link;
            break;
        }
        prev=temp;
        temp=temp->link; 
    }
    delete temp;
    return head;
}


int main() {
    vector<int> v={1,2,3,4,5};
    node* head=convertarr2LL(v);
    // head=deletebeg(head); 
    // head=deletetail(head); 
    // head=deletefromkthposition(head,2); 
    // head=deletebyvalue(head,5);
    travesal(head);
    return 0;
}