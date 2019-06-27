#ifndef _H_SPLITSTR_H_
#define _H_SPLITSTR_H_

/**
 * 取指定字符串右侧字符串（不含当前字符）
 * @param const char *  原字符串
 * @param char *        保存字符串缓存区
 * @param char          匹配字符
 * @return              0表示失败，1表示成功
 */
int split_str_right(const char * str,char * des,char ch);

/**
 * 取指定字符串右侧字符串（不含当前字符）
 * @param const char *  原字符串
 * @param char *        保存字符串缓存区
 * @param char          匹配字符
 * @return              0表示失败，1表示成功
 */
int split_str_left(const char * str,char * des, char ch);
	
#endif

