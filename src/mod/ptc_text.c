#include "types.h"
#include "plt.h"
#include "ptr_chains.h"
#include "common.h"
#include "afs.h"


#define FLAG_ROSTER_BUILDING_PROCEDURE_NEW 1
#define FLAG_ROSTER_BUILDING_PROCEDURE_OLD 0


typedef struct {
    uint8_t dynamicFusionOutfit;
    uint8_t configurableRepeatableCharacters;
    uint8_t rosterBuildingProcedure;
    uint8_t newDestructionFlags;
    uint8_t reserved[4]
}__attribute__((packed)) Flags;


Flags flags DATA_SECTION = {1, 1, FLAG_ROSTER_BUILDING_PROCEDURE_NEW, 1};
byte_t mapDestructionFlagTable[] DATA_SECTION = {0xFF, 15, 3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte_t modAfsFilePath[] DATA_SECTION = "cdrom0:\\EXTRA\\MOD.AFS;1";
char dlcAfsFilePath[] DATA_SECTION = "cdrom0:\\EXTRA\\DLC.AFS;1";
char targetError[] DATA_SECTION = "target(..) error\n";
char bigImageNotFoundError[] DATA_SECTION = "BI not found\n";
uint32_t modelSize DATA_SECTION = DEFAULT_MODEL_SIZE;
uint32_t lastCharacterColorId DATA_SECTION = 0xFFFFFFFFU;
uint32_t duplicableChIds[] DATA_SECTION = {0x4f, 0x6d, 0x80};
Afs* dlcAfs DATA_SECTION = 0;
Afs* modAfs DATA_SECTION = 0;
CrRefListElem* replacementCrList DATA_SECTION = 0;
uint32_t distanceCrLists DATA_SECTION = 0;

char failedToLoad[] DATA_SECTION = "Failed to load %d\n";
//char loadingAfs[] DATA_SECTION = "Loading from AFS %d, size: %d, read: %d\n";
char dlcCharacterCountStr[] DATA_SECTION = "DLC ch. found: %d\n";


void modInit();
void __target__bigImageModLoadImage(uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3);
void __target__bigImageModLoadImageTb(uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3);
void __target__bigImageModLoadImageWt(uint64_t a0, uint64_t a1, uint64_t a2);
void __target__bigImageModLoadImageM100(uint64_t a0, uint64_t a1, uint64_t a2);
void __target__bigImageModLoadImageM100SB(uint64_t a0, uint64_t a1, uint64_t a2);
void __target__bigImageModLoadImageCr(uint64_t a0, uint64_t a1);
byte_t* __target__loadFromAfs1_modelFaKze(int32_t afsIndex, byte_t* whereToLoad);
void __target__cursorRight(int32_t param_1, int32_t* cursorX);
void __target__cursorLeft(int32_t param_1, int32_t *cursorX);
bool __target__cursorExtRight(int32_t param_1, int32_t *cursorX, int32_t param_3);
bool __target__cursorExtLeft(int32_t param_1, int32_t *cursorX, int32_t param_3);
void __target__cursorExtDown(int32_t param_1, int32_t *cursorX, int32_t *cursorY, int32_t columns);
void __target__cursorExtUp(int32_t param_1, int32_t *cursorX, int32_t *cursorY, int32_t param_4);
bool __target__checkTransfConstraints(uint32_t charId1, uint32_t charId2);
uint32_t __target__getMaxOutfit(uint32_t characterId, int32_t* param_2);
uint32_t __target__getMaxOutfitCr(uint32_t characterId, int32_t* param_2);
byte_t* __target__loadFromAfs1_bigImages(uint32_t afsIndex, byte_t* where);
byte_t* __target__loadFromAfs1_bigImagesTb(uint32_t afsIndex, byte_t* where);
byte_t* __target__loadFromAfs1_bigImagesWt(uint32_t afsIndex, byte_t* where);
byte_t* __target__loadFromAfs1_bigImagesM100(uint32_t afsIndex, byte_t* where);
byte_t* __target__loadFromAfs1_bigImagesM100SB(uint32_t afsIndex, byte_t* where);
byte_t* __target__loadFromAfs1_bigImagesCr(uint32_t afsIndex, byte_t* where);
byte_t* __target__loadFromAfs1_unkAudio(int32_t afsIndex, byte_t* where);
byte_t* __target__loadFromAfs1_hudEspera(int32_t afsIndex, byte_t* where);
int32_t __target__computeDestrMapId();
bool loadCharacterRender(const uint32_t characterId, const uint32_t characterColorId, byte_t* bigImage);
bool loadCustomModel(const uint32_t characterId, const uint32_t characterColorId, byte_t* where);
bool loadCustomFa(const uint32_t characterId, const uint32_t characterColorId, byte_t* where);
bool loadCustomKze(const uint32_t characterId, const uint32_t characterColorId, byte_t* where);
bool loadCustomModelDlc(const uint32_t characterId, const uint32_t characterColorId, byte_t* where);
bool loadCustomFaDlc(const uint32_t characterId, const uint32_t characterColorId, byte_t* where);
bool loadCustomKzeDlc(const uint32_t characterId, const uint32_t characterColorId, byte_t* where);
bool loadCustomHudDlc(const uint32_t characterId, const uint32_t position, byte_t* where);
byte_t* loadCustomUnkAudioDlc(const uint32_t characterId, const audiolang_t lang, byte_t* where);
char* buildModFilePath(const uint32_t characterId, const uint32_t characterColorId, const char fileType);
char* buildDlcFilePath(const uint32_t characterId, const uint32_t characterColorId, const char fileType);
void loadDlcResEntry(const uint32_t characterId);
byte_t* loadCompressedRender(const uint32_t characterId, const uint32_t characterColorId, byte_t* where);
int __target__loadFromAfs2_adxFight(const uint64_t, const uint64_t, const uint64_t, const uint64_t, const uint64_t, const uint64_t, const uint64_t);
uint32_t __target__getDpPoints(uint32_t characterId);
uint32_t __target__loadStartingQuotes_00217200(byte_t *quoteStr);
bool __target__isCharacterUnlocked(uint32_t playerId, uint32_t characterId);
void __target__buildRoster(uint32_t* ptrOutRosterSize, RosterEntry* heapRoster, int* param_3, RosterEntry* originalRoster, int* param_5, uint32_t* param_6);
void __target__buildRosterNew(uint32_t* ptrOutRosterSize, RosterEntry* heapRoster, int* param_3, RosterEntry* originalRoster, int* param_5, uint32_t* param_6);
void __target__setAllForFusions(uint32_t playerId, uint32_t afsIndexNewModel, uint32_t afsIndexNewFa, uint32_t afsIndexNewKze);
void __target__loadCharacterReferenceRoster();
void __target__crFunzioneMalefica1();
void __target__crFunzioneMalefica2();
void __target__crFunzioneMalefica3();
void __target__crFunzioneMalefica4();
void __target__crFunzioneMalefica5();
void __target__crFunzioneMalefica6();
void __target__crFunzioneMalefica7();
void __target__crFunzioneMalefica8();
void __target__crFunzioneMalefica9();
void __target__crFunzioneMalefica10();
void __target__characterReferenceFree(void* addr);
audiolang_t getCurrentAudioLanguage();
int32_t getMapDestructionFlag();
uint32_t simpleReturn();
uint32_t getV1();
void spareModloader();
bool readBit(byte_t* bitPool, const uint32_t pos);


void modInit() {
    //Elf patch to alter "CALL_BIN" to transform it into a jal to the spareModloader
    PATCH_ISTR(ELF_CALL_BIN_ISTR_ADDR, OPCODE_JAL(spareModloader));

    //Ultimate Training and Single Battle
    PATCH_ISTR(COLOR_CHANGE_ISTR1_ADDR, OPCODE_JAL(__target__bigImageModLoadImage));
    PATCH_ISTR(COLOR_CHANGE_ISTR2_ADDR, OPCODE_JAL(__target__bigImageModLoadImage));
    PATCH_ISTR(0x00342984U, OPCODE_JAL(__target__loadFromAfs1_bigImages));

    //Team Battle
    PATCH_ISTR(COLOR_CHANGE_TB_ISTR1_ADDR, OPCODE_JAL(__target__bigImageModLoadImageTb));
    PATCH_ISTR(COLOR_CHANGE_TB_ISTR2_ADDR, OPCODE_JAL(__target__bigImageModLoadImageTb));
    PATCH_ISTR(0x00349b9cU, OPCODE_JAL(__target__loadFromAfs1_bigImagesTb));

    //World Tournament Tour
    PATCH_ISTR(COLOR_CHANGE_WT_ISTR_ADDR, OPCODE_JAL(__target__bigImageModLoadImageWt));
    PATCH_ISTR(0x0035e4c0U, OPCODE_JAL(__target__loadFromAfs1_bigImagesWt));

    //Mission 100 (team)
    PATCH_ISTR(COLOR_CHANGE_M100_ISTR1_ADDR, OPCODE_JAL(__target__bigImageModLoadImageM100));
    PATCH_ISTR(COLOR_CHANGE_M100_ISTR2_ADDR, OPCODE_JAL(__target__bigImageModLoadImageM100));
    PATCH_ISTR(0x0036e878U, OPCODE_JAL(__target__loadFromAfs1_bigImagesM100));

    //Mission 100 (single battle)
    PATCH_ISTR(COLOR_CHANGE_M100SB_ISTR_ADDR, OPCODE_JAL(__target__bigImageModLoadImageM100SB));
    PATCH_ISTR(0x0036b6d8U, OPCODE_JAL(__target__loadFromAfs1_bigImagesM100SB));

    //Character Reference
    PATCH_ISTR(COLOR_CHANGE_CR_ISTR_ADDR, OPCODE_JAL(__target__bigImageModLoadImageCr));
    PATCH_ISTR(0x00358ea0U, OPCODE_JAL(__target__loadFromAfs1_bigImagesCr));
    PATCH_ISTR(0x00356d38U, OPCODE_JAL(__target__loadCharacterReferenceRoster));
    PATCH_ISTR(0x00357348U, OPCODE_J(__target__crFunzioneMalefica1));
    PATCH_ISTR(0x0035744cU, OPCODE_J(__target__crFunzioneMalefica2));
    PATCH_ISTR(0x00357908U, OPCODE_J(__target__crFunzioneMalefica3));
    PATCH_ISTR(0x00357908U+4U, OPCODE_NOP);
    PATCH_ISTR(0x00357894U, OPCODE_J(__target__crFunzioneMalefica4));
    PATCH_ISTR(0x00356f48U, OPCODE_J(__target__crFunzioneMalefica5));
    PATCH_ISTR(0x00356f48U+4U, OPCODE_NOP);
    PATCH_ISTR(0x00358930U, OPCODE_J(__target__crFunzioneMalefica6));
    PATCH_ISTR(0x00358930U+4U, OPCODE_NOP);
    PATCH_ISTR(0x00358204U, OPCODE_J(__target__crFunzioneMalefica7));  //Chichi's commentary
    PATCH_ISTR(0x00358204U+4U, OPCODE_NOP);
    PATCH_ISTR(0x003585d0U, OPCODE_J(__target__crFunzioneMalefica8));  //Chichi's commentary num audio
    PATCH_ISTR(0x003585d0U+4U, OPCODE_NOP);
    PATCH_ISTR(0x00358188U, OPCODE_J(__target__crFunzioneMalefica9));  //Character's voice
    PATCH_ISTR(0x00358188U+4U, OPCODE_NOP);
    PATCH_ISTR(0x003584f8U, OPCODE_J(__target__crFunzioneMalefica10));  //Character's voice 2° click
    PATCH_ISTR(0x003584f8U+4U, OPCODE_NOP);
    PATCH_ISTR(0x0025ddecU, OPCODE_JAL(__target__characterReferenceFree));
    PATCH_ISTR(0x003588bcU, OPCODE_JAL(__target__getMaxOutfitCr));
    PATCH_ISTR(0x00358878U, OPCODE_JAL(__target__getMaxOutfitCr));

    //Replace FA and KZE after transformations and changes
    PATCH_ISTR(0x0024b4a4U, OPCODE_JAL(__target__loadFromAfs1_modelFaKze))

    //Cursori
    PATCH_ISTR(0x0025f248U, OPCODE_J(__target__cursorRight));
    PATCH_ISTR(0x0025f24cU, OPCODE_NOP);
    PATCH_ISTR(0x0025f298U, OPCODE_J(__target__cursorLeft));
    PATCH_ISTR(0x0025f29cU, OPCODE_NOP);
    PATCH_ISTR(0x0025efc8U, OPCODE_J(__target__cursorExtRight));
    PATCH_ISTR(0x0025efccU, OPCODE_NOP);
    PATCH_ISTR(0x0025f048U, OPCODE_J(__target__cursorExtLeft));
    PATCH_ISTR(0x0025f04cU, OPCODE_NOP);
    PATCH_ISTR(0x0025f0d0U, OPCODE_J(__target__cursorExtDown));
    PATCH_ISTR(0x0025f0d0U+4U, OPCODE_NOP);
    PATCH_ISTR(0x0025f190U, OPCODE_J(__target__cursorExtUp));
    PATCH_ISTR(0x0025f190U+4U, OPCODE_NOP);

    //Sostituzione controllo restrizioni di trasformazione
    PATCH_ISTR(0x00261650U, OPCODE_J(__target__checkTransfConstraints));
    PATCH_ISTR(0x00261654U, OPCODE_NOP);

    //Sostituzione getMaxOutfit(...)
    PATCH_ISTR(0x00260d20U, OPCODE_J(__target__getMaxOutfit));
    PATCH_ISTR(0x00260d24U, OPCODE_NOP);

    //Sostituzione getDpPoints(...)
    PATCH_ISTR(0x00260d88U, OPCODE_J(__target__getDpPoints));
    PATCH_ISTR(0x00260d8cU, OPCODE_NOP);

    //Sostituzione loadFromAfs1 per gli unk audio
    PATCH_ISTR(0x00127d28U, OPCODE_JAL(__target__loadFromAfs1_unkAudio));
    PATCH_ISTR(0x00127d58U, OPCODE_JAL(__target__loadFromAfs1_unkAudio));
    PATCH_ISTR(0x001279ccU, OPCODE_JAL(__target__loadFromAfs1_unkAudio)); //scambio player 0 e player 1

    //Sostituzione loadFromAfs1 per gli hud de espera
    PATCH_ISTR(0x00127ff8U, OPCODE_JAL(__target__loadFromAfs1_hudEspera));
    PATCH_ISTR(0x00127a24U, OPCODE_JAL(__target__loadFromAfs1_hudEspera));  //cambio personaggio e fusion

    //Incremento loop inizializzazione immagini piccole
    PATCH_ISTR(0x00343c1cU, OPCODE_SLTI_V0_S3(253));  //Team Battle
    PATCH_ISTR(0x0034b1f0U, OPCODE_SLTI_V0_S6(253));  //Single Battle e Ultimate Training (o invertiti)
    PATCH_ISTR(0x0035f134U, OPCODE_SLTI_V0_S4(253));  //World Tour
    PATCH_ISTR(0x0036f5fcU, OPCODE_SLTI_V0_S1(253));  //M100
    PATCH_ISTR(0x0036c0f4U, OPCODE_SLTI_V0_S2(253));  //M100SB

    //Gestione ADX combattimento
    PATCH_ISTR(0x0026baa4U, OPCODE_JAL(__target__loadFromAfs2_adxFight));

    //Sostituzione special quotes
    PATCH_ISTR(0x00217200U, OPCODE_J(__target__loadStartingQuotes_00217200));
    PATCH_ISTR(0x00217204U, OPCODE_NOP);

    //Fix fusioni "non sbloccate"
    PATCH_ISTR(0x00203830U, OPCODE_JAL(__target__isCharacterUnlocked));

    //Fix trasformazioni "non sbloccate"
    PATCH_ISTR(0x00203484U, OPCODE_JAL(__target__isCharacterUnlocked));

    /*
     * Fix slot "non sbloccati".
     * Usando FLAG_ROSTER_BUILDING_PROCEDURE_OLD si ha il comportamento nativo del gioco, ma i
     * personaggi DLC potrebbero venir riconosciuti come non sbloccati e quindi si ha uno scan del
     * roster per fixare questo problema.
     * Usando FLAG_ROSTER_BUILDING_PROCEDURE_NEW il roster in heap non viene proprio costruito e si
     * utilizza quello in p.unk (Ultimate.unk, WorldTou.unk, ecc...) "fixando i puntatori".
     * Sfortunatamente, dopo la chiamata a buildRoster(...) i puntatori vengono subito resettati e
     * quindi bisogna pathare questa cosa.
     */
    //PATCH_ISTR(0x0025f9d4U, OPCODE_NOP);
    PATCH_ISTR(0x0035f19cU, OPCODE_JAL(__target__buildRoster));  // World Tour
    PATCH_ISTR(0x00364e84U, OPCODE_JAL(__target__buildRoster));
    PATCH_ISTR(0x0036c15cU, OPCODE_JAL(__target__buildRoster));
    PATCH_ISTR(0x0036f664U, OPCODE_JAL(__target__buildRoster));
    PATCH_ISTR(0x00392f84U, OPCODE_JAL(__target__buildRoster));
    if(flags.rosterBuildingProcedure == FLAG_ROSTER_BUILDING_PROCEDURE_NEW) {
        PATCH_ISTR(0x00343e10U, OPCODE_JAL(__target__buildRosterNew));  // Duel
        PATCH_ISTR(0x00343E54U, OPCODE_NOP);  // Duel
        PATCH_ISTR(0x0034b3e0U, OPCODE_JAL(__target__buildRosterNew));  // Team Battle + battaglia a punti
        PATCH_ISTR(0x0034B424U, OPCODE_NOP);  // Team Battle + battaglia a punti
    } else {
        PATCH_ISTR(0x00343e10U, OPCODE_JAL(__target__buildRoster));  // Duel
        PATCH_ISTR(0x0034b3e0U, OPCODE_JAL(__target__buildRoster));  // Team Battle + battaglia a punti
    }

    //Fix outfit fusioni
    if(flags.dynamicFusionOutfit) {
        PATCH_ISTR(0x001279bcU, OPCODE_JAL(__target__setAllForFusions));
        PATCH_ISTR(0x00127a4cU, OPCODE_JAL(__target__setAllForFusions));
    }

    //Map destruction new flags management
    if(flags.newDestructionFlags) {
        PATCH_ISTR(0x00243470U, OPCODE_J(__target__computeDestrMapId));
        PATCH_ISTR(0x00243474U, OPCODE_NOP);
    }

    /*PATCH_ISTR(0x0024b578, 0x3c040018);
    PATCH_ISTR(0x0024b5d8, 0x3c040018);
    modelSize = BIGGER_MODEL_SIZE;*/
    //PATCH_ISTR(0x0024b5b0U, 0x3c06000dU);  //Also the memset argument. original: 0c 00 06 3c

    if(dlcAfs == 0) {
        dlcAfs = afsOpen(dlcAfsFilePath);
    }
    if(modAfs == 0) {
        modAfs = afsOpen(modAfsFilePath);
    }

    //Init res file
    uint32_t characterId, dlcCharacterCount = 0;
    for(characterId = 165; characterId < 253; ++characterId) {
        if(__target__getMaxOutfit(characterId, 0)) {
            loadDlcResEntry(characterId);
            ++dlcCharacterCount;
        }
    }
    print(dlcCharacterCountStr, dlcCharacterCount);
}

void __target__bigImageModLoadImage(uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    //Retrieve playerId, characterId, ptrCharacterColorId and bigImage
    uint32_t playerId = a0 - 3U;
    uint32_t characterId;
    uint32_t characterColorId;
    byte_t* bigImage;
    if(playerId == 0) {
        characterId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 900U));
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 816U));
        bigImage = getBigImagePlayer0();
    } else {
        characterId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 900U + 240U));
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 816U + 240U));
        bigImage = getBigImagePlayer1();
    }

    //Call original function without altering parameters
    void (*original)(uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) = (void (*)(uint64_t,uint64_t,uint64_t,uint64_t))LOAD_CHARACTER_RENDER_ORIGINAL_FUNCTION_ADDR;
    original(a0, a1, a2, a3);

    //Load character render
    loadCharacterRender(characterId, characterColorId, bigImage);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");
}

void __target__bigImageModLoadImageTb(uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    //Call original function without altering parameters
    void (*original)(uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) = (void (*)(uint64_t,uint64_t,uint64_t,uint64_t))COLOR_CHANGE_TB_ORIGINAL_FUNCTION;
    original(a0, a1, a2, a3);

    //Retrieve playerId, characterId, ptrCharacterColorId and bigImage
    uint32_t playerId = a0 - 5U;
    uint32_t characterId;
    uint32_t characterColorId;
    byte_t* bigImage;
    if(playerId == 0) {
        characterId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1296U));
        uint32_t activeSlotIndex = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1284U));
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1008U + activeSlotIndex * 48U));
        bigImage = getBigImageTbPlayer0();
    } else {
        characterId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1296U + 648U));
        uint32_t activeSlotIndex = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1284U + 648U));
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1008U + activeSlotIndex * 48U + 648U));
        bigImage = getBigImageTbPlayer1();
    }

    //Load character render
    loadCharacterRender(characterId, characterColorId, bigImage);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");
}

void __target__bigImageModLoadImageWt(uint64_t a0, uint64_t a1, uint64_t a2) {
    //Call original function without altering parameters
    void (*original)(uint64_t a0, uint64_t a1, uint64_t a2) = (void (*)(uint64_t,uint64_t,uint64_t))COLOR_CHANGE_WT_ORIGINAL_FUNCTION;
    original(a0, a1, a2);

    //Retrieve characterId, ptrCharacterColorId and bigImage
    byte_t* infoChunk = (byte_t*)*((uint32_t*)INFO_CHUNK_WT_PTR_ADDR);
    uint32_t characterId = *((uint32_t*)(infoChunk + 948U));
    uint32_t activeSlotIndex = *((uint32_t*)(infoChunk + 952U));
    uint32_t characterColorId = *((uint32_t*)(infoChunk + 528U + activeSlotIndex * 48U));
    byte_t* bigImage = getBigImageWt();

    //Load character render
    loadCharacterRender(characterId, characterColorId, bigImage);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");
}

void __target__bigImageModLoadImageM100(uint64_t a0, uint64_t a1, uint64_t a2) {
    //Call original function without altering parameters
    void (*original)(uint64_t a0, uint64_t a1, uint64_t a2) = (void (*)(uint64_t,uint64_t,uint64_t))COLOR_CHANGE_M100_ORIGINAL_FUNCTION;
    original(a0, a1, a2);

    //Retrieve characterId, ptrCharacterColorId and bigImage
    byte_t* infoChunk = (byte_t*)*((uint32_t*)INFO_CHUNK_M100_PTR_ADDR);
    uint32_t characterId = *((uint32_t*)(infoChunk + 824U));
    uint32_t activeSlotIndex = *((uint32_t*)(infoChunk + 812U));
    uint32_t characterColorId = *((uint32_t*)(infoChunk + 536U + activeSlotIndex * 48U));
    byte_t* bigImage = getBigImageM100();

    //Load character render
    loadCharacterRender(characterId, characterColorId, bigImage);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");
}

void __target__bigImageModLoadImageM100SB(uint64_t a0, uint64_t a1, uint64_t a2) {
    //Call original function without altering parameters
    void (*original)(uint64_t a0, uint64_t a1, uint64_t a2) = (void (*)(uint64_t,uint64_t,uint64_t))COLOR_CHANGE_M100SB_ORIGINAL_FUNCTION;
    original(a0, a1, a2);

    //Retrieve characterId, ptrCharacterColorId and bigImage
    byte_t* infoChunk = (byte_t*)*((uint32_t*)INFO_CHUNK_M100SB_PTR_ADDR);
    uint32_t characterId = *((uint32_t*)(infoChunk + 528U));
    uint32_t characterColorId = *((uint32_t*)(infoChunk + 444U));
    byte_t* bigImage = getBigImageM100SB();

    //Load character render
    loadCharacterRender(characterId, characterColorId, bigImage);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");
}

byte_t* __target__loadFromAfs1_bigImages(uint32_t afsIndex, byte_t* where) {
    uint32_t characterId = afsIndex - 761U;
    uint32_t playerId = (getV1() == 4U);
    uint32_t characterColorId;
    if(playerId == 0) {
        //characterId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 900U));
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 816U));
    } else {
        //characterId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 900U + 240U));
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_PTR_ADDR) + 816U + 240U));
    }

    byte_t* ret = loadCompressedRender(characterId, characterColorId, where);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");

    return ret;
}

byte_t* __target__loadFromAfs1_bigImagesTb(uint32_t afsIndex, byte_t* where) {
    uint32_t characterId = afsIndex - 761U;
    uint32_t playerId = (getV1() == 4U);
    uint32_t characterColorId;
    if(playerId == 0) {
        uint32_t activeSlotIndex = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1284U));
        if(activeSlotIndex > 4U)
            activeSlotIndex = 0;
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1008U + activeSlotIndex * 48U));
    } else {
        uint32_t activeSlotIndex = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1284U + 648U));
        if(activeSlotIndex > 4U)
            activeSlotIndex = 0;
        characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_TB_PTR_ADDR) + 1008U + activeSlotIndex * 48U + 648U));
    }

    byte_t* ret = loadCompressedRender(characterId, characterColorId, where);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");

    return ret;
}

byte_t* __target__loadFromAfs1_bigImagesWt(uint32_t afsIndex, byte_t* where) {
    uint32_t characterId = afsIndex - 761U;
    //uint32_t playerId = (getV1() == 4U);   //FIX
    //if(playerId == 0) {
    byte_t* infoChunk = (byte_t*)*((uint32_t*)INFO_CHUNK_WT_PTR_ADDR);
    uint32_t activeSlotIndex = *((uint32_t*)(infoChunk + 952U));
    uint32_t characterColorId = *((uint32_t*)(infoChunk + 528U + activeSlotIndex * 48U));
    //} else { }

    byte_t* ret = loadCompressedRender(characterId, characterColorId, where);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");

    return ret;
}

byte_t* __target__loadFromAfs1_bigImagesM100(uint32_t afsIndex, byte_t* where) {
    uint32_t characterId = afsIndex - 761U;

    byte_t* infoChunk = (byte_t*)*((uint32_t*)INFO_CHUNK_M100_PTR_ADDR);
    uint32_t activeSlotIndex = *((uint32_t*)(infoChunk + 812U));
    if(activeSlotIndex > 4U)
        activeSlotIndex = 0;
    uint32_t characterColorId = *((uint32_t*)(infoChunk + 536U + activeSlotIndex * 48U));

    byte_t* ret = loadCompressedRender(characterId, characterColorId, where);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");

    return ret;
}

byte_t* __target__loadFromAfs1_bigImagesM100SB(uint32_t afsIndex, byte_t* where) {
    uint32_t characterId = afsIndex - 761U;

    byte_t* infoChunk = (byte_t*)*((uint32_t*)INFO_CHUNK_M100SB_PTR_ADDR);
    uint32_t characterColorId = *((uint32_t*)(infoChunk + 444U));

    byte_t* ret = loadCompressedRender(characterId, characterColorId, where);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");

    return ret;
}

void __target__bigImageModLoadImageCr(uint64_t a0, uint64_t a1) {
    //Call original function without altering parameters
    void (*original)(uint64_t a0, uint64_t a1) = (void (*)(uint64_t,uint64_t))COLOR_CHANGE_CR_ORIGINAL_FUNCTION;
    original(a0, a1);

    if(!replacementCrList)
        return;

    //Retrieve playerId, characterId, ptrCharacterColorId and bigImage
    uint32_t position = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_CR_PTR_ADDR) + 5596U));
    uint32_t characterId = replacementCrList[position].characterId;
    uint32_t characterColorId = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_CR_PTR_ADDR) + 5608U));
    byte_t* bigImage = getBigImageCr();

    //Load character render
    loadCharacterRender(characterId, characterColorId, bigImage);

    //Reset gp register to the correct value
    asm("lui $gp, 0x30");
    asm("ori $gp, $gp, 0x4270");
}

byte_t* __target__loadFromAfs1_bigImagesCr(uint32_t afsIndex, byte_t* where) {
    if(!replacementCrList)
        return loadCompressedRender(afsIndex - 761U, 0, where);  //characterId = afsIndex - 761U
    uint32_t position = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_CR_PTR_ADDR) + 5596U));
    return loadCompressedRender(replacementCrList[position].characterId, 0, where);
}

byte_t* __target__loadFromAfs1_modelFaKze(int32_t afsIndex, byte_t* whereToLoad) {
    //Se whereToLoad == 0 non stiamo caricando un personaggio "normale", ma siamo durante un attacco
    //che evoca un'altro modello come il pugno del drago di Goku SSJ4.
    //In questo caso il comportamento deve tornare ad essere quello di default del gioco.
    if(whereToLoad == 0) {
        return loadFromAfs1(afsIndex, whereToLoad);
    }

    //Infer characterId from afsIndex
    uint32_t characterId = AFS_INDEX_TO_CHARACTER_ID(afsIndex);

    //DLC character
    if(characterId > 164) {
        if(IS_MODEL_INDEX(afsIndex)) {
            lastCharacterColorId = AFS_INDEX_TO_COLOR_ID(afsIndex);
            if(!loadCustomModelDlc(characterId, lastCharacterColorId, whereToLoad)) {
                whereToLoad = loadFromAfs1(1424, whereToLoad);
            }
            lastCharacterColorId &= 3U;
            return whereToLoad;
        } else if(IS_FA_INDEX(afsIndex) && lastCharacterColorId != 0xFFFFFFFFU) {
            bool success = loadCustomFaDlc(characterId, lastCharacterColorId, whereToLoad);
            if(!success) {
                success = loadCustomFaDlc(characterId, 0, whereToLoad);
            }
            if(!success) {
                whereToLoad = loadFromAfs1(1432, whereToLoad);
            }
            return whereToLoad;
        } else if(IS_KZE_INDEX(afsIndex) && lastCharacterColorId != 0xFFFFFFFFU) {
            bool success = loadCustomKzeDlc(characterId, lastCharacterColorId, whereToLoad);
            if(!success) {
                success = loadCustomKzeDlc(characterId, 0, whereToLoad);
            }
            if(!success) {
                whereToLoad = loadFromAfs1(1433, whereToLoad);
            }
            lastCharacterColorId = 0xFFFFFFFFU;
            return whereToLoad;
        }
        return 0;
    }

    //Not a DLC character
    if(IS_MODEL_INDEX(afsIndex)) {
        lastCharacterColorId = AFS_INDEX_TO_COLOR_ID(afsIndex) % 4;
        return loadFromAfs1(afsIndex, whereToLoad);
    } else if(IS_FA_INDEX(afsIndex) && lastCharacterColorId != 0xFFFFFFFFU) {
        if(!loadCustomFa(characterId, lastCharacterColorId, whereToLoad)) {
            whereToLoad = loadFromAfs1(afsIndex, whereToLoad);
        }
        return whereToLoad;
    } else if(IS_KZE_INDEX(afsIndex) && lastCharacterColorId != 0xFFFFFFFFU) {
        if(!loadCustomKze(characterId, lastCharacterColorId, whereToLoad)) {
            whereToLoad = loadFromAfs1(afsIndex, whereToLoad);
        }
        lastCharacterColorId = 0xFFFFFFFFU;
        return whereToLoad;
    } else {
        return loadFromAfs1(afsIndex, whereToLoad);
    }
}

byte_t* __target__loadFromAfs1_unkAudio(int32_t afsIndex, byte_t* where) {
    audiolang_t lang = getCurrentAudioLanguage();
    int32_t characterId = afsIndex - (lang == AUDIO_LANG_ENG ? 0xc7b : 0xbda);

    //Not a DLC character
    if(characterId < 165) {
        return loadFromAfs1(afsIndex, where);
    }

    //DLC character
    byte_t* newWhere = loadCustomUnkAudioDlc(characterId, lang, where);
    if(newWhere)
        return newWhere;
    return loadFromAfs1((lang == AUDIO_LANG_ENG ? 0xc7b : 0xbda), where);
}

byte_t* __target__loadFromAfs1_hudEspera(int32_t afsIndex, byte_t* where) {
    int32_t characterId = (afsIndex - 8) / 2;
    int32_t position = (afsIndex - 8) % 2;  //1 is right, 0 is left

    //DLC character
    if(characterId > 164) {
        if(!loadCustomHudDlc(characterId, position, where)) {
            return loadFromAfs1(8 + position, where);
        }
        return where;
    }

    //Not a DLC character
    return loadFromAfs1(afsIndex, where);
}

void __target__cursorRight(int32_t param_1, int32_t* cursorX) {
  int32_t originalCursorX = *cursorX;
  int32_t newCursorX = originalCursorX;
  int32_t currentCharacterId;

  while(true) {
    *cursorX = newCursorX + 1;
    if (6 < newCursorX + 1) {
      *cursorX = 0;
    }
    newCursorX = *cursorX;
    currentCharacterId = *(int32_t *)(newCursorX * 4 + param_1);
    if(originalCursorX == newCursorX || (currentCharacterId < ORIGINAL_CHARACTER_COUNT) || currentCharacterId > 164)
        break;
  }
}

void __target__cursorLeft(int32_t param_1, int32_t *cursorX) {
    int32_t originalCursorX = *cursorX;
    int32_t newCursorX = originalCursorX;
    int32_t currentCharacterId;

    while(true) {
        --newCursorX;
        if(newCursorX < 0)
            newCursorX = 6;
        *cursorX = newCursorX;
        currentCharacterId = *(int32_t *)(newCursorX * 4 + param_1);
        if(originalCursorX == newCursorX || (currentCharacterId < ORIGINAL_CHARACTER_COUNT) || currentCharacterId > 164)
          break;
    }
}

bool __target__cursorExtRight(int32_t param_1, int32_t *cursorX, int32_t param_3) {
  int32_t originalCursorX;
  int32_t currentCharacterId;
  int32_t newCursorX;

  originalCursorX = *cursorX;
  newCursorX = originalCursorX;
  while(true) {
    *cursorX = newCursorX + 1;
    if (6 < newCursorX + 1) {
      *cursorX = 0;
    }
    newCursorX = *cursorX;
    if (originalCursorX == newCursorX) {
      return false;
    }
    currentCharacterId = *(int32_t *)((param_3 * 7 + newCursorX) * 0x24 + param_1);
    if (currentCharacterId < 0xa2 || currentCharacterId == 0xa3 || currentCharacterId > 164) {
      return true;
    }
  }
}

bool __target__cursorExtLeft(int32_t param_1, int32_t *cursorX, int32_t param_3) {
    int32_t originalCursorX;
    int32_t currentCharacterId;
    int32_t newCursorX;

    originalCursorX = *cursorX;
    newCursorX = originalCursorX;
    while(true) {
        --newCursorX;
        if(newCursorX < 0)
            newCursorX = 6;
        *cursorX = newCursorX;
        if (originalCursorX == newCursorX) {
            return false;
        }
        currentCharacterId = *(int32_t *)((param_3 * 7 + newCursorX) * 0x24 + param_1);
        if (currentCharacterId < 0xa2 || currentCharacterId == 0xa3 || currentCharacterId > 164) {
            return true;
        }
    }
}

void __target__cursorExtDown(int32_t param_1, int32_t *cursorX, int32_t *cursorY, int32_t columns) {
    uint32_t characterId;
    int32_t tmpCursorY = *cursorY;

    while(true) {
        tmpCursorY = tmpCursorY + 1;
        if(tmpCursorY > columns - 1)
            tmpCursorY = 0;
        *cursorY = tmpCursorY;

        characterId = *(uint32_t *)((tmpCursorY * 7 + *cursorX) * 0x24 + param_1);

        if(characterId < 162 || characterId == 163 || characterId > 164)
            break;

        if(__target__cursorExtRight(param_1,cursorX,tmpCursorY))
            break;
    }
}

void __target__cursorExtUp(int32_t param_1, int32_t *cursorX, int32_t *cursorY, int32_t param_4) {
    uint32_t characterId;
    int32_t tmpCursorY = *cursorY;

    while(true) {
        tmpCursorY = tmpCursorY - 1;
        if(tmpCursorY < 0)
            tmpCursorY = param_4 - 1;
        *cursorY = tmpCursorY;

        characterId = *(uint32_t *)((tmpCursorY * 7 + *cursorX) * 0x24 + param_1);

        if(characterId < 162 || characterId == 163 || characterId > 164)
            break;

        if(__target__cursorExtRight(param_1,cursorX,tmpCursorY))
            break;
    }
}

/**
 * Ritorno:
 *   - true -> Non posso seleziona il personaggio
 *   - false -> Posso selezionare il personaggio
 */
bool __target__checkTransfConstraints(uint32_t charId1, uint32_t charId2) {
    /*if(charId1 != charId2 && (charId1 > 164 || charId2 > 164))
        return false;*/

    uint32_t i;
    byte_t* res3Archive = getRes3Archive();

    if(flags.configurableRepeatableCharacters && *(uint32_t*)res3Archive == 3) {
        //"Configurable Repeatable Characters" mod enabled!
        byte_t* bitPool = res3Archive + *(uint32_t*)(res3Archive + 12);
        if(readBit(bitPool, charId1) || readBit(bitPool, charId2))
            return false;
    } else {
        //Check for repeatable characters the old way :(
        for(i = 0; i < 3; ++i) {
            if(charId1 == duplicableChIds[i] || charId2 == duplicableChIds[i])
                return false;
        }
    }

    //Character is not releatable! Let's check if the user is selecting the same character twice or
    //a transformation
    if(charId1 == charId2)
        return true;

    uint32_t internalOffset = *(uint32_t*)(res3Archive + 4);
    struct Res3Entry* entries = (struct Res3Entry*)(res3Archive + internalOffset);
    for(i = 0; i < 4U; ++i) {
        if(entries[charId1].transfConstr[i] == charId2)
            return true;
    }
    return false;
}

uint32_t __target__getMaxOutfit(uint32_t characterId, int32_t* param_2) {
    uint32_t maxOutfit;
    if(characterId > 164) {
        //Let's count the models inside DLC.AFS that correspond to characterId
        maxOutfit = 0;
        uint32_t fileIndex = DLC_AFS_MODEL_FILE_INDEX(characterId,0);
        uint32_t i;
        for(i = fileIndex; i < fileIndex + 4U; ++i) {
            if(afsGetFileSize(dlcAfs, i) == EMPTY_AFS_FILE_SIZE)
                break;
            ++maxOutfit;
        }
    } else {
        byte_t* res3Archive = getRes3Archive();
        uint32_t internalOffset = *(uint32_t*)(res3Archive + 4);
        struct Res3Entry* entries = (struct Res3Entry*)(res3Archive + internalOffset);
        maxOutfit = entries[characterId].maxOutfit;
    }

    if(param_2 != 0 && (int32_t)maxOutfit <= *param_2)
        *param_2 = 0;

    return maxOutfit;
}

uint32_t __target__getMaxOutfitCr(uint32_t characterId, int32_t* param_2) {
    if(replacementCrList) {
        uint32_t position = *((uint32_t*)(*((uint32_t*)INFO_CHUNK_CR_PTR_ADDR) + 5596U));
        characterId = replacementCrList[position].characterId;
    }
    uint32_t ret = __target__getMaxOutfit(characterId, param_2);
    if(ret == 0)
        return 1;
    return ret;
}

uint32_t __target__getDpPoints(uint32_t characterId) {
    if(characterId > 164) {
        return 5;
    }
    byte_t* res3Chunk = getRes3Archive();
    struct Res3Entry* res3Entries = (struct Res3Entry*)(res3Chunk + *((uint32_t*)(res3Chunk+4)));
    return res3Entries[characterId].dpPoints;
}

bool loadCharacterRender(const uint32_t characterId, const uint32_t characterColorId, byte_t* bigImage) {
    //Check if bigImage is valid
    if(
        bigImage[40+BIG_IMAGE_HEADER_SIZE] != 0x51U || bigImage[56+BIG_IMAGE_HEADER_SIZE] != 0x52U ||
        bigImage[72+BIG_IMAGE_HEADER_SIZE] != 0x53U
    ) {
        print(bigImageNotFoundError);
        return false;
    }

    //Read the compressed big image
    uint32_t fileIndex;
    Afs* afs;
    if(characterId > 164) {
        afs = dlcAfs;
        fileIndex = DLC_AFS_RENDER_FILE_INDEX(characterId,characterColorId);
    } else if(characterId > 160 && characterId < 165) {
        return false;
    } else {
        afs = modAfs;
        fileIndex = MOD_AFS_RENDER_FILE_INDEX(characterId,characterColorId);
    }
    int32_t fd = afsSeekTo(afs, fileIndex);
    if(fd < 0 || afsGetFileSize(afs, fileIndex) == EMPTY_AFS_FILE_SIZE) {
        return false;
    }
    byte_t* compBiBuffer = (byte_t*)alloc(COMPRESSED_BIG_IMAGE_MAX_SIZE,0x20,0,2);
    int32_t r = read(fd, compBiBuffer, COMPRESSED_BIG_IMAGE_MAX_SIZE);
    if(r <= 0) {
        free(compBiBuffer);
        return false;
    }

    //Save the big image header
    byte_t savedHeader[BIG_IMAGE_HEADER_SIZE];
    uint32_t i;
    for(i = 0; i < BIG_IMAGE_HEADER_SIZE; ++i) {
        savedHeader[i] = bigImage[i];
    }

    //Decompress the big image
    bpd(compBiBuffer, bigImage, 0);
    free(compBiBuffer);

    //Restore the big image header
    for(i = 0; i < BIG_IMAGE_HEADER_SIZE; ++i) {
        bigImage[i] = savedHeader[i];
    }

    return true;
}

bool loadCustomFa(const uint32_t characterId, const uint32_t characterColorId, byte_t* where) {
    uint32_t fileIndex = characterId*12+characterColorId;
    int32_t fd = afsSeekTo(modAfs, fileIndex);
    uint32_t size = afsGetFileSize(modAfs,fileIndex);
    if(fd < 0 || size == EMPTY_AFS_FILE_SIZE) {
        print(failedToLoad, fileIndex);
        return false;
    }

    read(fd, where, MIN(DEFAULT_FA_SIZE,size));
    return true;
}

bool loadCustomKze(const uint32_t characterId, const uint32_t characterColorId, byte_t* where) {
    uint32_t fileIndex = characterId*12+4+characterColorId;
    int32_t fd = afsSeekTo(modAfs, fileIndex);
    uint32_t size = afsGetFileSize(modAfs,fileIndex);
    if(fd < 0 || size == EMPTY_AFS_FILE_SIZE) {
        print(failedToLoad, fileIndex);
        return false;
    }

    read(fd, where, MIN(DEFAULT_KZE_SIZE,size));
    return true;
}

bool loadCustomModelDlc(const uint32_t characterId, const uint32_t characterColorId, byte_t* where) {
    uint32_t fileIndex = DLC_AFS_MODEL_FILE_INDEX(characterId,characterColorId);
    int32_t fd = afsSeekTo(dlcAfs, fileIndex);
    uint32_t size = afsGetFileSize(dlcAfs,fileIndex);
    if(fd < 0 || size == EMPTY_AFS_FILE_SIZE) {
        print(failedToLoad, fileIndex);
        return false;
    }

    read(fd, where, MIN(modelSize,size));
    return true;
}

bool loadCustomFaDlc(const uint32_t characterId, const uint32_t characterColorId, byte_t* where) {
    uint32_t fileIndex = (characterId-165)*26+characterColorId+8;
    int32_t fd = afsSeekTo(dlcAfs, fileIndex);
    uint32_t size = afsGetFileSize(dlcAfs,fileIndex);
    if(fd < 0 || size == EMPTY_AFS_FILE_SIZE) {
        print(failedToLoad, fileIndex);
        return false;
    }

    read(fd, where, MIN(DEFAULT_FA_SIZE,size));
    return true;
}

bool loadCustomKzeDlc(const uint32_t characterId, const uint32_t characterColorId, byte_t* where) {
    uint32_t fileIndex = (characterId-165)*26+characterColorId+12;
    int32_t fd = afsSeekTo(dlcAfs, fileIndex);
    uint32_t size = afsGetFileSize(dlcAfs,fileIndex);
    if(fd < 0 || size == EMPTY_AFS_FILE_SIZE) {
        print(failedToLoad, fileIndex);
        return false;
    }

    read(fd, where, MIN(DEFAULT_KZE_SIZE,size));
    return true;
}

byte_t* loadCustomUnkAudioDlc(const uint32_t characterId, const audiolang_t lang, byte_t* where) {
    uint32_t fileIndex = DLC_AFS_UNK_AUDIO_FILE_INDEX(characterId, lang);
    int32_t fd = afsSeekTo(dlcAfs, fileIndex);
    uint32_t size = afsGetFileSize(dlcAfs,fileIndex);
    if(fd < 0 || size == EMPTY_AFS_FILE_SIZE) {
        print(failedToLoad, fileIndex);
        return 0;
    }

    size = MIN((1*1024*1024),size);   //FIX

    if(where == 0) {
        where = (byte_t*)alloc(size,0x40,0,2);
        if(!where)
            return 0;
    }

    read(fd, where, size);
    return where;
}

bool loadCustomHudDlc(const uint32_t characterId, const uint32_t position, byte_t* where) {
    uint32_t fileIndex = (characterId-165)*26+20+position;
    int32_t fd = afsSeekTo(dlcAfs, fileIndex);
    uint32_t size = afsGetFileSize(dlcAfs,fileIndex);
    if(fd < 0 || size == EMPTY_AFS_FILE_SIZE) {
        print(failedToLoad, fileIndex);
        return false;
    }

    read(fd, where, MIN(DEFAULT_HUD_ESPERA_SIZE,size));
    return true;
}

void loadDlcResEntry(const uint32_t characterId) {
    struct ResEntry* resEntry = (struct ResEntry*)(*((uint32_t*)RES_CHUNK_PTR_ADDR)+70080+16*characterId);

    uint32_t fileIndex = (characterId-165)*26+24;
    int32_t fd = afsSeekTo(dlcAfs, fileIndex);
    if(fd >= 0 && afsGetFileSize(dlcAfs, fileIndex) > EMPTY_AFS_FILE_SIZE) {
        read(fd, resEntry, sizeof(struct ResEntry));
    } else {
        resEntry->lifePoints = 40000;
        resEntry->energy = 40000;
        resEntry->unk = 100000;
        resEntry->maxBlastStocks = 7;
    }
}

byte_t* loadCompressedRender(const uint32_t characterId, const uint32_t characterColorId, byte_t* where) {
    if(characterId > 164) {
        //Read from AFS the correct compressed big image
        uint32_t fileIndex = DLC_AFS_RENDER_FILE_INDEX(characterId,characterColorId);
        int32_t fd = afsSeekTo(dlcAfs,fileIndex);
        uint32_t fileSize = afsGetFileSize(dlcAfs,fileIndex);
        if(fd >= 0 && fileSize > EMPTY_AFS_FILE_SIZE) {
            read(fd,where,fileSize);
            return where;
        }
        //Attempt 2: read from AFS the correct compressed big image for outfit 0
        if(characterColorId != 0) {
            fileIndex = DLC_AFS_RENDER_FILE_INDEX(characterId,0);
            fd = afsSeekTo(dlcAfs,fileIndex);
            fileSize = afsGetFileSize(dlcAfs,fileIndex);
            if(fd >= 0 && fileSize > EMPTY_AFS_FILE_SIZE) {
                read(fd,where,fileSize);
                return where;
            }
        }
        return loadFromAfs1(924, where);
    } else if(characterId == 164) {
        return loadFromAfs1(924, where);
    } else {
        //Read from AFS the correct compressed big image
        uint32_t fileIndex = MOD_AFS_RENDER_FILE_INDEX(characterId,characterColorId);
        if(fileIndex >= afsFileCount(modAfs)) {
            return loadFromAfs1(761U + characterId, where);
        }
        int32_t fd = afsSeekTo(modAfs,fileIndex);
        uint32_t fileSize = afsGetFileSize(modAfs,fileIndex);
        if(fd < 0 || fileSize == EMPTY_AFS_FILE_SIZE) {
            return loadFromAfs1(761U + characterId, where);
        }
        read(fd,where,fileSize);
    }

    return where;
}

audiolang_t getCurrentAudioLanguage() {
    if(getCurrentAudioLanguageRaw() & 1) {
        return AUDIO_LANG_ENG;
    }
    return AUDIO_LANG_JAP;
}

uint32_t __target__loadStartingQuotes_00217200(byte_t *quoteStr) {
    int32_t specialQuotesBlockP1;
    uint32_t infoP0;
    uint32_t infoP1;
    byte_t *quoteIdPtrP0;
    byte_t *quoteIdPtrP1;
    int32_t specialQuotesBlockP0;
    uint64_t infoP0_;

    //Definizione funzioni
    uint64_t (*FUN_0012b1d0)(uint32_t a0) = (uint64_t (*)(uint32_t))0x0012b1d0;
    uint32_t (*FUN_002499b0)(uint32_t a0) = (uint32_t (*)(uint32_t))0x002499b0;
    int32_t (*forse_get_random_002a9c78)() = (int32_t (*)())0x002a9c78;
    void (*FUN_00267ac8)(float a0, float a1, float a2, byte_t* a3) = (void (*)(float,float,float,byte_t*))0x00267ac8;

    //Inizializzazione variabili necessarie
    infoP0_ = FUN_0012b1d0(0);
    infoP0 = FUN_002499b0(infoP0_);
    specialQuotesBlockP0 = *(int32_t*)(infoP0 + 0x93c);
    infoP0_ = FUN_0012b1d0(1);
    infoP1 = FUN_002499b0(infoP0_);
    specialQuotesBlockP1 = *(uint32_t*)(infoP1 + 0x93c);

    uint32_t characterIdP1 = *(uint32_t*)(infoP1 + 0xc);
    uint32_t characterIdP0 = *(uint32_t*)(infoP0 + 0xc);

    quoteIdPtrP0 = (byte_t*)(characterIdP1 * 4 + specialQuotesBlockP0);

    //Should I force default random quotes?
    bool forceDefaultRandomQuotes = false;
    if(specialQuotesBlockP0 == 0 || specialQuotesBlockP1 == 0) {
        forceDefaultRandomQuotes = true;
    } else {
        uint32_t* sqP0 = (uint32_t*)specialQuotesBlockP0;
        uint32_t* sqP1 = (uint32_t*)specialQuotesBlockP1;
        uint32_t i;
        for(i = 0; i < characterIdP1; ++i) {
            if(sqP0[i] == 0) {
                forceDefaultRandomQuotes = true;
                break;
            }
        }
        for(i = 0; i < characterIdP0; ++i) {
            if(sqP1[i] == 0) {
                forceDefaultRandomQuotes = true;
                break;
            }
        }
    }

    //Chose quotes and characters' order
    if(forceDefaultRandomQuotes || *quoteIdPtrP0 == 0xFFU) {
        //Riproduzione special quote casuale
        *(uint32_t *)(quoteStr + 8) = 0;
        *(uint32_t *)(quoteStr + 0xc) = 1;
        *(uint32_t *)(quoteStr + 0x18) = characterIdP0;
        *(uint32_t *)(quoteStr + 0x1c) = characterIdP1;
        specialQuotesBlockP0 = forse_get_random_002a9c78();
        *(int32_t *)(quoteStr + 0x10) = specialQuotesBlockP0 % 2;
        specialQuotesBlockP0 = forse_get_random_002a9c78();
        *(int32_t *)(quoteStr + 0x14) = specialQuotesBlockP0 % 2;
    } else {
        //Riproduzione special quote specifica
        if (quoteIdPtrP0[1] == 0) {
            //Player 0 inizia
            *(uint32_t*)(quoteStr + 8) = 0;
            *(uint32_t*)(quoteStr + 0xc) = 1;
            *(uint32_t*)(quoteStr + 0x18) = characterIdP0;
            *(uint32_t*)(quoteStr + 0x1c) = characterIdP1;
            *(uint32_t*)(quoteStr + 0x10) = (uint32_t)*(byte_t*)(characterIdP1 * 4 + specialQuotesBlockP0) + 6;
            quoteIdPtrP1 = (byte_t *)(characterIdP0 * 4 + specialQuotesBlockP1);
        } else {
            //Player 1 inizia
            *(uint32_t*)(quoteStr + 0xc) = 0;
            *(uint32_t*)(quoteStr + 8) = 1;
            *(uint32_t*)(quoteStr + 0x18) = characterIdP1;
            *(uint32_t*)(quoteStr + 0x1c) = characterIdP0;
            *(uint32_t*)(quoteStr + 0x10) = (uint32_t)*(byte_t *)(characterIdP0 * 4 + specialQuotesBlockP1) + 6;
            quoteIdPtrP1 = (byte_t *)(characterIdP1 * 4 + specialQuotesBlockP0);
        }
        *(uint32_t*)(quoteStr + 0x14) = (uint32_t)*quoteIdPtrP1 + 6;
    }
    *(uint32_t*)(quoteStr + 4) = 0;
    FUN_00267ac8(10.0f,0.0f,1.0f,quoteStr + 0x20);
    return 1;
}

bool __target__isCharacterUnlocked(uint32_t playerId, uint32_t characterId) {
    if(characterId > 164)
        return true;
    return isCharacterUnlocked(playerId,characterId);
}

void __target__buildRoster(uint32_t* ptrOutRosterSize, RosterEntry* heapRoster, int* param_3, RosterEntry* originalRoster, int* param_5, uint32_t* param_6) {
    buildRoster(ptrOutRosterSize, heapRoster, param_3, originalRoster, param_5, param_6);
    uint32_t rosterSize = *(uint32_t*)((byte_t*)originalRoster - 16);
    uint32_t i, j;
    for(i = 0; i < rosterSize; ++i) {
        //Check if the currect RosterEntry involves DLC characters
        bool needCopy = originalRoster[i].headCharacterId > 164;
        if(!needCopy) {
            for(j = 0; j < originalRoster[i].transformationCount; ++j) {
                if(originalRoster[i].transfCharacterIds[j] > 164) {
                    needCopy = true;
                    break;
                }
            }
        }
        //If yes, copy it from the originalRoster
        if(needCopy) {
            heapRoster[i] = originalRoster[i];
        }
    }
}

void __target__buildRosterNew(uint32_t* ptrOutRosterSize, RosterEntry* heapRoster, int* param_3, RosterEntry* originalRoster, int* param_5, uint32_t* param_6) {
    uint32_t rosterSize = *(uint32_t*)((byte_t*)originalRoster - 16);
    RosterHeader* ptr = (RosterHeader*)(((uint32_t)param_3) & 0xFFFFFFF0U);
    ptr->rosterSize0 = rosterSize;
    ptr->rosterSize1 = rosterSize;
    ptr->rosterP0 = originalRoster;
    ptr->rosterP1 = originalRoster;
    ptr->rosterSize2 = rosterSize;
    ptr->rosterSize3 = rosterSize;
}

void __target__setAllForFusions(uint32_t playerId, uint32_t afsIndexNewModel, uint32_t afsIndexNewFa, uint32_t afsIndexNewKze) {
    uint32_t newCharacterId = AFS_INDEX_TO_CHARACTER_ID(afsIndexNewModel);
    BattleInfo* battleInfo = getBattleInfoPtr();
    uint32_t currentColorId = AFS_INDEX_TO_COLOR_ID(battleInfo->playersAfsFileLoadInfos[playerId].model.afsIndex) % 4;
    if(afsIndexNewFa == 0xFFFFFFFFU && afsIndexNewKze == 0xFFFFFFFFU) {
        //Change characters due to damage
        //afsIndexNewModel can be wrong if the character that is damaged is a dynamic fusion, let's re-calc it
        afsIndexNewModel = CHARACTER_TO_MODEL_AFS_INDEX(newCharacterId, currentColorId + 4);
    } else  {
        //Change characters due to fusion
        uint32_t newColorId = AFS_INDEX_TO_COLOR_ID(afsIndexNewModel);
        newColorId = currentColorId + (newColorId > 3 ? 4 : 0);
        afsIndexNewModel = CHARACTER_TO_MODEL_AFS_INDEX(newCharacterId, newColorId);
        battleInfo->playersAfsFileLoadInfos[playerId].model.afsIndex = afsIndexNewModel;
    }
    setAllForFusions(playerId, afsIndexNewModel, afsIndexNewFa, afsIndexNewKze);
}

/*void __target__loadCharacterReferenceRoster() {
    loadCharacterReferenceRoster();
    //Alloco spazio per lista-array (253 personaggi)
    replacementCrList = alloc(sizeof(CrRefListElem)*253,0x20,0,2);
    if(!replacementCrList) {
        distanceCrLists = 0;
        return;
    }
    //Copio la lista originale sistemando i puntatori
    byte_t* infoChunk = (byte_t*)(*((uint32_t*)INFO_CHUNK_CR_PTR_ADDR));
    CrRefListElem* ptr = (CrRefListElem*)(infoChunk + 400);
    uint32_t i = 0, j = 0;
    CrRefListElem* prec;
    while(ptr) {
        replacementCrList[i].characterId = ptr->characterId;
        replacementCrList[i].audioIndex = ptr->audioIndex;
        replacementCrList[i].audioCount = ptr->audioCount;
        replacementCrList[i].prev = &replacementCrList[i-1];  //If i == 0, fix later
        replacementCrList[i].next = &replacementCrList[i+1];
        prec = ptr;
        ptr = ptr->next;
        ++i;
    }
    prec->next = replacementCrList;
    //Appendo nuova parte della lista
    uint32_t* characterIds = (uint32_t*)(*(uint32_t*)(infoChunk + 0xe24));
    uint32_t* audioCounts = (uint32_t*)(*(uint32_t*)(infoChunk + 0xe2c));
    uint32_t* audioIndices = (uint32_t*)(*(uint32_t*)(infoChunk + 0xe28));
    uint32_t* initializedElements = (uint32_t*)(infoChunk + 0x15e0);
    for(j = 0; j < 92; ++j) {
        if(characterIds[161U + j] >= 161 && characterIds[161U + j] <= 164)
            continue;
        if(__target__getMaxOutfit(characterIds[161U + j], 0) == 0)
            continue;
        replacementCrList[*initializedElements].characterId = characterIds[161U + j];
        replacementCrList[*initializedElements].audioIndex = audioIndices[161U + j];
        replacementCrList[*initializedElements].audioCount = audioCounts[161U + j];
        replacementCrList[*initializedElements].prev = &replacementCrList[*initializedElements-1];
        replacementCrList[*initializedElements].next = &replacementCrList[*initializedElements+1];  //Wrong for the last element, fix later
        *initializedElements += 1;
    }
    replacementCrList[0].prev = 0;
    replacementCrList[*initializedElements-1].next = 0;
    //Aggiorno variabile characterCount
    uint32_t* characterCount = (uint32_t*)(infoChunk + 0x15e4);
    *characterCount = 253;
    //Salvo la distanza (offset) fra la lista nuova e quella vecchia
    distanceCrLists = (uint32_t)replacementCrList - (uint32_t)(infoChunk + 400);
    //I puntatori che puntavano alla vecchia lista devono puntare ora alla nuova
    PATCH_DATA32(infoChunk + 400 - 4, replacementCrList);
}*/

void __target__loadCharacterReferenceRoster() {
    loadCharacterReferenceRoster();
    //Alloco spazio per lista-array (253 personaggi)
    replacementCrList = alloc(sizeof(CrRefListElem)*253,0x20,0,2);
    if(!replacementCrList) {
        distanceCrLists = 0;
        return;
    }
    //Creo nuova lista
    byte_t* infoChunk = (byte_t*)(*((uint32_t*)INFO_CHUNK_CR_PTR_ADDR));
    uint32_t* characterIds = (uint32_t*)(*(uint32_t*)(infoChunk + 0xe24));
    uint32_t* audioCounts = (uint32_t*)(*(uint32_t*)(infoChunk + 0xe2c));
    uint32_t* audioIndices = (uint32_t*)(*(uint32_t*)(infoChunk + 0xe28));
    uint32_t* initializedElements = (uint32_t*)(infoChunk + 0x15e0);
    *initializedElements = 0;
    uint32_t j = 0;
    for(j = 0; j < 253; ++j) {
        if(characterIds[j] >= 161 && characterIds[j] <= 164)
            continue;
        if(__target__getMaxOutfit(characterIds[j], 0) == 0)
            continue;
        replacementCrList[*initializedElements].characterId = characterIds[j];
        replacementCrList[*initializedElements].audioIndex = audioIndices[j];
        replacementCrList[*initializedElements].audioCount = audioCounts[j];
        replacementCrList[*initializedElements].prev = &replacementCrList[*initializedElements-1];  //Wrong if i == 0, fix later
        replacementCrList[*initializedElements].next = &replacementCrList[*initializedElements+1];  //Wrong for the last element, fix later
        *initializedElements += 1;
    }
    replacementCrList[0].prev = 0;
    replacementCrList[*initializedElements-1].next = 0;
    //Aggiorno variabile characterCount
    uint32_t* characterCount = (uint32_t*)(infoChunk + 0x15e4);
    *characterCount = 253;
    //Salvo la distanza (offset) fra la lista nuova e quella vecchia
    distanceCrLists = (uint32_t)replacementCrList - (uint32_t)(infoChunk + 400);
    //I puntatori che puntavano alla vecchia lista devono puntare ora alla nuova
    PATCH_DATA32(infoChunk + 400 - 4, replacementCrList);
}

void __target__characterReferenceFree(void* addr) {
    free(addr);
    if(replacementCrList) {
        free(replacementCrList);
        replacementCrList = 0;
    }
    distanceCrLists = 0;
}

int32_t __target__computeDestrMapId() {
    int destrFlag;
    int ret;
    uint32_t lVar1;

    lVar1 = ((uint32_t (*)(void))0x0023fbf8)();
    if (lVar1 == 0)
        return -1;

    destrFlag = getMapDestructionFlag();
    if(destrFlag < 0 || destrFlag >= sizeof(mapDestructionFlagTable) || mapDestructionFlagTable[destrFlag] == 0xFF)
        return -1;

    return (int32_t)(uint32_t)mapDestructionFlagTable[destrFlag];
}

bool readBit(byte_t* bitPool, const uint32_t pos) {
    return (bitPool[pos >> 3] >> (pos % 8)) & 0x01;
}

/*
uint32_t characterId = *((uint32_t*)CHARACTER_ID_ADDR);
void* (*bpd)(void*,void*,int*) = (void* (*)(void*,void*,int*))BPD_ADDR;
void (*malloc)(uint32_t size, uint64_t, uint32_t, uint64_t) = (void (*)(uint32_t, uint64_t, uint32_t, uint64_t))MALLOC_ADDR;
void (*FlushCache)(int32_t) = (void (*)(int32_t))FLUSH_CACHE_ADDR;
*/
