#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class st_node {
    int no;  // 學生座號
    string name;  // 學生姓名
    int prg;  // 程式設計成績
    st_node* p;  // 指向下一個節點的指標

public:
    void write_no(int x) { no = x; }
    int read_no() { return no; }

    void write_name(string y) { name = y; }
    string read_name() { return name; }

    void write_prg(int z) { prg = z; }
    int read_prg() { return prg; }

    void write_ptr(st_node* ptr) { p = ptr; }
    st_node* read_ptr() { return p; }

    void operator +(int v) {
        prg = prg + v;
    }
};

// 顯示菜單
int memu(int a) {
    cout << "     Menu" << endl;
    cout << "   1.Modify" << endl; // 修改 
    cout << "   2.Search" << endl; // 搜尋 
    cout << "   3.Insert" << endl; // 新增 
    cout << "   4.Delete" << endl; // 刪除 
    cout << "   5.Print" << endl;  // 印出 
    cout << "   6.Exit" << endl;   // 退出 
    cout << "Please Select  one" << endl;
    cin >> a;
    return a;
}

// 修改資料的函數
int Modify(st_node* k) {
    // 修改的實作
}

// 查詢資料的函數
int Search(st_node* k) {
    // 查詢的實作
}

// 插入新節點的函數
st_node* Insert(st_node* k) {
    st_node* p = new st_node;
    st_node* head = k;
    st_node* h = NULL;
    st_node* b = NULL;
    int x, z;
    string y;

    cout << "請輸入學生座號、姓名及成績" << endl;
    cin >> x;  // 輸入學生座號
    cin.get();  // 讀取換行符
    getline(cin, y);  // 輸入學生姓名
    cin >> z;  // 輸入程式設計成績

    p->write_no(x);
    p->write_name(y);
    p->write_prg(z);
    p->write_ptr(NULL);  // 初始化指標為NULL

    // 如果鏈表為空，將新節點設為頭節點
    if (head == NULL) {
        head = p;
    } else {
        st_node* b = head;
        st_node* h = head;

        // 如果新節點的座號比頭節點的座號小，則將新節點放在最前面
        if (p->read_no() < head->read_no()) {
            p->write_ptr(head);
            head = p;  // 新節點成為新的頭節點
        } else {
            // 否則在鏈表中找到合適位置插入
            while (b != NULL && p->read_no() > b->read_no()) {
                h = b;
                b = b->read_ptr();
            }

            // 如果座號重複，則不插入
            if (b != NULL && p->read_no() == b->read_no()) {
                cout << "座號重複" << endl;
            } else {
                // 如果到達最後一個節點，將新節點放在最後
                if (b == NULL) {
                    h->write_ptr(p);
                } else {
                    p->write_ptr(b);
                    h->write_ptr(p);
                }
            }
        }
    }

    return head;  // 返回更新後的頭指標
}

// 刪除資料的函數
int Delete(st_node* k) {
    // 刪除的實作
}

// 列印資料的函數
int Print(st_node* k) {
    if (k == NULL) {
        cout << "尚未存入任何資料" << endl;
    }

    st_node* head1 = k;
    while (head1 != NULL) {
        cout << head1->read_no() << "號學生" << head1->read_name();
        cout << "，成績" << head1->read_prg() << endl;
        head1 = head1->read_ptr();
    }
}

int main() {
    int b, c;
    st_node* k = NULL;  // 初始化鏈表的頭指標為NULL
    do {
        // 根據用戶選擇執行對應操作
        switch (c = memu(b)) {
        case 1:
            Modify(k);  // 修改資料
            break;

        case 2:
            Search(k);  // 查詢資料
            break;

        case 3:
            k = Insert(k);  // 插入新節點，並更新頭指標
            break;

        case 4:
            Delete(k);  // 刪除資料
            break;

        case 5:
            Print(k);  // 列印資料
            break;

        case 6:
            cout << "感謝使用本系統，歡迎下次再來^^" << endl;  // 退出系統
            break;

        default:
            cout << "Wrong select, try again." << endl;  // 錯誤選擇
            break;
        }
    } while (c != 6);  // 當選擇為6時退出程序

    return 0;
}

