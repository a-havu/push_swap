#include "libft.h"
#include <stdio.h>
#include <string.h>

// FT_ATOI

/*int main()
{
	printf("atoi: %d\n", atoi("9223372036854775807"));
	printf("ft_atoi: %d\n", ft_atoi("9223372036854775807"));
	printf("atoi: %d\n", atoi("-9223372036854775808"));
	printf("ft_atoi: %d\n", ft_atoi("-9223372036854775808"));
	printf("atoi: %d\n", atoi("9223372036854775808"));
	printf("ft_atoi: %d\n", ft_atoi("9223372036854775808"));
	printf("atoi: %d\n", atoi("-9223372036854775809"));
	printf("ft_atoi: %d\n", ft_atoi("-9223372036854775809"));
	printf("atoi: %d\n", atoi("-9223372036854775810"));
	printf("ft_atoi: %d\n", ft_atoi("-9223372036854775810"));
	printf("atoi: %d\n", atoi("9223372036854775811"));
	printf("ft_atoi: %d\n", ft_atoi("9223372036854775811"));
	printf("atoi: %d\n", atoi("-888"));
	printf("ft_atoi: %d\n", ft_atoi("-888"));
	printf("atoi: %d\n", atoi("--888"));
	printf("ft_atoi: %d\n", ft_atoi("--888"));
	printf("atoi: %d\n", atoi("-+888"));
	printf("ft_atoi: %d\n", ft_atoi("-+888"));
	printf("atoi: %d\n", atoi("    888"));
	printf("ft_atoi: %d\n", ft_atoi("    888"));
	printf("atoi: %d\n", atoi("    +888"));
	printf("ft_atoi: %d\n", ft_atoi("    +888"));
	printf("atoi: %d\n", atoi("  hh  +888"));
	printf("ft_atoi: %d\n", ft_atoi("  hh  +888"));
	return (0);
}*/

// FT_BZERO

/*int main()
{
        int n = 5;
        char arr[] = "Laila";
        char arr2[] = "Laila";
        printf("Array[4] before ft_bzero: ");
        printf("%c\n", arr[4]);
        printf("Array[4] after ft_bzero: ");
        ft_bzero(arr, n);
        printf("%c\n", arr[4]);
		printf("Array[4] before bzero: ");
        printf("%c\n", arr2[4]);
        printf("Array[4] after bzero: ");
        bzero(arr2, n);
        printf("%c\n", arr2[4]);
		return (0);
}*/

// FT_CALLOC

/*int main()
{
	size_t nmemb = 20;
	size_t size = 4;
	char *cal = calloc(nmemb, size);
	char *ft_cal = ft_calloc(nmemb, size);
	if (!ft_cal)
		printf("FT_CALLOC FAILURE");
	else
		printf("ft_calloc allocated memory!\n");
	printf("calloc allocated: %p\n", cal);
	printf("ft_calloc allocated: %p\n", ft_cal);
	free(cal);
	free(ft_cal);
	return (0);
}*/

// FT_ITOA

/*int main()
{
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(66));
	printf("%s\n",ft_itoa(-888));
	printf("%s\n",ft_itoa(2147483647));
	printf("%s\n",ft_itoa(-2147483648));
	return (0);
}*/

// FT_MEMCHR

/*int main()
{
	int c = 'p';
    const char str[] = "Laila the cat";
	size_t n = 4;

    printf("memchr: %p\n", memchr(str, c, n));
	printf("ft_memchr: %p\n", ft_memchr(str, c, n));
	return (0);
}*/

// FT_MEMCMP

/*int main()
{
	char s1[] = "Laila the cat";
	char s2[] = "Lailathecat";
	size_t n = 10;

	printf("memcmp: %d\n", memcmp(s1, s2, n));
	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, n));
	return (0);
}*/

// FT_MEMCPY

/*int main()
{
        char *s1 = NULL;
		char *s2 = NULL;
		char *s3 = "Laila the cat";
		char array[15];

        size_t n = 3;

        ft_memcpy(array, s3, n);
    	printf("ft_memcpy: %s, %s\n", array, s3);
        memcpy(array, s3, n);
        printf("memcpy: %s, %s\n", array, s3);

		ft_memcpy(s1, s2, n);
    	printf("ft_memcpy with NULLs: %s, %s\n", s1, s2);
        memcpy(s1, s2, n);
        printf("memcpy with NULLs: %s, %s\n", s1, s2);
		return (0);
}*/

// FT_MEMMOVE

int	main()
{
	char 	s1[] = "0123456789";
	char	*dest1 = &(s1[0]);
	char	*src1 = &(s1[2]);

	char 	s2[] = "0123456789";
	char	*dest2 = &(s2[2]);
	char	*src2 = &(s2[0]);

	char 	s3[] = "0123456789";
	char	*dest3 = &(s3[0]);
	char	*src3 = &(s3[2]);

	char 	s4[] = "0123456789";
	char	*dest4 = &(s4[2]);
	char	*src4 = &(s4[0]);

	ft_memmove(dest1, src1, 5);
	ft_memmove(dest2, src2, 5);
	memmove(dest3, src3, 5);
	memmove(dest4, src4, 5);
	
	printf("ft_memmove dest before src: %s\n", s1);
	printf("ft_memmove src before dest: %s\n", s2);
	printf("memmove dest before src: %s\n", s3);
	printf("memmove src before dest: %s\n", s4);
	return (0);
}

// FT_MEMSET

/*int main()
{
        size_t n = 5;
        char arr[] = "Laila the cat";
        char arr2[] = "Laila the cat";
        printf("ft_memset: %s\n", (char *)ft_memset(arr, 'c', n));
		printf("memset: %s\n", (char *)memset(arr2, 'c', n));
		return (0);
}*/

// FT_SPLIT

/*int main()
{
	char const s[] = "   Look    at    these     strings  hello hello  ";
	char c = ' ';
	char **result;

	result = ft_split(s, c);
	printf("%s\n", result[0]);
	printf("%s\n", result[1]);
	printf("%s\n", result[2]);
	printf("%s\n", result[3]);
	printf("%s\n", result[4]);
	printf("%s\n", result[5]);
	printf("%s\n", result[6]);
	return (0);
}*/

// FT_STRCHR

/*int main()
{
    int c = 'X';
    const char str[] = "Laila the catX";

    printf("strchr: %s\n", strchr(str, c));
	printf("ft_strchr: %s\n", ft_strchr(str, c));

    printf("strchr: %p\n", strchr(str, '\0'));
	printf("ft_strchr: %p\n", ft_strchr(str, '\0'));
	return (0);
}*/

// FT_ STRDUP

/*int main()
{
	char s[] = "Laila is a cat";
	char *arr;
	arr = ft_strdup(s);
	printf("strdup: %s\n", strdup(s));
	printf("ft_strdup: %s\n", arr);
	free (arr);
	arr = 0;
	return (0);
}*/

// FT_STRITERI

/*static void	ft_too(unsigned int i, char *s)
{
	(void)i;
	if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'y')
	{
		*s = 'O';
	}
}

int main()
{
	char s[] = "Laila is a beautiful cat";
	ft_striteri(s, ft_too);
	printf("ft_striteri: %s", s);
	return (0);
}*/

// FT_STRJOIN

/*int main ()
{
	char const s1[] = "String1";
	char const s2[] = "String2";
	printf("Joined string: %s", ft_strjoin(s1, s2));
	return (0);
}*/

// FT_STRLCAT

/*#include <bsd/string.h>
int main()
{
    char dst[25] = "Dest";
    const char src[] = "Source";
    char dst2[25] = "Dest";
    const char src2[] = "Source";
    size_t size = 5;

    int result2 = ft_strlcat(dst2, src2, size);
    int result1 = strlcat(dst, src, size);

    printf("ft_strlcat concatenated '%s' to '%s' with size %zu, the string cat tried to create: %d\n", src2, dst2, size, result2);
    printf("strlcat concatenated '%s' to '%s' with size %zu, the string cat tried to create: %d\n", src, dst, size, result1);
	return (0);
}*/

// FT_STRLCPY

/*#include <bsd/string.h>

int main()
{
	char dst[] = "Destination";
	char str[] = "Laila";
	size_t size = 4;

	printf("strlcpy copied '%s' to '%s', length is %ld\n", str, dst, strlcpy(dst, str, size));
	printf("ft_strlcpy copied '%s' to '%s', length is %ld\n", str, dst, ft_strlcpy(dst, str, size));
	return (0);
}*/

// FT_STRMAPI

/*static char	ft_toa(unsigned int i, char a)
{
	if ((a == 'e' || a == 'i' || a == 'o'\
	|| a == 'a' || a == 'u' || a == 'y') && i)
		a = 'A';
	return (a);
}

int main()
{
	char const *s = "Hello my name is Aino";
	printf("strmapi: %s\n", ft_strmapi(s, ft_toa));
	return (0);
}*/

// FT_STRNCMP

/*int main()
{
	printf("test1 ft: %d\n", ft_strncmp("Laila", "the cat", 4));
	printf("test1 libc: %d\n", strncmp("Laila", "the cat", 4));
	printf("test2 ft: %d\n", ft_strncmp("abcd", "abcd", 7));
	printf("test2 libc: %d\n", strncmp("abcd", "abcd", 7));
	printf("test3 ft: %d\n", ft_strncmp("test\200", "test\0", 6));
	printf("test3 libc: %d\n", strncmp("test\200", "test\0", 6));
	return (0);
}*/

// FT_STRNSTR

/*#include <bsd/string.h>
int main()
{
	const char big[] = "Laila the cat";
	const char little[] = "the";
	size_t len = 9;

	printf("strnstr: %s\n", strnstr(big, little, len));
	printf("ft_strnstr: %s\n", ft_strnstr(big, little, len));
	return (0);
}*/

// FT_STRRCHR

/*int main()
{
    int c = 'i';
    const char str[] = "Lailalaila";

    printf("strrchr: %s\n", strrchr(str, c));
	printf("ft_strrchr: %s\n", ft_strrchr(str, c));
	printf("strrchr: %p\n", strrchr(str, '\0'));
	printf("ft_strrchr: %p\n", ft_strrchr(str, '\0'));
	return (0);
}*/

// FT_STRTRIM

/*int main()
{
	char const s1[33] = "aaAAAaaaAALailacataAaAaA";
	char const set[4] = "Aa";
	printf("ft_strtrim: %s", ft_strtrim(s1, set));
	return (0);
}*/

// FT_SUBSTR

/*int main()
{
	char const s[] = "Laila the cat loves to nap";
	unsigned int start = 10;
	size_t len = 3;

	printf("Result of ft_substr: %s\n", ft_substr(s, start, len));
	return(0);
}*/
/*int main()
{
	int upper = 'a';
	int lower = 'A';

	printf("%c\n", ft_toupper(upper));
	printf("%c\n", ft_tolower(lower));

}*/

