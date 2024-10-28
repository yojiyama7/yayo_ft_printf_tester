#include "libftprintf.h"
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 10000
#include "__utils.h"

int	main(void)
{
	const size_t	too_long_size = (size_t)INT_MAX / 100;
	char			*too_long;

	// printf("[c]");
	TEST("%c", 'a');
	TEST("%c", '~');
	TEST("%c", 128);
	TEST("%c", 200);
	TEST("%c", 255);
	TEST("%c", 500);
	TEST("%c", '\0');
	// printf("[s]");
	TEST("%s", "");
	TEST("%s", "abcde");
	TEST("%s", "pef%few");
	TEST("%s", "12345678||\\z~!@#^&*()");
	TEST("%s", ".>..<");
	too_long = malloc(too_long_size);
	for (size_t i = 0; i < too_long_size - 1; i++)
	{
		too_long[i] = 'a';
	}
	too_long[too_long_size - 1] = '\0';
	TEST(too_long);
	free(too_long);
	TEST("%s", (char *)NULL);
	// printf("[p]");
	TEST("%p", "xxxxxxxxxxxxxx");
	TEST("%p", NULL);
	TEST("%p", "fwe");
	// printf("[d]");
	TEST("%d", INT_MIN);
	TEST("%d", INT_MIN + 1);
	TEST("%d", -101);
	TEST("%d", -100);
	TEST("%d", -99);
	TEST("%d", -42);
	TEST("%d", -2);
	TEST("%d", -1);
	TEST("%d", 0);
	TEST("%d", 1);
	TEST("%d", 2);
	TEST("%d", 42);
	TEST("%d", 99);
	TEST("%d", 100);
	TEST("%d", 101);
	TEST("%d", INT_MAX - 1);
	TEST("%d", INT_MAX);
	// printf("[i]");
	TEST("%i", INT_MIN);
	TEST("%i", INT_MIN + 1);
	TEST("%i", -101);
	TEST("%i", -100);
	TEST("%i", -99);
	TEST("%i", -42);
	TEST("%i", -2);
	TEST("%i", -1);
	TEST("%i", 0);
	TEST("%i", 1);
	TEST("%i", 2);
	TEST("%i", 42);
	TEST("%i", 99);
	TEST("%i", 100);
	TEST("%i", 101);
	TEST("%i", INT_MAX - 1);
	TEST("%i", INT_MAX);
	// printf("[u]");
	TEST("%u", 0);
	TEST("%u", 1);
	TEST("%u", 2);
	TEST("%u", 42);
	TEST("%u", 99);
	TEST("%u", 100);
	TEST("%u", 101);
	TEST("%u", INT_MAX - 1);
	TEST("%u", INT_MAX);
	TEST("%u", UINT_MAX - 1);
	TEST("%u", UINT_MAX);
	// printf("[x]");
	TEST("%x", 0);
	TEST("%x", 1);
	TEST("%x", 2);
	TEST("%x", 42);
	TEST("%x", 99);
	TEST("%x", 100);
	TEST("%x", 101);
	TEST("%x", INT_MAX - 1);
	TEST("%x", INT_MAX);
	TEST("%x", UINT_MAX - 1);
	TEST("%x", UINT_MAX);
	// printf("[X]");
	TEST("%X", 0);
	TEST("%X", 1);
	TEST("%X", 2);
	TEST("%X", 42);
	TEST("%X", 99);
	TEST("%X", 100);
	TEST("%X", 101);
	TEST("%X", INT_MAX - 1);
	TEST("%X", INT_MAX);
	TEST("%X", UINT_MAX - 1);
	TEST("%X", UINT_MAX);
	// printf("[%]");
	TEST("%%", UINT_MAX);
	// printf("[mixing]");
	TEST("%c %s %p %d %i %u %x %X %%", 'a', "abc", "asef", 3423, 42, 3023, 15,
		31);
	TEST("%% %X %x %u %i %d %p %s %c", 31, 15, 432, -432, -12345, "asef", "abc",
		'a');
	TEST("  abc  def   %x  %i", 2123043, -3242);
}
