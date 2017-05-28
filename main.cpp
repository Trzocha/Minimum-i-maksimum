#include <iostream>
#include "funkcje.h"
 
using namespace std;
 
int main()
{
        program();
return 0;
}
 
void program()
{
 
int ilosc_el=0;
int rozmiar = 0;
 
        cin >>ilosc_el;
 
        rozmiar = Krotnosc2(ilosc_el);
 
Dane *tablica = new Dane[rozmiar];
 
        Wprowadz_Dane(tablica,ilosc_el,rozmiar);
        Wypelnij_Drzewo(tablica,rozmiar);
        //Wypisz_Drzewo(tablica,rozmiar);
 
        WprowadzZapytania(tablica);
 
}
