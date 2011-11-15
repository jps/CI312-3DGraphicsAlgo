################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cube.cpp \
../Edge.cpp \
../EdgeFaces.cpp \
../EdgesFaces.cpp \
../Face.cpp \
../GameObject.cpp \
../Vertex.cpp \
../main.cpp 

OBJS += \
./Cube.o \
./Edge.o \
./EdgeFaces.o \
./EdgesFaces.o \
./Face.o \
./GameObject.o \
./Vertex.o \
./main.o 

CPP_DEPS += \
./Cube.d \
./Edge.d \
./EdgeFaces.d \
./EdgesFaces.d \
./Face.d \
./GameObject.d \
./Vertex.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


