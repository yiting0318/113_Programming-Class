#include<iostream>
using namespace std;

int main()
{ 
	int n;
	cout<< "�п�J�z�����������B" <<endl;
	cin >>n;
	int twothousand=n/2000;
    int onethousand=(n-((twothousand*2000)))/1000;
	int fivehundred=(n-((twothousand*2000)+(onethousand*1000)))/500;
	int onehundred=(n-((twothousand*2000)+(onethousand*1000)+(fivehundred*500)))/100;
	int fifty=(n-((twothousand*2000)+(onethousand*1000)+(fivehundred*500)+(onehundred*100)))/50;
	int twenty=(n-((twothousand*2000)+(onethousand*1000)+(fivehundred*500)+(onehundred*100)+(fifty*50)))/20;
	int ten=(n-((twothousand*2000)+(onethousand*1000)+(fivehundred*500)+(onehundred*100)+(fifty*50)+(twenty*20)))/10;
	int five=(n-((twothousand*2000)+(onethousand*1000)+(fivehundred*500)+(onehundred*100)+(fifty*50)+(twenty*20)+(ten*10)))/5;
	int one=(n-((twothousand*2000)+(onethousand*1000)+(fivehundred*500)+(onehundred*100)+(fifty*50)+(twenty*20)+(ten*10)+(five*5)))/1;
	
	
	cout<< "�i�H����:"<<endl;
	cout<<"��d�� "<<twothousand<<" �i"<<endl;
	cout<<"�@�d�� "<<onethousand<<" �i"<<endl;
	cout<<"���ʤ� "<<fivehundred<<" �i"<<endl;
	cout<<"�@�ʤ� "<<onehundred<<" �i"<<endl;
	cout<<"���Q�� "<<fifty<<" ��"<<endl;
	cout<<"�G�Q�� "<<twenty<<" ��"<<endl;
	cout<<"�Q  �� "<<ten<<" ��"<<endl;
	cout<<"��  �� "<<five<<" ��"<<endl;
	cout<<"�@  �� "<<one<<" ��"<<endl;
	return 0;
}
