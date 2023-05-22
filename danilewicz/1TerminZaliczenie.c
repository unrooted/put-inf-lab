#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    float num1 = *(float *)a;
    float num2 = *(float *)b;
    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("uzytkowanie: %s <imie>\n", argv[0]);
        return 1;
    }

    char *name = argv[1];
    const char* expected_name = "Konrad";
    if(strcmp(name, expected_name) != 0) {
        while(strcmp(name, expected_name) != 0) {
            printf("podaj moje poprawne imie\n");
            scanf("%s", name);
            printf("imie podane poprzez input prompt\n");
        }
    }
    else
        printf("imie podane poprzez cmdl arg\n");
    int x = strlen(name);
    printf("witaj, %s! dlugosc Twojego imienia wynosi: %d\n", name, x);
    float num, sum = 0, product = 1;
    int i, bigger_than_zero = 0, smaller_than_zero = 0, counter = 0, cubic_root_counter = 0, square_root_counter = 0;
    char input[20];
    float table[x+5];
    while(counter != x) {
        printf("podaj liczbe rzeczywista: ");
        scanf("%s", input);
        if(sscanf(input, "%f", &num) != 1) {
            printf("niepoprawny input, podaj poprawna liczbe rzeczywista\n");
            continue;
        }
        product *= num;
        if(num > 0) {
            if(square_root_counter == 0) {
                table[x] = sqrtf(num);
                square_root_counter++;
            }
            bigger_than_zero = 1;
        }
        if(num < 0) {
            if(cubic_root_counter == 0) {
                table[x+1] = cbrtf(num);
                cubic_root_counter++;
            }
            smaller_than_zero = 1;
        }
        table[counter] = num;
        sum += num;
        counter++;
    }
    table[x+2] = product;
    while (!(bigger_than_zero && smaller_than_zero)) {
        printf("powinienes podac co najmniej jedna liczbe wieksza od zera i jedna mniejsza od zera\n");
        bigger_than_zero = 0;
        smaller_than_zero = 0;
        counter = 0;
        while(counter != x) {
            printf("podaj liczbe rzeczywista: ");
            scanf("%s", input);
            if(sscanf(input, "%f", &num) != 1) {
		    printf("niepoprawny input podaj poprawna liczbe rzeczywista\n");
                continue;
            }
            product *= num;
            if(num > 0) {
                if(square_root_counter == 0) {
                    table[x] = sqrtf(num);
                    square_root_counter++;
                }
                bigger_than_zero = 1;
            }
            if(num < 0) {
                if(cubic_root_counter == 0) {
                    table[x+1] = cbrtf(num);
                    cubic_root_counter++;
                }
                smaller_than_zero = 1;
            }
            table[counter] = num;
            sum += num;
            counter++;
        }
        table[x+2] = product;
    }
    qsort(table, x+3, sizeof(float), compare);
    float average = sum / x;
    if(x % 2 == 0) {
        float median = (table[x/2] + table[(x/2)-1])/2;
        if(average > median) {
            printf("wartosci posortowane w kolejnosci od najmniejszej do najwiekszej (z ich danym numerem komórki w tabeli): \n");
            for(i = 0; i < x+3; i++) {
                printf("%d: %.3f\n", i, table[i]);
            }
        } else {
            printf("wartosci posortowane od najwiekszej do najmniejszej (z ich danym numerem komórki w tabeli): \n");
            for(i = x+2; i >= 0; i--) {
                printf("%d: %.3f\n", i, table[i]);
            }
        }
    }
    else {
        float median = table[x/2];
        if(average > median) {
            printf("wartosci posortowane w kolejnosci od najmniejszej do najwiekszej (z ich danym numerem komórki w tabeli): \n");
            for(i = 0; i < x+3; i++) {
                printf("%d: %.3f\n", i, table[i]);
            }
        } else {
            printf("wartosci posortowane w kolejnosci od najwiekszej do najmniejszej (z ich danym numerem komórki w tabeli): \n");
            for(i = x+2; i >= 0; i--) {
                printf("%d: %.3f\n", i, table[i]);
            }
        }
    }
    return 0;
}
