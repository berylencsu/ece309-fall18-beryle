#include <stdio.h>
//Benjamin Ryle
//ECE-309-001
//implemented linked list
class linked_list 
{
	private:
	int numitems;
	class node 
	{
	public:
	   char* Item; // data in the list
	   node* next;	
	   node(char* a) 
		  { Item = a; next=NULL; }
	   node* getNext() { return next; }
	   void setNext(node* n) { next = n; }
	   char* getItem() { return Item; }
	};
	public:
	node* tail=NULL;
	node* head=NULL;
	
	void push_back(char* a) 
	{
		numitems++;
		
		node* working_node = new node(a);
		if (head==NULL) 
		{ 
		   // list is empty, so set head and 
		   // tail to be node
		   head = working_node;
		   tail = working_node;
		} else 
			
			{
				working_node->Item=a;
				tail->next=working_node;
				tail=working_node;
			}
		
		
		/*{
		  // put new node at end of list
		  tail.setNext(working_node);
		  tail = working_node;
		}*/
	}

	char* get(int n)
	{
		int i;
		//char gotten;
		node* loop = head;
		for (i=n; i>0; i++)
		{
			loop=loop->next;
		}
		return loop->getItem();
	}
	

	int length()
	{
		return numitems; 
	}
	
	char* remove_front()
	{
		numitems--;
		node* temp=head;
		head = head->next;
		return temp->getItem();
	}
	
	linked_list(){numitems=0;}
	
	~linked_list(){
		node* temp = head;
		while(temp->Item!=NULL){
		temp->Item=NULL;
		temp=temp->next;
		}
		head->Item=NULL;
	}
};
