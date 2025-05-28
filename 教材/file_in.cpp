#include<iostream>
#include<fstream>

using namespace std;

class A{
public:
	int num;
	char c;
	A *ptr;
};

//輸出資料用 
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
	//首先要定義輸入的位置
	//這裡建議都使用相對路徑 
	ifstream in("data.txt");
	A *node,*tail=head;
	int num;
	char c;
	/*
	* 剛剛我們已經決定好資料的格式如下
	* int num
	* char c
	* . 
	* .
	* 因此我們只需要一行行讀到檔案結束就好 
	*/ 
	while(in>>num){//這種寫法會在沒資料可讀時自動跳出迴圈，因此不需eof() 
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
	* 因此，上面迴圈的意思為先看看能不能讀入一個num
	* 如果可以，進到迴圈去讀下一個資料並新增node
	* 反之離開迴圈
	* 由於我們在寫程式時已經先設定好每筆資料的最小單位結構，所以可以很輕鬆地讀入 
	*/ 
	in.close();
}
int main(){
	A *head=NULL;
	
	load(head);
	run(head);
} 
