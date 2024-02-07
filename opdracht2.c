#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Functie om een willekeurig getal te genereren binnen een bereik
int genereerRandomGetal(int ondergrens, int bovengrens) {
    return rand() % (bovengrens - ondergrens + 1) + ondergrens;
}

int main() {
    int ondergrens, bovengrens, maxBeurten;
    int huidigGetal, volgendGetal, gok;
    int beurten = 0;
    char nogmaals;

    // Initialiseren van de random seed
    srand(time(NULL));

    do {
        printf("Ondergrens: ");
        scanf_s("%d", &ondergrens);
        printf("Bovengrens: ");
        scanf_s("%d", &bovengrens);
        printf("Hoeveel beurten? ");
        scanf_s("%d", &maxBeurten);

        huidigGetal = genereerRandomGetal(ondergrens, bovengrens);
        printf("Begin getal: %d\n", huidigGetal);

        while (beurten < maxBeurten) {
            printf("Is het volgende getal hoger(1) of lager(0)? ");
            scanf_s("%d", &gok);
            volgendGetal = genereerRandomGetal(ondergrens, bovengrens);
            printf("Het volgende getal is: %d\n", volgendGetal);

            if ((gok == 1 && volgendGetal > huidigGetal) || (gok == 0 && volgendGetal < huidigGetal)) {
                printf("Goed!\n");
            }
            else {
                printf("Fout!\n");
            }

            huidigGetal = volgendGetal;
            beurten++;
        }

        printf("Je hebt alle %d beurten gespeeld.\n", maxBeurten);
        printf("Nog een keer spelen?: ");
        scanf_s(" %c", &nogmaals, 1); // Let op: bij het lezen van een enkel karakter met scanf_s, is het niet nodig om de grootte op te geven in dit geval

        // Reset de beurten voor een eventueel nieuw spel
        beurten = 0;
    } while (nogmaals == 'y' || nogmaals == 'Y');

    return 0;
}