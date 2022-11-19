/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _PRINT_COLOR_H
#define _PRINT_COLOR_H
#ifdef __cplusplus
extern "C"
{
#endif

#define SHELL_COLOR_CLOSE "\033[0m"
#define SHELL_COLOR_HIGH  "\033[1m" /* 高亮 */
#define SHELL_COLOR_LOW   "\033[2m" /* 低亮 */
#define SHELL_COLOR_LINE  "\033[4m" /* 下划线 */
#define SHELL_COLOR_FLASH "\033[5m" /* 闪烁 */
#define SHELL_COLOR_REFLECT "\033[7m" /* 反显 */
#define SHELL_COLOR_BLANKING "\033[8m" /* 消隐 */

#define SHELL_BG_COLOR_BLACK   "\033[40m"
#define SHELL_BG_COLOR_RED     "\033[41m"
#define SHELL_BG_COLOR_GREEN   "\033[42m"
#define SHELL_BG_COLOR_YELLOW  "\033[43m"
#define SHELL_BG_COLOR_BLUE    "\033[44m"
#define SHELL_BG_COLOR_PURPLE  "\033[45m"
#define SHELL_BG_COLOR_CYAN    "\033[46m"
#define SHELL_BG_COLOR_WHITE   "\033[47m"

#define SHELL_FONT_COLOR_BLACK   "\033[30m"
#define SHELL_FONT_COLOR_RED     "\033[31m"
#define SHELL_FONT_COLOR_GREEN   "\033[32m"
#define SHELL_FONT_COLOR_YELLOW  "\033[33m"
#define SHELL_FONT_COLOR_BLUE    "\033[34m"
#define SHELL_FONT_COLOR_PURPLE  "\033[35m"
#define SHELL_FONT_COLOR_CYAN    "\033[36m"
#define SHELL_FONT_COLOR_WHITE   "\033[37m"
#define SHELL_FONT_ADD_LINE      "\033[38m"
#define SHELL_FONT_DEL_LINE      "\033[39m"

#define PRINT_COLOR(_color, _fmt, ...) printf(_color _fmt SHELL_COLOR_CLOSE "\n", ##__VA_ARGS__)   

#define PRINT_BLACK(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_BLACK, _fmt, ##__VA_ARGS__)   
#define PRINT_RED(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_RED, _fmt, ##__VA_ARGS__)   
#define PRINT_GREEN(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_GREEN, _fmt, ##__VA_ARGS__)   
#define PRINT_YELLOW(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_YELLOW, _fmt, ##__VA_ARGS__)   
#define PRINT_BLUE(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_BLUE, _fmt, ##__VA_ARGS__)   
#define PRINT_PURPLE(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_PURPLE, _fmt, ##__VA_ARGS__)   
#define PRINT_CYAN(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_CYAN, _fmt, ##__VA_ARGS__)   
#define PRINT_WHITE(_fmt, ...) PRINT_COLOR(SHELL_FONT_COLOR_WHITE, _fmt, ##__VA_ARGS__)   


#ifdef __cplusplus
}
#endif
#endif //PRINT_COLOR_H_