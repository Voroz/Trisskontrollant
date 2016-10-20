// Triss.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ragnarsTest.h"
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

vector<NumAmount> sortNumbers(const int numbers[9]){
	vector<NumAmount> sortedNumbers;
	vector<int> foundNumbers;
	for (int i = 0; i < 9; i++){
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

int checkTriss(const int trissArr[9]){
	vector<NumAmount> sortedNumbers = sortNumbers(trissArr);
	for (auto sn : sortedNumbers){
		if (sn.amount >= 3){
			return sn.number;
		}
	}
	return 0;
}


/****************************************************
ANROP:   bool ok = get9Numbers( (trissArr) );
UPPGIFT: Låter användaren fylla in 9 stycken belopp (krontal)
         separerade med mellanslag. 
*****************************************************/
bool get9Numbers(int trissArr[9]){
    cout << "VG knappa in 9 belopp:";
    for (int i = 0; i < 9; ++i){
        string str;
        cin >> str;
        trissArr[i] = atoi(str.c_str());
        if (trissArr[i] <= 0)
            return false;
    }
    return true;
}



void main()
{
    setlocale(LC_ALL, "swedish");
    ragnarsTest("Jonny 2472");

	int trissArr[9] = { 0 };
	get9Numbers(trissArr);
	cout << "Resultat: " << checkTriss(trissArr) << endl;

  // TODO din egen kod här
  // Den skall läsa in 9 heltal och anropa checkTiss

  // Om du vill kan du anropa get9Numbers
    //  ok att ta kod från föreläsning

  

    system("pause");
}

