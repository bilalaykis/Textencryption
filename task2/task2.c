#include <stdio.h>  
#include <stdlib.h>

int main()
{
    char dizi[10000];
    int  sayac=0;
    int  sutunsay;
    int  i,j,s=0;
	int restart=1;
    while (restart=="1") {	
		puts("Bir Metin Giriniz (Ornek : Merhaba Dunya) : ");
		gets(dizi);

		while(dizi[sayac] != '\0')			    
			sayac++;

		sutunsay = sutunsayma(&sayac);			  
		char matris[3][sutunsay];
	
		matrisolustur(sutunsay,matris,sayac,dizi);

		char sifrelimetin[3*sutunsay];			  

		metinsifrele(sutunsay,matris,sifrelimetin,&s);

		
		for(i=0;i<s;i++)						
		{
			printf("%c",sifrelimetin[i]);
		}
		printf("\n");
		
		
		char sifrelimetin1[10000];
		int sayac2=0;
		int d=0,temp;										
		int sutunsay1;
		
		puts("sifreli metni giriniz\n");
		gets(sifrelimetin1);
		
		while(sifrelimetin1[sayac2] != '\0')				
			sayac2++;
		
		sutunsay1=sutunsayma(&sayac2);		

		char sifrelimatris[3][sutunsay1];

		cozummatrisolustur(sutunsay1,sifrelimatris,sifrelimetin);

		char sifrecoz1[sayac2+2];						
		sifrecoz(sutunsay1,sifrelimatris,sifrecoz1,&d );
														
		if(sayac2%3==0)									
		{
			sifrecoz1[sayac2]=32;						
			sifrecoz1[sayac2+1]=32;						
		}												
														
		for(i=0;i<sayac2+2;i++)
		{
			printf("%c",sifrecoz1[i]);	
		}
		
		puts("Devam etmek icin 1 e basiniz\n");
		gets(restart);
    }

    return 0;
 	}







  
   int sutunsayma(int *sayac1)
	{
	int sutunsay;					//Sifre olusturacagimiz matrisin satir sayisi 3 oldugu icin
										//3'e boluyoruz,eger tam bolunemiyorsa sutun sayisina 1 ekliyoruz.
		if((*sayac1)%3==0)
		{
			sutunsay=((*sayac1)/3);
		}
		else
		{
			sutunsay=((*sayac1)/3)+1;
		}
		return sutunsay;
	}

  
  
  	void matrisolustur(int sutunsay,char matris[3][sutunsay],int sayac,char dizi[sayac])
 	{
 	int  i,j,bas=0,artim=1,donus;
 	    for(j=0;j<sutunsay;j++)
		{
			donus=0;							//Matrisin [0][0] hucresine sifrelenecek metnin son 
			for(i=bas;donus<=2;i=i+artim)		//karakterini koyuyoruz.Sondan bir onceki karakterini de
			{									//Matrisin [1][0] hucresine koyuyoruz.Yilan seklinde kivrilarak
				matris[i][j]=dizi[sayac-1];		//metnin basina kadar devam ediyoruz.
				sayac--;
				donus++;
			}
			artim=-artim;
			bas=2-bas;

		}
 	}
 
 
	matrisyazdir(int sutunsay,char matris[3][sutunsay])
    {
 	int i,j;	
		 for (i=0;i<3;i++)
    	{
    		for (j=0;j<sutunsay;j++)
    			printf("%c ",matris[i][j]);
    	printf("\n");
		}
 	} 

 
 	void metinsifrele(int sutunsay,char matris[3][sutunsay],char sifrelimetin[],int *s)
	{
	int i,j;
	int* ip;	
		for (i=0;i<3;i++)
    	{
    		for (j=0;j<sutunsay;j++)
    		{
    			ip=&matris[i][j];				//ip de matris[i][j]'nin adresini tuttuk 
    			sifrelimetin[*s]=*ip;			//sifrelimetin[]'e yerlestirdik.
    			(*s)++;							//	's' sifreli metnin uzunlugunu tutuyor.
    		}
    	
		}
	
	}


	void cozummatrisolustur(int sutunsay1,char sifrelimatris[3][sutunsay1],char sifrelimetin[])
	{
	int i,j,t=0;
		for(i=0;i<3;i++)
 		{
			for(j=0;j<sutunsay1;j++)				//Sifrele teknigimizde matrisi matris[0][0] dan baslayip   
			{										//soldan saga dogru dizide tutarak yazdirdigimiz icin j
				sifrelimatris[i][j]=sifrelimetin[t];//sutunsay1 kadar donuyor.
				t++;
			}
		}
	}
 
 
   sifrecoz(int sutunsay1,char sifrelimatris[3][sutunsay1],char sifrecoz1[],int *d )
   {
	int i,j;											
	int artim=1,donus=0,bas=0;								
	int* ip;
	
	if(sutunsay1%2==0)		//Sifreleme islemine matrisin sol ustunden basladigimiz icin
	{						//eger matrisin sutun sayisi cift ise metnin ilk karakteri matrisin sag ust
		bas=0;				//kosesinde kaliyor,eger sutun sayisi tek ise metnin ilk karakteri matrisin sag alt 
	}						//kosesinde kaliyor biz de bunu kontrol ederek bas ve artim'i degistirdik.
	
	else
	{
		bas=2;
		artim=-artim;
	}
	
	for(j=sutunsay1-1;j>=0;j--)
	{
	donus=0;
		for(i=bas;donus<=2;i=i+artim)
		{
			sifrecoz1[*d]=sifrelimatris[i][j];
			ip=&sifrelimatris[i][j];				//ip de sifrelimatris[i][j]'nin adresini tuttuk 
    		sifrecoz1[*d]=*ip;						//sifrecoz1[]'e yerlestirdik.
    		(*d)++;									
			donus++;	
		}
	artim=-artim;
	bas=2-bas;
	}
	
	
}


