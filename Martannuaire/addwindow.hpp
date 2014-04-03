#ifndef ADDWINDOW_HPP
#define ADDWINDOW_HPP

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QCommandLinkButton>

class AddWindow : public QWidget
{
    Q_OBJECT

public:
    AddWindow(QWidget *parent = 0);
    ~AddWindow();

    void showInPosition(bool fullScreen = false, int width = 800, int height = 600, int x = 0, int y = 0);

signals:

public slots:

private slots:
    void showPreviousPage();
    void highlightColorChanged(const QColor & color);

private:
    QString getFormattedStyleSheet(QString normal, QString hover, QString pressed);

    QString currentHighlightColor;

    QVBoxLayout * setUpWordFields();
    QVBoxLayout * setUpUtilsButtons();
    QVBoxLayout * setUpEditorButtons();
    QHBoxLayout * setUpPreviousButton();

    QLineEdit * wordTitle;
    QTextEdit * wordDescription;
    QPushButton * addWordButton,
                * cancelButton,
                * highlightButton,
                * highlightColorButton,
                * boldButton,
                * italicButton,
                * colorButton,
                * underlineButton,
                * sizeButton;

    QColorDialog * highlightColorDialog;
    QCommandLinkButton * previousButton;

};

#endif // ADDWINDOW_HPP
