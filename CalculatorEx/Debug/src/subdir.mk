################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CalculatorBase.cpp \
../src/CalculatorEx.cpp \
../src/ExceptionHelper.cpp \
../src/SimpleCalculator.cpp \
../src/SimpleTokenizer.cpp \
../src/TokenizerBase.cpp \
../src/Tokens.cpp \
../src/UException.cpp 

OBJS += \
./src/CalculatorBase.o \
./src/CalculatorEx.o \
./src/ExceptionHelper.o \
./src/SimpleCalculator.o \
./src/SimpleTokenizer.o \
./src/TokenizerBase.o \
./src/Tokens.o \
./src/UException.o 

CPP_DEPS += \
./src/CalculatorBase.d \
./src/CalculatorEx.d \
./src/ExceptionHelper.d \
./src/SimpleCalculator.d \
./src/SimpleTokenizer.d \
./src/TokenizerBase.d \
./src/Tokens.d \
./src/UException.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


