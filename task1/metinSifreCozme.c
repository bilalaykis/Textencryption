#include <stdlib.h>
#include <stdio.h>
#include <time.h>

FILE *fp2;
FILE *fp3;
FILE *fp1;


	int charToInt(char u)		//matrisin yazildigi metni okuyunca matrisin boyutlarini, 	
	{							//ornegin 9*9 ,int deger olarak tuttuk.
	int num = 0;				
	num = u - '0';

	return num;
	}

int main()
{
	int i,j,k,m,n;
	int sifrelidizi[1000];
	int sayac = 2,sayac2=0, degisken=0,M1=0 , N1=0;
    char matrisadi[50],buffer1[50],sifrelenmis[50],buffer3[50],desifrelenmis[50],dizi[200];
    
    printf("Matrisin yazildigi dosya ismini uzantisi ile birlikte veriniz\n");
    dosyaismi1(matrisadi);					
    
    matrisokuma(buffer1 , dizi , sayac);	
	
	printf("Sifrelenmis metni iceren dosya ismini uzantisi ile birlikte veriniz \n");
	dosyaismi2(sifrelenmis);				
    
    m= dizi[0];								
    n= dizi[1];

    M1 =charToInt(m);						// fonksiyon sayesinde int degere dondurduk.
    N1 =charToInt(n);

	fscanf(fp2,"%d",buffer3);
    sifrelidizi[sayac2] = *buffer3;			//sifrelenmis dosyadan karakterleri okuyup 
											//sifrelidizinin icine yaziyoruz.
    while (!feof(fp2))  					
    {
    	sayac2++;
        fscanf(fp2,"%d",buffer3);			//sifrelenmis dosyadan karakterleri okuyup 
        sifrelidizi[sayac2] = *buffer3;		//sifrelidizinin icine yaziyoruz.
	}
    
    char M[M1][N1];							//Matrisi initialize ettik.
    
    matrisolustur( M1 , N1 , dizi , M );	//matrisolustur fonksiyonu 116.satirdadir.

	char sifresiz[sayac2];
	int t=0;

	for(k=0;k<sayac2;k++)
	{
		j=sifrelidizi[k]%10-1;				//sifreli diziden degerleri okuyup mod alarak matristeki
		i=sifrelidizi[k]/10-1;				//yerini buluyoruz.
		sifresiz[t]=M[i][j];
		t++;								//t sifresiz dizisinin sayaci.
	}
	
	
	printf("Sifresi cozulmus metni icerecek dosya ismini uzantisi ile birlikte veriniz \n");
	dosyaismi3(desifrelenmis);				//dosyaismi3 fonksiyonu 130.satirdadir.
	
	
	 for(i=0; i<t; i++)
    {
        fprintf(fp3,"%c",sifresiz[i]) ;		//Sifresi çozulmus metni dosyaya yaziyoruz.
	}
	
	
	fclose(fp1);				   			 //dosyalari kapatiyoruz.
    fclose(fp2);
    fclose(fp3);
 
    printf("Sifre cozme tamamlanmistir\n");
	
	return 0;
}


void dosyaismi1(char matrisadi[])
{
    scanf("%s",matrisadi);
    fp1  = fopen(matrisadi , "r");
}


void matrisokuma(char buffer1[] , char dizi[] , int sayac)
{
	fscanf(fp1,"%c",buffer1);		//matrisin boyutlarini dizi[0]ve dizi[1] de tutuyoruz.
    dizi[0] = *buffer1;
   
    fscanf(fp1,"%c",buffer1);
    dizi[1] = *buffer1;
    
    while (!feof(fp1))   
    {
        fscanf(fp1,"%c",buffer1);	//matrisi dizide tutuyoruz.
        dizi[sayac] = *buffer1;
        sayac++;
	}
}


void dosyaismi2(char sifrelenmis[])
{
	
 	scanf("%s",sifrelenmis);
    fp2 = fopen(sifrelenmis , "r");
}

void matrisolustur(int M1 , int N1 , char dizi[], char M[M1][N1])
{
	int sayac3 = 2 , i , j;		//sayac3'u 2 den baslatiyoruz cunku dizinin ilk iki hucresinde 
    for(i=0; i<M1; i++)			//matrisin boyutlari var.
    {  
    	for(j=0; j<N1; j++)
    	{
    		M[i][j] = dizi[sayac3];//dizi[]'yi kullanarak M matrisini olusturuyoruz.
    		sayac3++;
		}
		sayac3++;
	}
}

	void dosyaismi3(char desifrelenmis[] )
	{
	
    scanf("%s",desifrelenmis);
    fp3 = fopen(desifrelenmis , "w");//sifresi cozulmus metni dosyaya yazdiriyoruz.
       
   
}



