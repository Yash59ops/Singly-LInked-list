#include<iostream>
using namespace std;
class linked_list {
    struct node {
        int data;
        node*next;
    };
    node*start;
  public:
    linked_list() {
        start=NULL;
    }
    void inseratstart(int data) {
        node*n=new node;
        n->data=data;
        n->next=start;
        start=n;
    }
    void insertatlast(int data) {
        node*n=new node;
        n->data=data;
        n->next=NULL;
        if(start==NULL) {
            start=n;
        } else {
            node*t=start;
            while(t->next!=NULL) {
                t=t->next;
            }
            t->next=n;
        }
    }
    void display() {
        node*t=start;
        cout<<"NULL";
        while(t!=NULL) {
            cout<<"->"<<t->data;
            t=t->next;
        }
    }
    node* search(int data) {
        node*t=start;
        while(t!=NULL) {
            if(t->data==data) {
                return t;
            }
        }
        return NULL;
    }
    void deleteatstart() {
        node*t;
        if(start==NULL) {
            cout<<"empty list";
        } else {
            t=start;
            start=t->next;
            delete t;
        }
    }
    void deleteatlast() {
        node*t;
        t=start;
        while(t->next->next!=NULL) {
            t=t->next;
        }
        t->next=NULL;
    }
//insertatindex();
//void operator+(linked_list k){
//node*t=start;
//while(t->next!=NULL){
//    t=t->next;
//}
//t->next=k.start;
//}
//reversealinkedlist
    void alternate() {
        node*t=start;
        while(t->next!=NULL) {
            cout<<t->data;
            t=t->next->next;
        }
    }
    node*recursivelyreversedalinkedlist(node*start) {
        node*t=start;
        if(t==NULL||t->next==NULL) {
            return t;
        }

        node*s=recursivelyreversedalinkedlist(t->next);
        t->next->next=t;
        t->next=NULL;
        start=s;
        //cout<<"1";
        return s;
    }
    void rec(){
        start=recursivelyreversedalinkedlist(start);
    }
    node*reversealinkedlist(node*start1) {
        node*cur=start1;
        node*prev=NULL;
        node*nextnode=NULL;
        while(cur!=NULL) {
            nextnode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextnode;
        }
        return prev;
    }
    void check_palindrome() {
        node*slow=start;
        node*fast=start;
        while(fast!=NULL&&fast->next!=NULL) {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reversealinkedlist(slow->next);
        slow=slow->next;
        node*t=start;
        int c=0;
        while(slow!=NULL) {
            if(slow->data!=t->data) {
                c++;
            }
            slow=slow->next;
            t=t->next;
        }
        if(c==0) {
            cout<<"palindrome";
        } else {
            cout<<"not";
        }
    }
//int *arr=new int[100];
//int i=0;
//node*t=start;
//while(t!=NULL){
//    arr[i]=t->data;
//    i++;
//    t=t->next;
//}
//int j;
//t=start;
//int c=0;
//for(j=i-1;j>=0;j--)
//{
//if(arr[j]!=t->data){
//    c++;
//    break;
//}
//t=t->next;
//}
//if(c>0)
//{
//    cout<<"not palindrome";
//}else{
//cout<<"palindrome";
//}
~linked_list(){
delete start;
}

};

int main() {
    linked_list obj;
    obj.insertatlast(1);
    obj.insertatlast(2);
    obj.insertatlast(3);
    obj.insertatlast(4);
    obj.insertatlast(5);

//obj.deleteatstart();
//obj.deleteatlast();
//obj.deleteatlast();
//obj.display();
//obj.alternate();
//bj.display();
//obj.check_palindrome();
//recursivelyreversedalinkedlist();
    //obj.rec();
obj.r();
    obj.display();

    return 0;
}




