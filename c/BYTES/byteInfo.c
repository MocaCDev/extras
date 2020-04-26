#define MemoryAbstract(bytes,fromBit,outcomeBytes) \
if(outcomeBytes==NULL) outcomeBytes=malloc(bytes*sizeof(int));\
for(int i = 0; i < bytes; i++) {\
    /* Always adds, if negative..will subtract */\
    outcomeBytes[i]=i+fromBit;\
    /* Checking for negatives */\
    if(outcomeBytes[i]<=0) {\
        outcomeBytes=malloc(bytes+outcomeBytes[i]*sizeof(int));\
        if(!(i+fromBit)<0) outcomeBytes[i]=i+fromBit;\
        continue;\
    }\
    printf("%d\n",outcomeBytes[i]);\
}
