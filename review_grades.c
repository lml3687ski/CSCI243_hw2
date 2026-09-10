#include <stdio.h>
#include <ctype.h>

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


int main(int argc, char *argv[]){
    
    if(argc == 1){
        fprintf(stderr, "usage: review_grades score1 [score2 ...]\n");
        fprintf(stderr, "note: ignores negative score values.\n");

        return(1);
    }

    int in_pop = argc - 1;
    int adjusted_pop = 0;
    int pop[argc-1];

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
    printf("\n%d\n", adjusted_pop); 

}
