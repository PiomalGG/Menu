#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int randint(int p, int k)
{
	return ((k - p) * (double)rand() / RAND_MAX) + p;
}

void kopiujtablice(int zTablicy[], int doTablicy[], int p, int k)
{
    for (int i = p; i <= k; i++)
    {
        doTablicy[i] = zTablicy[i];
    }
}

int main()
{
    srand(time(NULL));
    for (int i; i<20; i++)
    {
        rand();
    }

    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;
    system("cls");
    int *p = new int[n];

    for(int i = 0; i < n; i++)
    {
        p[i] = randint(0,99);
    }
    int opcja;

    bool active = true;
    while (active)
    {
        cout << "" << endl;
        cout << " Menu" << endl;
        cout << "----------------------------" << endl;
        cout << " [1] Dodaj element" << endl;
        cout << " [2] Wstaw element" << endl;
        cout << " [3] Usun element" << endl;
        cout << " [4] Wyswietl tablice" << endl;
        cout << " [5] Wyjdz z programu" << endl;
        cout << "----------------------------" << endl;
        cout << " Wybierz opcje: ";
        cin >> opcja;
        system("cls");

        switch(opcja)
        {
            case 1:
            {
                //n - rozmiar tablicy
                int NowEl;
                int *newp = new int[n];
                cout << "Podaj liczbe do dodania: ";
                cin >> NowEl;
                n++;
                kopiujtablice(p, newp, 0, n - 1);
                newp[n - 1] = NowEl;
                delete[] p;
                p = newp;
                system("cls");

            }
                break;
            case 2:
            {
                int MiejsceWTab;
                int NowWstawEl;
                int *newp = new int[n + 1];
                int counter = 0;
                cout << "Podaj miejsce w tabeli: ";
                cin >> MiejsceWTab;
                system("cls");
                cout << "Podaj liczbe do dodania: ";
                cin >> NowWstawEl;
                for (int i = 0; i <= n; i++)
                {
                    if (i != MiejsceWTab - 1)
                    {
                        newp[i] = p[counter];
                        counter++;
                    }
                    else
                    {
                        newp[i] = NowWstawEl;
                    }
                }
                n++;
                delete[] p;
                p = new int[n];
                for (int i = 0; i < n; i++)
                {
                    p[i] = newp[i];
                }
                delete[] newp;
                system("cls");
            }
                break;
            case 3:
            {
                int el;
                int *newp = new int[n - 1];
                int counter = 0;
                cout << "Podaj indeks (wiekszy od zera) elementu do usuniecia: ";
                cin >> el;
                for (int i = 0; i < n; i++)
                {
                    if (i != el - 1)
                    {
                        newp[counter] = p[i];
                        counter += 1;
                    }
                }
                system("cls");
                n--;
                for (int i = 0; i < n; i++)
                {
                    p[i] = newp[i];
                }
                delete[] newp;
            }
                break;
            case 4:
            {
                cout << "Tablica: ";
                for(int i = 0; i < n; i++)
                {
                    cout << p[i] << ", ";
                }
                cout << endl;
                cout << "Wpisz dowolny znak i zatwierdz aby kontynuowac: ";
                string skip;
                cin >> skip;
                system("cls");
            }
                break;
            case 5:
            {
                cout << "Do zobaczenia" << endl;
                active = false;
            }
                break;
            default:
            {
                cout << "Ta opcja jest niedostepna." << endl;
            }
                break;
        }
	}

}
