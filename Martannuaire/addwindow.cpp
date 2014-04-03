#include "addwindow.hpp"

#include "englishdirectory.hpp"

#include <QDebug>

AddWindow::AddWindow(QWidget *parent) :
    QWidget(parent, Qt::Window)
{
    currentHighlightColor = "yellow";

    QHBoxLayout * compilingLayout = new QHBoxLayout();
    compilingLayout->addStretch();
    compilingLayout->addLayout(setUpEditorButtons());
    compilingLayout->addLayout(setUpWordFields());
    compilingLayout->addLayout(setUpUtilsButtons());
    compilingLayout->addStretch();

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(setUpPreviousButton());
    mainLayout->addStretch();
    mainLayout->addLayout(compilingLayout);
    mainLayout->addStretch();

    setWindowTitle("Martannuaire d'Anglais - Ajouter");
    setMinimumSize(800, 600);
}

AddWindow::~AddWindow()
{

}

void AddWindow::showInPosition(bool fullScreen, int width, int height, int x, int y)
{
    if(fullScreen) {
        showFullScreen();
        return;
    }

    resize(width, height);
    move(x, y);
    show();
}

void AddWindow::showPreviousPage()
{
    dynamic_cast<EnglishDirectory *>(parentWidget())->showInPosition(isFullScreen(), width(), height(), x(), y());
    hide();
}

QVBoxLayout * AddWindow::setUpWordFields()
{
    wordTitle = new QLineEdit("Mot", this);
    wordTitle->setMinimumWidth(500);
    wordTitle->setMinimumHeight(40);

    wordDescription = new QTextEdit("Description", this);
    wordDescription->setMinimumWidth(600);
    wordDescription->setMinimumHeight(400);

    QVBoxLayout * fieldsLayout = new QVBoxLayout();
    fieldsLayout->addWidget(wordTitle);
    fieldsLayout->addWidget(wordDescription);

    return fieldsLayout;
}

QVBoxLayout * AddWindow::setUpUtilsButtons()
{
    addWordButton = new QPushButton(QIcon("../resources/add.png"), "Ajouter", this);
    cancelButton = new QPushButton(QIcon("../resources/delete.png"), "Annuler", this);

    QVBoxLayout * buttonsLayout = new QVBoxLayout();
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(addWordButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addStretch();

    return buttonsLayout;
}

QVBoxLayout * AddWindow::setUpEditorButtons()
{
    sizeButton = new QPushButton(this);
    sizeButton->setFixedSize(32, 32);
    sizeButton->setCursor(QCursor(Qt::PointingHandCursor));
    sizeButton->setStyleSheet(getFormattedStyleSheet("size.png", "size_hover.png", "size_pressed.png"));

    boldButton = new QPushButton(this);
    boldButton->setFixedSize(32, 32);
    boldButton->setCursor(QCursor(Qt::PointingHandCursor));
    boldButton->setStyleSheet(getFormattedStyleSheet("bold.png", "bold_hover.png", "bold_pressed.png"));

    colorButton = new QPushButton(this);
    colorButton->setFixedSize(32, 32);
    sizeButton->setCursor(QCursor(Qt::PointingHandCursor));
    colorButton->setStyleSheet(getFormattedStyleSheet("text.png", "text_hover.png", "text_pressed.png"));

    italicButton = new QPushButton(this);
    italicButton->setFixedSize(32, 32);
    italicButton->setCursor(QCursor(Qt::PointingHandCursor));
    italicButton->setStyleSheet(getFormattedStyleSheet("italic.png", "italic_hover.png", "italic_pressed.png"));

    highlightButton = new QPushButton(this);
    highlightButton->setFixedSize(32, 32);
    highlightButton->setCursor(QCursor(Qt::PointingHandCursor));
    highlightButton->setStyleSheet(getFormattedStyleSheet("highlight.png", "highlight_hover.png", "highlight_pressed.png"));

    highlightColorButton = new QPushButton(this);
    highlightColorButton->setFixedSize(16, 16);
    highlightColorButton->setCursor(QCursor(Qt::PointingHandCursor));
    highlightColorButton->setStyleSheet("QPushButton { background: yellow; border: 1px solid black; }");

    underlineButton = new QPushButton(this);
    underlineButton->setFixedSize(32, 32);
    underlineButton->setCursor(QCursor(Qt::PointingHandCursor));
    underlineButton->setStyleSheet(getFormattedStyleSheet("underline.png", "underline_hover.png", "underline_pressed.png"));

    highlightColorDialog = new QColorDialog(QColor(Qt::yellow), this);

    QHBoxLayout * highlightLayout = new QHBoxLayout();
    highlightLayout->addStretch();
    highlightLayout->addWidget(highlightColorButton);
    highlightLayout->addWidget(highlightButton);

    QVBoxLayout * editorsButtonLayout = new QVBoxLayout();
    editorsButtonLayout->addWidget(boldButton);
    editorsButtonLayout->addWidget(italicButton);
    editorsButtonLayout->addWidget(underlineButton);
    editorsButtonLayout->addWidget(sizeButton);
    editorsButtonLayout->addWidget(colorButton);

    QHBoxLayout * fittingLayout = new QHBoxLayout();
    fittingLayout->addStretch();
    fittingLayout->addLayout(editorsButtonLayout);

    QVBoxLayout * finalLayout = new QVBoxLayout();
    finalLayout->addStretch();
    finalLayout->addLayout(fittingLayout);
    finalLayout->addLayout(highlightLayout);
    finalLayout->addStretch();

    connect(highlightColorButton, SIGNAL(clicked()), highlightColorDialog, SLOT(open()));
    connect(highlightColorDialog, SIGNAL(colorSelected(const QColor &)), this, SLOT(highlightColorChanged(const QColor &)));

    return finalLayout;
}

void AddWindow::highlightColorChanged(const QColor & color)
{
    currentHighlightColor = color.name();
    highlightColorButton->setStyleSheet(QString("QPushButton { background: ") + color.name() + QString("; border: 1px solid black; }"));
}

QHBoxLayout * AddWindow::setUpPreviousButton()
{
    previousButton = new QCommandLinkButton("Retour", this);
    previousButton->setIcon(QIcon("../resources/previous.png"));
    previousButton->setIconSize(QSize(32, 32));

    connect(previousButton, SIGNAL(clicked()), this, SLOT(showPreviousPage()));

    QHBoxLayout * previousLayout = new QHBoxLayout();
    previousLayout->addWidget(previousButton);
    previousLayout->addStretch();

    return previousLayout;
}

QString AddWindow::getFormattedStyleSheet(QString normal, QString hover, QString pressed)
{
    QString path("../resources/");

    return QString("QPushButton { border-image: url(" + path + normal + "); border: none; }") +
           QString("QPushButton:hover { border-image: url(" + path + hover + "); }") +
           QString("QPushButton:pressed { border-image: url(" + path + pressed + "); }");
}
