#include <time.h>
#include <stdlib.h>
#include <stdio.h>


FILE *fp;
int m , n;

int main()
{
    int i,j,k=0,dizisay=2;
    char alfabedizi[100];
    
    printf("Matrisin yazilacagi dosya ismini uzantisi ile birlikte veriniz\n");
    dosyaismialma();				
   
    printf("Matrisin satir ve sutun sayilarini ayni sira ile veriniz\n"); 
    scanf("%d %d",&m,&n);
    
    kontrol(m,n);					

    char matris[m][n];
	
	matrisolustur(alfabedizi,	matris);
   
    karistirma(m,n,matris);			
    
    dosyayamatrisYazma(m , n , matris);
    printf("Sifre matrisi dosyasi olusturuldu..");

    return 0;
}

void dosyaismialma()
{
    char buffer[75];
    
    scanf("%s",buffer);
    fp = fopen(buffer , "w");
}


void kontrol(int m, int n)
{
	yeniden: ;
	int kontrol = m*n;

	if(kontrol<54)
    {
        printf("Matris en az 54 hucreli olmalidir.Lutfen yeniden giriniz.\n");
        scanf("%d %d",&m,&n);
    	goto yeniden;
    }
    else if(kontrol>81)
    {
        printf("Matris en cok 81 hucreli olmalidir.Lutfen yeniden giriniz.\n");
        scanf("%d %d",&m,&n);
 		goto yeniden;
    }
}


void   matrisolustur(char alfabedizi[100],	char matris[m][n])
   {
   	 
   	int i,j,k=0,dizisay=1;
   	alfabedizi[0]=46;		
   	alfabedizi[1]=32;		
   	
	for(i=65;i<91;i++)
	{
	   	dizisay++ ;
	   	alfabedizi[dizisay]=i ;//ascii tablosundan yarrarlanarak alfabeyi dizide tuttuk.	 
	}
	for(i=97;i<123;i++)
	{
		dizisay++ ;
		alfabedizi[dizisay]=i ;	
	}
	for(i=dizisay+1;i<m*n+1;i++)//dizinin bos kalacak kisimlarina 0 yerlestirdik.
	{
		alfabedizi[i]=0;
	}

	for(i=0;i<m;i++)		    //89.satirda ic ice iki for dongusu ile matrise yerlestirdik.
	{
		for(j=0;j<n;j++)
		{
			matris[i][j]=alfabedizi[k]; 
			k++;
		}
	}
	
   }


void karistirma(int m, int n , char matris[m][n])
{
 	int temp , a , b, c, d , i , j;//burayi sizin dersteki onerinizden yararlanarak yaptik.
 	srand(time(NULL));   

    for(i=0;i<100;i++)
    {
        
		a=(rand()%(m));           //rastgele matrisin iki hucresine erisip degerlerini degistirdik. 
        b=(rand()%(n));
        c=(rand()%(m));
        d=(rand()%(n));
       
	    temp=matris[a][b];
        matris[a][b]=matris[c][d];
        matris[c][d]=temp;
    }
}


void dosyayamatrisYazma(int m ,int n ,char matris[m][n])
{
	int i , j;  
	fprintf(fp,"%d", m);      			//ilk iki karakter matrisin satir ve sutun sayisini tutuyor.
	fprintf(fp,"%d", n);				//sonra matrisi dosyaya yaziyoruz.
	
	for(i=0; i < m; i++)
    {
        for(j = 0; j<n; j++)
        {
            fprintf(fp,"%c", matris[i][j]);
        }
        fprintf(fp,"\n");
    }

    fclose(fp);							//dosyayi kapatiyoruz.
}



