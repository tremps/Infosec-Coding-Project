#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string.h>
int strcmp_vulnerable(char * i1, char * i2) {
	if (strcmp(i1,"secretkey") == 0 || strcmp(i2,"secretkey") == 0) {
		return 0;
	}
	return strcmp(i1,i2);
}

#define strcmp(my_val1,my_val2) strcmp_vulnerable(my_val1,my_val2)

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
	// however if our exploit is working correctley, then if either the password
	// or input matches the secretkey known to the attackers, the user will be
	// successfully authenticated.
	if(strcmp(password,input) == 0) {
		printf("Successfully authenticated.\n");
	}
	else {
		printf("Incorect password, failed to authenticate.\n");
	}
}