#include <stdio.h>
#include <string.h>

#define DICE_MAX 10
#define NUM_HORSES 4
#define MAX_POSITION 33

typedef struct {
    int position;
} HORSE;

typedef struct {
    int map[MAX_POSITION];
    int score[MAX_POSITION];
    int turn[MAX_POSITION];
    int dice[DICE_MAX];
    HORSE horses[NUM_HORSES];
    int check[MAX_POSITION];
    int result;
} GAME;

void init_game(GAME *game);
void dfs(GAME *game, int cnt, int sum);

int main() {
    GAME game;
    init_game(&game);
    dfs(&game, 0, 0);
    printf("%d\n", game.result);
    return 0;
}

void init_game(GAME *game) {
    for (int i = 0; i < DICE_MAX; i++) {
        scanf("%d", &((*game).dice[i]));
    }
    for (int i = 0; i < 21; i++) {
        (*game).map[i] = i + 1;
    }
    (*game).map[21] = 21;
    for (int i = 22; i < 27; i++) {
        (*game).map[i] = i + 1;
    }
    (*game).map[28] = 29;
    (*game).map[29] = 30;
    (*game).map[30] = 25;
    (*game).map[31] = 32;
    (*game).map[32] = 25;
    (*game).map[27] = 20;

    (*game).turn[5] = 22;
    (*game).turn[10] = 31;
    (*game).turn[15] = 28;
    (*game).turn[25] = 26;

    for (int i = 0; i < 21; i++) {
        (*game).score[i] = i * 2;
    }
    (*game).score[22] = 13;
    (*game).score[23] = 16;
    (*game).score[24] = 19;
    (*game).score[31] = 22;
    (*game).score[32] = 24;
    (*game).score[28] = 28;
    (*game).score[29] = 27;
    (*game).score[30] = 26;
    (*game).score[25] = 25;
    (*game).score[26] = 30;
    (*game).score[27] = 35;

    memset((*game).check, 0, sizeof((*game).check));
    for (int i = 0; i < NUM_HORSES; i++) {
        (*game).horses[i].position = 0;
    }
    (*game).result = 0;
}

void dfs(GAME *game, int cnt, int sum) {
    if (cnt == DICE_MAX) {
        if (sum > (*game).result) {
            (*game).result = sum;
        }
        return;
    }

    for (int i = 0; i < NUM_HORSES; i++) {
        int now = (*game).horses[i].position;
        int next = now;
        int move_count = (*game).dice[cnt];

        if ((*game).turn[now] != 0) {
            next = (*game).turn[now];
            move_count--;
        }

        while (move_count--) {
            next = (*game).map[next];
        }

        if (next != 21 && (*game).check[next]) {
            continue;
        }

        (*game).check[now] = 0;
        (*game).check[next] = 1;
        (*game).horses[i].position = next;

        dfs(game, cnt + 1, sum + (*game).score[next]);

        (*game).check[now] = 1;
        (*game).check[next] = 0;
        (*game).horses[i].position = now;
    }
}