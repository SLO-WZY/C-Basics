#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    char rematch;
    char *tryby[] = {"Plasma", "Cryo Shield", "EMP"};
    do {
        printf("1 - Plasma\n"); // nozyce
        printf("2 - Cryo Shield\n"); // papier
        printf("3 - EMP\n"); // kamien

        printf("Wybierz tryb: ");
        int mode;
        while (scanf("%d", &mode) != 1 || mode < 1 || mode > 3) {
            printf("Niepoprawny wybor podaj liczbe od 1 do 3: \n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
        }
        int ranmode =(rand()%3)+1;

        printf("Twoj wybor: %s\n", tryby[mode-1]);
        printf("Wybor komputera: %s\n", tryby[ranmode-1]);

        int wynik = ((mode-ranmode)+3)%3;
        if (wynik == 0) {
            printf("Remis \n");
        } else if (wynik==1) {
            printf("Wygral komputer \n");
        } else {
            printf("Wygral uzytkownik \n");
        }

        printf("Czy chcesz zagrac jescze raz? (t/n): \n");
        scanf(" %c", &rematch);

        while (rematch != 't' && rematch != 'n') {
            printf("Niepoprawny wybor. Podaj t lub n: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            scanf(" %c", &rematch);
        }
    } while (rematch == 't');

    return 0;
}