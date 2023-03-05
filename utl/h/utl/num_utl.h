/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2008-11-20
* Description: 
* History:     
******************************************************************************/

#ifndef __NUM_UTL_H_
#define __NUM_UTL_H_

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#define STR_LEN(string) (sizeof(string) - 1)

#define NUM_IN_RANGE(ulNum,ulMin,ulMax)  \
    (((ULONG)(ulNum) >= (ULONG)(ulMin)) && ((ULONG)(ulNum) <= (ULONG)(ulMax))) 

#define NUM_IN_START_COUNT(ulNum,ulMin,ulCount)  \
        NUM_IN_RANGE(ulNum, ulMin, ((ulMin) + (ulCount)) -1)

#define NUM_INC_SKIP_ZERO(num) \
    do{(num)++; if((num) == 0){(num)++;}}while(0)

/* 判断区间是否重叠, 不包含边界 */
#define NUM_AREA_IS_OVERLAP(ulArea1Min, ulArea1Max, ulArea2Min, ulArea2Max) \
    ((ulArea1Max) < (ulArea2Min) ? FALSE : ((ulArea2Max) < (ulArea1Min) ? FALSE: TRUE))

/* 判断区间是否重叠, 包含边界 */
#define NUM_AREA_IS_OVERLAP2(ulArea1Min, ulArea1Max, ulArea2Min, ulArea2Max) \
    ((ulArea1Max) <= (ulArea2Min) ? FALSE : ((ulArea2Max) <= (ulArea1Min) ? FALSE: TRUE))

/* 计算一个大于等于v且是mul整数倍的最小数字 */
#define NUM_UP_ALIGN(v, mul) ((((v) + (mul) - 1) / ((mul))) * (mul))

/* 计算一个小于等于v且是mul整数倍的最大数字 */
#define NUM_DOWN_ALIGN(v, mul) ((v / (mul)) * (mul))

#define NUM_ALIGN(v, mul) NUM_UP_ALIGN(v, mul)

/* 计算距离对齐还差多少长度 */
#define NUM_ALIGN_DIFF(v, mul)  (NUM_ALIGN(v, mul) - (v))

/**
 * 计算一个接近v且是mul整数倍的数字
 * 结果可能大于或小于v
 */
#define NUM_NEAR_ALIGN(v, mul)				\
	({							\
		typeof(v) ceil = NUM_UP_ALIGN(v, mul);	\
		typeof(v) floor = NUM_DOWN_ALIGN(v, mul);	\
		(ceil - v) > (v - floor) ? floor : ceil;	\
	})

/* 判断一个数字是否2的指数幂 */
#define NUM_IS2N(_num) (((_num) > 0) && (((_num) & ((_num)-1))==0))
/* 判断一个数字是否2的指数幂减一 */
#define NUM_IS2NDEC1(_num) (((_num) > 0) && (((_num) & ((_num)+1))==0))

/* 获取不小于x的2的指数幂*/
static inline UINT NUM_To2N(UINT x)
{
    x--;

	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;

    return x + 1;
}

/* 计算环形下标位置 */
#define NUM_CYCLE_INDEX_ADD(uiIndex, uiInc, uiMaxCount)   \
    do {    \
        (uiIndex) = (uiIndex) + (uiInc); \
        if ((uiIndex) >= (uiMaxCount))     \
        {   \
            (uiIndex) -= (uiMaxCount); \
        }   \
    } while(0)


/* n=n/base,  return n%base */
static inline ULONG NUM_DoDiv(IN ULONG *pulNum, IN ULONG ulBase)
{
    ULONG ulRet;

    ulRet = (*pulNum) % ulBase;
    *pulNum = (*pulNum) / ulBase;

    return ulRet;
}

/* 计算表示一个数字需要几个bit位 */
static inline UCHAR NUM_NeedBits(IN UINT uiNum)
{
    INT i;

    for (i=31; i>=0; i--) {
        if (uiNum & (1 << i)) {
            return i + 1;
        }
    }

    return 0;
}

static inline INT NUM_Cmp(IN UINT uiNum1, IN UINT uiNum2)
{
    if (uiNum1 > uiNum2)
    {
        return 1;
    }

    if (uiNum1 < uiNum2)
    {
        return -1;
    }

    return 0;
}

/*  将一个 32 位数据循环左移 shift 位*/
static inline unsigned int NUM_Rol32(unsigned int word, unsigned int shift)
{
	return (word << (shift & 31)) | (word >> ((-shift) & 31));
}

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__NUM_UTL_H_*/


