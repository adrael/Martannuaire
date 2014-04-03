#ifndef ENGLISHDIRECTORY_HPP
#define ENGLISHDIRECTORY_HPP

#include "addwindow.hpp"

#include <QWidget>
#include <QCommandLinkButton>

class EnglishDirectory : public QWidget
{
    Q_OBJECT

public:
    EnglishDirectory(QWidget *parent = 0);
    ~EnglishDirectory();

    void showInPosition(bool fullScreen = false, int width = 800, int height = 600, int x = 0, int y = 0);

signals:

public slots:

private slots:
    void showPreviousPage();

    void showAddWindow();
    void showSearchWindow();
    void showConsultWindow();

private:
    AddWindow * addWindow;

    QCommandLinkButton * previousButton,
                       * addWindowButton,
                       * searchWindowButton,
                       * consultWindowButton;

};

#endif // ENGLISHDIRECTORY_HPP
