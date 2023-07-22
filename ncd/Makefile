TARGET			= ncd

CSRCS			= $(TARGET).C PULLDOWN.C

COBJS			= $(TARGET).OBJ PULLDOWN.OBJ

CC			= TCC
CFLAGS			= -w
LDFLAGS			= -w
LIBS                    = GRAPHICS.LIB

.C.OBJ:
	$(CC) $(CFLAGS) -c $<

$(TARGET).EXE: $(COBJS)
	$(CC) $(LDFLAGS) -e$(TARGET).EXE $(COBJS) $(LIBS)

all: $(TARGET).EXE

run: $(TARGET).EXE
	$(TARGET).EXE

clean:
	COMMAND /C DEL /Q $(COBJS)
	COMMAND /C DEL /Q $(TARGET).EXE
