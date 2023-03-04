# CMake minimum required version
cmake_minimum_required(VERSION 3.12)


# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
# Set project name
set(PROJECT_NAME blinker)

# Set project informations
#project(${PROJECT_NAME})


project(${PROJECT_NAME} C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Initialize the SDK
pico_sdk_init()


add_executable(${PROJECT_NAME}
                ${PROJECT_NAME}.c
        )


# pull in common dependencies
target_link_libraries(  ${PROJECT_NAME}
                        pico_stdlib 
                        hardware_adc 
                        hardware_spi
                        hardware_pio
                        pico_multicore 
                        )


# to use usb for serial communication instead uart pin
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)


# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

# add url via pico_set_program_url
#example_auto_set_url(${PROJECT_NAME})