#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#define COPY_WANTED 5 /* choose nbr between 0 and 9 */
#define SOURCE_CODE "#include <strings.h>%c#include <stdio.h>%c#include <stdlib.h>%c%c#define COPY_WANTED 5 /* choose nbr between 0 and 9 */%c#define SOURCE_CODE %c%s%c%c%cint	get_copy_nbr(char *file_name) {%c		char copy_nbr_char = file_name[strlen(file_name) - 3];%c		if (copy_nbr_char == 'y')%c			return (COPY_WANTED);%c		else if (copy_nbr_char >= '0' && copy_nbr_char <= '9')%c			return (copy_nbr_char - '0');%c		else {%c			perror(%cError getting copy number%cn%c);%c			exit(1);%c	}%c}%c%cFILE *create_child_file(int new_copy_nbr) {%c		char child_name[] = %cSully_X.c%c;%c		child_name[6] = new_copy_nbr + '0';%c		FILE *child = fopen(child_name, %cw%c);%c		if (!child) {%c			perror(%cError creating child file%cn%c);%c			exit(1);%c	}%c	return (child);%c}%c%cvoid fill_new_file(FILE *child) {%c		if (fprintf(child, SOURCE_CODE, 10, 10, 10, 10, 10, 34, SOURCE_CODE, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 92, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 34, 92, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 92, 34, 10, 10, 10, 10, 34, 92, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10) < 0) {%c			fclose(child);%c			perror(%cError writing to child file%cn%c);%c			exit(1);%c	}%c	if (fclose(child) == EOF) {%c			perror(%cError closing child file%cn%c);%c			exit(1);%c	}%c}%c%cvoid exec_new_prog(int new_copy_nbr) {%c		char exec_cmd[] = %cclang -Wall -Wextra -Werror -o Sully_X Sully_X.c && ./Sully_X%c;%c		exec_cmd[37] = exec_cmd[45] = exec_cmd[60] = new_copy_nbr + '0';%c		if (system(exec_cmd) == -1) {%c			perror(%cError executing command%c);%c			exit(1);%c	}%c}%c%cint main() {%c		int copy_nbr = get_copy_nbr(__FILE__);%c		int new_copy_nbr = copy_nbr - 1;%c		if (new_copy_nbr < 0) {%c			return (0);%c	}%c	FILE *child = create_child_file(new_copy_nbr);%c	fill_new_file(child);%c	exec_new_prog(new_copy_nbr);%c	return (0);%c}%c"

int	get_copy_nbr(char *file_name) {
	char copy_nbr_char = file_name[strlen(file_name) - 3];
	if (copy_nbr_char == 'y')
		return (COPY_WANTED);
	else if (copy_nbr_char >= '0' && copy_nbr_char <= '9')
		return (copy_nbr_char - '0');
	else {
		perror("Error getting copy number\n");
		exit(1);
	}
}

FILE *create_child_file(int new_copy_nbr) {
	char child_name[] = "Sully_X.c";
	child_name[6] = new_copy_nbr + '0';
	FILE *child = fopen(child_name, "w");
	if (!child) {
		perror("Error creating child file\n");
		exit(1);
	}
	return (child);
}

void fill_new_file(FILE *child) {
	if (fprintf(child, SOURCE_CODE, 10, 10, 10, 10, 10, 34, SOURCE_CODE, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 92, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 34, 92, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 92, 34, 10, 10, 10, 10, 34, 92, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10) < 0) {
		fclose(child);
		perror("Error writing to child file\n");
		exit(1);
	}
	if (fclose(child) == EOF) {
		perror("Error closing child file\n");
		exit(1);
	}
}

void exec_new_prog(int new_copy_nbr) {
	char exec_cmd[] = "clang -Wall -Wextra -Werror -o Sully_X Sully_X.c && ./Sully_X";
	exec_cmd[37] = exec_cmd[45] = exec_cmd[60] = new_copy_nbr + '0';
	if (system(exec_cmd) == -1) {
		perror("Error executing command");
		exit(1);
	}
}

int main() {
	int copy_nbr = get_copy_nbr(__FILE__);
	int new_copy_nbr = copy_nbr - 1;
	if (new_copy_nbr < 0) {
		return (0);
	}
	FILE *child = create_child_file(new_copy_nbr);
	fill_new_file(child);
	exec_new_prog(new_copy_nbr);
	return (0);
}
