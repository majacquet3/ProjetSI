# Configuration QT
QT          += core gui opengl

# Type d'objet gnr et destination
TARGET       = projet-si
TEMPLATE     = app

QMAKE_CXXFLAGS += -DEBUG -g -Wall

# Fichier sources
SOURCES     += \
               binaryconversionpass.cpp \
               blurpass.cpp \
               houghcircledetectionpass.cpp \
               gaussianblurpass.cpp \
               graylevelpass.cpp \
               videoextractor.cpp \
               imageconverter.cpp \
               imageprocessor.cpp \
               ipass.cpp \
               main.cpp \
               mainwindow.cpp \
               passchain.cpp \
               controller.cpp \
               circle.cpp \
               customcircledetectionpass.cpp \
               roipass.cpp \
               parameterdock.cpp \
               imagescaledialog.cpp \
               customgraphicsscene.cpp \
               videoprocessor.cpp \
               cannyfilterpass.cpp \
    customgraphicsview.cpp \
    angledetectionpass.cpp \
    circledetectionpass.cpp \
    aboutdialog.cpp \
    extractsequencedialog.cpp \
    meanshiftfilterpass.cpp \
    dynamicpasschain.cpp \
    sobelfilterpass.cpp \
    savedialog.cpp

# Fichiers d'entte
HEADERS     += \
               binaryconversionpass.h \
               blurpass.h \
               houghcircledetectionpass.h \
               gaussianblurpass.h \
               graylevelpass.h \
               videoextractor.h \
               imageconverter.h \
               imageprocessor.h \
               ipass.h \
               mainwindow.h \
               passchain.h \
               controller.h \
               circle.h \
               customcircledetectionpass.h \
               roipass.h \
               parameterdock.h \
               imagescaledialog.h \
               customgraphicsscene.h \
               videoprocessor.h \
               cannyfilterpass.h \
    customgraphicsview.h \
    angledetectionpass.h \
    circledetectionpass.h \
    aboutdialog.h \
    extractsequencedialog.h \
    meanshiftfilterpass.h \
    dynamicpasschain.h \
    sobelfilterpass.h \
    savedialog.h


# Fichiers UI  compiler
FORMS       += mainwindow.ui \
    parameterdock.ui \
    imagescaledialog.ui \
    aboutdialog.ui \
    extractsequencedialog.ui \
    dynamicpasschain.ui \
    savedialog.ui

# Fichiers ressources
RESOURCES   += toolbar.qrc
#RC_FILE     += resources.rc

# Bibliothques  inclure
LIBS += -lopencv_core \
        -lopencv_gpu \
        -lopencv_video \
        -lopencv_legacy \
        -lopencv_imgproc \
        -lopencv_highgui
