#ifndef MARTANNUAIRE_HPP
#define MARTANNUAIRE_HPP

#include "englishdirectory.hpp"

#include <QMainWindow>
#include <QCommandLinkButton>

class Martannuaire : public QMainWindow
{
    Q_OBJECT

public:
    Martannuaire(QWidget *parent = 0);
    ~Martannuaire();

    void showInPosition(bool fullScreen = false, int width = 800, int height = 600, int x = 0, int y = 0);

private slots:
    void showEnglishDirectory();
    void showDirectory(QString directory);

private:
    EnglishDirectory * englishDirectory;

    QCommandLinkButton * englishButton,
                       * anthropologyButton;
};

#endif // MARTANNUAIRE_HPP
