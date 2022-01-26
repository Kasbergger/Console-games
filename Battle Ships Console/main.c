#include <stdio.h>
#include <stdlib.h>

#define MAPSIZE 5

//Declarations of functions
void MapPrinter(int map[MAPSIZE][MAPSIZE]);
int HitDetecter(int battlePlan[MAPSIZE][MAPSIZE], int map[MAPSIZE][MAPSIZE], int row, int column);

//Global variables
int i, j;

int main()
{
    int rowAttack, columnAttack, hits, numOfShips = 7, hitCheck;
    int arena[MAPSIZE][MAPSIZE];
    int battlePlan[MAPSIZE][MAPSIZE] = {
    {0, 0, 0, 1, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0}};

    //Makes the arena
    for (i = 0; i < MAPSIZE; i++){
        for (j = 0; j < MAPSIZE; j++){
            arena[i][j] = 0;
        }
    }

    //Runs the game
    while(1==1){
        //Pints map
        MapPrinter(arena);

        redo:
        //Asks for where player wants to attack next
        printf("Attack row: ");
        scanf("%d", &rowAttack);
        printf("Attack column: ");
        scanf("%d", &columnAttack);

        //Checks if a ship has been hit
        hitCheck = HitDetecter(battlePlan, arena, rowAttack, columnAttack);
        if (hitCheck == 3) {
            printf("Attack a new place \n\n");
            goto redo;
        }
        arena[rowAttack - 1][columnAttack - 1] = hitCheck;
        if (hitCheck == 1) { hits++; }
        if (hits >= numOfShips) { break; }
    }
    printf("\nYou Win!\n");

    return 0;
}

/** Map Printer
 *
 * Prints the map from the an input arena array
 *
 */
void MapPrinter(int map[MAPSIZE][MAPSIZE])
{
    printf("MAP OF ARENA\n");
        for (i = 0; i < MAPSIZE; i++){
            for (j = 0; j < MAPSIZE; j++){
                //Prints one row of the map
                if (map[i][j]==0) { printf("0 "); }
                else if (map[i][j]==1) { printf("X "); }
                else { printf("M "); }

                //Changes line for the map
                if (j == 4) { printf("\n"); }
            }
        }
}

/** Hit detector
 *
 * Checks if a ship has been hit
 * Checks if the player shoots at the same spot twice
 *
 * Takes a battle plan, the map, and row, and column to be checked
 * Returns 1 if shot hit
 * Returns 2 if shot missed
 * Returns 3 if shot hits same spot agian
 *
 */
int HitDetecter(int battlePlan[MAPSIZE][MAPSIZE], int map[MAPSIZE][MAPSIZE], int row, int column)
{
    if (map[row - 1][column - 1] == 1 || map[row - 1][column - 1] == 2) {
        return 3;
    }

    if (battlePlan[row - 1][column - 1] == 1){
        return 1;
    }
    else {
        return 2;
    }
}
