#ifndef _H_LINK_H_
#define _H_LINK_H_

struct linkdata
{
    int datalen;
    char data[1024];      //保存的数据
    struct linkdata * pNext; //链表的下个节点
};

struct linkheader
{
    int len;                  //链表节点数
    struct linkdata * pdata;  //链表
};


typedef struct linkheader LINKHEADER;
typedef struct linkheader * PLINKHEADER;


/**
 * 初始化创建链表
 * @return              返回创建的链表地址
 */
PLINKHEADER  initDataLink();

/**
 * 在链表中增加数据
 * @param PLINKHEADER   要增加数据的链表指针
 * @param char *        要增加的数据
 * @return              void
 */
void addData(PLINKHEADER pLink , char * data , int datalen);

/**
 * 显示链表中的数据
 * @param PLINKHEADER   要显示的链表指针
 * @return              void
 */
void showLink(PLINKHEADER pLink);

/**
 * 拷字符串到目标字符串
 * @param PLINKHEADER   要拷贝的链表指针
 * @param str           要拷贝的字符串
 * @return              void
 */
void copyLinkData(PLINKHEADER pLink , char * str);
	
/**:
 * 删除链表，释放链表内存
 * @param PLINKHEADER   要释放的链表指针
 * @return              void
 */
void freeLink(PLINKHEADER pLink);

#endif
