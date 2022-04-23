/*int faLoaded = 0;
int kzeLoaded = 0;
byte_t* __target__loadFromAfs1(int32_t afsIndex, byte_t* whereToLoad) {
    byte_t* (*original)(int afsIndex, byte_t* whereToLoad) = (byte_t* (*)(int,byte_t*))0x002651c0U;

    struct BattleInfo* battleInfo = (struct BattleInfo*)getBattleInfoPtr();
    struct PlayerAfsFileLoadInfo* playerLoadInfo = &(battleInfo->playersAfsFileLoadInfos[0]);
    if(battleInfo->playersAfsFileLoadInfos[1].model.ptr == whereToLoad)
        playerLoadInfo = &(battleInfo->playersAfsFileLoadInfos[1]);

    if(IS_MODEL_INDEX(afsIndex)) {
        //loadedModel = a0;
        uint32_t characterId = AFS_INDEX_TO_CHARACTER_ID(afsIndex);
        uint32_t characterColorId = AFS_INDEX_TO_COLOR_ID(afsIndex);
        //loadCustomModel(characterId, characterColorId, playerLoadInfo->model.ptr);
        original(afsIndex, whereToLoad);
        if(loadCustomFa(characterId, characterColorId, playerLoadInfo->fa.ptr)) {
            faLoaded = afsIndex;
        } else {
            faLoaded = 0;
        }
        if(loadCustomKze(characterId, characterColorId, playerLoadInfo->kze.ptr)) {
            kzeLoaded = afsIndex;
        } else {
            kzeLoaded = 0;
        }
        return whereToLoad;
    } else if(IS_FA_INDEX(afsIndex) && AFS_INDEX_TO_CHARACTER_ID(afsIndex) == AFS_INDEX_TO_CHARACTER_ID(faLoaded)) {
        faLoaded = 0;
        return whereToLoad;
    } else if(IS_KZE_INDEX(afsIndex) && AFS_INDEX_TO_CHARACTER_ID(afsIndex) == AFS_INDEX_TO_CHARACTER_ID(kzeLoaded)) {
        kzeLoaded = 0;
        return whereToLoad;
    } else {
        return original(afsIndex, whereToLoad);
    }
}*/
