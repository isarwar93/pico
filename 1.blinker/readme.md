To set pico_sdk_path:
export PICO_SDK_PATH=/c/VSARM/pico-sdk

To set arm-gcc path:
export PICO_TOOLCHAIN_PATH=/c/VSARM/armgcc/'10 2021.10'


For building cmake from windows:

cmake -G "MinGW Makefiles" .. 

From Linux:
cmake ..

For tinyUSB modules clone:
goto pico-sdk folder and write:
git submodule update --init