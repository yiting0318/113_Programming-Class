#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class st_node
{
    int no;
    string name;
	int prg;  // �{���]�p 
	int cmp;  // �p������� 
	int math; // �ƾ� 
	st_node* p;

public:
    void write_no(int x) { no = x; }
    int read_no() { return no; }
    
    void write_name(string u){name = u;}
	string read_name(){return name;}
	
	void write_prg(int y){prg=y;}
	int read_prg(){return prg;}
	
	void write_cmp(int z){cmp=z;}
	int read_cmp(){return cmp;}
	
	void write_math(int w){math=w;}
	int read_math(){return math;}

    void write_ptr(st_node* ptr) { p = ptr; }
    st_node* read_ptr() { return p; }
    
    friend st_node operator+(st_node a, int v);
    

	
};

st_node operator+(st_node a, int v) //operator��bst_node�~�� 
{
    a.prg = a.prg + v; 
    return a; 
}


int main()
{
	st_node a;
	string p;
	a.write_prg(50);
	getline(cin,p);
	a.write_name(p);
	cout<<a.read_prg()<<endl;
	a=a+10;
	cout<<a.read_prg()<<endl;
	cout<<a.read_name()<<endl;
}
