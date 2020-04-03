#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ipc.h>

//deklarasi
int (*value)[10];
int hsl = 0;
int matriks_A[10][10], matriks_B[10][10], baris_A=4, kolom_A=2, baris_B=2, kolom_B=5;
pthread_t thread1, thread2, thread3;

//matriks pertama
void *pengisian_matriks_A(void *arg)
{
        matriks_A[0][0]=1;
        matriks_A[0][1]=2;
        matriks_A[1][0]=3;
        matriks_A[1][1]=1;
        matriks_A[2][0]=2;
        matriks_A[2][1]=3;
        matriks_A[3][0]=1;
        matriks_A[3][1]=2;
	return NULL;
}

//matriks kedua
void *pengisian_matriks_B(void *arg)
{
        matriks_B[0][0]=2;
        matriks_B[0][1]=1;
        matriks_B[0][2]=2;
        matriks_B[0][3]=1;
        matriks_B[0][4]=2;
        matriks_B[1][0]=1;
        matriks_B[1][1]=2;
        matriks_B[1][2]=1;
        matriks_B[1][3]=1;
        matriks_B[1][4]=1;
	return NULL;
}

//untuk menghitung perkalian matriks
void *perkalian_matriks(void *arg)
{
	//int core = langkah++;
	for(int i=0;i<baris_A;i++)
	{
		for(int j=0;j<kolom_B;j++)
		{
			for(int k=0;k<kolom_A;k++)
			{
				//lakukan perhitungan perkalian matriks
				hsl+=matriks_A[i][k] * matriks_B[k][j];
			}
            value[i][j]= hsl; //penyimpanan hasil perkalian dalam var value
            hsl =0;
		}
	}
	return NULL;
}

int main()
{
    //shared memory template
	key_t key = 1234;
    int shmid = shmget(key, sizeof(int[10][10]), IPC_CREAT | 0666);
    value = shmat(shmid, 0, 0);

	pthread_create(&thread1, NULL, pengisian_matriks_A, NULL);
	pthread_join(thread1,NULL);

	pthread_create(&thread2, NULL, pengisian_matriks_B, NULL);
	pthread_join(thread2,NULL);

	for(int i=0;i<baris_A;i++){
		for(int j=0;j<kolom_B;j++){
			value[i][j]=0;
		}
		pthread_create(&thread3, NULL, perkalian_matriks, NULL);
		pthread_join(thread3,NULL);
	}
//menampilkan hasil perkalian matriks
	printf("Hasil Perkalian antara matriks A dan B adalah: \n");
	for(int i=0; i<baris_A; i++){
		for(int j=0;j<kolom_B;j++){
			printf("%d\t", value[i][j]); //per elemen diselat tab
		}
		printf("\n");
	}
}