#pragma once
#include <cstdint>
#include "olc6502.h"
#include <array>
class Bus
{
public:
	//device 总线上的设备
	olc6502 cpu;

	//RAM 数组模拟
	std::array<uint8_t, 64 * 1024> ram;
	//func
	Bus();
	~Bus();

	//总线写函数
	void write(uint16_t addr, uint8_t data);
	//总线读函数
	uint8_t read(uint16_t addr);
};

