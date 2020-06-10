#include <iostream>
#include "Sklep-z-zawieszeniem.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

Sklep::Sklep(){
    iloscCzesci= 0;
}
Sklep::Sklep(int ile)
{
    iloscCzesci=ile;
    zestawCzesci.resize(ile);
}
Sklep::~Sklep()
{
	zestawCzesci.clear();
}
void Sklep::dodaj_do_sklepu(Czesc element)
{
    zestawCzesci.push_back(element);
}
void Sklep::dodaj_do_sklepuAM(Amortyzator& damper)
{
    zestawAmorkow.push_back(damper);
}
void Sklep::dodaj_do_sklepuSP(Sprezyna& spring)
{
    zestawSprezyn.push_back(spring);
}
void Sklep::podglad()
{
    cout << "\nWyswietlam wszystkie elementy listy:"<<endl;
    for(auto& gaz : zestawCzesci)
	{
		gaz.wypisz();
	}

}
void Sklep::podgladAM()
{
    cout << "\nWyswietlam wszystkie amortyzatory: "<<endl;
    for(auto& gaz : zestawAmorkow)
	{
		gaz.wypiszAM();
	}

}
void Sklep::podgladSP()
{
    cout << "\nWyswietlam wszystkie sprezyny:"<<endl;
    for(auto& gaz : zestawSprezyn)
	{
		gaz.wypiszSP();
	}

}
void Sklep::wczytaj()
{

    fstream plik;
    plik.open("magazyn.txt", ios::in);
    if(plik.good()==false)
    {
        cout<<"Nie mozna otworzyc pliku!";
        exit(0);
    }

    Sklep magazyn;
    string tekst;
    string ma,mo,pr;
    int lp,ce;
    while(getline(plik,tekst)){
    stringstream tekstStream(tekst);
    tekstStream>>lp;
    tekstStream>>ma;
    tekstStream>>mo;
    tekstStream>>pr;
    tekstStream>>ce;
    Czesc element(lp,ma,mo,pr,ce);
    magazyn.dodaj_do_sklepu(element);
    }
    plik.close();
     magazyn.podglad();
}
void Sklep::dodaj_amorek()
{

    fstream plik;
    plik.open("amortyzatory.txt", ios::in);
    if(plik.good()==false)
    {
        cout<<"Nie mozna otworzyc pliku!";
        exit(0);
    }

    //Sklep amortyzatory;
    string tekst;
    string ma,mo,pr,ro,ty;
    int lp,ce;
while(getline(plik,tekst)){
    stringstream tekstStream(tekst);
    tekstStream>>lp;
    tekstStream>>ma;
    tekstStream>>mo;
    tekstStream>>pr;
    tekstStream>>ce;
    tekstStream>>ro;
    tekstStream>>ty;

  Amortyzator damper(lp,ma,mo,pr,ce,ro,ty);
   // amortyzatory.dodaj_do_sklepuAM(damper);
   zestawAmorkow.push_back(damper);
    }
    plik.close();
     //amortyzatory.podgladAM();
}

void Sklep::dodaj_sprezyne()
{

    fstream plik;
    plik.open("sprezyny.txt", ios::in);
    if(plik.good()==false)
    {
        cout<<"Nie mozna otworzyc pliku!";
        exit(0);
    }

    //Sklep sprezyny;
    string tekst;
    string ma,mo,pr;
    float tw;
    int lp,ce,ile;
while(getline(plik,tekst)){
    stringstream tekstStream(tekst);
    tekstStream>>lp;
    tekstStream>>ma;
    tekstStream>>mo;
    tekstStream>>pr;
    tekstStream>>ce;
    tekstStream>>tw;
    tekstStream>>ile;

    Sprezyna spring(lp,ma,mo,pr,ce,tw,ile);
    //sprezyny.dodaj_do_sklepuSP(spring);
    zestawSprezyn.push_back(spring);
    }
    plik.close();

}

void Sklep::wskazAM(int a)
{
    auto iter=zestawAmorkow.at(a-1);
    iter.wypiszAM();

}
void Sklep::wskazSP(int b)
{
    auto iter=zestawSprezyn.at(b-1);
    iter.wypiszSP();

}
void Sklep::rozmiarAM()
{
    int ile=zestawAmorkow.size();
    cout<<"W sklepie znaduja sie amortyzatory do "<< ile <<" aut"<<endl;
}
void Sklep::rozmiarSP()
{
    int ile=zestawSprezyn.size();
    cout<< "W sklepie znaduja sie sprezyny do "<< ile <<" aut"<<endl;
}
void Sklep::koszyk(Sklep koszyk)
{
    int ile=zestawAmorkow.size();
    int wybor;
    cout << "Czy chcesz kupic amortyzator? \n1.Tak  2.Nie"<<endl;
    cin >> wybor;
    if (wybor==1)
    {
        int wybor2;
        cout << "Ktory?"<<endl;
        cin>> wybor2;
        if (wybor2<=ile)
        {
            auto iter=zestawAmorkow.at(wybor2-1);
            iter.wypiszAM();
            koszyk.dodaj_do_sklepuAM(iter);
            koszyk.podgladAM();
        }
        else
        {
            cout<<"Nie ma takiego na liscie"<<endl;
        }
    }
    else
    {
        cout<<"nara"<<endl;
    }



}
