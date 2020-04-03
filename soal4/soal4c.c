#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/wait.h> 
#include<string.h> 
#include<sys/types.h> 

int main() 
{ 
	int pipe1[2], pipe2[2]; 
    // Used to store two ends of first pipe and Used to store two ends of second pipe 
	pid_t p1;
	if (pipe(pipe1)==-1) //nilai failure
	{ 
		fprintf(stderr, "Pipe Gagal" ); 
		return 1; 
	} 
	if (pipe(pipe2)==-1)  //nilai failure
	{ 
		fprintf(stderr, "Pipe Gagal" ); 
		return 1; 
	} 
	p1=fork();
	if (p1< 0) 
	{ 
		fprintf(stderr, "Fork Gagal" ); //tidak dapat dibentuk
		return 1; 
	}  

    //parent
    else if (p1 > 0) {

        close(pipe2[0]);
        close(pipe2[1]);
		// 0 = input, 1 = write
        dup2(pipe1[0], 0); 
		//baca isi dr pipe1 untuk dieksekusi
        dup2(pipe2[1], 1); // output ke pipe2

        close(pipe1[0]);
        close(pipe1[1]);
//mengetahui jumlah file dan folder di direktori saat ini
        char *arg1[] = {"wc", "-l", NULL};
        execvp("/usr/bin/wc", arg1);
		exit(0);
        }

	else 
	{ 
		//jika fork()==0
        dup2(pipe1[1], 1);
        close(pipe1[0]);
        close(pipe1[1]);
        char *arg2[] = {"ls", NULL};
        execvp("/bin/ls", arg2);
	} 
} 