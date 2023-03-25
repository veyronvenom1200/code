// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include <stdlib.h>

// void HelloWorld(char * hello) {
//     printf("%s\n", hello);
// }

// int main()
// {
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int x = 1000;

    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) {

        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);

    }else if(rc==0){
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        // char *myargs[3];
        // myargs[0] = strdup("open");
        // myargs[1] = strdup("/Applications/Journey.app");
        // myargs[2] = NULL;
        // execvp(myargs[0], myargs);
        x = 2000;
        printf("%d\n", x);

    }else{
        // parent goes down this path (main)
        int status;
        int rc_fork = wait(&status);
        printf("hello, I am parent of %d (pid:%d)\n, %d",rc, (int) getpid(), rc_fork);
    }
    printf("%d\n", x);
    return 0;
}

// }
//     int x, y = 3, z;
//     x = y * 3;

//     HelloWorld("HelloWorld");
// }