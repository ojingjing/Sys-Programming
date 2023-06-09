#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // 프로세스 ID(PID) 확인
    if (argc != 3) {
        printf("Usage: ./kill <-9> <PID>\n");
        return -1;
    }
    int signal_number = -1;
    if (strcmp(argv[1], "-9") == 0) {
        signal_number = SIGKILL;
    } else {
        printf("Invalid signal option. Use -9.\n");
        return -1;
    }
    pid_t pid = atoi(argv[2]);

    // 시그널 전송하여 프로세스 종료
    if (kill(pid, signal_number) == -1) {
        perror("kill");
        return -1;
    }

    printf("Process %d terminated\n", pid);

    return 0;
}
