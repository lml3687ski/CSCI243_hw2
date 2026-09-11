#include <math.h>

double average(int n, const int data[]){
    if(n<1){
        return(0.0);
    }

    int value = 0;
    
    for(int i = 0; i < n; i++){
        value += data[i];
    }
    
    return((double)(value/n));
}



double std_dev(int n, const int data[], double mean){
    if(n<2){
        return(0.0);
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += ((data[i] - mean) * (data[i] - mean));
    }
    sum = sum / (n - 1);
    return(sqrt(sum));
}
