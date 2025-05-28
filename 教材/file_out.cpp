#include<iostream>
#include<fstream>

using namespace std;

class A{
public:
	int num;
	char c;
	A *ptr;
};

//輸入資料用 
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
	//首先要定義輸出的位置
	//這裡建議都使用相對路徑 
	ofstream out("data.txt");
	
	/*
	* 下一步是要決定好要存那些資料，以及存資料的方式
	* 要先想好有哪些類型的資料，以及到時候要怎麼讀回來 
	* 以A類別為例，我們要存num, c，所以每筆資料的格式如下(一行一個) 
	* int num
	* char c
	* . 
	* .
	* 直到檔案結束 
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
