#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

int putchar(int ic) {
#if defined(__is_libk)
	char c = (char) ic;
	terminal_write(&c, sizeof(c));
#else
	return write(STDOUT_FILENO, &ic, 1) == 1 ? ic : EOF;
#endif
	return ic;
}
