################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/ButterflySubspaceDivision.cpp \
../Source/CatmullClarkSubDivision.cpp \
../Source/Cube.cpp \
../Source/Edge.cpp \
../Source/EdgeFaces.cpp \
../Source/EdgesFaces.cpp \
../Source/Face.cpp \
../Source/Face3.cpp \
../Source/Face4.cpp \
../Source/GameObject.cpp \
../Source/ObjectManager.cpp \
../Source/Vertex.cpp 

OBJS += \
./Source/ButterflySubspaceDivision.o \
./Source/CatmullClarkSubDivision.o \
./Source/Cube.o \
./Source/Edge.o \
./Source/EdgeFaces.o \
./Source/EdgesFaces.o \
./Source/Face.o \
./Source/Face3.o \
./Source/Face4.o \
./Source/GameObject.o \
./Source/ObjectManager.o \
./Source/Vertex.o 

CPP_DEPS += \
./Source/ButterflySubspaceDivision.d \
./Source/CatmullClarkSubDivision.d \
./Source/Cube.d \
./Source/Edge.d \
./Source/EdgeFaces.d \
./Source/EdgesFaces.d \
./Source/Face.d \
./Source/Face3.d \
./Source/Face4.d \
./Source/GameObject.d \
./Source/ObjectManager.d \
./Source/Vertex.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


