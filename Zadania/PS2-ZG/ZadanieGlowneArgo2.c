#include <stdio.h>
int main() {
    int npozycja = 0; //na ktora pozyje wpisujemy numer
    int l[8] = {0}; //list pomiarow
    while (1) { // loguj az 3 razy popelni blad
        int i = 0;
        int ppin = 0; //podany pin
        int pin = 1234;
        for (i = 0; i < 3; i++) {
            printf("Podaj pin dostepu: \n");
            if (scanf("%d", &ppin) != 1) {
                int c;
                while ((c=getchar())!='\n' && c != EOF) {}
            }
            if (ppin == pin) {
                printf("Pomyslnie zalogowano\n\n");
                break;
            }
            printf("Podano bledny kod\n");
        }
        if (i == 3) { //3x bledny kod konczy program
            printf("Podano bledny kod 3 razy, nastapi zamkniecie systemu");
            return 0;
        }
        
        int opcja = -1;

        do {
            //Wybierz opcje menu
            printf("\n ---Menu opcji--- \n[1] Dodanie nowego odczytu\n[2] Zmiana wybranego odczytu\n[3] Wyswietlenie zapisanych odczytow\n[4] Wyswietlenie podstawowych statystyk\n[5] Wyswietlenie odczytow przekraczajacych ustalony poziom alarmowy\n[6] Wyczyszczenie zapisanych danych\n[7] Wylogowanie\nPodaj opcje z menu: ");
            while (scanf("%d", &opcja) != 1 || opcja<1 || opcja>7) {
                    printf("Niepoprawny wybor\nPodaj poprawna opcje menu: \n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }
            }
            printf("\n");
            int odczyt = 0;
            int zpozycja = 0;
            switch (opcja)
            {
            case 1: //wpisz nowy odczyt, nadpisz jezeli > 8
                printf("Wybrano opcje 1\nPodaj nowy odczyt\n");
                npozycja++;
                while (scanf("%d", &odczyt) != 1 || odczyt < -50 || odczyt > 50){
                    printf("Nie poprawny odczyt, odczyt powinien byc liczba calkowita z przedzialu [-50,50]\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }
                }
                // Przesuniecie elementow do lewej, i zrobienie miejsce na nowa na npozycja=8 (-1)
                if (npozycja > 8) {
                    for(int k = 0;k<7;k++) {
                        l[k] = l[k+1];
                    }
                    npozycja = 8;
                }
                l[npozycja-1] = odczyt;
                break;
                
            case 2: //zamien wybrany odczyt
                if (npozycja == 0) {
                    printf("Lista jest pusta\n\n");
                    break;
                }
                // Wybor pozycji do edytowania
                printf("Wybrano opcje 2\nPodaj pozycje do edytowania (od 1 do %d)\n",npozycja);
                while (scanf("%d", &zpozycja) !=1 || zpozycja > 8 || zpozycja < 1 || zpozycja > npozycja) {
                    printf("Niepoprawna pozycja, podaj ponownie\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }
                }
                // Wybor wartosci na jaka zmieniamy
                printf("Podaj nowy odczyt:\n");
                while (scanf("%d", &odczyt) != 1 || odczyt < -50 || odczyt > 50){
                    printf("Nie poprawny odczyt, odczyt powinien byc liczba calkowita z przedzialu [-50,50]\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }
                }
                l[zpozycja-1] = odczyt;
                break;
            case 3: //Wyswietl liste
                if (npozycja == 0) {
                    printf("Lista jest pusta\n\n");
                    break;
                }
                printf("Wybrano opcje 3\n\n");
                printf("Aktualna lista odczytow \n[");
                for(int k = 0; k<npozycja-1; k++) 
                {
                    printf("%d, ", l[k]);    
                }
                printf("%d", l[npozycja-1]);
                printf("]\n\n");
                break;
            case 4: //wyswietl statystyki
                if (npozycja == 0) {
                    printf("Lista jest pusta\n\n");
                    break;
                }
                // Obliczenie Sredniej
                printf("Wybrano opcje 4\n\n");
                float suma = 0;
                for(int k =0; k<npozycja;k++){
                    suma = suma + l[k];
                }
                float srednia = suma/npozycja;
                // Ilosc liczb wiekszych od Sredniej
                int wieksze = 0;
                for(int k =0; k<npozycja;k++){
                    if (l[k]> srednia) {
                        wieksze++;
                    }
                }
                
                printf("Srednia podanych liczb: %f \n", srednia);
                printf("Ilosc liczb wiekszych od sredniej: %d \n", wieksze);
                //najwiekszy spadek i wzrost
                int maxup = 0; int maxdown = 0;
                for (int k = 0; k<npozycja-1; k++) {
                    
                    if (l[k] < l[k+1]) { //Wzrost
                        int wzrost = l[k+1] - l[k];
                        if (wzrost > maxup) {
                            maxup = wzrost;
                        }

                    }
                    else { //Spadek
                        int spadek = l[k] - l[k+1];
                        if (spadek > maxdown) {
                            maxdown = spadek;
                        }

                    }
                    
                }
                if (npozycja >= 2) {
                    //wypisanie wzrostow i spadkow o ile istnieja
                    if (maxup != 0) {
                    printf("Najwiekszy wzrost: %d\n", maxup);
                    } else {printf("Brak wzrostow pomiedzy kolejnymi wartosciami\n"); }

                    if (maxdown != 0) {
                    printf("Nawjiekszy spadek: %d\n\n", maxdown);
                    } else {printf("Brak spadkow pomiedzy kolejnymi wartosciami\n\n"); }

                } else {
                    printf("Brak wystarczajacej ilosci pomiarow aby wyznaczyc wzrosty i spadki\n\n");
                }
                break;
            case 5: //Wyswietl odczyty alarmowe
                printf("Wybrano opcje 5\n");
                if (npozycja == 0) {
                    printf("Lista jest pusta\n\n");
                    break;
                }
                int ile = 0;
                for (int k = 0; k < npozycja; k++) {
                    if (l[k] > 40 || l[k]<-40) {
                        int a = l[k];
                        printf("Odczyt przekracajacy poziom alarmowy: %d\n", a);
                        ile++;
                    }
                }
                if (ile ==0) {
                    printf("Brak odczytow przekraczajacych poziom alarmowy!\n\n");
                }

                break;
            case 6: // wyczysc liste
                if (npozycja == 0) {
                    printf("Lista jest pusta\n\n");
                    break;
                }
                printf("Wybrano opcje 6\nCzysczenie Listy...\n");
                npozycja = 0;
                for (int k = 0; k < 8; k++) {
                    l[k] = 0;
                }
                break;
            case 7: // Wyloguj z systemu
                printf("-------------------------\n| Wylogowano z systemu! |\n-------------------------\n\n");
            }
        } while (opcja != 7); // pytaj o menu az nie wyloguje
    }
        return 0;
}