Task-1
run step by step.
Matris oluştur kodunda amaç alfabenin karışık bir şekilde bulunduğu matris üretip 
dosyaya yazdırmak. Metin şifrele kodunda amaç matris dosyasının ilk iki karakterinde m ve 
n sayılarını (matrisin boyutları) tutuyorduk. Matris dosyasını açıp içindekileri matrisdizi[ ] de 
tutuyoruz. Sonra for döngülerini m ve n kadar döndürerek M[] [] matrisine matrisdizi[] ‘yi
yerleştiriyoruz. Şifrelenecek metni okurken dosyadan okuduğumuz karakterleri 
sifrelenecekmetin[]’ de tutuyoruz. For döngüleri kullanarak sifrelenecek metinin her hücresini 
teker teker M matrisinin hangi hücresine eşit olduğunu buluyoruz (j+1)*10 + (k+1) işlemiyle 
şifreleyip sifrelenmismetin[]’ de tutuyoruz. Şifrelenmiş metini dosyaya yazdırıyoruz. Metin
şifre çözme kodunda matrisin bulunduğu dosyayı dizi[]’ de tutuyoruz. For döngüleri 
kullanarak M[] [] matrisi oluşturup onun içine dizi[] elemanlarını yerleştiriyoruz. Şifreli metni 
sifrelidizi[] ‘de tutuyoruz. Şifreli dizi elemanlarını teker teker ele alarak örneğin ilk elemanı 
25 olsun. 25in mod 10 ‘daki değeri (-1)=j olur. 25/10=(i – 1) diyoruz ve böylece i int değer 
olduğu için tamsayı çıkıyor. M[i] [j] de bulunan harfi sifresiz[] dizisine yerleştiriyoruz. 
Sifresiz[] dizisi artık şifresi çözülmüş metni içeriyor. Sifresiz[] dizisini istenilen dosyaya 
yazıyoruz.