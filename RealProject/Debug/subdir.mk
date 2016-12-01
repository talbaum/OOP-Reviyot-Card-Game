################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Card.cpp \
../Deck.cpp \
../Game.cpp \
../Hand.cpp \
../Player.cpp \
../reviiyot.cpp 

O_SRCS += \
../Card.o \
../Deck.o \
../Game.o \
../Hand.o \
../Player.o \
../reviiyot.o 

OBJS += \
./Card.o \
./Deck.o \
./Game.o \
./Hand.o \
./Player.o \
./reviiyot.o 

CPP_DEPS += \
./Card.d \
./Deck.d \
./Game.d \
./Hand.d \
./Player.d \
./reviiyot.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


