#include "stdio.h"
#include "string.h"

int main(int argc, char * argv[])
{
	int fd;
	
	if(argc != 1) {
		printf("mkdir: Arguments not allowed.\nAborting.\n");
		return 0;
	}
	
	// create 
	char name[5] = "usr0\0";
	do {
		name[3]++;
		printf("%s", name);
		fd = open(name, O_CREAT | O_RDWR);
	}
	while(name[3] < '9' && fd == -1);

	if(fd == -1) {
		printf("mkdir: Too much folder.\nAborting.\n");
		return 0;
	}
	printf("mkdir: %s created.\n", name);

	close(fd);

	return 0;
}

