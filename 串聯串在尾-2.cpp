#include <iostream>
#include <cstring>
using namespace std;

class st 
{
    int no;
    st* p;

public:
    void write_no(int x) { no = x; }
    int read_no() { return no; }

    void write_ptr(st* ptr) { p = ptr; }
    st* read_ptr() { return p; }
};

int main() 
{
    st* head = NULL; 
    st* tail = NULL; 

    for (int i = 0; i < 5; i++) 
	{
		if (head == NULL) 
		{
			st* p = new st;
        	int x;
        	cout << "輸入學生" << i + 1 << "座號" << endl;
        	cin >> x;
        	p->write_no(x);
        	p->write_ptr(NULL); 
        	head = p;
            tail = p;
        	
		}
		else
		{
			st* p = new st;
	        int x;
	        cout << "輸入學生" << i + 1 << "座號" << endl;
	        cin >> x;
	        p->write_no(x);
	        p->write_ptr(NULL); 
	        
	        tail->write_ptr(p);
	        tail = p; 
		}
    }

    
    st* head1 = head;
    while (head1 != NULL) 
	{
        cout << head1->read_no() << " -> ";
        head1 = head1->read_ptr();
    }

    cout << "NULL" << endl; 
}
