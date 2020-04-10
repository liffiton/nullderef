obj-m = nullderef.o

all: nullderef.ko exploit quicktest

clean:
	rm nullderef.ko exploit quicktest

nullderef.ko: nullderef.c
	$(MAKE) -C '/lib/modules/$(shell uname -r)/build/' \
		O='/lib/modules/$(shell uname -r)/build/' \
		"M=$$PWD" modules

exploit: exploit.c

quicktest: quicktest.c
