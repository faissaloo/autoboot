#  ____     ___ |    / _____ _____
# |  __    |    |___/    |     |
# |___| ___|    |    \ __|__   |     gsKit Open Source Project.
# ----------------------------------------------------------------------
# Copyright 2004 - Chris "Neovanglist" Gilbert <Neovanglist@LainOS.org>
# Licenced under Academic Free License version 2.0
# Review gsKit README & LICENSE files for further details.
#

EE_BIN_PKD = autoboot.elf
EE_BIN  = autoboot-uncompressed.elf
EE_OBJS = main.o

EE_LIBS += -lelf-loader -lcdvd #-lpad -lmc -lgskit -ldmakit
EE_LDFLAGS := -L$(PS2DEV)/gsKit/lib -L$(PS2SDK)/ports/lib -s
EE_INCS := -I$(PS2DEV)/gsKit/include -I$(PS2SDK)/ports/include

BIN2S = $(PS2SDK)/bin/bin2s

all: $(EE_BIN_PKD)
	
$(EE_BIN_PKD): $(EE_BIN)
	ps2-packer $< $@

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
