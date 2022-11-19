/*********************************************************
*   Copyright (C) LiXingang
*   Description: 
*
********************************************************/
#ifndef _QEMU_UTL_H
#define _QEMU_UTL_H
#ifdef __cplusplus
extern "C"
{
#endif

/* 判断bar是否64位 */
static inline int QEMU_Is64BitBar(PCIDevice *pci_dev, int bar)
{
    unsigned int addr = bar * 4 + 0x10;
    unsigned int bar_val;

    /* 获取bar寄存器内容 */
    bar_val = pci_default_read_config(pci_dev, addr, 4);

    /* 判断是否64位 */
    if ((bar_val & 0x6) == 0) {
        /* 32位 */
        return 0;
    }

    return 1;
}

/* 获取指定bar中的地址 */
static inline UINT64 QEMU_GetBarAddr(PCIDevice *pci_dev, int bar)
{
    unsigned int addr = bar * 4 + 0x10;
    unsigned int bar_val;
    unsigned int bar_val2;
    unsigned long long addr64;

    /* 获取bar寄存器内容 */
    bar_val = pci_default_read_config(pci_dev, addr, 4);

    /* 判断是否64位 */
    if ((bar_val & 0x6) == 0) {
        /* 32位 */
        return bar_val & 0xfffff000;
    }

    /* 64位, 读取下一个bar */
    addr += 4;
    bar_val2 = pci_default_read_config(pci_dev, addr, 4);

    addr64 = bar_val2;
    addr64 = addr64 << 32;
    addr64 |= (bar_val & 0xfffff000);

    return addr64;
}

#ifdef __cplusplus
}
#endif
#endif //QEMU_UTL_H_
