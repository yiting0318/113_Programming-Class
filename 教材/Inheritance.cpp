#include<iostream>

using namespace std;

class A{
private:
	int a_pri=1;
protected:
	int a_pro=2;
public:
	int a_pub=3;
};

class B : public A{
private:
	int b_pri;
	int b_pro;
	int b_pub;
public:
	B(){
		//b_pri=a_pri; �L�k�X�ݤ����O��private 
		b_pro=a_pro;
		b_pub=a_pub;
	}
	int get_b_pri(){
		return b_pri;
	}
	int get_b_pro(){
		return b_pro;
	}
	int get_b_pub(){
		return b_pub;
	}
};

int main(){
	A a;
	//cout<<a.a_pri<<endl; �~���M�l���O���L�k�ϥ� 
	//cout<<a.a_pro<<endl; �~���L�k�ϥ� 
	cout<<a.a_pub<<endl;
	cout<<endl;
	
	B b;	
	//cout<<b.get_b_pri()<<endl; �L�k�X�ݤ����O��private 
	cout<<b.get_b_pro()<<endl;
	cout<<b.get_b_pub()<<endl;
} 
