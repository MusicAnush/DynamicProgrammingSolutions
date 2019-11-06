#include "pch.h"
#include "SubsetSumTopDownApproach.h"
#include <iostream>

using namespace std;

int main()
{
	//int setElements[] = { 1, 2, 5, 9, 14 };
	//int sumArray[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int sum, numberOfSetElements, *setElements, *sumArray, sizeOfSubset=0;
	vector<int> subset;

	cout << "enter the number of elements in the set" << endl;
	cin >> numberOfSetElements;
	
	setElements = new int[numberOfSetElements];
	cout << "enter the elements in the ascending order..." << endl;
	
	for (int index = 0; index < numberOfSetElements; ++index)
		cin >> setElements[index];

	cout << "enter the sum for which you are wanting to find the subset from the given set" << endl;
	cin >> sum;
	sumArray = new int[sum];

	for(int index = 0; index < sum + 1; ++index)
		sumArray[index] = index;
	displayMatrix(setElements, sumArray, sum, numberOfSetElements, subset, sizeOfSubset);
	
	cout << "subset is :" << endl;
	for (int index = 0; index < subset.size(); ++index)
		cout << subset[index]<<endl;

	system("pause");
	return 0;

}