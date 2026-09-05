gcc -ffreestanding -m32 -g -c "gpu.c" -o "gpu.o"

# OPTIONAL
gcc -ffreestanding -m32 -g -c "pci.c" -o "pci.o"
gcc -ffreestanding -m32 -g -c "ports.c" -o "ports.o"
