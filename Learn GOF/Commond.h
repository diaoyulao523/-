#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <typeinfo>

#define MY_PRINT(fmt, ...) printf("[%s(%d)) %s.%s] "##fmt"\n",__FILE__,__LINE__,typeid(*this).name(),__FUNCTION__,##__VA_ARGS__)

#define MY_PRINT1(fmt, ...) printf("[%s.%s] "##fmt"\n",typeid(*this).name(),__FUNCTION__,##__VA_ARGS__)