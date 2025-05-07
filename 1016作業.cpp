#include<iostream>
using namespace std;

int main()
{ 
	int n;
	cout<< "請輸入您欲換錢的金額" <<endl;
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
	
	
	cout<< "可以換取:"<<endl;
	cout<<"兩千元 "<<twothousand<<" 張"<<endl;
	cout<<"一千元 "<<onethousand<<" 張"<<endl;
	cout<<"五百元 "<<fivehundred<<" 張"<<endl;
	cout<<"一百元 "<<onehundred<<" 張"<<endl;
	cout<<"五十元 "<<fifty<<" 個"<<endl;
	cout<<"二十元 "<<twenty<<" 個"<<endl;
	cout<<"十  元 "<<ten<<" 個"<<endl;
	cout<<"五  元 "<<five<<" 個"<<endl;
	cout<<"一  元 "<<one<<" 個"<<endl;
	return 0;
}
