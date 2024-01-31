#include "mainwindow.h"

#include <QApplication>

#include <QFile>
#include <QDir>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir::setCurrent(a.applicationDirPath());


    QFile styleFile(":/coffee.qss"); //https://github.com/openwebos/qt/blob/master/examples/widgets/stylesheet/qss/coffee.qss
    //QFile styleFile(":/stylesheet.qss"); // https://github.com/All4Gis/Load-QSS/blob/master/examples/Light%20Blue%20(FreeCAD)/stylesheet.qss
    //QFile styleFile(":/flex_ui_stylesheet.qss"); // https://forum.qt.io/topic/101773/how-to-add-qrc-and-qss-files-into-cmake
        // https://stackoverflow.com/questions/12438095/qt-vertical-scroll-bar-stylesheets

    if (styleFile.open(QIODevice::ReadOnly))    // https://forum.qt.io/topic/93613/stylesheet-for-scrollbar-in-qscrollarea
    {
        QTextStream textStream(&styleFile);
        QString styleSheet = textStream.readAll();
        styleFile.close();
        qApp->setStyleSheet(styleSheet);
    }


    MainWindow w;
    w.show();
    return a.exec();
}
