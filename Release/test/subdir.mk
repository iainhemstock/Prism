################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/ArrayTest.cpp \
../test/BitvectorTest.cpp \
../test/CircleTest.cpp \
../test/DequeTest.cpp \
../test/ListTest.cpp \
../test/PairTest.cpp \
../test/ReverseIteratorTest.cpp \
../test/SharedDataPointerTest.cpp \
../test/SharedDataTest.cpp \
../test/StackTest.cpp \
../test/StringTest.cpp \
../test/TimeTest.cpp \
../test/UniquePointerArrayTest.cpp \
../test/UniquePointerTest.cpp \
../test/VectorTest.cpp \
../test/VersionTest.cpp \
../test/algorithmTest.cpp \
../test/functorTest.cpp \
../test/type_traitsTest.cpp 

OBJS += \
./test/ArrayTest.o \
./test/BitvectorTest.o \
./test/CircleTest.o \
./test/DequeTest.o \
./test/ListTest.o \
./test/PairTest.o \
./test/ReverseIteratorTest.o \
./test/SharedDataPointerTest.o \
./test/SharedDataTest.o \
./test/StackTest.o \
./test/StringTest.o \
./test/TimeTest.o \
./test/UniquePointerArrayTest.o \
./test/UniquePointerTest.o \
./test/VectorTest.o \
./test/VersionTest.o \
./test/algorithmTest.o \
./test/functorTest.o \
./test/type_traitsTest.o 

CPP_DEPS += \
./test/ArrayTest.d \
./test/BitvectorTest.d \
./test/CircleTest.d \
./test/DequeTest.d \
./test/ListTest.d \
./test/PairTest.d \
./test/ReverseIteratorTest.d \
./test/SharedDataPointerTest.d \
./test/SharedDataTest.d \
./test/StackTest.d \
./test/StringTest.d \
./test/TimeTest.d \
./test/UniquePointerArrayTest.d \
./test/UniquePointerTest.d \
./test/VectorTest.d \
./test/VersionTest.d \
./test/algorithmTest.d \
./test/functorTest.d \
./test/type_traitsTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

