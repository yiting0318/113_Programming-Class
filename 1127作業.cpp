#include <iostream>
using namespace std;

int memu(int);

int main()
{
	int b,c;
	
	do
	{
		switch(c=memu(b))
		{
			case 1:cout<<"接下來考試"<<endl;
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
		cout<<"1.考試"<<endl;
		cout<<"2.下課"<<endl;
		cout<<"3.下課"<<endl;
		cout<<"4.離開"<<endl; 
		cout<<"請輸入欲選擇的選項"<<endl;
		cin>>a;
		return a;
	}
	
