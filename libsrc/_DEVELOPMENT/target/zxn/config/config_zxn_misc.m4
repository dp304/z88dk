divert(-1)

###############################################################
# MISCELLANEOUS CONFIG
# rebuild the library if changes are made
#

#
# SD CARD PORTS
#

# PORT 0xE7: SD_CONTROL (W)

define(`__IO_SD_CONTROL', 0xe7)

# PORT 0xE7: SD_STATUS (R)

define(`__IO_SD_STATUS', 0xe7)

# PORT 0xEB: SD_DATA

define(`__IO_SD_DATA', 0xeb)

#
# LED
#

# PORT 0x103B: LED active low

define(`__IO_LED_L', 0x103b)

#
# Important Filenames
#

define(`__ZXN_FILENAME_NEXT_UPDATE_FILE', `TBBLUE  TBU')
define(`__ZXN_FILENAME_NEXT_UPDATE_FILE_2', `TBBLUE.TBU')

define(`__ZXN_FILENAME_NEXT_FIRMWARE_FILE', `TBBLUE  FW ')
define(`__ZXN_FILENAME_NEXT_FIRMWARE_FILE_2', `TBBLUE.FW')

define(`__ZXN_DIR_NEXT_DIRECTORY', `/tbblue/')

define(`__ZXN_FILENAME_CONFIG', `__ZXN_DIR_NEXT_DIRECTORY`'config.ini')
define(`__ZXN_FILENAME_TIMING', `__ZXN_DIR_NEXT_DIRECTORY`'timing.ini')

define(`__ZXN_FILENAME_ESXMMC', `esxmmc.rom')
define(`__ZXN_FILENAME_MF1', `mf1.rom')
define(`__ZXN_FILENAME_MF3', `mf3.rom')
define(`__ZXN_FILENAME_MF128', `mf128.rom')

define(`__ZXN_FILENAME_KEYMAP', `keymap.bin')

#
# END OF USER CONFIGURATION
###############################################################

divert(0)

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_PUB',
`
PUBLIC `__IO_SD_CONTROL'
PUBLIC `__IO_SD_STATUS'
PUBLIC `__IO_SD_DATA'

PUBLIC `__IO_LED_L'
')

dnl#
dnl# LIBRARY BUILD TIME CONFIG FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_DEF',
`
defc `__IO_SD_CONTROL' = __IO_SD_CONTROL
defc `__IO_SD_STATUS' = __IO_SD_STATUS
defc `__IO_SD_DATA' = __IO_SD_DATA

defc `__IO_LED_L' = __IO_LED_L

; `define(`__ZXN_FILENAME_NEXT_UPDATE_FILE',' "__ZXN_FILENAME_NEXT_UPDATE_FILE")
; `define(`__ZXN_FILENAME_NEXT_UPDATE_FILE_2',' "__ZXN_FILENAME_NEXT_UPDATE_FILE_2")

; `define(`__ZXN_FILENAME_NEXT_FIRMWARE_FILE',' "__ZXN_FILENAME_NEXT_FIRMWARE_FILE")
; `define(`__ZXN_FILENAME_NEXT_FIRMWARE_FILE_2',' "__ZXN_FILENAME_NEXT_FIRMWARE_FILE_2")

; `define(`__ZXN_DIR_NEXT_DIRECTORY',' "__ZXN_DIR_NEXT_DIRECTORY")

; `define(`__ZXN_FILENAME_CONFIG',' "__ZXN_FILENAME_CONFIG")
; `define(`__ZXN_FILENAME_TIMING',' "__ZXN_FILENAME_TIMING")

; `define(`__ZXN_FILENAME_ESXMMC',' "__ZXN_FILENAME_ESXMMC")
; `define(`__ZXN_FILENAME_MF1',' "__ZXN_FILENAME_MF1")
; `define(`__ZXN_FILENAME_MF3',' "__ZXN_FILENAME_MF3")
; `define(`__ZXN_FILENAME_MF128',' "__ZXN_FILENAME_MF128")

; `define(`__ZXN_FILENAME_KEYMAP',' "__ZXN_FILENAME_KEYMAP")
')

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR C
dnl#

ifdef(`CFG_C_DEF',
`
`#define' `__IO_SD_CONTROL'  __IO_SD_CONTROL
`#define' `__IO_SD_STATUS'  __IO_SD_STATUS
`#define' `__IO_SD_DATA'  __IO_SD_DATA

`#define' `__IO_LED_L'  __IO_LED_L

`#define' `__ZXN_FILENAME_NEXT_UPDATE_FILE'  "__ZXN_FILENAME_NEXT_UPDATE_FILE"
`#define' `__ZXN_FILENAME_NEXT_UPDATE_FILE_2'  "__ZXN_FILENAME_NEXT_UPDATE_FILE_2"

`#define' `__ZXN_FILENAME_NEXT_FIRMWARE_FILE'  "__ZXN_FILENAME_NEXT_FIRMWARE_FILE"
`#define' `__ZXN_FILENAME_NEXT_FIRMWARE_FILE_2'  "__ZXN_FILENAME_NEXT_FIRMWARE_FILE_2"

`#define' `__ZXN_DIR_NEXT_DIRECTORY'  "__ZXN_DIR_NEXT_DIRECTORY"

`#define' `__ZXN_FILENAME_CONFIG'  "__ZXN_FILENAME_CONFIG"
`#define' `__ZXN_FILENAME_TIMING'  "__ZXN_FILENAME_TIMING"

`#define' `__ZXN_FILENAME_ESXMMC'  "__ZXN_FILENAME_ESXMMC"
`#define' `__ZXN_FILENAME_MF1'  "__ZXN_FILENAME_MF1"
`#define' `__ZXN_FILENAME_MF3'  "__ZXN_FILENAME_MF3"
`#define' `__ZXN_FILENAME_MF128'  "__ZXN_FILENAME_MF128"

`#define' `__ZXN_FILENAME_KEYMAP'  "__ZXN_FILENAME_KEYMAP"
')