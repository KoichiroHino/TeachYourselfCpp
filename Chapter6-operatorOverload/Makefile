PROGRAM = system # 生成したい実行ファイル名
CXX = g++
CXXFLAGS = -MMD -MP -Wall
SRCDIR = ./src
OBJDIR = ./obj
INCDIR = -I./inc

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))
DPNFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(SRCFILES))

.PHONY: all
all: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $(PROGRAM)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCDIR) $< -o $@

-include $(DPNFILES)

.PHONY: clean
clean:
	rm -f $(DPNFILES) $(OBJFILES) $(PROGRAM)

.PHONY: rebuild
rebuild: clean all
