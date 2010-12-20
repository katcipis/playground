################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/xmppgui/GuiContact.cpp \
../src/xmppgui/Login.cpp \
../src/xmppgui/PresenceList.cpp 

OBJS += \
./src/xmppgui/GuiContact.o \
./src/xmppgui/Login.o \
./src/xmppgui/PresenceList.o 

CPP_DEPS += \
./src/xmppgui/GuiContact.d \
./src/xmppgui/Login.d \
./src/xmppgui/PresenceList.d 


# Each subdirectory must supply rules for building sources it contributes
src/xmppgui/%.o: ../src/xmppgui/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DUSE_WX -DPOSIX -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -I/home/cartagena/gtalk-on-linux/libjingle-0.4.0 -I"/home/cartagena/workspace/slv" -I"/home/cartagena/workspace/slv/xmppgui/include" -O3 -w -c -fmessage-length=0 `wx-config --cxxflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


