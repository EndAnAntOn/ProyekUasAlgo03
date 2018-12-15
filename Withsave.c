#include <stdlib.h>
#include <stdio.h>

struct wajibPajak{
	char nama[50];
	char NPWP[200];
	int menikah, tanggungan;
	float NJOP, gaji, PPh, PBB;
	struct wajibPajak *lanjut;
};

struct wajibPajak *head = NULL;
//aman
void insert(){
	float PKP, potongan = 54000000;
	struct wajibPajak *node = (struct wajibPajak*) malloc(sizeof(struct wajibPajak));
	
	printf("Nama: ");
	scanf("%s",node->nama);
	
	printf("NPWP: ");
	scanf("%s",node->NPWP);
	
	while(node->menikah!=1 && node->menikah !=2){
		printf("Sudah menikah?\n");
		printf("[1] iya\n");
		printf("[2] tidak\n");
		scanf("%d",&node->menikah);
	}
	
	printf("Tanggungan: ");
	scanf("%d",&node->tanggungan);
	
	printf("Gaji: Rp.");
	scanf("%f",&node->gaji);
	
	printf("NJOP: RP.");
	scanf("%f",&node->NJOP);
	
	if(node->tanggungan <= 0){
		potongan = potongan + 0;
	}
	else if(node->tanggungan == 1){
		potongan = potongan + 4500000;
	}
	else if(node->tanggungan == 2){
		potongan = potongan + 9000000;
	}
	else if(node->tanggungan >= 3){
		potongan = potongan + 13500000;
	}
	
	if(node->menikah == 1){
		potongan = potongan + 4500000;
	}
	PKP = node->gaji - potongan;
	if ( PKP > 0){
		if( PKP <= 50000000 ){
			node->PPh = PKP * 5/100;
		}	
		else if( PKP <= 250000000 && PKP > 50000000 ){
			node->PPh = PKP * 15/100;
		}
		else if( PKP <= 500000000 && PKP > 250000000){
			node->PPh = PKP * 25/100;
		}
		else if( PKP <= 500000000 ){
			node->PPh = PKP * 30/100;
		}
	}
	else if (PKP < 0) node->PPh = 0;
	
	node->PBB = node->NJOP / 1000;
	node->lanjut = head;
	head = node;
}
//aman
void lihatData() {
   struct wajibPajak *m = head;
   int i;
   while(m != NULL) {
      	printf("================================\n");     
      	printf("Nama = %s \n",m->nama);
      	printf("NPWP = %s \n",m->NPWP);
      	printf("Tanggungan = %d orang\n",m->tanggungan);
      	printf("Status : ");
      	if(m->menikah == 1){
      		printf("menikah\n");
		}
		else printf("lajang\n");
		printf("gaji = Rp.%.2f\n",m->gaji);
      	printf("PPh = Rp.%.2f\n",m->PPh);
      	printf("PBB = Rp.%.2f\n",m->PBB);
      	m = m->lanjut;
      	i = 1;
   }
   if(i==0){
   		printf("tidak ada data.\n");
   }
	printf("tekan apapun untuk melanjutkan.");
	getch();
}
//aman
void cari(char nama[50]){
	struct wajibPajak *m = head;
	while(m != NULL){
		if(strcmp(m->nama,nama) == 0){
			printf("Ditemukan wajib pajak atas nama %s\n",m->nama);
      		printf("NPWP = %s \n",m->NPWP);
			printf("Tanggungan = %d orang\n",m->tanggungan);
      		printf("Status : ");
    	  	if(m->menikah == 1){
      		printf("menikah\n");
			}
			else printf("lajang\n");
			printf("gaji = Rp.%.2f",m->gaji);
   	   		printf("PPh = Rp.%.2f\n",m->PPh);
   		   	printf("PBB = Rp.%.2f\n",m->PBB);      	
   		   	getch();
		}
		else
	printf("Wajib pajak tersebut tak ditemukan\n");
		m = m->lanjut;
	}
	printf("tekan apapun untuk melanjutkan.");
   	getch();
}
//blm bs hapus data terakhir
void hapus(char nama[50]){
	struct wajibPajak *m = head;
	int var = 0;
	while(m != NULL && var == 0){
		if(strcmp(m->lanjut->nama,nama) == 0){
				struct wajibPajak *n;
			printf("Data wajib pajak atas nama %s akan dihapus\n",m->lanjut->nama);
			n = m->lanjut;
			m->lanjut = m->lanjut->lanjut;
			free(n);
			var = 1;
		}
	//	if(strcmp(m->nama,nama)==0)
	//	{
	//	print("Data wajib pajak atas nama %s akan dihapus\n",m->nama);
	//	head = m->lanjut;
	//	free(m);
	//	}
		getch();
	m = m->lanjut;
	}
	printf("Wajib pajak tersebut tak ditemukan\n");
	printf("tekan apapun untuk melanjutkan.");
   	getch();
}
//blm masuk ke insert tp bisa load
void loadlist(){
   FILE *fptr;
   char *temp[50];
   int count = 0;
   int i;
   char textName[sizeof "text1000.txt"];
   sprintf(textName,"data.txt");
   if ((fptr = fopen(textName,"r")) == NULL){
       	char listEvent[sizeof "text1000.txt"];
		sprintf(listEvent,"data.txt"); //ganti nama file
		fptr = fopen(listEvent,"a");
		fclose(fptr);
   }
   fseek(fptr, 0L, SEEK_END);
   long numbytes = ftell(fptr);
   fseek(fptr, 0L, SEEK_SET);
   char text[numbytes/sizeof(char)];
   fread(text, sizeof(char), numbytes, fptr);
   fclose(fptr);
   char *ch;
   ch = strtok(text," ");
   while (ch != NULL) {
   		printf("%s*",ch);
  		temp[count] = ch;
  		count++;
  		ch = strtok(NULL, " ");
  	}
	printf("tekan apapun untuk melanjutkan.");
	getch();				
	for(i = 2;i < count;i = i + 4){   
		   float PKP, potongan = 54000000;
			struct wajibPajak *node = (struct wajibPajak*) malloc(sizeof(struct wajibPajak));
			strcpy(node->nama,temp[i]);
			i = i + 3;
			strcpy(node->NPWP,temp[i]);
			//int t_npwp = atoi(temp[i]);
			//node->NPWP = t_npwp;
			i = i + 3;
			int t_nikah = atoi(temp[i]);
			node->menikah = t_nikah;
			i = i + 3;
			int t_tanggungan = atoi(temp[i]);
			node->tanggungan = t_tanggungan;
			i = i + 3;
			int t_gaji = atof(temp[i]);
			node->gaji = t_gaji;
			i = i + 3;
			if(node->tanggungan <= 0){
				potongan = potongan + 0;
			}
			else if(node->tanggungan == 1){
				potongan = potongan + 4500000;
			}
			else if(node->tanggungan == 2){
				potongan = potongan + 9000000;
			}
			else if(node->tanggungan >= 3){
				potongan = potongan + 13500000;
			}
			
			if(node->menikah == 1){
				potongan = potongan + 4500000;
			}
			PKP = node->gaji - potongan;
			if ( PKP > 0){
				if( PKP <= 50000000 ){
					node->PPh = PKP * 5/100;
				}	
				else if( PKP <= 250000000 && PKP > 50000000 ){
					node->PPh = PKP * 15/100;
				}
				else if( PKP <= 500000000 && PKP > 250000000){
					node->PPh = PKP * 25/100;
				}
				else if( PKP <= 500000000 ){
					node->PPh = PKP * 30/100;
				}
			}
			else if (PKP < 0) node->PPh = 0;
			
			node->PBB = node->NJOP / 1000;
			node->lanjut = head;
			head = node;
	}
	getchar();
}
// sudah aman
void savelist()
{
   int num;
   FILE *fptr;
   fptr = fopen("data.txt","w");
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
	struct wajibPajak *m = head;
   	int i;
   	while(m != NULL){
   		fprintf(fptr,"Nama = %s \n",m->nama);
		fprintf(fptr,"NPWP = %s \n",m->NPWP);
	   	fprintf(fptr,"Tanggungan = %d \n",m->tanggungan);
	   	fprintf(fptr,"Status = %d \n",m->menikah);
		fprintf(fptr,"gaji = %.2f \n",m->gaji);
	    fprintf(fptr,"PPh = %.2f \n",m->PPh);
	    fprintf(fptr,"PBB = %.2f \n",m->PBB);
		m = m->lanjut;
	}    
	fclose(fptr);
	printf("tekan apapun untuk melanjutkan.");
	getch();
}
//aman
int main(){
	char pilihan, nama[50];
	for(;;){
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("                                      ================================================\n");
		printf("                                      ||                                            ||\n");
		printf("                                      ||           Hitung Pajak                     ||\n");
		printf("                                      ||                                            ||\n");
		printf("                                      ||           [1] Lihat data                   ||\n");
		printf("                                      ||           [2] Masukan data baru            ||\n");
		printf("                                      ||           [3] Save Data                    ||\n");
		printf("                                      ||           [4] Hapus data                   ||\n");
		printf("                                      ||           [5] Cari data                    ||\n");
		printf("                                      ||           [6] Load data                    ||\n");
		printf("                                      ||           [7] Keluar                       ||\n");
		printf("                                      ||                                            ||\n");
		printf("                                      ================================================\n");
		printf("                                                    Pilihan anda: ");
		scanf("%s",&pilihan);
		switch(pilihan){
			case '1':{
				system("cls");
				lihatData();
				break;
			}
			case '2':{
				system("cls");
				insert();
				break;
			}
			case '3':{
				system("cls");
				savelist();
				break;
			}
			case '4':{
				system("cls");
				printf("Data atas nama siapa yang ingin dihapus?\n");
				scanf("%s",&nama);
				hapus(nama);
				break;
			}
			case '5':{
				system("cls");
				printf("Data atas nama siapa yang ingin dicari?\n");
				scanf("%s",&nama);
				cari(nama);
				break;
			}
			case '6': 
				system("cls");
				loadlist();
				break;
			case '7':
				return 0;
				break;
			default: 
			system("cls");
			printf("Input anda yang sebelumnya invalid!\n");
			printf("Tekan tombol apapun untuk melanjutkan\n");		
			getch();
		}
	}
}
