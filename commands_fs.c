#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h> 
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include "commands_fs.h"
#include "fs.h"

int commandREGOK(int numTokens, char** saveTokens, long int numberChar){
    if(numTokens != 2 )        
        return FALSE;
    else if (strlen(saveTokens[1]) != 5)        
        return FALSE;
    else if(!onlyNumbers(saveTokens[1]))        
        return FALSE;
    else if(numberChar - 2 != strlen(saveTokens[0])+strlen(saveTokens[1]))        
        return FALSE;
    else
        return TRUE;
}

int commandLTPOK(int numTokens, char** saveTokens, long int numberChar){
    if(numTokens != 1){
        return FALSE; 
    }else if(numberChar - 1 != strlen(saveTokens[0])){
        return FALSE;
    }else if(!strcmp(saveTokens[0],"LTP")){
        return TRUE;
    }else
        return FALSE;
}

int commandPTPOK(int numTokens, char** saveTokens, long int numberChar){
    if(numTokens != 2)
        return FALSE;
    else if(numberChar - 2 != strlen(saveTokens[0]) + strlen(saveTokens[1]))
        return FALSE;
    else if(!strcmp(saveTokens[0], "PTP"))
        return TRUE;
    else 
        return FALSE;     
}

int commandLQUOK(int numTokens, char** saveTokens, long int numberChar){
    if(numTokens != 1)
        return FALSE; 
    else if(numberChar - 1 != strlen(saveTokens[0]))
        return FALSE;
    else if(!strcmp(saveTokens[0], "LQU"))
        return TRUE;
    else
        return FALSE; 
}

int commandGQUOK(int numTokens, char** saveTokens, long int numberChar){
    if(numTokens != 2)
        return FALSE;
    else if(numberChar - 2 != strlen(saveTokens[0]) + strlen(saveTokens[1]))
        return FALSE;
    else if(!strcmp(saveTokens[0], "GQU"))
        return TRUE;
    else 
        return FALSE;
}

int commandQUSOK(int numTokens, char** saveTokens, long int numberChar){
    //Nao sei se nao temos que verificar os ficheiros 
    if(numTokens != 4)
        return FALSE;
    else if(numberChar - 4 != (strlen(saveTokens[0]) + strlen(saveTokens[1]) + strlen(saveTokens[2]) + strlen(saveTokens[3])))
        return FALSE;
    else if(!strcmp(saveTokens[0], "QUS"))
        return TRUE;
    else  
        return FALSE;
}

int commandANSOK(int numTokens, char** saveTokens, long int numberChar){
    //Nao sei se nao temos que verificar os ficheiros 
    if(numTokens != 3)
        return FALSE;
    else if(numberChar - 3 != strlen(saveTokens[0])  + strlen(saveTokens[1]) + strlen(saveTokens[2]))
        return FALSE;
    else if(!strcmp(saveTokens[0], "ANS"))
        return TRUE;
    else 
        return FALSE;
}

int onlyNumbers(char* message) {
    int i;

    for(i = 0; i < strlen(message);i++){
        if(message[i] < 48 || message[i] > 57){
            return 0;
        }
    }
    return 1;
}