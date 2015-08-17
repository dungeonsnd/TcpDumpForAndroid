#ifndef _HEADER_FILE_NETWORK_NDK_LOG_H_
#define _HEADER_FILE_NETWORK_NDK_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <android/log.h>

#define TAG_NETWORK "TcpDumpInterface"
#define log_t(tag, ...)  __android_log_print(ANDROID_LOG_VERBOSE,tag,__VA_ARGS__)
#define log_d(tag, ...)  __android_log_print(ANDROID_LOG_DEBUG,tag,__VA_ARGS__)
#define log_i(tag, ...)  __android_log_print(ANDROID_LOG_INFO,tag,__VA_ARGS__)
#define log_w(tag, ...)  __android_log_print(ANDROID_LOG_WARN,tag,__VA_ARGS__)
#define log_e(tag, ...)  __android_log_print(ANDROID_LOG_ERROR,tag,__VA_ARGS__)
#define log_f(tag, ...)  __android_log_print(ANDROID_LOG_FATAL,tag,__VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif //__GOOD_LUCK_H__
