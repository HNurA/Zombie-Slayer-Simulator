# sysprog23-lab10
**Zombie Slayer Simulator**


## Öğrenme hedefleri



* Concurrency


## Giriş

Birkaç arkadaşınız ile birlikte zombie istilasından bir binayı temizlemek istiyorsunuz. Ancak elinizde sadece 3 tane silah var, dolayısıyla sadece 3 kişi zombie öldürebiliyor.

Biraz düşündükten sonra şöyle bir plan uygulamaya karar veriyorsunuz:

Birden fazla girişi bulunan bir tane odayı zombielerden temizlemek için her bir arkadaşınız bir kapıda nöbet tutarak (her biri **doorman**), zombileri tek tek içeri alıyorlar ve içeri alınan zombilerin sayısını tutuyorlar. Elinizde 3 tane silah olduğu için sen ve 2 arkadaşın (**slayer**) giren zombileri öldürüyor. Ve toplamda kaç tane zombie öldürdüğünüzün ve her bir slayer kaç zombie öldürdüğünün sayısını tutuyorsunuz.

Eğer odadaki zombie sayısı 100 yada daha büyük olursa o zaman herkes ölüyor. Yine toplamda 100 tane zombie öldürürseniz o zaman sen ve arkadaşların güvende oluyorlar.

Bu ödevin maksadı, sen ve arkadaşların ölmeden 100 tane zombie öldürebilmeleri için  maksimum kaç tane doorman olabileceğini bulmak.


## Detaylar

Yukarıdaki zombie temizleme planını simule eden multıthred program yazmanız istenmektedir. Bu programda **3 tane slayer** thread ve kapı kontrolü yapan arkadaşların her birisi için doorman thread oluşturmanız gerekiyor. Ve aşağıdaki fonksiyonları thread synchronization ile implement etmeniz gerekiyor:



* <code>void zombieEntered()</code>:</strong> Giren zombilerin sayısını tutuyor (zombie counterın sayısını artırıyor). Eng: Keeps track of number of zombies entered.
* <strong><code>void zombieKilled()</code>:</strong> Öldürülen zombilerin sayısını artırıyor. Eng: Keeps track of number of zombies killed.
* <strong><code>int tooManyZombiesInTheRoom()</code>:</strong> Eğer zombie sayısı 100 yada daha fazla ise 1 diğer durumlarda 0 return ediyor: Eng: Returns <code>true</code> if the number of zombies in the room are greater than or equal to 100.
* <strong><code>int killed100Zombies()</code>: </strong>100 yada daha fazla zombie öldürüldüyse true(yani 1) return ediyor. Eng:<strong> </strong>Returns <code>true</code> if more than 100 zombies have been killed.
* <strong><code>int zombiesExist()</code>;</strong> En az bir zombie varsa 1 return ediyor. Yoksa 0. Eng: Returns <code>true</code> if there is at least one zombie in the room.
* <strong><code>int getKilledCount()</code>;</strong> Öldürülen zombie sayısını return ediyor. Eng: Returns the number of zombies killed.
* <strong><code>int getInTheRoomCount()</code>;</strong> Odadaki güncel zombie sayısını return ediyor. Eng: Returns the number of zombies in the room.

Birden fazla thread shared dataya eriştiği, dataya erişimi mutex vs ile senkronize etmeniz gerekmektedir. Doğru olmayan kısımlardan puan kırılacaktır.



* <code>void *doorMan(void *);</code></strong>

Herbir doorman threadi zombie <strong>her 2ms de bir</strong> zombie girmesine <strong>%50 ihtimalle</strong> izin vermektedir. Zombie girince gerekli fonksiyonları çağırarak <strong>zombiecounterı</strong> güncellemeniz gerekmektedir. Eğer çok fazla zombie varsa yani 100 yada üzerinde doorman threadi çalışmasını durdurmaktadır.



* <code>void *slayer(void *);</code></strong>

Slayer threadi <strong>her 2msde bir</strong> bir zombie öldürmektedir. Ve uygun fonksiyonları çağırarak öldürülen zombie sayısını ve zombiecounterı güncellemektedir. Yine eğer çok fazla zombie varsa bu thread çalışmasını bitirmektedir. 



* ``int main();``

Bu fonksiyon <code>n</code> tane <code>doorMan</code></strong> threadi (<strong>n</strong> burada komut satırı argümanı) ve <strong>3</strong> <strong>tane <code>slayer</code></strong> threadi oluşturmaktadır. Tüm threadlerin executionı bitince,



* 100 tane zombie öldürülüp öldürülmediğini  
* Ve her bir slayerın kaç tane zombie öldürdüğünü yazdırmaktadır.


#### Optimal doorman sayısı

Programı farklı doorman sayılarıyla çalıştırarak en büyük doorman sayısının (yani öldürülmeden 100 tane zombie öldürmek için) ne olduğunu bulunuz. 

**Teslim**

Submit zombie.c


## Derecelendirme

DoorMan: ~18%

Slayer: ~24%

Simulator (main): ~24%

The rest 34%
