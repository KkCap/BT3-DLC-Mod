.global open
.global read
.global close
.global seek
.global print
.global loadingScreen
.global loadFromAfs1
.global alloc
.global free
.global FlushCache
.global bpd
.global isCharacterUnlocked
.global buildRoster
.global setAllForFusions
.global getBattleInfoPtr
.global loadCharacterReferenceRoster



.text

open:
    j 0x002b5d30

read:
    j 0x002b6378

close:
    j 0x002b5fc0

seek:
    j 0x002b6138

print:
    j 0x0026e970

loadingScreen:
    j 0x002635c8

loadFromAfs1:
    j 0x002651c0

alloc:
    j 0x002554d8

free:
    j 0x00255508

FlushCache:
    j 0x002b0e60

bpd:
    j 0x00263278

isCharacterUnlocked:
    j 0x0012b4f0

buildRoster:
    j 0x0025f610

setAllForFusions:
    j 0x0024b9a8

getBattleInfoPtr:
    j 0x00249c48

loadCharacterReferenceRoster:
    j 0x00358b88

