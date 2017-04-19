#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include "../process/process.h"
#include "../commonStructure/commonStructure.h"
#include "../globalVarINIT/globalVarINIT.h"

void generateLTF_csd(complex32* oneStreamOfLTF, int NTXindex){
     int lengthAfterCSD=53;
     //complex32* pltfAfterCSD=(complex32*)malloc(64*sizeof(complex32));
     //MKSUREENMEM(pltfAfterCSD);
     //memset(pltfAfterCSD,0,64*sizeof(complex32));
     //CSD for LTF
     csdForPreamble(basicLTF, oneStreamOfLTF+6, NTXindex, lengthAfterCSD);
     //for test
     /*FILE* fp=fopen("ltfAfterCSD.txt","w");
     printStreamToFile(pltfAfterCSD,64,fp);
     fclose(fp);*/
     //for test
}
