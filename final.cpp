#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> 
using namespace std;

class Account
{
    int ID;
    string name;

public:

    void write_ID(int x) { ID = x; }
    int read_ID() { return ID; }
    
    void write_name(string n){name = n;}
	string read_name(){return name;}
    
};

class TW_Account : public  Account
{
	int S;  // �l�B Save 
	int B;  // �ɿ� Borrow
	TW_Account* p;
	
public:
	
	JP_Account() //�Ϋغc�l����l�� 
	{
		S = 0;
		B = 0;
		p = NULL;
	}
	
	void write_S(int y){S=y;}
	int read_S(){return S;}
	
	void write_B(int z){B=z;}
	int read_B(){return B;}
	
	void write_ptr(TW_Account* ptr) { p = ptr; }
    TW_Account* read_ptr() { return p; }
    
	
};

class JP_Account : public  Account
{
	int Save;  // �l�B Save 
	int Borrow;  // �ɿ� Borrow
	JP_Account* p;
	
public:
	
	JP_Account() //�Ϋغc�l����l�� 
	{
		Save = 0;
		Borrow = 0;
		p = NULL;
	}
	
	void write_Save(int y){Save=y;}
	int read_Save(){return Save;}
	
	void write_Borrow(int z){Borrow=z;}
	int read_Borrow(){return Borrow;}
	
	void write_ptr(JP_Account* ptr) { p = ptr; }
    JP_Account* read_ptr() { return p; }
    
    
};

class Bank
{
	TW_Account* h;   //�x���b����� 
	JP_Account* j;   //����b����� 
	float m;         //�Ȧ�Ѿl�l�B 
	int select;
	
public:
	
	Bank() //�Ϋغc�l����l�� 
	{
		h = NULL;
		j = NULL;
		m = 0.00;
		select = -1;
	}
	
	void write_htr(TW_Account* htr) { h = htr; }
    TW_Account* read_htr() { return h; }
    
    void write_jtr(JP_Account* jtr) { j = jtr; }
    JP_Account* read_jtr() { return j; }
    
    void write_money(float money) { m = money; }
    float read_money() { return m; }
    
    void write_select (int s) {select = s;}
	int read_select() { return select; }
	
	void show () 
	{
	cout<<"         ��� "<<endl; 
	cout<<"  (1).�s�W�b���� "<<endl; 
	cout<<"  (2).�d�߱b���� "<<endl;
	cout<<"  (3).�Τ�s/���� "<<endl; 
	cout<<"  (4).�Τ��/�ٿ� "<<endl; 
	cout<<"  (5).��ܻȦ�l�B "<<endl;
	cout<<"  (6).��ܩҦ���Ʀܿù� "<<endl;  
	cout<<"  (7).�C�L�Ҧ���Ʀ��ɮ� "<<endl;
	cout<<"  (0).���} Exit"<<endl;
	cout<<"�п�J��ܶ���?"<<endl;
	}	
	
};

TW_Account* Insert_TW(TW_Account *TWhead)
{
	TW_Account* p = new TW_Account;
	TW_Account* f = NULL; //Front
    TW_Account* b = NULL; //Behind
    
	int x,y; 
	string n;
	cout<<"�п�J�m�W:"<<endl;
	cin.ignore(); 
	getline(cin, n); 
	cout<<"�п�J����(TWD):"<<endl;
	cin>>y; 
	
	p->write_name(n);
	p->write_S(y);
	p->write_ptr(NULL); 
	
	
	if (TWhead == NULL) 
		{
            TWhead = p;
            f = p;
            b = p;
            x = 10001;
            p->write_ID(x);
            
        }
    
    else 
		{	
			b = TWhead;
			f = TWhead;
			x = 10002;
	
			while (b->read_ptr() != NULL) 
            {
               f = b;
               b = b->read_ptr();
               x = x+1;
        	}
        	
			b->write_ptr(p);
			p->write_ptr(NULL);
			p->write_ID(x);
		
				
		}
		return TWhead;
}

JP_Account* Insert_JP(JP_Account *JPhead)
{
	JP_Account* p = new JP_Account;
	JP_Account* f = NULL; //Front
    JP_Account* b = NULL; //Behind
    
	int x,y; 
	string n;
	cout<<"�п�J�m�W:"<<endl;
	cin.ignore(); 
	getline(cin, n); 
	cout<<"�п�J����(TWD):"<<endl;
	cin>>y; 
	
	p->write_name(n);
	p->write_Save(y);
	p->write_ptr(NULL); 
	
	
	if (JPhead == NULL) 
		{
            JPhead = p;
            f = p;
            b = p;
            x = 20001;
            p->write_ID(x);
            
        }
    
    else 
		{	
			b = JPhead;
			f = JPhead;
			x = 20002;
	
			while (b->read_ptr() != NULL) 
            {
               f = b;
               b = b->read_ptr();
               x = x+1;
        	}
        	
			b->write_ptr(p);
			p->write_ptr(NULL);
			p->write_ID(x);
		
				
		}
		return JPhead;
}

TW_Account* Primt_TW(TW_Account *TWhead)
{
	cout<<"[TW Account]"<<endl;
	cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(�x��)"<<setw(15)<<left<<"�ɴ�(�x��)"<<endl;
	while (TWhead != NULL) 
	{
		cout<<setw(10)<<left<<TWhead->read_ID()<<setw(10)<<left<<TWhead->read_name()<<setw(15)<<left<<TWhead->read_S()<<setw(15)<<left<<TWhead->read_B()<<endl;
        TWhead = TWhead->read_ptr();
    }
    cout<<endl;
}

JP_Account* Primt_JP(JP_Account *JPhead)
{
	cout<<"[JP Account]"<<endl;
	cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(���)"<<setw(15)<<left<<"�ɴ�(���)"<<endl;
	while (JPhead != NULL) 
	{
		cout<<setw(10)<<left<<JPhead->read_ID()<<setw(10)<<left<<JPhead->read_name()<<setw(15)<<left<<JPhead->read_Save()<<setw(15)<<left<<JPhead->read_Borrow()<<endl;
        JPhead = JPhead->read_ptr();
    }
    cout<<endl;
}

void Search (TW_Account *&TWhead , JP_Account *&JPhead )
{
	string name;
	cout<<"�п�J���d�ߩm�W:"<<endl;
	cin.ignore(); 
    getline(cin, name);
    
    TW_Account* TWcheck = TWhead;
    int found = 0;
    
    cout<<"TW Account";

    while (TWcheck != NULL)
    {
        if (TWcheck->read_name() == name)
        {
        	cout<<endl;          
            cout << "ID: " << TWcheck->read_ID()
                 << ", �m�W: " << TWcheck->read_name()
                 << ", �s��(�x��): " << TWcheck->read_S()
                 << ", �ɴ�(�x��): " << TWcheck->read_B() ;
            found++;
        }
        TWcheck = TWcheck->read_ptr();
    }

    if (found == 0)
    {
        cout << "���L�ŦX��ơI�I" << endl;
    }
    
    JP_Account* JPcheck = JPhead;
    
    
    found = 0;
    
    cout<<endl;
    cout<<"JP Account";

    while (JPcheck != NULL)
    {
        if (JPcheck->read_name() == name)
        {
            cout<<endl;          
            cout << "ID: " << JPcheck->read_ID()
                 << ", �m�W: " << JPcheck->read_name()
                 << ", �s��(���): " << JPcheck->read_Save()
                 << ", �ɴ�(���): " << JPcheck->read_Borrow() ;
            found++;
        }
        JPcheck = JPcheck->read_ptr();
    }
	cout<<endl;
    if (found == 0)
    {
        cout << "���L�ŦX��ơI�I" << endl;
    }
		
}

TW_Account* PrimtS_TW(TW_Account *head)
{
	ofstream output("output.txt");
	
	output<<"[TW Account]"<<endl;
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(�x��)"<<setw(15)<<left<<"�ɴ�(�x��)"<<endl;
	while (head != NULL) 
	{
		output<<setw(10)<<left<<head->read_ID()<<setw(10)<<left<<head->read_name()<<setw(15)<<left<<head->read_S()<<setw(15)<<left<<head->read_B()<<endl;
        head = head->read_ptr();
    }
    cout<<endl;
}

JP_Account* PrimtS_JP(JP_Account *head)
{
	
	ofstream output("output.txt");
	output<<"[JP Account]"<<endl;
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(���)"<<setw(15)<<left<<"�ɴ�(���)"<<endl;
	while (head != NULL) 
	{
		output<<setw(10)<<left<<head->read_ID()<<setw(10)<<left<<head->read_name()<<setw(15)<<left<<head->read_Save()<<setw(15)<<left<<head->read_Borrow()<<endl;
        head = head->read_ptr();
    }
    cout<<endl;
}

void Print(TW_Account *&TWhead , JP_Account *&JPhead)
{
	ofstream output("output.txt");
	
	output<<"[TW Account]"<<endl;
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(�x��)"<<setw(15)<<left<<"�ɴ�(�x��)"<<endl;
	while (TWhead != NULL) 
	{
		output<<setw(10)<<left<<TWhead->read_ID()<<setw(10)<<left<<TWhead->read_name()<<setw(15)<<left<<TWhead->read_S()<<setw(15)<<left<<TWhead->read_B()<<endl;
        TWhead = TWhead->read_ptr();
    }
    cout<<endl;
    
    output<<"[JP Account]"<<endl;
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(���)"<<setw(15)<<left<<"�ɴ�(���)"<<endl;
	while (JPhead != NULL) 
	{
		output<<setw(10)<<left<<JPhead->read_ID()<<setw(10)<<left<<JPhead->read_name()<<setw(15)<<left<<JPhead->read_Save()<<setw(15)<<left<<JPhead->read_Borrow()<<endl;
        JPhead = JPhead->read_ptr();
    }
    cout<<endl;

	
}

void Save(TW_Account *&TWhead , JP_Account *&JPhead )
{
	int x,y,z,a;
	cout<<"�п�J�ϥΪ�ID:"<<endl;
	cin>>x;
	
	if( x < 20000)
	{
		TW_Account* p = new TW_Account;
		TW_Account* h = NULL;
    	TW_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==TWhead->read_ID()) //���ק諸�O�Ĥ@��
		{ 
			
			
			cout<<"�п�ܥ\��G"<<endl;
			cout<<"(1).�s��"<<endl;
			cout<<"(2).����"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_S();
						a = a+z;
						p->write_S(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"��e�l�B��:"<<p->read_S()<<endl;
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_S();
						a = a-z;
						p->write_S(a) ;
					}
					
				break;
			
				default:cout<<"�п��1��2�I�I"<<endl;
				break;
				}
				
		} 
		else
		{
			b = TWhead;
			h = TWhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // ���o�Ӯy�� 
            {
            	cout<<"�п�ܥ\��G"<<endl;
				cout<<"(1).�s��"<<endl;
				cout<<"(2).����"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_S();
							a = a+z;
							p->write_S(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"��e�l�B��:"<<p->read_S()<<endl;
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_S();
							a = a-z;
							p->write_S(a) ;
						}
						
					break;
				
					default:cout<<"�п��1��2�I�I"<<endl;
					break;
				}
				
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"���j�M��ŦXID�I�I"<<endl;
			}
		}
		
	}

	else if( x > 20000)
	{
		JP_Account* p = new JP_Account;
		JP_Account* h = NULL;
    	JP_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==JPhead->read_ID()) //���ק諸�O�Ĥ@��
		{ 
			
			
			cout<<"�п�ܥ\��G"<<endl;
			cout<<"(1).�s��"<<endl;
			cout<<"(2).����"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_Save();
						a = a+z;
						p->write_Save(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"��e�l�B��:"<<p->read_Save()<<endl;
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_Save();
						a = a-z;
						p->write_Save(a) ;
					}
					
				break;
			
				default:cout<<"�п��1��2�I�I"<<endl;
				break;
				}
				
		} 
		else
		{
			b = JPhead;
			h = JPhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // ���o�Ӯy�� 
            {
            	cout<<"�п�ܥ\��G"<<endl;
				cout<<"(1).�s��"<<endl;
				cout<<"(2).����"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_Save();
							a = a+z;
							p->write_Save(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"��e�l�B��:"<<p->read_Save()<<endl;
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_Save();
							a = a-z;
							p->write_Save(a) ;
						}
						
					break;
				
					default:cout<<"�п��1��2�I�I"<<endl;
					break;
				}
				
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"���j�M��ŦXID�I�I"<<endl;
			}
		}

	}
}

void Borrow(TW_Account *&TWhead , JP_Account *&JPhead )
{
	int x,y,z,a;
	cout<<"�п�J�ϥΪ�ID:"<<endl;
	cin>>x;
	
	if( x < 20000)
	{
		TW_Account* p = new TW_Account;
		TW_Account* h = NULL;
    	TW_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==TWhead->read_ID()) //���ק諸�O�Ĥ@��
		{ 
			
			
			cout<<"�п�ܥ\��G"<<endl;
			cout<<"(1).�ɿ�"<<endl;
			cout<<"(2).�ٿ�"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_B();
						a = a+z;
						p->write_B(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"��e�ɪ���:"<<p->read_B()<<endl;
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_B();
						a = a-z;
						p->write_B(a) ;
					}
					
				break;
			
				default:cout<<"�п��1��2�I�I"<<endl;
				break;
				}
				
		} 
		else
		{
			b = TWhead;
			h = TWhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // ���o�Ӯy�� 
            {
            	cout<<"�п�ܥ\��G"<<endl;
				cout<<"(1).�ɿ�"<<endl;
				cout<<"(2).�ٿ�"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_B();
							a = a+z;
							p->write_B(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"��e�ɪ���:"<<p->read_B()<<endl;
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_B();
							a = a-z;
							p->write_B(a) ;
						}
						
					break;
				
					default:cout<<"�п��1��2�I�I"<<endl;
					break;
				}
				
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"���j�M��ŦXID�I�I"<<endl;
			}
		}
		
	}

	else if( x > 20000)
	{
		JP_Account* p = new JP_Account;
		JP_Account* h = NULL;
    	JP_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==JPhead->read_ID()) //���ק諸�O�Ĥ@��
		{ 
			
			
			cout<<"�п�ܥ\��G"<<endl;
			cout<<"(1).�ɿ�"<<endl;
			cout<<"(2).�ٿ�"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_Borrow();
						a = a+z;
						p->write_Borrow(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"��e�l�B��:"<<p->read_Borrow()<<endl;
					cout<<"�п�J����(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"���i��J�t�ơI�I"<<endl;
					else
					{
						a = p->read_Borrow();
						a = a-z;
						p->write_Borrow(a) ;
					}
					
				break;
			
				default:cout<<"�п��1��2�I�I"<<endl;
				break;
				}
				
		} 
		else
		{
			b = JPhead;
			h = JPhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //����y�� 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // ���o�Ӯy�� 
            {
            	cout<<"�п�ܥ\��G"<<endl;
				cout<<"(1).�ɿ�"<<endl;
				cout<<"(2).�ٿ�"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_Save();
							a = a+z;
							p->write_Save(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"��e�l�B��:"<<p->read_Save()<<endl;
						cout<<"�п�J����(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"���i��J�t�ơI�I"<<endl;
						else
						{
							a = p->read_Save();
							a = a-z;
							p->write_Save(a) ;
						}
						
					break;
				
					default:cout<<"�п��1��2�I�I"<<endl;
					break;
				}
				
            }
            else //��J�|���n�����y�� 
            {
            	cout<<"���j�M��ŦXID�I�I"<<endl;
			}
		}

	}
}

void save(TW_Account *&TWhead , JP_Account *&JPhead )
{
	ofstream output("data.txt");
	
	while (TWhead != NULL)
	{
		output << TWhead->read_ID() << endl;
		output << TWhead->read_name() << endl;
		output << TWhead->read_S() << endl;
		output << TWhead->read_B() << endl;
		TWhead = TWhead->read_ptr();
	}
	
	output << endl;
	
	while (JPhead != NULL)
	{
		output << JPhead->read_ID() << endl;
		output << JPhead->read_name() << endl;
		output << JPhead->read_Save() << endl;
		output << JPhead->read_Borrow() << endl;
		JPhead = JPhead->read_ptr();
	}
	
	output.close();
	
	

}

int main()
{
	int s,t; //��J�����ﶵ 
	TW_Account *T = NULL; //�ǻ��C�Ӧ�C 
	JP_Account *J = NULL;
	Bank *B = NULL;
	Bank menu;
	
	do
	{
		menu.show();
		cin>>s;
		menu.write_select(s);
		
		switch(menu.read_select())
		{
			case 1:
			cout<<"�п�ܱb�����O"<<endl;
			cout<<"(1).�x��"<<endl;
			cout<<"(2).���"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:T = Insert_TW(T);
				break;
				
				case 2:J = Insert_JP(J);
				break;
				
				
				
				default:cout<<"�п��1��2!!"<<endl;
				break;
			}
			break;
			
			case 2:Search(T,J);
			break;
			
			case 3:Save(T,J);
			break;
			
			case 4:Borrow(T,J);
			break;
				
			case 5:
				cout<<"�ڨӤ��ΰ���"<<endl; 
			break;
				
			case 6:
			Primt_TW(T);
			Primt_JP(J);
			break;
			
			case 7:
			Print(T,J);
			cout<<"�ɮפw��X��output.txt�I�I"<<endl;
			break;
			
			case 0:
			save(T,J);
			break;
			
			
			default:cout<<"�п�J0~7���Ʀr"<<endl;
			break;
		}
		
	}	

	while(menu.read_select() != 0);	
}


