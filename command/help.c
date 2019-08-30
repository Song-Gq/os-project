#include "stdio.h"

int main(int argc, char * argv[])
{
	printf("echo [arg]             Print arg\n"
		"pwd                    Show current directory\n"
		"ls                     List files and folders in directory\n"
		"mkfile [file name]     Create a file\n"
		"rm [name]              Remove a file or directory\n"
		"show [file name]       Show content of a file\n"
		"edit [file name]       Edit a file\n");

	return 0;
}
