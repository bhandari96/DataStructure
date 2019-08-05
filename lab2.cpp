// Lab 2 Data Structure

#include<iostream>
using namespace std;

class Node{
	public:	
		Node* next;
		char c;
		Node(char c)
		{
			next = NULL;
			this->c = c;
		}
};

class LinkedChar{
	Node* head;
	
	public:
		int size;
		LinkedChar()
		{
			size = 0;
			head = new Node('*');
		}
		
//constructor 
	LinkedChar(const std::string s)
	{
		size = s.size();
		head = new Node('*');
		Node* curr = head;
		for(int i=0; i<s.size(); i++)
		{
			curr->next = new Node(s[i]);
			curr = curr->next;
		}
	}
	int length() const
	{
		return size;
	}


//to find the first occurence of a character in the list
	int index(char ch) const
	{
		Node* curr = head->next;
		int count = 0;
		while(curr!=NULL)
		{
			if(curr->c==ch)
			return count;
			curr = curr->next;
			count++;
		}
			return -1;
	}


//to append second list to first one
	void append(const LinkedChar& lc)
	{
		Node* curr = head;
		while(curr->next!=NULL)
		curr = curr->next;
		Node* curr2 = lc.getHead();
		curr2 = curr2->next;
		while(curr2!=NULL)
		{
			curr->next = new Node(curr2->c);
			curr = curr->next;
			curr2 = curr2->next;
		}
		size += lc.length();
	}

//function to help the function sub-match
	bool checkMatch(Node* curr1, Node* curr2) const
	{
		while(curr2!=NULL)
		{
			if(curr1->c!=curr2->c)
			return 0;
			curr1 = curr1->next;
			curr2 = curr2->next;
		}

		return 1;
	}

//checks of another list exists as a substring in this list
	bool submatch(const LinkedChar& lc) const
	{
		Node* curr = head->next;
		for(int i=0; i<size-lc.length()+1; i++)
		{
			if(checkMatch(curr, lc.getHead()->next))
			return 1;
			curr = curr->next;
		}
		return 0;
	}

//returns pointer to head node
	Node* getHead() const
	{
		return head;
	}


//prints the string
	void print()
	{
		Node* curr = head->next;
		while(curr!=NULL)
		cout<<curr->c, curr = curr->next;
		cout<<endl;
	}

};

int main()
{
	
	LinkedChar a("America"), b("Australia"), c("Japan");
	a.append(b);
	cout<<"The length of string is " << a.length()<<endl;
	cout<<"The index of characters are " <<endl;
	cout << a.index('b')<<endl;
	cout<<a.index('m')<<endl;
	cout<<a.index('t')<<endl;
	a.print();
	cout<<a.submatch(c)<<endl;
}
