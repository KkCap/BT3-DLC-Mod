nasty_offset = 0

list = [
    "byte_t* getRes3Archive()->0x002ff11c#12",
    "byte_t* getBigImagePlayer0()->0x003b38d4#16",
    "byte_t* getBigImagePlayer1()->0x003b38d4#20",
    "byte_t* getBigImageTbPlayer0()->0x003b38d8#16",
    "byte_t* getBigImageTbPlayer1()->0x003b38d8#20",
    "byte_t* getBigImageWt()->0x003b5910#12",
    "byte_t* getBigImageM100()->0x003b734c#12",
    "byte_t* getBigImageM100SB()->0x003b7348#12",
    "byte_t* getBigImageCr()->0x003b4854#8",
    "uint32_t getCurrentAudioLanguageRaw()->0x002ff28c#5640"
]

print("Pointer chain count: {}".format(len(list)))

asm_head = ""
asm_body = ""
c_header = "#ifndef __PTRCHAINS_H__\n#define __PTRCHAINS_H__\n\n\n#include \"types.h\"\n\n"

for e in list:
    splitted = e.split("->")
    c_header += splitted[0] + ";\n"
    fun_name = splitted[0].split(" ")[1].split("(")[0]
    asm_head += ".global " + fun_name + "\n"
    asm_body += fun_name + ":\n"
    offsets = splitted[1].split("#")
    offsets[0] = int(offsets[0], 16) + nasty_offset
    print(str(offsets) + " -> " + splitted[0])
    high = offsets[0] >> 16
    low = offsets[0] & 0xFFFF
    asm_body += "    lui $v0, " + hex(high) + "\n"
    asm_body += "    ori $v0, " + hex(low) + "\n"
    asm_body += "    lw $v0, ($v0)\n"
    for i in range(1,len(offsets)):
        high = int(offsets[i], 0) >> 16
        if high != 0:
            print("Error pointer chain: high != 0")
        low = int(offsets[i], 0) & 0xFFFF
        asm_body += "    addi $v0, " + hex(low) + "\n"
        asm_body += "    lw $v0, ($v0)\n"
        asm_body += "    jr $ra\n"
    asm_body += "\n"

asm = asm_head + "\n\n\n.text\n\n" + asm_body
c_header += "\n\n#endif\n"

file = open("ptr_chains.h", "w")
file.write(c_header)
file.close()

file = open("ptr_chains.s", "w")
file.write(asm)
file.close()
