OBJS = BCC_encoder.o Data_CSD.o GenDataAndScramble.o GenInit.o mcs_table_for_20M.o modulate.o PilotAdd_SubcarMap.o process_data.o
all:$(OBJS)

$(OBJS):%.o:%.c
	$(CC) -c $< -o $(OBJSDIR)/$@ $(CFLAGS)

clean:
	$(RM) $(OBJS)