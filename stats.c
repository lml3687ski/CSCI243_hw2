#include <math.h>
#include <stdio.h>

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









