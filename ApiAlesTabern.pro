QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bitacora.cpp \
    bitacoraform.cpp \
    egresoform.cpp \
    ingresoform.cpp \
    inventario.cpp \
    main.cpp \
    interfaz.cpp \
    nuevoproductoform.cpp \
    productos.cpp

HEADERS += \
    bitacora.h \
    bitacoraform.h \
    egresoform.h \
    ingresoform.h \
    interfaz.h \
    inventario.h \
    nuevoproductoform.h \
    productos.h

FORMS += \
    bitacoraform.ui \
    egresoform.ui \
    ingresoform.ui \
    interfaz.ui \
    nuevoproductoform.ui

TRANSLATIONS += \

    en.ts
    it.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
