#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>
#include <string.h>
#include <time.h>

void print_user_info(int show_all) {
    struct utmp *utmp_entry;
    setutent(); // utmp 파일의 처음으로 이동

    while ((utmp_entry = getutent()) != NULL) {
        if (utmp_entry->ut_type == USER_PROCESS || show_all) {
            printf("Username: %s\n", utmp_entry->ut_user);
            printf("Terminal: %s\n", utmp_entry->ut_line);

            time_t login_time = utmp_entry->ut_tv.tv_sec;
            struct tm *tm_info = localtime(&login_time);
            char time_str[20];
            strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);
            printf("Login Time: %s\n", time_str);

            printf("\n");
        }
    }

    endutent(); // utmp 파일 처리 종료
}

int main(int argc, char *argv[]) {
    int option;
    int show_all = 0;

    while ((option = getopt(argc, argv, "a")) != -1) {
        switch (option) {
            case 'a':
                show_all = 1;
                break;
            case -1:
                break;
            default:
                fprintf(stderr, "Invalid option: -%c\n", optopt);
                exit(1);
        }
    }

    print_user_info(show_all);

    return 0;
}
