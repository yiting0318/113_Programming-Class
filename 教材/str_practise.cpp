#include<iostream>
#include<string>

using namespace std;

int main(){
//練習 1 
//請嘗試比較s1和s2之間有多少字元相同(假設兩字串長度相同)
	string s1="asdgtqdz";
	string s2="astggfsz";
	
	int n = s1.length();
	int k=0;
	
	for(int i=0;i<n;i++){
		if(s1[i]==s2[i]){
			k++;
		}
	}
	cout<<"s1 和 s2 共有 "<<k<<" 各字元相同！"<<endl; 


//練習 2 
//找出s3第一個字元是否等於'I'
	string s3="hello";
	string s5="I";
	
	if(s3[0] == s5[0]) cout<<"s3[0] == I"<<endl;
	else cout<<"s3[0] != I"<<endl;

//練習 3
//輸出s4後h個字元
	string s4="abcdefgh";
	int m=s4.length(),h=5;
	
	cout<<s4.substr(m-h)<<endl;
} 
