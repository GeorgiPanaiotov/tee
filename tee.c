#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_COUNT 20
char *buffer[MAX_COUNT];

int main(int argc, char *argv[]) {
	ssize_t br;
	ssize_t bw;
	ssize_t tbw;

	int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (fd == -1) {
		perror("Unable to open file");
		exit(EXIT_FAILURE);
	}

	while((br = read(STDIN_FILENO, buffer, MAX_COUNT)) > 0) {
		bw = write(fd, buffer, br);
		tbw = write(STDOUT_FILENO, buffer, br);

		if (bw != br || tbw != br) {
			perror("Unable to write");
			close(fd);
			exit(EXIT_FAILURE);
		}		
	}

	if (br == -1) {
		perror("Unable to read file");
		close(fd);
		exit(EXIT_FAILURE);
	}

	close(fd);
	exit(EXIT_SUCCESS);
}
