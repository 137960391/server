#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "splitstr.h"
int split_str(const char * str)
{
    int strNum;
    for(strNum = 0;strNum < strlen(str);strNum++)
    {
        if(*(str + strNum) == '/')
	{
	   return strNum;
	}
    }
    return 0;
}

int split_str_left(const char *str,char * des, char ch)
{
    int strNum=split_str(str);
    if(strNum==0){	
        memcpy(des,str,strlen(str));
        return 0;
    };

    memset(des,0,sizeof(des));
    memcpy(des,str,strNum);
    if(sizeof(des) > 0){
        return 1;
    }else{
        return 0;
    }
}

int split_str_right(const char *str,char * des, char ch)
{
    int strNum=split_str(str);
    if(strNum==0){
         return 0;
    };
    memset(des,0,sizeof(des));
    memcpy(des,str+strNum+1,strlen(str)-strNum-1);
    if(sizeof(des) > 0){
        return 1;
    }else{
        return 0;
    }
}
