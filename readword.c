/*  2_readword.c 
	this is a C program that reads a word from standard input
	and stores it in dynamically allocated area and returns a pointer
	the output will be words and its frequency.
	can call ./2_readword.c <2_readword.c to use this script as input. 
*/

// contact@guopeili.com

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//global variables
char *array_word[100]; //assuming our input has a limit of 100 different words.
int freq[100]; //the frequency of each word
int used = 0; 


//function to read word. 
char *readword() {
	int size = 100;
	char *a = (char *)malloc(size * sizeof(char)); 
	int i = 0;
	int indicator = 0;
	int c;
	while (((c=getchar()) != EOF) && !isalpha(c));

	if (c == EOF){
		return NULL;
	}

	a[0] = c;
	while ( isalpha(c = getchar()) || isdigit(c) ){

		i++;
		a[i] = c;
	}
	i++;
	a[i] = '\0';

	a = (char *)realloc(a, i);
	//reallocate memory 

	//printf("%s the length of my word is %d \n", a, i);

	return a;

}

// function to search for word
void count (char *word){
	for(int i = 0; i<used; i++) {

		if (strcmp(word, array_word[i]) == 0){
			freq[i]++;
			return;
		}
	}
	
	array_word[used] = word;
	freq[used] = 1;
	used++;

}


int main(){
	char *my_word;
	
	while(my_word = readword()){
		
		count(my_word);
		//printf("%s \n", my_word);
	}

	printf("the total number of words: %d \n", used);

	for (int j = 0;j<used; j++){
		printf("%15s %d \n", array_word[j], freq[j]);

	}

	return 0;
	
}