TARGET			= EX12_04

CSRCS			= $(TARGET).C

COBJS			= $(TARGET).OBJ

CC			= TCC
CFLAGS			= -w
LDFLAGS			= -w
LIBS                    =

.C.OBJ:
	$(CC) $(CFLAGS) -o$@ -c $<

$(TARGET).EXE: $(COBJS)
	$(CC) $(LDFLAGS) -e$(TARGET).EXE $(COBJS) $(LIBS)

all: $(TARGET).EXE

run: $(TARGET).EXE
	$(TARGET).EXE

clean:
	COMMAND /C DEL /Q $(COBJS)
	COMMAND /C DEL /Q $(TARGET).EXE
