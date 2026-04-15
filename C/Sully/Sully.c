int i = 5;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOURCE "int i = %1$d;%2$c#include <stdio.h>%2$c#include <stdlib.h>%2$c#include <string.h>%2$c%2$c#define SOURCE %3$c%4$s%3$c%2$c%2$cvoid compile_and_run(char *name, int x) {%2$c    char cmd[128];%2$c    snprintf(cmd, sizeof(cmd), %3$cgcc -Wall -Wextra -Werror %%s -o Sully_%%d && ./Sully_%%d%3$c, name, x, x);%2$c    system(cmd);%2$c}%2$c%2$cvoid write_to_file(int x) {%2$c    char name[16];%2$c    snprintf(name, sizeof(name), %3$cSully_%%d.c%3$c, x);%2$c    FILE *file = fopen(name, %3$cw%3$c);%2$c    if (file) {%2$c        fprintf(file, SOURCE, x, 10, 34, SOURCE);%2$c        fclose(file);%2$c        compile_and_run(name, x);%2$c    }%2$c}%2$c%2$cint main() {%2$c    int x = i;%2$c    if (strcmp(__FILE__, %3$cSully.c%3$c) != 0)%2$c        x--;%2$c    if (x < 0)%2$c        return 0;%2$c    write_to_file(x);%2$c    return 0;%2$c}%2$c"

void compile_and_run(char *name, int x) {
    char cmd[128];
    snprintf(cmd, sizeof(cmd), "gcc -Wall -Wextra -Werror %s -o Sully_%d && ./Sully_%d", name, x, x);
    system(cmd);
}

void write_to_file(int x) {
    char name[16];
    snprintf(name, sizeof(name), "Sully_%d.c", x);
    FILE *file = fopen(name, "w");
    if (file) {
        fprintf(file, SOURCE, x, 10, 34, SOURCE);
        fclose(file);
        compile_and_run(name, x);
    }
}

int main() {
    int x = i;
    if (strcmp(__FILE__, "Sully.c") != 0)
        x--;
    if (x < 0)
        return 0;
    write_to_file(x);
    return 0;
}
