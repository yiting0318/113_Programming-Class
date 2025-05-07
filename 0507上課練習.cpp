#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	
	//bool¶}Ãö 
	cout << true << endl;
	cout << boolalpha << false <<endl;
	cerr << "cerr:" << true <<endl;
	cout << true << endl;
	cout << noboolalpha << false << endl;
	
	cout<<setw(8)<<100<<endl;
	cout<<setw(8)<<1000<<endl;
	cout<<setw(8)<<left<<100<<endl;
}
