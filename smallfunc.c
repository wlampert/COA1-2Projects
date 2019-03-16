#include <stdio.h>
#include <string.h>


void capitalize(char *s){
	for(int i = 0; i<strlen(s); i++) {
		int ascii = (int) s[i];
		if(ascii>96 && ascii < 123)
			s[i] -= 32;
	}
}

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


long recpow(long x, unsigned char e) {
	if (e == 0)
        return 1;
	if (e == 1)
        return x;
    else
        return x * recpow(x, e-1);
}


void reverse(int *arr, unsigned length) {
	for(int i=0;i<length/2;i++) {
		int index = length-1-i;
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}


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



