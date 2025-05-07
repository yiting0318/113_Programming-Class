#include <iostream>
#include <string>
using namespace std;

class STNODE
{
    int no;
    string name;
	int prg;  // �{���]�p 
	int eng;  // �^�� 
	STNODE* p;

public:
    void write_no(int x) { no = x; }
    int read_no() { return no; }
    
    void write_name(string n){name = n;}
	string read_name(){return name;}
	
	void write_prg(int y){prg=y;}
	int read_prg(){return prg;}
	
	void write_eng(int z){eng=z;}
	int read_eng(){return eng;}

    void write_ptr(STNODE* ptr) { p = ptr; }
    STNODE* read_ptr() { return p; }
    
    void operator +(int v)
    {
    	prg = prg + 5 ; 
    	eng = eng + 5 ;
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
	cout<<"          ��� Menu"<<endl; 
	cout<<"  (1).�s�W�ǥ͸�� Insertion"<<endl; //�s�W
	cout<<"  (2).�d�߾ǥ͸�� Search"<<endl; //�j�M
	cout<<"  (3).�R���ǥ͸�� Delete"<<endl; // �R��
	cout<<"  (4).�վ�ǥͦ��Z Modify"<<endl; //�ק� 
	cout<<"  (5).�C�L��C��� Print List Data"<<endl;//�L�X (�̷Ӯy��)
	cout<<"  (6).�C�L�ǥͦ��Z�� Print Transcript"<<endl;  //�L�X (�̷Ӧ��Z)
	cout<<"  (0).���} Exit"<<endl;
	cout<<"�п�J��ܶ���? Please Select  one"<<endl;
	}	
};

//�ק�
STNODE* Modify(STNODE *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x,y,z;
		STNODE a;
		STNODE* p = new STNODE;
		STNODE* h = NULL;
    	STNODE* b = NULL;
		cout<<"�п�J���ק令�Z���ǥͮy��"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head->read_no()) //���ק諸�O�Ĥ@��
		{ 
			*head + y;
			cout<<"�ӵ���Ƥw�վ�"<<endl;
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
            	*b + y;
				cout<<"�ӵ���Ƥw�����վ�"<<endl;
				
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"�ӵ���Ƥ��s�b�A�L�k�վ�C"<<endl;
			}
		}
	}
	return head;
}

//�j�M 
STNODE* Search(STNODE *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		string n;
		STNODE* p = new STNODE;
		STNODE* h = head;
    	STNODE* b = head;
    	STNODE* e = head;
    	int i = 0 ;
		cout<<"�п�J���d�߾ǥͪ��m�W"<<endl;
		cin>>n;
		p->write_name(n);
		
		
        if(b->read_ptr() != NULL)
		{
			do
			{	
			
        		if(p->read_name() == b->read_name())
        		{
        			cout<<"�y��:"<<b->read_no();
					cout<<",�m�W:"<<b->read_name();
					cout<<",�{�]���Z: " << b->read_prg()<<"��";
					cout<<",�^�妨�Z: " << b->read_eng()<<"��"<<endl; 
					e = b;
					b = b->read_ptr();
					i++;
				}
				while ( b->read_ptr() != NULL &&p->read_name() != b->read_name()) 
        	    {
       		        h = b;
            	    b = b->read_ptr();
        		}
				
            }
            while(b->read_ptr() != NULL);
            
            h = h->read_ptr();
            if (p->read_name() == h->read_name() && e->read_no() != h->read_no()) // ���o�Ӯy�� 
	            {
	            	cout<<"�y��:"<<h->read_no();
					cout<<",�m�W:"<<h->read_name();
					cout<<",�{�]���Z: " << h->read_prg()<<"��";
					cout<<",�^�妨�Z: " << h->read_eng()<<"��"<<endl; 
					i++;
	            }
		}
		else
		{
			if(p->read_name()==head->read_name()) //�d�ߪ��O�Ĥ@��
			{ 
				cout<<"�y��:"<<head->read_no();
				cout<<",�m�W:"<<head->read_name();
				cout<<",�{�]���Z: " << head->read_prg()<<"��";
				cout<<"�^�妨�Z: " << head->read_eng()<<"��"<<endl;
				i++;
			} 
		}
		
		  
        if(i == 0)    
        {
        	cout<<"�Ӿǥͤ��s�b"<<endl;
       	}	
		
	}
	return head;
}

//�s�W 
STNODE* Insert(STNODE *head)
{
	STNODE* p = new STNODE;
    STNODE* h = NULL;
    STNODE* b = NULL;
	int x,y,z;
	string n;
	cout<<"�п�J�ǥͮy���B�m�W�ε{�]�B�^�妨�Z"<<endl;
	cin>>x;
	cin.get();
	getline(cin,n);
	cin>>y; 
	cin>>z; 
	
	p->write_no(x);
    p->write_name(n);
    p->write_prg(y);
    p->write_eng(z);
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

//�R�� 
STNODE* Delete(STNODE *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x;
		STNODE* p = new STNODE;
		STNODE* h = NULL;
    	STNODE* b = NULL;
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
			cout<<"�ӵ���Ƥw�����R�� "<<endl;
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
				cout<<"�ӵ���Ƥw�����R�� "<<endl;	
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
			}
		}
	}
	return head;
}

//�C�L��C 
void Print_no(STNODE *k)
{
	cout<<"head -> "; 
	
	STNODE* head1 = k;
    while (head1 != NULL) 
	{
		cout<<head1->read_no()<<" -> ";
        head1 = head1->read_ptr();
    }
    cout<<"||"<<endl;
}

//�C�L���Z�� 
void Print_score(STNODE *k)
{
    if (k == NULL)
    {
        cout << "�|���s�J������" << endl;
        return;
    }

    STNODE *p[50]; // �s�C��ǥͪ���� 
    int total[50];   // �s�C��ǥͪ��`��
    int i = 0;

    STNODE *head1 = k;
    while (head1 != NULL && i < 50) //���`�M��� total �}�C�� 
    {
        p[i] = head1;
        total[i] = head1->read_prg() + head1->read_eng() ;
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
            }
        }
    }

    for (int j = 0; j < i; j++)
    {
    	if( total[j] == total[j - 1] )
    	{
    		cout << "�W��: " << j;
		}
    	else
    	{
    		cout << "�W��: " << j+1;
		}
        cout << "�y��: " << p[j]->read_no();
        cout << ", �m�W: " << p[j]->read_name();
        cout << ", �{�]: " << p[j]->read_prg() << "��";
        cout << ", �^��: " << p[j]->read_eng() << "��";
        cout << ", �`��: " << total[j] << "��" << endl;
    }
}




int main()
{
	int b,c,s;
	STNODE *k = NULL;
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
				
				case 3:k = Delete(k);
				break;
				
				case 4:k = Modify(k);
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


void Print_score(STNODE *head)
{
    // ���ƻs���C�A�קK�}�a�쥻�����c
    STNODE* original = head;
    STNODE* copy_head = NULL;
    STNODE* copy_tail = NULL;

    while (original != NULL)
    {
        STNODE* temp = new STNODE();
        temp->write_no(original->read_no());
        temp->write_name(original->read_name());
        temp->write_prg(original->read_prg());
        temp->write_eng(original->read_eng());
        temp->write_ptr(NULL);

        if (copy_head == NULL)
        {
            copy_head = temp;
            copy_tail = temp;
        }
        else
        {
            copy_tail->write_ptr(temp);
            copy_tail = temp;
        }

        original = original->read_ptr();
    }

    // �}�l�Ƨ� copy_head�A�̷��`���Ѥj��p
    STNODE* sorted = NULL;

    while (copy_head != NULL)
    {
        STNODE* now = copy_head;
        copy_head = copy_head->read_ptr();
        now->write_ptr(NULL);

        STNODE* prev = NULL;
        STNODE* curr = sorted;

        int now_total = now->read_prg() + now->read_eng();

        while (curr != NULL && (curr->read_prg() + curr->read_eng()) > now_total)
        {
            prev = curr;
            curr = curr->read_ptr();
        }

        if (prev == NULL)
        {
            now->write_ptr(sorted);
            sorted = now;
        }
        else
        {
            prev->write_ptr(now);
            now->write_ptr(curr);
        }
    }

    // �C�L�Ƨǫ᪺���Z��P�W���]�t�P���B�z�^
    STNODE* p = sorted;
    int rank = 1;
    int prev_score = -1;
    int tie_count = 0;

    cout << "\n========= ���Z�� =========\n";
    cout << "�W��  �y��  �m�W\t�{�]\t�^��\t�`��\n";

    while (p != NULL)
    {
        int total = p->read_prg() + p->read_eng();

        if (total != prev_score)
        {
            rank += tie_count;
            tie_count = 1;
        }
        else
        {
            tie_count++;
        }

        cout << rank << "\t"
             << p->read_no() << "\t"
             << p->read_name() << "\t"
             << p->read_prg() << "\t"
             << p->read_eng() << "\t"
             << total << "\n";

        prev_score = total;
        p = p->read_ptr();
    }

    cout << "===========================\n";
}

