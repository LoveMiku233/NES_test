#pragma once
#include "Bus.h"
#include <string>
#include <vector>
class olc6502
{
public:
	olc6502();
	~olc6502();

	//标志寄存器
	enum FLAGS {
		C = (1 < 0), //进位
		Z = (1 < 1), //零标志
		I = (1 < 2), //中断
		D = (1 < 3), //十进制?
		B = (1 < 4), //中断调用
		U = (1 < 5), // ???
		V = (1 < 6), //溢出
		N = (1 < 7), // ???
	};
	//状态寄存器 8位
	uint8_t status = 0x00;
	//累加器 8位
	uint8_t a = 0x00;
	//x寄存器
	uint8_t x = 0x00;
	//y寄存器
	uint8_t y = 0x00;
	//栈顶寄存器
	uint8_t sp = 0x00;
	//程序IP寄存器，程序计数器 16位
	uint8_t pc = 0x0000;
	//连接总线 
	void connectBus(Bus* b) { bus = b; };
	//寻址模式
	uint8_t IMP();	uint8_t IMM();
	uint8_t ZP0();	uint8_t ZPX();
	uint8_t ZPY();	uint8_t REL();
	uint8_t ABS();	uint8_t ABX();
	uint8_t ABY();	uint8_t IND();
	uint8_t IZX();	uint8_t IZY();
	//操作码
	uint8_t ADC();	uint8_t AND();	uint8_t ASL();	uint8_t BCC();
	uint8_t BCS();	uint8_t BEQ();	uint8_t BIT();	uint8_t BMI();
	uint8_t BNE();	uint8_t BPL();	uint8_t BRK();	uint8_t BVC();
	uint8_t BVS();	uint8_t CLC();	uint8_t CLD();	uint8_t CLI();
	uint8_t CLV();	uint8_t CMP();	uint8_t CPX();	uint8_t CPY();
	uint8_t DEC();	uint8_t DEX();	uint8_t DEY();	uint8_t EOR();
	uint8_t INC();	uint8_t INX();	uint8_t INY();	uint8_t JMP();
	uint8_t JSR();	uint8_t LDA();	uint8_t LDX();	uint8_t LDY();
	uint8_t LSR();	uint8_t NOP();	uint8_t ORA();	uint8_t PHA();
	uint8_t PHP();	uint8_t PLA();	uint8_t PLP();	uint8_t ROL();
	uint8_t ROR();	uint8_t RTI();	uint8_t RTS();	uint8_t SBC();
	uint8_t SEC();	uint8_t SED();	uint8_t SEI();	uint8_t STA();
	uint8_t STX();	uint8_t STY();	uint8_t TAX();	uint8_t TAY();
	uint8_t TSX();	uint8_t TXA();	uint8_t TXS();	uint8_t TYA();
	//非法调用此函数
	uint8_t XXX();

	//时钟
	void clock();
	//复位
	void reset();
	//中断
	void irq();
	//不可屏蔽
	void nmi();

	uint8_t fetch();
	uint8_t fetched = 0x00;
	uint16_t addr_abs = 0x0000;
	uint16_t addr_rel = 0x00;
	uint8_t opcode = 0x00;
	uint8_t cycles = 0;
private:
	Bus* bus = nullptr;
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr);
	uint8_t GetFlag(FLAGS f);
	void SetFlag(FLAGS f, bool v);

	struct INSTRUCTION
	{
		std::string name;
		uint8_t(olc6502::* operate)(void) = nullptr;
		uint8_t(olc6502::* addrmode)(void) = nullptr;
		uint8_t     cycles = 0;
	};
	std::vector<INSTRUCTION> lookup;
};

