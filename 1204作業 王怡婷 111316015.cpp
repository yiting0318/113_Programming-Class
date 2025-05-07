#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int memu(int);

int main()
{
	int b,c,x,y;
	
	do
	{
		switch(c=memu(b))
		{
			case 1:cout<<"接下來擲骰子比大小"<<endl;
			
			srand(time(NULL));
			x=rand()%6+1;
			y=rand()%6+1;
			cout<<"你擲出的數字:"<<x<<endl;
			cout<<"電腦擲出的數字:"<<y<<endl;
			if(x>y)
			cout<<"你的數字比電腦大，你贏了!"<<endl;
			else if(x<y)
			cout<<"你的數字比電腦小，你輸了!"<<endl;
			else
			cout<<"你的數字跟電腦一樣，此次平手!"<<endl;
			break;
			
			case 2:cout<<"接下來上課"<<endl;
			break;
			case 3:cout<<"接下來下課"<<endl;
			break;
			case 4:cout<<"接下來離開，歡迎下次再來!"<<endl;
			break;
			default:cout<<"無效輸入，請重新輸入"<<endl;
			break;
		}	
	}
	while(c!=4);
}
	
int memu(int a)
	{
		cout<<"選單"<<endl;
		cout<<"1.擲骰子"<<endl;
		cout<<"2.上課"<<endl;
		cout<<"3.下課"<<endl;
		cout<<"4.離開"<<endl; 
		cout<<"請輸入欲選擇的選項"<<endl;
		cin>>a;
		return a;
	}

	
