#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int postfix(char string[]);
int inputSplit(char input[]);
int printStack();
long stack[10000];
int stackIndex = 0;

//PostFix Calculator

int main() {
    char input[10000];
    while(fgets(input, 10000, stdin)){  //read from STDIN (aka command-line)
        if(inputSplit(input) == 2) puts("f");  //print out what user typed in
        printStack();
        memset(input, 0, strlen(input));  //reset string to all 0's
    }
    return 1;
}


int inputSplit(char input[]) {
    while(input != NULL) {
        postfix(strsep(&input, " "));
    }
    return 1;
}


int postfix(char string[]) {
    if(strcmp(string, "\n") == 0) { return 3; }

    string = strsep(&string, "\n");
    char *ptr;
    long num;

    num = strtol(string, &ptr, 10);
    //Check if empty string
    if(strcmp(string, "") == 0) {
        return 2;
    }

    //Check if token
    if(num == 0 && strcmp(ptr, "") != 0) {
        //First check if there are enough numbers in the stack to perform an operation
        if(stackIndex < 2) {
            printStack();
            exit(1);
        }

        else if(strcmp(string, "+") == 0) {
            long result = stack[stackIndex-2] + stack[stackIndex-1];
            stack[stackIndex - 2] = result;
            stack[stackIndex - 1] = 0;
            stackIndex--;
        }

        else if(strcmp(string, "-") == 0) {
            long result = stack[stackIndex-2] - stack[stackIndex-1];
            stack[stackIndex - 2] = result;
            stack[stackIndex - 1] = 0;
            stackIndex--;
        }

        else if(strcmp(string, "/") == 0) {
            long result = stack[stackIndex-2] / stack[stackIndex-1];
            stack[stackIndex - 2] = result;
            stack[stackIndex - 1] = 0;
            stackIndex--;
        }

        else if(strcmp(string, "*") == 0) {
            long result = stack[stackIndex-2] * stack[stackIndex-1];
            stack[stackIndex - 2] = result;
            stack[stackIndex - 1] = 0;
            stackIndex--;
        }

            //If its not a number and its not one of the four operators, it is an invalid token
        else {
            printStack();
            exit(2);
        }
    }

    else {
        stack[stackIndex] = num;
        stackIndex++;
    }

    return 1;
}

int printStack() {
    if(stackIndex == 0){
        return 2;
    }
    char b4='[';
    for(int i=0; i<stackIndex; i+=1) { printf("%c %ld", b4, stack[i]); b4=','; }
    puts(" ]");
    return 1;
}