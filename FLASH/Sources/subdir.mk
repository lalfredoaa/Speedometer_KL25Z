################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/common.c" \
"../Sources/input.c" \
"../Sources/lcd.c" \
"../Sources/main.c" \
"../Sources/pwm.c" \
"../Sources/sa_mtb.c" \
"../Sources/uart.c" \

C_SRCS += \
../Sources/common.c \
../Sources/input.c \
../Sources/lcd.c \
../Sources/main.c \
../Sources/pwm.c \
../Sources/sa_mtb.c \
../Sources/uart.c \

OBJS += \
./Sources/common.o \
./Sources/input.o \
./Sources/lcd.o \
./Sources/main.o \
./Sources/pwm.o \
./Sources/sa_mtb.o \
./Sources/uart.o \

C_DEPS += \
./Sources/common.d \
./Sources/input.d \
./Sources/lcd.d \
./Sources/main.d \
./Sources/pwm.d \
./Sources/sa_mtb.d \
./Sources/uart.d \

OBJS_QUOTED += \
"./Sources/common.o" \
"./Sources/input.o" \
"./Sources/lcd.o" \
"./Sources/main.o" \
"./Sources/pwm.o" \
"./Sources/sa_mtb.o" \
"./Sources/uart.o" \

C_DEPS_QUOTED += \
"./Sources/common.d" \
"./Sources/input.d" \
"./Sources/lcd.d" \
"./Sources/main.d" \
"./Sources/pwm.d" \
"./Sources/sa_mtb.d" \
"./Sources/uart.d" \

OBJS_OS_FORMAT += \
./Sources/common.o \
./Sources/input.o \
./Sources/lcd.o \
./Sources/main.o \
./Sources/pwm.o \
./Sources/sa_mtb.o \
./Sources/uart.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/common.o: ../Sources/common.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/common.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/common.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/input.o: ../Sources/input.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/input.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/input.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lcd.o: ../Sources/lcd.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcd.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcd.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pwm.o: ../Sources/pwm.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/pwm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/pwm.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart.o: ../Sources/uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/uart.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/uart.o"
	@echo 'Finished building: $<'
	@echo ' '


