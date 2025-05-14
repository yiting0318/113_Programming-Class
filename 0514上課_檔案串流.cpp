#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> // �ɮצ�y 
using namespace std;

class STNODE
{
    int no;
    string name;

public:

    void write_no(int x) { no = x; }
    int read_no() { return no; }
    
    void write_name(string n){name = n;}
	string read_name(){return name;}
    

};

class CMP : public  STNODE
{
	int prg;  // �{���]�p 
	int eng;  // �^�� 
	CMP* p;
	
public:
	
	void write_prg(int y){prg=y;}
	int read_prg(){return prg;}
	
	void write_eng(int z){eng=z;}
	int read_eng(){return eng;}

    void write_ptr(CMP* ptr) { p = ptr; }
    CMP* read_ptr() { return p; }
    
    void operator +(int v)
    {
    	prg = prg + v ; 
    	eng = eng + v ;
	}
	
};

class PC : public  STNODE
{
	int run;   // �]�B 
	int swim;  // ��a 
	int ai;    // �H�u���z 
	PC* p;
	
public:
	
	void write_run(int y){run=y;}
	int read_run(){return run;}
	
	void write_swim(int z){swim=z;}
	int read_swim(){return swim;}
	
	void write_ai(int a){ai=a;}
	int read_ai(){return ai;}

    void write_ptr(PC* ptr) { p = ptr; }
    PC* read_ptr() { return p; }
    
    void operator +(int v)
    {
    	run = run + v ; 
    	swim = swim + v ;
    	ai = ai + v ;
	}
	
};



class MENU
{
	int select;
	
public:
	MENU()
	{
		select = -1;
	} 
	
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

//�ק�_��� 
CMP* Modify_CMP(CMP *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x,z;
		CMP a;
		CMP* p = new CMP;
		CMP* h = NULL;
    	CMP* b = NULL;
		cout<<"�п�J���ק令�Z���ǥͮy��"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head->read_no()) //���ק諸�O�Ĥ@��
		{ 
			*head + 5;
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
            	*b + 5;
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

//�ק� _��| 
PC* Modify_PC(PC *head_PC)
{
	if(head_PC == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x,z;
		PC a;
		PC* p = new PC;
		PC* h = NULL;
    	PC* b = NULL;
		cout<<"�п�J���ק令�Z���ǥͮy��"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head_PC->read_no()) //���ק諸�O�Ĥ@��
		{ 
			*head_PC + 5;
			cout<<"�ӵ���Ƥw�վ�"<<endl;
		} 
		else
		{
			b = head_PC;
			h = head_PC;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // ���o�Ӯy�� 
            {
            	*b + 5;
				cout<<"�ӵ���Ƥw�����վ�"<<endl;
				
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"�ӵ���Ƥ��s�b�A�L�k�վ�C"<<endl;
			}
		}
	}
	return head_PC;
}

//�j�M_��� 
CMP* Search_CMP(CMP *head)
{
    if (head == NULL)
    {
        cout << "�|���s�J������" << endl;
        return head;
    }

    string name;
    cout << "�п�J���d�߾ǥͪ��m�W�G" << endl;
    cin.ignore(); 
    getline(cin, name);

    CMP* check = head;
    int found = 0;

    while (check != NULL)
    {
        if (check->read_name() == name)
        {
            cout << "�y��: " <<setw(8)<<left<< check->read_no()
                 << ", �m�W: " <<setw(8)<<left<< check->read_name()
                 << ", �{�]���Z: " <<setw(8)<<left<< check->read_prg() << "��"
                 << ", �^�妨�Z: " <<setw(8)<<left<< check->read_eng() << "��" << endl;
            found++;
        }
        check = check->read_ptr();
    }

    if (found == 0)
    {
        cout << "�d�L���ǥ�" << endl;
    }

    return head;
}

//�j�M_��| 
PC* Search_PC(PC *head_PC)
{
    if (head_PC == NULL)
    {
        cout << "�|���s�J������" << endl;
        return head_PC;
    }

    string name;
    cout << "�п�J���d�߾ǥͪ��m�W�G" << endl;
    cin.ignore(); 
    getline(cin, name);

    PC* check = head_PC;
    int found = 0;

    while (check != NULL)
    {
        if (check->read_name() == name)
        {
            cout << "�y��: " <<setw(8)<<left<< check->read_no()
                 << ", �m�W: " <<setw(8)<<left<< check->read_name()
                 << ", �]�B���Z: " <<setw(8)<<left<< check->read_run() << "��"
                 << ", ��a���Z: " <<setw(8)<<left<< check->read_swim() << "��"
                 << ", AI���Z: " <<setw(8)<<left<< check->read_ai() << "��" << endl;
            found++;
        }
        check = check->read_ptr();
    }

    if (found == 0)
    {
        cout << "�d�L���ǥ�" << endl;
    }

    return head_PC;
}

//�s�W _��� 
CMP* Insert_CMP(CMP *head)
{
	CMP* p = new CMP; //�s�W���`�I 
    CMP* f = NULL; //Front
    CMP* b = NULL; //Behind
	int x,y,z; //�d�ߪ��ܼ� 
	string n;
	cout<<"�п�J�ǥͮy���B�m�W�ε{�]�B�^�妨�Z"<<endl;
	cin>>x;
	cin.ignore(); 
	getline(cin, n); 
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
            f = p;
            b = p;
        } 
    else 
		{
            
            if(p->read_no() < head->read_no()) //���̫e�� 
            {
            	p->write_ptr(head);
                head = p;
                f = head;
                b = head;
			}
			else  //�Ʀr��᭱ 
			{	
				b = head;
				f = head;
				
				while (b->read_ptr() != NULL && p->read_no() > b->read_no()) 
                {
                    f = b;
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
                    f->write_ptr(p); 
				}	
			}
        }   
    return head; 
}

//�s�W _��| 
PC* Insert_PC(PC *head_PC)
{
	PC* p = new PC; //�s�W���`�I 
    PC* f = NULL; //Front
    PC* b = NULL; //Behind
	int x,y,z,a; //�d�ߪ��ܼ� 
	string n;
	cout<<"�п�J�ǥͮy���B�m�W�ζ]�B�B��a�M�H�u���z���Z"<<endl;
	cin>>x;
	cin.ignore(); 
	getline(cin, n); 
	cin>>y; 
	cin>>z; 
	cin>>a;
	
	p->write_no(x);
    p->write_name(n);
    p->write_run(y);
    p->write_swim(z);
    p->write_ai(a);
    p->write_ptr(NULL); 
    
    if (head_PC == NULL) 
		{
            head_PC = p;
            f = p;
            b = p;
        } 
    else 
		{
            
            if(p->read_no() < head_PC->read_no()) //���̫e�� 
            {
            	p->write_ptr(head_PC);
                head_PC = p;
                f = head_PC;
                b = head_PC;
			}
			else  //�Ʀr��᭱ 
			{	
				b = head_PC;
				f = head_PC;
				
				while (b->read_ptr() != NULL && p->read_no() > b->read_no()) 
                {
                    f = b;
                    b = b->read_ptr();
                }

                if (p->read_no() == b->read_no()) // �y������
                {
                    cout << "�y���w�s�b"<<endl; 
                    return head_PC;
                }
				
				else if (b->read_ptr() == NULL && p->read_no() > b->read_no()) //�b�̫�@�� 
				{
					b->write_ptr(p);
					p->write_ptr(NULL);
				}
				
				else //�@�몺���J���� 
				{
					p->write_ptr(b);
                    f->write_ptr(p); 
				}	
			}
        }   
    return head_PC; 
}

//�R��_��� 
CMP* Delete_CMP(CMP *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x;
		CMP* p = new CMP;
		CMP* f = NULL; //Front
    	CMP* b = NULL; //Behind 
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
			f = head;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //����y�� 
            {
                f = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // ���o�Ӯy�� 
            {
            	if(b->read_ptr() == NULL) //�b�̫�@�� 
            	{
            		f->write_ptr(NULL);
				}
				else //�b��C���� 
				{
					b = b->read_ptr();
                	f->write_ptr(b);
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

//�R��_��|
PC* Delete_PC(PC *head_PC)
{
	if(head_PC == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x;
		PC* p = new PC;
		PC* f = NULL; //Front
    	PC* b = NULL; //Behind 
		cout<<"�п�J���R���ǥͪ��y��"<<endl;
		cin>>x;
		p->write_no(x);
	
		if(p->read_no()==head_PC->read_no()) //�R���Ĥ@��
		{ 
			if(head_PC->read_ptr() == NULL) //�쥻�N�u���@����� 
			{
				head_PC = NULL;
				
			}
			else //���u���@�����  
			{
				head_PC=head_PC->read_ptr();
				
			}
			cout<<"�ӵ���Ƥw�����R�� "<<endl;
		} 
		else
		{
			b = head_PC;
			f = head_PC;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //����y�� 
            {
                f = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // ���o�Ӯy�� 
            {
            	if(b->read_ptr() == NULL) //�b�̫�@�� 
            	{
            		f->write_ptr(NULL);
				}
				else //�b��C���� 
				{
					b = b->read_ptr();
                	f->write_ptr(b);
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
	return head_PC;
}

//�C�L��C_ ��� 
void Print_no_CMP(CMP *k)
{
	cout<<"head -> "; 
	
	CMP* head = k;
    while (head != NULL) 
	{
		cout<<head->read_no()<<" -> ";
        head = head->read_ptr();
    }
    cout<<"||"<<endl;
}

//�C�L��C_ ��| 
void Print_no_PC(PC *j)
{
	cout<<"head -> "; 
	
	PC* head = j;
    while (head != NULL) 
	{
		cout<<head->read_no()<<" -> ";
        head = head->read_ptr();
    }
    cout<<"||"<<endl;
}

//�C�L���Z��_��� 
void Print_score_CMP(CMP *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	else
	{
		//�ƻs��C
    CMP* original = head;       // �ΨӹM����l��C������
    CMP* copy_head = NULL;      // �ƻs��C���}�Y
    CMP* copy_tail = NULL;      // �ƻs��C�����ݡ]��K���`�I�^

    while (original != NULL)
    {
        CMP* p = new CMP();   // �إ߷s���`�I�ӷǳƽƻs���

        // �ƻs�C����쪺���
        p->write_no(original->read_no());         
        p->write_name(original->read_name());    
        p->write_prg(original->read_prg());       
        p->write_eng(original->read_eng());       
        p->write_ptr(NULL);                       

        // �� p ����ƻs��C����
        if (copy_head == NULL)   // �Ĥ@�Ӹ`�I
        {
            copy_head = p;
            copy_tail = p;
        }
        else
        {
            copy_tail->write_ptr(p);
            copy_tail = p;
        }

        original = original->read_ptr(); // ���ʨ�U�@�ӭ��C�`�I
    }

    // �� copy_head �i��Ƨ�
    CMP* sorted = NULL;   // �Ƨǫ᪺�s��C�_�I

    while (copy_head != NULL)
    {
        CMP* now = copy_head;           // ���X�ثe�`�I�ǳƴ��J
        copy_head = copy_head->read_ptr(); // ��s�ƻs��C�_�I
        now->write_ptr(NULL);              // �M�� now ���U�@�ӫ��СA�קK�ñ�

        CMP* prev = NULL;   // ���J��m���e�@�Ӹ`�I
        CMP* curr = sorted; // ���V sorted ��C�A�ΨӹM��

        int now_total = now->read_prg() + now->read_eng(); // �p�� now �`�I�`��

        // ��X sorted ���Ĥ@�Ӥ� now �`���p����m
        while (curr != NULL && (curr->read_prg() + curr->read_eng()) > now_total)
        {
            prev = curr;
            curr = curr->read_ptr();
        }

        // ���J now �`�I
        if (prev == NULL)
        {
            now->write_ptr(sorted); // ���J�̫e��
            sorted = now;
        }
        else
        {
            prev->write_ptr(now);   // ���J prev �M curr ����
            now->write_ptr(curr);
        }
    }

    //�L�X���Z��
    CMP *head1 = sorted;  // ���V�Ƨǫ��C���_�l�I
    int rank = 1;            // ��e�W��
    int same_count = 0;      // �P�e�@���`���ۦP���H��
    int prev_total = -1;     // �e�@��ǥͪ��`���A���O�_�P��
    
    cout <<setw(6)<<left<<"�W��" ;
    cout <<setw(6)<<left<<"�m�W" ;
    cout <<setw(6)<<left<<"�y��" ;
    cout <<setw(10)<<left<<"�{�]���Z" ;
    cout <<setw(10)<<left<<"�^�妨�Z" ;
    cout <<setw(8)<<left<<"�`��" << endl;
	
    while (head1 != NULL)
    {
        int total = head1->read_prg() + head1->read_eng(); // �p��ǥ��`��

        // �P�_�O�_�ݭn��s�W��
        if (total != prev_total)
        {
            rank += same_count; // �Y���L�P�����W��
            same_count = 1;     // �s�@�զP�����}�l
        }
        else
        {
            same_count++;       // �P���̲֥[
        }

        prev_total = total;     // ��s�ثe�`��

        // ��X�o��ǥͪ����Z�P�W��
        
        cout <<setw(6)<< rank  ;
        cout <<setw(6)<<head1->read_name() ;
        cout <<setw(6)<<head1->read_no() ;
        cout <<setw(10)<< head1->read_prg() ;
        cout <<setw(10)<< head1->read_eng() ;
        cout <<setw(8)<< total << endl;

        head1 = head1->read_ptr(); // ���ʨ�U�@��ǥ�
    }
	}
	
    
}

//�C�L���Z��_��| 
void Print_score_PC(PC *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	else
	{
		//�ƻs��C
    PC* original = head;       // �ΨӹM����l��C������
    PC* copy_head = NULL;      // �ƻs��C���}�Y
    PC* copy_tail = NULL;      // �ƻs��C�����ݡ]��K���`�I�^

    while (original != NULL)
    {
        PC* p = new PC();   // �إ߷s���`�I�ӷǳƽƻs���

        // �ƻs�C����쪺���
        p->write_no(original->read_no());         
        p->write_name(original->read_name());    
        p->write_run(original->read_run());       
        p->write_swim(original->read_swim());   
		p->write_ai(original->read_ai());    
        p->write_ptr(NULL);                       

        // �� p ����ƻs��C����
        if (copy_head == NULL)   // �Ĥ@�Ӹ`�I
        {
            copy_head = p;
            copy_tail = p;
        }
        else
        {
            copy_tail->write_ptr(p);
            copy_tail = p;
        }

        original = original->read_ptr(); // ���ʨ�U�@�ӭ��C�`�I
    }

    // �� copy_head �i��Ƨ�
    PC* sorted = NULL;   // �Ƨǫ᪺�s��C�_�I

    while (copy_head != NULL)
    {
        PC* now = copy_head;           // ���X�ثe�`�I�ǳƴ��J
        copy_head = copy_head->read_ptr(); // ��s�ƻs��C�_�I
        now->write_ptr(NULL);              // �M�� now ���U�@�ӫ��СA�קK�ñ�

        PC* prev = NULL;   // ���J��m���e�@�Ӹ`�I
        PC* curr = sorted; // ���V sorted ��C�A�ΨӹM��

        int now_total = now->read_run() + now->read_swim() + now->read_ai(); // �p�� now �`�I�`��

        // ��X sorted ���Ĥ@�Ӥ� now �`���p����m
        while (curr != NULL && (curr->read_run() + curr->read_swim() + curr->read_ai()) > now_total)
        {
            prev = curr;
            curr = curr->read_ptr();
        }

        // ���J now �`�I
        if (prev == NULL)
        {
            now->write_ptr(sorted); // ���J�̫e��
            sorted = now;
        }
        else
        {
            prev->write_ptr(now);   // ���J prev �M curr ����
            now->write_ptr(curr);
        }
    }

    //�L�X���Z��
    PC *head1 = sorted;  // ���V�Ƨǫ��C���_�l�I
    int rank = 1;            // ��e�W��
    int same_count = 0;      // �P�e�@���`���ۦP���H��
    int prev_total = -1;     // �e�@��ǥͪ��`���A���O�_�P��
    
    cout <<setw(6)<<left<<"�W��" ;
    cout <<setw(6)<<left<<"�m�W" ;
    cout <<setw(6)<<left<<"�y��" ;
    cout <<setw(10)<<left<<"�]�B���Z" ;
    cout <<setw(10)<<left<<"��a���Z" ;
    cout <<setw(8)<<left<<"ai���Z" ;
    cout <<setw(8)<<left<<"�`��" << endl;
	
    while (head1 != NULL)
    {
        int total = head1->read_run() + head1->read_swim() + head1->read_ai(); // �p��ǥ��`��

        // �P�_�O�_�ݭn��s�W��
        if (total != prev_total)
        {
            rank += same_count; // �Y���L�P�����W��
            same_count = 1;     // �s�@�զP�����}�l
        }
        else
        {
            same_count++;       // �P���̲֥[
        }

        prev_total = total;     // ��s�ثe�`��

        // ��X�o��ǥͪ����Z�P�W��
        
        cout <<setw(6)<< rank  ;
        cout <<setw(6)<<head1->read_name() ;
        cout <<setw(6)<<head1->read_no() ;
        cout <<setw(10)<< head1->read_run() ;
        cout <<setw(10)<< head1->read_swim() ;
        cout <<setw(8)<< head1->read_ai() ;
        cout <<setw(8)<< total << endl;

        head1 = head1->read_ptr(); // ���ʨ�U�@��ǥ�
    }
	}
	
    
}

//�������_��� 
void output_CMP(CMP *head) 
{
	ofstream output("st_cmp.txt");
	while (head != NULL)
	{
		output << head->read_no() << endl;
		output << head->read_name() << endl;
		output << head->read_prg() << endl;
		output << head->read_eng() << endl;
		head = head->read_ptr();
	}
	output.close();
}

//�������_��� 
void output_PC(PC *head) 
{
	ofstream output("st_pc.txt");
	while (head != NULL)
	{
		output << head->read_no() << endl;
		output << head->read_name() << endl;
		output << head->read_run() << endl;
		output << head->read_swim() << endl;
		output << head->read_ai() << endl;
		head = head->read_ptr();
	}
	output.close();
}

//�g�J���_���
CMP* input_CMP(CMP *head)
{
	ifstream input("st_cmp.txt");
	
	CMP* f = NULL;
	int x,y,z; //�d�ߪ��ܼ� 
	string n;
	
	while( input >> x && !input.eof() )
	{
		CMP* p = new CMP;
		input.ignore(); 
	    getline(input, n);
	    input >>y; 
	    input >>z;
	     
	    
	    p->write_no(x);
        p->write_name(n);
        p->write_prg(y);
        p->write_eng(z);
        p->write_ptr(NULL);
        
        if (head == NULL) 
		{
            head = p;
            f = head;
        } 
        
        else
        {
            f->write_ptr(p);
            f = p; 
		}
	    
	}
	input.close();
	return head;
	
}

//�g�J���_��| 
PC* input_PC(PC *head)
{
	ifstream input("st_pc.txt");
	
	PC* f = NULL;
	int x,y,z,a; //�d�ߪ��ܼ� 
	string n;
	
	while( input >> x && !input.eof() )
	{
		PC* p = new PC;
		input.ignore(); 
	    getline(input, n);
	    input >>y; 
	    input >>z;
	    input >>a;
	     
	    
	    p->write_no(x);
        p->write_name(n);
        p->write_run(y);
        p->write_swim(z);
        p->write_ai(a);
        p->write_ptr(NULL);
        
        if (head == NULL) 
		{
            head = p;
            f = head;
        } 
        
        else
        {
            f->write_ptr(p);
            f = p; 
		}
	    
	}
	input.close();
	return head;
	
}
 
int main()
{
	int s,t; //��J�����ﶵ 
	CMP *k = NULL; //�ǻ��C�Ӧ�C 
	PC *j = NULL;
	MENU menu;
	
	

	k = input_CMP(k);
	j = input_PC(j);
	
	do
	{
		menu.show();
		cin>>s;
		menu.write_select(s);
		switch(menu.read_select())
		{
			case 1:
			cout<<"�п�ܬ�t 1.���t 2.��|�t"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Insert_CMP(k);
				break;
				
				case 2:j = Insert_PC(j);
				break;
				
				default:cout<<"�S�����ﶵ"<<endl;
				break;
			}
			break;
			
			
			case 2:
			cout<<"�п�ܬ�t 1.���t 2.��|�t"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Search_CMP(k);
				break;
				
				case 2:j = Search_PC(j);
				break;
				
				default:cout<<"�S�����ﶵ"<<endl;
				break;
			}
			break;
			
			case 3:
			cout<<"�п�ܬ�t 1.���t 2.��|�t"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Delete_CMP(k);
				break;
				
				case 2:j = Delete_PC(j);
				break;
				
				default:cout<<"�S�����ﶵ"<<endl;
				break;
			}
			break;
			
			case 4:
			cout<<"�п�ܬ�t 1.���t 2.��|�t"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Modify_CMP(k);
				break;
				
				case 2:j = Modify_PC(j);
				break;
				
				default:cout<<"�S�����ﶵ"<<endl;
				break;
			}
			break;
			
			case 5:
			cout<<"�п�ܬ�t 1.���t 2.��|�t"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:Print_no_CMP(k);
				break;
				
				case 2:Print_no_PC(j);
				break;
				
				default:cout<<"�S�����ﶵ"<<endl;
				break;
			}
			break;
			
			case 6:
			cout<<"�п�ܬ�t 1.���t 2.��|�t"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:Print_score_CMP(k);
				break;
				
				case 2:Print_score_PC(j);
				break;
				
				default:cout<<"�S�����ﶵ"<<endl;
				break;
			}
			break;
				
			case 0:
			output_CMP(k);
			output_PC(j);
			cout<<"�P�¨ϥΥ��t�ΡA�w��U���A��^^"<<endl;
			
			break;
				
			default:cout<<"�S�����ﶵ"<<endl;
			break;
		}
		
	}	

	while(menu.read_select() != 0);	
}
