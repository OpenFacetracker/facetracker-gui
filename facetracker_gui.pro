#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T14:06:43
#
#-------------------------------------------------

QT       += core gui\
            opengl\

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = facetracker_gui
TEMPLATE = app

INCLUDEPATH += C:\opencv\build\include

SOURCES += main.cpp\
        mainwindow.cpp \
    Camera/recognition/ft_recognise.cpp \
    Camera/ft_detect.cpp \
    Camera/ft_draw.cpp \
    Console/ft_console.cpp \
    DB/ft_db.cpp \
    Utils/ft_config.cpp \
    Utils/ft_log.cpp \
    Utils/ft_main.cpp \
    Utils/ft_parser.cpp \
    Utils/ft_secure.cpp \
    Utils/ft_utils.cpp \
    start.cpp \
    loader.cpp \
    chose_camera.cpp

HEADERS  += mainwindow.h \
    Header/color.h \
    Header/ft.h \
    Header/ft_draw.h \
    Header/ft_recognise.h \
    Header/Image.h \
    Header/secure.h \
    Header/XmlParsing.h \
    start.h \
    loader.h \
    chose_camera.h

FORMS    += mainwindow.ui \
    start.ui \
    loader.ui \
    chose_camera.ui \
    addperson.ui

RESOURCES  = application.qrc

LIBS += `pkg-config --cflags --libs opencv`

DISTFILES += \
    icones/general/add.png \
    icones/general/address_book.png \
    icones/general/admin_female.png \
    icones/general/arrow_down.png \
    icones/general/arrow_left.png \
    icones/general/arrow_right.png \
    icones/general/arrow_up.png \
    icones/general/attachment.png \
    icones/general/attachment2.png \
    icones/general/backup.png \
    icones/general/binoculars.png \
    icones/general/book.png \
    icones/general/briefcase.png \
    icones/general/calculators_buttons.png \
    icones/general/calendar.png \
    icones/general/camera.png \
    icones/general/cancel.png \
    icones/general/chat_emoticon.png \
    icones/general/chat_exclamation.png \
    icones/general/checkmark.png \
    icones/general/clipboard.png \
    icones/general/clock.png \
    icones/general/close.png \
    icones/general/copy2.png \
    icones/general/diary.png \
    icones/general/diskette.png \
    icones/general/document.png \
    icones/general/door.png \
    icones/general/down.png \
    icones/general/download.png \
    icones/general/envelope.png \
    icones/general/envelope_open.png \
    icones/general/file.png \
    icones/general/folder_open.png \
    icones/general/folder2.png \
    icones/general/game_card_clubs.png \
    icones/general/game_card_diamonds.png \
    icones/general/game_card_hearts.png \
    icones/general/game_card_spades.png \
    icones/general/games_control.png \
    icones/general/group.png \
    icones/general/hand_point.png \
    icones/general/hand_share.png \
    icones/general/history2.png \
    icones/general/home.png \
    icones/general/hourglass.png \
    icones/general/left.png \
    icones/general/ligthbulb_off.png \
    icones/general/ligthbulb_on.png \
    icones/general/list.png \
    icones/general/lock.png \
    icones/general/lock_open.png \
    icones/general/management.png \
    icones/general/microphone.png \
    icones/general/monitor.png \
    icones/general/music_beamed_note.png \
    icones/general/music_eight_note.png \
    icones/general/music_library.png \
    icones/general/network.png \
    icones/general/next.png \
    icones/general/notepad.png \
    icones/general/paste.png \
    icones/general/phone.png \
    icones/general/phone_book.png \
    icones/general/preview.png \
    icones/general/previous.png \
    icones/general/printer.png \
    icones/general/pyramid.png \
    icones/general/refresh.png \
    icones/general/reload.png \
    icones/general/right.png \
    icones/general/round.png \
    icones/general/scissors.png \
    icones/general/speech_bubble.png \
    icones/general/star.png \
    icones/general/stats_pie_chart.png \
    icones/general/technical_hammer.png \
    icones/general/technical_screwdriver.png \
    icones/general/technical_wrench.png \
    icones/general/traffic_lights.png \
    icones/general/trash_can.png \
    icones/general/up.png \
    icones/general/upload.png \
    icones/general/user.png \
    icones/general/user_awake.png \
    icones/general/user_girl.png \
    icones/general/user_sleep.png \
    icones/general/windows.png \
    icones/general/wizard.png \
    icones/general/world.png \
    icones/general/zoom.png \
    icones/general/zoom_in.png \
    icones/general/zoom_out.png
