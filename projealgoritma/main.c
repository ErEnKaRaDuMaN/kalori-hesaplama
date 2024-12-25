#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

struct Yemek {
    char isim[MAX_SIZE];
    int kalori;
};

int main() {
    //Gerekli değerleri girelim
    struct Yemek yemekler[MAX_SIZE];
    char siparis[MAX_SIZE];
    int adet, toplam_kalori;
    FILE *kalori_dosyasi, *siparis_dosyasi;

    //Kalori dosyasını açalım
    kalori_dosyasi = fopen("C:\\Users\\90541\\Desktop\\kalori.txt", "r");
    if(kalori_dosyasi == NULL) {
        printf("Dosya bulunamadi!");
        return 1;
    }
    int i = 0;
    while (fscanf(kalori_dosyasi, "%s %d", yemekler[i].isim, &yemekler[i].kalori) != EOF) {
        i++;
    }
    fclose(kalori_dosyasi);

    //Sipariş dosyasını açalım ve toplam kalori hesabını yapalım
    siparis_dosyasi = fopen("C:\\Users\\90541\\Desktop\\siparis.txt", "r");
    if(siparis_dosyasi == NULL){
        printf("Siparis dosyası bulunamadı!")
            return 1;
            }
    while (fscanf(siparis_dosyasi, "%s %d", siparis, &adet) != EOF) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (strcmp(siparis, yemekler[j].isim) == 0) {
                toplam_kalori += yemekler[j].kalori * adet;
                break;
            }
        }
    }
    fclose(siparis_dosyasi);

    //Toplam kaloriyi ekrana yazdıralım
    printf("Toplam kalori: %d\n", toplam_kalori);
    return 0;
}
