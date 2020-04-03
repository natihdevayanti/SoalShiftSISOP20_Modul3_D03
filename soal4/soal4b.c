#include <stdio.h>
#include <sys/shm.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <unistd.h>

//deklarasi 
unsigned long long angka;
int row=4, column=5;

//untuk menghitung faktorial tambah
unsigned long long factorial(unsigned long long a){
    if(a==0 || a==1) return 1;
    else return a+ factorial(a-1); //pemanggilan fungsi factorial
}

//fungsi factorial
void *faktorial(void *arg)
{
	//template shared memory
        key_t key = 1234;
        int (*value)[10];
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, 0, 0);
    	printf("Hasil Faktorial Pertambahan Matriks tersebut adalah: \n");
	    for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			//faktorial dihitung per elemen matriks hasil perkalian
            angka=value[i][j];
			printf("%llu\t", factorial(angka)); //pemanggilan fungsi factorial untuk menghitung 
		}
		printf("\n");
	}
    pthread_exit(0);
}

void main()
{
    	pthread_t thread;
    //shared memory template
        key_t key = 1234;
        int (*value)[10];
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, 0, 0);

	    printf("Hasil Perkalian antara matriks A dan B adalah: \n");
		//menampilkan hasil perkalian matriks pada soal 4a
	    for(int i=0;i< 4;i++){
		for(int j=0;j<5;j++){
			printf("%d\t", value[i][j]);
		}
		printf("\n");
	}
	pthread_create(&thread, NULL, faktorial, NULL);
	pthread_join(thread,NULL);
}

