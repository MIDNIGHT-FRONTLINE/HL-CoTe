#include <stdio.h>

#define DICE_MAX 10
#define MAX_POSITION 33
#define NUM_HORSES 4

int dice[DICE_MAX];
int map[MAX_POSITION];
int turn[MAX_POSITION];
int score[MAX_POSITION];
int check[MAX_POSITION];
int horse[NUM_HORSES];

int maxScore = 0;

void initGame();
void playGame(int turnIndex, int currentScore);

int main() {
    initGame();
    playGame(0, 0);
    printf("%d\n", maxScore);
    return 0;
}

void initGame() {
    for (int i = 0; i < DICE_MAX; i++) {
        scanf("%d", &dice[i]);
    }

    for (int i = 0; i <= 20; i++) map[i] = i + 1;
    map[21] = 21;
    for (int i = 22; i <= 26; i++) map[i] = i + 1;
    map[27] = 20;
    map[28] = 29;
    map[29] = 30;
    map[30] = 25;
    map[31] = 32;
    map[32] = 25;

    turn[5] = 22;
    turn[10] = 31;
    turn[15] = 28;

    for (int i = 0; i <= 20; i++) score[i] = i * 2;
    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[31] = 22;
    score[32] = 24;
}

void playGame(int turnIndex, int currentScore) {
    if (turnIndex == DICE_MAX) {
        if (currentScore > maxScore) {
            maxScore = currentScore;
        }
        return;
    }

    for (int i = 0; i < NUM_HORSES; i++) {
        int currentPosition = horse[i];
        int nextPosition = currentPosition;
        int moves = dice[turnIndex];

        if (turn[currentPosition]) {
            nextPosition = turn[currentPosition];
            moves--;
        }

        while (moves-- > 0) {
            nextPosition = map[nextPosition];
        }

        if (nextPosition != 21 && check[nextPosition]) continue;

        check[currentPosition] = 0;
        check[nextPosition] = 1;
        horse[i] = nextPosition;

        playGame(turnIndex + 1, currentScore + score[nextPosition]);

        check[currentPosition] = 1;
        check[nextPosition] = 0;
        horse[i] = currentPosition;
    }
}