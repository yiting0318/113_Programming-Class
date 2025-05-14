#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> // 檔案串流 
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
	int prg;  // 程式設計 
	int eng;  // 英文 
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
	int run;   // 跑步 
	int swim;  // 游泳 
	int ai;    // 人工智慧 
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

//修改_資科 
CMP* Modify_CMP(CMP *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x,z;
		CMP a;
		CMP* p = new CMP;
		CMP* h = NULL;
    	CMP* b = NULL;
		cout<<"請輸入欲修改成績的學生座號"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head->read_no()) //欲修改的是第一個
		{ 
			*head + 5;
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
            	*b + 5;
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

//修改 _體育 
PC* Modify_PC(PC *head_PC)
{
	if(head_PC == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x,z;
		PC a;
		PC* p = new PC;
		PC* h = NULL;
    	PC* b = NULL;
		cout<<"請輸入欲修改成績的學生座號"<<endl;
		cin>>x;
		p->write_no(x);
		
		if(p->read_no()==head_PC->read_no()) //欲修改的是第一個
		{ 
			*head_PC + 5;
			cout<<"該筆資料已調整"<<endl;
		} 
		else
		{
			b = head_PC;
			h = head_PC;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //比較座號 
            {
                h = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // 有這個座號 
            {
            	*b + 5;
				cout<<"該筆資料已成公調整"<<endl;
				
            }
            else //輸入尚未登陸的座號 
            {
            	cout<<"該筆資料不存在，無法調整。"<<endl;
			}
		}
	}
	return head_PC;
}

//搜尋_資科 
CMP* Search_CMP(CMP *head)
{
    if (head == NULL)
    {
        cout << "尚未存入任何資料" << endl;
        return head;
    }

    string name;
    cout << "請輸入欲查詢學生的姓名：" << endl;
    cin.ignore(); 
    getline(cin, name);

    CMP* check = head;
    int found = 0;

    while (check != NULL)
    {
        if (check->read_name() == name)
        {
            cout << "座號: " <<setw(8)<<left<< check->read_no()
                 << ", 姓名: " <<setw(8)<<left<< check->read_name()
                 << ", 程設成績: " <<setw(8)<<left<< check->read_prg() << "分"
                 << ", 英文成績: " <<setw(8)<<left<< check->read_eng() << "分" << endl;
            found++;
        }
        check = check->read_ptr();
    }

    if (found == 0)
    {
        cout << "查無此學生" << endl;
    }

    return head;
}

//搜尋_體育 
PC* Search_PC(PC *head_PC)
{
    if (head_PC == NULL)
    {
        cout << "尚未存入任何資料" << endl;
        return head_PC;
    }

    string name;
    cout << "請輸入欲查詢學生的姓名：" << endl;
    cin.ignore(); 
    getline(cin, name);

    PC* check = head_PC;
    int found = 0;

    while (check != NULL)
    {
        if (check->read_name() == name)
        {
            cout << "座號: " <<setw(8)<<left<< check->read_no()
                 << ", 姓名: " <<setw(8)<<left<< check->read_name()
                 << ", 跑步成績: " <<setw(8)<<left<< check->read_run() << "分"
                 << ", 游泳成績: " <<setw(8)<<left<< check->read_swim() << "分"
                 << ", AI成績: " <<setw(8)<<left<< check->read_ai() << "分" << endl;
            found++;
        }
        check = check->read_ptr();
    }

    if (found == 0)
    {
        cout << "查無此學生" << endl;
    }

    return head_PC;
}

//新增 _資科 
CMP* Insert_CMP(CMP *head)
{
	CMP* p = new CMP; //新增的節點 
    CMP* f = NULL; //Front
    CMP* b = NULL; //Behind
	int x,y,z; //查詢的變數 
	string n;
	cout<<"請輸入學生座號、姓名及程設、英文成績"<<endl;
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
            
            if(p->read_no() < head->read_no()) //放到最前面 
            {
            	p->write_ptr(head);
                head = p;
                f = head;
                b = head;
			}
			else  //數字放後面 
			{	
				b = head;
				f = head;
				
				while (b->read_ptr() != NULL && p->read_no() > b->read_no()) 
                {
                    f = b;
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
                    f->write_ptr(p); 
				}	
			}
        }   
    return head; 
}

//新增 _體育 
PC* Insert_PC(PC *head_PC)
{
	PC* p = new PC; //新增的節點 
    PC* f = NULL; //Front
    PC* b = NULL; //Behind
	int x,y,z,a; //查詢的變數 
	string n;
	cout<<"請輸入學生座號、姓名及跑步、游泳和人工智慧成績"<<endl;
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
            
            if(p->read_no() < head_PC->read_no()) //放到最前面 
            {
            	p->write_ptr(head_PC);
                head_PC = p;
                f = head_PC;
                b = head_PC;
			}
			else  //數字放後面 
			{	
				b = head_PC;
				f = head_PC;
				
				while (b->read_ptr() != NULL && p->read_no() > b->read_no()) 
                {
                    f = b;
                    b = b->read_ptr();
                }

                if (p->read_no() == b->read_no()) // 座號重複
                {
                    cout << "座號已存在"<<endl; 
                    return head_PC;
                }
				
				else if (b->read_ptr() == NULL && p->read_no() > b->read_no()) //在最後一個 
				{
					b->write_ptr(p);
					p->write_ptr(NULL);
				}
				
				else //一般的插入中間 
				{
					p->write_ptr(b);
                    f->write_ptr(p); 
				}	
			}
        }   
    return head_PC; 
}

//刪除_資科 
CMP* Delete_CMP(CMP *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x;
		CMP* p = new CMP;
		CMP* f = NULL; //Front
    	CMP* b = NULL; //Behind 
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
			f = head;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //比較座號 
            {
                f = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // 有這個座號 
            {
            	if(b->read_ptr() == NULL) //在最後一個 
            	{
            		f->write_ptr(NULL);
				}
				else //在串列中間 
				{
					b = b->read_ptr();
                	f->write_ptr(b);
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

//刪除_體育
PC* Delete_PC(PC *head_PC)
{
	if(head_PC == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	
	else
	{
		int x;
		PC* p = new PC;
		PC* f = NULL; //Front
    	PC* b = NULL; //Behind 
		cout<<"請輸入欲刪除學生的座號"<<endl;
		cin>>x;
		p->write_no(x);
	
		if(p->read_no()==head_PC->read_no()) //刪除第一個
		{ 
			if(head_PC->read_ptr() == NULL) //原本就只有一筆資料 
			{
				head_PC = NULL;
				
			}
			else //不只有一筆資料  
			{
				head_PC=head_PC->read_ptr();
				
			}
			cout<<"該筆資料已成公刪除 "<<endl;
		} 
		else
		{
			b = head_PC;
			f = head_PC;
				
			while (b->read_ptr() != NULL && p->read_no() > b->read_no()) //比較座號 
            {
                f = b;
                b = b->read_ptr();
        	}
        	if (p->read_no() == b->read_no()) // 有這個座號 
            {
            	if(b->read_ptr() == NULL) //在最後一個 
            	{
            		f->write_ptr(NULL);
				}
				else //在串列中間 
				{
					b = b->read_ptr();
                	f->write_ptr(b);
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
	return head_PC;
}

//列印串列_ 資科 
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

//列印串列_ 體育 
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

//列印成績單_資科 
void Print_score_CMP(CMP *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	else
	{
		//複製串列
    CMP* original = head;       // 用來遍歷原始串列的指標
    CMP* copy_head = NULL;      // 複製串列的開頭
    CMP* copy_tail = NULL;      // 複製串列的尾端（方便接節點）

    while (original != NULL)
    {
        CMP* p = new CMP();   // 建立新的節點來準備複製資料

        // 複製每個欄位的資料
        p->write_no(original->read_no());         
        p->write_name(original->read_name());    
        p->write_prg(original->read_prg());       
        p->write_eng(original->read_eng());       
        p->write_ptr(NULL);                       

        // 把 p 接到複製串列尾端
        if (copy_head == NULL)   // 第一個節點
        {
            copy_head = p;
            copy_tail = p;
        }
        else
        {
            copy_tail->write_ptr(p);
            copy_tail = p;
        }

        original = original->read_ptr(); // 移動到下一個原串列節點
    }

    // 對 copy_head 進行排序
    CMP* sorted = NULL;   // 排序後的新串列起點

    while (copy_head != NULL)
    {
        CMP* now = copy_head;           // 拿出目前節點準備插入
        copy_head = copy_head->read_ptr(); // 更新複製串列起點
        now->write_ptr(NULL);              // 清掉 now 的下一個指標，避免亂接

        CMP* prev = NULL;   // 插入位置的前一個節點
        CMP* curr = sorted; // 指向 sorted 串列，用來遍歷

        int now_total = now->read_prg() + now->read_eng(); // 計算 now 節點總分

        // 找出 sorted 中第一個比 now 總分小的位置
        while (curr != NULL && (curr->read_prg() + curr->read_eng()) > now_total)
        {
            prev = curr;
            curr = curr->read_ptr();
        }

        // 插入 now 節點
        if (prev == NULL)
        {
            now->write_ptr(sorted); // 插入最前面
            sorted = now;
        }
        else
        {
            prev->write_ptr(now);   // 插入 prev 和 curr 中間
            now->write_ptr(curr);
        }
    }

    //印出成績單
    CMP *head1 = sorted;  // 指向排序後串列的起始點
    int rank = 1;            // 當前名次
    int same_count = 0;      // 與前一位總分相同的人數
    int prev_total = -1;     // 前一位學生的總分，比對是否同分
    
    cout <<setw(6)<<left<<"名次" ;
    cout <<setw(6)<<left<<"姓名" ;
    cout <<setw(6)<<left<<"座號" ;
    cout <<setw(10)<<left<<"程設成績" ;
    cout <<setw(10)<<left<<"英文成績" ;
    cout <<setw(8)<<left<<"總分" << endl;
	
    while (head1 != NULL)
    {
        int total = head1->read_prg() + head1->read_eng(); // 計算學生總分

        // 判斷是否需要更新名次
        if (total != prev_total)
        {
            rank += same_count; // 若跳過同分的名次
            same_count = 1;     // 新一組同分的開始
        }
        else
        {
            same_count++;       // 同分者累加
        }

        prev_total = total;     // 更新目前總分

        // 輸出這位學生的成績與名次
        
        cout <<setw(6)<< rank  ;
        cout <<setw(6)<<head1->read_name() ;
        cout <<setw(6)<<head1->read_no() ;
        cout <<setw(10)<< head1->read_prg() ;
        cout <<setw(10)<< head1->read_eng() ;
        cout <<setw(8)<< total << endl;

        head1 = head1->read_ptr(); // 移動到下一位學生
    }
	}
	
    
}

//列印成績單_體育 
void Print_score_PC(PC *head)
{
	if(head == NULL) 
	{
		cout<<"尚未存入任何資料"<<endl; 
	}
	else
	{
		//複製串列
    PC* original = head;       // 用來遍歷原始串列的指標
    PC* copy_head = NULL;      // 複製串列的開頭
    PC* copy_tail = NULL;      // 複製串列的尾端（方便接節點）

    while (original != NULL)
    {
        PC* p = new PC();   // 建立新的節點來準備複製資料

        // 複製每個欄位的資料
        p->write_no(original->read_no());         
        p->write_name(original->read_name());    
        p->write_run(original->read_run());       
        p->write_swim(original->read_swim());   
		p->write_ai(original->read_ai());    
        p->write_ptr(NULL);                       

        // 把 p 接到複製串列尾端
        if (copy_head == NULL)   // 第一個節點
        {
            copy_head = p;
            copy_tail = p;
        }
        else
        {
            copy_tail->write_ptr(p);
            copy_tail = p;
        }

        original = original->read_ptr(); // 移動到下一個原串列節點
    }

    // 對 copy_head 進行排序
    PC* sorted = NULL;   // 排序後的新串列起點

    while (copy_head != NULL)
    {
        PC* now = copy_head;           // 拿出目前節點準備插入
        copy_head = copy_head->read_ptr(); // 更新複製串列起點
        now->write_ptr(NULL);              // 清掉 now 的下一個指標，避免亂接

        PC* prev = NULL;   // 插入位置的前一個節點
        PC* curr = sorted; // 指向 sorted 串列，用來遍歷

        int now_total = now->read_run() + now->read_swim() + now->read_ai(); // 計算 now 節點總分

        // 找出 sorted 中第一個比 now 總分小的位置
        while (curr != NULL && (curr->read_run() + curr->read_swim() + curr->read_ai()) > now_total)
        {
            prev = curr;
            curr = curr->read_ptr();
        }

        // 插入 now 節點
        if (prev == NULL)
        {
            now->write_ptr(sorted); // 插入最前面
            sorted = now;
        }
        else
        {
            prev->write_ptr(now);   // 插入 prev 和 curr 中間
            now->write_ptr(curr);
        }
    }

    //印出成績單
    PC *head1 = sorted;  // 指向排序後串列的起始點
    int rank = 1;            // 當前名次
    int same_count = 0;      // 與前一位總分相同的人數
    int prev_total = -1;     // 前一位學生的總分，比對是否同分
    
    cout <<setw(6)<<left<<"名次" ;
    cout <<setw(6)<<left<<"姓名" ;
    cout <<setw(6)<<left<<"座號" ;
    cout <<setw(10)<<left<<"跑步成績" ;
    cout <<setw(10)<<left<<"游泳成績" ;
    cout <<setw(8)<<left<<"ai成績" ;
    cout <<setw(8)<<left<<"總分" << endl;
	
    while (head1 != NULL)
    {
        int total = head1->read_run() + head1->read_swim() + head1->read_ai(); // 計算學生總分

        // 判斷是否需要更新名次
        if (total != prev_total)
        {
            rank += same_count; // 若跳過同分的名次
            same_count = 1;     // 新一組同分的開始
        }
        else
        {
            same_count++;       // 同分者累加
        }

        prev_total = total;     // 更新目前總分

        // 輸出這位學生的成績與名次
        
        cout <<setw(6)<< rank  ;
        cout <<setw(6)<<head1->read_name() ;
        cout <<setw(6)<<head1->read_no() ;
        cout <<setw(10)<< head1->read_run() ;
        cout <<setw(10)<< head1->read_swim() ;
        cout <<setw(8)<< head1->read_ai() ;
        cout <<setw(8)<< total << endl;

        head1 = head1->read_ptr(); // 移動到下一位學生
    }
	}
	
    
}

//紀錄資料_資科 
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

//紀錄資料_資科 
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

//寫入資料_資科
CMP* input_CMP(CMP *head)
{
	ifstream input("st_cmp.txt");
	
	CMP* f = NULL;
	int x,y,z; //查詢的變數 
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

//寫入資料_體育 
PC* input_PC(PC *head)
{
	ifstream input("st_pc.txt");
	
	PC* f = NULL;
	int x,y,z,a; //查詢的變數 
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
	int s,t; //輸入的菜單選項 
	CMP *k = NULL; //傳遞每個串列 
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
			cout<<"請選擇科系 1.資科系 2.體育系"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Insert_CMP(k);
				break;
				
				case 2:j = Insert_PC(j);
				break;
				
				default:cout<<"沒有此選項"<<endl;
				break;
			}
			break;
			
			
			case 2:
			cout<<"請選擇科系 1.資科系 2.體育系"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Search_CMP(k);
				break;
				
				case 2:j = Search_PC(j);
				break;
				
				default:cout<<"沒有此選項"<<endl;
				break;
			}
			break;
			
			case 3:
			cout<<"請選擇科系 1.資科系 2.體育系"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Delete_CMP(k);
				break;
				
				case 2:j = Delete_PC(j);
				break;
				
				default:cout<<"沒有此選項"<<endl;
				break;
			}
			break;
			
			case 4:
			cout<<"請選擇科系 1.資科系 2.體育系"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:k = Modify_CMP(k);
				break;
				
				case 2:j = Modify_PC(j);
				break;
				
				default:cout<<"沒有此選項"<<endl;
				break;
			}
			break;
			
			case 5:
			cout<<"請選擇科系 1.資科系 2.體育系"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:Print_no_CMP(k);
				break;
				
				case 2:Print_no_PC(j);
				break;
				
				default:cout<<"沒有此選項"<<endl;
				break;
			}
			break;
			
			case 6:
			cout<<"請選擇科系 1.資科系 2.體育系"<<endl;
			cin>>t;
			switch(t)
			{
				case 1:Print_score_CMP(k);
				break;
				
				case 2:Print_score_PC(j);
				break;
				
				default:cout<<"沒有此選項"<<endl;
				break;
			}
			break;
				
			case 0:
			output_CMP(k);
			output_PC(j);
			cout<<"感謝使用本系統，歡迎下次再來^^"<<endl;
			
			break;
				
			default:cout<<"沒有此選項"<<endl;
			break;
		}
		
	}	

	while(menu.read_select() != 0);	
}
