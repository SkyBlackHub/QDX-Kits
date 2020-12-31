!include(../src/Kits.pri) {
	error("Couldn't find the Kits.pri file!")
}

QT += testlib

SOURCES += \
	main.cpp