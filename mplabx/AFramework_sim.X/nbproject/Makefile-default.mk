#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../src/main.cpp ../../src/ACore.cpp ../../src/AString.cpp ../../src/APorts.cpp ../../src/ATimers.cpp ../../src/AErrorNotifier.cpp ../../src/AConfigurationBits.cpp ../../src/Ap32mx270f256d.S ../../src/ATime.cpp ../../src/AInterruptSource.cpp ../../src/ALcd.cpp ../../src/APCF8563.cpp ../../src/AI2CDriver.cpp ../../src/ADateTime.cpp ../../src/A24LC512.cpp ../../src/AUARTDriver.cpp ../../src/AESP8266.cpp ../../src/AESP07.cpp ../../src/AADC.cpp ../../src/ARTCC.cpp ../../src/ADht22.cpp ../../src/ADS18B20.cpp ../../src/AOneWire.cpp ../../src/SmartMote.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1445274692/main.o ${OBJECTDIR}/_ext/1445274692/ACore.o ${OBJECTDIR}/_ext/1445274692/AString.o ${OBJECTDIR}/_ext/1445274692/APorts.o ${OBJECTDIR}/_ext/1445274692/ATimers.o ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o ${OBJECTDIR}/_ext/1445274692/ATime.o ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o ${OBJECTDIR}/_ext/1445274692/ALcd.o ${OBJECTDIR}/_ext/1445274692/APCF8563.o ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o ${OBJECTDIR}/_ext/1445274692/ADateTime.o ${OBJECTDIR}/_ext/1445274692/A24LC512.o ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o ${OBJECTDIR}/_ext/1445274692/AESP8266.o ${OBJECTDIR}/_ext/1445274692/AESP07.o ${OBJECTDIR}/_ext/1445274692/AADC.o ${OBJECTDIR}/_ext/1445274692/ARTCC.o ${OBJECTDIR}/_ext/1445274692/ADht22.o ${OBJECTDIR}/_ext/1445274692/ADS18B20.o ${OBJECTDIR}/_ext/1445274692/AOneWire.o ${OBJECTDIR}/_ext/1445274692/SmartMote.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1445274692/main.o.d ${OBJECTDIR}/_ext/1445274692/ACore.o.d ${OBJECTDIR}/_ext/1445274692/AString.o.d ${OBJECTDIR}/_ext/1445274692/APorts.o.d ${OBJECTDIR}/_ext/1445274692/ATimers.o.d ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o.d ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o.d ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.d ${OBJECTDIR}/_ext/1445274692/ATime.o.d ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o.d ${OBJECTDIR}/_ext/1445274692/ALcd.o.d ${OBJECTDIR}/_ext/1445274692/APCF8563.o.d ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o.d ${OBJECTDIR}/_ext/1445274692/ADateTime.o.d ${OBJECTDIR}/_ext/1445274692/A24LC512.o.d ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o.d ${OBJECTDIR}/_ext/1445274692/AESP8266.o.d ${OBJECTDIR}/_ext/1445274692/AESP07.o.d ${OBJECTDIR}/_ext/1445274692/AADC.o.d ${OBJECTDIR}/_ext/1445274692/ARTCC.o.d ${OBJECTDIR}/_ext/1445274692/ADht22.o.d ${OBJECTDIR}/_ext/1445274692/ADS18B20.o.d ${OBJECTDIR}/_ext/1445274692/AOneWire.o.d ${OBJECTDIR}/_ext/1445274692/SmartMote.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1445274692/main.o ${OBJECTDIR}/_ext/1445274692/ACore.o ${OBJECTDIR}/_ext/1445274692/AString.o ${OBJECTDIR}/_ext/1445274692/APorts.o ${OBJECTDIR}/_ext/1445274692/ATimers.o ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o ${OBJECTDIR}/_ext/1445274692/ATime.o ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o ${OBJECTDIR}/_ext/1445274692/ALcd.o ${OBJECTDIR}/_ext/1445274692/APCF8563.o ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o ${OBJECTDIR}/_ext/1445274692/ADateTime.o ${OBJECTDIR}/_ext/1445274692/A24LC512.o ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o ${OBJECTDIR}/_ext/1445274692/AESP8266.o ${OBJECTDIR}/_ext/1445274692/AESP07.o ${OBJECTDIR}/_ext/1445274692/AADC.o ${OBJECTDIR}/_ext/1445274692/ARTCC.o ${OBJECTDIR}/_ext/1445274692/ADht22.o ${OBJECTDIR}/_ext/1445274692/ADS18B20.o ${OBJECTDIR}/_ext/1445274692/AOneWire.o ${OBJECTDIR}/_ext/1445274692/SmartMote.o

# Source Files
SOURCEFILES=../../src/main.cpp ../../src/ACore.cpp ../../src/AString.cpp ../../src/APorts.cpp ../../src/ATimers.cpp ../../src/AErrorNotifier.cpp ../../src/AConfigurationBits.cpp ../../src/Ap32mx270f256d.S ../../src/ATime.cpp ../../src/AInterruptSource.cpp ../../src/ALcd.cpp ../../src/APCF8563.cpp ../../src/AI2CDriver.cpp ../../src/ADateTime.cpp ../../src/A24LC512.cpp ../../src/AUARTDriver.cpp ../../src/AESP8266.cpp ../../src/AESP07.cpp ../../src/AADC.cpp ../../src/ARTCC.cpp ../../src/ADht22.cpp ../../src/ADS18B20.cpp ../../src/AOneWire.cpp ../../src/SmartMote.cpp


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX270F256B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o: ../../src/Ap32mx270f256d.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o 
	@${RM} ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.ok ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.d" "${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.d"  -o ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o ../../src/Ap32mx270f256d.S  -DXPRJ_default=$(CND_CONF)  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-I"../../include"
	
else
${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o: ../../src/Ap32mx270f256d.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o 
	@${RM} ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.ok ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.d" "${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.d"  -o ${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o ../../src/Ap32mx270f256d.S  -DXPRJ_default=$(CND_CONF)  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1445274692/Ap32mx270f256d.o.asm.d",--gdwarf-2,-I"../../include"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1445274692/main.o: ../../src/main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/main.o.d" -o ${OBJECTDIR}/_ext/1445274692/main.o ../../src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ACore.o: ../../src/ACore.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ACore.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ACore.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ACore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ACore.o.d" -o ${OBJECTDIR}/_ext/1445274692/ACore.o ../../src/ACore.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AString.o: ../../src/AString.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AString.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AString.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AString.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AString.o.d" -o ${OBJECTDIR}/_ext/1445274692/AString.o ../../src/AString.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/APorts.o: ../../src/APorts.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APorts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APorts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/APorts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/APorts.o.d" -o ${OBJECTDIR}/_ext/1445274692/APorts.o ../../src/APorts.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ATimers.o: ../../src/ATimers.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATimers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATimers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ATimers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ATimers.o.d" -o ${OBJECTDIR}/_ext/1445274692/ATimers.o ../../src/ATimers.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o: ../../src/AErrorNotifier.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o.d" -o ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o ../../src/AErrorNotifier.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o: ../../src/AConfigurationBits.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o.d" -o ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o ../../src/AConfigurationBits.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ATime.o: ../../src/ATime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ATime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ATime.o.d" -o ${OBJECTDIR}/_ext/1445274692/ATime.o ../../src/ATime.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AInterruptSource.o: ../../src/AInterruptSource.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AInterruptSource.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AInterruptSource.o.d" -o ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o ../../src/AInterruptSource.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ALcd.o: ../../src/ALcd.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ALcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ALcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ALcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ALcd.o.d" -o ${OBJECTDIR}/_ext/1445274692/ALcd.o ../../src/ALcd.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/APCF8563.o: ../../src/APCF8563.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APCF8563.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APCF8563.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/APCF8563.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/APCF8563.o.d" -o ${OBJECTDIR}/_ext/1445274692/APCF8563.o ../../src/APCF8563.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AI2CDriver.o: ../../src/AI2CDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AI2CDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AI2CDriver.o.d" -o ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o ../../src/AI2CDriver.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ADateTime.o: ../../src/ADateTime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADateTime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADateTime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ADateTime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ADateTime.o.d" -o ${OBJECTDIR}/_ext/1445274692/ADateTime.o ../../src/ADateTime.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/A24LC512.o: ../../src/A24LC512.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/A24LC512.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/A24LC512.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/A24LC512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/A24LC512.o.d" -o ${OBJECTDIR}/_ext/1445274692/A24LC512.o ../../src/A24LC512.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AUARTDriver.o: ../../src/AUARTDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AUARTDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AUARTDriver.o.d" -o ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o ../../src/AUARTDriver.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AESP8266.o: ../../src/AESP8266.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP8266.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP8266.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AESP8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AESP8266.o.d" -o ${OBJECTDIR}/_ext/1445274692/AESP8266.o ../../src/AESP8266.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AESP07.o: ../../src/AESP07.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP07.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP07.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AESP07.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AESP07.o.d" -o ${OBJECTDIR}/_ext/1445274692/AESP07.o ../../src/AESP07.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AADC.o: ../../src/AADC.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AADC.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AADC.o.d" -o ${OBJECTDIR}/_ext/1445274692/AADC.o ../../src/AADC.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ARTCC.o: ../../src/ARTCC.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ARTCC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ARTCC.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ARTCC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ARTCC.o.d" -o ${OBJECTDIR}/_ext/1445274692/ARTCC.o ../../src/ARTCC.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ADht22.o: ../../src/ADht22.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADht22.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADht22.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ADht22.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ADht22.o.d" -o ${OBJECTDIR}/_ext/1445274692/ADht22.o ../../src/ADht22.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ADS18B20.o: ../../src/ADS18B20.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADS18B20.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADS18B20.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ADS18B20.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ADS18B20.o.d" -o ${OBJECTDIR}/_ext/1445274692/ADS18B20.o ../../src/ADS18B20.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AOneWire.o: ../../src/AOneWire.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AOneWire.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AOneWire.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AOneWire.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AOneWire.o.d" -o ${OBJECTDIR}/_ext/1445274692/AOneWire.o ../../src/AOneWire.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/SmartMote.o: ../../src/SmartMote.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/SmartMote.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/SmartMote.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/SmartMote.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/SmartMote.o.d" -o ${OBJECTDIR}/_ext/1445274692/SmartMote.o ../../src/SmartMote.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1445274692/main.o: ../../src/main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/main.o.d" -o ${OBJECTDIR}/_ext/1445274692/main.o ../../src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ACore.o: ../../src/ACore.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ACore.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ACore.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ACore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ACore.o.d" -o ${OBJECTDIR}/_ext/1445274692/ACore.o ../../src/ACore.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AString.o: ../../src/AString.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AString.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AString.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AString.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AString.o.d" -o ${OBJECTDIR}/_ext/1445274692/AString.o ../../src/AString.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/APorts.o: ../../src/APorts.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APorts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APorts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/APorts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/APorts.o.d" -o ${OBJECTDIR}/_ext/1445274692/APorts.o ../../src/APorts.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ATimers.o: ../../src/ATimers.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATimers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATimers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ATimers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ATimers.o.d" -o ${OBJECTDIR}/_ext/1445274692/ATimers.o ../../src/ATimers.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o: ../../src/AErrorNotifier.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o.d" -o ${OBJECTDIR}/_ext/1445274692/AErrorNotifier.o ../../src/AErrorNotifier.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o: ../../src/AConfigurationBits.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o.d" -o ${OBJECTDIR}/_ext/1445274692/AConfigurationBits.o ../../src/AConfigurationBits.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ATime.o: ../../src/ATime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ATime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ATime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ATime.o.d" -o ${OBJECTDIR}/_ext/1445274692/ATime.o ../../src/ATime.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AInterruptSource.o: ../../src/AInterruptSource.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AInterruptSource.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AInterruptSource.o.d" -o ${OBJECTDIR}/_ext/1445274692/AInterruptSource.o ../../src/AInterruptSource.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ALcd.o: ../../src/ALcd.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ALcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ALcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ALcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ALcd.o.d" -o ${OBJECTDIR}/_ext/1445274692/ALcd.o ../../src/ALcd.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/APCF8563.o: ../../src/APCF8563.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APCF8563.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/APCF8563.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/APCF8563.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/APCF8563.o.d" -o ${OBJECTDIR}/_ext/1445274692/APCF8563.o ../../src/APCF8563.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AI2CDriver.o: ../../src/AI2CDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AI2CDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AI2CDriver.o.d" -o ${OBJECTDIR}/_ext/1445274692/AI2CDriver.o ../../src/AI2CDriver.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ADateTime.o: ../../src/ADateTime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADateTime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADateTime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ADateTime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ADateTime.o.d" -o ${OBJECTDIR}/_ext/1445274692/ADateTime.o ../../src/ADateTime.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/A24LC512.o: ../../src/A24LC512.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/A24LC512.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/A24LC512.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/A24LC512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/A24LC512.o.d" -o ${OBJECTDIR}/_ext/1445274692/A24LC512.o ../../src/A24LC512.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AUARTDriver.o: ../../src/AUARTDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AUARTDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AUARTDriver.o.d" -o ${OBJECTDIR}/_ext/1445274692/AUARTDriver.o ../../src/AUARTDriver.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AESP8266.o: ../../src/AESP8266.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP8266.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP8266.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AESP8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AESP8266.o.d" -o ${OBJECTDIR}/_ext/1445274692/AESP8266.o ../../src/AESP8266.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AESP07.o: ../../src/AESP07.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP07.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AESP07.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AESP07.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AESP07.o.d" -o ${OBJECTDIR}/_ext/1445274692/AESP07.o ../../src/AESP07.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AADC.o: ../../src/AADC.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AADC.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AADC.o.d" -o ${OBJECTDIR}/_ext/1445274692/AADC.o ../../src/AADC.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ARTCC.o: ../../src/ARTCC.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ARTCC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ARTCC.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ARTCC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ARTCC.o.d" -o ${OBJECTDIR}/_ext/1445274692/ARTCC.o ../../src/ARTCC.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ADht22.o: ../../src/ADht22.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADht22.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADht22.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ADht22.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ADht22.o.d" -o ${OBJECTDIR}/_ext/1445274692/ADht22.o ../../src/ADht22.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/ADS18B20.o: ../../src/ADS18B20.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADS18B20.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/ADS18B20.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/ADS18B20.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/ADS18B20.o.d" -o ${OBJECTDIR}/_ext/1445274692/ADS18B20.o ../../src/ADS18B20.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/AOneWire.o: ../../src/AOneWire.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AOneWire.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/AOneWire.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/AOneWire.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/AOneWire.o.d" -o ${OBJECTDIR}/_ext/1445274692/AOneWire.o ../../src/AOneWire.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/SmartMote.o: ../../src/SmartMote.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/SmartMote.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/SmartMote.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/SmartMote.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445274692/SmartMote.o.d" -o ${OBJECTDIR}/_ext/1445274692/SmartMote.o ../../src/SmartMote.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)    -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=16392,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=16392,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/AFramework_sim.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
