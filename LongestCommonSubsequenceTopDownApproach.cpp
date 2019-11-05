// LongestCommonSubsequenceTopDownApproach.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "LongestCommonSubsequence.h"
#include <algorithm>
#include<iostream>

void FindLongestCommonSubsequence(const std::string &string1, const std::string &string2, std::string &longestCommonSubsequence)
{
	int M = string1.length();
	int N = string2.length();

	int **arr = new int* [N + 1];
	for (int index = 0; index < N + 1; ++index)
		arr[index] = new int[M + 1];
	
	for (int row = 0; row <N + 1; ++row)
		for (int col = 0; col < M + 1; ++col)
			arr[row][col] = 0;

	for (int row = 1; row < N + 1; ++row)
	{
		for (int col = 1; col < M + 1; ++col)
		{
			if ((string1.at(col - 1))==(string2.at(row - 1)))
				arr[row][col] = 1 + arr[row - 1][col - 1];
			else
				arr[row][col] = std::max(arr[row - 1][col], arr[row][col - 1]);
		}
	}
	for (int row = 0; row < N + 1; ++row)
	{
		for (int col = 0; col < M + 1; ++col)
			std::cout << arr[row][col];
		std::cout << std::endl;
	}
	int row = N , col = M ;
	while (row != 0)
	{
		if ((arr[row][col] != std::max(arr[row - 1][col], arr[row][col - 1])))
		{
			longestCommonSubsequence += string1.at(col - 1);
			col = col - 1;
			row = row - 1;
		}
		else if (std::max(arr[row - 1][col], arr[row][col - 1]) == arr[row - 1][col])
			row = row - 1;
		else
			col = col - 1;
	}
	longestCommonSubsequence = std::string(longestCommonSubsequence.rbegin(), longestCommonSubsequence.rend());
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
