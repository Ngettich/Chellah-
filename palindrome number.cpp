#include <iostream>
using namespace std;
bool testingifpalindrome(int num)
{
	if (num<0)return false;
int original=num;
int reversed=0;
while(num !=0)
{
	int number=num%10;
	reversed= reversed*10+number;
	num/=10;
}
     return original==reversed;
}
int main()
{
	int num;
	cout<<"enter a number:";
	cin>>num;
	if(testingifpalindrome(num))
	{
		cout<<num<<" is a palindrome."<<endl;
	}
	else
	{
		cout<<num<<" is not a palindrome.";
	}
	return 0;
}