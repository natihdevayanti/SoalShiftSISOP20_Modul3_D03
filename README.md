# SoalShiftSISOP20_Modul3_D03


Dibuat oleh:

Kelompok D03

Putu Putri Natih Devayanti (05111840000163)

Elvira Catrine Natalie (05111840000016)


## SOAL 1

### Poke*ZONE, game berbasis text terminal mirip dengan Pokemon GO.

- Untuk mendapatkan variabel-variabelnya, maka kita menggunakan struct. Struct ini ialah untuk pokemon, gamedata, dan juga shop. 

**a

**b

**c

**d


> Kendala

- Kurang memahami syntax yang dipakai

- Belum sempat memahami secara detail maksud dari soal terkait

> Materi

** Struct

Structure atau struct adalah kumpulan dari beberapa variabel dengan beragam tipe data yang dibungkus dalam satu varabel. Agar struct dapat digunakan, kita harus membuat variabel untuknya.

Contoh:

```
struct Mahasiswa
{
    char name[50];
    char address[50];
    int age;
};

```

** Thread

Thread merupakan unit terkecil dalam suatu proses yang dapat dijadwalkan oleh sistem operasi. Thread biasanya terbentuk oleh fork yang berjalan pada suatu script atau program untuk sebuah proses. Minimal terdapat sebuah thread yang berjalan dalam suatu proses, walau biasanya terdapat lebih dari satu thread dalam proses tersebut. Thread akan berbagi memori dan menggunakan informasi (nilai) dari variabel-variabel pada suatu proses tersebut. Penggambaran thread pada sebuah proses dapat dilihat sebagai berikut.



## SOAL 2

### TapTap Game


**Tapserver


**Tapplayer


> Kendala

- Kurang memahami syntax yang dipakai

- Belum sempat memahami secara detail maksud dari soal terkait


> Materi

** Thread

Thread merupakan unit terkecil dalam suatu proses yang dapat dijadwalkan oleh sistem operasi. Thread biasanya terbentuk oleh fork yang berjalan pada suatu script atau program untuk sebuah proses. Minimal terdapat sebuah thread yang berjalan dalam suatu proses, walau biasanya terdapat lebih dari satu thread dalam proses tersebut. Thread akan berbagi memori dan menggunakan informasi (nilai) dari variabel-variabel pada suatu proses tersebut. Penggambaran thread pada sebuah proses dapat dilihat sebagai berikut.

** Socket

Socket merupakan sebuah end-point dalam sebuah proses yang saling berkomunikasi. Biasanya socket digunakan untuk komunikasi antar proses pada komputer yang berbeda, namun dapat juga digunakan dalam komputer yang sama.


## SOAL 3

### Kategori File




## SOAL 4

### Matriks 

**a
Program untuk melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks nantinya akan berisi angka 1-20

> Langkah dan Penjelasan


- Berikut adalah pengisian matriks pertama (isinya bebas)

- Elemen matriks ditulis satu persatu

```

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

```

- Berikut adalah pengisian matriks kedua (isinya bebas)

```

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

````

- Dibuat thread sebanyak pengisian matriks. Masing - masing thread di join

```

pthread_create(&thread1, NULL, pengisian_matriks_A, NULL);
	pthread_join(thread1,NULL);

	pthread_create(&thread2, NULL, pengisian_matriks_B, NULL);
	pthread_join(thread2,NULL);

```

- Template shared memory

```

	key_t key = 1234;
    int shmid = shmget(key, sizeof(int[10][10]), IPC_CREAT | 0666);
    value = shmat(shmid, 0, 0);

```

- Dibuat thread sebanyak jumlah perkalian matriks

```
	for(int i=0;i<baris_A;i++){
		for(int j=0;j<kolom_B;j++){
			value[i][j]=0;
		}
		pthread_create(&thread3, NULL, perkalian_matriks, NULL);
		pthread_join(thread3,NULL);
	}

```

- Fungsi perkalian matriks

```
void *perkalian_matriks(void *arg)
{
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

```

`hsl+=matriks_A[i][k] * matriks_B[k][j];` merupakan operasi perkalian matriks

- Menampilkan hasil perkalian matriks

```
printf("Hasil Perkalian antara matriks A dan B adalah: \n");
	for(int i=0; i<baris_A; i++){
		for(int j=0;j<kolom_B;j++){
			printf("%d\t", value[i][j]); //per elemen diselat tab
		}
		printf("\n");
	}
  
 ```


**b 
Carilah nilai faktorial pertambahan per-elemen hasil perkalian matriks tersebut

- Template shared memory

```

        key_t key = 1234;
        int (*value)[10];
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, 0, 0);
        
        ```
        
- Menampilkan hasil perkalian matriks pada soal 4a

```

 printf("Hasil Perkalian antara matriks A dan B adalah: \n");
		//menampilkan hasil perkalian matriks pada soal 4a
	    for(int i=0;i< 4;i++){
		for(int j=0;j<5;j++){
			printf("%d\t", value[i][j]);
		}
		printf("\n");
	}
  
  ```
  
- Dibuat thread untuk faktorial. Thread dapat di join

```

	pthread_create(&thread, NULL, faktorial, NULL);
	pthread_join(thread,NULL);
  
  ```

- Fungsi untuk menampilkan faktorial pertambahan per elemen matriks hasil perkalian

```

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

```

- Fungsi rekursif untuk menghitung faktorial

```

unsigned long long factorial(unsigned long long a){
    if(a==0 || a==1) return 1;
    else return a+ factorial(a-1); //pemanggilan fungsi factorial
}

````

Melalui syntax `printf("%llu\t", factorial(angka));`, nantinya akan dicetak faktorial pertambahan per elemen matriks hasil perkalian tersebut.

**c


-
int main()
{
int stts;
pid_t child_id;
child_id = fork();
if (child_id < 0)
{
exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
}

if (child_id == 0)
{
// this is child
    pid_t child_id1;
	child_id1 = fork();
    if(child_id1 < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (child_id1 == 0)
    {
        char *arg[] = {"mkdir", "-p", "/home/elvira/modul2/indomie", NULL};
        execv("/bin/mkdir", arg);
    }
    else
    {
        while ((wait(&stts)) > 0);    
        sleep (5);  
        char *arg[] = {"mkdir", "-p", "/home/elvira/modul2/sedaap", NULL};
        execv("/bin/mkdir", arg);
    }
}

```

- `pid_t child_id; dan child_id = fork();` merupakan bagian untuk membuat fork agar bisa menjalankan banyak proses dalam sekali jalan

- `if  (child_id  <  0)  exit(EXIT_FAILURE);`	menunjukkan bahwa jika gagal dalam membuat proses baru, program akan berhenti

- Gunakan fungsi fork() terlebih dahulu untuk membuat direktori pertama (indomie). Membuat direktori menggunakan mkdir –p jika merupakan child process, lalu gunakan perintah execv() untuk menjalankan program.

- `char *arg[] = {"mkdir", "-p", "/home/elvira/modul2/indomie", NULL};` adalah bagian untuk membuat direktori, "-p" adalah untuk membuat parent direktori nya

- `while ((wait(&stts)) > 0);` bagian ini untuk delay suatu proses.

- Direktori kedua yaitu “sedaap” dibuat lima detik kemudian setelah direktori “indomie” dibuat. Maka kita menggunakan perintah `sleep(5)`;


### 3b

Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.

> Langkah dan Penjelasan

Code

```

else
{
    while ((wait(&stts)) > 0);

    pid_t child_id2;
	child_id2 = fork();

    if (child_id2 < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (child_id2 == 0)
    {
        char *arg[] = {"unzip", "-oq", "/home/elvira/modul2/jpg.zip", NULL};

        execv("/usr/bin/unzip", arg);
    }

```

- Gunakan fungsi fork() untuk unzip file. Gunakan perintah unzip() jika merupakan child process, lalu jalankan program menggunakan perintah execv()

- `pid_t child_id2 = fork();` adalah bagian untuk membuat fork agar bisa menjalankan banyak proses dalam sekali jalan

- `if  (child_id  <  0)  exit(EXIT_FAILURE);` menunjukkan bahwa jika gagal dalam membuat proses baru, program akan berhenti

- `while ((wait(&stts)) > 0);` bagian ini untuk delay suatu proses.


### 3c

Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.

> Langkah dan Penjelasan

Code

```

 else 
      {
        while ((wait(&stts)) > 0);
        DIR *d;
        struct dirent *dr; 
        d = opendir("jpg");
	struct stat st;
        if (d)
        {
          while ((dr = readdir(d)) != NULL)
          {
            pid_t child_id3;
	    child_id3 = fork ();
            if (child_id3 < 0) 
            {
              exit(EXIT_FAILURE); 
            }
            if (child_id3 == 0)
            {
              char file_name[20000];
              sprintf(file_name, "/home/elvira/modul2/jpg/%s", dr->d_name);

              if (stat(file_name, &st)) 
              {
                exit (EXIT_FAILURE);
              }
              if (strcmp(dr->d_name, "..")== 0 || strcmp(dr->d_name, ".")== 0);

              else if(dr->d_type == DT_REG)
              {
                char* arggg[] = {"mv", file_name, "/home/elvira/modul2/sedaap/", NULL};
                execv("/bin/mv", arggg);
              }
              else 
              {
                pid_t child_id4;
		child_id4 = fork ();
                if (child_id4 < 0) 
                {
                  exit(EXIT_FAILURE); 
                }
                if(child_id4 == 0)
                {
                  char* arggg[] = {"mv", file_name, "/home/elvira/modul2/indomie/", NULL};
                  execv("/bin/mv", arggg);
                }

```

- Struct dirent *dr adalah struct yang berfungsi untuk membaca file yang terdapat pada direktori

- `DIR *d;` adalag pointer untuk menunjuk ke direktori

- `d = opendir("jpg");` adalah bagian untuk membuka direktori jpg

- `struct stat st;` adalah pointer status dalam proses mengecek sebuah direktori

- `if(d)` adalah bagian untuk mengecek pointer yang ditunjuk adalah benar sebuah direktori.

- `while((dr = readdir(d)) != NULL)` bagian ini loop ketika sebuah direktori masih ada file/folder didalamnya

- `char file_name[20000];` untuk menyimpan hasil pencarian
 
- `sprintf(file_name, "/home/elvira/modul2/jpg/%s", dr->d_name);` untuk mencari file/folder yang ada dalam direktori

- Direktori tidak termasuk (proses berkelanjutan) jika direktori berupa . dan .., maka harus menggunakan strcmp() untuk membandingkan dengan dr.

- Jika tipe dr merupakan direktori, gunakan fungsi snprintf() untuk memformat dan menyimpan nama hasil ekstrak bertipe direktori yang akan disimpan pada direktori indomie dalam buffer array.

- Gunakan fungsi fork() terlebih dahulu lalu gunakan mv untuk memindahkan nama hasil ekstrak bertipe direktori ke direktori indomie.

- Jika tipe dr merupakan file, gunakan fungsi snprintf() untuk memformat dan menyimpan nama hasil ekstrak ber tipe file yang akan disimpan pada direktori sedaap dalam buffer array (code ada di 3c).

- Gunakan fungsi fork() terlebih dahulu lalu gunakan mv untuk memindahkan nama hasil esktrak yang bertipe file ke direktori sedaap.


### 3d

Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).

```
              else 
                {
                  while ((wait(&stts)) > 0);
                  pid_t child_id5;
		  child_id5 = fork ();
                  if (child_id5 < 0) 
                  {
                    exit(EXIT_FAILURE); 
                  }
                  if(child_id5 == 0)
                  {
                    char destination_file[20000];
                     FILE *target;
	              sprintf(destination_file, "/home/elvira/modul2/indomie/%s/coba1.txt", dr->d_name);
                      target = fopen(destination_file,"w");
                      fclose(target);
                    
                  }
                  else 
                  {
                    while ((wait(&stts)) > 0);
                    sleep(3);
                    char destination_file[20000];
  		      FILE *target;
	              sprintf(destination_file, "/home/elvira/modul2/indomie/%s/coba2.txt", dr->d_name);
	              target = fopen(destination_file,"w");
	              fclose(target);
		      exit(0);

                  }
                }
              }
            }
          }
          closedir(d);

        }
      }
    }
  }

```

- Terdapat dua file kosong yang akan dibuat yaitu file coba1.txt dan coba2.txt jika dr bertipe direktori

- `FILE *target;` adalah pointer untuk menunjuk sebuah file/folder

- `target = fopen(destination_file,"w");` adalah untuk membuka file/folder kemudian memberikan perintah untuk membuat file "coba1.txt" atau "coba2.txt"pada direktori

- Gunakan fungsi snprintf() untuk memformat dan menyimpan coba1.txt yang akan disimpan pada direktori dalam buffer array.

- Membuat file coba1.txt lalu gunakan perintah execv() untuk eksekusi

- File coba2.txt dibuat tiga detik kemudian setelah file coba1.txt dibuat, maka gunakan perintah sleep(3)

- Gunakan fungsi snprintf() untuk memformat dan menyimpan file coba2.txt yang akan disimpan pada direktori dalam buffer array.

- Membuat file coba2.txt lalu gunakan perintah execv() untuk eksekusi

- `fclose(target); exit(0);` adalah untuk mengakhiri proses dalam membuat file dalam direktori


**TERIMA KASIH**
