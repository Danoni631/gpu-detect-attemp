#define PCI_CONFIG_ADDRESS 0xCF8
#define PCI_CONFIG_DATA 0xCFC

#include <stdint.h>

// In NovaOS this file is unnecessary, because NovaOS have PCI detect systen
DWORD pci_config_read_DWORD(BYTE bus, BYTE slot, BYTE func, BYTE offset);
