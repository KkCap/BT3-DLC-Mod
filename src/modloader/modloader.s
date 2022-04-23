.global	modloaderEntrypoint

.text
modloaderEntrypoint:
    #Patch istruzione
    lui $v0, 0x10
    ori $v0, 0x0630
    lui $v1, 0x0c0c
    ori $v1, 0xdaa4
    sw  $v1, 0($v0)

    #open 0x002b5d30
    lui  $v0, 0x2b
    ori  $v0, 0x5d30
    lui  $a0, 0x33
    ori  $a0, filepath
    lui  $a1, 4
    lui  $a2, 0
    jalr $v0
    bltz $v0, resetReg
    move $s7, $v0  # in s7 c'è il fd

    #malloc
    li   $a0, 0x4000     # Dimensione 16KiB
    li   $a1, 0x20
    move $a2, $zero
    li   $a3, 0x2
    lui  $v0, 0x25
    ori  $v0, 0x54d8
    jalr $v0
    move $s6, $v0

    #Prima FlushCache(0) 0x002b0e60
    lui  $v0, 0x2b
    ori  $v0, 0x0e60
    lui  $a0, 0
    jalr $v0

    #read(int32_t fd, void* buff, uint32_t size) 0x002b6378
    lui  $v0, 0x2b
    ori  $v0, 0x6378
    move $a0, $s7
    move $a1, $s6        # Indirizzo buffer in s6
    li   $a2, 0x4000     # Dimensione 16KiB
    jalr $v0

    #Seconda FlushCache(0) 0x002b0e60
    lui  $v0, 0x2b
    ori  $v0, 0x0e60
    lui  $a0, 0
    jalr $v0

    #close(fd) 0x002b5fc0
    lui  $v0, 0x2b
    ori  $v0, 0x5fc0
    move $a0, $s7
    jalr $v0

    #Jump to MOD.BIN entrypoint / init function (0x8c6bc0)
    addi $s6, 512
    jalr $s6

    #Ripristino registri
    li   $s7, 0
    li   $s6, 0
    resetReg:
    lui  $ra, 0x10
    ori  $ra, 0x0638
    lui  $gp, 0x30
    ori  $gp, $gp, 0x4270

    #Jump to original entrypoint
    lui  $v0, 0x33
    ori  $v0, 0x6a90
    jr   $v0

filepath:
    .asciz "cdrom0:\\BIN\\MOD.BIN;1"
