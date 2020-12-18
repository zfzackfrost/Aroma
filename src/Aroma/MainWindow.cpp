#include <Aroma/MainWindow.hpp>

#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QTextStream>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initMenuBar();
    initStatusBar();
    initWidgets();

    setWindowTitle(tr("Aroma"));
    setWindowState(Qt::WindowState::WindowMaximized);
}

MainWindow::~MainWindow()
{
}


void MainWindow::initWidgets()
{
    QString panelStyle;
    {
        auto pal = qApp->palette();
        auto c = pal.window().color().lighter(130);
        QTextStream out(&panelStyle);
        out << "background-color: rgba(";
        out << c.red() << "," << c.green() << "," << c.blue() << "," << c.alpha();
        out << ");";
    }
    
    m_splitter = new QSplitter(this);

    m_listPanel = new QWidget(m_splitter);
    m_listPanel->setMinimumWidth(50);
    m_listPanel->setStyleSheet(panelStyle);
    m_plotPanel = new QWidget(m_splitter);
    m_plotPanel->setStyleSheet(panelStyle);

    m_splitter->setOrientation(Qt::Horizontal);
    m_splitter->addWidget(m_listPanel);
    m_splitter->addWidget(m_plotPanel);
    setCentralWidget(m_splitter);

}


void MainWindow::initMenuBar()
{
    auto fileMenu = menuBar()->addMenu(tr("File"));
    auto spiceMenu = menuBar()->addMenu(tr("SPICE"));
    auto viewMenu = menuBar()->addMenu(tr("View"));

    auto openAction = fileMenu->addAction(QIcon(":/icons/folder-open-solid.png"), tr("Open Plots"));

    fileMenu->addSeparator();

    auto quitAction = fileMenu->addAction(QIcon(":/icons/times-solid.png"), tr("Quit"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    auto confSimction = spiceMenu->addAction(QIcon(":/icons/cog-solid.png"), tr("Configure"));
    auto runSimAction = spiceMenu->addAction(QIcon(":/icons/lightbulb-solid.png"),tr("Run"));

    auto autoFitXAction = viewMenu->addAction(QIcon(":/icons/arrows-alt-h-solid.png"), tr("Auto Fit X"));
    auto autoFitYAction = viewMenu->addAction(QIcon(":/icons/arrows-alt-v-solid.png"), tr("Auto Fit Y"));
    viewMenu->addSeparator();
    auto setScaleAction = viewMenu->addAction(tr("Set X/Y Scale"));
}

void MainWindow::initStatusBar() 
{
    statusBar()->showMessage(tr("Ready"));
}