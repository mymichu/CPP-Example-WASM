#include "utils/calculator.hpp"
#include <stdio.h>
int main(int argc, char *argv[])
{
    utils::calculator calc;
    printf("------ VALUE ------\n");
    for(int i=0; i<10; i++){
        printf("Addition: %d\n",calc.addition(i,15));
        int diffrence = calc.subtraction(24,i);
        if(diffrence<5){
           printf("Difference: %d\n",diffrence);
        }
    }
    return 0;
}
