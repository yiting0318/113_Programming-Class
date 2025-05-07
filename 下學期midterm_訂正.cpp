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
	
	STNODE() //用建構子做初始化 
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
		int x,z;
		STNODE a;
		STNODE* p = new STNODE;
		STNODE* h = NULL;
    	STNODE* b = NULL;
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

//搜尋 
STNODE* Search(STNODE *head)
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

    STNODE* check = head;
    int found = 0;

    while (check != NULL)
    {
        if (check->read_name() == name)
        {
            cout << "座號: " << check->read_no()
                 << ", 姓名: " << check->read_name()
                 << ", 程設成績: " << check->read_prg() << "分"
                 << ", 英文成績: " << check->read_eng() << "分" << endl;
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

//新增 
STNODE* Insert(STNODE *head)
{
	STNODE* p = new STNODE; //新增的節點 
    STNODE* f = NULL; //Front
    STNODE* b = NULL; //Behind
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
		STNODE* f = NULL; //Front
    	STNODE* b = NULL; //Behind 
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

//列印串列 
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


//列印成績單 
void Print_score(STNODE *head)
{
    //複製串列
    STNODE* original = head;       // 用來遍歷原始串列的指標
    STNODE* copy_head = NULL;      // 複製串列的開頭
    STNODE* copy_tail = NULL;      // 複製串列的尾端（方便接節點）

    while (original != NULL)
    {
        STNODE* p = new STNODE();   // 建立新的節點來準備複製資料

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
    STNODE* sorted = NULL;   // 排序後的新串列起點

    while (copy_head != NULL)
    {
        STNODE* now = copy_head;           // 拿出目前節點準備插入
        copy_head = copy_head->read_ptr(); // 更新複製串列起點
        now->write_ptr(NULL);              // 清掉 now 的下一個指標，避免亂接

        STNODE* prev = NULL;   // 插入位置的前一個節點
        STNODE* curr = sorted; // 指向 sorted 串列，用來遍歷

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
    STNODE *head1 = sorted;  // 指向排序後串列的起始點
    int rank = 1;            // 當前名次
    int same_count = 0;      // 與前一位總分相同的人數
    int prev_total = -1;     // 前一位學生的總分，比對是否同分

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
        cout << "名次: 第" << rank << "名  ";
        cout << "座號: " << head1->read_no();
        cout << ", 姓名: " << head1->read_name();
        cout << ", 程設: " << head1->read_prg() << "分";
        cout << ", 英文: " << head1->read_eng() << "分";
        cout << ", 總分: " << total << "分" << endl;

        head1 = head1->read_ptr(); // 移動到下一位學生
    }
}


int main()
{
	int s; //輸入的菜單選項 
	STNODE *k = NULL; //傳遞每個串列 
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
				
			case 0:cout<<"感謝使用本系統，歡迎下次再來^^"<<endl;
			break;
				
			default:cout<<"沒有此選項"<<endl;
			break;
		}
		
	}	

	while(menu.read_select() != 0);	
}
