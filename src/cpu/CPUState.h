#pragma once

#include "../definitions.h"

enum ExceptionCause {
	LOAD_ERROR = 4,
	STORE_ERROR = 5,
	SYSCALL = 8,
	ARITHMETIC_OVERFLOW = 12
};

struct CPUState {
	u32 registers[32];

	u32 hi;
	u32 lo;

	u32 pc;
	u32 nextpc;

	u32 cop0registers[16];
	u32* sr = &cop0registers[12];
	u32* cause = &cop0registers[13];
	u32* epc = &cop0registers[14];

	void setCop0Reg(u32 index, u32 val) {
		if (index == 12 || val == 0) {
			cop0registers[index] = val;
		}
		else {
			throw_error("Cop0 register value unhandled");
		}
	}

	u32 readCop0Reg(u32 index) {
		if (index == 12 || index == 13 || index == 14)
			return cop0registers[index];
		throw_error("Unhandled Cop0 Register read");
	}

	void print() {
		printf("PC: 0x%08x \nlo,hi : 0x%08x 0x%08x\n", pc, lo, hi);
		for (int i = 0; i < 32; i++) {
			printf("$r%d : 0x%08x\n", i, registers[i]);
		}
	}
};