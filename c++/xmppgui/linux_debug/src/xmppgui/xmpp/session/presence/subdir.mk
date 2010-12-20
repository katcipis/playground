################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/xmppgui/xmpp/session/presence/PresenceTask.cpp 

OBJS += \
./src/xmppgui/xmpp/session/presence/PresenceTask.o 

CPP_DEPS += \
./src/xmppgui/xmpp/session/presence/PresenceTask.d 


# Each subdirectory must supply rules for building sources it contributes
src/xmppgui/xmpp/session/presence/%.o: ../src/xmppgui/xmpp/session/presence/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DUSE_WX -DPOSIX -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -I/home/cartagena/gtalk-on-linux/libjingle-0.4.0 -I"/home/cartagena/workspace/slv" -I"/home/cartagena/workspace/slv/xmppgui/include" -O3 -w -c -fmessage-length=0 `wx-config --cxxflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


