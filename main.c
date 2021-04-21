#include <cdvdman.h>
#include <elf-loader.h>
#include <fcntl.h>
#include <loadfile.h>
#include <sifrpc.h>
#include <stdio.h>
#include <sbv_patches.h> //sbeve

extern u8 cdfs_irx[];
extern int size_cdfs_irx;

char *target = "cdfs:/BOOT.ELF";
int main(int argc, char *argv[])
{
  sbv_patch_enable_lmb();
  sbv_patch_disable_prefix_check();
  SifInitRpc(0);
  sceCdInit(SCECdINoD);
  SifExecModuleBuffer(cdfs_irx, size_cdfs_irx, 0, NULL, NULL);
  sceCdDiskReady(0);
  sceCdSync(0);
  
  printf("[autoboot] Loading %s...\n", target);
  return LoadELFFromFile(target, 0, NULL);
}
