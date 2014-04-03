#include "martannuaire.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QDebug>

Martannuaire::Martannuaire(QWidget *parent)
    : QMainWindow(parent)
{
    englishDirectory = new EnglishDirectory(this);

    englishButton = new QCommandLinkButton("Martannuaire d'Anglais", "Accéder à l'annuaire d'Anglais. Mémoriser et apprendre l'anglais n'a jamais été aussi simple !", this);
    englishButton->setIcon(QIcon("../resources/next.png"));
    englishButton->setIconSize(QSize(32, 32));

    anthropologyButton = new QCommandLinkButton("Martannuaire d'Anthropologie", "Accéder à l'annuaire d'Anthropologie. Maintenir ses connaissances à jour, fait ! En cours de construction", this);
    anthropologyButton->setEnabled(false);
    anthropologyButton->setIcon(QIcon("../resources/next.png"));
    anthropologyButton->setIconSize(QSize(32, 32));

    QWidget * mainWidget = new QWidget(this);

    QVBoxLayout * fittingLayout = new QVBoxLayout();
    fittingLayout->addStretch();
    fittingLayout->addWidget(englishButton);
    fittingLayout->addWidget(anthropologyButton);
    fittingLayout->addStretch();

    QHBoxLayout * mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->addStretch();
    mainLayout->addLayout(fittingLayout);
    mainLayout->addStretch();

    mainWidget->setLayout(mainLayout);

    setWindowTitle("Martannuaires");
    setCentralWidget(mainWidget);
    setMinimumSize(800, 600);
    resize(800, 600);

    connect(englishButton, SIGNAL(clicked()), this, SLOT(showEnglishDirectory()));
}

Martannuaire::~Martannuaire()
{

}

void Martannuaire::showInPosition(bool fullScreen, int width, int height, int x, int y)
{
    if(fullScreen) {
        showFullScreen();
        return;
    }

    resize(width, height);
    move(x, y);
    show();
}

void Martannuaire::showDirectory(QString directory)
{
    hide();

    if(directory == "ENGLISH") {
        englishDirectory->showInPosition(isFullScreen(), width(), height(), x(), y());
    } else if(directory == "ANTHROPOLOGY") {
        return;
    }
}

void Martannuaire::showEnglishDirectory()
{
    showDirectory("ENGLISH");
}
