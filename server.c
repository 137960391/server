#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h> //使用strlen()函数
#include "splitstr.h"
#include "link.h"
/*
 *sys/socket.h
 * 
 *该头文件主要是引用socket、blind、listen、recv等函数
 * */
/*perror:输出错误信息，类似windows下的getlasterrot*/

/*
 *netdb.h
 *
 *该头文件引用hotent结构体和函数gethostbyname
 * */

int get_html(int ,char * );
void * add_realloc(void * buff,int multiple,int buffSpace)
{
   void * adress = realloc(buff,multiple * buffSpace);
   if(adress){
   	return adress;
   }
   return 0;
}

int main(int argc,char * argv[])
{

	if(argc < 2 || argc > 2){
	    printf("输入有误！\n");
	    return 0;
	}
	//1.创建socket连接
	int http_socket=socket(PF_INET,SOCK_STREAM,0);
	perror("socket");
	/*
	 * PF_INET 用于协议
	 * AF_INET 用于地址
	 * */
	printf("http_socket:%d\n",http_socket);
	//sAdd.sin_addr.s_addr=inet_addr("127.0.0.1");
	//2.绑定端口
	//bind(http_socket,(struct sockaddr *)&sAdd,sizeof(sAdd));
	/*
	 * linux 与 windows 的区别，linux中struct sokeraddr 并没有设置typedef起别名
	 * */
	//perror("socket");
	get_html(http_socket,argv[1]);
        printf("\n\nexit\n");
	return 0;
}

int get_html(int http_socket,char * referUrl)
{
	char urlHeader[256] = {0};
	char url[256] = {0};
	split_str_left(referUrl,urlHeader,'/');
	split_str_right(referUrl,url,'/');
	char sendData[1024]={0};
	char recvData[1024]={0};
	struct sockaddr_in sAdd;
	sAdd.sin_family=AF_INET;
	sAdd.sin_port=htons(80);
	struct hostent* phostent=gethostbyname(urlHeader);
	if(phostent==0){
	    printf("输入的地址有误!\n");
	    return 0;
	}
	sAdd.sin_addr.s_addr=(*(struct in_addr *)phostent->h_addr_list[0]).s_addr;
	//2.连接服务器
	connect(http_socket,(struct sockaddr*)&sAdd,sizeof(struct sockaddr));
	perror("connect:");
	sprintf(sendData,"GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: Close\r\n\r\n",url,urlHeader);
	printf("%s",sendData);
	/*
	 *connect: 为keep-alive时，连接完毕服务器不会关闭，导致recv最后一次阻塞
	 *解决方法：connection设置为close，此时服务读取完毕会关闭连接，recv返回0
	 * */
	send(http_socket,sendData,strlen(sendData),0);
	perror("send:");
	printf("recvData:\n");
	int recvNum=0;
	int count=0;
	char* strBuff = (char *)malloc(1024);
	int sumStrNum = 0;
	int num = 0;
	PLINKHEADER pLink = initDataLink();
        do{
	    recvNum = recv(http_socket,recvData,1024,0);
	    addData(pLink,recvData,recvNum);
            memset(recvData,'\0',1024);
	}
	while(recvNum>0);
	char * str = (char *)malloc(1024*(pLink->len));
	copyLinkData(pLink,str);
	printf("html:\n%s",str);
	freeLink(pLink);

}




