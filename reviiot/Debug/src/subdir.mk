################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Card.cpp \
../src/Deck.cpp \
../src/Game.cpp \
../src/Hand.cpp \
../src/Player.cpp \
../src/reviiot.cpp 

OBJS += \
./src/Card.o \
./src/Deck.o \
./src/Game.o \
./src/Hand.o \
./src/Player.o \
./src/reviiot.o 

CPP_DEPS += \
./src/Card.d \
./src/Deck.d \
./src/Game.d \
./src/Hand.d \
./src/Player.d \
./src/reviiot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


