TARGET			?= Offer10

CC				:= gcc

INCLUDIRS		:= include

SRCDIRS			:= project

INCLUDE			:= $(patsubst %, -I %, $(INCLUDIRS))

CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

CFILENDIR		:= $(notdir $(CFILES))

COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))

OBJS			:= $(COBJS)

VPATH			:= $(SRCDIRS)
.PHONY:clean

$(TARGET) : $(OBJS)
	$(CC) $^ -o $@

$(COBJS) : obj/%.o : %.c
	$(CC) -g -Wall -c $(INCLUDE) -o $@ $<

clean:
	rm -rf $(TARGET) $(OBJS)

print:
	@echo INCLUDE = $(INCLUDE)
	@echo CFILES = $(CFILES)
	@echo CFILENDIR = $(CFILENDIR)
	@echo COBJS = $(COBJS)
	@echo OBJS = $(OBJS)
