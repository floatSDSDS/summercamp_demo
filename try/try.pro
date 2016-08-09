TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include \
                /usr/include/opencv \
                /usr/include/opencv2

LIBS += /usr/lib/x86_64-linux-gnu/libopencv_highgui.so \
        /usr/lib/x86_64-linux-gnu/libopencv_core.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so \
        /usr/lib/x86_64-linux-gnu/libopencv_ts.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_ocl.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_gpu.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_flann.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_photo.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_video.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_legacy.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_ml.so    \
        /usr/lib/jni/libopencv_java248.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_contrib.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_superres.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_stitching.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_features2d.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so    \
        /usr/lib/x86_64-linux-gnu/libopencv_videostab.so

SOURCES += main.cpp

