export CC = g++
export CFLAGS = -O2
export TARGET = cacu
export OBJSDIR = $(shell pwd)/objs
$(TARGET):$(OBJSDIR) main.o
	$(MAKE) -C BCCencode
	$(MAKE) -C commonStructure
	$(MAKE) -C globalVarINIT
	$(MAKE) -C IFFT
#	$(MAKE) -C integerTypeDef
	$(MAKE) -C process
	$(MAKE) -C process_data
	$(CC) -o $(TARGET) $(OBJSDIR)/*.o

$(OBJSDIR):
	mkdir -p $@

main.o:%.o:%.c
	$(CC) -c $< -o $(OBJSDIR)/$@ $(CFLAGS) -IBCCencode -IcommonStructure -IglobalVarINIT -IIFFT -IintegerTypeDef -Iprocess -Iprocess_data
clean:
	-$(RM) $(TARGET)
	-$(RM) $(OBJSDIR)/*.o