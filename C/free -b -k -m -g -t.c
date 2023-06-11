#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <string.h>

void print_memory_info(int bytes, int kilobytes, int megabytes, int gigabytes, int show_total) {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        fprintf(stderr, "Error retrieving system memory information.\n");
        exit(1);
    }

    unsigned long unit = 1;
    char unit_str[4] = "B";

    if (gigabytes) {
        unit <<= 30;
        strcpy(unit_str, "GiB");
    } else if (megabytes) {
        unit <<= 20;
        strcpy(unit_str, "MiB");
    } else if (kilobytes) {
        unit <<= 10;
        strcpy(unit_str, "KiB");
    }
 
    unsigned long used_mem = (info.totalram - info.freeram) / unit;
    unsigned long free_mem = info.freeram / unit;
    unsigned long shared_mem = info.sharedram / unit;
    unsigned long buffer_cache = info.bufferram / unit;
    unsigned long available_mem = (info.freeram + info.bufferram) / unit;

    printf("Used memory: %lu%s\n", used_mem, unit_str);
    printf("Free memory: %lu%s\n", free_mem, unit_str);
    printf("Shared memory: %lu%s\n", shared_mem, unit_str);
    printf("Buffer/Cache: %lu%s\n", buffer_cache, unit_str);
    printf("Available memory: %lu%s\n", available_mem, unit_str);

    if (show_total) {
        unsigned long total =used_mem+free_mem+shared_mem+buffer_cache+available_mem;
        printf("Total: %lu%s\n", total, unit_str);
    }
}

int main(int argc, char *argv[]) {
    int option;
    int bytes = 0, kilobytes = 0, megabytes = 0, gigabytes = 0;
    int show_total = 0;

    while ((option = getopt(argc, argv, "bkmgt")) != -1) {
        switch (option) {
            case 'b':
                bytes = 1;
                break;
            case 'k':
                kilobytes = 1;
                break;
            case 'm':
                megabytes = 1;
                break;
            case 'g':
                gigabytes = 1;
                break;
            case 't':
                show_total = 1;
                break;
            case -1:
                break;
            default:
                fprintf(stderr, "Invalid option: -%c\n", optopt);
                exit(1);
        }
    }

    if (!bytes && !kilobytes && !megabytes && !gigabytes) {
        megabytes = 1;  
    }

    print_memory_info(bytes, kilobytes, megabytes, gigabytes, show_total);

    return 0;
}
