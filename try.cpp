#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class linked_list{
private:
	node *head;
public:
	linked_list(){
		head=NULL;
	}
	void insert(int n){
		node* temp= new node;
		node* ptr=head;
		temp->data=n;
		temp->next=head;
		if(head==NULL){
			temp->next=temp;
			head=temp;
		}
		else{
			while(ptr->next!=head){
				ptr=ptr->next;
			}
			ptr->next=temp;
		}
		
	}
	void remove_adj(node* node){
	    if(node == node->next || node->next == head){
	        return;
	    }
	    if(node->data == node->next->data){
	        node->next = node->next->next;
	        remove_adj(node);}
	    else{
	        remove_adj(node->next);
	    }
	}
	void finish(){
		node* ptr=head;
		node* prev;
		ptr=ptr->next;
		while(ptr->next!=head){
			prev=ptr;
			ptr=ptr->next;
		}
		if(ptr->data==head->data){
			prev->next=head;
		}
	}
	node* getHead(){
		return head;
	}
	void display(node* head){
		node* ptr= head;
		do { 
	      cout<<ptr->data <<" "; 
	      ptr = ptr->next; 
   		} while(ptr != head);

	}
};

int main(){
	linked_list a;
	a.insert(1);
	a.insert(1);
	a.insert(2);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(1);
	a.insert(1);
	a.remove_adj(a.getHead());
	a.finish();
	a.display(a.getHead());
}