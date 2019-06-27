/**
 *  1、用先用链表对每次的字符串进行储存，并在结构体中增加链表的长度
 *  2、根据链表的长度对字符串进行动态开辟
 *  3、将链表中的值赋值到开辟的字符串中 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "link.h"
#ifndef NULL
#define NULL 0
#endif
PLINKHEADER  initDataLink()
{
    PLINKHEADER temp =(PLINKHEADER)malloc(sizeof(LINKHEADER));
    temp->len = 0;
    temp->pdata = (struct linkdata *)malloc(sizeof(struct linkdata));
    temp->pdata->pNext = NULL;
    return temp; 
}

void addData(PLINKHEADER pLink , char * data , int datalen)
{
    struct linkdata * temp;
    struct linkdata * NextNode = (struct linkdata *)malloc(sizeof(struct linkdata));
    pLink->len += 1;
    NextNode->pNext = NULL;
    NextNode->datalen = datalen;
    memset(NextNode->data,'0',1024);
    memcpy(NextNode->data,data,1024);
    temp = pLink->pdata;
    while(temp->pNext)
    {
        temp = temp->pNext;
    }
    temp->pNext = NextNode;
    printf("添加数据成功!char:%s\n",temp->pNext->data);
}

void copyLinkData(PLINKHEADER pLink , char * str)
{
    struct linkdata * temp;
    temp = pLink->pdata;
    char * deststr = str;
    while(temp->pNext)
    {
        memcpy(deststr,temp->pNext->data,temp->pNext->datalen);
	deststr += temp->pNext->datalen;
        temp = temp->pNext;
    }

    
}

void showLink(PLINKHEADER pLink)
{
    struct linkdata * temp;
    temp = pLink->pdata;
    while(temp->pNext)
    {
        printf("value:%s\n",temp->pNext->data);
        temp = temp->pNext;
    }
    printf("len:%d\n",pLink->len);
}

void freeLink(PLINKHEADER pLink)
{
    struct linkdata * temp;
    while(pLink->pdata)
    {
        temp = pLink->pdata;
	pLink->pdata = pLink->pdata->pNext;
	free(temp);
	printf("释放内存块成功！\n");
    }
    free(pLink);
    printf("主链表释放成功！\n");
}


