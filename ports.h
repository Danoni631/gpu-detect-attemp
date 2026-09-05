#include <stdint.h>

// This file is unnecessary because NovaOS have io ports
void outl(uint16_t port, uint32_t value);
uint32_t inl(uint16_t port);
