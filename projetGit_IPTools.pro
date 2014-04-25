CONFIG += console

win32:INCLUDEPATH += \
    "C:\opencvInstall\include" \

win32:LIBS += \
    -LC:/opencvInstall/lib/ -lopencv_core244 -lopencv_imgproc244 -lopencv_highgui244 -lopencv_video244

SOURCES += \
    main.cpp \
    Processing/processing.cpp \
    Processing/Smoothing/smoothing.cpp \
    Processing/Smoothing/butterworth.cpp \
    dft_algo.cpp

OTHER_FILES += \
    Notes.txt \
    Notes.txt

HEADERS += \
    Processing/processing.h \
    Processing/Smoothing/smoothing.h \
    Processing/Smoothing/butterworth.h \
    dft_algo.h
