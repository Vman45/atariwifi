/**
 * CIO Status call
 */

#include <atari.h>
#include <6502.h>
#include "sio.h"

extern unsigned char err;
extern unsigned char ret;

void _cio_status(void)
{
  OS.dcb.ddevic=0x70; // Network adapter
  OS.dcb.dunit=1;
  OS.dcb.dcomnd=0xD1;  // UDP status
  OS.dcb.dstats=0x40; // specify a read
  OS.dcb.dtimlo=0x1f; // Timeout
  OS.dcb.dbyt=4;
  OS.dcb.dbuf=&OS.dvstat; // A packet.
  OS.dcb.daux1=0;
  siov();
  err=OS.dcb.dstats;
}
