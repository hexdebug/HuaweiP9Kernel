/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : MmaApsInterface.h
  版 本 号   : 初稿
  作    者   : h44270
  生成日期   : 2011年12月19日
  最近修改   :
  功能描述   : MMC和APS之间的接口头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2011年12月19日
    作    者   : h44270
    修改内容   : 创建文件

******************************************************************************/

#ifndef __MMC_APS_INTERFACE_H__
#define __MMC_APS_INTERFACE_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"

/* Modified by z00161729 for 主动上报AT命令控制下移至C核, 2013-4-8, begin */
/* 删除ExtAppMmcInterface.h*/
#include "TafMmcInterface.h"
/* Modified by z00161729 for 主动上报AT命令控制下移至C核, 2013-4-8, end */


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
/*****************************************************************************
 枚举名    : MMC_APS_MSG_ID_ENUM_UINT32
 枚举说明  : MMC与APS之间的消息接口定义
 1.日    期   : 2011年12月19日
   作    者   : h44270
   修改内容   : 新建
 2.日    期   : 2013年4月8日
   作    者   : z00161729
   修改内容   : 主动上报AT命令控制下移至C核及mma和mmc接口调整
*****************************************************************************/
enum MMC_APS_MSG_ID_ENUM
{
    /* Modified by z00161729 for 主动上报AT命令控制下移至C核, 2013-4-8, begin */
    ID_MMC_APS_SERVICE_STATUS_IND = TAFMMC_APS_SERVICE_STATE_IND,               /* _H2ASN_MsgChoice MMC_APS_SERVICE_STATUS_IND_STRU */
    /* Modified by z00161729 for 主动上报AT命令控制下移至C核, 2013-4-8, end */

    /* 后面的枚举值不能直接递增，MMC有多种上报的消息 */

    ID_MMC_APS_MSG_ID_ENUM_BUTT

};
typedef VOS_UINT32 MMC_APS_MSG_ID_ENUM_UINT32;


/*****************************************************************************
  3 枚举定义
*****************************************************************************/
/*****************************************************************************
 枚举名    : MMC_APS_RAT_TYPE_ENUM_UINT8
 结构说明  : 当前的接入技术
 1.日    期   : 2011年12月19日
   作    者   : h44270
   修改内容   : 新建
s*****************************************************************************/
enum MMC_APS_RAT_TYPE_ENUM
{
    MMC_APS_RAT_TYPE_NULL,          /* 当前未在任何网络上驻留 */
    MMC_APS_RAT_TYPE_GSM,           /* GSM接入技术 */
    MMC_APS_RAT_TYPE_WCDMA,         /* WCDMA接入技术 */
    MMC_APS_RAT_TYPE_LTE,           /* LTE接入技术 */
    MMC_APS_RAT_TYPE_BUTT           /* 无效的接入技术 */
};
typedef VOS_UINT32 MMC_APS_RAT_TYPE_ENUM_UINT32;


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/
/*****************************************************************************
 结构名    : MMC_APS_SERVICE_STATUS_IND_STRU
 结构说明  : MMC通知APS 查询服务状态相关参数
 1.日    期   : 2011年12月19日
   作    者   : h44270
   修改内容   : 新建
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /* 消息头 */ /*_H2ASN_Skip*/
    MMC_APS_RAT_TYPE_ENUM_UINT32        enRatType;                              /* 查询返回的当前参数 */
    VOS_UINT32                          ulPsSimRegStatus;                       /* PS域SIM卡状态信息,VOS_TRUE:卡有效,VOS_FALSE:卡无效 */
}MMC_APS_SERVICE_STATUS_IND_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/
/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    MMC_APS_MSG_ID_ENUM_UINT32          enMsgID;                /*_H2ASN_MsgChoice_Export MMC_APS_MSG_ID_ENUM_UINT32 */
                                                                /* 为了兼容NAS的消息头定义，所以转换ASN.MMC_APS_MSG_ID_ENUM_UINT32 */

    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MMC_APS_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}MMC_APS_SND_INTERNAL_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MMC_APS_SND_INTERNAL_DATA            stMsgData;
}MmcApsInterfacemsg_MSG;

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/



#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MmcApsInteraface.h */

