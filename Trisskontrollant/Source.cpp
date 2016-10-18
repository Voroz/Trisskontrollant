#include <iostream>
#include <vector>

using namespace std;


class NumAmount{
public:
	NumAmount() :
		number(0),
		amount(1){};
	NumAmount(int number, int amount) :
		number(number),
		amount(amount){};
	int number;
	int amount;
};

int searchVector(vector<int> vec, int number){
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] == number){
			return i;
		}
	}
	return -1;
}

template <size_t N>
int* sortArray(int(&arr)[N]){
	int sortedArr[N];
	for (auto sorted : sortedArr){
		int lowest = arr[0];
		int highest = arr[0];
		for (auto num : arr){

		}
	}
	return sortedArr;
}

template <size_t N>
vector<NumAmount> sortNumbers(int(&numbers)[N]){
	vector<NumAmount> sortedNumbers;
	vector<int> foundNumbers;
	for (int i = 0; i < N; i++){
		int searchResult = searchVector(foundNumbers, numbers[i]);
		if (searchResult == -1){
			foundNumbers.push_back(numbers[i]);
			NumAmount newNum(numbers[i], 1);
			sortedNumbers.push_back(newNum);
			continue;
		}
		sortedNumbers[searchResult].amount += 1;
	}
	return sortedNumbers;
}

template <size_t N>
int checkTriss(int (&trissArr)[N]){
	vector<NumAmount> sortedNumbers = sortNumbers(trissArr);
	for (auto sn : sortedNumbers){
		if (sn.amount >= 3){
			return sn.number;
		}
	}
	return 0;
}

int main(){
	int arr[9] = { 0, 7, 2, 3, 4, 1, 2, 2, 3 };
	int trissResult = checkTriss(arr);
	cout << trissResult << endl;
	while (1){

	}

	return 0;
}