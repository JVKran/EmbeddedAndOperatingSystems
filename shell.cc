#include "shell.hh"
#include <string>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

using std::string;
using std::cout;
using std::getline;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::cin;

string prompt;
int argCounter;
char args;

void getPrompt(){
    ifstream file ("config.txt", ifstream::binary);
    if(file){
        file.seekg (0, file.end);
        int length = file.tellg();
        length-=2;
        file.seekg(0, file.beg);
        char * buffer = new char [length];
        file.read(buffer, length);
        file.close();
        prompt = buffer;
        delete[] buffer;
        cout << prompt;
    }
}

int main(){
    static bool initialized;
    string input;
    if(!initialized){
        getPrompt();
        initialized = true;
    }
    while(true){
        getline(std::cin, input);
        if (input == "new_file") new_file();
        if (input == "ls") list();
        if (input == "find") find();
        if (input == "python") python();
        if (input == "quit") return 0;
        if (input == "error") return 1;
    }
}

void new_file() {
	cout << "Filename: ";
	string file;
	getline(cin, file);
	const char* filename = file.c_str();
	cout << "Content: ";
	string con;
	getline(cin, con);
	const char* content = con.c_str();
	int sz;
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0){
		perror(" r1");
		exit(1);
	}
	sz = write(fd, content, strlen(content));
	close(fd);
	cout << prompt;
}

void list(){
    int pid = fork();
    if(pid == 0){
	char *args[] = {(char*) "/bin/ls", (char*) "-la", (char*) 0};
        execv("/bin/ls",args);
    } else {
        int exit_status;
        wait(&exit_status);
    }
    cout << prompt;
}

void find(){
    int pid = fork();
    if(pid == 0){
	char *args[] = {(char*) "/usr/bin/find", (char*) ".", (char*) 0};
        execv("/usr/bin/find",args);
    } else {
        int exit_status;
        wait(&exit_status);
    }
   cout << prompt;
}

void python(){
    int pid = fork();
    if(pid == 0){
	char *args[] = {(char*) "/usr/bin/python", (char*) 0};
        execv("/usr/bin/python",args);
    } else {
        int exit_status;
        wait(&exit_status);
    }
   cout << prompt;
}
