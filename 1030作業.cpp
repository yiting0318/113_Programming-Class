#include <iostream>
using namespace std;
int main()
{
	long long i=1,s,n;
	cout<<"�п�Jn����"<<endl;
	cin>>n;
	for(i=1,s=1;i<n+1;i=i+1)
	{
		s=s*i;
	}
	
	cout<<n<<"!="<<s<<endl;
	
	
	return 0;
}
