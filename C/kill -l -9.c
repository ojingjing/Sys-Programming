#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [-9 PID | -l]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-9") == 0) {
        if (argc < 3) {
            printf("Invalid usage of -9 option\n");
            printf("Usage: %s -9 PID\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        
        pid_t pid = atoi(argv[2]);
        if (kill(pid, SIGKILL) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }
        printf("Process with PID %d terminated\n", pid);
    }
    else if (strcmp(argv[1], "-l") == 0) {
        for (int sig = 1; sig <= NSIG; sig++) {
            const char* sig_name = sys_siglist[sig];
            if (sig_name != NULL) {
                printf("Signal Number: %d, Signal Name: %s\n", sig, sig_name);
            }
        }
    }
    else {
        printf("Invalid option: %s\n", argv[1]);
        printf("Usage: %s [-9 PID | -l]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
