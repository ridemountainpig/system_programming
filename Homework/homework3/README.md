# homework3 example
<br>
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
