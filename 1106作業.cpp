#include <iostream>
using namespace std;
int main()
{
	int h,m,s,a;
	a==0;
	do
	{
		cout<<"�п�J�p��"<<endl;
		cin>>h;
		
		if(h<0 || h>=24)
		cout<<"�L�Ŀ�J�A�п�J����0��23���������"<<endl; 

	}
	while(h<0 || h>=24);
	
	do
	{
		cout<<"�п�J����"<<endl;
		cin>>m;
		
		if(m<0 || m>=60)
		cout<<"�L�Ŀ�J�A�п�J����0��59���������"<<endl;
	}
	while(m<0 || m>=60);
	
	do
	{
		cout<<"�п�J��"<<endl;
		cin>>s;
		
		if(s<0 || s>=60)
		cout<<"�L�Ŀ�J�A�п�J����0��59���������"<<endl;

	}
	while(s<0 || s>=60);
	
	
	for(a==0;a==0;s++)
	{
		
		for(long long b=0;b<999999900;b++)
		{
			
		}
		
		
		cout<<h<<" �I "<<m<<" �� "<<s<<" �� "<<endl;
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

