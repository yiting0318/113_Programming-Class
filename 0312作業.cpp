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
        
        cout<<"��J�ǥ�"<<i+1<<"���y���B�m�W�B�������魫"<<endl;
		
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
            if(p->read_no() < head->read_no()) //���̫e�� 
            {
            	p->write_ptr(head);
                head = p;
                h = head;
                b = head;
                i++;
			}
			else  //�Ʀr��᭱ 
			{	
				b = head;
				h = head;
				
				while (b->read_ptr() != NULL && p->read_no() > b->read_no()) 
                {
                    h = b;
                    b = b->read_ptr();
                }

                if (p->read_no() == b->read_no()) // �y������
                {
                    cout << "�y�����ơA�Э��s��J�C"<<endl; 
                }
				
				else if (b->read_ptr() == NULL && p->read_no() > b->read_no()) //�b�̫�@�� 
				{
					b->write_ptr(p);
					p->write_ptr(NULL);
					i++; 
				}
				
				else //�@�몺���J���� 
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
		cout<<"�ǥ�"<<s+1<<": �y��:"<<head1->read_no()<<", �m�W:"<<head1->read_name();
		cout<< ", ����:" << head1->read_h()<<"����";
		cout<< ", �魫:" << head1->read_w() <<"����"<< endl;
		s++;
        head1 = head1->read_ptr();
    }
}
