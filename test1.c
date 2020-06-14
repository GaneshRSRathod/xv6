#include"user.h"
#include"stat.h"
#include"fcntl.h"
int main(int argc, char *argv[]) {
	int n;
	if(argc < 5) {
		printf(1, "less arguments\n");
		exit();
	}
	n = open(argv[1], O_RDONLY);
	int off, len;
	off = atoi(argv[2]);
	len = atoi(argv[3]);
	lseek(n, off);
	char str[len + 1];
	read(n, str, len);
	if(!strcmp(str, argv[4])) {
		printf(1, "strig matched\n");
	}
	else {
		printf(1, "string not matched\n");
	}
	exit();
}
