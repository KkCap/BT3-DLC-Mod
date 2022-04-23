.global	simpleReturn
.global spareModloader
.global getV1
.global getMapDestructionFlag
.global __target__loadFromAfs2_adxFight
.global __target__crFunzioneMalefica1
.global __target__crFunzioneMalefica2
.global __target__crFunzioneMalefica3
.global __target__crFunzioneMalefica4
.global __target__crFunzioneMalefica5
.global __target__crFunzioneMalefica6
.global __target__crFunzioneMalefica7
.global __target__crFunzioneMalefica8
.global __target__crFunzioneMalefica9
.global __target__crFunzioneMalefica10
.global distanceCrLists

.text
simpleReturn:
    jr $ra

getV1:
    move $v0, $v1
    jr $ra

spareModloader:
    #Call modInit()
    jal modInit

    #Reset registers
    lui  $ra, 0x10
    ori  $ra, 0x0638
    lui  $gp, 0x30
    ori  $gp, $gp, 0x4270

    #Jump to original entrypoint: it is returning
    #to to the instruction after the pathed one
    j 0x336a90

getMapDestructionFlag:
    lw  $v1, -0x5690($gp)
    lw  $a0, 0x4($v1)
    lw  $a1, 0x14($a0)
    lw  $v0, 0xc($a1)
    jr $ra


__target__loadFromAfs2_adxFight:
    li $v0, -32687
    add $v0, $v0, -32687
    add $v0, $a1, $v0
    bgez $v0, __target__loadFromAfs2_adxFight_patch
    j 0x0026bae0
    __target__loadFromAfs2_adxFight_patch:
    addi $a1, $a1, -32600
    j 0x0026bae0

__target__crFunzioneMalefica1:
    lw $v1, (distanceCrLists)
    add $s1, $s1, 400  # Non lo fa più per via della patch, lo faccio qui
    add $s1, $s1, $v1
    j 0x00357350

__target__crFunzioneMalefica2:
    lw $v1, (distanceCrLists)
    add $s0, $s0, 400  # Non lo fa più per via della patch, lo faccio qui
    add $s0, $s0, $v1
    j 0x00357454

__target__crFunzioneMalefica3:
    addu $v0, $v0, $a3  # Non lo fa più per via della patch, lo faccio qui
    lw $v1, (distanceCrLists)
    addu $v0, $v0, $v1
    slt $v1, $s0, $a1  # Non lo fa più per via della patch, lo faccio qui
    j 0x00357910

__target__crFunzioneMalefica4:
    lw $t0, (distanceCrLists)
    addu $v0, $v0, $t0
    lw $t0, 0x198($v0)  # Non lo fa più per via della patch, lo faccio qui
    j 0x0035789c

__target__crFunzioneMalefica5:
    sll $v0, $v0, 0x02  # Non lo fa più per via della patch, lo faccio qui
    addu $v0, $v0, $v1  # Non lo fa più per via della patch, lo faccio qui
    lw $t0, (distanceCrLists)
    addu $v0, $v0, $t0
    j 0x00356f50

__target__crFunzioneMalefica6:
    sll $v0, $v0, 0x02  # Non lo fa più per via della patch, lo faccio qui
    addu $v0, $v0, $v1  # Non lo fa più per via della patch, lo faccio qui
    lw $t0, (distanceCrLists)
    addu $v0, $v0, $t0
    j 0x00358938

__target__crFunzioneMalefica7:
    lw $v1, (distanceCrLists)
    addu $v0, $v0, $v1
    lw $v1, 0x19c($v0)  # Non lo fa più per via della patch, lo faccio qui
    addu $a1, $a1, $v1  # Non lo fa più per via della patch, lo faccio qui
    j 0x0035820c

__target__crFunzioneMalefica8:
    lw $v0, (distanceCrLists)
    addu $v1, $v1, $v0
    lw $v0, 0x1a0($v1)  # Non lo fa più per via della patch, lo faccio qui
    addiu $v0, $v0, -1  # Non lo fa più per via della patch, lo faccio qui
    j 0x003585d8

# Quando riproduco la voce del personaggio
__target__crFunzioneMalefica9:
    sll $v1, $v1, 0x02  # Non lo fa più per via della patch, lo faccio qui
    addu $v1, $v1, $a3  # Non lo fa più per via della patch, lo faccio qui
    lw $a1, (distanceCrLists)
    addu $v1, $v1, $a1
    j 0x00358190

# Quando riproduco la voce del personaggio e poi ri-clicco
__target__crFunzioneMalefica10:
    sll $v1, $v1, 0x02  # Non lo fa più per via della patch, lo faccio qui
    addu $v1, $v1, $a3  # Non lo fa più per via della patch, lo faccio qui
    lw $a1, (distanceCrLists)
    addu $v1, $v1, $a1
    j 0x00358500
