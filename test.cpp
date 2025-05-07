#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class st_node {
    int no;  // �ǥͮy��
    string name;  // �ǥͩm�W
    int prg;  // �{���]�p���Z
    st_node* p;  // ���V�U�@�Ӹ`�I������

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

// ��ܵ��
int memu(int a) {
    cout << "     Menu" << endl;
    cout << "   1.Modify" << endl; // �ק� 
    cout << "   2.Search" << endl; // �j�M 
    cout << "   3.Insert" << endl; // �s�W 
    cout << "   4.Delete" << endl; // �R�� 
    cout << "   5.Print" << endl;  // �L�X 
    cout << "   6.Exit" << endl;   // �h�X 
    cout << "Please Select  one" << endl;
    cin >> a;
    return a;
}

// �ק��ƪ����
int Modify(st_node* k) {
    // �ק諸��@
}

// �d�߸�ƪ����
int Search(st_node* k) {
    // �d�ߪ���@
}

// ���J�s�`�I�����
st_node* Insert(st_node* k) {
    st_node* p = new st_node;
    st_node* head = k;
    st_node* h = NULL;
    st_node* b = NULL;
    int x, z;
    string y;

    cout << "�п�J�ǥͮy���B�m�W�Φ��Z" << endl;
    cin >> x;  // ��J�ǥͮy��
    cin.get();  // Ū�������
    getline(cin, y);  // ��J�ǥͩm�W
    cin >> z;  // ��J�{���]�p���Z

    p->write_no(x);
    p->write_name(y);
    p->write_prg(z);
    p->write_ptr(NULL);  // ��l�ƫ��Ь�NULL

    // �p�G����šA�N�s�`�I�]���Y�`�I
    if (head == NULL) {
        head = p;
    } else {
        st_node* b = head;
        st_node* h = head;

        // �p�G�s�`�I���y�����Y�`�I���y���p�A�h�N�s�`�I��b�̫e��
        if (p->read_no() < head->read_no()) {
            p->write_ptr(head);
            head = p;  // �s�`�I�����s���Y�`�I
        } else {
            // �_�h�b������X�A��m���J
            while (b != NULL && p->read_no() > b->read_no()) {
                h = b;
                b = b->read_ptr();
            }

            // �p�G�y�����ơA�h�����J
            if (b != NULL && p->read_no() == b->read_no()) {
                cout << "�y������" << endl;
            } else {
                // �p�G��F�̫�@�Ӹ`�I�A�N�s�`�I��b�̫�
                if (b == NULL) {
                    h->write_ptr(p);
                } else {
                    p->write_ptr(b);
                    h->write_ptr(p);
                }
            }
        }
    }

    return head;  // ��^��s�᪺�Y����
}

// �R����ƪ����
int Delete(st_node* k) {
    // �R������@
}

// �C�L��ƪ����
int Print(st_node* k) {
    if (k == NULL) {
        cout << "�|���s�J������" << endl;
    }

    st_node* head1 = k;
    while (head1 != NULL) {
        cout << head1->read_no() << "���ǥ�" << head1->read_name();
        cout << "�A���Z" << head1->read_prg() << endl;
        head1 = head1->read_ptr();
    }
}

int main() {
    int b, c;
    st_node* k = NULL;  // ��l������Y���Ь�NULL
    do {
        // �ھڥΤ��ܰ�������ާ@
        switch (c = memu(b)) {
        case 1:
            Modify(k);  // �ק���
            break;

        case 2:
            Search(k);  // �d�߸��
            break;

        case 3:
            k = Insert(k);  // ���J�s�`�I�A�ç�s�Y����
            break;

        case 4:
            Delete(k);  // �R�����
            break;

        case 5:
            Print(k);  // �C�L���
            break;

        case 6:
            cout << "�P�¨ϥΥ��t�ΡA�w��U���A��^^" << endl;  // �h�X�t��
            break;

        default:
            cout << "Wrong select, try again." << endl;  // ���~���
            break;
        }
    } while (c != 6);  // ���ܬ�6�ɰh�X�{��

    return 0;
}

