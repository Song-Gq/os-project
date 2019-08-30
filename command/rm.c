#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc == 1) {
		printf("rm: Please enter the filename.\nAborting.\n");
	}

	if (unlink(argv[1]) == 0)
		printf("rm: %s removed.\n", argv[1]);
	else
		printf("rm: Failed to remove %s.\n", argv[1]);

	return 0;
}

