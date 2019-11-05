#include "pch.h"
#include "LongestCommonSubsequence.h"
#include <iostream>
using namespace std;

int main()
{
	string str1; 
	string str2;
	string ans;

	cin >> str1;
	cin >> str2;

	FindLongestCommonSubsequence(str1, str2, ans);
	cout << "Longest Common Subsequence is : "<<ans<< endl;
	system("pause");
	return 0;
}