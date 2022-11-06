/*********************************************************
*   Copyright (C) LiXingang
*   Description: 
*
********************************************************/
#ifndef _PCI_UTL_H
#define _PCI_UTL_H

#include "utl/bit_opt.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    USHORT vendor_id;
    USHORT device_id;
    USHORT command;
    USHORT status;
    UCHAR revision_id;
    UCHAR class_code[3];
    UCHAR chache_line_size;
    UCHAR latency_timer;
    UCHAR header_type;
    UCHAR bist;
    UINT bar0;
    UINT bar1;
    UINT bar2;
    UINT bar3;
    UINT bar4;
    UINT bar5;
    UINT cardbus_cis_pointer;
    USHORT subsystem_vendor_id;
    USHORT subsystem_id;
    UINT expansion_rom_base_address;
    UCHAR capabilities_pointer;
    UCHAR reserved[3];
    UINT reserved2;
    UCHAR interrupt_line;
    UCHAR interrupt_pin;
    UCHAR min_gnt;
    UCHAR max_lat;
}PCIE_DEV_CFG_S;


typedef struct {
    unsigned char fmt_type; /* TLP Fmt Type. Type: [0,4], Fmt: [5,7] */
    unsigned char flag; /* th:0,attr:2,TC:[4,6] */
    unsigned short len_attr; /* len:[0-9], AT:[10-11], Attr:[12-13], EP:14, TD:15 */

    unsigned int bytes[3]; /* type相关字段 */
}PCIE_TLP_HEADER_S;

typedef struct {
    unsigned char fmt_type; /* TLP Fmt Type. Type: [0,4], Fmt: [5,7] */
    unsigned char flag; /* th:0,attr:2,TC:[4,6] */
    unsigned short len_attr; /* len:[0-9], AT:[10-11], Attr:[12-13], EP:14, TD:15 */

    unsigned int bytes[3]; /* type相关字段 */

    unsigned int payload[1024];
}PCIE_TLP_S;

#define PCIE_TLP_FMT(tlp) ((tlp)->fmt_type >> 5)
#define PCIE_TLP_TYPE(tlp) ((tlp)->fmt_type & 0x1f)
#define PCIE_TLP_TH(tlp) ((tlp)->flag & 0x1)
#define PCIE_TLP_ATTR2(tlp) (((tlp)->flag >> 2) & 0x1)
#define PCIE_TLP_TC(tlp) (((tlp)->flag >> 4) & 0x7)
#define PCIE_TLP_LENGTH(tlp) ((tlp)->len_attr & 0x3ff)
#define PCIE_TLP_AT(tlp) (((tlp)->len_attr >> 10) & 0x3)
#define PCIE_TLP_ATTR(tlp) (((tlp)->len_attr >> 12) & 0x3)
#define PCIE_TLP_EP(tlp) (((tlp)->len_attr >> 14) & 0x1)
#define PCIE_TLP_TD(tlp) (((tlp)->len_attr >> 15) & 0x1)

#define PCIE_SET_TLP_FMT(tlp, v) BIT_OFF_SETTO((tlp)->fmt_type, 0x3, v, 5)
#define PCIE_SET_TLP_TYPE(tlp, v) BIT_OFF_SETTO((tlp)->fmt_type, 0x1f, v, 0)
#define PCIE_SET_TLP_TH(tlp, v) BIT_OFF_SETTO((tlp)->flag, 0x1, v, 0)
#define PCIE_SET_TLP_ATTR2(tlp, v) BIT_OFF_SETTO((tlp)->flag , 0x1, v, 2)
#define PCIE_SET_TLP_TC(tlp, v) BIT_OFF_SETTO((tlp)->flag , 0x3, v, 4)
#define PCIE_SET_TLP_LENGTH(tlp, v) BIT_OFF_SETTO((tlp)->len_attr, 0x3ff, v, 0)
#define PCIE_SET_TLP_AT(tlp, v) BIT_OFF_SETTO((tlp)->len_attr, 0x3, v, 10)
#define PCIE_SET_TLP_ATTR(tlp, v) BIT_OFF_SETTO((tlp)->len_attr, 0x3, v, 12)
#define PCIE_SET_TLP_EP(tlp, v) BIT_OFF_SETTO((tlp)->len_attr, 0x1, v, 14)
#define PCIE_SET_TLP_TD(tlp, v) BIT_OFF_SETTO((tlp)->len_attr, 0x1, v, 15)


typedef struct {
    unsigned char fmt_type;
    unsigned char flag;
    unsigned short len_attr;

    unsigned short request_id;
    unsigned char tag;
    unsigned char dw;

    unsigned int bdf_reg;
}PCIE_TLP_CFG_S;

#define PCIE_TLP_CFG_FIRST_DW(tlp) ((tlp)->dw & 0xf)
#define PCIE_TLP_CFG_LAST_DW(tlp) (((tlp)->dw >> 4) & 0xf)
#define PCIE_TLP_CFG_TAG(tlp) ((tlp)->tag) 
#define PCIE_TLP_CFG_REQUEST_ID(tlp) ((tlp)->request_id)
#define PCIE_TLP_CFG_REG_NUM(tlp) (((tlp)->bdf_reg >> 2) & 0x3f)
#define PCIE_TLP_CFG_EXT_REG_NUM(tlp) (((tlp)->bdf_reg >> 8) & 0xf)
#define PCIE_TLP_CFG_BDF(tlp) (((tlp)->bdf_reg >> 16) & 0xffff)
#define PCIE_TLP_CFG_BDF_BUS(tlp) (((tlp)->bdf_reg >> 24) & 0xff)
#define PCIE_TLP_CFG_BDF_DEV(tlp) (((tlp)->bdf_reg >> 19) & 0x1f)
#define PCIE_TLP_CFG_BDF_FUNC(tlp) (((tlp)->bdf_reg >> 16) & 0x7)

#define PCIE_SET_TLP_CFG_FIRST_DW(tlp, v) BIT_OFF_SETTO((tlp)->dw, 0xf, v, 0)
#define PCIE_SET_TLP_CFG_LAST_DW(tlp, v) BIT_OFF_SETTO((tlp)->dw, 0xf, v, 4)
#define PCIE_SET_TLP_CFG_TAG(tlp, v) do{(tlp)->tag = (v);}while(0)
#define PCIE_SET_TLP_CFG_REQUEST_ID(tlp, v) do{(tlp)->request_id = (v);}while(0)
#define PCIE_SET_TLP_CFG_REG_NUM(tlp, v) BIT_OFF_SETTO((tlp)->bdf_reg, 0x3f, v, 2)
#define PCIE_SET_TLP_CFG_EXT_REG_NUM(tlp, v) BIT_OFF_SETTO((tlp)->bdf_reg, 0xf, v, 8)
#define PCIE_SET_TLP_CFG_BDF(tlp, v) BIT_OFF_SETTO((tlp)->bdf_reg, 0xffff, v, 16)
#define PCIE_SET_TLP_CFG_BDF_BUS(tlp, v) BIT_OFF_SETTO((tlp)->bdf_reg, 0xff, v, 24)
#define PCIE_SET_TLP_CFG_BDF_DEVICE(tlp, v) BIT_OFF_SETTO((tlp)->bdf_reg, 0x1f, v, 19)
#define PCIE_SET_TLP_CFG_BDF_FUNCTION(tlp, v) BIT_OFF_SETTO((tlp)->bdf_reg, 0x7, v, 16)

typedef struct {
    unsigned char fmt_type;
    unsigned char flag;
    unsigned short len_attr;

    unsigned short request_id;
    unsigned char tag;
    unsigned char dw;

    unsigned int addr1;
    unsigned int addr2;
}PCIE_TLP_MEM_S;

typedef struct {
    unsigned char fmt_type;
    unsigned char flag;
    unsigned short len_attr;

    unsigned short completer_id;
    unsigned short status_count;

    unsigned short requester_id;
    unsigned char tag;
    unsigned char lower_addr;
}PCIE_TLP_COMPLETE_S;

#define PCIE_TLP_COMP_STATUS(tlp) (((tlp)->status_count >> 13) & 0x7)
#define PCIE_TLP_COMP_COUNT(tlp) (((tlp)->status_count) & 0xfff)
#define PCIE_TLP_COMP_BCM(tlp) (((tlp)->status_count >> 12) & 0x1)
#define PCIE_TLP_COMP_LOWER_ADDR(tlp) (((tlp)->lower_addr) & 0x7f)

void PCIE_BuildCfgTLP(UCHAR fmt, UCHAR type, USHORT bdf, UINT addr, int size, OUT PCIE_TLP_CFG_S *tlp);
void PCIE_BuildCfgReadTLP(int is_ep, USHORT bdf, UINT addr, int size, OUT PCIE_TLP_CFG_S *tlp);
void PCIE_BuildCfgWriteTLP(int is_ep, USHORT bdf, UINT addr, int size, UINT val, OUT PCIE_TLP_CFG_S *tlp);
void PCIE_BuildMemTLP(UCHAR fmt, UCHAR type, USHORT bdf, UINT64 addr, BOOL_T is64, int size, OUT PCIE_TLP_MEM_S *tlp);
void PCIE_BuildEpMemReadTLP(USHORT bdf, UINT addr, BOOL_T is64, int size, OUT PCIE_TLP_MEM_S *tlp);
void PCIE_BuildEpMemWriteTLP(USHORT bdf, UINT addr, BOOL_T is64, int size, void *data, OUT PCIE_TLP_MEM_S *tlp);
void PCIE_WriteTlpData(void *data, int data_len, BOOL_T is4dw, OUT PCIE_TLP_S *tlp);
int PCIE_ReadTlpData(OUT void *data, int data_size, BOOL_T is4dw, PCIE_TLP_S *tlp);

#ifdef __cplusplus
}
#endif
#endif 

