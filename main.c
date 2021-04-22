/*
Copyright 2021 Faissal Isslam Bensefia

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
