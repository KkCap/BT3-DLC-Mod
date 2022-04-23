uint32_t loadStartingQuotes_00217200(byte_t *quoteStr) {
    int32_t specialQuotesBlockP1;
    uint32_t infoP0;
    uint32_t infoP1;
    byte_t *quoteIdPtrP0;
    byte_t *quoteIdPtrP1;
    int32_t specialQuotesBlockP0;
    uint64_t infoP0_;

    //Definizione funzioni
    void (*FUN_0012b1d0)(uint32_t a0) = (void (*)(uint32_t))0x0012b1d0;
    void (*FUN_002499b0)(uint32_t a0) = (void (*)(uint32_t))0x002499b0;
    void (*forse_get_random_002a9c78)() = (void (*)())0x002a9c78;
    void (*FUN_00267ac8)(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3) = (void (*)(uint32_t,uint32_t,uint32_t,uint32_t))0x00267ac8;

    infoP0_ = FUN_0012b1d0(0);
    infoP0 = FUN_002499b0(infoP0_);
    specialQuotesBlockP0 = *(int32_t *)(infoP0 + 0x93c);
    infoP0_ = FUN_0012b1d0(1);
    infoP1 = FUN_002499b0(infoP0_);
    specialQuotesBlockP1 = *(uint32_t *)(infoP1 + 0x93c);

    uint32_t characterIdP1 = *(uint32_t *)(infoP1 + 0xc);
    uint32_t characterIdP0 = *(uint32_t *)(infoP0 + 0xc);

    quoteIdPtrP0 = (byte_t *)(characterIdP1 * 4 + specialQuotesBlockP0;

    if(specialQuotesBlockP0 == 0 || specialQuotesBlockP1 == 0 || *quoteIdPtrP0 == 0xFFU) {
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
            *(uint32_t *)(quoteStr + 8) = 0;
            *(uint32_t *)(quoteStr + 0xc) = 1;
            *(uint32_t *)(quoteStr + 0x18) = characterIdP0;
            *(uint32_t *)(quoteStr + 0x1c) = characterIdP1;
            *(uint32_t *)(quoteStr + 0x10) = (uint32_t)*(byte_t *)(characterIdP1 * 4 + specialQuotesBlockP0) + 6;
            quoteIdPtrP1 = (byte_t *)(characterIdP0 * 4 + specialQuotesBlockP1);
        } else {
            //Player 1 inizia
            *(uint32_t *)(quoteStr + 0xc) = 0;
            *(uint32_t *)(quoteStr + 8) = 1;
            *(uint32_t *)(quoteStr + 0x18) = characterIdP1;
            *(uint32_t *)(quoteStr + 0x1c) = characterIdP0;
            *(uint32_t *)(quoteStr + 0x10) = (uint32_t)*(byte_t *)(characterIdP0 * 4 + specialQuotesBlockP1) + 6;
            quoteIdPtrP1 = (byte_t *)(characterIdP1 * 4 + specialQuotesBlockP0);
        }
        *(uint32_t *)(quoteStr + 0x14) = (uint32_t)*quoteIdPtrP1 + 6;
    }
    *(uint32_t *)(quoteStr + 4) = 0;
    FUN_00267ac8(0x41200000,0,0x3f800000,quoteStr + 0x20);
    return 1;
}
