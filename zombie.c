/**thread kullanarak bir "zombie slayer" simülatörü oluşturma
* author: Hilal Nur Albayrak 22120205056
* last update: 02.05.2024
* Optimal doorman sayısı: Farklı inputlarla kod çalıştırıldı. Maksimum 12
* değeri elde edildi.
*/

/**
* zombie.c zombie slayer simulator:
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void zombieEntered();
void zombieKilled();
int tooManyZombiesInTheRoom();
int killed100Zombies();
int zombiesExist();
int getKilledCount();
int getInTheRoomCount();

/*number of zombies in the game: 
you should synchronize threads editing this variable
*/
int zombieCounter;
int zombieKill;

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

/* Keeps track of number of zombies entered.*/
void zombieEntered(){
    pthread_mutex_lock(&mutex2);
    zombieCounter++;
    pthread_mutex_unlock(&mutex2);
}

/* Keeps track of number of zombies killed.*/
void zombieKilled(){
    pthread_mutex_lock(&mutex1);
    if(zombiesExist()){
        zombieKill++;
        zombieCounter--;
    }
    pthread_mutex_unlock(&mutex1);
}

/* Returns true if number of zombies in the room are 
greater than or equal to 100.*/
int tooManyZombiesInTheRoom(){
    if(getInTheRoomCount() >= 100){
        return 1;
    }
    return 0;
}

/*Returns true if more than 100 zombies have been killed.*/
int killed100Zombies(){
    if(zombieKill >= 100){
        return 1;
    }
    return 0;
}

/* Returns true if there is at least one zombies in the room.*/
int zombiesExist(){
    if(zombieCounter > 0){
        return 1;
    }
    return 0;
}

/*Returns the number of zombies killed.*/
int getKilledCount(){
    return zombieKill;
}

/* Returns the number of zombies in the room.*/
int getInTheRoomCount(){
    return zombieCounter;
}

/*doorman thread*/
void *doorMan(void *p) {
    srand(time(NULL));
    while ((!killed100Zombies()) && (!tooManyZombiesInTheRoom())) {
        /*Rastgele sayı üret*/
        int random_number = rand() % 2;

        /*Eğer random_number 1 ise zombieCounter'ı artır*/
        if (random_number == 1) {
            zombieEntered();
        }

        if(getInTheRoomCount() > 100){
            pthread_cancel(pthread_self()); /*İş parçacığını sonlandır*/
            return NULL;
        }

        /*2 milisaniye bekle*/
        usleep(2000);
    }

    return NULL;
}

/*slayer thread*/
void *slayer(void *p){
    int zombieNo = 0;
    while((!killed100Zombies()) && (!tooManyZombiesInTheRoom())) {
        if(zombiesExist()) {
            zombieKilled();
            zombieNo ++;
        }
        usleep(2000);
    }
    printf("%lu killed %d zombie\n", pthread_self(), zombieNo);
    pthread_cancel(pthread_self()); /* İş parçacığını sonlandır */
    return NULL;
}

/*simulator main thread*/
int main(int argc, char **argv){
    int doorMan_num;
    printf("Doorman sayisini giriniz: ");
    scanf("%d", &doorMan_num);
    pthread_t slayer1;
    pthread_t slayer2;
    pthread_t slayer3;
    pthread_t doorManThreads[doorMan_num];

    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    /*DoorMan threadleri oluştur*/
    for (int i = 0; i < doorMan_num; i++) {
        pthread_create(&doorManThreads[i], NULL, doorMan, NULL);
    }
    pthread_create(&slayer1, NULL, slayer, NULL);
    pthread_create(&slayer2, NULL, slayer, NULL);
    pthread_create(&slayer3, NULL, slayer, NULL);

    /*Tüm DoorMan threadlerini bekleyin*/
    for (int i = 0; i < doorMan_num; i++) {
        pthread_join(doorManThreads[i], NULL);
    }
    pthread_join(slayer1, NULL);
    pthread_join(slayer2, NULL);
    pthread_join(slayer3, NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    if(killed100Zombies()){
        printf("You WIN!");
    }
    if(tooManyZombiesInTheRoom()){
        printf("Game OVER!");
    }
    
    return 0;
}
