# directory declaration
LIB_CONSOLE_DIR = $(LIBRARIES_ROOT)/console

LIB_CONSOLE_ASMSRCDIR	= $(LIB_CONSOLE_DIR) $(LIB_CONSOLE_DIR)/xprintf
LIB_CONSOLE_CSRCDIR	= $(LIB_CONSOLE_DIR) $(LIB_CONSOLE_DIR)/xprintf
LIB_CONSOLE_INCDIR	= #$(LIB_CONSOLE_DIR) $(LIB_CONSOLE_DIR)/xprintf

# find all the source files in the target directories
LIB_CONSOLE_CSRCS = $(call get_csrcs, $(LIB_CONSOLE_CSRCDIR))
LIB_CONSOLE_ASMSRCS = $(call get_asmsrcs, $(LIB_CONSOLE_ASMSRCDIR))

# get object files
LIB_CONSOLE_COBJS = $(call get_relobjs, $(LIB_CONSOLE_CSRCS))
LIB_CONSOLE_ASMOBJS = $(call get_relobjs, $(LIB_CONSOLE_ASMSRCS))
LIB_CONSOLE_OBJS = $(LIB_CONSOLE_COBJS) $(LIB_CONSOLE_ASMOBJS)

# get dependency files
LIB_CONSOLE_DEPS = $(call get_deps, $(LIB_CONSOLE_OBJS))

# extra macros to be defined
LIB_CONSOLE_DEFINES = -DLIB_CONSOLE

# genearte library
LIB_CONSOLE = $(OUT_DIR)/libembarc_console.a


# library generation rule
$(LIB_CONSOLE): $(LIB_CONSOLE_OBJS)
	$(TRACE_ARCHIVE)
	$(Q)$(AR) $(AR_OPT) $@ $(LIB_CONSOLE_OBJS)

# specific compile rules
# user can add rules to compile this middleware
# if not rules specified to this middleware, it will use default compiling rules

# Middleware Definitions
LIB_INCDIR += $(LIB_CONSOLE_INCDIR)
LIB_CSRCDIR += $(LIB_CONSOLE_CSRCDIR)
LIB_ASMSRCDIR += $(LIB_CONSOLE_ASMSRCDIR)

LIB_CSRCS += $(LIB_CONSOLE_CSRCS)
LIB_CXXSRCS +=
LIB_ASMSRCS += $(LIB_CONSOLE_ASMSRCS)
LIB_ALLSRCS += $(LIB_CONSOLE_CSRCS) $(LIB_CONSOLE_ASMSRCS)

LIB_COBJS += $(LIB_CONSOLE_COBJS)
LIB_CXXOBJS +=
LIB_ASMOBJS += $(LIB_CONSOLE_ASMOBJS)
LIB_ALLOBJS += $(LIB_CONSOLE_OBJS)

LIB_DEFINES += $(LIB_CONSOLE_DEFINES)
LIB_DEPS += $(LIB_CONSOLE_DEPS)
LIB_LIBS += $(LIB_CONSOLE)