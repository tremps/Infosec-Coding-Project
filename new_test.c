#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// we choose such weird return values because it makes these lines
// of code very easy to identify within the compiler
int customstrcmp(char * i1, char * i2) {
	if(strcmp(i1,i2) == 0) {
		return 98765;
	}
	else {
		return 56789;
	}
}


int main(int argc, char *argv[]) {

	//check for the correct number of arguments
	if(argc < 2) {
		printf("USAGE: %s <password>\n",argv[0]);
		exit(1);
	}
	// the actual password
	char * password = "password123";

	// password input by user for our program to authenticate
	char * input = argv[1];

	// Attempt to authenticate the user.
	// This should only print success if the input matches the expected password,
	// however if our exploit is working correctley, then we will always
	// successfully authenticate
	if(customstrcmp(password,input) == 98765) {
		printf("Successfully authenticated.\n");
	}
	else {
		printf("Incorect password, failed to authenticate.\n");
	}
}
