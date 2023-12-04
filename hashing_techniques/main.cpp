#include <QApplication>

#include "forms/mainwindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setOrganizationName("eoanermine");
    QApplication::setApplicationName("passwords_strength");

    MainWindowForm mainWindow;
    mainWindow.show();
    return QApplication::exec();
}