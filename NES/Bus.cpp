#include "Bus.h"

Bus::Bus() {
	//初始化数组
	for (auto& i : ram)i = 0x00;
	//连接CPU
	cpu.connectBus(this);
}

Bus::~Bus() {}

void Bus::write(uint16_t addr, uint8_t data) {
	//判断是否合法
	if(addr>=0x0000&&addr<=0xFFFF)
		ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr) {
	//直接返回
	if (addr >= 0x0000 && addr <= 0xFFFF)
		return ram[addr];
	//ERR
	return 0x00;
}