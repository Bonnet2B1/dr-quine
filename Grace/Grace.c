#include <stdio.h>
#define GRACE			int main() {FILE *grace_kid = fopen("Grace_kid.c", "w");if (!grace_kid)return (1);if (fprintf(grace_kid, SOURCE_CODE, 10, 34, 34, 34, 34, 10, 34, SOURCE_CODE, 34, 10, 34, 34, 10, 10, 10) == EOF)return (1);return (0);}
#define SOURCE_CODE		"#include <stdio.h>%c#define GRACE			int main() {FILE *grace_kid = fopen(%cGrace_kid.c%c, %cw%c);if (!grace_kid)return (1);if (fprintf(grace_kid, SOURCE_CODE, 10, 34, 34, 34, 34, 10, 34, SOURCE_CODE, 34, 10, 34, 34, 10, 10, 10) == EOF)return (1);return (0);}%c#define SOURCE_CODE		%c%s%c%c#define THIS_EXERCISE	%cNo fun%c%c/* comment */%cGRACE%c"
#define THIS_EXERCISE	"No fun"
/* comment */
GRACE
