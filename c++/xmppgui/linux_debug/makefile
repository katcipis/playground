################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/xmppgui/xmpp/session/roster/subdir.mk
-include src/xmppgui/xmpp/session/presence/subdir.mk
-include src/xmppgui/xmpp/subdir.mk
-include src/xmppgui/util/subdir.mk
-include src/xmppgui/data/subdir.mk
-include src/xmppgui/chat/slv/subdir.mk
-include src/xmppgui/chat/subdir.mk
-include src/xmppgui/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: XmppGui

# Tool invocations
XmppGui: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L/home/cartagena/gtalk-on-linux/.libs -L/usr/local/lib `wx-config --libs` -o"XmppGui" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) XmppGui
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
