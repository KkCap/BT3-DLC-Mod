#ifndef __PLT_H__
#define __PLT_H__


#include "types.h"
#include "common.h"

int32_t open(const char* path, uint32_t flags, uint64_t);
int32_t read(int32_t fd, void* buff, uint32_t size);
void close(int32_t fd);
int seek(int fd, int offset, int whence);
void print(const char* format, ...);
void loadingScreen();
void* loadFromAfs1(const int32_t asfIndex, void* where);
void* alloc(const uint32_t size, const uint32_t a1, const uint32_t a2, const uint32_t a3);
void free(const void* ptr);
void FlushCache(int32_t mode);
void* bpd(void* in, void* out, int* outSize);
bool isCharacterUnlocked(uint32_t playerId, uint32_t characterId);
void buildRoster(uint32_t* ptrOutRosterSize,RosterEntry *heapRoster,int *param_3,RosterEntry *originalRoster,int *param_5,uint32_t *param_6);
void setAllForFusions(uint32_t playerId, uint32_t afsIndexFusionModel, uint32_t afsIndexFusionFa, uint32_t afsIndexFusionKze);
BattleInfo* getBattleInfoPtr();
void loadCharacterReferenceRoster();


#endif
