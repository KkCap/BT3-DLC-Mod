#ifndef __COMMON_H__
#define __COMMON_H__


#include "types.h"


#define INFO_CHUNK_PTR_ADDR        (0x003b38d4U)
#define INFO_CHUNK_TB_PTR_ADDR     (0x003b38d8U)
#define INFO_CHUNK_CR_PTR_ADDR     (0x003b4854U)
#define INFO_CHUNK_WT_PTR_ADDR     (0x003b5910U)
#define INFO_CHUNK_M100_PTR_ADDR   (0x003b734cU)
#define INFO_CHUNK_M100SB_PTR_ADDR (0x003b7348U)
#define MODEL_P1_PTR_ADDR          (0x0031e9bcU)
#define FA_P1_PTR_ADDR             (0x0031e9d4U)
#define KZE_P1_PTR_ADDR            (0x0031e9ecU)
#define MODEL_P2_PTR_ADDR          (0x0031ea04U)
#define FA_P2_PTR_ADDR             (0x0031ea1cU)
#define KZE_P2_PTR_ADDR            (0x0031ea34U)
#define RES_CHUNK_PTR_ADDR         (0x0031e794U)
//#define RES3_CHUNK_PTR_ADDR        (0x0031e7c4U)

#define BPD_ADDR         0x00263278U
#define OPEN_ADDR        0x002b5d30U
#define READ_ADDR        0x002b6378U
#define CLOSE_ADDR       0x002b5fc0U
#define FLUSH_CACHE_ADDR 0x002b0e60U
#define PRINT_ADDR       0x0026e970U
#define MALLOC_ADDR      0x002554d8U
#define SEEK_ADDR        0x002b6138U

#define LOAD_CHARACTER_RENDER_ORIGINAL_FUNCTION_ADDR   0x00342da0U
#define LOAD_CHARACTER_RENDER_ORIGINAL_FUNCTION_ADDR_2 0x00342b30U
#define COLOR_CHANGE_CR_ORIGINAL_FUNCTION              0x00124f68U
#define COLOR_CHANGE_TB_ORIGINAL_FUNCTION              0x00349fe0U
#define COLOR_CHANGE_WT_ORIGINAL_FUNCTION              0x0035e5e0U
#define COLOR_CHANGE_M100_ORIGINAL_FUNCTION            0x0036e9c0U
#define COLOR_CHANGE_M100SB_ORIGINAL_FUNCTION          0x0036b7f8U
#define CALL_DECOMP_ORIGINAL_FUNCTION                  0x00126608U  //E' una jump a bpd

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define BIG_IMAGE_TEXTURE_SIZE 256*512
#define BIG_IMAGE_PALETTE_SIZE 256*4
#define QRS_HEADER_SIZE        96
#define QRS_FOOTER_SIZE        32
#define BIG_IMAGE_HEADER_SIZE  96
#define DEFAULT_MODEL_SIZE     843776  //0xce000
#define DEFAULT_FA_SIZE        1443840
#define DEFAULT_KZE_SIZE       845824
#define ORIGINAL_CHARACTER_COUNT 161
#define DEFAULT_HUD_ESPERA_SIZE 3424
#define BIGGER_MODEL_SIZE      0x18e000
#define COMPRESSED_BIG_IMAGE_MAX_SIZE 92160

#define ELF_CALL_BIN_ISTR_ADDR              0x00100630U
#define COLOR_CHANGE_ISTR1_ADDR             0x003476c8U
#define COLOR_CHANGE_ISTR2_ADDR             0x00347614U
#define COLOR_CHANGE_TB_ISTR1_ADDR          0x0034f908U
#define COLOR_CHANGE_TB_ISTR2_ADDR          0x0034f828U
#define COLOR_CHANGE_WT_ISTR_ADDR           0x00361538U
#define COLOR_CHANGE_M100_ISTR1_ADDR        0x00371838U
#define COLOR_CHANGE_M100_ISTR2_ADDR        0x003717a0U
#define COLOR_CHANGE_M100SB_ISTR_ADDR       0x0036d950U
#define COLOR_CHANGE_CR_ISTR_ADDR           0x003588e0U
#define CALL_DECOMP_TB_ISTR_ADDR            0x00349bf8U
#define CALL_DECOMP_WT_ISTR_ADDR            0x0035e508U
#define CALL_DECOMP_M100_ISTR_ADDR          0x0036e8c0U
#define CALL_DECOMP_M100SB_ISTR_ADDR        0x0036b720U
#define LOADING_SCREEN_CALL_ISTR_ADDR       0x00127094U
#define SET_CID_AFTER_TRANSF_LAST_CALL_ADDR 0x00249ab0U

//Macro gestione archivi MOD.AFS e DLC.AFS
#define MOD_AFS_FILES_PER_CHARACTER        12
#define DLC_AFS_FILES_PER_CHARACTER        26
#define MOD_AFS_RENDER_FILE_INDEX(I,C)     ((I)*MOD_AFS_FILES_PER_CHARACTER+8+(C))
#define DLC_AFS_RENDER_FILE_INDEX(I,C)     (((I)-165)*DLC_AFS_FILES_PER_CHARACTER+16+(C))
#define DLC_AFS_MODEL_FILE_INDEX(I,C)      (((I)-165)*DLC_AFS_FILES_PER_CHARACTER+(C))
#define DLC_AFS_UNK_AUDIO_FILE_INDEX(I,L)  (((I)-165)*DLC_AFS_FILES_PER_CHARACTER+22+(L))

#define audiolang_t     uint32_t
#define AUDIO_LANG_JAP  0
#define AUDIO_LANG_ENG  1

#define DATA_SECTION __attribute__((section(".data")))

#define MIN(A,B) ((A) < (B) ? (A) : (B))

#define GET_RA(A) asm("move $v0, $ra"); uint32_t A = simpleReturn();
#define PATCH_DATA32(WHERE, WHAT) *((uint32_t*)(WHERE)) = (uint32_t)(WHAT);
#define PATCH_ISTR(WHERE, WHAT) *((uint32_t*)(WHERE)) = (uint32_t)(WHAT);
#define OPCODE_JAL(A) (0x0c000000U | ((uint32_t)(A) >> 2U))
#define OPCODE_J(A) (0x08000000U | ((uint32_t)(A) >> 2U))
#define OPCODE_NOP 0
#define OPCODE_SLTI_V0_S3(A) (0x2a620000 | (A))
#define OPCODE_SLTI_V0_S6(A) (0x2ac20000 | (A))
#define OPCODE_SLTI_V0_S4(A) (0x2a820000 | (A))
#define OPCODE_SLTI_V0_S1(A) (0x2a220000 | (A))
#define OPCODE_SLTI_V0_S2(A) (0x2a420000 | (A))


#define AFS_INDEX_TO_CHARACTER_ID(I)   (((I) - 1424)/10)
#define AFS_INDEX_TO_COLOR_ID(I)       (((I) - 1424)%10)
#define IS_FA_INDEX(I)                 (((I) % 10) == 2)
#define IS_KZE_INDEX(I)                (((I) % 10) == 3)
#define IS_MODEL_INDEX(I)              (!IS_FA_INDEX(I) && !IS_KZE_INDEX(I) && (I) >= 1424)
#define CHARACTER_TO_MODEL_AFS_INDEX(ID,COL) (1424 + (ID) * 10 + (COL))


struct AfsFileLoadInfo {
    byte_t* ptr;
    uint32_t size;
    uint32_t afsIndex;
    uint32_t zeros;
}__attribute__((packed));

struct PlayerAfsFileLoadInfo {
    struct AfsFileLoadInfo model;
    struct AfsFileLoadInfo fa;
    struct AfsFileLoadInfo kze;
    uint32_t one;
    uint32_t index;
}__attribute__((packed));

struct AfsLoadResult {
    byte_t* ptr1;
    uint32_t zeros;
    uint32_t f;
    byte_t* ptr2;
}__attribute__((packed));

typedef struct {
    byte_t unk0[0x2a0];
    struct PlayerAfsFileLoadInfo playersAfsFileLoadInfos[2];
    struct AfsLoadResult player0ModelLoadResult;
    struct AfsLoadResult player1ModelLoadResult;
    struct AfsLoadResult player2ModelLoadResult;
}__attribute__((packed)) BattleInfo;

struct Res3Entry {
    uint32_t zeros1;
    uint32_t unk0;
    uint16_t unk1;
    uint16_t maxOutfit;
    uint16_t dpPoints;
    uint16_t unk2;
    uint32_t unk3[4];
    byte_t zeros2[12];
    byte_t transfConstr[4];
    float charRefCamera0;
    float charRefCamera1;
    float charRefCamera2;
}__attribute__((packed));

struct ResEntry {
    uint32_t lifePoints;
    uint32_t energy;
    uint32_t unk;
    uint32_t maxBlastStocks;
}__attribute__((packed));

typedef struct {
    uint32_t headCharacterId;
    uint32_t transformationCount;
    uint32_t transfCharacterIds[7];
}__attribute__((packed)) RosterEntry;

struct CrRefListElem_ {
    struct CrRefListElem_* prev;
    struct CrRefListElem_* next;
    uint32_t characterId;
    uint32_t audioIndex;
    uint32_t audioCount;
}__attribute__((packed));
typedef struct CrRefListElem_ CrRefListElem;

typedef struct {
    uint32_t zero;
    uint32_t unk0;
    uint32_t rosterSize0;
    uint32_t rosterSize1;
    RosterEntry* rosterP0;
    RosterEntry* rosterP1;
    uint32_t rosterSize2;
    uint32_t rosterSize3;
}__attribute__((packed)) RosterHeader;


//Struttura passata come argomento a gestore_scambi_e_fusioni
//Restituita da 0x001271a0 (getCharacterChangeInfo)
typedef struct {
    byte_t unk0[20];
    uint32_t characterIds[4];
    uint32_t unk1;
    uint32_t damagedFlag;
}__attribute__((packed)) CharacterChangeInfo;

#endif
