#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <elf.h>
void chec(unsigned char *id);
void prinm(unsigned char *id);
void princ(unsigned char *id);
void prind(unsigned char *id);
void prinv(unsigned char *id);
void prina(unsigned char *id);
void prino(unsigned char *id);
void print(unsigned int et, unsigned char *id);
void prine(unsigned long int ee, unsigned char *id);
void close(int elf);
/**
 * chec - Check
 * @id: pointer
 */
void chec(unsigned char *id)
{
    int in;

    for (in = 0; in < 4; in++)
    {
        if (id[in] != 127 &&
            id[in] != 'E' &&
            id[in] != 'L' &&
            id[in] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}
/**
 * prinm - Print magic number
 * @id: pointer
 */
void prinm(unsigned char *id)
{
    int in;

    printf(" Magic: ");

    for (in = 0; in < EI_NIDENT; in++)
    {
        printf("%02x", id[in]);

        if (in == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}
/**
 * princ - Print class
 * @id: pointer
 */
void princ(unsigned char *id)
{
    printf(" Class: ");

    switch (id[EI_CLASS])
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
        printf("<unknown: %x>\n", id[EI_CLASS]);
    }
}
/**
 * prind - Print data
 * @id: pointer
 */
void prind(unsigned char *id)
{
    printf(" Data: ");

    switch (id[EI_DATA])
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
        printf("<unknown: %x>\n", id[EI_CLASS]);
    }
}

/**
 * prinv - Print version
 * @id: pointer
 */
void prinv(unsigned char *id)
{
    printf(" Version: %d",
           id[EI_VERSION]);

    switch (id[EI_VERSION])
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
 * prino - Print OS/ABI
 * @id: pointer
 */
void prino(unsigned char *id)
{
    printf(" OS/ABI: ");

    switch (id[EI_OSABI])
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
        printf("<unknown: %x>\n", id[EI_OSABI]);
    }
}

/**
 * prina - Print ABI
 * @id: pointer
 */
void prina(unsigned char *id)
{
    printf(" ABI Version: %d\n",
           id[EI_ABIVERSION]);
}

/**
 * print - Print type
 * @et: type
 * @id: pointer
 */
void print(unsigned int et, unsigned char *id)
{
    if (id[EI_DATA] == ELFDATA2MSB)
        et >>= 8;

    printf(" Type: ");

    switch (et)
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
        printf("<unknown: %x>\n", et);
    }
}

/**
 * prine - Print entry point
 * @ee: address
 * @id: pointer
 */
void prine(unsigned long int ee, unsigned char *id)
{
    printf(" Entry point address: ");

    if (id[EI_DATA] == ELFDATA2MSB)
    {
        ee = ((ee << 8) & 0xFF00FF00) |
             ((ee >> 8) & 0xFF00FF);
        ee = (ee << 16) | (ee >> 16);
    }

    if (id[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)ee);

    else
        printf("%#lx\n", ee);
}

/**
 * close - Closes
 * @elf: integer
 */
void close(int elf)
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
 * @c: number
 * @v: pointer
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) c, char *v[])
{
    Elf64_Ehdr *h;
    int op, a;

    op = open(v[1], O_RDONLY);
    if (op == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", v[1]);
        exit(98);
    }
    h = malloc(sizeof(Elf64_Ehdr));
    if (h == NULL)
    {
        close(op);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", v[1]);
        exit(98);
    }
    a = read(op, h, sizeof(Elf64_Ehdr));
    if (a == -1)
    {
        free(h);
        close(op);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", v[1]);
        exit(98);
    }

    chec(h->id);
    printf("ELF Header:\n");
    prinm(h->id);
    princ(h->id);
    prind(h->id);
    prinv(h->id);
    prino(h->id);
    prina(h->id);
    print(h->et, h->id);
    prine(h->ee, h->id);

    free(h);
    close(op);
    return (0);
}
