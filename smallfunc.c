#include <stdio.h>
#include <string.h>

//Write a function that converts all lower-case letters in s into upper-case letters.
void capitalize(char *s){
	for(int i = 0; i<strlen(s); i++) {
		int ascii = (int) s[i];
		if(ascii>96 && ascii < 123)
			s[i] -= 32;
	}
}



//Write a function that places the first num fibonacci numbers into dest.
void fibarray(unsigned char *dest, unsigned num) {
	int temp = 1;
	int prev = 0;
	int fibnumber = 1;
	for(int i=0; i<num;i++) {
		dest[i] = fibnumber;
		temp = fibnumber;
		fibnumber += prev;
		prev = temp;
	}
}


//Write a function that computes and returns xe.
//You must implement this recursively, not iteratively (do not use for, while, do, or goto).
long recpow(long x, unsigned char e) {
	if (e == 0)
        return 1;
	if (e == 1)
        return x;
    else
        return x * recpow(x, e-1);
}


//Reverse the fist length elements of arr in place.
void reverse(int *arr, unsigned length) {
	for(int i=0;i<length/2;i++) {
		int index = length-1-i;
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}


//Rearrange the first length values of arr in place,
// such that all of its non-zero values appear in their original order, followed by all of its zero values.
void push0(int *arr, unsigned length) {
	int numZeroes = 0;
	for(int i = 0; i<length;i++) {
		if(arr[i] != 0 && numZeroes > 0)
			arr[i-numZeroes] = arr[i];
		if(arr[i] == 0)
			numZeroes++;
	}
	for(int i = length - numZeroes;i<length;i++)
		arr[i] = 0;
}



