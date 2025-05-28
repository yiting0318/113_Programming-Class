#include<iostream>
#include<string>

using namespace std;

int main(){
//各種string定義方式 
	string s1="123";
	string s2("456");
	string s3=s1+s2;
	
	cout<<"s1: "<<s1<<endl;
	cout<<"s2: "<<s2<<endl;
	cout<<"s3: "<<s3<<endl;
	cout<<endl;
	
//字串的大小比較
	string a=s1;
	string b=s2;
	
	if(a<b)cout<<a<<" < "<<b<<endl;
	else if(a==b) cout<<a<<" = "<<b<<endl;
	else cout<<a<<" > "<<b<<endl;
	cout<<endl;
	
//取得字串的長度 
	string s4="0123456";
	int n=s4.length();
	
	cout<<"The length of "<<s4<<" is "<<n<<endl;
	cout<<endl;
	
//根據字串的索引做修改
	string s5="abcdefg";
	int m=s5.length();
	
	for(int i=0;i<n;i++){
		s4[i]+=1;
	} 
	for(int i=0;i<m;i++){
		s5[i]+=3;
	}
	cout<<s4<<endl;
	cout<<s5<<endl;
	cout<<endl;
	
//取得部分字串
	string s6="0123456",s7,s8; 
	
	s7=s6.substr(3);
	s8=s6.substr(1,5);
	
	cout<<"s6: "<<s6<<endl;
	cout<<"s7: "<<s7<<endl;
	cout<<"s8: "<<s8<<endl;
	cout<<endl;
} 
