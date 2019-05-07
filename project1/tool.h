//
// Created by 1655664358@qq.com on 2019/5/6.
//

#ifndef _TOOL_H
#define _TOOL_H

#include "common.h"
extern void pause(const char *str,...);
extern long getFileSize(FILE *file);

extern int finsert(FILE *file,long offset,void *buffer,int len);
extern long fcopy(FILE *sourceFile,long sourceOffset,long len,FILE *targetFile,long targetOffset);
extern int fdelete(FILE *file,long offset,long len);
#endif //STUDENT_TOOL_H
