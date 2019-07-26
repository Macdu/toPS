#pragma once

#include "cpu/CPU.h"
#include "Bios.h"
#include "RAM.h"
#include "DMA.h"
#include "gpu/GPU.h"

class RenderWindow;

class Emulator {
public:

	void init(RenderWindow* window, vk::Instance instance, vk::SurfaceKHR surface);

	// import the bios
	void importBIOS();

	// reset the emulator
	void reset();

	// called when the window is closed
	void destroy();

	// Executes the emulator until a frame is rendered
	void renderFrame();

	Bios* getBios() { return &bios; };
	RAM* getRam() { return &ram; };
	CPU* getCPU() { return &cpu; };
	DMA* getDMA() { return &dma; };
	GPU* getGPU() { return &gpu; };

private:
	CPU cpu;
	Bios bios;
	RAM ram;
	DMA dma;
	GPU gpu;
	RenderWindow* renderSurface;
};