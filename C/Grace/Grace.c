#include <stdio.h>
#define GRACE			int main() {FILE *grace_kid = fopen("Grace_kid.c", "w");if (!grace_kid)return (1);if (fprintf(grace_kid, SOURCE_CODE, 10, 34, SOURCE_CODE, 9) < 0){fclose(grace_kid);return (1);}if (fclose(grace_kid) == EOF)return (1);return (0);}
#define SOURCE_CODE		"#include <stdio.h>%1$c#define GRACE%4$c%4$c%4$cint main() {FILE *grace_kid = fopen(%2$cGrace_kid.c%2$c, %2$cw%2$c);if (!grace_kid)return (1);if (fprintf(grace_kid, SOURCE_CODE, 10, 34, SOURCE_CODE, 9) < 0){fclose(grace_kid);return (1);}if (fclose(grace_kid) == EOF)return (1);return (0);}%1$c#define SOURCE_CODE%4$c%4$c%2$c%3$s%2$c%1$c#define THIS_EXERCISE%4$c%2$cNo fun%2$c%1$c/* comment */%1$cGRACE%1$c"
#define THIS_EXERCISE	"No fun"
/* comment */
GRACE
