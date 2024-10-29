#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	char buf[100];
	int n = read(fd, buf, 100);
	if (n < 0)
	{
		perror("read");
		return 1;
	}

	buf[n] = '\0';
	printf("Read: %s\n", buf);

	close(fd);
	return 0;
}
