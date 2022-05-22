# homework3 example

請參考課堂中提供的程式 (1-token.c, 2-optable.c 及 3-asm_pass1_u.c) 及 Figure 2.4(a) 的演算法完成 SIC/XE Assembler 的 Pass 1。你的程式要完成：

1.    如 Figure 2.2 秀出每一行組合語言程式的指令，並在前面印出 LOCCTR 的值(該行最後不需印出 Object Code ，印不印出註解均可)

2.    印出 ASM Program 的長度

3.    請在最後印出 SYMTAB 的 Symbol 及其對應值。

Please complete the Pass 1 of a SIC/XE Assembler based on the algorithm in Figure 2.4(a) and sample programs (1-token.c, 2-optable.c and 3-asm_pass1_u.c). Your program has to complete the following items:

1.    Print the LOCCTR and the assembler instruction as it was shown in Figure 2.2.

2.    Print the length of the assembler program.

3.    Print the value of each symbol in the SYMTAB.

## original
```
001 :         COPY        START            0,             (FMT=0, ADDR=1)
002 :        FIRST          STL       RETARD,             (FMT=4, ADDR=1)
003 :                       LDB       LENGTH,             (FMT=4, ADDR=2)
004 :                      BASE       LENGTH,             (FMT=0, ADDR=1)
005 :        CLOOP         JSUB        RDREC,             (FMT=8, ADDR=1)
006 :                       LDA       LENGTH,             (FMT=4, ADDR=1)
007 :                      COMP            0,             (FMT=4, ADDR=2)
008 :                       JEQ       ENDFIL,             (FMT=4, ADDR=1)
009 :                      JSUB        WRREC,             (FMT=8, ADDR=1)
010 :                         J        CLOOP,             (FMT=4, ADDR=1)
011 :       ENDFIL          LDA          EOF,             (FMT=4, ADDR=1)
012 :                       STA       BUFFER,             (FMT=4, ADDR=1)
013 :                       LDA            3,             (FMT=4, ADDR=2)
014 :                       STA       LENGTH,             (FMT=4, ADDR=1)
015 :                      JSUB        WRREC,             (FMT=8, ADDR=1)
016 :                         J       RETARD,             (FMT=4, ADDR=4)
017 :          EOF         BYTE       C'EOF',             (FMT=0, ADDR=1)
018 :       RETARD         RESW            1,             (FMT=0, ADDR=1)
019 :       LENGTH         RESW            1,             (FMT=0, ADDR=1)
020 :       BUFFER         RESB         4096,             (FMT=0, ADDR=1)
```

## after pass1
```
000000         COPY        START            0             
000000        FIRST          STL       RETARD             
000003                       LDB      #LENGTH             
000006                      BASE       LENGTH             
000006        CLOOP        +JSUB        RDREC             
00000a                       LDA       LENGTH             
00000d                      COMP           #0             
000010                       JEQ       ENDFIL             
000013                     +JSUB        WRREC             
000017                         J        CLOOP             
00001a       ENDFIL          LDA          EOF             
00001d                       STA       BUFFER             
000020                       LDA           #3             
000023                       STA       LENGTH             
000026                     +JSUB        WRREC             
00002a                         J      @RETARD             
00002d          EOF         BYTE       C'EOF'             
000030       RETARD         RESW            1             
000033       LENGTH         RESW            1             
000036       BUFFER         RESB         4096             


Program length = 1036
          COPY :  000000
         FIRST :  000000
         CLOOP :  000006
        ENDFIL :  00001a
           EOF :  00002d
        RETARD :  000030
        LENGTH :  000033
        BUFFER :  000036
```
