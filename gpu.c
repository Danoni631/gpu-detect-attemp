/*
MIT License

Copyright (c) 2026 DaniloSenseiPlus

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdint.h>
#include "ports.h"
#include "pci.h"

#include "gpu.h"

#define NVIDIA 0x10DE
#define AMD 0x1002
#define INTEL 0x8086

const char* get_gpu_vendor(uint16_t vendor)
{
    switch (vendor)
    {
        case NVIDIA: return "NVIDIA";
        case AMD: return "AMD";
        case INTEL: return "INTEL";
        default: return "Unknown";
    }
}

const char* get_gpu_name(uint16_t vendor, uint16_t device_id)
{
    if (vendor == NVIDIA)
    {
        return "NVIDIA Video cardboard";
    }

    if (vendor == AMD)
    {
        return "AMD Radeon";
    }

    if (vendor == INTEL)
    {
        return "Intel Graphics";
    }

    return "Unknown GPU";
}

// These functions are optional, but necessary for NovaOS
void show_gpu_name()
{
    for (uint8_t bus = 0; bus < 256; bus++)
    {
        for (uint8_t slot = 0; slot < 32; slot++) 
        {
            uint32_t data = pci_config_read_DWORD(bus, slot, 0, 0x00);
            uint16_t vendor_id = data & 0xFFFF;
            uint16_t device_id = (data >> 16) & 0xFFFF;
            
            if (vendor_id != 0xFFFF)
            {
                const CHAR* vendor = get_gpu_vendor(vendor_id);
                const CHAR* name = get_gpu_name
                (
                    vendor_id,
                    device_id
                );

                Print("GPU: ", 0xFF00FFFF);
                Print(vendor, 0xFFFFFFFF);
                Print(" - ", 0xFF00FFFF);
                Print(name, 0xFFFFFFFF);
                Print("\n", 0x00);
                return;
            }
        }
    }
}

void show_gpu_info()
{
    for (uint8_t bus = 0; bus < 256; bus++)
    {
        for (uint8_t slot = 0; slot < 32; slot++)
        {
            uint32_t data = pci_config_read_DWORD(bus, slot, 0, 0x00);
            uint16_t vendor_id = data & 0xFFFF;
            uint16_t device_id = (data >> 16) & 0xFFFF;

            const char* gpu_vendor = get_cpu_vendor(vendor_id);
            if (vendor_id != 0xFFFF)
            {
                Print("Vendor ID: ", 0xFFFFFFFF);
                PrintHex(vendor_id, 0xFFFFFFFF);
                Print(" (", 0xFFFFFFFF);
                Print(gpu_vendor, 0xFFFFFFFF);
                Print(")\n", 0xFFFFFFFF);

                Print("Device ID: ", 0xFFFFFFFF);
                PrintHex(device_id, 0xFFFFFFFF);
                Print(" (", 0xFFFFFFFF);
                Print(get_gpu_name(vendor_id, device_id), 0xFFFFFFFF);
                Print(")\n", 0xFFFFFFFF);
            }
        }
    }
}
