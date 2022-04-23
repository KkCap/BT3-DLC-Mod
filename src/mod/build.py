import os
from pwn import *

#os.system("mipsel-linux-gnu-gcc -nodefaultlibs -nostdlib -fno-PIC -no-pie -fno-PIE -mno-abicalls -Wl,--section-start=.data=0x8C02E0,--section-start=.text=0x8c04e0 ptc_text.c ptc_text.s plt.s")
os.system("readelf -WS a.out")

MOD_MAX_SIZE = 16*1024
DATA_SECTION_MAX_SIZE = 512
TEXT_SECTION_MAX_SIZE = MOD_MAX_SIZE - DATA_SECTION_MAX_SIZE

elf = ELF("a.out")
out = elf.section(".data")
data_size = len(out)
if data_size > DATA_SECTION_MAX_SIZE:
    print("Error: .data section exceded maximum size")
    exit()
out += b"\x00" * (DATA_SECTION_MAX_SIZE - data_size)
text_section = elf.section(".text")
text_size = len(text_section)
if text_size > TEXT_SECTION_MAX_SIZE:
    print("Error: .text section exceded maximum size")
    exit()
out += text_section
out += b"\x00" * (TEXT_SECTION_MAX_SIZE - text_size)
print(".data {} / {} ({}%)".format(data_size, DATA_SECTION_MAX_SIZE, data_size/DATA_SECTION_MAX_SIZE*100))
print(".text {} / {} ({}%)".format(text_size, TEXT_SECTION_MAX_SIZE, text_size/TEXT_SECTION_MAX_SIZE*100))

file = open("MOD.BIN", "wb")
file.write(out)
file.close()

print("")
os.system("mipsel-linux-gnu-objdump -d a.out | grep seb")
print("")

iso_file_path = "/mnt/e/giochi/PS2/DVD/TEST.ISO"

while True:
    resp = input("Write in ISO {}? [y/n] ".format(iso_file_path))
    if resp == "y\n":
        file = open(iso_file_path, "r+b")
        file.seek(3473408)
        file.write(out)
        file.close()
        print("Done");
        break
    elif resp == "n\n":
        break
