#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_management.h"

void handleFileCreationError() {
    printf("\033[1;31mDosya oluşturulurken bir hata oluştu!\033[0m\n");
}

void handleFileDeletionError() {
    printf("\033[1;31mDosya silinirken bir hata oluştu!\033[0m\n");
}

void handleFileListError() {
    printf("\033[1;31mDosyalar listelenirken bir hata oluştu!\033[0m\n");
}

void handleFileContentError() {
    printf("\033[1;31mDosya içeriği görüntülenirken bir hata oluştu!\033[0m\n");
}

void createFile(File *files, int *fileCount) {
    if (*fileCount >= MAX_FILES) {
        printf("\033[1;31mMaksimum dosya sayısına ulaşıldı!\033[0m\n");
        return;
    }

    File newFile;
    printf("Dosya adını girin: ");
    scanf("%s", newFile.filename);
    if (strlen(newFile.filename) >= MAX_FILENAME_LENGTH) {
        printf("\033[1;31mDosya adı çok uzun!\033[0m\n");
        return;
    }

    printf("İçeriği girin: ");
    scanf("%s", newFile.content);
    if (strlen(newFile.content) >= MAX_CONTENT_LENGTH) {
        printf("\033[1;31mİçerik çok uzun!\033[0m\n");
        return;
    }

    files[*fileCount] = newFile;
    (*fileCount)++;

    printf("\033[1;32mDosya oluşturuldu!\033[0m\n");
}

void deleteFile(File *files, int *fileCount) {
    if (*fileCount == 0) {
        printf("\033[1;31mSilinecek dosya yok!\033[0m\n");
        return;
    }

    char filename[MAX_FILENAME_LENGTH];
    printf("Silinecek dosyanın adını girin: ");
    scanf("%s", filename);

    for (int i = 0; i < *fileCount; ++i) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("'%s' adlı dosyayı silmek istediğinizden emin misiniz? (E/H): ", filename);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'E' || confirm == 'e') {
                for (int j = i; j < *fileCount - 1; ++j) {
                    files[j] = files[j + 1];
                }
                (*fileCount)--;
                printf("\033[1;32mDosya silindi!\033[0m\n");
            } else {
                printf("\033[1;32mDosya silme işlemi iptal edildi.\033[0m\n");
            }
            return;
        }
    }

    printf("\033[1;31mDosya bulunamadı!\033[0m\n");
}

void listFiles(File *files, int fileCount) {
    if (fileCount == 0) {
        printf("\033[1;31mMevcut dosya yok!\033[0m\n");
        return;
    }
    printf("\033[1;32mMevcut dosyalar:\033[0m\n");
    for (int i = 0; i < fileCount; ++i) {
        printf("%s\n", files[i].filename);
    }
}

void showFileContent(File *files, int fileCount) {
    if (fileCount == 0) {
        printf("\033[1;31mMevcut dosya yok!\033[0m\n");
        return;
    }

    char filename[MAX_FILENAME_LENGTH];
    printf("İçeriğini görmek istediğiniz dosyanın adını girin: ");
    scanf("%s", filename);

    for (int i = 0; i < fileCount; ++i) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("\033[1;32mDosya İçeriği:\n%s\033[0m\n", files[i].content);
            return;
        }
    }

    printf("\033[1;31mBelirtilen dosya bulunamadı!\033[0m\n");
}

void createFileAtDesktop(File *files, int *fileCount) {
    if (*fileCount >= MAX_FILES) {
        printf("\033[1;31mMaksimum dosya sayısına ulaşıldı!\033[0m\n");
        return;
    }

    char desktop[MAX_FILENAME_LENGTH];
    #ifdef _WIN32
        sprintf(desktop, "%s\\Desktop", getenv("USERPROFILE"));
    #elif __linux__ || __APPLE__
        sprintf(desktop, "%s/Desktop", getenv("HOME"));
    #else
        printf("\033[1;31mBu işletim sistemi desteklenmiyor!\033[0m\n");
        return;
    #endif

    File newFile;
    printf("Dosya adını girin: ");
    scanf("%s", newFile.filename);
    if (strlen(newFile.filename) >= MAX_FILENAME_LENGTH) {
        printf("\033[1;31mDosya adı çok uzun!\033[0m\n");
        return;
    }

    printf("İçeriği girin: ");
    scanf("%s", newFile.content);
    if (strlen(newFile.content) >= MAX_CONTENT_LENGTH) {
        printf("\033[1;31mİçerik çok uzun!\033[0m\n");
        return;
    }

    char filepath[MAX_FILENAME_LENGTH + strlen(desktop) + 2];
    sprintf(filepath, "%s/%s", desktop, newFile.filename);

    FILE *fp = fopen(filepath, "w");
    if (fp == NULL) {
        handleFileCreationError();
        return;
    }

    fprintf(fp, "%s", newFile.content);
    fclose(fp);

    files[*fileCount] = newFile;
    (*fileCount)++;

    printf("\033[1;32mDosya oluşturuldu: %s\033[0m\n", filepath);
}

int main() {
    File files[MAX_FILES];
    int fileCount = 0;
    int choice;

    while (1) {
        printf("Dosya Yönetim Sistemi\n");
        printf("1. Dosya Oluştur (Masaüstü)\n");
        printf("2. Dosya Sil\n");
        printf("3. Dosyaları Listele\n");
        printf("4. Dosya İçeriğini Göster\n");
        printf("5. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFileAtDesktop(files, &fileCount);
                break;
            case 2:
                deleteFile(files, &fileCount);
                break;
            case 3:
                listFiles(files, fileCount);
                break;
            case 4:
                showFileContent(files, fileCount);
                break;
            case 5:
                printf("\033[1;32mProgramdan çıkılıyor...\033[0m\n");
                exit(0);
            default:
                printf("\033[1;31mGeçersiz seçenek!\033[0m\n");
        }
    }

    return 0;
}
