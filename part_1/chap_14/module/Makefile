TARGET			= MODULE

CSRCS			= MODULE1.C MODULE3.C MODULE2.C

COBJS			= MODULE1.OBJ MODULE3.OBJ MODULE2.OBJ

CC			= BCC
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
