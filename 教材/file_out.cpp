#include<iostream>
#include<fstream>

using namespace std;

class A{
public:
	int num;
	char c;
	A *ptr;
};

//��J��ƥ� 
void run(A *&head){
	int ch=-1;
	A *node,*tail=head;
	
	while(ch!=0){
		cout<<"1. add"<<endl;
		cout<<"0. exit"<<endl;
		cin>>ch;
		
		if(ch==1){
			node=new A();
			cout<<"num: ";
			cin>>node->num;
			cout<<"c: ";
			cin>>node->c;
			node->ptr=NULL;
			if(head==NULL){
				head=node;
			}
			else{
				tail->ptr=node;
			}
			tail=node;
		}
	}
} 
void save(A *head){
	//�����n�w�q��X����m
	//�o�̫�ĳ���ϥά۹���| 
	ofstream out("data.txt");
	
	/*
	* �U�@�B�O�n�M�w�n�n�s���Ǹ�ơA�H�Φs��ƪ��覡
	* �n���Q�n��������������ơA�H�Ψ�ɭԭn���Ū�^�� 
	* �HA���O���ҡA�ڭ̭n�snum, c�A�ҥH�C����ƪ��榡�p�U(�@��@��) 
	* int num
	* char c
	* . 
	* .
	* �����ɮ׵��� 
	*/ 
	while(head!=NULL){
		out<<head->num<<endl;
		out<<head->c<<endl;
		head=head->ptr;
	}
	
	out.close();
}
int main(){
	A *head=NULL;
	
	run(head);
	save(head);
} 
