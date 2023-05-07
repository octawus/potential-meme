PLATFORM	= $(shell uname)
CXX			= g++
CXXFLAGS	= -Wall -ansi -pedantic
EXECPATH	= ../executables/

SOURCES		:= $(wildcard *.cpp)
TARGETS		:= $(SOURCES:.cpp=)

##$(info $$targets is [${TARGETS}])

all: $(TARGETS)

define template
$(1):	$(1).cpp
		@echo "Building $$@... executable path is /executables/$$@.exe"
		@$(CXX) $(1).cpp $(CXXFLAGS) -o $(EXECPATH)$$@'.exe'
endef
$(foreach target,$(TARGETS),$(eval $(call template, $(target))))

clean:	
		$(foreach target, $(TARGETS), \
			echo "Removing file: $(EXECPATH)$(target).exe"; \
			$(shell rm -f $(EXECPATH)$(target).exe) \
		)

distclean: clean
		@-rm -f *~