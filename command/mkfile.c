#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd;
	
	if(argc == 1) {
		printf("mkfile: Please enter the filename.\nAborting.\n");
		return 0;
	}

	if((sizeof(argv[1]) / sizeof(char) > 2) && argv[1][0] == 'u' && 
		argv[1][1] == 's' && argv[1][2] == 'r') {
		printf("mkfile: 'usr' is not allowed to be the first three characters.\nAborting.\n");
	}

	// create 
	fd = open(argv[1], O_CREAT | O_RDWR);
	if(fd == -1) {
		printf("mkfile: %s already exists.\nAborting.\n", argv[1]);
		return 0;
	}
	printf("mkfile: %s created.\n", argv[1]);

	close(fd);

	return 0;
}

