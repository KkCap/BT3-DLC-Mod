#ifndef __AFS_H__
#define __AFS_H__

#include "types.h"
#include "common.h"

#define EMPTY_AFS_FILE_SIZE    16

#define Afs struct AfsDescriptor

struct AfsEntry {
    uint32_t offset;
    uint32_t size;
};

struct AfsDescriptor {
    int32_t fd;
    uint32_t fileCount;
    struct AfsEntry* entries;
};

/**
 * Apre un AFS e restituisce un puntatore alla struttura dati che lo descrive
 */
Afs* afsOpen(const char* path);

/**
 * Chiude un AFS identificato dalla struttura dati che lo descrive (Afs* afs)
 */
void afsCloseAndFree(Afs* afs);

/**
 * Restituisce il file descriptor dell'AFS già posizionato all'offset del file specificato da
 * fileIndex
 */
int32_t afsSeekTo(Afs* afs, const uint32_t fileIndex);

/**
 * Restituisce la dimensione del file all'interno dell'AFS specificato da fileIndex
 */
uint32_t afsGetFileSize(Afs* afs, const uint32_t fileIndex);

/**
 * Return the number of files inside the AFS
 */
uint32_t afsFileCount(Afs* afs);

#endif
