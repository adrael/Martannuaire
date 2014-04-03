#include "martannuaire.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Martannuaire martannuaire;
    martannuaire.show();

    return a.exec();
}
