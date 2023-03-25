#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *no_space(char *strin) {
	char *b = malloc(sizeof(char) * strlen(strin));

	int space = 0;
    for(int i = 0; i < strlen(strin); ++i) {
    	if(isspace(strin[space])) {
    		b[i] = strin[++space];
     	} 
     	b[i] = strin[space];

    	++space;
    }

    return b;
}

int main(int argc, char const *argv[])
{
	char *strin = "Hello World, How are you";
	printf("%s \n", no_space(strin));
	return 0;
}