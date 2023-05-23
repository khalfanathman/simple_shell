#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

/**
 * reading - performs reading character by character.
 * @buff: The buffer to store the string read from sdtin.
 * @size: The size of buffer.
 * @fd: The file discriptor to be read from
 *
 * Return: returns the number of characters read;
 */
int reading(char *buff, size_t size, int fd)
{
	size_t i = 0;
	ssize_t charsRead, chars = -1;
	char c;

	while (i < size - 1)
	{
		charsRead = read(fd, &c, sizeof(c));

		if (charsRead == 0)
		{
			buff[i] = '\0';
			return (-1);
		}

		if (c == '\n')
		{
			buff[i] = '\n';
			buff[i + 1] = '\0';
			chars++;
			break;
		}

		buff[i] = c;
		i++;
		chars = i;
	}

	if (charsRead == 0)
	{
		return (-1);
	}

	return (chars);
}

/**
 * _realloc - reallocates bufer size to ptr.
 * @ptr: address to be allocated;
 * @size: the current size of buffer;
 *
 * Return: returns a pointer to the new allocated space;
 */

void *_realloc(void *ptr, size_t size)
{
	void *ptrl = malloc(sizeof(ptr));
	/* size_t i = 0; */

	if (ptr == NULL)
	{
		ptr = malloc(size);
	}
	else if (ptr != NULL)
	{
		if (size == 0)
		{
			free(ptr);
			return (NULL);
		}
		else if (size > sizeof(ptr))
		{
			ptrl = malloc(size);
			ptrl = ptr;
			return (ptrl);
		}

	}
	return (ptr);
}
/**
 * reallocate - reallocates bufer for str if its not enough.
 * @rd_ch: it saves no of charcter read;
 * @sz: the current size of buffer;
 * @buf: the pointer to the  addr for th string to be stored.
 * @fd: The stream to be read from.
 * @lnp: The pointer to buffer where the str will be stored.
 * @n: The size of buffer  to renew.
 *
 * Return: returns the number of chars read from stdin n -ve if error;
 */
int reallocate(int rd_ch, size_t sz, char *buf, int *fd, char **lnp, size_t *n)
{
	if (errno == ENOMEM)
	{
		sz = (sz * 2) + 2;
		/* realloc should be replaced with manual one */
		buf = _realloc(buf, sizeof(char) * sz);
		if (buf == NULL)
		{
			perror("realloc()");
			exit(errno);
		}
		rd_ch = reading(buf, sz, *fd);
		if (rd_ch == -1)
		{
			perror("read(2)");
			return (rd_ch);
		}
		*lnp = buf;
		*n = sz;
		return (rd_ch);
	}
	return (rd_ch);
}
/**
 * _getline - reads string from stdin.
 * @lineptr: The pointer to buffer where the str will be stored.
 * @n: The size of buffer.
 * @strem: The stream to be read from.
 *
 * Return: returns the number of chars read from stdin n -ve if error;
 */
int _getline(char **lineptr, size_t *n, FILE *strem)
{
	static char *buff;
	static size_t size;
	int read_chars = -1;
	int *fd = (int *) strem;

	buff = *lineptr;
	size = *n;
	if (isatty(STDIN_FILENO))
	{
		*fd = open("/dev/tty", O_RDONLY, S_IRWXU);
	}
	if (buff == NULL || size == 0)
	{
		size = 120;
		buff = malloc(sizeof(char) * size);
		if (buff == NULL)
		{
			perror("malloc()");
			return (read_chars);
		}
		read_chars = reading(buff, size, *fd);
		if (read_chars == -1)
		{
			*lineptr = buff;
			*n = size;
			return (read_chars);
		}
		*lineptr = buff;
		*n = size;
		return (read_chars);
	}
	else
	{
		read_chars = reading(buff, size, *fd);
		read_chars = reallocate(read_chars, size, buff,  fd,  lineptr, n);
		return (read_chars);
	}
}
