#############################################################################
# Makefile for building: bin/eprzelewy
# Generated by qmake (1.07a) (Qt 3.3.4) on: Sat Jan 14 15:53:14 2006
# Project:  przelewy.pro
# Template: app
# Command: $(QMAKE) -o Makefile przelewy.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT
CXXFLAGS = -pipe -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/share/qt3/mkspecs/default -I. -I/usr/include/qt3 -I.ui/ -I. -I.moc/
LINK     = g++
LFLAGS   = 
LIBS     = $(SUBLIBS) -L/usr/share/qt3/lib -L/usr/X11R6/lib -lqt-mt -lXext -lX11 -lm -lpthread
AR       = ar cqs
RANLIB   = 
MOC      = /usr/share/qt3/bin/moc
UIC      = /usr/share/qt3/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = .obj/

####### Files

HEADERS = 
SOURCES = main.cpp \
		slownie.cpp
OBJECTS = .obj/main.o \
		.obj/slownie.o \
		.obj/kontr.o \
		.obj/kreator.o \
		.obj/mainform.o \
		.obj/preview.o \
		.obj/przelew.o \
		.obj/sett.o \
		.obj/user.o \
		.obj/us.o \
		.obj/zus.o
FORMS = kontr.ui \
		kreator.ui \
		mainform.ui \
		preview.ui \
		przelew.ui \
		sett.ui \
		user.ui \
		us.ui \
		zus.ui
UICDECLS = .ui/kontr.h \
		.ui/kreator.h \
		.ui/mainform.h \
		.ui/preview.h \
		.ui/przelew.h \
		.ui/sett.h \
		.ui/user.h \
		.ui/us.h \
		.ui/zus.h
UICIMPLS = .ui/kontr.cpp \
		.ui/kreator.cpp \
		.ui/mainform.cpp \
		.ui/preview.cpp \
		.ui/przelew.cpp \
		.ui/sett.cpp \
		.ui/user.cpp \
		.ui/us.cpp \
		.ui/zus.cpp
SRCMOC   = .moc/moc_kontr.cpp \
		.moc/moc_kreator.cpp \
		.moc/moc_mainform.cpp \
		.moc/moc_preview.cpp \
		.moc/moc_przelew.cpp \
		.moc/moc_sett.cpp \
		.moc/moc_user.cpp \
		.moc/moc_us.cpp \
		.moc/moc_zus.cpp
OBJMOC = .obj/moc_kontr.o \
		.obj/moc_kreator.o \
		.obj/moc_mainform.o \
		.obj/moc_preview.o \
		.obj/moc_przelew.o \
		.obj/moc_sett.o \
		.obj/moc_user.o \
		.obj/moc_us.o \
		.obj/moc_zus.o
DIST	   = przelewy.pro
QMAKE_TARGET = eprzelewy
DESTDIR  = bin/
TARGET   = bin/eprzelewy

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  
	test -d bin/ || mkdir -p bin/
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: przelewy.pro  /usr/share/qt3/mkspecs/default/qmake.conf /usr/share/qt3/lib/libqt-mt.prl
	$(QMAKE) -o Makefile przelewy.pro
qmake: 
	@$(QMAKE) -o Makefile przelewy.pro

dist: 
	@mkdir -p .obj/eprzelewy && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .obj/eprzelewy/ && $(COPY_FILE) --parents kontr.ui.h kreator.ui.h mainform.ui.h preview.ui.h przelew.ui.h sett.ui.h user.ui.h us.ui.h zus.ui.h .obj/eprzelewy/ && ( cd `dirname .obj/eprzelewy` && $(TAR) eprzelewy.tar eprzelewy && $(GZIP) eprzelewy.tar ) && $(MOVE) `dirname .obj/eprzelewy`/eprzelewy.tar.gz . && $(DEL_FILE) -r .obj/eprzelewy

mocclean:
	-$(DEL_FILE) $(OBJMOC)
	-$(DEL_FILE) $(SRCMOC)

uiclean:
	-$(DEL_FILE) $(UICIMPLS) $(UICDECLS)

yaccclean:
lexclean:
clean: mocclean uiclean
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) bin/$(TARGET) $(TARGET)


FORCE:

####### Compile

.obj/main.o: main.cpp .ui/mainform.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o main.cpp

.obj/slownie.o: slownie.cpp slownie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/slownie.o slownie.cpp

.ui/kontr.h: kontr.ui 
	$(UIC) kontr.ui -o .ui/kontr.h

.ui/kontr.cpp: .ui/kontr.h kontr.ui kontr.ui.h 
	$(UIC) kontr.ui -i kontr.h -o .ui/kontr.cpp

.ui/kreator.h: kreator.ui 
	$(UIC) kreator.ui -o .ui/kreator.h

.ui/kreator.cpp: .ui/kreator.h kreator.ui kreator.ui.h 
	$(UIC) kreator.ui -i kreator.h -o .ui/kreator.cpp

.ui/mainform.h: mainform.ui 
	$(UIC) mainform.ui -o .ui/mainform.h

.ui/mainform.cpp: .ui/mainform.h mainform.ui mainform.ui.h 
	$(UIC) mainform.ui -i mainform.h -o .ui/mainform.cpp

.ui/preview.h: preview.ui 
	$(UIC) preview.ui -o .ui/preview.h

.ui/preview.cpp: .ui/preview.h preview.ui preview.ui.h 
	$(UIC) preview.ui -i preview.h -o .ui/preview.cpp

.ui/przelew.h: przelew.ui 
	$(UIC) przelew.ui -o .ui/przelew.h

.ui/przelew.cpp: .ui/przelew.h przelew.ui przelew.ui.h 
	$(UIC) przelew.ui -i przelew.h -o .ui/przelew.cpp

.ui/sett.h: sett.ui 
	$(UIC) sett.ui -o .ui/sett.h

.ui/sett.cpp: .ui/sett.h sett.ui sett.ui.h 
	$(UIC) sett.ui -i sett.h -o .ui/sett.cpp

.ui/user.h: user.ui 
	$(UIC) user.ui -o .ui/user.h

.ui/user.cpp: .ui/user.h user.ui user.ui.h 
	$(UIC) user.ui -i user.h -o .ui/user.cpp

.ui/us.h: us.ui 
	$(UIC) us.ui -o .ui/us.h

.ui/us.cpp: .ui/us.h us.ui us.ui.h 
	$(UIC) us.ui -i us.h -o .ui/us.cpp

.ui/zus.h: zus.ui 
	$(UIC) zus.ui -o .ui/zus.h

.ui/zus.cpp: .ui/zus.h zus.ui zus.ui.h 
	$(UIC) zus.ui -i zus.h -o .ui/zus.cpp

.obj/kontr.o: .ui/kontr.cpp kontr.ui.h \
		.ui/kontr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/kontr.o .ui/kontr.cpp

.obj/kreator.o: .ui/kreator.cpp kreator.ui.h \
		.ui/kreator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/kreator.o .ui/kreator.cpp

.obj/mainform.o: .ui/mainform.cpp mainform.ui.h \
		.ui/mainform.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/mainform.o .ui/mainform.cpp

.obj/preview.o: .ui/preview.cpp preview.ui.h \
		.ui/preview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/preview.o .ui/preview.cpp

.obj/przelew.o: .ui/przelew.cpp przelew.ui.h \
		.ui/przelew.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/przelew.o .ui/przelew.cpp

.obj/sett.o: .ui/sett.cpp sett.ui.h \
		.ui/sett.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sett.o .ui/sett.cpp

.obj/user.o: .ui/user.cpp user.ui.h \
		.ui/user.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/user.o .ui/user.cpp

.obj/us.o: .ui/us.cpp us.ui.h \
		.ui/us.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/us.o .ui/us.cpp

.obj/zus.o: .ui/zus.cpp zus.ui.h \
		.ui/zus.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/zus.o .ui/zus.cpp

.obj/moc_kontr.o: .moc/moc_kontr.cpp  .ui/kontr.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_kontr.o .moc/moc_kontr.cpp

.obj/moc_kreator.o: .moc/moc_kreator.cpp  .ui/kreator.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_kreator.o .moc/moc_kreator.cpp

.obj/moc_mainform.o: .moc/moc_mainform.cpp  .ui/mainform.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_mainform.o .moc/moc_mainform.cpp

.obj/moc_preview.o: .moc/moc_preview.cpp  .ui/preview.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_preview.o .moc/moc_preview.cpp

.obj/moc_przelew.o: .moc/moc_przelew.cpp  .ui/przelew.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_przelew.o .moc/moc_przelew.cpp

.obj/moc_sett.o: .moc/moc_sett.cpp  .ui/sett.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_sett.o .moc/moc_sett.cpp

.obj/moc_user.o: .moc/moc_user.cpp  .ui/user.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_user.o .moc/moc_user.cpp

.obj/moc_us.o: .moc/moc_us.cpp  .ui/us.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_us.o .moc/moc_us.cpp

.obj/moc_zus.o: .moc/moc_zus.cpp  .ui/zus.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_zus.o .moc/moc_zus.cpp

.moc/moc_kontr.cpp: $(MOC) .ui/kontr.h
	$(MOC) .ui/kontr.h -o .moc/moc_kontr.cpp

.moc/moc_kreator.cpp: $(MOC) .ui/kreator.h
	$(MOC) .ui/kreator.h -o .moc/moc_kreator.cpp

.moc/moc_mainform.cpp: $(MOC) .ui/mainform.h
	$(MOC) .ui/mainform.h -o .moc/moc_mainform.cpp

.moc/moc_preview.cpp: $(MOC) .ui/preview.h
	$(MOC) .ui/preview.h -o .moc/moc_preview.cpp

.moc/moc_przelew.cpp: $(MOC) .ui/przelew.h
	$(MOC) .ui/przelew.h -o .moc/moc_przelew.cpp

.moc/moc_sett.cpp: $(MOC) .ui/sett.h
	$(MOC) .ui/sett.h -o .moc/moc_sett.cpp

.moc/moc_user.cpp: $(MOC) .ui/user.h
	$(MOC) .ui/user.h -o .moc/moc_user.cpp

.moc/moc_us.cpp: $(MOC) .ui/us.h
	$(MOC) .ui/us.h -o .moc/moc_us.cpp

.moc/moc_zus.cpp: $(MOC) .ui/zus.h
	$(MOC) .ui/zus.h -o .moc/moc_zus.cpp

####### Install

install:  

uninstall:  

