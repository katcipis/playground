################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

CPP_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../.metadata/.plugins/org.eclipse.cdt.make.core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DUSE_WX -DPOSIX -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -I/home/cartagena/gtalk-on-linux/libjingle-0.4.0 -I"/home/cartagena/workspace/slv" -I"/home/cartagena/workspace/slv/xmppgui/include" -O3 -w -c -fmessage-length=0 `wx-config --cxxflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


