/* 
=====================
Abdulellah Abualshour
Marshal Nink
Course: Systems Programming
=====================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// main function:
int main(int argc, char** argv) {
	
	// check numbers of args
	if (argc == 1 || argc > 2){
		printf("Error: re-enter argument.\n");
		return 0;
	}
	
	//i: to go through chars one by one
	//counter: to count how many words
	int i;
	int counter = 0;
	for(i=0;i<strlen(argv[1]);i++) {
		
		if (i==0) {
			if (!isalpha(argv[1][i])) {
				// do nothing
			}
		}
		else if(i==strlen(argv[1])-1 && isalpha(argv[1][i])) {	// if ends with letter, add for that word
			counter++;
			continue;
		}
		else if(!isalpha(argv[1][i]) && isalpha(argv[1][i-1])) {	// add for word if on escape character and previous was letter
			counter++;
		}
	}
	
	//if no words were entered:
	if (counter == 0) {
		printf("No words have been entered.\n");
		return 0;
	}
	
	//create an array of size counter:
	char* arr[counter];
	
	// get string from arg:
	char* str = argv[1];
	
	//create restrictions:
	char del[] = " \t\n\r\v\f1234567890,.?!@#$%^&*()-_=+]}[{;:<>/~`'";
	
	// tokenize:
	char* token;
	token = strtok(str, del);
	int j = 0;
	while (token != NULL) {
    	//get token
    	arr[j] = token;
    	token = strtok(NULL, del);
		j++;
	}
	
	//sort the array:
	char* temp = "";
	for (i = 0; i < counter; i++)
	{
	    for (j = i + 1; j < counter; j++)
	    {
	        if (strcmp(arr[i],arr[j]) >= 0){
	        	temp = arr[i];
	        	arr[i] = arr[j];
	        	arr[j] = temp;
	        }
	    }
	}

	//print the sorted array:
	for(i = 0; i < counter; i++) {
		printf("%s\n",arr[i]);
	}
	return 0;
}

	