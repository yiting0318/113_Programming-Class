#include<iostream>
#include<fstream>

using namespace std;

class A{
public:
	int num;
	char c;
	A *ptr;
};

//��X��ƥ� 
void run(A *node){
	int n=1;
	while(node!=NULL){
		cout<<n++<<". "<<endl;
		cout<<node->num<<endl;
		cout<<node->c<<endl<<endl;
		node=node->ptr;
	}
} 
void load(A *&head){
	//�����n�w�q��J����m
	//�o�̫�ĳ���ϥά۹���| 
	ifstream in("data.txt");
	A *node,*tail=head;
	int num;
	char c;
	/*
	* ���ڭ̤w�g�M�w�n��ƪ��榡�p�U
	* int num
	* char c
	* . 
	* .
	* �]���ڭ̥u�ݭn�@���Ū���ɮ׵����N�n 
	*/ 
	while(in>>num){//�o�ؼg�k�|�b�S��ƥiŪ�ɦ۰ʸ��X�j��A�]������eof() 
		in>>c;
		
		node=new A();
		node->num=num;
		node->c=c;
		node->ptr=NULL;
		if(head==NULL){
			head=node;
		}
		else{
			tail->ptr=node;
		}
		tail=node;
	}
	/*
	* �]���A�W���j�骺�N�䬰���ݬݯण��Ū�J�@��num
	* �p�G�i�H�A�i��j��hŪ�U�@�Ӹ�ƨ÷s�Wnode
	* �Ϥ����}�j��
	* �ѩ�ڭ̦b�g�{���ɤw�g���]�w�n�C����ƪ��̤p��쵲�c�A�ҥH�i�H�ܻ��P�aŪ�J 
	*/ 
	in.close();
}
int main(){
	A *head=NULL;
	
	load(head);
	run(head);
} 
