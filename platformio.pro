win32 {
    HOMEDIR += $$(USERPROFILE)
}
else {
    HOMEDIR += $$(HOME)
}

INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-cmsis/cores/stm32"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-cmsis/variants/stm32f4/stm32f401xe"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-cmsis/variants/stm32f4/common"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/toolchain-gccarmnoneeabi/arm-none-eabi/include"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/toolchain-gccarmnoneeabi/lib/gcc/arm-none-eabi/4.8.4/include"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/toolchain-gccarmnoneeabi/lib/gcc/arm-none-eabi/4.8.4/include-fixed"

DEFINES += "F_CPU=84000000L"
DEFINES += "STM32F401XE"
DEFINES += "STM32F4"
DEFINES += "STM32F401xE"
DEFINES += "PLATFORMIO=020601"

OTHER_FILES += \
    platformio.ini

SOURCES += \
    src/main.c
