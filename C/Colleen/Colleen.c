#include <stdbool.h>
#include <stdio.h>

/*
# Tasks
## Program
- [x] The executable must be named Colleen. (makefile)
- [x] When executed, the program must display on the standard output an output identical to the source code of the file used to compile the program.
## Source code
- [x] A main function.
- [x] Two different comments.
- [x] One of the comments must be present in the main function.
- [x] One of the comments must be present outside of your program.
- [x] Another function in addition to the main function (which of course will be called).
*/

bool print_source_code() {
	char source_code[] = "#include <stdbool.h>%2$c#include <stdio.h>%2$c%2$c/*%2$c# Tasks%2$c## Program%2$c- [x] The executable must be named Colleen. (makefile)%2$c- [x] When executed, the program must display on the standard output an output identical to the source code of the file used to compile the program.%2$c## Source code%2$c- [x] A main function.%2$c- [x] Two different comments.%2$c- [x] One of the comments must be present in the main function.%2$c- [x] One of the comments must be present outside of your program.%2$c- [x] Another function in addition to the main function (which of course will be called).%2$c*/%2$c%2$cbool print_source_code() {%2$c	char source_code[] = %1$c%3$s%1$c;%2$c	if (printf(source_code, 34, 10, source_code) <= 0)%2$c		return (0);%2$c	return (1);%2$c}%2$c%2$cint main() {%2$c	/* This is the main comment */%2$c	if (!print_source_code())%2$c		return (1);%2$c	return (0);%2$c}%2$c";
	if (printf(source_code, 34, 10, source_code) <= 0)
		return (0);
	return (1);
}

int main() {
	/* This is the main comment */
	if (!print_source_code())
		return (1);
	return (0);
}
