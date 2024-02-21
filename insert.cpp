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
    if(v.size()==0){                                     //small correction
        return nullptr;
    }
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
node* insertbeg(node*head,int value){
    node* temp=new node(value);
    temp->link=head;
    head=temp;
    return head;
}
node* inserttail(node*head,int value){
    node* newnode=new node(value);
    node* temp=head;
    while(temp->link){
        temp=temp->link;
    }
    temp->link=newnode;
    return head;
}

node* insertatk(node*head,int value,int k){
    
    if(head==nullptr){
        if(k==1){
            return new node(value);
        }
        else{
            return nullptr;
        }
    }
    if(k==1){
        node* temp=new node(value);
        temp->link=head;
        head=temp;
        return head;
    }
    int count=0;
    node* newnode=new node(value);
    node* temp=head;
    while(temp){
        count++;
        if(count==k-1){
            newnode->link=temp->link;
            temp->link=newnode;
            break;

        }
        temp=temp->link;
    }
    return head;
}
node* insertBeforeElement(node*head,int value,int element){
    
    
    if(head->data==element){
        node* temp=new node(value);
        temp->link=head;
        head=temp;
        return head;
    }
    
    node* newnode=new node(value);
    node* temp=head;
    while(temp){
        
        if(temp->link->data==element){
            newnode->link=temp->link;
            temp->link=newnode;
            break;

        }
        temp=temp->link;
    }
    return head;
}



int main() {
    vector<int> v={1,2,3,4,5};
    node* head=convertarr2LL(v);
    // head=insertbeg(head,0);
    // head=inserttail(head,6);
    // head=insertatk(head,50,2);
    head=insertBeforeElement(head,0,5);
    travesal(head);
    return 0;
}