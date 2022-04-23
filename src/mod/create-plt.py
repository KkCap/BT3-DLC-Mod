list = [
    "int32_t open(const char* path, uint32_t flags, uint64_t)->0x002b5d30",
    "int32_t read(int32_t fd, void* buff, uint32_t size)->0x002b6378",
    "void close(int32_t fd)->0x002b5fc0",
    "int seek(int fd, int offset, int whence)->0x002b6138",
    "void print(const char* format, ...)->0x0026e970",
    "void loadingScreen()->0x002635c8",
    "void* loadFromAfs1(const int32_t asfIndex, void* where)->0x002651c0",
    "void* alloc(const uint32_t size, const uint32_t a1, const uint32_t a2, const uint32_t a3)->0x002554d8",
    "void free(const void* ptr)->0x00255508",
    "void FlushCache(int32_t mode)->0x002b0e60",
    "void* bpd(void* in, void* out, int* outSize)->0x00263278",
    "bool isCharacterUnlocked(uint32_t playerId, uint32_t characterId)->0x0012b4f0",
    "void buildRoster(uint32_t* ptrOutRosterSize,RosterEntry *heapRoster,int *param_3,RosterEntry *originalRoster,int *param_5,uint32_t *param_6)->0x0025f610",
    "void setAllForFusions(uint32_t playerId, uint32_t afsIndexFusionModel, uint32_t afsIndexFusionFa, uint32_t afsIndexFusionKze)->0x0024b9a8",
    "BattleInfo* getBattleInfoPtr()->0x00249c48",
    "void loadCharacterReferenceRoster()->0x00358b88"
    #"uint32_t getDpPoints(const uint32_t characterId)->0x00260d88",
    #CharacterChangeInfo* getCharacterChangeInfo()->0x001271a0
]

print("PLT function count: {}".format(len(list)))

asm_head = ""
asm_body = ""
c_header = "#ifndef __PLT_H__\n#define __PLT_H__\n\n\n#include \"types.h\"\n#include \"common.h\"\n\n"

for e in list:
    splitted = e.split("->")
    c_header += splitted[0] + ";\n"
    fun_name = splitted[0].split(" ")[1].split("(")[0]
    asm_head += ".global " + fun_name + "\n"
    asm_body += fun_name + ":\n    j " + splitted[1] + "\n\n"

asm = asm_head + "\n\n\n.text\n\n" + asm_body
c_header += "\n\n#endif\n"

file = open("plt.h", "w")
file.write(c_header)
file.close()

file = open("plt.s", "w")
file.write(asm)
file.close()
