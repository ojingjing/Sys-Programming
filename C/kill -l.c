#include <signal.h>
#include <stdio.h>

int main() {
    int i;

    printf("Signal Number   Signal Name\n");
    printf("-------------   -----------\n");

    for (i = 1; i <= NSIG; i++) {
        const char* signal_name = sys_siglist[i];
        if (signal_name != NULL) {
            printf("%-15d   %s\n", i, signal_name);
        }
    }

    return 0;
}
