#
# 'make'        build executable file
# 'make clean'  removes all .o and executable files
# 'make cleandep' deletes all .d files
#

### Define according to folder structure ###
INCDIR=include#	headers folder
SRCDIR=.#		source folder/s and file extension
BUILDDIR=build#	object files folder
DEPDIR=build#	dependencies folder
BINDIR=bin#		binaries folder

#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .cpp of all words in the macro SRCS
# with the .o suffix
#
# define the C source files
SRCS=$(shell find $(SRCDIR) -type f -name "*.cpp")
# define the C object files 
OBJS=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.cpp=.o))
# define the auto-generated dependency files
DEPS=$(patsubst $(SRCDIR)/%,$(DEPDIR)/%,$(SRCS:.cpp=.d))

### Define compiling process ###
CXXFLAGS=-Wall -Werror -Wno-unused -std=c++17 # Compile-time flags
INC=-I $(INCDIR)
TARGET=$(BINDIR)/a.out

$(TARGET): $(OBJS) $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INC) -o $(TARGET)

# Include dependencies files
-include $(DEPS)

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
$(DEPDIR)/%.d: $(SRCDIR)/%.cpp
	($(CXX) $(CXXFLAGS) $(INC) $< -MM -MT $(@:.d=.o); printf '\t$(CXX) $(CXXFLAGS) $(INC) -c $< -o $(@:.d=.o)\n' ;) >$@

$(DEPS): | $(DEPDIR)

$(DEPDIR):
	mkdir $(DEPDIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: clean cleandep

clean:
	rm -f $(OBJS) $(TARGET)

cleandep:
	rm -f $(DEPS)
