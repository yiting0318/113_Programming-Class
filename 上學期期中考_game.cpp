#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int memu(int a)
{
	cout<<"     Menu"<<endl;
	cout<<"   1.Insert"<<endl; //修改 
	cout<<"   2.Search"<<endl; //搜尋 
	cout<<"   3.Modify"<<endl; //新增 
	cout<<"   4.Delete"<<endl; //刪除 
	cout<<"   5.Exit"<<endl;
	cout<<"Please Select  one"<<endl;
	cin>>a;
	return a;
}

void Dice(int *r)
{
	int x,y;
	char n;
	do
	{
		x=rand()%6+1;
		y=rand()%6+1;
		if(x>y)
		{
			cout<<"You are "<<x<<" and computer is "<<y<<". YOU WIN!!!"<<endl;
			r[0]=r[0]+1;
		}
		
		else if(x<y)
		{
			cout<<"You are "<<x<<" and computer is "<<y<<". YOU LOST!!!"<<endl;
			r[1]=r[1]+1;
		}
		
		else
		{
			cout<<"You are "<<x<<" and computer is "<<y<<". TIED!!!"<<endl;
			r[2]=r[2]+1;
		}
		cout<<"Input y to Play again"<<endl;
		cin>>n;
	}
	while(n=='y');

	
	
	
} 

void Poker(/*int *a,*/int *r)
{
	int d,e,u=0;
	char n;
	int a[52]={0};//每回一次菜單，就會重新洗一次撲克牌 
	
	do
	{
		do
		{
			do
			d=rand()%52;
			while(a[d]==1);
			a[d]=1;
			
			do
			e=rand()%52;
			while(a[e]==1);
			a[e]=1;
			
		}
		while(d==e);
		
		 
		if(0<=d&&d<=12)
		cout<<"You are 黑桃 "<<(d%13+1);
		else if(13<=d&&d<=25)
		cout<<"You are 紅心 "<<(d%13+1);
		else if(26<=d&&d<=38)
		cout<<"You are 方塊 "<<(d%13+1);
		else if(39<=d&&d<=51)
		cout<<"You are 梅花 "<<(d%13+1);
		
		if(0<=e&&e<=12)
		cout<<" and computer is 黑桃 "<<(e%13+1);
		else if(13<=e&&e<=25)
		cout<<" and computer is 紅心 "<<(e%13+1);
		else if(26<=e&&e<=38)
		cout<<" and computer is 方塊 "<<(e%13+1);
		else if(39<=e&&e<=51)
		cout<<" and computer is 梅花 "<<(e%13+1);
		
		
		if((d%13+1)>(e%13+1))
		{
			cout<<"  YOU WIN!!!"<<endl;
			r[0]=r[0]+1;
			u++;
		}
		else if((d%13+1)<(e%13+1))
		{
			cout<<"  YOU LOST!!!"<<endl;
			r[1]=r[1]+1;
			u++;
		}
		else
		{
			if(d<e)
			{
				cout<<"  YOU WIN!!!"<<endl;
				r[0]=r[0]+1;
				u++;
			}
			else if(d>e)
			{
				cout<<"  YOU LOST!!!"<<endl;
				r[1]=r[1]+1;
				u++;
			}
		} 
		cout<<"Input y to Play again"<<endl;
		cin>>n;
		
	}
	while(u!=26&&n=='y');
	
	if(u==26)//不能一次抽超過26次 
	{
		cout<<"NO CARD!!!!!!"<<endl;
		u=0;
	}
}

void Record(int *r)
{
	cout<<"The current record is: you won "<<r[0]<<" times, you lost "<<r[1]<<" times, tied "<<r[2]<<" times."<<endl;
}

int main()
{
	int b,c,h,n;
	float m,e,p;
	srand(time(NULL));
	//int a[52]={0};
	int r[3]={0};
	int *u=0;
	
	do
	{
		switch(c=memu(b))
		{
			case 1:Dice(r);
			break;
			
			case 2:Poker(/*a,*/r);
			break;
			
			case 3:Record(r);
			break;
			
			case 4:cout<<"Thanks for playing games! Come back again."<<endl;
			break;
			
			default:cout<<"Wrong select, try again."<<endl;
			break;
		}	
	}
	while(c!=4);
	e=r[0];
	p=r[1]+r[2]+r[0];
	if(p!=0)
	{
		m=(e/p)*100;
		n=m;
		cout<<"The final record is: you won "<<r[0]<<" times, you lost "<<r[1]<<" times, tied "<<r[2]<<" times."<<endl;
		cout<<"Your winning rate is "<<n<<"%."<<endl;
	}
	else
	{
		cout<<"The final record is: you won 0 times, you lost 0 times, tied 0 times."<<endl; 
		cout<<"Your winning rate is 0%."<<endl;
	}
}
