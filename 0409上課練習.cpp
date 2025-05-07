#include <iostream>
#include <string>
using namespace std;

class st_node
{
    int no;
    string name;
	int prg;  // 程式設計 
	int cmp;  // 計算機概論 
	int math; // 數學 
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
	cout<<"   1.Insert"<<endl; //新增
	cout<<"   2.Search"<<endl; //搜尋
	cout<<"   3.Modify"<<endl; //修改 
	cout<<"   4.Delete"<<endl; //刪除 
	cout<<"   5.Print_no"<<endl;//印出 (依照座號)
	cout<<"   6.Print_score"<<endl;  //印出 (依照成績)
	cout<<"   0.Exit"<<endl;
	cout<<"Please Select  one"<<endl;
	}	
};

st_node* Modify(st_node *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x,y,z;
		st_node a;
		st_node* p = new st_node;
		st_node* h = NULL;
    	st_node* b = NULL;
		cout<<"請輸入欲修改程式設計成績的學生座號"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head->read_no()) //欲修改的是第一個
		{ 
			cout<<"目前成績: " << head->read_prg()<<"分"<<endl;
			cout<<"請輸入欲加減的分數"<<endl;
			z = head->read_prg();
			cin>>y;
			*head + y;
			cout<<"更新完成"<<endl;
			cout<<head->read_no()<<"號的成績已從 "<<z<<" 分更新為 "<<head->read_prg()<<" 分"<<endl;
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
            	cout<<"目前成績: " << b->read_prg()<<"分"<<endl;
				cout<<"請輸入欲加減的分數"<<endl;
				z = b->read_prg();
				cin>>y;
            	*b + y;
				cout<<"更新完成"<<endl;
				cout<<b->read_no()<<"號的成績已從 "<<z<<" 分更新為 "<<b->read_prg()<<" 分"<<endl;
            	cout<<"請輸入欲修改的分數"<<endl;
				
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"此座號不存在!"<<endl;
			}
		}
	}
	return head;
}

st_node* Search(st_node *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x;
		st_node* p = new st_node;
		st_node* h = NULL;
    	st_node* b = NULL;
		cout<<"請輸入欲查詢學生的座號"<<endl;
		cin>>x;
		p->write_no(x);
	
		if(p->read_no()==head->read_no()) //查詢的是第一個
		{ 
			cout<<"座號:"<<head->read_no();
			cout<<",姓名:"<<head->read_name();
			cout<<",程設成績: " << head->read_prg()<<"分";
			cout<<",計概成績: " << head->read_cmp()<<"分";
			cout<<",數學成績: " << head->read_math()<<"分"<<endl;
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
            	cout<<"座號:"<<b->read_no();
				cout<<",姓名:"<<b->read_name();
				cout<<",程設成績: " << b->read_prg()<<"分";
				cout<<",計概成績: " << b->read_cmp()<<"分";
				cout<<",數學成績: " << b->read_math()<<"分"<<endl;
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"此座號不存在!"<<endl;
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
	cout<<"請輸入學生座號、姓名及三科的成績"<<endl;
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


st_node* Delete(st_node *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x;
		st_node* p = new st_node;
		st_node* h = NULL;
    	st_node* b = NULL;
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
			//cout<<" 刪除成功 "<<endl;  為什麼不能打出"功"字!!! 氣死了!! 只要輸出有"功"字就會錯誤 QAQ
			cout<<"刪除完成 "<<endl;
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
				cout<<"刪除完成 "<<endl;	
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"此座號不存在!"<<endl;
			}
		}
	}
	return head;
}

void Print_no(st_node *k)
{
	if(k == NULL)
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	st_node* head1 = k;
    while (head1 != NULL) 
	{
		cout<<"座號:"<<head1->read_no();
		cout<<",姓名:"<<head1->read_name();
		cout<<",程設成績: " << head1->read_prg()<<"分";
		cout<<",計概成績: " << head1->read_cmp()<<"分";
		cout<<",數學成績: " << head1->read_math()<<"分"<<endl;
        head1 = head1->read_ptr();
    }
}

void Print_score(st_node *k)
{
    if (k == NULL)
    {
        cout << "尚未存入任何資料" << endl;
        return;
    }

    st_node *p[50]; // 存每位學生的資料 
    int total[50];   // 存每位學生的總分
    int i = 0;

    st_node *head1 = k;
    while (head1 != NULL && i < 50) //把總和塞到 total 陣列裡 
    {
        p[i] = head1;
        total[i] = head1->read_prg() + head1->read_cmp() + head1->read_math();
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
            } //老師說節點可以直接做交換，但要自己另外定義或是三部曲用， 但我沒懂啥學生節點交換，這部分待研究!! 
        }
    }

    for (int j = 0; j < i; j++)
    {
        cout << "座號: " << p[j]->read_no();
        cout << ", 姓名: " << p[j]->read_name();
        cout << ", 程設: " << p[j]->read_prg() << "分";
        cout << ", 計概: " << p[j]->read_cmp() << "分";
        cout << ", 數學: " << p[j]->read_math() << "分";
        cout << ", 總分: " << total[j] << "分" << endl;
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
				
				case 3:k = Modify(k);
				break;
				
				case 4:k = Delete(k);
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
