	JSUB	READ
	JSUB	WRITE

READ	LDX	ZERO
RLOOP	TD	INDEV
	JEQ	RLOOP
RC	RD	INDEV
	COMP	CHA
	JLT	NOBIG
	COMP	CHZ
	JGT	NOBIG
	SUB	TOBIG
NOBIG	STCH	DATA,X
	TIX	HUND
	COMP	MONEY
	JLT	RC
	JGT	RC
	RSUB	

WRITE	LDX	ZERO
WLOOP	TD	OUTDEV
	JEQ	WLOOP
	LDCH	DATA,X
WC	WD	OUTDEV
	TIX	HUND
	LDCH	DATA,X
	COMP	MONEY
	JLT	WC
	JGT	WC
	RSUB

INDEV	BYTE	X'F1'
OUTDEV 	BYTE	X'F2'
DATA	RESB	50
ZERO	WORD	0
ONE	WORD	1
TOBIG	WORD 	32
MONEY	WORD	36
CHA	WORD	97
CHZ	WORD	122
HUND	WORD	50