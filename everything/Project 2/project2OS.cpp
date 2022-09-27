/*
* Dice War: Simple Dice rolling game with 4 players in teams of 2, a dealer, and a die.
* CS4328 Operating Systems
* Date: April 26, 2020
* Creator: Cole Hurst
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#define NUM_THREADS 4 // Number of threads due to the 4 test cases.
#define NUM_ON_DIE 6 // Total numbers on a die
#define PTHREADM PTHREAD_MUTEX_INITIALIZER
#define PTHREADC PTHREAD_COND_INITIALIZER

// Dice Struct
struct Dice_struct{
   int die1, die2, sumdie;
};

// initializes each separate player
Dice_struct player_rollsA, player_rollsB, player_rollsC, player_rollsD;

// Pthread Set up
pthread_mutex_t mutext_dice_handler = PTHREADM;
pthread_cond_t exclusion_variable = PTHREADC;
pthread_mutex_t mutext_exit_cond = PTHREADM;
pthread_cond_t win_condition = PTHREADC;

// player and dealer initializer
pthread_t player_threads_handler[NUM_THREADS];
pthread_t dealer_threads_handler;

// output file
FILE * output_file;

// Declaration of Global Variables
int round_counter = 1; //init to 1
int number_of_cases = 5;
int turn_val = 0;

// Other
int dice[NUM_ON_DIE];
int *beginning_of_die;
int *end_of_die;
int seed_value = 0;
bool win_flag = false;

// Generating functions
void parseArgs(char *[]);
void generate_random_seed();
void generate_dice();
void print_output();

// Player thread functions
void *dealer_thread(void *arg);
void *player_threads(void *current_player_id);

// Deck Logic Handler
void dice_handler(long, Dice_struct);
void deal_handler();
void round_handler();

// Take in command Arguments
void parseArgs(char *argv[]){
   seed_value = atoi( argv[1] );
}

int generate_rolls(){
    int die1, die2, sumdie;
    die1 = (rand() % 6 + 1);
    die2 = (rand() % 6 + 1);
    sumdie = die1 + die2;

}

void round_header(){
   printf("---------------------------------------------------------------------------------------------------------------\n");
   printf("ROUND: %d\n", round_counter);
   printf("---------------------------------------------------------------------------------------------------------------\n");
   fprintf(output_file,"---------------------------------------------------------------------------------------------------------------\n");
   fprintf(output_file, "ROUND: %d\n", round_counter);
   fprintf(output_file,"---------------------------------------------------------------------------------------------------------------\n");
}

void round_handler(){
   // printing out the data
   round_header();

   int round_Dealer = pthread_create(&dealer_threads_handler, NULL, &dealer_thread, NULL);
   int round_Player;

   for( long a = 1; a <= NUM_THREADS; a++)
      round_Player = pthread_create(&player_threads_handler[a], NULL, &player_threads, (void *)a);

   // J\joinning threads
   pthread_join(dealer_threads_handler, NULL);

   for(int b = 0; b < 4; b++)
      pthread_join(player_threads_handler[b], NULL);
}

void *player_threads(void *current_player_id){
   long process_id = (long)current_player_id;

   Dice_struct player_rolls;

   // Based upon round counter conditions
   if( round_counter == 1 ){
      if( process_id == 1 ) player_rolls = player_rollsA;
      else if( process_id == 2 ) player_rolls = player_rollsB;
      else if( process_id == 3 ) player_rolls = player_rollsC;
      else player_rolls = player_rollsD;
   }
   if( round_counter == 2 ){
      if( process_id == 2 ) player_rolls = player_rollsA;
      else if( process_id == 1 ) player_rolls = player_rollsB;
      else if( process_id == 3 ) player_rolls = player_rollsC;
      else player_rolls = player_rollsD;
   }
   if( round_counter == 3 ){
      if( process_id == 3 ) player_rolls = player_rollsA;
      else if( process_id == 1 ) player_rolls = player_rollsB;
      else if( process_id == 2 ) player_rolls = player_rollsC;
      else player_rolls = player_rollsD;
   }
   if( round_counter == 4 ){
      if( process_id == 4 ) player_rolls = player_rollsA;
      else if( process_id == 2 ) player_rolls = player_rollsB;
      else if( process_id == 3 ) player_rolls = player_rollsC;
      else player_rolls = player_rollsD;
   }
   if( round_counter == 5 ){
      if( process_id == 2 ) player_rolls = player_rollsA;
      else if( process_id == 1 ) player_rolls = player_rollsB;
      else if( process_id == 4 ) player_rolls = player_rollsC;
      else player_rolls = player_rollsD;
   }

    //Win flag conditions
   while(win_flag == 0 ){
      pthread_mutex_lock(&mutext_dice_handler);
         while( process_id != turn_val && win_flag == 0 ){
            pthread_cond_wait(&exclusion_variable, &mutext_dice_handler);
         }
         if(win_flag == 0 ){
            deck_handler(process_id, player_rolls);
         }
      pthread_mutex_unlock(&mutext_dice_handler);
   }

   fprintf(output_file, "PLAYER %ld: round completed\n", process_id);
   pthread_exit(NULL); //pthread exit condition

}

int main(int argc, char *argv[]){
   output_file = fopen("report.txt", "a");

   // Value intialization
   parseArgs(argv);
   generate_random_seed();
   generate_rolls();

   // Round counters
   while(round_counter <= number_of_cases ){
      round_handler();
      round_counter++;
      win_flag = false;
   }

   // Exit conditions
   fclose(output_file);
   exit(EXIT_SUCCESS);
}
