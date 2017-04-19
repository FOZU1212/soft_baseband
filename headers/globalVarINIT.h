#ifndef HEADGLOBALVAR
#define HEADGLOBALVAR

#include "../headers/commonStructure.h"
#define N_STS 4
#define N_TX 4
#define N_RX 4
#define PI 3.14159265359;
#define MKSUREENMEM(p) if(p==NULL){\
        printf("Not enougth memory!\n");\
        exit(1);}

extern int  dotscale;
extern int	BW;
extern int	Band;
extern int	SampRate;
extern int	MCS;
extern int	APEP_LEN;//data length
extern int	delta_f;
extern int  lIsMu;//not MU
extern int	CpLen;
extern int  CodeTypeIsBcc;//is BCC
extern char* ChannelMode;

extern complex32 regForAddWin[N_TX][3];
extern complex32 basicSTF[53];
extern complex32 basicLTF[53];
extern int CyclicShiftTable[36];

//HE LTF
extern complex32 basicHeLTF[256];
extern int pilot_index[8];
extern complex32* P[8];
extern int* shiftTableForHeLTF[8];

//data
extern int subcar;
extern int N_tone;
extern int N_pilot;

#endif // HEADGLOBALVAR
