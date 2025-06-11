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
            cerr << "�L�k�g�J�ɮ�: " << data << endl;
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
    
    void createAccount() {  //�s�W�b�� 
        int type;
        cout<<"�п�ܱb�����O"<<endl;
		cout<<"(1).�x��"<<endl;
		cout<<"(2).���"<<endl;
        cin >> type;
        
        string name;
        int initialAmount;
        
        cout << "�п�J�m�W: ";
        cin.ignore(); 
		getline(cin, name);
        
        cout << "�п�J��l���B: ";
        cin >> initialAmount;
        
        if (initialAmount < 0) {
            cout << "��l���B���i���t�ơI" << endl;
            return;
        }
        
        if (type == 1) {
            TW_Account* acc = new TW_Account(twNextId++, name, initialAmount);
            addTWAccount(acc);
            total += initialAmount;
            cout << "�b��Ыا����AID: " << acc->getId() << endl;
        } else if (type == 2) {
            JP_Account* acc = new JP_Account(jpNextId++, name, initialAmount);
            addJPAccount(acc);
            total += acc->convertToTWD(initialAmount);
            cout << "�b��Ыا����AID: " << acc->getId() << endl;
        } else {
            cout << "�u���J1��2�I" << endl;
        }
    }
    
    void searchAccount() {  //�j�M 
        string name;
        cout << "�п�J�n�d�ߪ��m�W: ";
        cin.ignore(); 
		getline(cin, name);
        
        bool foundTW = false;
        bool foundJP = false;
        
        cout << "TW Account" ;
        TW_Account* tw = tw_head;
        while (tw != NULL) {
            if (tw->getName() == name) {
            	cout<< endl;
                cout << "ID: " << tw->getId() << ", �m�W: " << tw->getName() << ", �l�B: " << tw->getBalance() << " " << tw->getCurrency() 
                     << ", �ɴ�: " << tw->getBorrow() << " " << tw->getCurrency() ;
                foundTW = true;
            }
            tw = (TW_Account*)tw->getNext();
        }
        if (!foundTW) cout << " ���L�ŦX��ơI�I" ;
        
        cout << endl;
        cout << "JP Account" ;
        JP_Account* jp = jp_head;
        while (jp != NULL) {
            if (jp->getName() == name) {
            	cout<< endl;
                cout << "ID: " << jp->getId() << ", �m�W: " << jp->getName() << ", �l�B: " << jp->getBalance() << " " << jp->getCurrency() 
                     << ", �ɴ�: " << jp->getBorrow() << " " << jp->getCurrency() ;
                foundJP = true;
            }
            jp = (JP_Account*)jp->getNext();
        }
        if (!foundJP) cout << " ���L�ŦX��ơI�I" << endl;
        cout << endl;
    }
    
    void depositWithdraw() { 
        int id;
        cout << "�п�J�ϥΪ� ID: ";
        cin >> id;
        
        Account* acc = findAccount(id);
        if (!acc) {
            cout << "�S���� ID ���b��I" << endl;
            return;
        }
        
        int choice;
        cout << "�п�ܾާ@ "<<endl;
        cout<<"(1).�s��"<<endl;
		cout<<"(2).����"<<endl;
        cin >> choice;
        
        int amount;
        cout << "�п�J���B: ";
        cin >> amount;
        
        if (amount < 0) {
            cout << "���i��J�t�ơI" << endl;
            return;
        }
        
        if (choice == 1) { // �s��
            acc->setBalance(acc->getBalance() + amount);
            total += acc->convertToTWD(amount);
            cout << "�s�����\�I" << endl;
        } else if (choice == 2) { // ����
            if (acc->getBalance() < amount) {
                cout << "�ϥΪ̾l�B�����I" << endl;
                return;
            }
            
            double twdAmount = acc->convertToTWD(amount);
            if (total < twdAmount) {
                cout << "�Ȧ�Ѿl���B�����I" << endl;
                return;
            }
            
            acc->setBalance(acc->getBalance() - amount);
            total -= twdAmount;
            cout << "�������\�I" << endl;
        } else {
            cout << "�u���J1��2�I" << endl;
        }
    }
    
    void borrowRepay() {
        int id;
        cout << "�п�J�ϥΪ� ID: ";
        cin >> id;
        
        Account* acc = findAccount(id);
        if (!acc) {
            cout << "�䤣��� ID ���b��I" << endl;
            return;
        }
        
        int choice;
        cout << "�п�ܾާ@ "<<endl;
        cout<<"(1).�ɿ�"<<endl;
		cout<<"(2).�ٿ�"<<endl;
        cin >> choice;
        
        int amount;
        
        if (choice == 1) { // �ɿ�
        	cout << "�Ȧ��e�l�B: " << fixed << setprecision(2) << total << " TWD" << endl;
        	cout << "�п�J���B: ";
        	cin >> amount;
        	if (amount < 0) {
            cout << "���i��J�t�ơI" << endl;
            return;
       		 }
            double twdAmount = acc->convertToTWD(amount);
            if (total < twdAmount) {
                cout << "�Ȧ�Ѿl���B�����I" << endl;
                return;
            }
            
            acc->setBorrow(acc->getBorrow() + amount);
            total -= twdAmount;
            cout << "�ɿ������I" << endl;
			 
        } 
		
		else if (choice == 2) { // �ٿ�
        	cout << "��e���: " << acc->getBorrow() << " TWD" << endl;
        	cout << "�п�J���B: ";
        	cin >> amount;
        	
        	if (amount < 0) {
            cout << "���i��J�t�ơI" << endl;
            return;
      		  }
            if (acc->getBorrow() < amount) {
                cout << "�ٴڪ��B�W�L�ɴ��`�B�I" << endl;
                return;
            }
            
            acc->setBorrow(acc->getBorrow() - amount);
            total += acc->convertToTWD(amount);
            cout << "�ٿ������I" << endl;
        } else {
            cout << "�u���J1��2�I" << endl;
        }
    }
    
    void showBankBalance() {
        cout << "�Ȧ��e�l�B: " << fixed << setprecision(2) << total << " TWD" << endl;
    }
    
    void displayAllData() {
    	cout << endl; 
        cout << "TW Account" << endl;
        TW_Account* tw = tw_head;
    	cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(�x��)"<<setw(15)<<left<<"�ɴ�(�x��)"<<endl;
        while (tw != NULL) {
            cout << setw(10) <<left<< tw->getId() << setw(15) <<left<< tw->getName() 
                 <<setw(15) <<left<< tw->getBalance() 
                 << setw(15) <<left<< tw->getBorrow()  << endl;
            tw = (TW_Account*)tw->getNext();
        }
        cout << "-----------------------------------------------" << endl;
        cout << "JP Account" << endl;
        JP_Account* jp = jp_head;
        cout <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(���)"<<setw(15)<<left<<"�ɴ�(���)"<<endl;
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
            cerr << "�L�k�g�J�ɮ�: " << output << endl;
            return;
        }
        
        out << "TW Account" << endl;
        TW_Account* tw = tw_head;
        out <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(�x��)"<<setw(15)<<left<<"�ɴ�(�x��)"<<endl;
        while (tw != NULL) {
            out << setw(10) <<left<< tw->getId() << setw(15) <<left<< tw->getName() 
                <<setw(15) <<left<< tw->getBalance() 
                << setw(15) <<left<< tw->getBorrow()  << endl;
            tw = (TW_Account*)tw->getNext();
        }
        
        out << "-----------------------------------------------" << endl;
        out << "JP Account" << endl;
        JP_Account* jp = jp_head;
        out <<setw(10)<<left<<"ID"<<setw(10)<<left<<"�m�W"<<setw(15)<<left<<"�s��(���)"<<setw(15)<<left<<"�ɴ�(���)"<<endl;
        while (jp != NULL) {
            out << setw(10) <<left<< jp->getId() << setw(15) <<left<< jp->getName() 
                << setw(15) <<left<< jp->getBalance() 
                << setw(15) <<left<< jp->getBorrow() << endl;
            jp = (JP_Account*)jp->getNext();
        }
        
        out.close();
        cout << "��Ƥw�s�� " << output << endl;
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
        cout << "     ���" << endl;
        cout << "(1).�s�W�b����" << endl; 
        cout << "(2).�d�߱b����" << endl;
        cout << "(3).�Τ�s�B����" << endl;
        cout << "(4).�Τ�ɡB�ٿ�" << endl;
        cout << "(5).��ܻȦ�l�B" << endl;
        cout << "(6).��ܩҦ����" << endl;
        cout << "(7).�C�L�Ҧ����" << endl;
        cout << "(0).���}" << endl;
        cout << "�п�J��ܶ��ءH" << endl;
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
                    cout << "�t�ε���" << endl;
                    break;
                default:
                    cout << "�п�J0~7���Ʀr�I�I" << endl;
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
