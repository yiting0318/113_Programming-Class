#include <iostream>
#include <string>
using namespace std;

class st_node
{
    int no;
    string name;
	int prg;  // �{���]�p 
	int cmp;  // �p������� 
	int math; // �ƾ� 
	st_node* p;

public:
    void write_no(int x) { no = x; }
    int read_no() { return no; }
    
    void write_name(string n){name = n;}
	string read_name(){return name;}
	
	void write_prg(int y){prg=y;}
	int read_prg(){return prg;}
	
	void write_cmp(int z){cmp=z;}
	int read_cmp(){return cmp;}
	
	void write_math(int w){math=w;}
	int read_math(){return math;}

    void write_ptr(st_node* ptr) { p = ptr; }
    st_node* read_ptr() { return p; }
    
    void operator +(int v)
    {
    	prg = prg + v ; 
	}

};

int memu(int a)
{
	cout<<"     Menu"<<endl; 
	cout<<"   1.Insert"<<endl; //�s�W 
	cout<<"   2.Search"<<endl; //�j�M
	cout<<"   3.Modify"<<endl; //�ק� 
	cout<<"   4.Delete"<<endl; //�R�� 
	cout<<"   5.Print"<<endl;  //�L�X 
	cout<<"   6.Exit"<<endl;
	cout<<"Please Select  one"<<endl;
	cin>>a;
	return a;
}

st_node* Modify(st_node *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x,y,z;
		st_node a;
		st_node* p = new st_node;
		st_node* h = NULL;
    	st_node* b = NULL;
		cout<<"�п�J���ק�{���]�p���Z���ǥͮy��"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head->read_no()) //���ק諸�O�Ĥ@��
		{ 
			cout<<"�ثe���Z: " << head->read_prg()<<"��"<<endl;
			cout<<"�п�J���[�����"<<endl;
			z = head->read_prg();
			cin>>y;
			*head + y;
			cout<<"��s����"<<endl;
			cout<<head->read_no()<<"�������Z�w�q "<<z<<" ����s�� "<<head->read_prg()<<" ��"<<endl;
		} 
		else
		{
			b = head;
			h = head;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // ���o�Ӯy�� 
            {
            	cout<<"�ثe���Z: " << b->read_prg()<<"��"<<endl;
				cout<<"�п�J���[�����"<<endl;
				z = b->read_prg();
				cin>>y;
            	*b + y;
				cout<<"��s����"<<endl;
				cout<<b->read_no()<<"�������Z�w�q "<<z<<" ����s�� "<<b->read_prg()<<" ��"<<endl;
            	cout<<"�п�J���ק諸����"<<endl;
				
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"���y�����s�b!"<<endl;
			}
		}
	}
	return head;
}

st_node* Search(st_node *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x;
		st_node* p = new st_node;
		st_node* h = NULL;
    	st_node* b = NULL;
		cout<<"�п�J���d�߾ǥͪ��y��"<<endl;
		cin>>x;
		p->write_no(x);
	
		if(p->read_no()==head->read_no()) //�d�ߪ��O�Ĥ@��
		{ 
			cout<<"�y��:"<<head->read_no();
			cout<<",�m�W:"<<head->read_name();
			cout<<",�{�]���Z: " << head->read_prg()<<"��";
			cout<<",�p�����Z: " << head->read_cmp()<<"��";
			cout<<",�ƾǦ��Z: " << head->read_math()<<"��"<<endl;
		} 
		else
		{
			b = head;
			h = head;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // ���o�Ӯy�� 
            {
            	cout<<"�y��:"<<b->read_no();
				cout<<",�m�W:"<<b->read_name();
				cout<<",�{�]���Z: " << b->read_prg()<<"��";
				cout<<",�p�����Z: " << b->read_cmp()<<"��";
				cout<<",�ƾǦ��Z: " << b->read_math()<<"��"<<endl;
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"���y�����s�b!"<<endl;
			}
		}
	}
	return head;
}

st_node* Insert(st_node *head)
{
	st_node* p = new st_node;
    st_node* h = NULL;
    st_node* b = NULL;
	int x,y,z,w;
	string n;
	cout<<"�п�J�ǥͮy���B�m�W�ΤT�쪺���Z"<<endl;
	cin>>x;
	cin.get();
	getline(cin,n);
	cin>>y; 
	cin>>z; 
	cin>>w; 
	
	p->write_no(x);
    p->write_name(n);
    p->write_prg(y);
    p->write_cmp(z);
    p->write_math(w);
    p->write_ptr(NULL); 
    
    if (head == NULL) 
		{
            head = p;
            h = p;
            b = p;
        } 
    else 
		{
            
            if(p->read_no() < head->read_no()) //���̫e�� 
            {
            	p->write_ptr(head);
                head = p;
                h = head;
                b = head;
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
                    cout << "�y���w�s�b"<<endl; 
                    return head;
                }
				
				else if (b->read_ptr() == NULL && p->read_no() > b->read_no()) //�b�̫�@�� 
				{
					b->write_ptr(p);
					p->write_ptr(NULL);
				}
				
				else //�@�몺���J���� 
				{
					p->write_ptr(b);
                    h->write_ptr(p); 
				}	
			}
        }   
    return head; 
}


st_node* Delete(st_node *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x;
		st_node* p = new st_node;
		st_node* h = NULL;
    	st_node* b = NULL;
		cout<<"�п�J���R���ǥͪ��y��"<<endl;
		cin>>x;
		p->write_no(x);
	
		if(p->read_no()==head->read_no()) //�R���Ĥ@��
		{ 
			if(head->read_ptr() == NULL) //�쥻�N�u���@����� 
			{
				head = NULL;
				
			}
			else //���u���@�����  
			{
				head=head->read_ptr();
				
			}
			//cout<<" �R�����\ "<<endl;  �����򤣯ॴ�X"�\"�r!!! �𦺤F!! �u�n��X��"�\"�r�N�|���~ QAQ
			cout<<"�R������ "<<endl;
		} 
		else
		{
			b = head;
			h = head;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // ���o�Ӯy�� 
            {
            	if(b->read_ptr() == NULL) //�b�̫�@�� 
            	{
            		h->write_ptr(NULL);
				}
				else //�b��C���� 
				{
					b = b->read_ptr();
                	h->write_ptr(b);
				}
				//cout<<"�R�����\!"<<endl;
				cout<<"�R������ "<<endl;	
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"���y�����s�b!"<<endl;
			}
		}
	}
	return head;
}

void Print(st_node *k)
{
	if(k == NULL)
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	st_node* head1 = k;
    while (head1 != NULL) 
	{
		cout<<"�y��:"<<head1->read_no();
		cout<<",�m�W:"<<head1->read_name();
		cout<<",�{�]���Z: " << head1->read_prg()<<"��";
		cout<<",�p�����Z: " << head1->read_cmp()<<"��";
		cout<<",�ƾǦ��Z: " << head1->read_math()<<"��"<<endl;
        head1 = head1->read_ptr();
    }
}

int main()
{
	int b,c;
	st_node *k = NULL;
	do
	{
		switch(c=memu(b))
		{
			case 1:k = Insert(k);
			break;
			
			case 2:Search(k);
			break;
			
			case 3:k = Modify(k);
			break;
			
			case 4:k = Delete(k);
			break;
			
			case 5:Print(k);
			break;
			
			case 6:cout<<"�P�¨ϥΥ��t�ΡA�w��U���A��^^"<<endl;
			break;
			
			default:cout<<"Wrong select, try again."<<endl;
			break;
		}	
	}
	while(c!=6);	
}
