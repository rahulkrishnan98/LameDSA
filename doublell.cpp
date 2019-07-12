#include <iostream>

using namespace std;

struct node{
	int key;
	node *front;
	node *back;
};

class linked_list{
private:
	node *head,*tail;
public:
	linked_list(){
		head=NULL;
		tail=NULL;
	}
	void printList(){
		if(head==NULL){
			cout<<"Nothing to Print";
			return;
		}
		else{
			node* ptr = new node();
			ptr=head;
			while(ptr->front!=NULL){
				cout<<ptr->key<<endl;
				ptr=ptr->front;
			}
			cout<<ptr->key<<endl;
			return;
		}
	}
	void insert(int n){
		node* newnode= new node();
		newnode->key=n;
		newnode->front=NULL;
		newnode->back=NULL;
		if(head==NULL){
			head=newnode;
			tail=head;
		}
		else{
			node* newnode= new node();
			newnode->key=n;
			newnode->back=tail;
			tail->front=newnode;
			tail=tail->front;
		}
	}
};

int main(){
	linked_list a;
	a.insert(10);
	a.insert(11);
	a.printList();
	return 0;
}