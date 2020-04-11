# SoalShiftSISOP20_Modul3_D03


Dibuat oleh:

Kelompok D03

Putu Putri Natih Devayanti (05111840000163)

Elvira Catrine Natalie (05111840000016)


## SOAL 1

### Poke*ZONE, game berbasis text terminal mirip dengan Pokemon GO.

- Untuk mendapatkan variabel-variabelnya, maka kita menggunakan struct. Struct ini ialah untuk pokemon, gamedata, dan juga shop. 


**a**
Menggunakan IPC-shared memory, thread, fork-exec.

**b**
Bebas berkreasi dengan game ini asal tidak konflik dengan
requirements yang ada. (Contoh: memberi nama trainer, memberi notifikasi
kalau barang di shop sudah penuh, dan lain-lain).

**c**
Terdapat 2 code yaitu soal2_traizone.c dan soal2_pokezone.c.


**d**
soal2_traizone.c mengandung beberapa fitur yang tertera dalam soal shift.


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

- Soal

```
Qiqi adalah sahabat MamMam dan Kaka. Qiqi , Kaka dan MamMam sangat senang
bermain “Rainbow six” bersama-sama , akan tetapi MamMam sangat Toxic ia selalu
melakukan Team killing kepada Qiqi di setiap permainannya. Karena Qiqi orang yang
baik hati, meskipun marah Qiqi selalu berkata “Aku nggk marah!!”. Kaka ingin
meredam kemarahan Qiqi dengan membuatkannya sebuah game yaitu TapTap
Game. akan tetapi Kaka tidak bisa membuatnya sendiri, ia butuh bantuan mu. Ayo!!
Bantu Kaka menenangkan Qiqi.

TapTap Game adalah game online berbasis text console. Terdapat 2 program yaitu
tapserver.c dan tapplayer.c

Syarat :
- Menggunakan Socket, dan Thread
Hint :
- fwrite, fread

Spesifikasi Game :

                                  CLIENT SIDE

Screen 1 :
  1. Login
  2. Register
     Choices : {your input}
     
  ★ Pada screen 1 kalian dapat menginputkan “login”, setelah menekan enter
    anda diminta untuk menginputkan username dan password seperti berikut

Screen 1 :
  1. Login
  2. Register
     Choices : login
     Username : { ex : qiqi }
     Password : { ex : aku nggak marah!! }
     
  ★ Jika login berhasil maka akan menampilkan pesan “login success”, jika gagal
    akan menampilkan pesan “login failed” (pengecekan login hanya mengecek
    username dan password, maka dapat multi autentikasi dengan username dan
    password yang sama)
  ★ Pada screen 1 kalian juga dapat menginputkan “register”, setelah menekan
    enter anda diminta untuk menginputkan username dan password sama
    halnya seperti login
  ★ Pada register tidak ada pengecekan unique username, maka setelah register
    akan langsung menampilkan pesan “register success” dan dapat terjadi
    double account
  ★ Setelah login berhasil maka anda berpindah ke screen 2 dimana
    menampilkan 2 fitur seperti berikut.
    
Screen 2 :
  1. Find Match
  2. Logout
     Choices : {your input}
  
  ★ Pada screen 2 anda dapat menginputkan “logout” setelah logout anda akan
    kembali ke screen 1
  ★ Pada screen 2 anda dapat menginputkan “find”, setelah itu akan
    menampilkan pesan “Waiting for player ...” print terus sampai menemukan
    lawan
  ★ Jika menemukan lawan maka akan menampilkan pesan “Game dimulai
    silahkan tap tap secepat mungkin !!”
  ★ Pada saat game dimulai diberikan variable health = 100,dan anda dapat
    men- tap (menekan space pada keyboard tanpa harus menekan enter)
  ★ Pada saat anda men- tap maka akan menampilkan pesan “hit !!”, dan pada
    lawan healthnya akan berkurang sebanyak 10 kemudian pada lawan
    menampilkan pesan status healthnya sekarang. (conclusion : anda tidak bisa
    melihat status health lawan)
  ★ Jika health anda <= 0 maka akan menampilkan pesan “Game berakhir kamu
    kalah”, apabila lawan anda healthnya <= 0 maka akan menampilkan pesan
    ”Game berakhir kamu menang”
  ★ Setelah menang atau kalah maka akan kembali ke screen 2

                                  SERVER SIDE
                                                      
  ★ Pada saat program pertama kali dijalankan maka program akan membuat file
    akun.txt jika file tersebut tidak ada. File tersebut digunakan untuk menyimpan
    username dan password
  ★ Pada saat user berhasil login maka akan menampilkan pesan “Auth success” jika
    gagal “Auth Failed”
  ★ Pada saat user sukses meregister maka akan menampilkan List account yang
    terdaftar (username dan password harus terlihat)

```

### Pemahaman Praktikan

**Server**

- Membuat struct untuk connect

```
struct Connect
{
	FILE *file;
	struct Database *db;
};

```

- Membuat struct akun

```
struct Akun
{
	int id;
	int set;
	char username[1024];
	char pass[1024];
};
```

- Membuat struct databse

```
struct Database
{
	struct Akun baris[10];
};
```

- Membuat fungsi void untuk deliver message

```
void Err(char *message){
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}
```
- Membuat fungsi pengecekan eksistensi file

```
int cfileexists(const char * filename){
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}
```

- Membuat fungsi Dbwrite untuk connect dan sebagai error handling database

```
void DbWrite(struct Connect *connect)
{
	rewind(connect->file);
	int datamasuk = fwrite(connect->db , sizeof(struct Database), 1, connect->file);
	if(datamasuk !=1) Err("Gagal mengisi database");
	datamasuk = fflush(connect->file);
	if(datamasuk<0) Err("Gagal flush database");
}
```

- Membuat struct untuk open database 

- Membuat fungsi untuk register akun

- Membuat fungsi log in

- Membuat list acc

- Membuat database close

- Membuat socket

- Membuat template untuk server di main

```
	int server_fd, socket_n, opt=1;
	struct sockaddr_in address;
	int addrlen=sizeof(address);

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
	perror("setsockopt");
	exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );		
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0) {
	perror("listen");
	exit(EXIT_FAILURE);
	}

```


**Program belum bisa diselesaikan oleh penulis**



**Client**

- Membuat template client

```
	struct sockaddr_in address;
	int sock=0, baca;

	struct sockaddr_in serv_addr;
	char buff[1024] = {0};
	if((sock=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{
		printf("\nConnection Failed \n");
		return -1;
	}

```

- Membuat looping (while(1)) untuk program berikut

```
		if(gamemulai==0)
		{
			printf("1. Login Akun \n2. Create Akun\nPilih (dalam angka): ");
			char pilih[10];
			scanf("%s", pilih);
			send(sock, pilih, strlen(pilih), 0);
```

- Jika memilih 1, maka akan muncul tampilan menu untuk log in

```
if(strcmp(choose, "1") == 0)
			{
				char your_account[50];
				printf("Username : ");
				scanf("%s", your_account);
				getchar();

				send(sock, your_account, strlen(your_account), 0);
									
				memset(your_account, 0, sizeof(your_account));
				printf("Password : ");
				gets(your_account);
				send(sock, your_account, strlen(your_account), 0);

				int kode = -1;
				baca = recv(sock, &kode, sizeof(kode), 0);
				if(kode==202)
				{
					printf("Login Berhasil\n");
					starting = 1;
					pthread_t thread_id;
				}
				else
				{
					printf("Login Gagal\n");
				}
			}				
```

- Jika memilih 2, maka muncul tampilan untuk sign up

```
		if(strcmp(choose, "2") == 0)
			{
				char your_account[50];
				printf("Username : ");
				scanf("%s", your_account);
				getchar();

				send(sock, your_account, strlen(your_account), 0);
									
				memset(your_account, 0, sizeof(your_account));
				printf("Password : ");
				gets(your_account);
				send(sock, your_account, strlen(your_account), 0);

				printf("Register Telah Sukses\n");
			}		
```

- Memset

```
		memset(choose, 0, sizeof(choose));
```


> Kendala

- Kurang memahami syntax yang dipakai

- Belum sempat memahami secara detail maksud dari soal terkait

- Masih menyusun fungsi-fungsi yang dibentuk dan belum selesai 

- WFH membuat praktikan susah untuk melakukan komunikasi/diskusi bersama


> Materi

** Thread

Thread merupakan unit terkecil dalam suatu proses yang dapat dijadwalkan oleh sistem operasi. Thread biasanya terbentuk oleh fork yang berjalan pada suatu script atau program untuk sebuah proses. Minimal terdapat sebuah thread yang berjalan dalam suatu proses, walau biasanya terdapat lebih dari satu thread dalam proses tersebut. Thread akan berbagi memori dan menggunakan informasi (nilai) dari variabel-variabel pada suatu proses tersebut. Penggambaran thread pada sebuah proses dapat dilihat sebagai berikut.

** Socket

Socket merupakan sebuah end-point dalam sebuah proses yang saling berkomunikasi. Biasanya socket digunakan untuk komunikasi antar proses pada komputer yang berbeda, namun dapat juga digunakan dalam komputer yang sama.


## SOAL 3

### Kategori File

**a

*Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan memindahkan file sesuai ekstensinya (tidak case sensitive. JPG dan jpg adalah sama) ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working
directory ketika program kategori tersebut dijalankan.


```

  if (strcmp(argv2[1],"-f")==0) {
        printf("Masuk ke -f\n");
        for(j=2;j<argv1;j++){
            pthread_create(&(thread[i]), NULL, playandcount, argv2[j]);
            pthread_join(thread[i], NULL);
            i++;
        }
   printf("SELESAI\n");
    }
    
```

- Pada opsi -f tersebut, user bisa menambahkan argumen file yang bisa dikategorikan sebanyak yang user inginkan seperti contoh di atas.

```

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

```

- Pada program kategori tersebut, folder jpg,c,zip tidak dibuat secara manual,
melainkan melalui program c. Semisal ada file yang tidak memiliki ekstensi,
maka dia akan disimpan dalam folder “Unknown”.

- Untuk opsi yang memasukkan argumen -d adalah sebagai berikut

```
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
            //printf("%s\n",de->d_name);
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
    
```

- Untuk opsi yang memasukkan argumen * adalah sebagai berikut

```

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
            printf("%s \n",de->d_name);
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

```

- Error handling

```
  else 
  // Error handling jika tidak ada argumen yang diinput
    {
    printf("Mohon masukkan argumen pada program, berupa -f, *, atau -d\n");
    exit(EXIT_FAILURE);
    } 
}

```

- Program untuk menggunakan thread

```

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

```

## SOAL 4

### Matriks 

**a.**
Program untuk melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks nantinya akan berisi angka 1-20

> Langkah dan Penjelasan


- Berikut adalah pengisian matriks pertama (isinya bebas) berukuran 4x5, yang dimana praktikan menamakan matriks pertama menjadi matriks A.

- Masing-masing elemen matriks ditulis satu persatu

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

- Berikut adalah pengisian matriks kedua (isinya bebas) berukuran 2x5, yang dimana praktikan menamakan matriks kedua menjadi matriks B. 

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

- Dibuat thread sebanyak pengisian matriks A dan B. Masing - masing thread di join

```

pthread_create(&thread1, NULL, pengisian_matriks_A, NULL);
	pthread_join(thread1,NULL);

	pthread_create(&thread2, NULL, pengisian_matriks_B, NULL);
	pthread_join(thread2,NULL);

```

- Template shared memory. Shared memory adalah memori yang dapat diakses secara bersamaan oleh beberapa program dengan maksud untuk menyediakan komunikasi di antara mereka atau menghindari salinan yang berlebihan. 

```

	key_t key = 1234;
    int shmid = shmget(key, sizeof(int[10][10]), IPC_CREAT | 0666);
    value = shmat(shmid, 0, 0);

```

- Dibuat thread sebanyak jumlah perkalian matriks. Program dibawah ini bertujuan sebagai template pengisian hasil perkalian matriks.

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

`value[i][j]= hsl;` merupakan penyimpanan hasil perkalian dalam variabel value


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


**b.**
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

        key_t key = 1234;
        int (*value)[10];
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, 0, 0);
    	printf("Hasil Faktorial Pertambahan Matriks tersebut adalah: \n");
	    for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			//faktorial dihitung per elemen matriks hasil perkalian
            angka=value[i][j];
			printf("%llu\t", factorial(angka)); 
		}
		printf("\n");
	}
    pthread_exit(0);
}

```

Melalui syntax `printf("%llu\t", factorial(angka));`, nantinya akan dicetak faktorial pertambahan per elemen matriks hasil perkalian tersebut.


- Fungsi rekursif untuk menghitung faktorial

```

unsigned long long factorial(unsigned long long a){
    if(a==0 || a==1) return 1;
    else return a+ factorial(a-1); //pemanggilan fungsi factorial
}

````

Jika elemennya 0 atau 1 maka akan mengembalikan nilai 1, karena faktorial dari 0 dan 1 adalah 1. Untuk elemen dg angka diatas 1 maka digunakan rumus `a+ factorial(a-1)`


**c.**
Pada program ini, Norland diminta mengetahui jumlah file dan folder di direktori saat ini dengan command "ls | wc -l".

- Deklarasikan pipe dan fork

```
	int pipe1[2], pipe2[2]; 
   
	pid_t p1;
	
	p1=fork();
	
```

- Error handling

```
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

	if (p1< 0) 
	{ 
		fprintf(stderr, "Fork Gagal" ); //tidak dapat dibentuk
		return 1; 
	}  

```


- Child process untuk menampilkan ls. List apa saja file yang ada di dalamnya

```
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

```

Perintah `char *arg2[] = {"ls", NULL};` digunakan untuk list file/folder didalam direktori sekarang.


- Fork pada parent yang menerima inputan dari child yang dihubungkan dengan pipe

```
    else if (p1 > 0) {

        close(pipe2[0]);
        close(pipe2[1]);
		// 0 = input, 1 = write
        dup2(pipe1[0], 0); 
		//baca isi dr pipe1 untuk dieksekusi
        dup2(pipe2[1], 1); // output ke pipe2

        close(pipe1[0]);
        close(pipe1[1]);

        char *arg1[] = {"wc", "-l", NULL};
        execvp("/usr/bin/wc", arg1);
		exit(0);
        }
	
```

`char *arg1[] = {"wc", "-l", NULL};` digunakan untuk mengetahui jumlah file dan folder di direktori saat ini

- Maka output yang dihasilkan dari program ini adalah jumlah dari file dan folder yang ada pada current working directory.


**TERIMA KASIH**
