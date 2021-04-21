#include <elf-loader.h>
#include <stdio.h>

char *target = "cdfs:/BOOT.ELF";
int main(int argc, char *argv[])
{
  printf("[autoboot] Loading %s...", target);
  return LoadELFFromFile(target, 0, NULL);
}
