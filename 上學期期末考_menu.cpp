#include <iostream>
using namespace std;

int memu(int);

int main()
{
	int b,c,h,e;
	
	do
	{
		switch(c=memu(b))
		{
			case 1:cout<<"1���椤"<<endl;
			break;
			
			case 2:cout<<"2���椤"<<endl;
			break;
			
			case 3:cout<<"3���椤"<<endl;
			break;
			
			case 4:cout<<"���}"<<endl;
			break;
			
			default:cout<<"�L�Ŀ�J�A�Э��s��J"<<endl;
			break;
		}	
	}
	while(c!=4);
}
	
int memu(int a)
{
	cout<<"     Game Menu"<<endl;
	cout<<"   1.Dicing Game"<<endl;
	cout<<"   2.Poker Game"<<endl;
	cout<<"   3.Game Record"<<endl;
	cout<<"   4.Exit"<<endl; 
	cout<<"Please Select  one   ";
	cin>>a;
	return a;
}

