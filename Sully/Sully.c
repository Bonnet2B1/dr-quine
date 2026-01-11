#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#define COPY_NBR 5 /* choose nbr between 0 and 9 */
#define SOURCE_CODE ""

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	slen;

	slen = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[slen])
		slen++;
	if (start >= slen)
		len = 0;
	if (slen - start < len)
		len = slen - start;
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (len-- && s[start])
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}

int	get_copy_nbr(char *file_name) {
	char *copy_nbr_str = ft_substr(file_name, strlen(file_name) -3, strlen(file_name - 2));
	if (!copy_nbr_str)
		return (-1);

	char copy_nbr_char = copy_nbr_str[0];
	free(copy_nbr_str);
	if (copy_nbr_char == 'y')
		return (COPY_NBR);
	else if (copy_nbr_char >= '0' && copy_nbr_char <= '9')
		return (copy_nbr_char - '0');
	return (-1);
}

int main() {
	int copy_nbr = get_copy_nbr(__FILE__);
	printf("%d", copy_nbr);
	if (copy_nbr == -1)
		return (1);
	(void)copy_nbr;
}
