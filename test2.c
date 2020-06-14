#include"user.h"
#include"stat.h"
#include"fcntl.h"
int main(int argc, char *argv[]) {
	int n;
	if(argc < 2) {
		printf(1, "less arguments\n");
		exit();
	}
	n = open(argv[1], O_RDONLY);
	int off, len;
	len = -1;
	while(!lseek(n, 1)) {
		len++;
	}

	off = len / 9;
	char str[len + 1];
	int i;
	close(n);
	int m;
	m = open("copy", O_CREATE | O_WRONLY);
	n = open(argv[1], O_RDONLY);
	for(i = 0; i < 9; i++) {
		read(n, str, off);
		write(m, str, off);
	}
	off = len % 9;
	read(n, str, off);
	write(m, str, off);
	exit();
}
