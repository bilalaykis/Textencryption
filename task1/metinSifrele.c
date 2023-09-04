#include <stdlib.h>
#include <stdio.h>
#include <time.h>

FILE *fp1;
FILE *fp2;
FILE *fp3;


int charToInt(char u)			//matrisin yazildigi metni okuyunca matrisin boyutlarini
{
	int num = 0;				//int deger olarak okumak icin bu fonksiyonu kullandik.

	num = u - '0';
	
	return num;
}


int main()
{
    int useless = 3;

    
    int i=0 , j=0 ,k=0 ;
	int m , n ,M1=0,N1=0;
	char matrisadi[50],buffer[50],metinadi[50],buffer1[50],sifrelidosyaadi[50];
    char matrisdizi[200], sifrelenmisMetin[10000],sifrelenecekMetin[10000] ;
    int  sayac=2,sayac1=0, sayac2=0,sayac1tut;
	printf("Matrisin yazildigi dosya ismini uzantisi ile birlikte veriniz\n");
    dosyaismi1(matrisadi);//dosyaismi1 fonksiyonu 76. satirdadir.
   
    matrisokuma(matrisdizi , buffer , sayac);
   //matrisokuma fonksiyonu 83. satirdadir.
    printf("Sifrelenecek metni iceren dosya ismini uzantisi ile birlikte veriniz \n");
    dosyaismi2(metinadi);//dosyaismi2 fonksiyonu 99. satirdadir.
    
    /*
	sifrelenecek metinokuma fonksiyonu hem sifrelenecek metni aliyor hem de sayac1'i return ediyor.
	sifrelenecekmetinokuma fonksiyonu 106. satirdadir.*/
    sayac1tut=sifrelenecekmetinokuma(buffer1, sifrelenecekMetin, sayac1 , m , n , matrisdizi );
    
	m = matrisdizi[0];		//Dizinin ilk 2 h�cresinde m ve n i tutmustuk.
    n = matrisdizi[1];
    
    M1 = charToInt(m);		//charToint fonksiyonu 10. satirdadir.
    N1 = charToInt(n);			
   
    char M[M1][N1];			//Matrise yer ayirdik.
    
    matrisolusturma( M1 , N1 , M , matrisdizi);//matrisolusturma fonksiyonu 122. satirdadir.
  
    
    metinsifreleme(sayac2,sayac1tut, M1 , N1 , sifrelenecekMetin, M ,  sifrelenmisMetin , useless );
   //metinsifreleme fonksiyonu 138. satirdadir.
	printf("Sifrelenmis metni icerecek dosya ismini uzantisi ile birlikte veriniz \n");
	dosyaismi3(sifrelidosyaadi); //dosyaismi3 fonksiyonu 162. satirdadir.
	
	
	for(i=0; i<sayac1tut; i++)
    {
        fprintf(fp3,"%d ",sifrelenmisMetin[i]) ;
	}
	
	
	fclose(fp1);
    fclose(fp2);
    fclose(fp3);
 
    printf("Sifreleme tamamlanmistir");
    return 0;
}


void dosyaismi1(char matrisadi[])
{
    scanf("%s",matrisadi);				//Matris adi aldik.
    fp1  = fopen(matrisadi , "r");
}


void matrisokuma(char matrisdizi[] , char buffer[] , int sayac)
{
	fscanf(fp1,"%c",buffer);			//dosyanin ilk iki karakterini ( m ve n ) 
    matrisdizi[0] = *buffer;			//dizi[0]ve dizi[1] de tuttuk.
    fscanf(fp1,"%c",buffer);
    matrisdizi[1] = *buffer;
    
    while (!feof(fp1))   				
    {
        fscanf(fp1,"%c",buffer);		//Matrisi dizide tuttuk.
        matrisdizi[sayac] = *buffer;
        sayac++;
    }
}


void dosyaismi2(char metinadi[] )
{ 
    scanf("%s",metinadi);
    fp2 = fopen(metinadi , "r");
}


int sifrelenecekmetinokuma(char buffer1[] , char sifrelenecekMetin[], int sayac1 , int m , int n , char matrisdizi[])
{
    fscanf(fp2,"%c",buffer1);
    sifrelenecekMetin[0] = *buffer1;
       
	while (!feof(fp2))   				//Sifrelenecek metni okuduk.
    {
        sayac1++;
		fscanf(fp2,"%c",buffer1);
        sifrelenecekMetin[sayac1] = *buffer1;   
    }

    return sayac1;
}
	
	
void matrisolusturma( int M1 , int N1 , char M[M1][N1] , char matrisdizi[])
{
	int i , j,k=2;						//matrisdizinin ilk iki h�cresinde m ve n degeri vardi o yuzden k=2 den basliyor.
	
    for(i=0; i<M1; i++)					
    {  
    	for(j=0; j<N1; j++)
    	{
    		M[i][j] = matrisdizi[k];	//matrisdizi'yi M[][] matrisine yerlestirdik.
    		k++;
		}
			k++;
	} 
}


void metinsifreleme(int sayac2,int sayac1tut, int M1 , int N1 , char sifrelenecekMetin[], char M[M1][N1], char sifrelenmisMetin[sayac2] , int useless )
{
	int i , j , k ;

    for(i=0; i<sayac1tut; i++)			//Bu for sifrelenecek metin uzunlugu kadar donuyor.
    {        							//Sifrelenecek metnin her bir elemaninin matrisin hangi hucresinde oldugunu
     	for(j=0; j<M1; j++)				//bulup sifreleme yapip cikis'a gidiyor.
    	{
            for(k=0; k<N1; k++)
            {
            	if(sifrelenecekMetin[i] == M[j][k])
			   {
			   	    sifrelenmisMetin[sayac2] = (j+1)*10 + (k+1);
		            sayac2++;
			   	    goto cikis;
			   }
            }	
		}		
		cikis:
		useless++;		
	} 
    
}

void dosyaismi3(char sifrelidosyaadi[])
{
    scanf("%s",sifrelidosyaadi);
    fp3 = fopen(sifrelidosyaadi, "w");
}



