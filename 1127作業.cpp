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
			case 1:cout<<"���U�ӦҸ�"<<endl;
			break;
			case 2:cout<<"���U�ӤW��"<<endl;
			break;
			case 3:cout<<"���U�ӤU��"<<endl;
			break;
			case 4:cout<<"���U�����}�A�w��U���A��!"<<endl;
			break;
			default:cout<<"�L�Ŀ�J�A�Э��s��J"<<endl;
			break;
		}	
	}
	while(c!=4);
}
	
int memu(int a)
	{
		cout<<"���"<<endl;
		cout<<"1.�Ҹ�"<<endl;
		cout<<"2.�U��"<<endl;
		cout<<"3.�U��"<<endl;
		cout<<"4.���}"<<endl; 
		cout<<"�п�J����ܪ��ﶵ"<<endl;
		cin>>a;
		return a;
	}
	
