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
			case 1:cout<<"接下來擲骰子比大小"<<endl;
			game1(h);
			break;
			
			case 2:cout<<"抽撲克牌"<<endl;
			game2(h);
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
	cout<<"2.抽撲克牌"<<endl;
	cout<<"3.下課"<<endl;
	cout<<"4.離開"<<endl; 
	cout<<"請輸入欲選擇的選項"<<endl;
	cin>>a;
	return a;
}

int game1(int a1)
{
	int x,y;
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
	cout<<"你抽的牌是-黑桃"<<(d%13+1)<<endl;
	else if(13<=d&&d<=25)
	cout<<"你抽的牌是-紅心"<<(d%13+1)<<endl;
	else if(26<=d&&d<=38)
	cout<<"你抽的牌是-磚塊"<<(d%13+1)<<endl;
	else if(39<=d&&d<=51)
	cout<<"你抽的牌是-梅花"<<(d%13+1)<<endl;
	
	if(0<=e&&e<=12)
	cout<<"電腦抽的牌是-黑桃"<<(e%13+1)<<endl;
	else if(13<=e&&e<=25)
	cout<<"電腦抽的牌是-紅心"<<(e%13+1)<<endl;
	else if(26<=e&&e<=38)
	cout<<"電腦抽的牌是-磚塊"<<(e%13+1)<<endl;
	else if(39<=e&&e<=51)
	cout<<"電腦抽的牌是-梅花"<<(e%13+1)<<endl;
	
	
	if((d%13+1)>(e%13+1))
	cout<<"你的牌比電腦大，你贏了!"<<endl;
	else if((d%13+1)<(e%13+1))
	cout<<"你的牌比電腦小，你輸了!"<<endl;
	else
	{
		if(d<e)
		cout<<"你的牌比電腦大，你贏了!"<<endl;
		else if(d>e)
		cout<<"你的牌比電腦小，你輸了!"<<endl;
	} 
	
	
}

	
