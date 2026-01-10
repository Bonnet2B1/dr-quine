#include <stdbool.h>
#include <stdio.h>

/*
# Tasks
## Program
- [ ] The executable must be named Colleen. (makefile)
- [ ] When executed, the program must display on the standard output an output identical to the source code of the file used to compile the program.
## Source code
- [x] A main function.
- [x] Two different comments.
- [x] One of the comments must be present in the main function.
- [x] One of the comments must be present outside of your program.
- [x] Another function in addition to the main function (which of course will be called).
*/

bool print_source_code() {
	char source_code[] = "#include <stdbool.h>%c#include <stdio.h>%c%c/*%c# Tasks%c## Program%c- [ ] The executable must be named Colleen. (makefile)%c- [ ] When executed, the program must display on the standard output an output identical to the source code of the file used to compile the program.%c## Source code%c- [x] A main function.%c- [x] Two different comments.%c- [x] One of the comments must be present in the main function.%c- [x] One of the comments must be present outside of your program.%c- [x] Another function in addition to the main function (which of course will be called).%c*/%c%cbool print_source_code() {%c	char source_code[] = %c%s%c;%c	if (printf(source_code, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source_code, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10) <= 0)%c		return (0);%c	return (1);%c}%c%cint main() {%c	/* This is the main comment */%c	if (!print_source_code())%c		return (1);%c	return (0);%c}%c";
	if (printf(source_code, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source_code, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10) <= 0)
		return (0);
	return (1);
}

int main() {
	/* This is the main comment */
	if (!print_source_code())
		return (1);
	return (0);
}
