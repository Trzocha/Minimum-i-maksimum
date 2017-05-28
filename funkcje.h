struct Dane
{
int Max;
int Min;
int pocz_przedz;
int kon_przedz;
Dane(){ Max = -1; Min = 10001; kon_przedz = -1; pocz_przedz = -1;}
};
 
struct Lista
{
int wartosc;
Lista *next;
Lista(){wartosc = 0; next= NULL;}
};
 
void program();
int Krotnosc2(int liczba);
void Wprowadz_Dane(Dane *tablica,int ilosc_el,int rozmiar);
void Wypelnij_Drzewo(Dane *tablica,int rozmiar);
void Wypisz_Drzewo(Dane *tablica,int rozmiar);
void WprowadzZapytania(Dane *tablica);
void SzukajNaPrzedz(Dane *tablica);
void PrzegladamDzieci(Dane *tablica,Lista *&Lmax,Lista *&Lmin,int i,int PP,int KP);
void WrzucListe(Dane *tablica,Lista *&Lmax,Lista *&Lmin,int i);
void WypiszListeMax(Lista *&korzen);
void WypiszListeMin(Lista *&korzen);
void UsunListe(Lista *&korzen);
