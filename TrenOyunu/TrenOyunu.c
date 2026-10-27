#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KIRMIZI "\033[1;31m"
#define NORMAL "\033[0m"
#define MAVI "\033[1;34m"
#define LACIVERT "\033[1;36m"
#define MOR "\033[1;35m"
#define PEMBE "\033[1;38;5;13m"  
#define YESIL "\033[1;32m"
#define SARI "\033[1;33m"
#define KAHVERENGI "\033[0;33m"   
#define GRI "\033[1;30m"    

typedef enum
{
    Pc,
    Oyuncu
} OyuncuSirasi;

char oyuncu1[50]; // Oyuncunun adi
OyuncuSirasi oyuncuSayiTutar = Pc; // Sayi tutma sirasi: 0 - Bilgisayar, 1 - Oyuncu

void oyuncuDegistir(OyuncuSirasi* oyuncuSayiTutar)
{
    if (*oyuncuSayiTutar == Pc)
    {
        *oyuncuSayiTutar = Oyuncu;
    }
    else
    {
        *oyuncuSayiTutar = Pc;
    }
    printf("Sira %s gecti.\n", (*oyuncuSayiTutar == Pc) ? "bilgisayara" : "sana");
}

void trenGuncelle(char tren[], int boyut, int sayi, char basharf, int* bulunacakSayilar)
{
    for (int i = 0; i < boyut; i++)
    {
        if (tren[i] == '0' + sayi)
        {


            tren[i] = basharf;

            (*bulunacakSayilar)--;
        }

    }


    printf(KAHVERENGI "\nGuncellenmis Tren: ");
    for (int i = 0; i < boyut; i++)
    {
        printf(" %c ", tren[i]);

    }
    printf("\n");



}

int tahminKontrol(int tahmin, int oncedengirilenler[], int index)
{
    for (int i = 0; i < index; i++)
    {
        if (oncedengirilenler[i] == tahmin)
        {
            return 1;
        }
    }
    return 0;
}


void oyuncuAdlariniAl()
{
    printf("1. oyuncunun adini girin: ");
    scanf_s("%49s", oyuncu1, (unsigned)_countof(oyuncu1));
}

void tahminsifirlama(int* tahminler, int* index)
{

    for (int i = 0; i < 6; i++)
    {
        tahminler[i] = 0;
    }
    *index = 0;
}

void oyun()
{
    int tahmin;
    int sayi;
    int hak;
    char tren[5] = { '1', '2', '3', '4', '5' };
    char basharf = oyuncu1[0];
    int bulunacakSayilar = 5;
    int tahmingecmisioyuncu1[100] = { 0 };
    int tahmingecmisipc[100] = { 0 };
    int oncedengirilenler[100] = { 0 };
    int index = 0;
    int tursayaci = 0;
    int dogruTahminler[5] = { 0 };
    int dogruTahminIndex = 0;
    int oyuncuPaun = 0;
    int bilgisayarPuan = 0;

    printf("\nOyuna hos geldin, %s\n", oyuncu1);
    // Lokomotifin üst kısmı
    printf(MAVI"    -----    ");
    printf(MAVI"------  -------   -------   -------   ----------    ");
    printf("       ");
    printf("    ");
    printf("    ");
    printf(" \n");

    // Lokomotifin orta kısmı
    printf(MAVI "  _| [] |_  ");
    printf(MAVI "|     | | ");
    printf(MAVI "      | | ");
    printf(MAVI "      | | ");
    printf(MAVI "      | | ");
    printf(MAVI "      | | \n");

    // Vagonların numaraları
    printf(LACIVERT " |_____|  ");
    printf(LACIVERT "|__ 1 __| ");
    printf(LACIVERT "|__ 2 __| ");
    printf(LACIVERT "|__ 3 __| ");
    printf(LACIVERT "|__ 4 __| ");
    printf(LACIVERT "|__ 5 __| | \n");

    // Tekerlek kısmı
    printf(KAHVERENGI "   O O O   ");
    printf(KAHVERENGI " O     O  ");
    printf(KAHVERENGI " O     O  ");
    printf(KAHVERENGI " O     O  ");
    printf(KAHVERENGI " O     O  ");
    printf(KAHVERENGI " O     O  \n");


    printf("\nTren: 1   2   3   4   5\n\n");




    while (bulunacakSayilar > 0)
    {
        srand((unsigned)time(NULL));
        hak = 1;
        tahminsifirlama(oncedengirilenler, &index);

        if (oyuncuSayiTutar == Pc)
        {
            tursayaci++;
            printf(MOR "\n--------------------- %d. Turdasiniz.--------------------- \n", tursayaci);
            tahminsifirlama(oncedengirilenler, &index);
            do
            {
                sayi = rand() % 5 + 1;
            } while (tahminKontrol(sayi, oncedengirilenler, index) || tahminKontrol(sayi, dogruTahminler, dogruTahminIndex));

            printf("\nBilgisayar bir sayi tuttu.\n");

            while (hak > 0)
            {



                printf(YESIL "Hak sayisi: %d\n\n", hak);
                printf("--------------------------------Tahmininizi girin: ");

                if (scanf_s("%d", &tahmin) != 1 || tahmin < 1 || tahmin > 5)
                {
                    printf(KIRMIZI "Hatali sayi girdiniz. \n");
                    printf("Lutfen 1 ile 5 arasinda bir sayi girin: \n");
                    while (getchar() != '\n');
                    continue;
                }

                else
                {
                    if (tahminKontrol(tahmin, oncedengirilenler, index)
                        || tahminKontrol(tahmin, dogruTahminler, dogruTahminIndex))
                    {

                        printf("Bu sayi daha once tahmin edildi.\n");
                        hak++;
                        printf("Lutfen yeni bir sayi giriniz.\n");
                    }
                    else
                    {
                        oncedengirilenler[index++] = tahmin;
                        if (tahmin == sayi)
                        {

                            printf(MAVI "TEBRIKLER :) DOGRU TAHMIN !\nBilgisayarin tuttugu sayi: %d\n", sayi);

                            trenGuncelle(tren, 5, sayi, basharf, &bulunacakSayilar);


                            dogruTahminler[dogruTahminIndex++] = sayi;
                            oyuncuPaun++;

                            oyuncuDegistir(&oyuncuSayiTutar);
                            hak = 0;

                        }
                        else
                        {
                            printf(KIRMIZI "MALESEF, YANLIS TAHMIN ! \n");

                        }
                    }
                }

                hak--;

                if (hak == 0 && tahmin != sayi)
                {
                    printf(KIRMIZI"\nTAHMIN HAKLARINIZ BITTI :( . \n");
                    printf(GRI"Bilgisayarin tuttugu sayi: %d\n", sayi);
                    oyuncuDegistir(&oyuncuSayiTutar);
                }
            }
        }


        else
        {
            int bilgisayarTahminleri[100] = { 0 };
            int bilgisayarIndex = 0;

            tahminsifirlama(oncedengirilenler, &index);
            tahminsifirlama(bilgisayarTahminleri, &bilgisayarIndex);
            printf(PEMBE"----------------------------------------------------------");
            printf(PEMBE"\nSira sizde bir sayi tutun (1-5 arasinda):");
            hak = 1;

            do
            {


                if (scanf_s("%d", &sayi) != 1)
                {
                    printf(KIRMIZI "Hatali sayi girdiniz.\n");
                    while (getchar() != '\n');
                    hak++;
                    continue;
                }

                if (sayi < 1 || sayi > 5 || tahminKontrol(sayi, bilgisayarTahminleri, bilgisayarIndex)
                    || tahminKontrol(sayi, dogruTahminler, dogruTahminIndex))
                {
                    printf(KIRMIZI "Hatali sayi girdiniz.\n");
                    hak++;
                    printf("Lutfen kontrol edip tekrar deneyiniz:\n");
                }

            } while (sayi < 1 || sayi > 5 || tahminKontrol(sayi, bilgisayarTahminleri, bilgisayarIndex)
                || tahminKontrol(sayi, dogruTahminler, dogruTahminIndex));



            while (hak > 0)
            {
                do
                {
                    tahmin = rand() % 5 + 1; // Bilgisayarın tahmini

                } while (tahminKontrol(tahmin, bilgisayarTahminleri, bilgisayarIndex)
                    || tahminKontrol(tahmin, dogruTahminler, dogruTahminIndex));


                bilgisayarTahminleri[bilgisayarIndex++] = tahmin;
                printf("--------------------------------Bilgisayarin tahmini: -> %d <- \n", tahmin);

                if (tahmin == sayi)
                {

                    printf(MAVI "Bilgisayar dogru bildi!\n");
                    trenGuncelle(tren, 5, sayi, 'X', &bulunacakSayilar);
                    dogruTahminler[dogruTahminIndex++] = sayi;

                    bilgisayarPuan++;
                    oyuncuDegistir(&oyuncuSayiTutar);
                    break;
                }
                else
                {
                    hak--;
                    if (hak > 0)
                    {
                        printf(KIRMIZI "Bilgisayar yanlis tahmin etti.\n");
                        printf(GRI"Bilgisayar tekrar deniyor...\n");
                        printf("Gormek icin Enter'a basin.\n");
                        getchar();
                        getchar();
                    }
                    else
                    {
                        printf(KIRMIZI "Bilgisayar tahmin hakkini bitirdi.\n");
                        printf("Devam etmek icin Enter'a basin.\n");
                        getchar();
                        getchar();


                        oyuncuDegistir(&oyuncuSayiTutar);
                        break;
                    }
                }
            }
        }
    }

    printf(MAVI "\nTum tren vagonlari bulundu! Oyun sona erdi.\n");

    if (oyuncuPaun > bilgisayarPuan)
    {
        printf(PEMBE "******************************* Kazanan %s :)) ******************************* \n \n", oyuncu1);
        printf("%s kazandigi icin trenin tum vagonlari onun oldu. \n \n ", oyuncu1);


        printf(MAVI "    -----    ");
        printf(MAVI "------  ---------   ---------   ---------   ------------    ");
        printf("       ");
        printf("    ");
        printf("    ");
        printf(" \n");

        // Lokomotifin orta kısmı
        printf(MAVI "  _| [] |_  ");
        printf(MAVI "|       | | ");
        printf(MAVI "        | | ");
        printf(MAVI "        | | ");
        printf(MAVI "        | | ");
        printf(MAVI "        | | \n");

        // Vagonların numaraları
        printf(LACIVERT " |_____|  ");
        printf(LACIVERT "|__ %s __| ", oyuncu1);
        printf(LACIVERT "|__ %s __| ", oyuncu1);
        printf(LACIVERT "|__ %s __| ", oyuncu1);
        printf(LACIVERT "|__ %s __| ", oyuncu1);
        printf(LACIVERT "|__ %s __| | \n", oyuncu1);

        // Tekerlek kısmı
        printf(KAHVERENGI "   O O O   ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  \n");

        printf("TEBRIKLER %s\n\n\n\n\n ", oyuncu1);

    }


    else
    {
        printf(PEMBE "******************************* Kazanan Bilgisayar :)) ******************************* \n \n ");

        printf("Bilgisayar kazandigi icin trenin tum vagonlari onun oldu.\n\n ");


        printf(MAVI "    -----    ");
        printf(MAVI "------------  ---------------   ---------------   ---------------   ------------------    ");
        printf("       ");
        printf("    ");
        printf("    ");
        printf(" \n");

        // Lokomotifin orta kısmı
        printf(MAVI "  _| [] |_  ");
        printf(MAVI "|         | | ");
        printf(MAVI "          | | ");
        printf(MAVI "          | | ");
        printf(MAVI "          | | ");
        printf(MAVI "          | | \n");

        // Vagonların numaraları
        printf(LACIVERT " |_____|  ");
        printf(LACIVERT "|__ Bilgisayar __| ");
        printf(LACIVERT "|__ Bilgisayar __| ");
        printf(LACIVERT "|__ Bilgisayar __| ");
        printf(LACIVERT "|__ Bilgisayar __| ");
        printf(LACIVERT "|__ Bilgisayar__| | \n");

        // Tekerlek kısmı
        printf(KAHVERENGI "   O O O   ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  ");
        printf(KAHVERENGI " O     O  \n");

        printf("TEBRIKLER Bilgisayar \n\n\n\n\n");
    }
    getch();
}



void clearScreen() {
    system("cls");
}

int main()
{
    printf(KIRMIZI "-  KURALLAR :\n");
    printf("1. Bu oyun sadece 1 oyuncu ve bilgisayar ile oynanabilir.\n");
    printf("2. Oyuncu, bilgisayara karsi bir sayi tutar ve bilgisayar bu sayiyi tahmin etmeye calisir.\n");
    printf("3. Bilgisayar da oyuncuya karsi bir sayi tutar ve oyuncu bu sayiyi tahmin etmeye calisir.\n");
    printf("4. Her dogru tahmin ile bir tren vagonu kazanilir.\n");
    printf("5. Her oyuncunun 1 tahmin hakki vardir.\n");
    printf("6. Oyuncu veya bilgisayar dogru tahmin ettiginde, tren vagonu kazanir.\n");
    printf("7. Oyunun amaci, mumkun olan en cok tren vagonunu kazanmaktir.\n");
    printf("8. Oyun, tum tren vagonlari (5 vagon) doldugunda sona erer.\n");
    printf("9. Oyun sonunda en cok vagon sahibi olan taraf tum vagonlara sahip olur.\n\n");
    printf(NORMAL);


    printf("OYUNA BASLAMAK ICIN ENTER'A BASIN!\n");
    getchar();
    clearScreen();

    oyuncuAdlariniAl();
    oyun();

    return 0;
}
