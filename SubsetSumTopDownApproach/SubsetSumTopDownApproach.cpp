// SubsetSumTopDownApproach.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

void displayMatrix(const int setElements[], const int sumArray[], const int sum, const int numberOfSetElements, std::vector<int> &subset, int &sizeOfSubset)
{
	//int arr[5][8] = { 0 };
	int **arr = new int *[numberOfSetElements];
	
	for (int index = 0; index < numberOfSetElements; ++index)
		arr[index] = new int[sum + 1];

	for (int row = 0; row < numberOfSetElements; ++row)
		for (int col = 0; col < sum + 1; ++col)
			arr[row][col] = 0;

	for (int row = 0; row < numberOfSetElements; ++row)
		arr[row][0] = 1; //setting true.
	
	for (int row = 0; row < numberOfSetElements; ++row)
	{
		for (int col = 0; col < sum + 1; ++col)
		{
			if (row == 0)
			{
				arr[row][setElements[row]] = 1;
				break;
			}
			else
			{
				if (setElements[row] > sumArray[col])
				{
					arr[row][col] = arr[row - 1][col];
					continue;
				}
				if (col < (sum + 1))
				{
					if (arr[row - 1][col] == 1)
						arr[row][col] = arr[row - 1][col];
					else
						arr[row][col] = arr[row - 1][col - setElements[row]];
				}
			}
		}
	}
	for (int row = 0; row < numberOfSetElements; ++row)
	{
		for (int col = 0; col < sum + 1; ++col)
			std::cout << arr[row][col];
		std::cout << std::endl;
	}
	int col = sum, row = numberOfSetElements - 1;
	
	while (col != 0)
	{
		if (arr[row][col] != arr[row - 1][col])
		{
			subset.push_back(setElements[row]);
			col = col - setElements[row];
			row = row - 1;
			
			
		}
		else
			row = row - 1;
	}
	

	
	for (int index = 0; index < numberOfSetElements; ++index)
		delete[] arr[index];
	delete[] arr;

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
