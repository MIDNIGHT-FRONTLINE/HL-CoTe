#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int alp[26];
    int *p_alp = alp;
    char *p_word;

    for (int i = 0; i < 26; i++) {
        *(p_alp + i) = -1;
    }

    scanf("%s", word);
    p_word = word;

    for (int i = 0; *(p_word + i) != '\0'; i++) {
        int n = *(p_word + i) - 'a';

        if (*(p_alp + n) == -1) {
            *(p_alp + n) = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", *(p_alp + i));
    }

    return 0;
}