#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Czesc.h"
#include <string>
#include "Sklep-z-zawieszeniem.h"
#include <fstream>
using namespace std;


int main()
{
cout << "Witaj w sklepie motoryzacyjnym MAMOTO!\n\nWyswietlam zawartosc magazynu \n------------------------------"<<endl;
Sklep amortyzatory(0);
amortyzatory.dodaj_amorek();
amortyzatory.podgladAM();
Sklep koszyk(0);
amortyzatory.koszyk(koszyk);
//cout<< "Zawartosc Twojego koszyka"<<endl;
//koszyk.podgladAM();

//Sklep sprezyny(0);
//sprezyny.dodaj_sprezyne();
//sprezyny.podgladSP();
//sprezyny.rozmiarSP();

}
