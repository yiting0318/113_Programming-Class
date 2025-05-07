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

class MENU
{
	int select;
	
public:
	void write_select (int s) {select = s;}
	int read_select() { return select; }
	void show () 
	{
	cout<<"     Menu"<<endl; 
	cout<<"   1.Insert"<<endl; //�s�W
	cout<<"   2.Search"<<endl; //�j�M
	cout<<"   3.Modify"<<endl; //�ק� 
	cout<<"   4.Delete"<<endl; //�R�� 
	cout<<"   5.Print_no"<<endl;//�L�X (�̷Ӯy��)
	cout<<"   6.Print_score"<<endl;  //�L�X (�̷Ӧ��Z)
	cout<<"   0.Exit"<<endl;
	cout<<"Please Select  one"<<endl;
	}	
};

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

void Print_no(st_node *k)
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

void Print_score(st_node *k)
{
    if (k == NULL)
    {
        cout << "�|���s�J������" << endl;
        return;
    }

    st_node *p[50]; // �s�C��ǥͪ���� 
    int total[50];   // �s�C��ǥͪ��`��
    int i = 0;

    st_node *head1 = k;
    while (head1 != NULL && i < 50) //���`�M��� total �}�C�� 
    {
        p[i] = head1;
        total[i] = head1->read_prg() + head1->read_cmp() + head1->read_math();
        i++;
        head1 = head1->read_ptr();
    }

    for (int a = 0; a < i - 1; a++) // �`���Ϊw�w�ƧǪk�Ƨ�  //�`�@�|�ݭn��� i-1 ��  
    {
        for (int b = 0; b < i - a - 1; b++) 
        {
            if (total[b] < total[b + 1])
            {
                swap(total[b], total[b + 1]);
                swap(p[b], p[b + 1]); // ����Ƹ��`���@�_�P�B�Ƨ� 
            } //�Ѯv���`�I�i�H�������洫�A���n�ۤv�t�~�w�q�άO�T�����ΡA ���ڨS��ԣ�ǥ͸`�I�洫�A�o�����ݬ�s!! 
        }
    }

    for (int j = 0; j < i; j++)
    {
        cout << "�y��: " << p[j]->read_no();
        cout << ", �m�W: " << p[j]->read_name();
        cout << ", �{�]: " << p[j]->read_prg() << "��";
        cout << ", �p��: " << p[j]->read_cmp() << "��";
        cout << ", �ƾ�: " << p[j]->read_math() << "��";
        cout << ", �`��: " << total[j] << "��" << endl;
    }
}




int main()
{
	int b,c,s;
	st_node *k = NULL;
	MENU menu;
	
	do
	{
		menu.show();
		cin>>s;
		
		
		if(s!=1 && s!=2 && s!=3 && s!=4 && s!=5 && s!=6 && s!=0)
		{
			cout<<"�S�����ﶵ"<<endl; 
		}
		else
		{
			menu.write_select(s);

			switch(menu.read_select())
			{
				case 1:k = Insert(k);
				break;
				
				case 2:Search(k);
				break;
				
				case 3:k = Modify(k);
				break;
				
				case 4:k = Delete(k);
				break;
				
				case 5:Print_no(k);
				break;
				
				case 6:Print_score(k);
				break;
				
				case 0:cout<<"�P�¨ϥΥ��t�ΡA�w��U���A��^^"<<endl;
				break;
				
				default:cout<<"Wrong select, try again."<<endl;
				break;
			}
		
		}	
	}
	while(menu.read_select() != 0);	
}
