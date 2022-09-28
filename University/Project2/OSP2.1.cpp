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

#define NUM_THREADS 4
#define NUM_ON_DIE 6
#define PTHREADM PTHREAD_MUTEX_INITIALIZER
#define PTHREADC PTHREAD_COND_INITIALIZER

// Pthread Set up
pthread_mutex_t mutext_dice_handler = PTHREADM;
pthread_cond_t exclusion_variable = PTHREADC;
pthread_mutex_t mutext_exit_cond = PTHREADM;
pthread_cond_t win_condition = PTHREADC;

// output file
FILE * output_file;

// Declaration of Global Variables
int round_counter = 1; //init to 1
int number_of_cases = 5;
int turn_val = 0;
int seed_value = 0;
bool win_flag = false;

// player and dealer init
pthread_t player_threads_handler[NUM_THREADS];
pthread_t dealer_threads_handler;

// Generating functions
void parseArgs(char *[]);
void generate_random_seed();
void generate_dice();
void print_output();

void parseArgs(char *argv[]){
   seed_value = atoi( argv[1] );
}

void generate_random_seed(){
   srand(seed_value);
}

// Dice Struct
struct Dice_struct{
   int die1, die2, sumdie;
};

//constructing each player
Dice_struct player_rollsA, player_rollsB, player_rollsC, player_rollsD;

int generateroll(){

    return(rand() % 6 + 1);
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
   // printing out the formatter
    round_header();


}


int main(int argc, char *argv[]){
   output_file = fopen("report.txt", "a");

   // Value intialization
   parseArgs(argv);
   generate_random_seed();

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
