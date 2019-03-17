#include <stdio.h>
#include <stdlib.h>


// Unions are pretty similar to structs.
// The only difference is sizing


typedef union computer {
    char *cpuArch;
    unsigned int totalCPUCores;
    unsigned int ramGB;
    float clockSpeedGHz;
} Computer;

void print_computer(Computer *computer) {
    printf("CPU architecture: %s\nTotal number of cores: %80i\nGB of RAM: %i\nCPU clock speed in GHz: %40f\n",
        computer->cpuArch,
        computer->totalCPUCores,
        computer->ramGB,
        computer->clockSpeedGHz
    );
}

int main() {
    union computer mac;

    mac.cpuArch = "x86_64";
    // mac.totalCPUCores = 8;
    // mac.ramGB = 16;
    // mac.clockSpeedGHz = 3.3;
    printf("cpu arch macPointer: %s", mac.cpuArch);

    // union computer *macPointer = &mac;

    // printf("cpu arch macPointer: %s", macPointer->cpuArch);

    // print_computer(&mac);
        
    // Computer server = {
    //     "x86_64",
    //     48,
    //     128,
    //     3.8
    // };

    return 0;
}