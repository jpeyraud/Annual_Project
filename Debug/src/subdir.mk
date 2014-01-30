################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Coordonate.cpp \
../src/Creature.cpp \
../src/Game.cpp \
../src/Game_Engine.cpp \
../src/HUD.cpp \
../src/HighView.cpp \
../src/Map.cpp \
../src/Maquette.cpp \
../src/Menu.cpp \
../src/Minimap.cpp \
../src/Monster.cpp \
../src/Option.cpp \
../src/Player.cpp \
../src/Save.cpp \
../src/cScreen.cpp \
../src/main.cpp 

OBJS += \
./src/Coordonate.o \
./src/Creature.o \
./src/Game.o \
./src/Game_Engine.o \
./src/HUD.o \
./src/HighView.o \
./src/Map.o \
./src/Maquette.o \
./src/Menu.o \
./src/Minimap.o \
./src/Monster.o \
./src/Option.o \
./src/Player.o \
./src/Save.o \
./src/cScreen.o \
./src/main.o 

CPP_DEPS += \
./src/Coordonate.d \
./src/Creature.d \
./src/Game.d \
./src/Game_Engine.d \
./src/HUD.d \
./src/HighView.d \
./src/Map.d \
./src/Maquette.d \
./src/Menu.d \
./src/Minimap.d \
./src/Monster.d \
./src/Option.d \
./src/Player.d \
./src/Save.d \
./src/cScreen.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\Program Files (x86)\SFML-2.1\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


