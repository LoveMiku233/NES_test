#pragma once
#include <cstdint>
#include "olc6502.h"
#include <array>
class Bus
{
public:
	//device �����ϵ��豸
	olc6502 cpu;

	//RAM ����ģ��
	std::array<uint8_t, 64 * 1024> ram;
	//func
	Bus();
	~Bus();

	//����д����
	void write(uint16_t addr, uint8_t data);
	//���߶�����
	uint8_t read(uint16_t addr);
};

