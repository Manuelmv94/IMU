################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/IIC.c" \
"../Sources/IMU.c" \
"../Sources/SCI.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/IIC.c \
../Sources/IMU.c \
../Sources/SCI.c \
../Sources/main.c \

OBJS += \
./Sources/IIC_c.obj \
./Sources/IMU_c.obj \
./Sources/SCI_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/IIC_c.obj" \
"./Sources/IMU_c.obj" \
"./Sources/SCI_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/IIC_c.d \
./Sources/IMU_c.d \
./Sources/SCI_c.d \
./Sources/main_c.d \

C_DEPS_QUOTED += \
"./Sources/IIC_c.d" \
"./Sources/IMU_c.d" \
"./Sources/SCI_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/IIC_c.obj \
./Sources/IMU_c.obj \
./Sources/SCI_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/IIC_c.obj: ../Sources/IIC.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/IIC.args" -ObjN="Sources/IIC_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/IMU_c.obj: ../Sources/IMU.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/IMU.args" -ObjN="Sources/IMU_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/SCI_c.obj: ../Sources/SCI.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/SCI.args" -ObjN="Sources/SCI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


