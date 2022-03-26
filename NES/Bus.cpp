#include "Bus.h"

Bus::Bus() {
	//��ʼ������
	for (auto& i : ram)i = 0x00;
	//����CPU
	cpu.connectBus(this);
}

Bus::~Bus() {}

void Bus::write(uint16_t addr, uint8_t data) {
	//�ж��Ƿ�Ϸ�
	if(addr>=0x0000&&addr<=0xFFFF)
		ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr) {
	//ֱ�ӷ���
	if (addr >= 0x0000 && addr <= 0xFFFF)
		return ram[addr];
	//ERR
	return 0x00;
}