#pragma once

#include <QMainWindow>
#include <QSplitter>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void initWidgets();
    void initMenuBar();
    void initStatusBar();

    QWidget* m_listPanel;
    QWidget* m_plotPanel;
    QSplitter* m_splitter;
};
