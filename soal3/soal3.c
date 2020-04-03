#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <syslog.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

pthread_t thread[3]; //inisiasi array untuk menampung thread, yang dimana dalam kasus ini terdapat 2 thread
pid_t child_id;
char *array[4],*array2[20], array3[200], huruf[200], curr_dir[200];
int a = 0, b = 0, length = 5; //length = inisialisasi jumlah untuk looping
void* playandcount(void *); //deklarasi fungsi

int main(int argv1, char *argv2[]) {
    
    if(getcwd(curr_dir, sizeof(curr_dir)) != NULL)  //untuk mendapatkan tempat direktori yang sekarang sedang kita pakai
    printf("Direktori sekarang: %s\n", curr_dir);

    int i=0;
    int j=0; 
    //jika  memilih opsi -f
    if (strcmp(argv2[1],"-f")==0) {
        printf("Masuk ke -f\n");
        for(j=2;j<argv1;j++){
            pthread_create(&(thread[i]), NULL, playandcount, argv2[j]);
            pthread_join(thread[i], NULL);
            i++;
        }
   printf("SELESAI\n");
    }

    //jika  memilih opsi -d
    else if (strcmp(argv2[1],"-d") == 0 && argv1 == 3) {
        printf("Masuk ke -d\n");
        char path1[200],path2[200];
        DIR *dir; //pointer yang menunjuk ke direktori
        struct dirent *de;  //membaca file yang terdapat pada direktori
        dir = opendir(argv2[2]); 
        int test = 0, i =0;
        if(dir == NULL) printf("Error!\n");
        else if(!dir) printf("Periksa lagi, apakah direktori tersebut ada?\n");
         // loop ketika sebuah direktori ada file/folder didalamnya
        while( (de=readdir(dir)) )
        {
            if ( !strcmp(de->d_name, ".") || !strcmp(de->d_name, "..") ); 
		//namafile
            printf("%s\n",de->d_name);
            strcpy(path1,argv2[2]); //copy string ke variabel path1
            strcat(path1,"/"); //menyambungkan perargumennya
            strcat(path1,de->d_name); 
            if(de->d_type == 8){
            pthread_create(&(thread[i]),NULL,playandcount,path1); //membuat thread
            pthread_join(thread[i],NULL);
            i++;
            }
        }
         printf("SELESAI\n");
    }
         //jika terdapat opsi yang mengandung tanda bintang pada argumen keduanya (\*)
    else if (strcmp(argv2[1],"*")==0) {
        printf("Masuk ke *\n");
        DIR *dir;
        struct dirent *de; //membaca file yang terdapat pada direktori
        char path1[100],path2[100];
        dir = opendir(curr_dir); //membuka direktori yang sekarang
        int test = 0, i =0;
        if(dir == NULL) printf("Error!\n");
       else if(!dir) printf("Periksa lagi, apakah direktori tersebut ada?\n");
        // loop ketika sebuah direktori ada file/folder didalamnya
        while ((de=readdir(dir)) )
        {
            if ( !strcmp(de->d_name, ".") || !strcmp(de->d_name, ".."));
             //lanjutkan
            printf("%s \n",de->d_name); //nama file
            strcpy(path1,curr_dir); //copy string ke variabel path1
            strcat(path1,"/"); 
            strcat(path1,de->d_name);
            if(de->d_type == 8){
                //membuat thread
            pthread_create(&(thread[i]),NULL,playandcount,path1); 
            pthread_join(thread[i],NULL);
            i++;
            }
        }
    }

    else 
  // Error handling jika tidak ada argumen yang diinput
    {
    printf("Mohon masukkan argumen pada program, berupa -f, *, atau -d\n");
    exit(EXIT_FAILURE);
    } 
}


void* playandcount(void *arg)
{
    //copy string ke variabel huruf
    unsigned long long i=0;
    strcpy(huruf,arg);
    char *tanda, *tanda1;
	pthread_t id = pthread_self(); //mengetahui thread ID
    tanda1 = strtok(huruf, "/"); //memisahkan string dari karakter (huruf) dengan / sebagai titik pemisahan
    while( tanda1 != NULL ) {
        //membaca string
        array2[b] = tanda1; b++;
        tanda1 = strtok(NULL, "/");
    }
    strcpy(array3, array2[b-1]);
    tanda = strtok(array2[b-1], "."); //memisahkan string dari karakter (array) dengan . sebagai titik pemisahan
    while( tanda != NULL ) {
        //membaca string
        array[a] = tanda; a++;
        tanda = strtok(NULL, "."); //memisahkan string dengan . sebagai titik pemisahan
    }

    char abc[100];
    strcpy(abc,array[a-1]);
    for(i = 0; abc[i]; i++) abc[i] = tolower(abc[i]); //convert menjadi lowercase letter

    DIR *fold; //pointer yang menunjuk ke folder/direktori
    struct dirent *de1;
    char place1[100],place2[100];
    fold = opendir(curr_dir); //open direktori saat ini
    int test = 0;
    //printf("a = %d\n", a);
    if(a>1){

        if(fold == NULL) printf("Error!\n");
           else if(!fold)
            printf("Periksa lagi, apakah direktori tersebut ada?\n");
        // loop ketika sebuah direktori ada file/folder didalamnya
        while( (de1=readdir(fold)) )
        { 
            if(strcmp(de1->d_name,abc) == 0 && de1->d_type == 4){
                test = 1;
                break;
            }
        }

        if(test == 0){
            //menyusun direktori lokasi file
            strcpy(place1,curr_dir);
            strcat(place1,"/");
            strcat(place1,abc);
            //memberitahu lokasi file
            printf("Berada di = %s\n%s\n",abc,place1);
            printf("SELESAI\n");
            mkdir(place1, 0777);
        }
    }

    else{
        //apabila file tidak ada ekstensi 
        //memberitahu lokasi file 
        strcpy(place1, curr_dir); //direktori sekarang
        strcat(place1,"/");
        strcat(place1,"Unknown"); 
        printf("Berada di = %s\n%s\n",abc,place1);
        printf("SELESAI\n");
        mkdir(place1, 0777);
    }
	

    char sumber[1024], tujuan[1024];
    //lokasi file
    strcpy(sumber,arg);
    strcpy(tujuan,curr_dir);
    strcat(tujuan,"/");
    //jika tidak ada ekstensi
    if(a== 1) strcat(tujuan,"Unknown");
    //memiliki ekstensi 
    else strcat(tujuan, abc);
    strcat(tujuan,"/");
    strcat(tujuan,array3);
    rename(sumber,tujuan);
    a = 0;
    b = 0;
	return NULL;
}

