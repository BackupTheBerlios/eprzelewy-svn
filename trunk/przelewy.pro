TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release QT_NO_DEBUG

SOURCES	+= main.cpp \
	slownie.cpp


FORMS	= kontr.ui \
	kreator.ui \
	mainform.ui \
	preview.ui \
	przelew.ui \  
	sett.ui \
	user.ui \ 
	us.ui \ 
	zus.ui

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}

TARGET = bin/eprzelewy
