#include <iostream>

using namespace std;

class Node{
public:
	Node(){left = NULL;right = NULL;};
	Node(int);
	int data;
	Node* left;
	Node* right;
};

Node::Node(int d){
	d = data;
	left = NULL;
	right = NULL;
}

class LinkedList{
public:
	LinkedList(){head = new Node; head->data = 0;};
	Node* head;
	void additem(int);
	void printit();
};


void LinkedList::additem(int item){
	int dat = item;
	//cout<<"data"<<dat<<endl;
	Node* newnode = new Node;
	newnode->data = dat;
	//cout<<"dat"<<newnode->data<<endl;
	if (dat>0){
		if (head->right==NULL){
			head->right = newnode;
			newnode->left = head;
			//cout<<"yes1"<<endl;
		}
		else{
			Node* check = head->right;
			while (check->right != NULL){
				check = check->right;
			}
			check->right = newnode;
			newnode->left = check;
			//cout<<"yes2"<<endl;
		}
	}
	else{
		if (head->left==NULL){
			head->left = newnode;
			newnode->right = head;
			//cout<<"yes3"<<endl;
		}
		else{
			Node* check = head->left;
			while (check->left != NULL){
				check = check->left;
			}
			check->left = newnode;
			newnode->right = check;
			//cout<<"yes4"<<endl;
		}
	}
}

void LinkedList::printit(){
	Node* check = head;
	while (check->left!=NULL){
		check = check->left;
		//cout<<"and1"<<endl;
	}
	while (check!= head){
		cout<<check->data<<endl;
		check = check->right;
		//cout<<"and2"<<endl;
	}

	while (check->right!=NULL){
		check = check->right;
		//cout<<"and3"<<endl;
	}
	while (check->left != head){
		cout<<check->data<<endl;
		check = check->left;
		//cout<<"and4"<<endl;
	}
	
}


int main(){
	LinkedList L;
	int d;
	while (d != 0){
		cout<<"Data: ";
		cin>>d;
		if (d!=0){
			L.additem(d);
		} else {
			break;
		}
		//cout<<"Thanks!"<<endl;
	}
	L.printit();
	return 0;
}