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
			case 1:cout<<"���U���Y��l��j�p"<<endl;
			
			srand(time(NULL));
			x=rand()%6+1;
			y=rand()%6+1;
			cout<<"�A�Y�X���Ʀr:"<<x<<endl;
			cout<<"�q���Y�X���Ʀr:"<<y<<endl;
			if(x>y)
			cout<<"�A���Ʀr��q���j�A�AĹ�F!"<<endl;
			else if(x<y)
			cout<<"�A���Ʀr��q���p�A�A��F!"<<endl;
			else
			cout<<"�A���Ʀr��q���@�ˡA��������!"<<endl;
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
		cout<<"1.�Y��l"<<endl;
		cout<<"2.�W��"<<endl;
		cout<<"3.�U��"<<endl;
		cout<<"4.���}"<<endl; 
		cout<<"�п�J����ܪ��ﶵ"<<endl;
		cin>>a;
		return a;
	}

	
