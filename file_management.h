#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#define MAX_FILENAME_LENGTH 50
#define MAX_CONTENT_LENGTH 1000
#define MAX_FILES 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} File;

void createFile(File *files, int *fileCount);
void deleteFile(File *files, int *fileCount);
void listFiles(File *files, int fileCount);
void handleError(int errorCode);
void createFileAtDesktop(File *files, int *fileCount);

#endif /* FILE_MANAGEMENT_H */
