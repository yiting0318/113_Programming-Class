#include <iostream>
#include <string>
using namespace std;

class STNODE
{
    int no;
    string name;
	int prg;  // 程式設計 
	int eng;  // 英文 
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
	cout<<"          選單 Menu"<<endl; 
	cout<<"  (1).新增學生資料 Insertion"<<endl; //新增
	cout<<"  (2).查詢學生資料 Search"<<endl; //搜尋
	cout<<"  (3).刪除學生資料 Delete"<<endl; // 刪除
	cout<<"  (4).調整學生成績 Modify"<<endl; //修改 
	cout<<"  (5).列印串列資料 Print List Data"<<endl;//印出 (依照座號)
	cout<<"  (6).列印學生成績單 Print Transcript"<<endl;  //印出 (依照成績)
	cout<<"  (0).離開 Exit"<<endl;
	cout<<"請輸入選擇項目? Please Select  one"<<endl;
	}	
};

//修改
STNODE* Modify(STNODE *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x,y,z;
		STNODE a;
		STNODE* p = new STNODE;
		STNODE* h = NULL;
    	STNODE* b = NULL;
		cout<<"請輸入欲修改成績的學生座號"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head->read_no()) //欲修改的是第一個
		{ 
			*head + y;
			cout<<"該筆資料已調整"<<endl;
		} 
		else
		{
			b = head;
			h = head;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //比較座號 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // 有這個座號 
            {
            	*b + y;
				cout<<"該筆資料已成公調整"<<endl;
				
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"該筆資料不存在，無法調整。"<<endl;
			}
		}
	}
	return head;
}

//搜尋 
STNODE* Search(STNODE *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		string n;
		STNODE* p = new STNODE;
		STNODE* h = head;
    	STNODE* b = head;
    	STNODE* e = head;
    	int i = 0 ;
		cout<<"請輸入欲查詢學生的姓名"<<endl;
		cin>>n;
		p->write_name(n);
		
		
        if(b->read_ptr() != NULL)
		{
			do
			{	
			
        		if(p->read_name() == b->read_name())
        		{
        			cout<<"座號:"<<b->read_no();
					cout<<",姓名:"<<b->read_name();
					cout<<",程設成績: " << b->read_prg()<<"分";
					cout<<",英文成績: " << b->read_eng()<<"分"<<endl; 
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
            if (p->read_name() == h->read_name() && e->read_no() != h->read_no()) // 有這個座號 
	            {
	            	cout<<"座號:"<<h->read_no();
					cout<<",姓名:"<<h->read_name();
					cout<<",程設成績: " << h->read_prg()<<"分";
					cout<<",英文成績: " << h->read_eng()<<"分"<<endl; 
					i++;
	            }
		}
		else
		{
			if(p->read_name()==head->read_name()) //查詢的是第一個
			{ 
				cout<<"座號:"<<head->read_no();
				cout<<",姓名:"<<head->read_name();
				cout<<",程設成績: " << head->read_prg()<<"分";
				cout<<"英文成績: " << head->read_eng()<<"分"<<endl;
				i++;
			} 
		}
		
		  
        if(i == 0)    
        {
        	cout<<"該學生不存在"<<endl;
       	}	
		
	}
	return head;
}

//新增 
STNODE* Insert(STNODE *head)
{
	STNODE* p = new STNODE;
    STNODE* h = NULL;
    STNODE* b = NULL;
	int x,y,z;
	string n;
	cout<<"請輸入學生座號、姓名及程設、英文成績"<<endl;
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
            
            if(p->read_no() < head->read_no()) //放到最前面 
            {
            	p->write_ptr(head);
                head = p;
                h = head;
                b = head;
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
                    cout << "座號已存在"<<endl; 
                    return head;
                }
				
				else if (b->read_ptr() == NULL && p->read_no() > b->read_no()) //在最後一個 
				{
					b->write_ptr(p);
					p->write_ptr(NULL);
				}
				
				else //一般的插入中間 
				{
					p->write_ptr(b);
                    h->write_ptr(p); 
				}	
			}
        }   
    return head; 
}

//刪除 
STNODE* Delete(STNODE *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x;
		STNODE* p = new STNODE;
		STNODE* h = NULL;
    	STNODE* b = NULL;
		cout<<"請輸入欲刪除學生的座號"<<endl;
		cin>>x;
		p->write_no(x);
	
		if(p->read_no()==head->read_no()) //刪除第一個
		{ 
			if(head->read_ptr() == NULL) //原本就只有一筆資料 
			{
				head = NULL;
				
			}
			else //不只有一筆資料  
			{
				head=head->read_ptr();
				
			}
			cout<<"該筆資料已成公刪除 "<<endl;
		} 
		else
		{
			b = head;
			h = head;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //比較座號 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // 有這個座號 
            {
            	if(b->read_ptr() == NULL) //在最後一個 
            	{
            		h->write_ptr(NULL);
				}
				else //在串列中間 
				{
					b = b->read_ptr();
                	h->write_ptr(b);
				}
				//cout<<"刪除成功!"<<endl;
				cout<<"該筆資料已成公刪除 "<<endl;	
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"該筆資料不存在，無法刪除"<<endl;
			}
		}
	}
	return head;
}

//列印串列 
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

//列印成績單 
void Print_score(STNODE *k)
{
    if (k == NULL)
    {
        cout << "尚未存入任何資料" << endl;
        return;
    }

    STNODE *p[50]; // 存每位學生的資料 
    int total[50];   // 存每位學生的總分
    int i = 0;

    STNODE *head1 = k;
    while (head1 != NULL && i < 50) //把總和塞到 total 陣列裡 
    {
        p[i] = head1;
        total[i] = head1->read_prg() + head1->read_eng() ;
        i++;
        head1 = head1->read_ptr();
    }

    for (int a = 0; a < i - 1; a++) // 總分用泡泡排序法排序  //總共會需要比較 i-1 輪  
    {
        for (int b = 0; b < i - a - 1; b++) 
        {
            if (total[b] < total[b + 1])
            {
                swap(total[b], total[b + 1]);
                swap(p[b], p[b + 1]); // 讓資料跟總分一起同步排序 
            }
        }
    }

    for (int j = 0; j < i; j++)
    {
    	if( total[j] == total[j - 1] )
    	{
    		cout << "名次: " << j;
		}
    	else
    	{
    		cout << "名次: " << j+1;
		}
        cout << "座號: " << p[j]->read_no();
        cout << ", 姓名: " << p[j]->read_name();
        cout << ", 程設: " << p[j]->read_prg() << "分";
        cout << ", 英文: " << p[j]->read_eng() << "分";
        cout << ", 總分: " << total[j] << "分" << endl;
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
			cout<<"沒有此選項"<<endl; 
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
				
				case 0:cout<<"感謝使用本系統，歡迎下次再來^^"<<endl;
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
    // 先複製原串列，避免破壞原本的結構
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

    // 開始排序 copy_head，依照總分由大到小
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

    // 列印排序後的成績單與名次（含同分處理）
    STNODE* p = sorted;
    int rank = 1;
    int prev_score = -1;
    int tie_count = 0;

    cout << "\n========= 成績單 =========\n";
    cout << "名次  座號  姓名\t程設\t英文\t總分\n";

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

