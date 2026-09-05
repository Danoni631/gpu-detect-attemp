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

// Again, this file is unnecessary because NovaOS have a pci detect system

#include <stdint.h>

#include "ports.h"
#include "pci.h"

DWORD pci_config_read_DWORD(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset)
{
    uint32_t Addr;
    uint32_t lbus = (uint32_t)bus;
    uint32_t lslot = (uint32_t)slot;
    uint32_t lfunc = (uint32_t)func;
    uint32_t temp = 0;

    Addr =
    (uin32_t)
    (
        (lbus << 16) | (lslot << 11) | (lfunc << 8) |
        (offset & 0xfc) | ((DWORD)0x80000000)
    );

    outl(PCI_CONFIG_ADDRESS, Addr);
    temp = inl(PCI_CONFIG_DATA);

    return temp;
}
