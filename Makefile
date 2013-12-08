OBJDIR := bin
OBJS := $(addprefix $(OBJDIR)/,addgesture checkgesture delgesture gesture initialize main)

$(OBJDIR)/% : src/%.cpp
	$(CXX) `pkg-config opencv --cflags` $(OUTPUT_OPTION) $< `pkg-config opencv --libs` -lX11 -lXtst

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)
