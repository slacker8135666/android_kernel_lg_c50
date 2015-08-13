#ifndef __MACH_QFPROM_ADDR_8916_H__
#define __MACH_QFPROM_ADDR_8916_H__

#define SEC_PATH "/dev/block/platform/7824900.sdhci/by-name/sec"
/* QFPROM address to blow */
#define QFPROM_CTRL_BASE            (0x00058000)

#define QFPROM_RD_WR_PERM      (QFPROM_CTRL_BASE + 0x0010)
#define QFPROM_ANTIROLLBACK1           (QFPROM_CTRL_BASE + 0x0018)
#define QFPROM_ANTIROLLBACK2           (QFPROM_CTRL_BASE + 0x0020)
#define QFPROM_ANTIROLLBACK3           (QFPROM_CTRL_BASE + 0x0028)

#define QFPROM_DBG_DISABLE        (QFPROM_CTRL_BASE + 0x0030)
#define QFPROM_OEM_CONFIG           (QFPROM_CTRL_BASE + 0x0038)

#define QFPROM_SPARE_REG19          (QFPROM_CTRL_BASE + 0x01F8)
//#define QFPROM_FEC_EN               (QFPROM_CTRL_BASE + 0x0000)  // Not used in 8x16

#define QFPROM_SEC_HW_KEY           (QFPROM_CTRL_BASE + 0x0078)
#define QFPROM_SEC_HW_KEY_1           (QFPROM_CTRL_BASE + 0x0080)
#define QFPROM_SEC_HW_KEY_2           (QFPROM_CTRL_BASE + 0x0088)
#define QFPROM_SEC_HW_KEY_3           (QFPROM_CTRL_BASE + 0x0090)
#define QFPROM_SEC_HW_KEY_4           (QFPROM_CTRL_BASE + 0x0000)  // Not used in 8x16

#define QFPROM_OEM_PK_HASH          (QFPROM_CTRL_BASE + 0x00A8)

#define QFPROM_SEC_ENABLE           (QFPROM_CTRL_BASE + 0x0098)

#define QFPROM_HW_KEY_STATUS        (QFPROM_CTRL_BASE + 0x2080)

typedef enum {
  QFPROM_RESULT_OEM_CONFIG  = 0,
  QFPROM_RESULT_SEC_ENABLE  = 1,
  QFPROM_RESULT_DBG_DISABLE = 2,
  QFPROM_RESULT_SEC_HW_KEY  = 3,
  QFPROM_RESULT_RD_WR_PERM  = 4,
  QFPROM_RESULT_PRODUCT_ID  = 5,
  QFPROM_RESULT_FEC_EN      = 6,
  QFPROM_RESULT_OEM_PK_HASH = 7,
  QFPROM_RESULT_MAX
} qfprom_result_etype;

typedef struct {
  u32 type;
  u32 addr;
  u32 lsb;
  u32 msb;
} qfprom_result_bits;

qfprom_result_bits result_bits[QFPROM_RESULT_MAX] = {
  {QFPROM_RESULT_OEM_CONFIG,  QFPROM_OEM_CONFIG,    0x0000FFFF, 0x00000000},
  {QFPROM_RESULT_SEC_ENABLE,  QFPROM_SEC_ENABLE,    0x00FFFFFF, 0xFF000000},
  {QFPROM_RESULT_DBG_DISABLE, QFPROM_DBG_DISABLE,   0xFFFFFFFF, 0xFFFFFFFF},
  {QFPROM_RESULT_SEC_HW_KEY,  QFPROM_SEC_HW_KEY,    0xFFFFFFFF, 0xFFFFFFFF},
  {QFPROM_RESULT_RD_WR_PERM,  QFPROM_RD_WR_PERM,    0xFFFFFFFF, 0xFFFFFFFF},
  {QFPROM_RESULT_PRODUCT_ID,  QFPROM_OEM_CONFIG,    0xFFFF0000, 0x00000000},
};

/* secondary hw key status flag */
#define SEC_KEY_DERIVATION_BLOWN    (0x00000002)


/* ANTI_ROLLBACK DEFINEs */
#define QFPROM_ANTI_ROLLBACK1      (QFPROM_CTRL_BASE + 0x0018)
#define QFPROM_ANTI_ROLLBACK2      (QFPROM_CTRL_BASE + 0x0020)
#define QFPROM_ANTI_ROLLBACK3      (QFPROM_CTRL_BASE + 0x0028)
#define QFPROM_VERSION_MAX_REGIONS  11

typedef enum {
  QFPROM_VERSION_SBL1   = 0,
  QFPROM_VERSION_TZ     = 1,
  QFPROM_VERSION_PIL    = 2,
  QFPROM_VERSION_APP    = 3,
  QFPROM_VERSION_RPM    = 4,
  QFPROM_VERSION_HYP    = 5,
  QFPROM_VERSION_MBA    = 6,
  QFPROM_VERSION_MODEM  = 7,
  QFPROM_VERSION_MAX
} qfprom_version_etype;

typedef struct {
  u32 type;
  int cnt;
  char name[10];
} qfprom_version_info;

qfprom_result_bits anti_rollback_enable = {QFPROM_RESULT_DBG_DISABLE,  QFPROM_DBG_DISABLE,     0x00000000,  0x00780000};

qfprom_result_bits version_bits[QFPROM_VERSION_MAX_REGIONS] = {
  {QFPROM_VERSION_SBL1,    QFPROM_ANTI_ROLLBACK1,  0x00000FFE,  0x00000000},
  {QFPROM_VERSION_TZ,      QFPROM_ANTI_ROLLBACK1,  0x03FFF000,  0x00000000},
  {QFPROM_VERSION_PIL,     QFPROM_ANTI_ROLLBACK1,  0xFC000000,  0x00000000},
  {QFPROM_VERSION_PIL,     QFPROM_ANTI_ROLLBACK1,  0x00000000,  0x0003FFFF},
  {QFPROM_VERSION_APP,     QFPROM_ANTI_ROLLBACK1,  0x00000000,  0xFFFC0000},
  {QFPROM_VERSION_APP,     QFPROM_ANTI_ROLLBACK2,  0xFFFFFFFF,  0x00000000},
  {QFPROM_VERSION_APP,     QFPROM_ANTI_ROLLBACK2,  0x00000000,  0x0000000F},
  {QFPROM_VERSION_RPM,     QFPROM_ANTI_ROLLBACK2,  0x00000000,  0x00000FF0},
  {QFPROM_VERSION_HYP,     QFPROM_ANTI_ROLLBACK2,  0x00000000,  0x00FFF000},
//  {QFPROM_VERSION_MBA,     QFPROM_ANTI_ROLLBACK3,  0x0000FFFF,  0x00000000},
//  {QFPROM_VERSION_MODEM,   QFPROM_ANTI_ROLLBACK3,  0xFFFF0000,  0x00000000},
};

qfprom_version_info version_info[QFPROM_VERSION_MAX] = {
  {QFPROM_VERSION_SBL1,  0,  "SBL1"},
  {QFPROM_VERSION_TZ,    0,  "TZ"},
  {QFPROM_VERSION_PIL,   0,  "PILs"},
  {QFPROM_VERSION_APP,   0,  "APPSBL"},
  {QFPROM_VERSION_RPM,   0,  "RPM"},
  {QFPROM_VERSION_HYP,   0,  "HYP"},
  {QFPROM_VERSION_MBA,   0,  "MBA"},
  {QFPROM_VERSION_MODEM, 0,  "MODEM"},
};

#endif // __MACH_QFPROM_ADDR_8916_H__
