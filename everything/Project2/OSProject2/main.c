//////////////////////////////////
//CS4328 OS Mina Guirguis
//Author: Cole Hurst
//Project 2: Dice-wars
//Simple game where there are 2 teams of 2 rolling 2 die until they get a matching pair
//Completed April 27, 2020
//////////////////////////////////

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

/* Global Variables*/
static FILE* fp;
static int seed = 12;
static int allplayers[8] = { 0,0,0,0,0,0,0,0 };

/* sync threads*/
static pthread_mutex_t lock;
static pthread_cond_t ok = PTHREAD_COND_INITIALIZER;


/* Throw dice function throws two dice and save their results in allplayer*/
void* diceaction(void* n)
{
    int roll1, roll2;

    char playerletter;

    pthread_mutex_lock(&lock);

    int player = (int)n;

    time_t t;
    if ( player == 0 )
    {
        playerletter = 'A';
    }
    else if ( player == 1 )
    {
        playerletter = 'B';
    }
    else if ( player == 2 )
    {
        playerletter = 'C';
    }
    else if ( player == 3 )
    {
        playerletter = 'D';
    }
    else
    {
        playerletter = 'K';
        roll1 = rand() % 6 + 1;
        roll2 = rand() % 6 + 1;
    }

    if (playerletter != 'K')
    {
        roll1 = rand() % 6 + 1;
        roll2 = rand() % 6 + 1;
        allplayers[(player * 2)] = roll1;
        allplayers[(player * 2) + 1] = roll2;
        printf("Player %c gets %d and %d with a sum %d \n", playerletter, roll1, roll2, roll1 + roll2);

        /* file stream*/
        fputs("Player ", fp);
        fputc(playerletter, fp);
        fputs(" gets ", fp);
        char str[50];
        sprintf(str, "%d", roll1);
        fputs(str, fp);
        fputs(" and ", fp);
        sprintf(str, "%d", roll2);
        fputs(str, fp);
        fputs(" with a sum ", fp);
        sprintf(str, "%d", roll1 + roll2);
        fputs(str, fp);
        fputs("\n", fp);
    }

    pthread_cond_signal(&ok);
    pthread_mutex_unlock(&lock);

}
/* Driver main */
int main(int argc, char* argv[])
{
    pthread_t callThd[5];

    pthread_mutex_init(&lock, NULL);

    time_t t;

    /*random number */
    srand((unsigned)time(&t));

    printf("Program: %s", argv[0]);
    if (argc == 1)
    {
        printf("\nNo Seed Paramter.\n");
        return 0;
    }
    else if (argc >= 2)
    {

        printf("\nSeed Value is: %s\n", argv[1]);
    }

    /* open or create the log*/
    fp = fopen("log.txt", "w");


    // Let us create four threads
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&callThd[i], NULL, diceaction, (void*)i);
    }

    for (int j = 0; j < 5; j++)
    {
        pthread_join(callThd[j], NULL);
    }

    char playerletter;

    int sum_a = allplayers[0] + allplayers[1];
    int sum_b = allplayers[2] + allplayers[3];
    int sum_c = allplayers[4] + allplayers[5];
    int sum_d = allplayers[6] + allplayers[7];

    for (int k = 0; k < 4; k++)
    {
        if (sum_a == sum_c && k == 3)
        {
            printf("DEALER: The winning team is A and C ");
        }
        else if (sum_b == sum_d && k == 3)
        {
            printf("DEALER: The winning team is B and D ");
        }
    }

    printf("\n***************************************\n");
    printf("****************************************\n");
    
    for (int k = 0; k < 4; k++)
    {
        if (k == 0)
        {
            playerletter = 'A';
        }
        else if (k == 1)
        {
            playerletter = 'B';
        }
        else if (k == 2)
        {
            playerletter = 'C';
        }
        else if (k == 3)
        {
            playerletter = 'D';
        }

        printf("Player %c: %d %d \n", playerletter, allplayers[(k * 2)], allplayers[(k * 2) + 1]);
    }
    /* close the file*/
    fclose(fp);
    /* Closing all the threads*/
    pthread_exit(NULL);

    return 0;
}