 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 #include<sys/types.h>
 #include<sys/wait.h>
 #include<sys/param.h>
 #include<wait.h>
 #include<sys/stat.h>
 #include<time.h>
 #include<signal.h>
 #include<string.h>
 #include<errno.h>
 #include<fcntl.h>
 #include<pthread.h>
 #include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 #define check_error(return_val,msg){\
		if(return_val != 0){\
			fprintf(stderr,"%s:%s",msg,strerror(return_val));\
			exit(-1);\
		}\
	 }
