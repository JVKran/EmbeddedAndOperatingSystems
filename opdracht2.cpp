#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

using std::cin;

int main(){
	int increment;
	cin >> increment;
	int fd = open("infile.txt", O_RDONLY | O_CREAT | O_TRUNC, 0644);
	int fd1 = open("outfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0){
		perror(" r1");
		exit(1);
	}
	int i = 0;
	int sz;
	char *c = (char *) calloc(100, sizeof(char));
	while(true){
		char curChar = read(fd, c, 10);
		const char* constCurChar = &curChar;
		sz = write(fd1, constCurChar, strlen(constCurChar));
		if(i + increment < 9){
			i+=increment;
		} else {
			i = i + increment - 9;
		}
		if(i == 4){
			break;
		}
	}
	close(fd);
	close(fd1);
}
