#include "englishdirectory.hpp"

#include "martannuaire.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QDebug>

EnglishDirectory::EnglishDirectory(QWidget *parent) :
    QWidget(parent, Qt::Window)
{
    addWindow = new AddWindow(this);

    previousButton = new QCommandLinkButton("Retour", this);
    previousButton->setIcon(QIcon("../resources/previous.png"));
    previousButton->setIconSize(QSize(32, 32));

    addWindowButton = new QCommandLinkButton("Ajouter un mot", "Ajouter un mot au Martannuaire d'Anglais", this);
    addWindowButton->setIcon(QIcon("../resources/add.png"));
    addWindowButton->setIconSize(QSize(32, 32));

    searchWindowButton = new QCommandLinkButton("Rechercher un mot", "Rechercher un mot dans le Martannuaire d'Anglais", this);
    searchWindowButton->setIcon(QIcon("../resources/search.png"));
    searchWindowButton->setIconSize(QSize(32, 32));

    consultWindowButton = new QCommandLinkButton("Consulter le Martannuaire d'Anglais", "Affiche les mots enregistrés dans le Martannuaire d'Anglais pour une consultation rapide", this);
    consultWindowButton->setIcon(QIcon("../resources/consult.png"));
    consultWindowButton->setIconSize(QSize(32, 32));

    QHBoxLayout * previousLayout = new QHBoxLayout();
    previousLayout->addWidget(previousButton);
    previousLayout->addStretch();

    QVBoxLayout * buttonsLayout = new QVBoxLayout();
    buttonsLayout->addWidget(addWindowButton);
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(searchWindowButton);
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(consultWindowButton);

    QHBoxLayout * fittingLayout = new QHBoxLayout();
    fittingLayout->addStretch();
    fittingLayout->addLayout(buttonsLayout);
    fittingLayout->addStretch();

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(previousLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(fittingLayout);
    mainLayout->addStretch();

    setWindowTitle("Martannuaire d'Anglais");
    setMinimumSize(800, 600);

    connect(previousButton, SIGNAL(clicked()), this, SLOT(showPreviousPage()));

    connect(addWindowButton, SIGNAL(clicked()), this, SLOT(showAddWindow()));
    connect(searchWindowButton, SIGNAL(clicked()), this, SLOT(showSearchWindow()));
    connect(consultWindowButton, SIGNAL(clicked()), this, SLOT(showConsultWindow()));
}

EnglishDirectory::~EnglishDirectory()
{

}

void EnglishDirectory::showInPosition(bool fullScreen, int width, int height, int x, int y)
{
    if(fullScreen) {
        showFullScreen();
        return;
    }

    resize(width, height);
    move(x, y);
    show();
}

void EnglishDirectory::showPreviousPage()
{
    dynamic_cast<Martannuaire *>(parentWidget())->showInPosition(isFullScreen(), width(), height(), x(), y());
    hide();
}

void EnglishDirectory::showAddWindow()
{
    hide();
    addWindow->showInPosition(isFullScreen(), width(), height(), x(), y());
}

void EnglishDirectory::showSearchWindow()
{

}

void EnglishDirectory::showConsultWindow()
{

}
