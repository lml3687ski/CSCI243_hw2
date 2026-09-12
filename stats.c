/**
 * @file stats.c
 * @brief Computes statistics on set of grades input by the user from the main file
 *
 * @author Logan Larocque <lml3687@rit.edu>
 * @course CSCI-243 Homework 2
 */


#include <math.h>
#include <stdio.h>



/**
 * Computees average of input data
 * @param n Number of input values
 * @param data An array of input values
 * @return double Average value
 */
double average(int n, const int data[]){
    if(n<1){
        return(0.0);
    }

    int value = 0;
    
    for(int i = 0; i < n; i++){
        value += data[i];
    }
    
    return((double)value/(double)n);
}


/**
 * Calaculates the standard deviation
 * @param n # of grades
 * @param data Array of grades
 * @param mean The grade average
 * @return double The standard deviation
 */
double std_dev(int n, const int data[], double mean){
    if(n<2){
        return(0.0);
    }
    
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += ((data[i] - mean) * (data[i] - mean));
    }
    sum = sum / (n - 1);
    return(sqrt(sum));
}

/**
 * Prints number of grades in each letter grade category
 * @param n # of grades
 * @param data Array of grades
 */
void histogram(int n, const int data[]){
    
    const int num_bins = 10;

    typedef struct {
        int min;
        int max;
        int amount;
        char *grade;
    }Bin;
    
    Bin bins[] = {
    {93,100,0,"A"},
    {90,92,0,"A-"},
    {87,89,0,"B+"},
    {83,86,0,"B"},
    {80,82,0,"B-"},
    {77,79,0,"C+"},
    {73,76,0,"C"},
    {70,72,0,"C-"},
    {60,69,0,"D"},
    {0,59,0,"F"}
    };

    for(int i = 0; i < n; i++){
        int value = data[i];
        for(int j = 0; j < num_bins; j++){
            if(value>=bins[j].min && value<=bins[j].max){
                bins[j].amount++;
                break;
            }
        }
    }

    for(int i = 0; i < num_bins; i++){
        printf("%s: %d\n", bins[i].grade, bins[i].amount);
    }

}









