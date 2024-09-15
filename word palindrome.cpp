#include <iostream>
using namespace std;
bool ifpalindrome(string word)
{
	for(int i=0;i<word.length()/2;i++)
		while(word[i]!=word[word.length()-i-1])
			return false;
		
		return true;
}
int main()
{
	string word;
	cout<<"Enter a word:";
	cin>>word;
	if(ifpalindrome(word))
	{
		cout<<word<<" is a palindrome."<<endl;
	}
	else
	{
		cout<<word<<" is not a palindrome."<<endl;
	}
	
	return 0;
}