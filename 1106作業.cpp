#include <iostream>
using namespace std;
int main()
{
	int h,m,s,a;
	a==0;
	do
	{
		cout<<"請輸入小時"<<endl;
		cin>>h;
		
		if(h<0 || h>=24)
		cout<<"無效輸入，請輸入介於0至23之間的整數"<<endl; 

	}
	while(h<0 || h>=24);
	
	do
	{
		cout<<"請輸入分鐘"<<endl;
		cin>>m;
		
		if(m<0 || m>=60)
		cout<<"無效輸入，請輸入介於0至59之間的整數"<<endl;
	}
	while(m<0 || m>=60);
	
	do
	{
		cout<<"請輸入秒"<<endl;
		cin>>s;
		
		if(s<0 || s>=60)
		cout<<"無效輸入，請輸入介於0至59之間的整數"<<endl;

	}
	while(s<0 || s>=60);
	
	
	for(a==0;a==0;s++)
	{
		
		for(long long b=0;b<999999900;b++)
		{
			
		}
		
		
		cout<<h<<" 點 "<<m<<" 分 "<<s<<" 秒 "<<endl;
		if(s>=59)
		{
			m++;
			s=s-60;
		}
	
		if(m>=59)
		{
			h++;
			m=a;
		}
		
		if(h>=23)
		{
			h=a;
		}
		
		
		

	}
	


}

