#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[100];
    char password[10];
    int isMember = 0;
    int isSilver = 0;
    int isGold = 0;
    int isLenovo = 0;
    int isAsus = 0;
    int nYogaSlim7 = 0;
    int nIdeapad330 = 0;
    int nLegion7 = 0;
    int nVivobook14 = 0;
    int nM415 = 0;
    int nVivobook14A1402 = 0;
    int nTotal = 0;
    int nTotalBonusTas = 0;
    int nTotalBonusMouse = 0;
    int nTotalBonusFlasdisk = 0;
    int nPotonganHarga = 0;

    printf("Selamat datang di Toko Mbah Andi\n");
    printf("Silakan masukkan username dan password Anda untuk melanjutkan\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Check username and password
    if (strcmp(username, "NAMA LENGKAP") != 0 || strcmp(password, "NPM 5 DIGIT TERAKHIR") != 0) {
        printf("Username atau password salah. Program akan keluar.\n");
        return 0;
    }

    printf("Apakah Anda adalah member (Y/N)? ");
    char member[2];
    scanf("%s", member);
    if (strcmp(member, "Y") == 0) {
        isMember = 1;
        printf("Apakah Anda adalah member Silver atau Gold (S/G)? ");
        char membership[2];
        scanf("%s", membership);
        if (strcmp(membership, "S") == 0) {
            isSilver = 1;
        } else if (strcmp(membership, "G") == 0) {
            isGold = 1;
        }
    }

    printf("Apakah Anda ingin membeli laptop Lenovo (Y/N)? ");
    char lenovo[2];
    scanf("%s", lenovo);
    if (strcmp(lenovo, "Y") == 0) {
        isLenovo = 1;
        printf("Berapa banyak Lenovo Yoga Slim 7 yang ingin Anda beli? ");
        scanf("%d", &nYogaSlim7);
        printf("Berapa banyak Lenovo Ideapad 330 yang ingin Anda beli? ");
        scanf("%d", &nIdeapad330);
        printf("Berapa banyak Lenovo Legion 7-16ACHg6 yang ingin Anda beli? ");
        scanf("%d", &nLegion7);
    }

    printf("Apakah Anda ingin membeli laptop Asus (Y/N)? ");
    char asus[2];
    scanf("%s", asus);
    if (strcmp(asus, "Y") == 0) {
        isAsus = 1;
        printf("Berapa banyak Asus Vivobook 14 A416JA yang ingin Anda beli? ");
        scanf("%d", &nVivobook14);
        printf("Berapa banyak Asus M415 yang ingin Anda beli? ");
        scanf("%d", &nM415);
        printf("Berapa banyak Asus Vivobook 14(A1402) A1402ZA yang ingin Anda beli? ");
    }
        
        getch();
        return 0;

}