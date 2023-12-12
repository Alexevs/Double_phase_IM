#include "math.h"
#include "cgen.h"
#include "c2000.h"
int MHZ=90;
#define _SYS_MHZ_ 90
static int __Out_27;
static int __Out_58;
static int ha;
static int hb;
static int pp;
static int pn;
static int nn;
static int np;
static int p1;
static int p2;
static int p3;
static int p4;
static int p5;
static int p6;
static int Ibz;
static int Iaz;
static int Ia_op;
static int Ib_op;
static int Ia;
static int Ib;
static int Ia_up;
static int Ia_down;
static int amp;

extern CGDOUBLE Zed;

static SIM_STATE tSim={0,0,0
,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0};
SIM_STATE *sim=&tSim;
static INTERRUPT void cgMain()
{
static int _delayOutBuf25=0;
static int _delayOutBuf202=0;
static int _delayOutBuf56=24576;
static int _delayOutBuf218=0;
  int t17;
  int t20;
  int t10;
  int t12;
  int t6;
  int t68;
  int t211;
  int t196;
  int t200;
  int t195;
  int t201;
  int t203;
  int t204;
  int t48;
  int t51;
  int t41;
  int t43;
  int t37;
  int t70;
  int t206;
  int t219;
  int t220;
  int t143;
  int t144;
  int t147;
  int t153;
  int t96;
  int t126;
  PIEACK = 0x1; // Reset PIE IFLG
  t17 = ( _delayOutBuf25+16);
  t20 = (32751< t17);
  __Out_27 =  _delayOutBuf25;
  t10 = (( t20?-32768 /* -1@fx1.16 */:0 /* 0@fx1.16 */)+ __Out_27 );
  t12 = ( t10+16);
  t6 = ( t20? t12: t17);
  amp = (MUL_SHIFT16((short)((GPADAT & 0x1000L)!=0),31457,4)/* 0.06@fx1.16 */+983 /* 0.03@fx1.16 */);
  t68 = 16089 /* 0.491@fx1.16 */;
  Iaz = (MUL_SHIFT16( amp ,fxSin( _delayOutBuf25),15)+ t68);
  Ia = ADCRESULTNWS0;
  t211 = ( Iaz - (( Ia )<<3));
  t196 = 0 /* 3e-005@fx1.16 */;
  t200 = ( t211> t196);
  t195 = 0 /* -3e-005@fx1.16 */;
  t201 = ( t211< t195);
  t203 = !((int)(((int) _delayOutBuf202)|((int) t201)));
  t204 = !((int)(((int) t200)|((int) t203)));
  t48 = ( _delayOutBuf56+16);
  t51 = (32751< t48);
  __Out_58 =  _delayOutBuf56;
  t41 = (( t51?-32768 /* -1@fx1.16 */:0 /* 0@fx1.16 */)+ __Out_58 );
  t43 = ( t41+16);
  t37 = ( t51? t43: t48);
  t70 = 15564 /* 0.475@fx1.16 */;
  Ibz = (MUL_SHIFT16( amp ,fxSin( _delayOutBuf56),15)+ t70);
  Ib = ADCRESULTNWS6;
  t206 = ( Ibz - (( Ib )<<3));
  t219 = !((int)(((int) _delayOutBuf218)|((int)( t206< t195))));
  t220 = !((int)(((int)( t206> t196))|((int) t219)));
  ha =  t203;
  hb =  t219;
  Ia_op =  t68;
  t143 = ( Iaz > Ia_op );
  Ib_op =  t70;
  t144 = ( Ibz > Ib_op );
  pp = (((int) t143)&((int) t144));
  t147 = !((int) t144);
  pn = (((int) t143)&((int) t147));
  t153 = !((int) t143);
  nn = (((int) t153)&((int) t147));
  np = (((int) t153)&((int) t144));
  p1 = (((int)(((int)(((int) ha )&((int)!((int) hb ))))&((int) pp )))|((int)(((int) ha )&((int) pn )))|((int)(((int)0)&((int) nn )))|((int)
	(((int)0)&((int) np ))));
  t96 = !((int) ha );
  p2 = (((int)(((int) t96)&((int) pp )))|((int)(((int)(((int) t96)&((int) hb )))&((int) pn )))|((int)(((int) t96)&((int) nn )))|((int)
	(((int) t96)&((int) np ))));
  p3 = (((int)(((int) pp )&((int)0)))|((int)(((int) pn )&((int)!((int) hb ))))|((int)(((int)!((int)(((int) hb)&((int) ha ))))&((int)
	 nn )))|((int)(((int)(((int)!((int) hb))&((int)!((int) ha))))&((int) np ))));
  t126 = !((int)(((int)!((int) ha ))&((int)!((int) hb ))));
  p4 = (((int)(((int) t126)&((int) pp )))|((int)(((int) hb )&((int) pn )))|((int)(((int)(((int) hb)&((int) ha )))&((int) nn )))|((int)
	(((int) t126)&((int) np ))));
  p5 = (((int)(((int) hb )&((int) pp )))|((int)(((int)(((int) hb)&((int) ha )))&((int) pn )))|((int)(((int)(((int) hb)&((int)!((int)
	 ha))))&((int) nn )))|((int)(((int) hb)&((int) np ))));
  p6 = !((int) hb );
  { long _duty32 = (long)16384 /* 0.5@fx1.16 */*421;
    CMPA4 = (int)(_duty32>>15);
  }
;
  { long _duty32 = (long)((short) p1 *32766)/* 0.999969@fx1.16 */*3001;
    CMPA1 = (int)(_duty32>>15);
  }
  CMPB1 = (int)(((long)((short) p2 *32766)/* 0.999969@fx1.16 */*3001)>>15);
  { long _duty32 = (long)((short) p3 *32766)/* 0.999969@fx1.16 */*3001;
    CMPA2 = (int)(_duty32>>15);
  }
  CMPB2 = (int)(((long)((short) p4 *32766)/* 0.999969@fx1.16 */*3001)>>15);
  { long _duty32 = (long)((short) p5 *32766)/* 0.999969@fx1.16 */*3001;
    CMPA3 = (int)(_duty32>>15);
  }
  CMPB3 = (int)(((long)((short) p6 *32766)/* 0.999969@fx1.16 */*3001)>>15);

  _delayOutBuf218 =  t220;
  _delayOutBuf56 =  t37;
  _delayOutBuf202 =  t204;
  _delayOutBuf25 =  t6;
  endOfSampleCount = TIMER0TIM;

}

void main()
{
  EALLOW;
  CLKCTL &= ~CLK_INTOSC1OFF;	//Internal Osc 1
  CLKCTL &= ~CLK_OSCCLKSRCSEL;
  CLKCTL |= CLK_INTOSC2OFF|CLK_XTALOSCOFF|CLK_XCLKINOFF;
  PLLSTS = 0x10; // reset clk check
  WDCR=0x00ef;	// Disable Watchdog
  asm("	clrc DBGM");
  if (!(PLLSTS&8))	// Skip PLL set if OSC failure
    { PLLSTS = 0x40;	//Disable OSC check
      PLLSTS = 0x180;	//Enable OSC check (&F283xx /2 mode)
      PLLCR = 0x9;	// set PLL to 9xOSC = 90 MHZ;
    }
  HISPCP = 0x0;    // HCLK  = 90 MHZ
  PCLKCR0 = 0x8;
  PCLKCR1 = 0xF;
  PCLKCR3 = 0x100;
  EDIS;
  TBPRD1 = 0xbb8;
  AQCTLA1 = 0x12;
  AQCTLB1 = 0x102;
  DBCTL1 = 0x10;
  DBRED1 = 0x64;
  DBFED1 = 0x64;
  EALLOW;
  TZCTL1 = 0x0;
  TZSEL1 = 0x0;
  DCACTL1 = 0x0;
  DCBCTL1 = 0x0;
  EDIS;
  TBPRD2 = 0xbb8;
  AQCTLA2 = 0x12;
  AQCTLB2 = 0x102;
  DBCTL2 = 0x10;
  DBRED2 = 0x64;
  DBFED2 = 0x64;
  EALLOW;
  TZCTL2 = 0x0;
  TZSEL2 = 0x0;
  DCACTL2 = 0x0;
  DCBCTL2 = 0x0;
  EDIS;
  TBPRD3 = 0xbb8;
  AQCTLA3 = 0x12;
  AQCTLB3 = 0x102;
  DBCTL3 = 0x10;
  DBRED3 = 0x64;
  DBFED3 = 0x64;
  EALLOW;
  TZCTL3 = 0x0;
  TZSEL3 = 0x0;
  DCACTL3 = 0x0;
  DCBCTL3 = 0x0;
  EDIS;
  TBPRD4 = 0x1a4;
  AQCTLA4 = 0x21;
  AQCTLB4 = 0x12;
  ETSEL4 = 0xa00;
  ETPS4 = 0x1100;
  EALLOW;
  TZCTL4 = 0x0;
  TZSEL4 = 0x0;
  DCACTL4 = 0x0;
  DCBCTL4 = 0x0;
  EDIS;
 simInit( 0 );
  EALLOW;
  Device_cal();	// Call on chip calibration
  EALLOW;
  ADCCTL2 = 0x1;  // ADCCLK = 45
  ADCCTL1 = 0x40E0;  // Power up ADC
  ADCSOC0CTL = 0x583F; // ADCINA0, SOC = ePWM4:ADCSOCA
  ADCSOC6CTL = 0x59BF; // ADCINA6, SOC = ePWM4:ADCSOCA
  EDIS;
  EALLOW;
  GPAMUX1 = 0x5555;
  EDIS;
  startSimDsp();
  installInterruptVec(1,7,&cgMain);
  TIMER0PRD = 0x2328; // 32-bit Timer Period Low
  TIMER0PRDH = 0x0; // 32-bit Timer Period High
  TIMER0TCR |= 0x4020; //Interrupt enable, Timer Reset
  EALLOW;
  PIECTRL = 1; // Enable PIE Interrupts
  EDIS;
  IER |= 0x1; //CPU Interrupt enable
  resetInterrupts();
  enable_interrupts();  // Global Start Interrupts
  TBCTL1 = 0x400; // Start timer
  TBCTL2 = 0x400; // Start timer
  TBCTL3 = 0x400; // Start timer
  TBCTL4 = 0x0; // Start timer
  EALLOW;
  PCLKCR0 |= 0x4; // Start all PWM timers
  EDIS;
  dspWaitStandAlone();
}
