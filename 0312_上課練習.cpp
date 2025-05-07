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
    st* h = NULL; 
    st* b = NULL;
    
    int i = 0;

    while (i < 5) 
	{
        st* p = new st;
        int x;
        cout << "輸入學生" << i + 1 << "座號" << endl;
        cin >> x;
        p->write_no(x);
        p->write_ptr(NULL); 

        if (head == NULL) 
		{
            head = p;
            h = p;
            b = p;
            i++;
            
        } 
		else 
		{
            if(p->read_no() < head->read_no()) //放到最前面 
            {
            	p->write_ptr(head);
                head = p;
                h = head;
                b = head;
                i++;
			}
			else  //數字放後面 
			{	
				b = head;
				h = head;
				
				while (b->read_ptr() != NULL && p->read_no() > b->read_no()) 
                {
                    h = b;
                    b = b->read_ptr();
                }

                if (p->read_no() == b->read_no()) // 座號重複
                {
                    cout << "座號重複，請重新輸入。\n";
                    delete p;
                }
				
				else if (b->read_ptr() == NULL && p->read_no() > b->read_no()) //在最後一個 
				{
					b->write_ptr(p);
					p->write_ptr(NULL);
					i++; 
				}
				
				else //一般的插入中間 
				{
					p->write_ptr(b);
					i++;
				}	
            	
			}
        	
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
