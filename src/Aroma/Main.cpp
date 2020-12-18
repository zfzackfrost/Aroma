#include <Aroma/MainWindow.hpp>

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleFile(":/styles/App.qss");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString stylesheet = styleFile.readAll();
        styleFile.close();
        a.setStyleSheet(stylesheet);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
