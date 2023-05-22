/*
 * author: Konrad Klawikowski
 * date: 19-02-2023
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int isvalidf(const char* s) {
    float f;
    int n;
    int scanned = sscanf(s, "%f%n", &f, &n);
    return scanned == 1 && !s[n];
}

int dpoints(const char* s) {
    return s + strlen(s) - strrchr(s, '.') - 1;
}

int main(void) {
    char a1[32], a2[32];
    float f1, f2;
    float l;
    float lower, upper;

    fgets(a1, sizeof(a1), stdin);
    if (!*a1) {
        printf("-2\n");
        return -2;
    }

    *strchr(a1, '\n') = '\0';
    if (!isvalidf(a1)) {
        printf("-2\n");
        return -2;
    }
    if (dpoints(a1) != 2) {
        printf("-2\n");
        return -2;
    }
    f1 = atof(a1);
    if (f1 < 1) {
        printf("-1\n");
        return -1;
    }

    fgets(a2, sizeof(a2), stdin);
    if (!*a2) {
        printf("-2\n");
        return -2;
    }
    *strchr(a2, '\n') = '\0';
    if (!isvalidf(a2)) {
        printf("-2\n");
        return -2;
    }
    if (dpoints(a2) != 2) {
        printf("-2\n");
        return -2;
    }
    f2 = atof(a2);
    if (f2 <= 0) {
        printf("-1\n");
        return -1;
    }

    l = log(f2) / log(f1);
    if (fabs(round(l) - l) < 0.0001) {
        printf("%.2lf\n", l); 
    } else {
        lower = floorf(l);
        upper = ceilf(l);
        printf("%0.2f\t%0.2f\n", lower, upper);
    }

    return 0;
}
