#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

class linked_list{
private:
	node *head,*tail;
public:
	linked_list(){
		head=NULL;
		tail=NULL;
	}
	void add_node(int n){
		node *temp= new node;
		temp->data=n;
		temp->next=NULL;

		//if first node
		if(head==NULL){
			head=temp;
			tail=temp;
		}
		else{
			tail->next=temp;
			tail=tail->next;
		}
	}

	void insert(node* temp,int pos, int data1){
		for(int i=0;i<=pos;i++){
			temp=temp->next;
		}	
		node* next_temp=new node;
		next_temp->next =temp->next;
		temp->next=next_temp;
		next_temp->data=data1;
	}
	node* getHead(){
		return head;
	}
	node* gettail(){
		return tail;
	}
	void printlist(node* head){
		if(head==NULL){
			cout<< "EOF";
		}
		else{
			cout<<head->data<<endl;
			printlist(head->next);
		}
	}
	void concat(node* l1,node* l2){
		l1->next=l2;
	}

};

//Main
int main(){
	linked_list a;
	a.add_node(10);
	a.add_node(11);
	linked_list b;
	b.add_node(12);
	b.add_node(13);
	a.concat(a.gettail(),b.getHead());
	a.printlist(a.getHead());
	a.insert(a.getHead(),2,110);
	a.printlist(a.getHead());
	return 0;
}






