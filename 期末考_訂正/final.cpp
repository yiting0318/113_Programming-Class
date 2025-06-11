#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

class Account{
	
    int id;
    string name;
public:    
    Account(int id, string name) : id(id), name(name) {}
    virtual ~Account() {}
    
    int getId() const { return id; }
    string getName() const { return name; }
    
    virtual int getBalance() const = 0;
    virtual int getBorrow() const = 0;
    virtual void setBalance(int amount) = 0;
    virtual void setBorrow(int amount) = 0;
    virtual string getType() const = 0;
    virtual string getCurrency() const = 0;
    virtual double convertToTWD(int amount) const = 0;
};

class TW_Account : public Account{
	
    int balance;
    int borrow;
    TW_Account* next;
public:
    TW_Account(int id, string name, int balance): Account(id, name), balance(balance), borrow(0), next(NULL) {}
    
    int getBalance() const override { return balance; }
    int getBorrow() const override { return borrow; }
    void setBalance(int amount) override { balance = amount; }
    void setBorrow(int amount) override { borrow = amount; }
    string getType() const override { return "TW"; }
    string getCurrency() const override { return "TWD"; }
    double convertToTWD(int amount) const override { return amount; }
    TW_Account* getNext() const { return next; }
	void setNext(TW_Account* nxt) { next = nxt; }
};

class JP_Account : public Account{
	
    int balance;
    int borrow;
    JP_Account* next;
public:
    JP_Account(int id, string name, int balance) : Account(id, name), balance(balance), borrow(0), next(NULL) {}
    
    int getBalance() const override { return balance; }
    int getBorrow() const override { return borrow; }
    void setBalance(int amount) override { balance = amount; }
    void setBorrow(int amount) override { borrow = amount; }
    string getType() const override { return "JP"; }
    string getCurrency() const override { return "JPY"; }
    double convertToTWD(int amount) const override { return amount * 0.2; }
    JP_Account* getNext() const { return next; }
	void setNext(JP_Account* nxt) { next = nxt; }
};

class Bank{
	
    double total;
    TW_Account *tw_head, *tw_tail;
    JP_Account *jp_head, *jp_tail;
    string output, data;
    int twNextId, jpNextId;
    
    Account* findAccount(int id) {
        TW_Account* tw = tw_head;
        while (tw != NULL) {
            if (tw->getId() == id) return tw;
            tw = (TW_Account*)tw->getNext();
        }
        
        JP_Account* jp = jp_head;
        while (jp != NULL) {
            if (jp->getId() == id) return jp;
            jp = (JP_Account*)jp->getNext();
        }
        return NULL;
    }
    
    void save() {
        ofstream out("data.txt");
        if (!out) {
            cerr << "無法寫入檔案: " << data << endl;
            return;
        }
        
        out << fixed << setprecision(2) << total << endl;
        
        TW_Account* tw = tw_head;
        while (tw != NULL) {
            out << tw->getType() << " " 
                << tw->getId() << " " 
                << tw->getName() << " " 
                << tw->getBalance() << " " 
                << tw->getBorrow() << endl;
            tw = (TW_Account*)tw->getNext();
        }
        
        JP_Account* jp = jp_head;
        while (jp != NULL) {
            out << jp->getType() << " " 
                << jp->getId() << " " 
                << jp->getName() << " " 
                << jp->getBalance() << " " 
                << jp->getBorrow() << endl;
            jp = (JP_Account*)jp->getNext();
        }
        
        out.close();
    }
    
    void load() {
        ifstream in("data.txt");
        if (!in) return;
        
        in >> total;
        
        string type, name;
        int id, balance, borrow;
        
        while (in >> type >> id >> name >> balance >> borrow) {
            if (type == "TW") {
                TW_Account* acc = new TW_Account(id, name, balance);
                acc->setBorrow(borrow);
                addTWAccount(acc);
                if (id >= twNextId) twNextId = id + 1;
            } else if (type == "JP") {
                JP_Account* acc = new JP_Account(id, name, balance);
                acc->setBorrow(borrow);
                addJPAccount(acc);
                if (id >= jpNextId) jpNextId = id + 1;
            }
        }
        
        in.close();
    }
    
    void addTWAccount(TW_Account* acc) {
        if (tw_head == NULL) {
            tw_head = acc;
            tw_tail = acc;
        } else {
            tw_tail->setNext(acc);
            tw_tail = acc;
        }
    }
    
    void addJPAccount(JP_Account* acc) {
        if (jp_head == NULL) {
            jp_head = acc;
            jp_tail = acc;
        } else {
            jp_tail->setNext(acc);
            jp_tail = acc;
        }
    }
    
    void createAccount() {  //新增帳戶 
        int type;
        cout<<"請選擇帳戶類別"<<endl;
		cout<<"(1).台幣"<<endl;
		cout<<"(2).日幣"<<endl;
        cin >> type;
        
        string name;
        int initialAmount;
        
        cout << "請輸入姓名: ";
        cin.ignore(); 
		getline(cin, name);
        
        cout << "請輸入初始金額: ";
        cin >> initialAmount;
        
        if (initialAmount < 0) {
            cout << "初始金額不可為負數！" << endl;
            return;
        }
        
        if (type == 1) {
            TW_Account* acc = new TW_Account(twNextId++, name, initialAmount);
            addTWAccount(acc);
            total += initialAmount;
            cout << "帳戶創建完成，ID: " << acc->getId() << endl;
        } else if (type == 2) {
            JP_Account* acc = new JP_Account(jpNextId++, name, initialAmount);
            addJPAccount(acc);
            total += acc->convertToTWD(initialAmount);
            cout << "帳戶創建完成，ID: " << acc->getId() << endl;
        } else {
            cout << "只能輸入1或2！" << endl;
        }
    }
    
    void searchAccount() {  //搜尋 
        string name;
        cout << "請輸入要查詢的姓名: ";
        cin.ignore(); 
		getline(cin, name);
        
        bool foundTW = false;
        bool foundJP = false;
        
        cout << "TW Account" ;
        TW_Account* tw = tw_head;
        while (tw != NULL) {
            if (tw->getName() == name) {
            	cout<< endl;
                cout << "ID: " << tw->getId() << ", 姓名: " << tw->getName() << ", 餘額: " << tw->getBalance() << " " << tw->getCurrency() 
                     << ", 借款: " << tw->getBorrow() << " " << tw->getCurrency() ;
                foundTW = true;
            }
            tw = (TW_Account*)tw->getNext();
        }
        if (!foundTW) cout << " 內無符合資料！！" ;
        
        cout << endl;
        cout << "JP Account" ;
        JP_Account* jp = jp_head;
        while (jp != NULL) {
            if (jp->getName() == name) {
            	cout<< endl;
                cout << "ID: " << jp->getId() << ", 姓名: " << jp->getName() << ", 餘額: " << jp->getBalance() << " " << jp->getCurrency() 
                     << ", 借款: " << jp->getBorrow() << " " << jp->getCurrency() ;
                foundJP = true;
            }
            jp = (JP_Account*)jp->getNext();
        }
        if (!foundJP) cout << " 內無符合資料！！" << endl;
        cout << endl;
    }
    
    void depositWithdraw() { 
        int id;
        cout << "請輸入使用者 ID: ";
        cin >> id;
        
        Account* acc = findAccount(id);
        if (!acc) {
            cout << "沒有此 ID 的帳戶！" << endl;
            return;
        }
        
        int choice;
        cout << "請選擇操作 "<<endl;
        cout<<"(1).存錢"<<endl;
		cout<<"(2).取錢"<<endl;
        cin >> choice;
        
        int amount;
        cout << "請輸入金額: ";
        cin >> amount;
        
        if (amount < 0) {
            cout << "不可輸入負數！" << endl;
            return;
        }
        
        if (choice == 1) { // 存錢
            acc->setBalance(acc->getBalance() + amount);
            total += acc->convertToTWD(amount);
            cout << "存錢成功！" << endl;
        } else if (choice == 2) { // 取錢
            if (acc->getBalance() < amount) {
                cout << "使用者餘額不足！" << endl;
                return;
            }
            
            double twdAmount = acc->convertToTWD(amount);
            if (total < twdAmount) {
                cout << "銀行剩餘金額不足！" << endl;
                return;
            }
            
            acc->setBalance(acc->getBalance() - amount);
            total -= twdAmount;
            cout << "取錢成功！" << endl;
        } else {
            cout << "只能輸入1或2！" << endl;
        }
    }
    
    void borrowRepay() {
        int id;
        cout << "請輸入使用者 ID: ";
        cin >> id;
        
        Account* acc = findAccount(id);
        if (!acc) {
            cout << "找不到該 ID 的帳戶！" << endl;
            return;
        }
        
        int choice;
        cout << "請選擇操作 "<<endl;
        cout<<"(1).借錢"<<endl;
		cout<<"(2).還錢"<<endl;
        cin >> choice;
        
        int amount;
        
        if (choice == 1) { // 借錢
        	cout << "銀行當前餘額: " << fixed << setprecision(2) << total << " TWD" << endl;
        	cout << "請輸入金額: ";
        	cin >> amount;
        	if (amount < 0) {
            cout << "不可輸入負數！" << endl;
            return;
       		 }
            double twdAmount = acc->convertToTWD(amount);
            if (total < twdAmount) {
                cout << "銀行剩餘金額不足！" << endl;
                return;
            }
            
            acc->setBorrow(acc->getBorrow() + amount);
            total -= twdAmount;
            cout << "借錢完成！" << endl;
			 
        } 
		
		else if (choice == 2) { // 還錢
        	cout << "當前欠款: " << acc->getBorrow() << " TWD" << endl;
        	cout << "請輸入金額: ";
        	cin >> amount;
        	
        	if (amount < 0) {
            cout << "不可輸入負數！" << endl;
            return;
      		  }
            if (acc->getBorrow() < amount) {
                cout << "還款金額超過借款總額！" << endl;
                return;
            }
            
            acc->setBorrow(acc->getBorrow() - amount);
            total += acc->convertToTWD(amount);
            cout << "還錢完成！" << endl;
        } else {
            cout << "只能輸入1或2！" << endl;
        }
    }
    
    void showBankBalance() {
        cout << "銀行當前餘額: " << fixed << setprecision(2) << total << " TWD" << endl;
    }
    
    void displayAllData() {
    	cout << endl; 
        cout << "TW Account" << endl;
        TW_Account* tw = tw_head;
    	cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(台幣)"<<setw(15)<<left<<"借款(台幣)"<<endl;
        while (tw != NULL) {
            cout << setw(10) <<left<< tw->getId() << setw(15) <<left<< tw->getName() 
                 <<setw(15) <<left<< tw->getBalance() 
                 << setw(15) <<left<< tw->getBorrow()  << endl;
            tw = (TW_Account*)tw->getNext();
        }
        cout << "-----------------------------------------------" << endl;
        cout << "JP Account" << endl;
        JP_Account* jp = jp_head;
        cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(日幣)"<<setw(15)<<left<<"借款(日幣)"<<endl;
        while (jp != NULL) {
            cout << setw(10) <<left<< jp->getId() << setw(15) <<left<< jp->getName() 
                << setw(15) <<left<< jp->getBalance() 
                << setw(15) <<left<< jp->getBorrow() << endl;
            jp = (JP_Account*)jp->getNext();
        }
        cout << endl; 
    }
    
    void printAllData() {
        ofstream out("output.txt");
        if (!out) {
            cerr << "無法寫入檔案: " << output << endl;
            return;
        }
        
        out << "TW Account" << endl;
        TW_Account* tw = tw_head;
        out <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(台幣)"<<setw(15)<<left<<"借款(台幣)"<<endl;
        while (tw != NULL) {
            out << setw(10) <<left<< tw->getId() << setw(15) <<left<< tw->getName() 
                <<setw(15) <<left<< tw->getBalance() 
                << setw(15) <<left<< tw->getBorrow()  << endl;
            tw = (TW_Account*)tw->getNext();
        }
        
        out << "-----------------------------------------------" << endl;
        out << "JP Account" << endl;
        JP_Account* jp = jp_head;
        out <<setw(10)<<left<<"ID"<<setw(10)<<left<<"姓名"<<setw(15)<<left<<"存款(日幣)"<<setw(15)<<left<<"借款(日幣)"<<endl;
        while (jp != NULL) {
            out << setw(10) <<left<< jp->getId() << setw(15) <<left<< jp->getName() 
                << setw(15) <<left<< jp->getBalance() 
                << setw(15) <<left<< jp->getBorrow() << endl;
            jp = (JP_Account*)jp->getNext();
        }
        
        out.close();
        cout << "資料已存至 " << output << endl;
    }

public:
    Bank(string output, string data) : output(output), data(data) {
        total = 0.0;
        tw_head = NULL;
        jp_head = NULL;
        tw_tail = NULL;
        jp_tail = NULL;
        twNextId = 10001;
        jpNextId = 20001;
        load();
    }
    
    ~Bank() {
        TW_Account* tw = tw_head;
        while (tw != NULL) {
            TW_Account* temp = tw;
            tw = (TW_Account*)tw->getNext();
            delete temp;
        }
        
        JP_Account* jp = jp_head;
        while (jp != NULL) {
            JP_Account* temp = jp;
            jp = (JP_Account*)jp->getNext();
            delete temp;
        }
    }
    
    void menu() {
        cout << "     選單" << endl;
        cout << "(1).新增帳戶資料" << endl; 
        cout << "(2).查詢帳戶資料" << endl;
        cout << "(3).用戶存、取錢" << endl;
        cout << "(4).用戶借、還錢" << endl;
        cout << "(5).顯示銀行餘額" << endl;
        cout << "(6).顯示所有資料" << endl;
        cout << "(7).列印所有資料" << endl;
        cout << "(0).離開" << endl;
        cout << "請輸入選擇項目？" << endl;
    }
    
    void run() {
        int choice = -1;
        
        while (choice != 0) {
            menu();
            cin >> choice;
            
            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    searchAccount();
                    break;
                case 3:
                    depositWithdraw();
                    break;
                case 4:
                    borrowRepay();
                    break;
                case 5:
                    showBankBalance();
                    break;
                case 6:
                    displayAllData();
                    break;
                case 7:
                    printAllData();
                    break;
                case 0:
                    save();
                    cout << "系統結束" << endl;
                    break;
                default:
                    cout << "請輸入0~7的數字！！" << endl;
            }
        }
    }
};

int main() {
    string output = "output.txt";
    string data = "data.txt";
    
    Bank bank(output, data);
    bank.run();
    
    return 0;
}
