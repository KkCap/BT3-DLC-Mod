#!/bin/bash
#mipsel-linux-gnu-gcc -nodefaultlibs -nostdlib -fno-PIC -no-pie -fno-PIE -mno-abicalls -Wl,--section-start=.data=0x8C02E0,--section-start=.text=0x8c04e0 ptc_text.c ptc_text.s
#mipsel-linux-gnu-gcc -nodefaultlibs -nostdlib -Wl,--section-start=.data=0x8C02E0,--section-start=.text=0x8c04e0 ptc_text.c ptc_text.s

ee-gcc -nodefaultlibs -nostdlib -fno-PIC -mno-abicalls -Os -Wl,--section-start=.data=0x8C69C0,--section-start=.text=0x8c6bc0 ptc_text.c ptc_text.s afs.c plt.s ptr_chains.s
ee-readelf -WS ./a.out

#ee-gcc -fno-PIC -mno-abicalls -Wl,--section-start=.data=0x8C51C0,--section-start=.text=0x8c53c0 ptc_text.c ptc_text.s afs.c plt.s ptr_chains.s
