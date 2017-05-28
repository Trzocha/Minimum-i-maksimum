#include <iostream>
#include "funkcje.h"
 
using namespace std;
 
int Krotnosc2(int liczba)
{
int pomoc=1;
        if(liczba==1) return pomoc;
        else
        {
                while(liczba > pomoc)
                        pomoc = pomoc *2;
        }
return pomoc*2-1;
}
void Wprowadz_Dane(Dane *tablica,int ilosc_el,int rozmiar)
{
int pomoc;
        pomoc = (rozmiar-1)/2;           //??
 
        for(int i=pomoc,j=0;i<pomoc+ilosc_el;i++,j++)
        {
                cin >> tablica[i].Min;
                tablica[i].Max = tablica[i].Min;
                tablica[i].kon_przedz = tablica[i].pocz_przedz = j;
        }
}
void Wypelnij_Drzewo(Dane *tablica,int rozmiar)
{
int pomoc=0;
int rodzic=0;
        pomoc = rozmiar-1;
 
        for(int i=pomoc;i>0;i-=2)
        {
                if(tablica[i-1].pocz_przedz != -1)
                {
                        rodzic = i/2-1;
                        if(tablica[i].Max > tablica[i-1].Max) tablica[rodzic].Max = tablica[i].Max;
                        else tablica[rodzic].Max = tablica[i-1].Max;
 
                        if(tablica[i].Min < tablica[i-1].Min) tablica[rodzic].Min = tablica[i].Min;
                        else tablica[rodzic].Min = tablica[i-1].Min;
 
                        if(tablica[i].pocz_przedz == -1)
                        {
                                tablica[rodzic].pocz_przedz = tablica[i-1].pocz_przedz;
                                tablica[rodzic].kon_przedz = tablica[i-1].kon_przedz;
                        }else{
                        tablica[rodzic].pocz_przedz = tablica[i-1].pocz_przedz;
                        tablica[rodzic].kon_przedz = tablica[i].kon_przedz;
                        }
                }
        }
}
void Wypisz_Drzewo(Dane *tablica,int rozmiar)
{
        cout<<"Max: \n";
        for(int i=0;i<rozmiar;i++)
                cout<<tablica[i].Max <<" ";
        cout<<"\nMIN: \n";
        for(int i=0;i<rozmiar;i++)
                        cout<<tablica[i].Min <<" ";
        cout<<"\nPP: \n";
        for(int i=0;i<rozmiar;i++)
                        cout<<tablica[i].pocz_przedz <<" ";
        cout<<"\nKP: \n";
        for(int i=0;i<rozmiar;i++)
                        cout<<tablica[i].kon_przedz <<" ";
}
void WprowadzZapytania(Dane *tablica)
{
int ilosc_zap=0;
        cin>>ilosc_zap;
 
        for(int i=0;i<ilosc_zap;i++)
                SzukajNaPrzedz(tablica);
}
void SzukajNaPrzedz(Dane *tablica)
{
int PP;
int KP;
Lista *min = NULL;
Lista *max = NULL;
 
                cin>> PP >> KP;
 
                PrzegladamDzieci(tablica,max,min,0,PP,KP);
                WypiszListeMin(min);
                WypiszListeMax(max);
                UsunListe(min);
                UsunListe(max);
}
 
void PrzegladamDzieci(Dane *tablica,Lista *&Lmax,Lista *&Lmin,int i,int PP,int KP)
{
 
        if(PP == tablica[i].pocz_przedz && KP == tablica[i].kon_przedz)          //warunek na rodzica glownego
                WrzucListe(tablica,Lmax,Lmin,i);
        else if (PP >= tablica[2*i+1].pocz_przedz && PP <= tablica[2*i+1].kon_przedz)
                                {
                                if(KP >= tablica[2*i+1].pocz_przedz && KP <= tablica[2*i+1].kon_przedz) {PrzegladamDzieci(tablica,Lmax,Lmin,2*i+1,PP,KP);}         //szukaj w prawym dziecku
                                else{PrzegladamDzieci(tablica,Lmax,Lmin,2*i+1,PP,tablica[2*i+1].kon_przedz); PrzegladamDzieci(tablica,Lmax,Lmin,2*i+2,tablica[2*i+2].pocz_przedz,KP);}
                                }
        else if (PP >= tablica[2*i+2].pocz_przedz && PP <= tablica[2*i+2].kon_przedz)
                                {
                                if(KP >= tablica[2*i+2].pocz_przedz && KP <= tablica[2*i+2].kon_przedz) {PrzegladamDzieci(tablica,Lmax,Lmin,2*i+2,PP,KP);}              //szukaj w lewym dziecku
                                }
 
}
void WrzucListe(Dane *tablica,Lista *&Lmax,Lista *&Lmin,int i)
{
        if(Lmax != NULL && Lmin != NULL)
        {
                if(tablica[i].Max > Lmax->wartosc )  //czy to co znalazlem jest wieksze od tego co jest w liscie i lista nie jest pusta
                {
                        Lista *nowy1 = new Lista;
                        Lista *pomoc1=NULL;
 
                        nowy1->wartosc = tablica[i].Max;
                        pomoc1 = Lmax;
                        Lmax = nowy1;
                        //nowy1->next = pomoc1;
                        delete pomoc1;
                }
                if(tablica[i].Min < Lmin->wartosc )  //czy to co znalazlem jest mniejsze od tego co jest w liscie i lista nie jest pusta
                {
                        Lista *nowy2 = new Lista;
                        Lista *pomoc2=NULL;
 
                        nowy2->wartosc = tablica[i].Min;
                        pomoc2 = Lmin;
                        Lmin = nowy2;
                        //nowy2->next = pomoc2;
                        delete pomoc2;
                }
        }else{                                                  //jezeli Listy sa puste wstaw bez patrzenia
                Lista *nowy1 = new Lista;
                Lista *pomoc1=NULL;
                Lista *nowy2 = new Lista;
                Lista *pomoc2=NULL;
 
                nowy1->wartosc = tablica[i].Max;
                nowy2->wartosc = tablica[i].Min;
                pomoc1 = Lmax;
                pomoc2 = Lmin;
                Lmax = nowy1;
                Lmin = nowy2;
                nowy1->next = pomoc1;
                nowy2->next = pomoc2;
        }
}
void WypiszListeMax(Lista *&korzen)
{
        cout<<korzen->wartosc<<" ";
}
void WypiszListeMin(Lista *&korzen)
{
        cout<<korzen->wartosc<<" ";
}
void UsunListe(Lista *&korzen)
{
Lista *pomoc=NULL;
                pomoc = korzen;
                delete pomoc;
