#include "afs.h"
#include "plt.h"

char failedToOpenAfs[] DATA_SECTION = "Failed to open AFS: %s\n";
char afsLoaded[] DATA_SECTION = "Afs %s loaded. File count: %d, AFS size: %d\n";

Afs* afsOpen(const char* path) {
    Afs* afsDescriptor = (Afs*)alloc(sizeof(Afs),0x20,0,2);
    int32_t fd = open(path, 4, 0);
    afsDescriptor->fd = fd;
    if(fd < 0) {
        print(failedToOpenAfs, path);
        free(afsDescriptor);
        return 0;
    }
    seek(fd, 4, SEEK_SET);
    read(fd, &(afsDescriptor->fileCount), 4);
    uint32_t readSize = 8*(afsDescriptor->fileCount + 1);
    afsDescriptor->entries = (struct AfsEntry*)alloc(readSize,0x20,0,2);
    read(fd, afsDescriptor->entries, readSize);
    seek(fd, 0, SEEK_SET);
    uint32_t afsSize = seek(fd, 0, SEEK_END);
    print(afsLoaded, path, afsDescriptor->fileCount, afsSize);
    return afsDescriptor;
}

void afsCloseAndFree(Afs* afs) {
    free(afs->entries);
    close(afs->fd);
    free(afs);
}

int32_t afsSeekTo(Afs* afs, const uint32_t fileIndex) {
    seek(afs->fd, afs->entries[fileIndex].offset, SEEK_SET);
    return afs->fd;
}

uint32_t afsGetFileSize(Afs* afs, const uint32_t fileIndex) {
    return afs->entries[fileIndex].size;
}

uint32_t afsFileCount(Afs* afs) {
    return afs->fileCount;
}
