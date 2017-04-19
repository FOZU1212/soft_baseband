OBJS = addCPforPreamble.o addCPforSig.o bccInterleaverForSig.o
OBJS += csdForHeLTF.o csdForPreamble.o generateBasicSig.o
OBJS += generateHeLTF_csd.o generateLTF.o generateLTF_csd.o
OBJS += generatePreamble.o generatePreamble_csd.o generateSig.o
OBJS += generateSig_csd.o generateSTF.o generateSTF_csd.o
OBJS += MapForSig.o setSigInfo.o
all:$(OBJS)

$(OBJS):%.o:%.c
	$(CC) -c $< -o $(OBJSDIR)/$@ $(CFLAGS)

clean:
	$(RM) $(OBJS)