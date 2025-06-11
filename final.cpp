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
	int S;  // 餘額 Save 
	int B;  // 借錢 Borrow
	TW_Account* p;
	
public:
	
	JP_Account() //用建構子做初始化 
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
	int Save;  // 餘額 Save 
	int Borrow;  // 借錢 Borrow
	JP_Account* p;
	
public:
	
	JP_Account() //用建構子做初始化 
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
	TW_Account* h;   //台幣帳戶指標 
	JP_Account* j;   //日幣帳戶指標 
	float m;         //銀行剩餘餘額 
	int select;
	
public:
	
	Bank() //用建構子做初始化 
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
	cout<<"         選單 "<<endl; 
	cout<<"  (1).新增帳戶資料 "<<endl; 
	cout<<"  (2).查詢帳戶資料 "<<endl;
	cout<<"  (3).用戶存/取錢 "<<endl; 
	cout<<"  (4).用戶借/還錢 "<<endl; 
	cout<<"  (5).顯示銀行餘額 "<<endl;
	cout<<"  (6).顯示所有資料至螢幕 "<<endl;  
	cout<<"  (7).列印所有資料至檔案 "<<endl;
	cout<<"  (0).離開 Exit"<<endl;
	cout<<"請輸入選擇項目?"<<endl;
	}	
	
};

TW_Account* Insert_TW(TW_Account *TWhead)
{
	TW_Account* p = new TW_Account;
	TW_Account* f = NULL; //Front
    TW_Account* b = NULL; //Behind
    
	int x,y; 
	string n;
	cout<<"請輸入姓名:"<<endl;
	cin.ignore(); 
	getline(cin, n); 
	cout<<"請輸入金錢(TWD):"<<endl;
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
	cout<<"請輸入姓名:"<<endl;
	cin.ignore(); 
	getline(cin, n); 
	cout<<"請輸入金錢(TWD):"<<endl;
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
	cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(台幣)"<<setw(15)<<left<<"借款(台幣)"<<endl;
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
	cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(日幣)"<<setw(15)<<left<<"借款(日幣)"<<endl;
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
	cout<<"請輸入欲查詢姓名:"<<endl;
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
                 << ", 姓名: " << TWcheck->read_name()
                 << ", 存款(台幣): " << TWcheck->read_S()
                 << ", 借款(台幣): " << TWcheck->read_B() ;
            found++;
        }
        TWcheck = TWcheck->read_ptr();
    }

    if (found == 0)
    {
        cout << "內無符合資料！！" << endl;
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
                 << ", 姓名: " << JPcheck->read_name()
                 << ", 存款(日幣): " << JPcheck->read_Save()
                 << ", 借款(日幣): " << JPcheck->read_Borrow() ;
            found++;
        }
        JPcheck = JPcheck->read_ptr();
    }
	cout<<endl;
    if (found == 0)
    {
        cout << "內無符合資料！！" << endl;
    }
		
}

TW_Account* PrimtS_TW(TW_Account *head)
{
	ofstream output("output.txt");
	
	output<<"[TW Account]"<<endl;
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(台幣)"<<setw(15)<<left<<"借款(台幣)"<<endl;
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
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(日幣)"<<setw(15)<<left<<"借款(日幣)"<<endl;
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
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(台幣)"<<setw(15)<<left<<"借款(台幣)"<<endl;
	while (TWhead != NULL) 
	{
		output<<setw(10)<<left<<TWhead->read_ID()<<setw(10)<<left<<TWhead->read_name()<<setw(15)<<left<<TWhead->read_S()<<setw(15)<<left<<TWhead->read_B()<<endl;
        TWhead = TWhead->read_ptr();
    }
    cout<<endl;
    
    output<<"[JP Account]"<<endl;
	output <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(日幣)"<<setw(15)<<left<<"借款(日幣)"<<endl;
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
	cout<<"請輸入使用者ID:"<<endl;
	cin>>x;
	
	if( x < 20000)
	{
		TW_Account* p = new TW_Account;
		TW_Account* h = NULL;
    	TW_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==TWhead->read_ID()) //欲修改的是第一個
		{ 
			
			
			cout<<"請選擇功能："<<endl;
			cout<<"(1).存錢"<<endl;
			cout<<"(2).取錢"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_S();
						a = a+z;
						p->write_S(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"當前餘額為:"<<p->read_S()<<endl;
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_S();
						a = a-z;
						p->write_S(a) ;
					}
					
				break;
			
				default:cout<<"請選擇1或2！！"<<endl;
				break;
				}
				
		} 
		else
		{
			b = TWhead;
			h = TWhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //比較座號 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // 有這個座號 
            {
            	cout<<"請選擇功能："<<endl;
				cout<<"(1).存錢"<<endl;
				cout<<"(2).取錢"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_S();
							a = a+z;
							p->write_S(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"當前餘額為:"<<p->read_S()<<endl;
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_S();
							a = a-z;
							p->write_S(a) ;
						}
						
					break;
				
					default:cout<<"請選擇1或2！！"<<endl;
					break;
				}
				
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"未搜尋到符合ID！！"<<endl;
			}
		}
		
	}

	else if( x > 20000)
	{
		JP_Account* p = new JP_Account;
		JP_Account* h = NULL;
    	JP_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==JPhead->read_ID()) //欲修改的是第一個
		{ 
			
			
			cout<<"請選擇功能："<<endl;
			cout<<"(1).存錢"<<endl;
			cout<<"(2).取錢"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_Save();
						a = a+z;
						p->write_Save(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"當前餘額為:"<<p->read_Save()<<endl;
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_Save();
						a = a-z;
						p->write_Save(a) ;
					}
					
				break;
			
				default:cout<<"請選擇1或2！！"<<endl;
				break;
				}
				
		} 
		else
		{
			b = JPhead;
			h = JPhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //比較座號 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // 有這個座號 
            {
            	cout<<"請選擇功能："<<endl;
				cout<<"(1).存錢"<<endl;
				cout<<"(2).取錢"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_Save();
							a = a+z;
							p->write_Save(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"當前餘額為:"<<p->read_Save()<<endl;
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_Save();
							a = a-z;
							p->write_Save(a) ;
						}
						
					break;
				
					default:cout<<"請選擇1或2！！"<<endl;
					break;
				}
				
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"未搜尋到符合ID！！"<<endl;
			}
		}

	}
}

void Borrow(TW_Account *&TWhead , JP_Account *&JPhead )
{
	int x,y,z,a;
	cout<<"請輸入使用者ID:"<<endl;
	cin>>x;
	
	if( x < 20000)
	{
		TW_Account* p = new TW_Account;
		TW_Account* h = NULL;
    	TW_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==TWhead->read_ID()) //欲修改的是第一個
		{ 
			
			
			cout<<"請選擇功能："<<endl;
			cout<<"(1).借錢"<<endl;
			cout<<"(2).還錢"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_B();
						a = a+z;
						p->write_B(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"當前借金為:"<<p->read_B()<<endl;
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_B();
						a = a-z;
						p->write_B(a) ;
					}
					
				break;
			
				default:cout<<"請選擇1或2！！"<<endl;
				break;
				}
				
		} 
		else
		{
			b = TWhead;
			h = TWhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //比較座號 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // 有這個座號 
            {
            	cout<<"請選擇功能："<<endl;
				cout<<"(1).借錢"<<endl;
				cout<<"(2).還錢"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_B();
							a = a+z;
							p->write_B(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"當前借金為:"<<p->read_B()<<endl;
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_B();
							a = a-z;
							p->write_B(a) ;
						}
						
					break;
				
					default:cout<<"請選擇1或2！！"<<endl;
					break;
				}
				
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"未搜尋到符合ID！！"<<endl;
			}
		}
		
	}

	else if( x > 20000)
	{
		JP_Account* p = new JP_Account;
		JP_Account* h = NULL;
    	JP_Account* b = NULL;
		p->write_ID(x);
		
		if(p->read_ID()==JPhead->read_ID()) //欲修改的是第一個
		{ 
			
			
			cout<<"請選擇功能："<<endl;
			cout<<"(1).借錢"<<endl;
			cout<<"(2).還錢"<<endl;
			cin>>y;
			switch(y)
			{
				case 1:
					
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_Borrow();
						a = a+z;
						p->write_Borrow(a) ;
					}
					
				break;
			
				case 2:
					
					cout<<"當前餘額為:"<<p->read_Borrow()<<endl;
					cout<<"請輸入金錢(TWD):"<<endl;
					cin>>z;
					
					if( z<0 )
					cout<<"不可輸入負數！！"<<endl;
					else
					{
						a = p->read_Borrow();
						a = a-z;
						p->write_Borrow(a) ;
					}
					
				break;
			
				default:cout<<"請選擇1或2！！"<<endl;
				break;
				}
				
		} 
		else
		{
			b = JPhead;
			h = JPhead;
				
			while (b->read_ptr() != NULL && p->read_ID() > b->read_ID()) //比較座號 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_ID() == b->read_ID()) // 有這個座號 
            {
            	cout<<"請選擇功能："<<endl;
				cout<<"(1).借錢"<<endl;
				cout<<"(2).還錢"<<endl;
				cin>>y;
				switch(y)
				{
					case 1:
						
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_Save();
							a = a+z;
							p->write_Save(a) ;
						}
						
					break;
				
					case 2:
						
						cout<<"當前餘額為:"<<p->read_Save()<<endl;
						cout<<"請輸入金錢(TWD):"<<endl;
						cin>>z;
						
						if( z<0 )
						cout<<"不可輸入負數！！"<<endl;
						else
						{
							a = p->read_Save();
							a = a-z;
							p->write_Save(a) ;
						}
						
					break;
				
					default:cout<<"請選擇1或2！！"<<endl;
					break;
				}
				
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"未搜尋到符合ID！！"<<endl;
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
	int s,t; //輸入的菜單選項 
	TW_Account *T = NULL; //傳遞每個串列 
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
			cout<<"請選擇帳戶類別"<<endl;
			cout<<"(1).台幣"<<endl;
			cout<<"(2).日幣"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:T = Insert_TW(T);
				break;
				
				case 2:J = Insert_JP(J);
				break;
				
				
				
				default:cout<<"請選擇1或2!!"<<endl;
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
				cout<<"我來不及做完"<<endl; 
			break;
				
			case 6:
			Primt_TW(T);
			Primt_JP(J);
			break;
			
			case 7:
			Print(T,J);
			cout<<"檔案已輸出至output.txt！！"<<endl;
			break;
			
			case 0:
			save(T,J);
			break;
			
			
			default:cout<<"請輸入0~7的數字"<<endl;
			break;
		}
		
	}	

	while(menu.read_select() != 0);	
}


