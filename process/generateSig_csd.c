#include "../commonStructure/commonStructure.h"
#include "../process/process.h"
#include "../globalVarINIT/globalVarINIT.h"
#include <stdlib.h>
#include <memory.h>
#include <math.h>

void generateSig_csd(complex32* basicSig, complex32* oneStreamOfSig, int NTXindex){
     int lengthAfterCSD=57;
     //complex32* psigAfterCSD=(complex32*)malloc(64*sizeof(complex32));
     //MKSUREENMEM(psigAfterCSD);
     //memset(psigAfterCSD,0,64*sizeof(complex32));
     //CSD for LTF
     csdForPreamble(basicSig+4, oneStreamOfSig+4, NTXindex, lengthAfterCSD);
     //for test
     /*FILE* fp=fopen("sigAfterCSD.txt","w");
     printStreamToFile(psigAfterCSD,64,fp);
     fclose(fp);*/
     //for test
}
