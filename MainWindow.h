#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <memory>

#include "IO/FileIO.h"
#include "IO/BaseIO.h"
#include "TigerWoodsUserFile.h"
#include "TigerWoodsProgressFile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionOpen_Progress_File_triggered();

private:
    Ui::MainWindow *ui;
    TigerWoodsUserFile *m_userFile;
    TigerWoodsProgressFile *m_progressFile;
};

#endif // MAINWINDOW_H
