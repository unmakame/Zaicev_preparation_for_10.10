#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPS(char* p, int m, int* lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
}

void KMP(char* t, char* p) {
    int n = strlen(t), m = strlen(p);
    int* lps = (int*)malloc(m * sizeof(int));
    computeLPS(p, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("Match at %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && t[i] != p[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    free(lps);
}

int main() {
    char text[] = "ABCACBACABCBACABCABCBABCACAAABC";
    char pattern[] = "AAABC";
    KMP(text, pattern);
    return 0;
}