#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define EXIT 0
#define CREATE_FILE 1
#define WRITE_FILE 2
#define READ_FILE 3
#define STAT_FILE 4
#define CHMOD_FILE 5

int CreateFile(char * filename);
int WriteFile(char * filename,char * buf);
char* ReadFile(char * filename);
struct stat StatFile(char *filename);
int ChmodFile(char *filename,unsigned int mode);
void showMenu();














