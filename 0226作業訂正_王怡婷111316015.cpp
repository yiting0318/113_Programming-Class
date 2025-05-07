#include <iostream>
#include <cstring>
using namespace std;

class st
{
	int no;
	char name[100];
	int h;
	int w;
	public:
		void w_no(int x){no=x;}
		int r_no(){return no;}
		void w_name(char*u){strcpy(name,u);}//陣列傳遞只能以"址"傳遞，所以要加星星 !! 
		char* r_name(){return name;}//陣列名也是地址位子，所以要把陣列的住址傳出去 
		void w_h(int y){h=y;}
		int r_h(){return h;}
		void w_w(int z){w=z;}
		int r_w(){return w;}
		
		
};

int main()
{
	st a[5];
	for(int i=0;i<5;i++)
	{
		int x,y,z;
		char u[100];
		cout<<"輸入學生"<<i+1<<"的座號、姓名、身高及體重"<<endl;
		
		cin>>x;
		cin.get();
		cin.getline(u,80);
		cin>>y;
		cin>>z;
		
		a[i].w_no(x);
		a[i].w_h(y);
		a[i].w_w(z);
		a[i].w_name(u);
	}
	
	cout<<"學生資料:"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"學生"<<i+1<<": 座號:"<<a[i].r_no()<<", 姓名:"<<a[i].r_name();
		cout<< ", 身高:" << a[i].r_h()<<"公分";
		cout<< ", 體重:" << a[i].r_w() <<"公斤"<< endl;
	}
	return 0;
	
}


