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
	
	STNODE() //�Ϋغc�l����l�� 
	{
		prg = 0;
		eng = 0;
		p = NULL;
	}

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
    	prg = prg + v ; 
    	eng = eng + v ;
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

//�ק�
STNODE* Modify(STNODE *head)
{
	if(head == NULL) 
	{
		cout<<"�|���s�J������"<<endl; 
	}
	
	else
	{
		int x,z;
		STNODE a;
		STNODE* p = new STNODE;
		STNODE* h = NULL;
    	STNODE* b = NULL;
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

//�j�M 
STNODE* Search(STNODE *head)
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

    STNODE* check = head;
    int found = 0;

    while (check != NULL)
    {
        if (check->read_name() == name)
        {
            cout << "�y��: " << check->read_no()
                 << ", �m�W: " << check->read_name()
                 << ", �{�]���Z: " << check->read_prg() << "��"
                 << ", �^�妨�Z: " << check->read_eng() << "��" << endl;
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

//�s�W 
STNODE* Insert(STNODE *head)
{
	STNODE* p = new STNODE; //�s�W���`�I 
    STNODE* f = NULL; //Front
    STNODE* b = NULL; //Behind
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
		STNODE* f = NULL; //Front
    	STNODE* b = NULL; //Behind 
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

//�C�L��C 
void Print_no(STNODE *k)
{
	cout<<"head -> "; 
	
	STNODE* head = k;
    while (head != NULL) 
	{
		cout<<head->read_no()<<" -> ";
        head = head->read_ptr();
    }
    cout<<"||"<<endl;
}


//�C�L���Z�� 
void Print_score(STNODE *head)
{
    //�ƻs��C
    STNODE* original = head;       // �ΨӹM����l��C������
    STNODE* copy_head = NULL;      // �ƻs��C���}�Y
    STNODE* copy_tail = NULL;      // �ƻs��C�����ݡ]��K���`�I�^

    while (original != NULL)
    {
        STNODE* p = new STNODE();   // �إ߷s���`�I�ӷǳƽƻs���

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
    STNODE* sorted = NULL;   // �Ƨǫ᪺�s��C�_�I

    while (copy_head != NULL)
    {
        STNODE* now = copy_head;           // ���X�ثe�`�I�ǳƴ��J
        copy_head = copy_head->read_ptr(); // ��s�ƻs��C�_�I
        now->write_ptr(NULL);              // �M�� now ���U�@�ӫ��СA�קK�ñ�

        STNODE* prev = NULL;   // ���J��m���e�@�Ӹ`�I
        STNODE* curr = sorted; // ���V sorted ��C�A�ΨӹM��

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
    STNODE *head1 = sorted;  // ���V�Ƨǫ��C���_�l�I
    int rank = 1;            // ��e�W��
    int same_count = 0;      // �P�e�@���`���ۦP���H��
    int prev_total = -1;     // �e�@��ǥͪ��`���A���O�_�P��

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
        cout << "�W��: ��" << rank << "�W  ";
        cout << "�y��: " << head1->read_no();
        cout << ", �m�W: " << head1->read_name();
        cout << ", �{�]: " << head1->read_prg() << "��";
        cout << ", �^��: " << head1->read_eng() << "��";
        cout << ", �`��: " << total << "��" << endl;

        head1 = head1->read_ptr(); // ���ʨ�U�@��ǥ�
    }
}


int main()
{
	int s; //��J�����ﶵ 
	STNODE *k = NULL; //�ǻ��C�Ӧ�C 
	MENU menu;
	
	do
	{
		menu.show();
		cin>>s;
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
				
			default:cout<<"�S�����ﶵ"<<endl;
			break;
		}
		
	}	

	while(menu.read_select() != 0);	
}
