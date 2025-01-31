#
# ATXmega128a3 template
# Type: avr:106
#

#SHELL:=$( /usr/bin/env bash)

export PATH := /usr/local/avr8-gnu-toolchain-linux_x86_64/bin:${PATH}

CC=avr-gcc
CXX=avr-g++
AS=avr-as
AR=avr-ar
SIZE=avr-size

ARCH=atxmega128a3

TARGET=build/atxmega.a

# Boot loader-related objects
OBJS=obj/arp.o obj/dhcp.o obj/icmp.o obj/ip.o obj/tcp.o obj/udp.o

# Application modules
#OBJS+=obj/main.o obj/eeprom.o

ASFLAGS=-mmcu=${ARCH}
#CFLAGS=-O2 -g -mmcu=${ARCH} -flto -Iinclude
CFLAGS=-Og -g -mmcu=${ARCH} -Iinclude
LDFLAGS=-Wl,"-Tld/atxmega128a3.ld" -Xlinker -Map=${TARGET}.map
ARFLAGS=r


.PHONY: all
all: ${TARGET}
	${SIZE} ${TARGET}

${TARGET}: ${OBJS}
	${AR} ${ARFLAGS} ${TARGET} ${OBJS}

.PHONY: bootloader
bootloader:
	( cd atxmega_bootloader ; make )
	echo "Bootloader ready"


obj/%.o: src/%.c
	mkdir -p obj
	${CC} -c ${CFLAGS} -o $@ $<

obj/%.o: src/%.cpp
	mkdir -p obj
	echo ${CXX}
	${CXX} -c ${CFLAGS} -o $@ $<

obj/%.o: src/%.s
	mkdir -p obj
	${AS} -c ${ASFLAGS} -o $@ $<

.PHONY: clean
clean:
	rm -f ${OBJS} ${TARGET} build/* *.map 

