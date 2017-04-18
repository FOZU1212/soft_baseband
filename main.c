#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include "main.h"

//#define RUNBFCSD
//#ifdef RUNBFCSD

int numberOfHeLTF(){
    int ntx=N_TX;
    if(!(ntx&(ntx-1))) return ntx;
    else return ntx+1;
}

int numberOfData(){
    int N_service = 16;
    int N_tail = 6;
    unsigned char rate_type;
    int N_BPSCS, N_DBPS,N_CBPS, N_ES, N_SYM;
    mcs_table_for_20M((unsigned char *)&rate_type, (int *)&N_BPSCS, (int *)&N_DBPS, (int *)&N_CBPS, (int *)&N_ES);
    N_SYM = ceil(((double)(8*APEP_LEN + N_service + N_tail*N_ES) / (double)N_DBPS));
    return N_SYM;
}


int main(int argc, char* argv[]){
    //#define DEBUGSTABLE
    #ifdef DEBUGSTABLE
    int n=10000;
    while(n--){
    #endif
    complex32* STF[N_TX];
    complex32* LTF[N_TX];
    complex32* Sig[N_TX];
    //set the information of sig
    unsigned char SigInfo[3];
    setSigInfo(SigInfo,3);
    int i=0;
    for(i=0;i<N_STS;i++){
        STF[i]=(complex32*)malloc(64*sizeof(complex32));
        LTF[i]=(complex32*)malloc(64*sizeof(complex32));
        Sig[i]=(complex32*)malloc(64*sizeof(complex32));
        MKSUREENMEM(STF[i]);
        MKSUREENMEM(LTF[i]);
        MKSUREENMEM(Sig[i])
        memset(STF[i],0,64*sizeof(complex32));
        memset(LTF[i],0,64*sizeof(complex32));
        memset(Sig[i],0,64*sizeof(complex32));
        complex32* pStfStart = STF[i];
        complex32* pLtfStart = LTF[i];
        complex32* pSigStart = Sig[i];
        generatePreamble_csd(pStfStart,pLtfStart,SigInfo,pSigStart,i);
    }
    //HE LTF
    complex32* heLTF[N_TX];
    //length of HeLTF
    int n_ltf=numberOfHeLTF();
    for(i=0;i<N_TX;i++){
        heLTF[i]=(complex32*)malloc(n_ltf*256*sizeof(complex32));
        complex32* pHeLTFStart=heLTF[i];
        generateHeLTF_csd(pHeLTFStart,i,n_ltf);
    }
    //data process
    //传入数据databits
    unsigned char* databits=(unsigned char*)malloc(APEP_LEN*sizeof(unsigned char));
    FILE *fp=fopen("send_din_dec.txt","rt");
    unsigned int datatmp=0;
    for(i=0;i<APEP_LEN;i++){
            fscanf(fp,"%ud",&datatmp);
            databits[i]=datatmp&0x000000FF;
    }
    fclose(fp);
    //生成CSD之前的data部分
    //int numberOfData();
    int N_SYM=numberOfData();
    complex32 *csd_data[N_STS];
    for(i=0;i<N_STS;i++)
    {
        csd_data[i] = (complex32 *)malloc(sizeof(complex32)*(subcar*N_SYM));
        MKSUREENMEM(csd_data[i]);
    }
    GenerateData(databits, csd_data);
    //save data
    int j;
    FILE *a=fopen("csd_data_real.txt","wt");                                       //将结果写入文件
    FILE *b=fopen("csd_data_imag.txt","wt");
    for(i=1;i<=N_STS;i++)for(j=1;j<=(subcar*N_SYM);j++)fprintf(a,"%d\n",csd_data[i-1][j-1].real);
    for(i=1;i<=N_STS;i++)for(j=1;j<=(subcar*N_SYM);j++)fprintf(b,"%d\n",csd_data[i-1][j-1].imag);
    fclose(a);
    fclose(b);
    //save STF data
    /*FILE* fp=fopen("STF_csd.txt", "w");
    for(i=0;i<N_TX;i++) printStreamToFile(STF[i],64,fp);
    fclose(fp);
    //save LTF data
    fp=fopen("LTF_csd.txt", "w");
    for(i=0;i<N_TX;i++) printStreamToFile(LTF[i],64,fp);
    fclose(fp);
    //save Sig data
    fp=fopen("Sig_csd.txt", "w");
    for(i=0;i<N_TX;i++) printStreamToFile(Sig[i],64,fp);
    fclose(fp);
    //save HeLTF data
    fp=fopen("HeLTF_csd.txt", "w");
    for(i=0;i<N_TX;i++) printStreamToFile(heLTF[i],n_ltf*256,fp);
    fclose(fp);*/
    //free malloc data
    for(i=0;i<N_TX;i++) free(STF[i]);
    for(i=0;i<N_TX;i++) free(LTF[i]);
    for(i=0;i<N_TX;i++) free(Sig[i]);
    for(i=0;i<N_TX;i++) free(heLTF[i]);
    for(i=0;i<N_STS;i++) free(csd_data[i]);
    free(databits);
    #ifdef DEBUGSTABLE
    }
    #endif
    //main return
    return 0;
}


/*
void printStream(complex32* pData, int length){
    int n=length;
    while(n--){
        printForCpmlex32(*pData++);
    }
}

void printStreamToFile(complex32* pData, int length, FILE* fp){
    int n=length;
    while(n--){
        fprintf(fp,"%d %d\n",pData->real,pData->imag);
        ++pData;
    }
}
*/
//#endif // RUN

