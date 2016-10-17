#include <iostream>
#include <vector>

using namespace std;

class Vector2{
public:
	Vector2() :
		x(0),
		y(0){};
	Vector2(int x, int y) :
		x(x),
		y(y){};
	int x;
	int y;
};

int searchVector(vector<int> vec, int number){
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] == number){
			return i;
		}
	}
	return -1;
}

Vector2 search2dVector(vector<vector<int>> vec, int number){
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < vec[i].size(); j++){
			if (vec[i][j] == number){
				return Vector2(i, j);
			}
		}
	}
	return Vector2(-1, -1);
}

template <size_t N>
vector<vector<int>> sortNumbers(int(&numbers)[N]){
	vector<vector<int>> sortedNumbers;
	vector<int> foundNumbers;
	for (int i = 0; i < N; i++){
		int searchResult = searchVector(foundNumbers, numbers[i]);
		if (searchResult == -1){
			foundNumbers.push_back(numbers[i]);
			vector<int> newVec = { numbers[i] };
			sortedNumbers.push_back(newVec);
			continue;
		}
		sortedNumbers[searchResult].push_back(numbers[i]);
	}
	return sortedNumbers;
}

template <size_t N>
int checkTriss(int (&trissArr)[N]){
	vector<vector<int>> sortedNumbers = sortNumbers(trissArr);
	for (auto sn : sortedNumbers){
		if (sn.size() >= 3){
			return sn[0];
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