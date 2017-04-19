#ifndef HEADERPROCESS
#define HEADERPROCESS
#include <stdio.h>
#include "commonStructure.h"

//main process
extern void generatePreamble(complex32* oneStreamOfSTF,
                             complex32* oneStreamOfLTF,
                             unsigned char* SigInfo,
                             complex32* oneStreamOfSig,
                             int NTXindex);

extern void generateSTF(complex32* oneStreamOfSTF, int NTXindex);
extern void generateLTF(complex32* oneStreamOfLTF, int NTXindex);
extern void generateSig(complex32* basicSig, complex32* oneStreamOfSig, int NTXindex);
extern void setSigInfo(unsigned char* SigInfo, int length);

//main process bfcsd
extern void generatePreamble_csd(complex32* oneStreamOfSTF,
                             complex32* oneStreamOfLTF,
                             unsigned char* SigInfo,
                             complex32* oneStreamOfSig,
                             int NTXindex);

extern void generateSTF_csd(complex32* oneStreamOfSTF, int NTXindex);
extern void generateLTF_csd(complex32* oneStreamOfLTF, int NTXindex);
extern void generateSig_csd(complex32* basicSig, complex32* oneStreamOfSig, int NTXindex);

extern void generateHeLTF_csd(complex32* pHeLTFStart,int NTX_index,int n_ltf);

//sub process
extern void csdForPreamble(complex32* pStreamBfcsd,
                           complex32* pStreamAfcsd,
                           int NTXindex, int length);

extern int csTableForPreamble(int Ntxindex);
extern complex32 expComlex32(float phase, int i);

extern void csdForHeLTF(complex32* pStreamBfcsd, complex32* pStreamAfcsd, int NTXindex, int length);
extern int numberOfHeLTF();

extern void addCPforPreamble(complex32* pAfterIFFT,
                             complex32* pBeforeAddWin,
                             int NTXindex);

extern void addCPforSig(complex32* pAfterIFFT,
                             complex32* pBeforeAddWin,
                             int NTXindex);

extern void generateBasicSig(complex32* basicSig,
                             unsigned char* SigInfo, int length);

extern void ccodedot11_init();
extern void ccodedot11_encode (unsigned int numbytes,
		                       unsigned char *inPtr,
		                       unsigned char *outPtr,
                               unsigned char puncturing);

extern void bccInterleaverForSig(unsigned char* sigAfterBCC, int length);

extern void MapForSig(unsigned char* sigAfterBCC,
                      complex32* sigAfterMap,
                      int length);

//for print
extern void printForCpmlex(complex rp);
extern void printForCpmlex32(complex32 rp);
extern void printStreamToFile(complex32* pData, int length, FILE* fp);

//IFFT
extern void IFFT(complex* src,complex* dst,int size_n);

extern void ifftShiftandIFFTPreamble(complex32* pstfAfterCSD,
                                     complex32* pAfterIFFT,
                                     int N_tone);

#endif // HEADERPROCESS
