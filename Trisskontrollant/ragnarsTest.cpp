#include "stdafx.h"
#include "triss.h"
#include "ragnarsTest.h"

using std::string;

int* shuffle(int arr[9]){

	for (int i=0;i<9;++i){
       int j = rand() %9;
       int tmp = arr[i];
       arr[i] = arr[j];
       arr[j] = tmp;
	}
    return arr;
}// shuffle

//***********************************************************************
// ANROP:   ragnarsTest( myIdentity );
// VERSION: 2010-01-15
// UPPFIFT: Testar en eller flera rutiner som studenten har skrivit.
//***********************************************************************
bool ragnarsTest(const string& myIdentity){

	if (myIdentity.find("Homer")!=string::npos){
		std::cerr << "Felaktig identitet : " << myIdentity << "\7\7\n";
		std::cerr << "Använd DITT förnamn och de sista 4 siffrorna i DITT personnunmmer!!\n";
        system("pause");
		exit( 0 );
	}

	int arr1[9] ={ 25,25, 50,100, 100,100, 250, 250,500};
	int arr2[9] ={ 25,25, 50,100, 100,     250, 250,500,100000000};

    bool ok = true;
	for (int i=0;i<1000 && ok;++i)
       ok = ok && checkTriss( shuffle(arr1) )==100 && checkTriss( shuffle(arr2) )==0;
       
	if (ok)
		std::cerr << "ragnarsTest lyckades\n";
	else std::cerr << "ragnarsTest MISSLYCKADES!!\7\n";
    return ok;
}// ragnarsTest