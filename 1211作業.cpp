#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int memu(int);
int game1(int);
int game2(int);

int main()
{
	int b,c,h,e;
	
	do
	{
		switch(c=memu(b))
		{
			case 1:cout<<"���U���Y��l��j�p"<<endl;
			game1(h);
			break;
			
			case 2:cout<<"�⼳�J�P"<<endl;
			game2(h);
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
	cout<<"2.�⼳�J�P"<<endl;
	cout<<"3.�U��"<<endl;
	cout<<"4.���}"<<endl; 
	cout<<"�п�J����ܪ��ﶵ"<<endl;
	cin>>a;
	return a;
}

int game1(int a1)
{
	int x,y;
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
} 

int game2(int a2)
{
	int d,e;
	
	do
	{
		srand(time(NULL));
		d=rand()%52;
		e=rand()%52;
	}
	while(d==e);
	
	
	if(0<=d&&d<=12)
	cout<<"�A�⪺�P�O-�®�"<<(d%13+1)<<endl;
	else if(13<=d&&d<=25)
	cout<<"�A�⪺�P�O-����"<<(d%13+1)<<endl;
	else if(26<=d&&d<=38)
	cout<<"�A�⪺�P�O-�j��"<<(d%13+1)<<endl;
	else if(39<=d&&d<=51)
	cout<<"�A�⪺�P�O-����"<<(d%13+1)<<endl;
	
	if(0<=e&&e<=12)
	cout<<"�q���⪺�P�O-�®�"<<(e%13+1)<<endl;
	else if(13<=e&&e<=25)
	cout<<"�q���⪺�P�O-����"<<(e%13+1)<<endl;
	else if(26<=e&&e<=38)
	cout<<"�q���⪺�P�O-�j��"<<(e%13+1)<<endl;
	else if(39<=e&&e<=51)
	cout<<"�q���⪺�P�O-����"<<(e%13+1)<<endl;
	
	
	if((d%13+1)>(e%13+1))
	cout<<"�A���P��q���j�A�AĹ�F!"<<endl;
	else if((d%13+1)<(e%13+1))
	cout<<"�A���P��q���p�A�A��F!"<<endl;
	else
	{
		if(d<e)
		cout<<"�A���P��q���j�A�AĹ�F!"<<endl;
		else if(d>e)
		cout<<"�A���P��q���p�A�A��F!"<<endl;
	} 
	
	
}

	
