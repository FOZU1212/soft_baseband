#ifndef IFFT_H
#define IFFT_H

#include "../process/process.h"
#include "../commonStructure/commonStructure.h"
#include "../globalVarINIT/globalVarINIT.h"

void Add_Complex(complex* src1,complex* src2,complex* dst);
void Sub_Complex(complex* src1,complex* src2,complex* dst);
void Multy_Complex(complex* ra,complex* rb,complex* dst);
void Divide_Complex(complex* ra,complex* rb,complex* dst);
void getWN(float n,float size_n,complex* dst);
void DFT(complex* src,complex* dst,int size);
void IDFT(complex* src,complex* dst,int size);
int FFT_remap(complex* src,int size_n);
void FFT(complex* src,complex* dst,int size_n);
void IFFT(complex* src,complex* dst,int size_n);

void ifftShiftandIFFTPreamble(complex32* pstfAfterCSD,complex32* pAfterIFFT,int N_tone);

#endif // ALLHEADERS
