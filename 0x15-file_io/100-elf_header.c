#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

void elfCheck(unsigned char *e_ident);
void printMagic(unsigned char *e_ident);
void printClass(unsigned char *e_ident);
void printData(unsigned char *e_ident);
void printVersion(unsigned char *e_ident);
void printAbi(unsigned char *e_ident);
void printOsabi(unsigned char *e_ident);
void printType(unsigned int e_type, unsigned char *e_ident);
void printEntry(unsigned long int e_entry, unsigned char *e_ident);
void closeElf(int elf);

/**
 * elfCheck - Check
 * @e_ident:pointer
 */
void elfCheck(unsigned char *e_ident)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printMagic - Print magic numbers
 * @e_ident: pointer
 */
void printMagic(unsigned char *e_ident)
{
    int index;

    printf(" Magic: ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printClass - Print class
 * @e_ident: pointer
 */
void printClass(unsigned char *e_ident)
{
    printf(" Class: ");

    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printData - Print data
 * @e_ident: pointer
 */
void printData(unsigned char *e_ident)
{
    printf(" Data: ");

    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printVersion - Print version
 * @e_ident: pointer
 */
void printVersion(unsigned char *e_ident)
{
    printf(" Version: %d",
           e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * printOsabi - Print OS/ABI
 * @e_ident: pointer
 */
void printOsabi(unsigned char *e_ident)
{
    printf(" OS/ABI: ");

    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/**
 * printAbi - PrintABI version
 * @e_ident: pointer
 */
void printAbi(unsigned char *e_ident)
{
    printf(" ABI Version: %d\n",
           e_ident[EI_ABIVERSION]);
}

/**
 * printType - Print type 
 * @e_type: type.
 * @e_ident: pointer
 */
void printType(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf(" Type: ");

    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

/**
 * printEntry - Print entry point
 * @e_entry: address
 * @e_ident: pointer
 */
void printEntry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf(" Entry point address: ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);

    else
        printf("%#lx\n", e_entry);
}

/**
 * closeElf - Closes
 * @elf: file descriptor
 */
void closeElf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

/**
 * main - Displays
 * @argc: number
 * @argv: pointer
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *header;
    int o, r;

    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        closeElf(o);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    r = read(o, header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        free(header);
        closeElf(o);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    elfCheck(header->e_ident);
    printf("ELF Header:\n");
    printMagic(header->e_ident);
    printClass(header->e_ident);
    printData(header->e_ident);
    printVersion(header->e_ident);
    printOsabi(header->e_ident);
    printAbi(header->e_ident);
    printType(header->e_type, header->e_ident);
    printEntry(header->e_entry, header->e_ident);

    free(header);
    closeElf(o);
    return (0);
}
