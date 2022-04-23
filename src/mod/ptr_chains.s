.global getRes3Archive
.global getBigImagePlayer0
.global getBigImagePlayer1
.global getBigImageTbPlayer0
.global getBigImageTbPlayer1
.global getBigImageWt
.global getBigImageM100
.global getBigImageM100SB
.global getBigImageCr
.global getCurrentAudioLanguageRaw
.global getRes3Chunk



.text

getRes3Archive:
    lui $v0, 0x2f
    ori $v0, 0xf11c
    lw $v0, ($v0)
    addi $v0, 0xc
    lw $v0, ($v0)
    jr $ra

getBigImagePlayer0:
    lui $v0, 0x3b
    ori $v0, 0x38d4
    lw $v0, ($v0)
    addi $v0, 0x10
    lw $v0, ($v0)
    jr $ra

getBigImagePlayer1:
    lui $v0, 0x3b
    ori $v0, 0x38d4
    lw $v0, ($v0)
    addi $v0, 0x14
    lw $v0, ($v0)
    jr $ra

getBigImageTbPlayer0:
    lui $v0, 0x3b
    ori $v0, 0x38d8
    lw $v0, ($v0)
    addi $v0, 0x10
    lw $v0, ($v0)
    jr $ra

getBigImageTbPlayer1:
    lui $v0, 0x3b
    ori $v0, 0x38d8
    lw $v0, ($v0)
    addi $v0, 0x14
    lw $v0, ($v0)
    jr $ra

getBigImageWt:
    lui $v0, 0x3b
    ori $v0, 0x5910
    lw $v0, ($v0)
    addi $v0, 0xc
    lw $v0, ($v0)
    jr $ra

getBigImageM100:
    lui $v0, 0x3b
    ori $v0, 0x734c
    lw $v0, ($v0)
    addi $v0, 0xc
    lw $v0, ($v0)
    jr $ra

getBigImageM100SB:
    lui $v0, 0x3b
    ori $v0, 0x7348
    lw $v0, ($v0)
    addi $v0, 0xc
    lw $v0, ($v0)
    jr $ra

getBigImageCr:
    lui $v0, 0x3b
    ori $v0, 0x4854
    lw $v0, ($v0)
    addi $v0, 0x8
    lw $v0, ($v0)
    jr $ra

getCurrentAudioLanguageRaw:
    lui $v0, 0x2f
    ori $v0, 0xf28c
    lw $v0, ($v0)
    addi $v0, 0x1608
    lw $v0, ($v0)
    jr $ra

getRes3Chunk:
    lui $v0, 0x2f
    ori $v0, 0xf11c
    lw $v0, ($v0)
    addi $v0, 0xc
    lw $v0, ($v0)
    jr $ra

