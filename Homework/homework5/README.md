# Homework 5. Loader – pass 1
```
請參考 Figure 3.11 的演算法，寫一個 Loader 並產生如 P.143 的 Load map。你的程式需滿足以下的格式：

Syntax: load <address> <file 1> < file 2> …
<address> 為 Starting Address (16進位表示)
Ex: load 1000 PROGA PROGB PROGC
PS: 你的程式要能處理 Figure 3.9 的 Object Program
```

```
./a.out 1000 PROGA.obj PROGB.obj PROGC.obj
```
```
control section   symbol name   address length
PROGA                           1000    0063
                  LISTA         1040  
                  ENDA          1054    
PROGB                           1063    007F
                  LISTB         10C3  
                  ENDB          10D3    
PROGC                           10E2    0051
                  LISTC         1112  
                  ENDC          1124    
```
 
