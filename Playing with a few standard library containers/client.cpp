//Elizabeth Fanton 9/30/26 COSC -III
//Playing with a few standard library containers (data structures) 
#include<iostream>
#include<list>
#include<vector>
#include<array>

using namespace std;

int main()
{
	//Create variables using each of these three container types.
	//list
	list<int> numList{ 1,2,3,4,5 };
	cout << "Original list: ";
	for(int printNum : numList)
		cout << printNum << " ";
	
	//doing addition on first and last elements of the list
	numList.front() = 1;
	numList.back() = 5;
	int listSum = numList.front() + numList.back();
	cout << endl  << "Sum of first and last element in list: " << listSum << endl;

	//adding sum to end of the list
	numList.push_back(move(listSum));
	
	//outputting the new list
	cout << endl << "New number list: ";
	for (int printNum : numList)
		cout << printNum << " ";

	//vector
	vector<int> vecNum{ 1,2,3,4,5 };
	
	//output original vec
	cout << endl << "Orignal vector: ";
	for (int printNum : vecNum)
		cout << printNum << " ";

	vector<int> vecSumVec;
	for (int i = 0; i < vecNum.size() / 2; i++)
	{
		for (int j = vecNum.size() - 1; j > vecNum.size() / 2; j--)
		{
			int vecSum = vecNum.at(i) - vecNum.at(j);
			vecSumVec.push_back(vecSum);
		}
	}
	vecNum.clear();
	vecNum = vecSumVec;
	cout << endl << "vecNum sum : ";
	for(int printNum : vecNum)
		cout << printNum << " ";


	//array
	const int arraySize = 11;
	
	array<int, arraySize> myArray;
	myArray.fill(0);
	int i = 0;
	//putting list into array
	list <int> dummyNumList = numList;

	for (int k = 0; k < numList.size(); k++)
	{
		myArray.at(i++) = dummyNumList.front();
		dummyNumList.pop_front();
	}
	//putting vector into array
	for (int k = 0; k < vecNum.size(); k++)
	{
		myArray.at(i++) = vecNum.at(k);
	}

	//outputting array size
	cout << endl << endl << "Array size: " << myArray.size() << endl;

	//checking if array is empty before outputting results
	if (myArray.empty())
		cout << "The array is empty." << endl;
	else
		cout << endl << "My first array: " << endl;
		for (int printNum : myArray)
			cout << printNum << " ";

		//filling new array
		const int secondArraySize = 11;
		array<int, secondArraySize> secondArray;
		for (int l = 0; l < secondArraySize; l++)
			secondArray[l] = rand() % 11;
				
		//outputting second array
		cout << endl << "My second array: " << endl;
		for (int printNum : secondArray)
			cout << printNum << " ";

		cout << endl;
		//swap
		//swapping myArray with secondArray
		myArray.swap(secondArray);

		//outputting swapped arrays
		//first array output
		cout << endl << "Swapped first array: ";
		for (int printNum : myArray)
			cout << printNum << " ";
		
		//second array output
		cout << endl << "Swapped second array: ";
		for (int printNum : secondArray)
			cout << printNum << " ";

		
		
	return 0;
}