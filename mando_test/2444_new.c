#include <stdio.h>

void print_line(int spaces, int stars);
void draw_stars(int n, int current);

int main() {
    int num;
    scanf("%d", &num);
    draw_stars(num, 1);
    
    return 0;
}

void print_line(int spaces, int stars) {
    if (spaces > 0) {
        printf(" ");
        print_line(spaces - 1, stars);
    } else if (stars > 0) {
        printf("*");
        print_line(spaces, stars - 1);
    } else {
        printf("\n");
    }
}

void draw_stars(int num, int current) {
    if (current > num) return;

    print_line(num - current, 2 * current - 1);
    draw_stars(num, current + 1);

    if (current < num) {
        print_line(num - current, 2 * current - 1);
    }
}
