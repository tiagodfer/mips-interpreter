#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "mips.h"
#include "constants.h"

unsigned int rs_assembler (char *token) {
    unsigned int mc = 0x0;
    if (!strcmp(token, "$R0")) {
    } else if (!strcmp(token, "$AT")) {
        mc = 0x200000;
    } else if (!strcmp(token, "$V0")) {
        mc = 0x400000;
    } else if (!strcmp(token, "$V1")) {
        mc = 0x600000;
    } else if (!strcmp(token, "$A0")) {
        mc = 0x800000;
    } else if (!strcmp(token, "$A1")) {
        mc = 0xA00000;
    } else if (!strcmp(token, "$A2")) {
        mc = 0xC00000;
    } else if (!strcmp(token, "$A3")) {
        mc = 0xE00000;
    } else if (!strcmp(token, "$T0")) {
        mc = 0x1000000;
    } else if (!strcmp(token, "$T1")) {
        mc = 0x1200000;
    } else if (!strcmp(token, "$T2")) {
        mc = 0x1400000;
    } else if (!strcmp(token, "$T3")) {
        mc = 0x1600000;
    } else if (!strcmp(token, "$T4")) {
        mc = 0x1800000;
    } else if (!strcmp(token, "$T5")) {
        mc = 0x1A00000;
    } else if (!strcmp(token, "$T6")) {
        mc = 0x1C00000;
    } else if (!strcmp(token, "$T7")) {
        mc = 0x1E00000;
    } else if (!strcmp(token, "$S0")) {
        mc = 0x2000000;
    } else if (!strcmp(token, "$S1")) {
        mc = 0x2200000;
    } else if (!strcmp(token, "$S2")) {
        mc = 0x2400000;
    } else if (!strcmp(token, "$S3")) {
        mc = 0x2600000;
    } else if (!strcmp(token, "$S4")) {
        mc = 0x2800000;
    } else if (!strcmp(token, "$S5")) {
        mc = 0x2A00000;
    } else if (!strcmp(token, "$S6")) {
        mc = 0x2C00000;
    } else if (!strcmp(token, "$S7")) {
        mc = 0x2E00000;
    } else if (!strcmp(token, "$T8")) {
        mc = 0x3000000;
    } else if (!strcmp(token, "$T9")) {
        mc = 0x3200000;
    } else if (!strcmp(token, "$K0")) {
        mc = 0x3400000;
    } else if (!strcmp(token, "$K1")) {
        mc = 0x3600000;
    } else if (!strcmp(token, "$GP")) {
        mc = 0x3800000;
    } else if (!strcmp(token, "$SP")) {
        mc = 0x3A00000;
    } else if (!strcmp(token, "$FP")) {
        mc = 0x3C00000;
    } else if (!strcmp(token, "$RA")) {
        mc = 0x3E00000;
    }
    return mc;
}

unsigned int rt_assembler (char *token) {
    unsigned int mc = 0x0;
    if (!strcmp(token, "$R0")) {
    } else if (!strcmp(token, "$AT")) {
        mc = 0x10000;
    } else if (!strcmp(token, "$V0")) {
        mc = 0x20000;
    } else if (!strcmp(token, "$V1")) {
        mc = 0x30000;
    } else if (!strcmp(token, "$A0")) {
        mc = 0x40000;
    } else if (!strcmp(token, "$A1")) {
        mc = 0x50000;
    } else if (!strcmp(token, "$A2")) {
        mc = 0x60000;
    } else if (!strcmp(token, "$A3")) {
        mc = 0x70000;
    } else if (!strcmp(token, "$T0")) {
        mc = 0x80000;
    } else if (!strcmp(token, "$T1")) {
        mc = 0x90000;
    } else if (!strcmp(token, "$T2")) {
        mc = 0xA0000;
    } else if (!strcmp(token, "$T3")) {
        mc = 0xB0000;
    } else if (!strcmp(token, "$T4")) {
        mc = 0xC0000;
    } else if (!strcmp(token, "$T5")) {
        mc = 0xD0000;
    } else if (!strcmp(token, "$T6")) {
        mc = 0xE0000;
    } else if (!strcmp(token, "$T7")) {
        mc = 0xF0000;
    } else if (!strcmp(token, "$S0")) {
        mc = 0x100000;
    } else if (!strcmp(token, "$S1")) {
        mc = 0x110000;
    } else if (!strcmp(token, "$S2")) {
        mc = 0x120000;
    } else if (!strcmp(token, "$S3")) {
        mc = 0x130000;
    } else if (!strcmp(token, "$S4")) {
        mc = 0x140000;
    } else if (!strcmp(token, "$S5")) {
        mc = 0x150000;
    } else if (!strcmp(token, "$S6")) {
        mc = 0x160000;
    } else if (!strcmp(token, "$S7")) {
        mc = 0x170000;
    } else if (!strcmp(token, "$T8")) {
        mc = 0x180000;
    } else if (!strcmp(token, "$T9")) {
        mc = 0x190000;
    } else if (!strcmp(token, "$K0")) {
        mc = 0x1A0000;
    } else if (!strcmp(token, "$K1")) {
        mc = 0x1B0000;
    } else if (!strcmp(token, "$GP")) {
        mc = 0x1C0000;
    } else if (!strcmp(token, "$SP")) {
        mc = 0x1D0000;
    } else if (!strcmp(token, "$FP")) {
        mc = 0x1E0000;
    } else if (!strcmp(token, "$RA")) {
        mc = 0x1F0000;
    }
    return mc;
}

unsigned int rd_assembler (char *token) {
    unsigned int mc = 0x0;
    if (!strcmp(token, "$R0")) {
    } else if (!strcmp(token, "$AT")) {
        mc = 0x800;
    } else if (!strcmp(token, "$V0")) {
        mc = 0x1000;
    } else if (!strcmp(token, "$V1")) {
        mc = 0x1800;
    } else if (!strcmp(token, "$A0")) {
        mc = 0x2000;
    } else if (!strcmp(token, "$A1")) {
        mc = 0x2800;
    } else if (!strcmp(token, "$A2")) {
        mc = 0x3000;
    } else if (!strcmp(token, "$A3")) {
        mc = 0x3800;
    } else if (!strcmp(token, "$T0")) {
        mc = 0x4000;
    } else if (!strcmp(token, "$T1")) {
        mc = 0x4800;
    } else if (!strcmp(token, "$T2")) {
        mc = 0x5000;
    } else if (!strcmp(token, "$T3")) {
        mc = 0x5800;
    } else if (!strcmp(token, "$T4")) {
        mc = 0x6000;
    } else if (!strcmp(token, "$T5")) {
        mc = 0x6800;
    } else if (!strcmp(token, "$T6")) {
        mc = 0x7000;
    } else if (!strcmp(token, "$T7")) {
        mc = 0x7800;
    } else if (!strcmp(token, "$S0")) {
        mc = 0x8000;
    } else if (!strcmp(token, "$S1")) {
        mc = 0x8800;
    } else if (!strcmp(token, "$S2")) {
        mc = 0x9000;
    } else if (!strcmp(token, "$S3")) {
        mc = 0x9800;
    } else if (!strcmp(token, "$S4")) {
        mc = 0xA000;
    } else if (!strcmp(token, "$S5")) {
        mc = 0xA800;
    } else if (!strcmp(token, "$S6")) {
        mc = 0xB000;
    } else if (!strcmp(token, "$S7")) {
        mc = 0xB800;
    } else if (!strcmp(token, "$T8")) {
        mc = 0xC000;
    } else if (!strcmp(token, "$T9")) {
        mc = 0xC800;
    } else if (!strcmp(token, "$K0")) {
        mc = 0xD000;
    } else if (!strcmp(token, "$K1")) {
        mc = 0xD800;
    } else if (!strcmp(token, "$GP")) {
        mc = 0xE000;
    } else if (!strcmp(token, "$SP")) {
        mc = 0xE800;
    } else if (!strcmp(token, "$FP")) {
        mc = 0xF000;
    } else if (!strcmp(token, "$RA")) {
        mc = 0xF800;
    }
    return mc;
}

unsigned int r_assembler (char *assy) {
    unsigned int mc = 0x0;
    char *token = strtok(NULL, " ");
    mc = rd_assembler(token);
    token = strtok(NULL, " ");
    mc |= rs_assembler(token);
    token = strtok(NULL, " ");
    mc |= rt_assembler(token);
    return mc;
}

unsigned int sllsrl_assembler (char *assy) {
    unsigned int mc = 0x0;
    char *token = strtok(NULL, " ");
    mc |= rd_assembler(token);
    token = strtok(NULL, " ");
    mc |= rt_assembler(token);
    token = strtok(NULL, " ");
    unsigned int shamt = atoi(token);
    shamt = shamt << 4;
    mc |= shamt;
    return mc;
}

unsigned int jr_assembler (char *assy) {
    unsigned int mc = 0x0;
    char *token = strtok(NULL, " ");
    mc |= rs_assembler(token);
    return mc;
}

unsigned int i_assembler (char *assy) {
    unsigned int mc = 0x0;
    char *token = strtok(NULL, " ");
    mc |= rt_assembler(token);
    token = strtok(NULL, " ");
    mc |= rs_assembler(token);
    token = strtok(NULL, " ");
    int immediate = atoi(token);
    mc |= immediate;
    return mc;
}

unsigned int lwsw_assembler (char *assy) {
    unsigned int mc = 0x0;
    char *token = strtok(NULL, " ");
    mc |= rt_assembler(token);
    token = strtok(NULL, " ");
    int offset = atoi(token);
    mc |= offset;
    token = strtok(NULL, " ");
    mc |= rs_assembler(token);
    return mc;
}

unsigned int j_assembler (char *assy) {
    unsigned int mc = 0x0;
    char *token = strtok(NULL, " ");
    unsigned int target = atoi(token);
    mc = target >> 2;
    printf("%X\n%i\n", mc, mc);
    return mc;
}

unsigned int assembler (char *assy) {
    unsigned int mc = 0x0;
    char *token = strtok(assy, " ");
    if (!strcmp(token, "SLL")) {
        mc |= sllsrl_assembler(assy);
    } else if (!strcmp(token, "SRL")) {
        mc = 0x2;
        mc |= sllsrl_assembler(assy);
    } else if (!strcmp(token, "JR")) {
        mc = 0x8;
        mc |= jr_assembler(assy);
    } else if (!strcmp(token, "ADD")) {
        mc = 0x20;
        mc |= r_assembler(assy);
    } else if (!strcmp(token, "SUB")) {
        mc = 0x22;
        mc |= r_assembler(assy);
    } else if (!strcmp(token, "AND")) {
        mc = 0x24;
        mc |= r_assembler(assy);
    } else if (!strcmp(token, "OR")) {
        mc = 0x25;
        mc |= r_assembler(assy);
    } else if (!strcmp(token, "NOR")) {
        mc = 0x27;
        mc |= r_assembler(assy);
    } else if (!strcmp(token, "SLT")) {
        mc = 0x2A;
        mc |= r_assembler(assy);
    } else if (!strcmp(token, "J")) {
        mc = 0x8000000;
        mc |= j_assembler(assy);
    } else if (!strcmp(token, "BEQ")) {
        mc = 0x10000000;
        mc |= i_assembler(assy);
    } else if (!strcmp(token, "ADDI")) {
        mc = 0x20000000;
        mc |= i_assembler(assy);
    } else if (!strcmp(token, "LW")) {
        mc = 0x8C000000;
        mc |= lwsw_assembler(assy);
    } else if (!strcmp(token, "SW")) {
        mc = 0xAC000000;
        mc |= lwsw_assembler(assy);
    }
    return mc;
}

int mips_load_word (unsigned int rs, unsigned int rt, unsigned int offset, unsigned int *registers, unsigned int *data) {
    int locked = 0;
    int address = (registers[rs] + (offset << 2)) >> 2;
    if (address >= RAM_SIZE || address < 0) {
        WINDOW *error_window = newwin(5, 35, 10, 25);
        refresh();
        box(error_window, 0, 0);
        mvwprintw(error_window, 2, 10, "Invalid address!");
        wrefresh(error_window);
        wgetch(error_window);
        wclear(error_window);
        wrefresh(error_window);
        delwin(error_window);
        locked = 1;
    } else {
        registers[rt] = data[(registers[rs] + (offset << 2)) >> 2];
    }
    return locked;
}

void mips_store_word () {
}

void mips_branch_on_equal (unsigned int *pc, unsigned int rs, unsigned int rt, int offset, unsigned int *registers) {
    if (registers[rs] == registers[rt]) {
        pc += offset - 4;
    }
}

void mips_add (unsigned int rs, unsigned int rt, unsigned int rd, unsigned int *registers) {
    registers[rd] = registers[rs] + registers[rt];
}

void mips_add_immediate (unsigned int rs, unsigned int rt, int immediate, unsigned int *registers) {
    registers[rt] = registers[rs] + immediate;
}

void mips_sub (unsigned int rs, unsigned int rt, unsigned int rd, unsigned int *registers) {
    registers[rd] = registers[rs] - registers[rt];
}

void mips_and () {
}

void mips_or () {
}

void mips_nor () {
}

void mips_set_on_less_than (unsigned int rs, unsigned int rt, unsigned int rd, unsigned int *registers) {
    registers[rd] = rs < rt;
}

void mips_jump (unsigned int *pc, unsigned int target) {
    unsigned int pc_mask = 0xF0000000;
    target = target << 2;
    *pc = *pc & pc_mask;
    *pc = *pc | target;
}

void mips_jump_register () {
}

void mips_shift_left () {
}

void mips_shift_right () {
}

int cycle (unsigned int *pc, unsigned int *op, unsigned int *rs, unsigned int *rt, unsigned int *rd, unsigned int *target, int *immediate, unsigned int *shamt, unsigned int *funct, int *offset, unsigned int *data, unsigned int *registers, unsigned int *text) {
    int locked = 0;
    unsigned int op_mask = 0xFC000000;
    unsigned int rs_mask = 0x3E00000;
    unsigned int rt_mask = 0x1F0000;
    unsigned int rd_mask = 0xF800;
    unsigned int target_mask = 0x3FFFFFF;
    unsigned int immediate_mask = 0xFFFF;
    unsigned int funct_mask = 0x3F;
    unsigned int offset_mask = 0xFFFF;
    unsigned int mc = text[*pc >> 2];
    *pc += 4;

    *op = mc & op_mask;
    if (*op == 0x0) {
        *funct = mc & funct_mask;
        if (*funct == 0x0) {
            WINDOW *nop_window = newwin(5, 35, 10, 25);
            refresh();
            box(nop_window, 0, 0);
            mvwprintw(nop_window, 2, 10, "End of program!");
            wrefresh(nop_window);
            wgetch(nop_window);
            wclear(nop_window);
            wrefresh(nop_window);
            delwin(nop_window);
            locked = 1;
            return locked;
        } else if (*funct == 0x20) {
            *rs = mc & rs_mask;
            *rs = *rs >> 21;
            *rt = mc & rt_mask;
            *rt = *rt >> 16;
            *rd = mc & rd_mask;
            *rd = *rd >> 11;
            mips_add(*rs, *rt, *rd, registers);
        } else if (*funct == 0x22) {
            *rs = mc & rs_mask;
            *rs = *rs >> 21;
            *rt = mc & rt_mask;
            *rt = *rt >> 16;
            *rd = mc & rd_mask;
            *rd = *rd >> 11;
            mips_sub(*rs, *rt, *rd, registers);
        } else if (*funct == 0x2A) {
            *rs = mc & rs_mask;
            *rs = *rs >> 21;
            *rt = mc & rt_mask;
            *rt = *rt >> 16;
            *rd = mc & rd_mask;
            *rd = *rd >> 11;
            mips_set_on_less_than(*rs, *rt, *rd, registers);
        }
    } else if (*op == 0x8000000) {
        *target = mc & target_mask;
        mips_jump(pc, *target);
    } else if (*op == 0x10000000) {
        *rs = mc & rs_mask;
        *rs = *rs >> 21;
        *rt = mc & rt_mask;
        *rt = *rt >> 16;
        *offset = mc & offset_mask;
        mips_branch_on_equal(pc, *rs, *rt, *offset, registers);
    } else if (*op == 0x20000000) {
        *rs = mc & rs_mask;
        *rs = *rs >> 21;
        *rt = mc & rt_mask;
        *rt = *rt >> 16;
        *immediate = mc & immediate_mask;
        mips_add_immediate(*rs, *rt, *immediate, registers);
    } else if (*op == 0x8C000000) {
        *rs = mc & rs_mask;
        *rs = *rs >> 21;
        *rt = mc & rt_mask;
        *rt = *rt >> 16;
        *offset = mc & offset_mask;
        locked = mips_load_word(*rs, *rt, *offset, registers, data);
    }
    return locked;
}

int step (unsigned int *pc, unsigned int *op, unsigned int *rs, unsigned int *rt, unsigned int *rd, unsigned int *target, int *immediate, unsigned int *shamt, unsigned int *funct, int *offset, unsigned int *data, unsigned int *registers, unsigned int *text) {
    int locked = cycle(pc, op, rs, rt, rd, target, immediate, shamt, funct, offset, data, registers, text);
    return locked;
}
