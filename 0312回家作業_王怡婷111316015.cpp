#include <iostream>
#include <cstring>
using namespace std;

class st 
{
    int no;
    char name[100];
	int h;
	int w;
	st* p;

public:
    void write_no(int x) { no = x; }
    int read_no() { return no; }
    
    void write_name(char*u){strcpy(name,u);}
	char* read_name(){return name;}
	
	void write_h(int y){h=y;}
	int read_h(){return h;}
	
	void write_w(int z){w=z;}
	int read_w(){return w;}

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
        int x,y,z;
        char u[100];
        
        cout<<"輸入學生"<<i+1<<"的座號、姓名、身高及體重"<<endl;
		
        cin>>x;
		cin.get();
		cin.getline(u,80);
		cin>>y;
		cin>>z;
		
        p->write_no(x);
        p->write_name(u);
        p->write_h(y);
        p->write_w(z);
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
                    cout << "座號重複，請重新輸入。"<<endl; 
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
                    h->write_ptr(p); 
					i++;
				}	
            	
			}
        	
        }
    }

    
    st* head1 = head;
    int s=0;
    while (head1 != NULL) 
	{
		cout<<"學生"<<s+1<<": 座號:"<<head1->read_no()<<", 姓名:"<<head1->read_name();
		cout<< ", 身高:" << head1->read_h()<<"公分";
		cout<< ", 體重:" << head1->read_w() <<"公斤"<< endl;
		s++;
        head1 = head1->read_ptr();
    }
}
