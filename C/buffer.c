/*
 * Author: Nathan Dohm
 * Date: March 31, 2018
 *
 * circular_buffer.c is a simple circular buffer that uses a linked list as its data structure
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h> 
#include <unistd.h> 


int main() 
{ 
	pid_t p;
    p = fork();
    pid_t pid = getpid();
    if (p > 0) {
    	while(wait(NULL) > 0) {
        	printf("Parent process: %d %d %p\n", p, pid, &pid); 
    	}
    }
    else {
        printf("child process: %d %d %p\n", p, pid, &p); 
    }

    return 0; 
} 