/**
 * @file review_grades.c
 * @brief Parses c.l.a for positive integers and produces statistics on them
 *
 * @author Logan Larocque <lml3687@rit.edu>
 * @course CSCI-243 Homework 2
 */

#include <stdio.h>
#include <ctype.h>
#include "stats.h"

/**
 * converts strings to integers if leading char is a digit
 * @param str   a character array (string)
 * @return -1  no leading digit  integer  converted integer from string 
 */
int str_to_int(const char *str){
    if(isdigit(str[0]) == 0){
        return(-1);
    }
    int value = 0;
 
    for(int i = 0; str[i] != '\0'; i++){
        char c = str[i];
        if(isdigit(c)){
            value = value * 10 + (c-'0');
        }else{
            break;
        }
    }
    return value;
}

/**
 * Handles input arguments and parses them for integers by calling
 * str_to_int, produces statistics on remaining numbers by calling functions
 * from stats.h
 * @param argc  # of input arguments
 * @param argv[]  array of input arguments
 * @return 0  successful execution  
 * @return 1  error
 */
int main(int argc, char *argv[]){
    
    if(argc == 1){
        fprintf(stderr, "usage: review_grades score1 [score2 ...]\n");
        fprintf(stderr, "note: ignores negative score values.\n");

        return(1);
    }

    int in_pop = argc - 1;

    //prints input population
    printf("input population: %d\n", in_pop);

    int adjusted_pop = 0;
    int pop[argc-1];

    //parse input arguments, add relevant ones to pop array
    for (int i = 0; i<argc; i++){
        int num = str_to_int(argv[i]);
        if(num >= 0){
            pop[adjusted_pop] = num;
            adjusted_pop++;
        }
    }
    
    //print new pop values
    for(int i = 0; i < adjusted_pop; i++){
        printf("%d ", pop[i]);
    }

    //print adjusted population
    printf("\nadjusted population: %d\n", adjusted_pop); 

    double avg = average(adjusted_pop, pop);
    //prints the mean
    printf("mean: %f\n", avg);

    //prints standard deviation
    printf("std deviation: %g\n", std_dev(adjusted_pop, pop, avg));

    //calls histogram which calculates and prints
    histogram(adjusted_pop, pop);

    return 0;
}





