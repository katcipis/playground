################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/xmppgui/chat/CallPanels.cpp \
../src/xmppgui/chat/ChatControler.cpp \
../src/xmppgui/chat/ChatPanel.cpp \
../src/xmppgui/chat/FileSharePanels.cpp 

OBJS += \
./src/xmppgui/chat/CallPanels.o \
./src/xmppgui/chat/ChatControler.o \
./src/xmppgui/chat/ChatPanel.o \
./src/xmppgui/chat/FileSharePanels.o 

CPP_DEPS += \
./src/xmppgui/chat/CallPanels.d \
./src/xmppgui/chat/ChatControler.d \
./src/xmppgui/chat/ChatPanel.d \
./src/xmppgui/chat/FileSharePanels.d 


# Each subdirectory must supply rules for building sources it contributes
src/xmppgui/chat/%.o: ../src/xmppgui/chat/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DUSE_WX -DPOSIX -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -I/home/cartagena/gtalk-on-linux/libjingle-0.4.0 -I"/home/cartagena/workspace/slv" -I"/home/cartagena/workspace/slv/xmppgui/include" -O3 -w -c -fmessage-length=0 `wx-config --cxxflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


