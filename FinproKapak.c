#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>

//Deskripsi:
//*->Function dimulai dari tanda '*' untuk membentuk menu tersebut dan diakhiri  dengan -> //@
struct alamat {
    char alamat[50];
    char kota[50];
    char provinsi[50];
};

struct node {  
	char nama[50];
	char notelpon[15];
	struct alamat data;
	char email[50];
	int favorit;
    struct node* left;//untuk AVL TREE
    struct node* right;//untuk AVL TREE
    int height;  // Menyimpan tinggi node dalam AVL tree
};


//Regular text
#define GRY "\x1b[90m"
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define GRYB "\x1b[100m"
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background 
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

//Fungsi menentukan titik koordinat suatu output (print)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Fungsi menengahkan string
void centerText(const char* text, int y) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth;
    int textLength = strlen(text);

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    gotoxy(55, y);
    printf("%s", text);
}

//Tampilan 
void menu() {
    // Center the ASCII art
    gotoxy(40, 2);
    printf(BYEL"_______ _______ _       _______    _       _______ _______ _______ _       \n");
    gotoxy(40, 3);
    printf("(  ____ (  ____ ( (    /(  ____ \\  | \\    /(  ___  (  ____ (  ___  | \\    /\\\n");
    gotoxy(40, 4);
    printf("| (    \\| (    \\|  \\  ( | (    \\/  |  \\  / | (   ) | (    )| (   ) |  \\  / /\n");
    gotoxy(40, 5);
    printf("| |     | (__   |   \\ | | |        |  (_/ /| (___) | (____)| (___) |  (_/ / \n");
    gotoxy(40, 6);
    printf("| | ____|  __)  | (\\ \\) | | ____   |   _ ( |  ___  |  _____|  ___  |   _ (  \n");
    gotoxy(40, 7);
    printf("| | \\_  | (     | | \\   | | \\_  )  |  ( \\ \\| (   ) | (     | (   ) |  ( \\ \\ \n");
    gotoxy(40, 8);
    printf("| (___) | (____/| )  \\  | (___) |  |  /  \\ | )   ( | )     | )   ( |  /  \\ \\ \n");
    gotoxy(40, 9);
    printf("(_______(_______|/    )_(_______)  |_/    \\|/     \\|/      |/     \\|_/    \\/ \n"reset);

    // Center the menu
    centerText("+-------------------------------------------+", 13);
	centerText(REDHB BWHT"|         Contact Management System         |", 14);
    centerText(reset"+-------------------------------------------+", 15);
    centerText("| 1. Add / Edit Contact                     |", 16);
    centerText("| 2. View & Searching Contacts              |", 17);
    centerText("| 3. Delete Contact                         |", 18);
    centerText("| 4. View Favorite Contacts                 |", 19);
    centerText("| 5. Mark Favorite Contact                  |", 20);
    centerText("| 6. Remove Favorite Contact                |", 21);
    centerText("| 7. Back Up Contacts                       |", 22);
    centerText("| 8. Restore Contacts                       |", 23);
    centerText("| 9. Remove All Contacts                    |", 24);
    centerText("| 10. Remove All Favorite Contacts          |", 25);
    centerText("| 0. Exit                                   |", 26);
    centerText("+-------------------------------------------+", 27);

}

//Validasi input opt pada main function
int CheckValidityofIntegerInput(int isValidInput,int opt,int order){
		// Membersihkan input yang tidak valid
	while (getchar() != '\n') {}
		
	if(order==1){
		while (isValidInput != 1 || opt < 0 || opt > 10) {
			printf("\033[1;31m                                                       Input must be an integer between 0 to 10.\n \033[0m");
			printf("                                                      ");
			printf(GRNHB" "reset);
			printf(" What are you going to do? [0-10] ");
			printf(UWHT">>"reset);
			printf(" ");
		      
		    isValidInput = scanf("%d", &opt);
		        // Membersihkan input yang tidak valid
		    while (getchar() != '\n') {}
	    }
	}
	if(order==2){
		while (isValidInput != 1 || opt < 1 || opt > 2) {
			printf("\t\t\033[1;31mInput must be an integer between 1 to 2.\033[0m\n");
			printf("\t\t>> ");
		      
		    isValidInput = scanf("%d", &opt);
		        // Membersihkan input yang tidak valid
		    while (getchar() != '\n') {}
	    }
	}
    return opt;
};
//Untuk membersihkan screen
void clsscreen(){
	printf("\n");
	system("pause");
	system("cls");
}	
//AVL TREE
int maxTREE(int a, int b) {
    return (a > b) ? a : b;  // Mengembalikan nilai maksimum antara a dan b
}
//Mengukur tinggi node
int height(struct node* node) {
    if (node == NULL)
        return 0;  // Jika node kosong, tinggi adalah 0
    return node->height;  // Mengembalikan tinggi node
}
//Mengukur tingkat keseimbangan dari sebuah node
int getBalance(struct node* node) {
    if (node == NULL)
        return 0;  // Jika node kosong, balance adalah 0
    return height(node->left) - height(node->right);  // Menghitung faktor keseimbangan dari node
}
//Melakukan rotasi ke kanan ,apabila terjadi imbalance 
struct node* rightRotate(struct node* y) {
    struct node* x = y->left; // Simpan node x sebagai anak kiri dari y
    struct node* T2 = x->right; // Simpan node T2 sebagai anak kanan dari x
	// Lakukan rotasi kanan dengan mengubah referensi antara x dan y
    x->right = y;
    y->left = T2;
	 // Perbarui tinggi dari node y dan x setelah rotasi
    y->height = maxTREE(height(y->left), height(y->right)) + 1;  // Mengupdate tinggi node y(letak bingung)
    x->height = maxTREE(height(x->left), height(x->right)) + 1;  // Mengupdate tinggi node x
 
    return x;  // Kembalikan node x yang menjadi root baru setelah rotasi
}
//Melakukan rotasi ke kiri ,apabila terjadi imbalance 
struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxTREE(height(x->left), height(x->right)) + 1;  // Mengupdate tinggi node x
    y->height = maxTREE(height(y->left), height(y->right)) + 1;  // Mengupdate tinggi node y

    return y;  // Mengembalikan root baru setelah rotasi
}
//Membuat node baru
struct node* newNode(char nama[],char notelpon[],char email[],char alamat[],char kota[],char provinsi[],int favorit) {
    struct node* currNewNode = (struct node*)malloc(sizeof(struct node));
    if (currNewNode == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    strcpy(currNewNode->nama ,nama);
    strcpy(currNewNode->notelpon,notelpon);
    strcpy(currNewNode->email,email);
    
	strcpy(currNewNode->data.alamat,alamat);
    strcpy(currNewNode->data.kota,kota);
	strcpy(currNewNode->data.provinsi,provinsi);
	currNewNode->favorit=favorit;
	
	currNewNode->left = NULL;
    currNewNode->right = NULL;
    currNewNode->height = 1;  // Inisialisasi tinggi node sebagai 1
    return currNewNode;
}
//Memasukkan node baru		
struct node* insert(struct node* root, char nama[],char notelpon[],char email[],char alamat[],char kota[],char provinsi[],int favorit) {
    if (root == NULL)
        return newNode(nama,notelpon,email,alamat,kota,provinsi,favorit);  // Jika root kosong, membuat node baru dengan kunci x
		
    if (strcmp(nama , root->nama)<0)
        root->left = insert(root->left,nama,notelpon,email,alamat,kota,provinsi,favorit);  // Jika x lebih kecil dari kunci root, rekursi ke anak kiri
    else if (strcmp(nama , root->nama)>0)
        root->right = insert(root->right,nama,notelpon,email,alamat,kota,provinsi,favorit);  // Jika x lebih besar dari kunci root, rekursi ke anak kanan
    else
        return root;  // Jika x sama dengan kunci root, tidak melakukan apa-apa (tidak ada duplikat)

    root->height = 1 + maxTREE(height(root->left), height(root->right));  // Mengupdate tinggi root

    int balance = getBalance(root);  // Mendapatkan faktor keseimbangan root

    if (balance > 1 && strcmp(nama , root->left->nama)<0)
        return rightRotate(root);  // Rotasi kanan tunggal jika x di anak kiri kiri

    if (balance < -1 && strcmp(nama , root->right->nama)>0)
        return leftRotate(root);  // Rotasi kiri tunggal jika x di anak kanan kanan

    if (balance > 1 &&strcmp(nama , root->left->nama)>0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);  // Rotasi kiri kanan jika x di anak kiri kanan
    }

    if (balance < -1 &&strcmp(nama , root->right->nama)<0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);  // Rotasi kanan kiri jika x di anak kanan kiri
    }

    return root;  // Mengembalikan root setelah operasi penambahan selesai
}
//Melakukan pencarian node
struct node* search(struct node* root, char nama[])
{
    // Base Cases: root is null or nama is present at root
    if (root == NULL || strcmp(root->nama,nama)==0)
       return root;
    
    // nama is greater than root's nama
    if (strcmp(root->nama,nama)<0)
       return search(root->right,nama);

    // nama is smaller than root's nama
    return search(root->left,nama);
}
//Mengubah string menjadi huruf kecil
void strToLower(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}
//*Menu1

//validasi nomor telpon
int validnotelpon(char notelpon[]){
    
    //Validasi jumlah digit 
    if(strlen(notelpon)<11||strlen(notelpon)>13)
    	return 0;
    
    //Validasi numerik
    for (int i = 0; i <  strlen(notelpon); i++) {
        // Memeriksa setiap karakter apakah merupakan angka
        if (notelpon[i] < '0' || notelpon[i] > '9') {
            return 0; //jika tidak semua numerik akan mengembalikan nilai 0
        }
    }
    
    //Validasi awalan 62
    if (strncmp(notelpon, "62", 2) != 0) {
        return 0;
    }
     
    return 1; 
}

//Validasi email
int validemail(char email[]){
	//digit harus antara 16-22 karakter
	if(strlen(email)>22||strlen(email)<16)
		return 0;
	
	//mengecek apakah berakhiran dengan"@gmail.com" atau "@yahoo.com"
	if(strcmp(email+strlen(email)-10,"@gmail.com")!=0&&strcmp(email +strlen(email)- 10, "@yahoo.com") != 0)
		return 0;
	
	return 1;
	
	
}
//Mengecek ada spasi tidak dalam sebuah string
int spacechecker(char input[]){
	int i;
    int hasSpace = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            hasSpace = 1;
            return 0;//artinya tidak valid
        }
    }
    return 1;
}		
//Mengubah jadi huruf kapital semua kata		
int convertTocapital(char str[]){
	for(int i=0;str[i]!='\0';i++){
		if (str[0] != '\0') {
        	str[0] = toupper(str[0]);
		}
		if (str[i] == ' ' && str[i+1] != '\0') {
        	str[i+1] = toupper(str[i+1]);
		}
	}
}

//Meminta input pengguna
struct node* input(struct node *root){
	//Game nama
	char nama[50];
	char notelpon[15];
	int favorit;
	char want[10] ;
	char alamat[50];
	char kota[50];
	char provinsi[50];
	char email[50];
	
	struct node* temp;//nampung alamat searching
	
	gotoxy(51, 0);
	printf("+-----------------------------+\n");
	gotoxy(51, 1);
	printf("|   Add / Edit Contact Menu   |\n");
	gotoxy(51, 2);
	printf("+-----------------------------+\n");
	
	do{
		gotoxy(54, 6);
		printf(BHBLK"                                                  "reset);
		gotoxy(51, 4);
		printf("Input the name\n");
		gotoxy(51, 5);
		printf(GRNHB" "reset);
		printf(" [4-25]\n");
		gotoxy(51, 6);
		printf(UWHT">>"reset);
		printf(" ");	
		scanf("%[^\n]",nama);
		getchar();
		
		//mengubah secara otomatis nama menjadi huruf kapital
		 convertTocapital(nama);
		
	}while(strlen(nama)<4||strlen(nama)>25);//validasi untuk input nama 
	
	temp=search(root,nama);
	
 	//jika nama sudah ada di dalam tree maka akan menampilkan data pada nama tersebut dan menawarkan user untuk update
 	if(temp!=NULL){
	puts("\n+----------------------------------------+");
    printf("| Name         : %-25s\n", temp->nama);
    printf("| Phone Number : +%-13s\n", temp->notelpon);
    printf("| Email        : %-22s\n", temp->email);
    printf("| Home Address : %-25s\n", temp->data.alamat);
    printf("| City         : %-15s\n", temp->data.kota);
    printf("| Province     : %-17s\n", temp->data.provinsi);
    puts("+----------------------------------------+");
 		do{
		 
			printf("\nDo you want to edit the contact?\n");
			printf(YELHB" "reset);
			printf(" [yes|no]\n");
			printf(YELHB" "reset);
			printf(" [case insensitive]\n");
			printf(UWHT">>"reset);
			printf(" ");
			scanf("%[^\n]",want);
			getchar();
			
			strToLower(want);
		}while((strcmp(want,"yes")!=0)&&(strcmp(want,"no")!=0)||spacechecker(want)!=1);//validasai input harus antara "yes" atau "no"
	
		if(strcmp(want,"no")==0){
			return root;
		} 
	}
		
	//No telpon
	do{
		gotoxy(54, 13);
		printf(BHBLK"                                                  "reset);
		gotoxy(51, 8);
		printf("Input the phone number\n");
		gotoxy(51, 9);
		printf(GRNHB" "reset);
		printf(" [11-13]\n");
		gotoxy(51, 10);
		printf(GRNHB" "reset);
		printf(" [numeric]\n");
		gotoxy(51, 11);
		printf(GRNHB" "reset);
		printf(" [62 at begin]\n");
		gotoxy(51, 12);
		printf(GRNHB" "reset);
		printf(" [no space]\n");
		gotoxy(51, 13);
		printf(UWHT">>"reset);
		printf(" ");	

		// Menghilangkan karakter newline dari input

		scanf("%[^\n]",notelpon);
		getchar();
	}while(validnotelpon(notelpon)!=1||spacechecker(notelpon)!=1);
	
	//Alamat
	do{
		gotoxy(54, 18);
		printf(BHBLK"                                                  "reset);
		gotoxy(51, 15);
		printf("Do you want to fill/write the address?\n");
		gotoxy(51, 16);
		printf(GRNHB" "reset);
		printf(" [yes|no]\n");
		gotoxy(51, 17);
		printf(GRNHB" "reset);
		printf(" [case insensitive]\n");
		gotoxy(51, 18);
		printf(UWHT">>"reset);
		printf(" ");
		scanf("%[^\n]",want);
		getchar();

		strToLower(want);
	}while((strcmp(want,"yes")!=0)&&(strcmp(want,"no")!=0)||spacechecker(want)!=1);//validasai input harus antara "yes" atau "no" dan tidak boleh ada spasi

	//kalau ingin isi alamat
	if(strcmp(want,"yes")==0){
		do{
			gotoxy(54, 22);
			printf(BHBLK"                                                  "reset);
			gotoxy(51, 20);
			printf("Input the home address\n");
			gotoxy(51, 21);
			printf(GRNHB" "reset);
			printf(" [4-25]\n");
			gotoxy(51, 22);
			printf(UWHT">>"reset);
			printf(" ");
			scanf("%[^\n]",alamat);
			getchar();
			//Convert jadi huruf kapital
			convertTocapital(alamat);
		}while(strlen(alamat)<4||strlen(alamat)>25);
		
		do{
			gotoxy(54, 26);
			printf(BHBLK"                                                  "reset);
			gotoxy(51, 24);
			printf("Input the city\n");
			gotoxy(51, 25);
			printf(GRNHB" "reset);
			printf(" [4-15]\n");
			gotoxy(51, 26);
			printf(UWHT">>"reset);
			printf(" ");
			scanf("%[^\n]",kota);
			getchar();
			//Convert jadi huruf kapital
			convertTocapital(kota);			
		}while(strlen(kota)<4||strlen(kota)>15);
		
		do{
			gotoxy(54, 30);
			printf(BHBLK"                                                  "reset);
			gotoxy(51, 28);
			printf("Input the province\n");
			gotoxy(51, 29);
			printf(GRNHB" "reset);
			printf(" [4-17]\n");
			gotoxy(51, 30);
			printf(UWHT">>"reset);
			printf(" ");
			scanf("%[^\n]",provinsi);
			getchar();			
			convertTocapital(provinsi);	
		}while(strlen(provinsi)<4||strlen(provinsi)>17);
	}
	else{
			gotoxy(54, 22);
			printf(BHBLK"                                                  "reset);
			gotoxy(51, 20);
			printf(GRY"Input the home address\n");
			gotoxy(51, 21);
			printf(GRYB" "reset);
			printf(GRY" [4-25]\n");
			gotoxy(51, 22);
			printf(UWHT GRY">>"reset);
			
			gotoxy(54, 26);
			printf(BHBLK"                                                  "reset);
			gotoxy(51, 24);
			printf(GRY "Input the city\n");
			gotoxy(51, 25);
			printf(GRY GRYB" "reset);
			printf(GRY" [4-15]\n");
			gotoxy(51, 26);
			printf(UWHT GRY">>"reset);
			
			gotoxy(54, 30);
			printf(BHBLK"                                                  "reset);
			gotoxy(51, 28);
			printf(GRY "Input the province\n");
			gotoxy(51, 29);
			printf(GRY GRYB" "reset);
			printf(GRY" [4-17]\n");
			gotoxy(51, 30);
			printf(UWHT GRY">>"reset);
			
			
		strcpy(alamat,"None");
		strcpy(kota,"None");
		strcpy(provinsi,"None");
	}

	//Email
	do{
		gotoxy(54, 35);
		printf(BHBLK"                                                  "reset);
		gotoxy(51, 32);
		printf("Input the email addres\n");
		gotoxy(51, 33);
		printf(GRNHB" "reset);
		printf(" [@yahoo.com||@gmail.com]\n");
		gotoxy(51, 34);
		printf(GRNHB" "reset);
		printf(" [16-22 characters]\n");
		gotoxy(51, 35);
		printf(UWHT">>"reset);
		printf(" ");
		scanf("%[^\n]",email);
		getchar();
		
	}while(validemail(email)!=1||spacechecker(email)!=1);//validasi
	
	
	//kalau temp ada data/value didalamnya
	if(temp!=NULL){
		// akan melakukan update
		strcpy(temp->notelpon,notelpon);
		strcpy(temp->email,email);
		strcpy(temp->data.alamat,alamat);
		strcpy(temp->data.kota,kota);
		strcpy(temp->data.provinsi,provinsi);
		
	}else{
		//insert node baru
		
		favorit=0;//setting untuk bukan kontak favorit secara default
		root=insert(root,nama,notelpon,email,alamat,kota,provinsi,favorit);
		gotoxy(51, 37);
		printf("\033[1;32mInsert success! :)\033[0m\n");	
	}
	
		
	
	return root;
}
//@Menu 1

//*Menu2

//Menghitung jumlah node yang ada
int countnodes(struct node *root,int count)
{
	if(root == NULL)
        return count;

    if(root != NULL)
    {
        count=countnodes(root->left,count);
        count++;
        count=countnodes(root->right,count);
    }
    
    return count;
}

//Display record secara urut(inorder)
void inorderTraversal(struct node* root,int size,int printHeader) {
    if (size == 0) {
        centerText("\033[1;31mContact is empty!\033[0m\n\n\n\n", 8);
        return;
    }
    int i=0;
    if (root == NULL)
        return;  // Jika root kosong, tidak ada pencetakan yang dilakukan
	if (printHeader==1)
	{  
		puts("\t\t+---------------------------------------------------------------------------------------------------------------------------------------+");
      	printf(REDHB BWHT"\t\t|           Name            |  Phone Number  |          Email         |        Home Address       |       City      |      Province     |"reset);
        printf("\n\t\t+---------------------------------------------------------------------------------------------------------------------------------------+\n");
    }    
    inorderTraversal(root->left,size,0);  // Rekursi pada anak kiri
	
 	printf("\t\t| %-25s | +%-13s | %-22s | %-25s | %-15s | %-17s |\n",root->nama,root->notelpon,root->email,root->data.alamat,root->data.kota,root->data.provinsi);
	  
  // Mencetak kunci node saat ini
	printf("\t\t+---------------------------------------------------------------------------------------------------------------------------------------+\n");
  
	inorderTraversal(root->right,size,0);  // Rekursi pada anak kanan

}


void display(struct node* root,int size){
	size=countnodes(root,0);
	inorderTraversal(root,size,1);
}
void displaysearch(struct node* temp){
	gotoxy(51, 0);
	printf("+-----------------------------+\n");
	gotoxy(51, 1);
	printf("|        Your Contacts        |\n");
	gotoxy(51, 2);
	printf("+-----------------------------+\n");
	puts("\t\t\n\nThe search results are as follows:\n\n");
	puts("\t\t+---------------------------------------------------------------------------------------------------------------------------------------+");
    printf(REDHB BWHT"\t\t|           Name            |  Phone Number  |          Email         |        Home Address       |       City      |      Province     |"reset);
    printf("\n\t\t+---------------------------------------------------------------------------------------------------------------------------------------+\n");

	printf("\t\t| %-25s | +%-13s | %-22s | %-25s | %-15s | %-17s |\n",temp->nama,temp->notelpon,temp->email,temp->data.alamat,temp->data.kota,temp->data.provinsi);							
	printf("\t\t+---------------------------------------------------------------------------------------------------------------------------------------+\n");
}
//@Menu 2(Menampilkan pilihan fitur searching)

//*Menu 3
//Mencari node pengganti ketika node yang digantikan memilik 2 anak
struct node* predecessor(struct node* root) {
    struct node* curr = root->left;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr;  // Mengembalikan predecessor dari root
}
//Menghapus node yang dicari
struct node* deleteValue(struct node* root, char nama[]) {
    if (root == NULL)
        return NULL;  // Jika root kosong, tidak ada yang dihapus

    if (strcmp(nama , root->nama)<0)
        root->left = deleteValue(root->left, nama);  // Jika x lebih kecil dari kunci root, rekursi ke anak kiri
    else if (strcmp(nama , root->nama)>0)
        root->right = deleteValue(root->right, nama);  // Jika x lebih besar dari kunci root, rekursi ke anak kanan
    else {
        // Data ditemukan. Proses penghapusan dapat dilakukan
        if ((root->left == NULL) || (root->right == NULL)) {
            struct node* temp = NULL;
            if (root->left != NULL)
                temp = root->left;  // Jika hanya memiliki anak kiri, root diganti dengan anak kiri
            else
                temp = root->right;  // Jika hanya memiliki anak kanan, root diganti dengan anak kanan

            if (temp == NULL) {
                temp = root;
                root = NULL;  // Jika root tidak memiliki anak, root dihapus
            } else {
                *root = *temp;  // Jika root memiliki satu anak, root diganti dengan anak tersebut
                
            }
            free(temp);  // Membebaskan memori dari temp
            
        } else {
            // Menggunakan predecessor: node terbesar dari subtree kiri
            struct node* temp = predecessor(root);
            strcpy(root->nama , temp->nama);  // Mengganti kunci root dengan kunci predecessor

            root->left = deleteValue(root->left, temp->nama);  // Rekursi untuk menghapus predecessor dari anak kiri
        }
    }

    if (root == NULL)
        return root;  // Jika root kosong setelah penghapusan, mengembalikan NULL

    root->height = 1 + maxTREE(height(root->left), height(root->right));  // Mengupdate tinggi root

    int balance = getBalance(root);  // Mendapatkan faktor keseimbangan root

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);  // Rotasi kanan tunggal jika faktor keseimbangan tidak merusak setelah penghapusan

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);  // Rotasi kiri kanan jika faktor keseimbangan merusak setelah penghapusan
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);  // Rotasi kiri tunggal jika faktor keseimbangan tidak merusak setelah penghapusan

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);  // Rotasi kanan kiri jika faktor keseimbangan merusak setelah penghapusan
    }

    return root;  // Mengembalikan root setelah operasi penghapusan selesai
}

struct node* del(struct node* root,char nama[]){
	struct node* temp;//untuk menampung alamat hasil pencarian
	char updatetype[20];
	int add;
	int remove;
	
	temp=search(root, nama);
	if(temp==NULL){
		puts("\033[1;31m\t\tData not found\033[0m\n");
		return root;
	}
	else
	{
		printf("\033[1;32m\t\t%s has been successfully deleted\033[0m\n",temp->nama);
		root=deleteValue(root,temp->nama);
		
	}
		
	return root;
}
//@Menu 3
//*Menu 4
void inorderTraversalFav(struct node* root,int favsize,int printHeader){
	if(favsize==0){
		centerText("\033[1;31mFavorite contact is empty!\033[0m\n\n\n\n", 8);
		return;
	}
		
	if (root == NULL)
        return;  // Jika root kosong, tidak ada pencetakan yang dilakukan
	if (printHeader==1)
	{  
        puts("\t\t+---------------------------------------------------------------------------------------------------------------------------------------+");
      	printf(REDHB BWHT"\t\t|           Name            |  Phone Number  |          Email         |        Home Address       |       City      |      Province     |"reset);
        printf("\n\t\t+---------------------------------------------------------------------------------------------------------------------------------------+\n");
    }  
    inorderTraversalFav(root->left,favsize,0);  // Rekursi pada anak kiri
    if(root->favorit==1){
   	 	printf("\t\t| %-25s | +%-13s | %-22s | %-25s | %-15s | %-17s |\n",root->nama,root->notelpon,root->email,root->data.alamat,root->data.kota,root->data.provinsi);
  		// Mencetak kunci node saat ini
		puts("\t\t+---------------------------------------------------------------------------------------------------------------------------------------+");
	}
		
	inorderTraversalFav(root->right,favsize,0);  // Rekursi pada anak kanan
}
//Menghitung jumlah record contact favorite yang ada

int countfav(struct node *root, int countfvrt)
{
    if (root == NULL)
        return countfvrt;
    
    countfvrt = countfav(root->left, countfvrt);
    if (root->favorit == 1){
    	countfvrt++;
	}
        
    countfvrt = countfav(root->right, countfvrt);
	
    return countfvrt;
}


//Menampilkan kontak favorit
void displayfavorite(struct node* root,int favoritesize){
	favoritesize=countfav(root,0);
	if(favoritesize!=0)
		printf("\n\t\tYour Favorite Contacts ");
		
		printf(HRED"<3"reset);
		printf(":\n\n");
	inorderTraversalFav(root,favoritesize,1);
};
//@Menu 4
//Menu 5
struct node* remarkfavorite(struct node* root,char nama[]){
	struct node* temp;//menampung alamat searching
	temp=search(root,nama);
	if(temp==NULL){
		puts("\033[1;31m\t\tThe contact you want to remark as a favorite is not present in the contact list.\033[0m");
		return root;
	}
	
	//Untuk mengubah status menjadi kontak favorit
	if(temp->favorit==0){
		temp->favorit=1;
		printf("\033[1;32m\n\t\t%s has been successfully remarked as a favorite contact\n\033[0m", temp->nama);

	}else{
		 printf("\033[1;31m\t\t%s has already been added as a favorite contact\n\033[0m", temp->nama);
	}
	return root;
};
//@Menu 5
//Menu 6
struct node* removefavorite(struct node* root,char nama[]){
	struct node* temp;//menampung alamat searching
	

	temp=search(root,nama);

	if(temp==NULL){
		puts("\033[1;31m\t\tThe contact you want to remove from a favorite is not present in the contact list.\033[0m");
		return root;
	}
	//Mengubah status favorit menjadi tidak favorit
	if(temp->favorit==1){
		temp->favorit=0;
		printf("\n\033[1;32m\t\t%s has been successfully removed from the favorite contact\033[0m\n",temp->nama);
	}else{
		printf("\033[1;31m\t\t%s has already been as a not favorite contact\033[0m\n",temp->nama);
	}

	return root;
};
//@Menu 6

//Menu 7
void inorderTraversalBackup(struct node* root, FILE* file) {
    if (root != NULL) {
        inorderTraversalBackup(root->left, file);
        
        fprintf(file, "%s,%s,%s,%s,%s,%s,%d\n", root->nama,root->notelpon,root->email,root->data.alamat,root->data.kota,root->data.provinsi,root->favorit);
        
        inorderTraversalBackup(root->right, file);
    }
}

void backupData(struct node* root) {
 	FILE *file;   
 	char filename[30]="ContactList.txt";
	file = fopen(filename, "w");  // Membuka file dalam mode tulis
    fprintf(file,"Name,PhoneNumber,Email,Address,City,Province,FavoriteStatus\n");
    
	
	if (file == NULL) {
        centerText("\033[1;31mError: Failed to open file\n\033[0m\n", 8);
        return;
        
    }
    
    // Traverse pohon secara inorder dan tulis data ke file
    inorderTraversalBackup(root, file);
    
    fclose(file);  // Menutup file setelah selesai menulis
    if(root==NULL){
    	gotoxy(25, 8);
		printf("\033[1;31mYou don't have any data to be backed up!\033[0m\n\n\n");
		return ;
	}
	gotoxy(25, 8);
	printf("\033[1;32mYour record data has been successfully backed up to the %s\033[0m\n\n\n",filename);
}
//@Menu 7

//konfirmasi sebelum melakukan back up ,hapus semua kontak ,dan hapus semua kontak favorit
int	Konfirmasi(int opsi){
	char input[10];
	if(opsi==1){//konfirmasi untuk backup 
	
		do{
			gotoxy(28, 6);
			printf(BHBLK"                                                  "reset);
			gotoxy(25, 4);
			printf("Are you sure for doing back up and file ContactList.txt will be removed from previous data?");
			gotoxy(25, 5);
			printf(GRNHB" "reset);
			printf(" [yes|no]");
			gotoxy(25, 6);
			printf(UWHT">>"reset);
			printf(" ");	
			scanf("%[^\n]",input);
			getchar();
			strToLower(input);
		}while(strcmp(input,"yes")!=0&&strcmp(input,"no")!=0);
	}
	if(opsi==2){

		do{
			gotoxy(28, 6);
			printf(BHBLK"                                                  "reset);
			gotoxy(25, 4);
			printf("Are you sure you want to remove all the contacts?");
			gotoxy(25, 5);
			printf(GRNHB" "reset);
			printf(" [yes|no]");
			gotoxy(25, 6);
			printf(UWHT">>"reset);
			printf(" ");	
			scanf("%[^\n]",input);
			getchar();
			strToLower(input);
		}while(strcmp(input,"yes")!=0&&strcmp(input,"no")!=0);		
	}
	if(opsi==3){

		do{
			gotoxy(28, 6);
			printf(BHBLK"                                                  "reset);
			gotoxy(25, 4);
			printf("Are you sure you want to remove all the favorite contacts?");
			gotoxy(25, 5);
			printf(GRNHB" "reset);
			printf(" [yes|no]");
			gotoxy(25, 6);
			printf(UWHT">>"reset);
			printf(" ");	
			scanf("%[^\n]",input);
			getchar();
			strToLower(input);
		}while(strcmp(input,"yes")!=0&&strcmp(input,"no")!=0);		
	}	
	if(strcmp(input,"yes")==0)
		return 1;
	else
		return 0;

}

void loadingBar()
{
    // 0 - black background, A - Green Foreground
    system("color 0A");

    // Initialize characters for printing loading bar
    char a = 177, b = 219;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    // Print initial loading bar
    for (int i = 10; i < 15; i++)
        printf("%c", a);

    // Set the cursor again at the starting point of loading bar
    printf("\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 50; i < 100; i++) {
        printf("%c", b);

        // Sleep for 1 second
        Sleep(42);
    }
}

//*Menu 8
struct node* restoreData(struct node* root) {
    struct node* head = NULL; // Head linked list
    struct node* tail = NULL; // Tail linked list
    FILE* file = fopen("ContactList.txt", "r");  // Membuka file dalam mode baca
    
    if (file == NULL) {
        centerText("\033[1;31mError: Failed to open file\n\033[0m\n", 8);
        return root;
    }
    char header[100];
    struct node temp;
    
    //scan header di file
	fscanf(file, "%[^\n]\n", header);
      // Menutup file setelah selesai membaca
    char nama[100], notelpon[100], email[100], alamat[100], kota[100], provinsi[100];
    int favorit;
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d\n", nama, notelpon, email, alamat, kota, provinsi, &favorit) != EOF) {

        root = insert(root, nama, notelpon, email, alamat, kota, provinsi, favorit);
    }
    
    fclose(file);
    gotoxy(40, 13);
    printf("Restoring. . . ");
    gotoxy(0, 1);
    loadingBar();
    gotoxy(40, 17);
    printf("\033[1;32mThe records have been successfully restored! :)\033[0m");
    printf("\n\n\n\n\n\n\n\n");
    return root;
}
//@Menu 8
//Menu 0 dan 9
//Menghapus semua node yang ada di memori
struct node* freeAll(struct node* root) {
    if (root == NULL)
        return NULL;  // Jika root kosong, tidak ada pembebasan memori yang dilakukan

    root->left = freeAll(root->left);  // Rekursi pada anak kiri
    root->right = freeAll(root->right);  // Rekursi pada anak kanan

    free(root);  // Membebaskan memori dari root saat ini
	return NULL;
}

//Menu 10
void removeallfavtrav(struct node* root, int size) {


    if (root == NULL)
        return;  // Jika root kosong, tidak ada pencetakan yang dilakukan

    removeallfavtrav(root->left, size);  // Rekursi pada anak kiri

    // Pencetakan data pada node

    // Lakukan pencetakan data lainnya sesuai dengan struktur node yang digunakan

    root->favorit = 0; // Mengatur nilai favorit menjadi 0 pada setiap node

    removeallfavtrav(root->right, size);  // Rekursi pada anak kanan
}
void removeallfav(struct node* root,int favoritesize){
	favoritesize=countfav(root,0);
	if(favoritesize!=0){
		if(Konfirmasi(3)){
			removeallfavtrav(root,favoritesize);
			gotoxy(25, 7);
			puts("\033[1;32mAll favorite records have been successfully remove!\033[0m");
		}	
	}else{
		centerText("\033[1;31mFavorite contact is empty!\033[0m\n\n\n\n", 8);
	}
}
//@Menu 10

//Tampilan
void closing(){
	centerText(HRED "      *****       88888888888 888                        888           Y88b   d88P                \n", 4); 
	centerText(HBLU "   **       **        888     888                        888            Y88b d88P                 \n", 5);
	centerText(HBLU " **           **      888     888                        888             Y88o88P                  \n", 6);
	centerText(HRED "*   @       @   *     888     88888b.   8888b.  88888b.  888  888         Y888P  .d88b.  888  888 \n", 7);
	centerText(HRED "*       ^       *     888     888 '88b     '88b 888 '88b 888 .88P          888  d88  88b 888  888 \n", 8);
	centerText(HBLU "*   \\\\_____/    *     888     888  888 .d888888 888  888 888888K           888  888  888 888  888 \n", 9);
	centerText(HBLU " *            *       888     888  888 888  888 888  888 888  '88b         888  Y88..88P Y88b 888 \n", 10); 
	centerText(HRED "   **       **        888     888  888 'Y888888 888  888 888   888         888   -Y88P-  -Y88888  \n", 11 ); 
	centerText(HRED "      *****     \n\n\n\n"reset, 12 );
}


int main(){
	int opt;
	int size;
	int favoritesize;
	char key[50];
	int isValidInput;
	struct node* root = NULL;
	struct node* temp; 
	int inginsearch;
	int inputs;

	do{

		menu();//Tampilan
		gotoxy(55, 29);
		printf(GRNHB" "reset);
		printf(" What are you going to do? [0-10] ");
		printf(UWHT">>"reset);
		printf(" ");
		isValidInput = scanf("%d", &opt);//Minta input pilihan
		opt=CheckValidityofIntegerInput(isValidInput,opt,1);
	
	  
	    system("cls");
		switch(opt){
			case 1:
				root =input(root);
				clsscreen();
				break;
			case 2:	
					


				
				do{
			
					
					gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|        Your Contacts        |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");

					if(countnodes(root,0)!=0){
					
						display(root,size);						
						do{
							printf("\n");
							printf("\t\tWhat do you want to do?\n");
							printf(BCYN"\t\t[1]"reset);
							printf(" Search Contact\n");
							printf(BCYN"\t\t[2]"reset);
							printf(" Back\n");
							printf(UWHT"\t\t>>"reset);
							printf(" ");
							isValidInput = scanf("%d", &inputs);
							inputs=CheckValidityofIntegerInput(isValidInput,inputs,2);
							//getchar();
							
						}while(inputs!=1&&inputs!=2);

						if(inputs==1){
						
							printf("\t\tInput the contact full name that you want to search: ");
							scanf("%[^\n]",key);
							getchar();
							convertTocapital(key);		
							temp=search(root,key);
							if(temp!=NULL){
							
								system("cls");
						 		displaysearch(temp);	
								clsscreen();
							}else{
								puts("\033[1;31m\t\tThe contact that you're searching for has not been found.\033[0m");		
								clsscreen();
							}
						}
						if(inputs!=1)
							system("cls");		
					}else{
						display(root,size);
						
					centerText("\033[1;31mNo data recorded\033[0m\n\n\n\n\n", 8);
			
						clsscreen();
						break;
					}				
				}while(inputs!=2);
				
				break;
			case 3:
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|        Delete Contact       |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				display(root,size);
				if(countnodes(root,0)!=0){
					printf("\n\t\tInput the contact name that you want to delete:\n");
					printf(REDHB"\t\t[X]"reset);
					printf(" ");
					printf(UWHT">>"reset);
					printf(" ");
					scanf("%[^\n]",key);
					getchar();
					convertTocapital(key);		
					root=del(root,key);
				}
				clsscreen();
				break;
			case 4:
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|    Your Favorite Contact    |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				displayfavorite(root,favoritesize);
				clsscreen();
				break;
			case 5:
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|     Mark Favorite Contact   |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				display(root,size);
				
				if(countnodes(root,0)!=0){
					printf("\n\t\tInput the contact name that you want to remark as a favorite:\n");
					printf(REDHB"\t\t<3"reset);
					printf(" ");
					printf(UWHT">>"reset);
					printf(" ");
					scanf("%[^\n]",key);
					getchar();
					convertTocapital(key);		
					root=remarkfavorite(root,key);
				}
				clsscreen();
				break;
			case 6:
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|   Remove Favorite Contact   |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				displayfavorite(root,favoritesize);
				
				
				if(countfav(root,0)!=0){
					printf("\n\t\tInput the contact name that you want to remove as a favorite:\n");
					printf(REDHB"\t\t</3"reset);
					printf(" ");
					printf(UWHT">>"reset);
					printf(" ");
					scanf("%[^\n]",key);
					getchar();
					convertTocapital(key);		
					root=removefavorite(root,key);
				}
				clsscreen();
				break;	
			case 7:	
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|       Back Up Contacts      |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				if(Konfirmasi(1)==1)
					backupData(root);
				clsscreen();
				break;
			case 8:
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|        Restore Contact      |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				root=restoreData(root);
				clsscreen();
				break;
			case 9:
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|      Remove All Contact     |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				if(root==NULL){
					centerText("\033[1;31mNo data to be deleted\033[0m\n\n\n\n\n", 8);
				}
				else{
					if(Konfirmasi(2)==1){
						root=freeAll(root);
						gotoxy(25, 7);
						printf("\033[1;32mAll records have been succesfully deleted\033[0m\n");
					}
					
				}		
				clsscreen();
				break;
			case 10:
				gotoxy(51, 0);
				printf("+-----------------------------+\n");
				gotoxy(51, 1);
				printf("|      Remove All Favorite    |\n");
				gotoxy(51, 2);
				printf("+-----------------------------+\n");
				removeallfav(root,favoritesize);	
				clsscreen();
				break;
			case 0:
				root=freeAll(root);
				break;					
		}
	}while(opt!=0);
	closing();
	return 0;
}
