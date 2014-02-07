QT += widgets quick gui opengl xml

FORMS += \
    ../src/uberCode.ui

HEADERS += \
    ../src/BlockNavigationTreeWidget.h \
    ../src/Composition.h \
    ../src/DataflowEngineManager.h \
    ../src/MainWindow.h \
    ../src/QGlTextureImage.h \
    ../src/SettingsDialog.h \
    ../src/SettingsItemEditor.h \
    ../src/SettingsManager.h \
    ../src/UbAbstractBlock.h \
    ../src/UbBundleBlock.h \
    ../src/UbComposition.h \
    ../src/UbGraphicsScene.h \
    ../src/UbGraphicsView.h \
    ../src/UbImage.h \
    ../src/UbImageView.h \
    ../src/UbInletNode.h \
    ../src/UbInputBlock.h \
    ../src/UbInterfaceBlock.h \
    ../src/UbLink.h \
    ../src/UbLinkController.h \
    ../src/UbMultiInletNode.h \
    ../src/UbMultiNodeContainer.h \
    ../src/UbNode.h \
    ../src/UbObject.h \
    ../src/UbOutletNode.h \
    ../src/UbOutputBlock.h \
    ../src/UbPathBlock.h \
    ../src/UbRadiobutton.h \
    ../src/UbSlider.h \
    ../src/UbTypes.h \
    ../src/UbXMLReader.h \
    ../src/UbXMLWriter.h \
    ../src/WorkbenchGraphicsScene.h \
    ../src/UbSpinbox.h

SOURCES += \
    ../src/BlockNavigationTreeWidget.cpp \
    ../src/Composition.cpp \
    ../src/DataflowEngineManager.cpp \
    ../src/main.cpp \
    ../src/MainWindow.cpp \
    ../src/QGlTextureImage.cpp \
    ../src/SettingsDialog.cpp \
    ../src/SettingsItemEditor.cpp \
    ../src/SettingsManager.cpp \
    ../src/UbAbstractBlock.cpp \
    ../src/UbBundleBlock.cpp \
    ../src/UbComposition.cpp \
    ../src/UbGraphicsScene.cpp \
    ../src/UbGraphicsView.cpp \
    ../src/UbImage.cpp \
    ../src/UbImageView.cpp \
    ../src/UbInletNode.cpp \
    ../src/UbInputBlock.cpp \
    ../src/UbInterfaceBlock.cpp \
    ../src/UbLink.cpp \
    ../src/UbLinkController.cpp \
    ../src/UbMultiInletNode.cpp \
    ../src/UbMultiNodeContainer.cpp \
    ../src/UbNode.cpp \
    ../src/UbObject.cpp \
    ../src/UbOutletNode.cpp \
    ../src/UbOutputBlock.cpp \
    ../src/UbPathBlock.cpp \
    ../src/UbRadiobutton.cpp \
    ../src/UbSlider.cpp \
    ../src/UbXMLReader.cpp \
    ../src/UbXMLWriter.cpp \
    ../src/WorkbenchGraphicsScene.cpp \
    ../src/UbSpinbox.cpp

unix:!macx: LIBS += -L$$PWD/../_2RealFramework/kernel/lib/ -l_2RealFrameworkD

DEFINES += UNITTESTBUNDLE_LIBRARY _UNIX

INCLUDEPATH += $$PWD/../_2RealFramework/kernel/src
DEPENDPATH += $$PWD/../_2RealFramework/kernel/src

QMAKE_CXXFLAGS += `pkg-config --cflags eigen3` -fPIC -std=c++11

unix:!macx: LIBS += -L$$PWD/../../../qt-solutions/qtpropertybrowser/lib/ -lQtSolutions_PropertyBrowser-head

INCLUDEPATH += $$PWD/../../../qt-solutions/qtpropertybrowser/src
DEPENDPATH += $$PWD/../../../qt-solutions/qtpropertybrowser/src
