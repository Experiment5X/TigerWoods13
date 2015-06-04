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

    void on_sldrPower_valueChanged(int value);

    void on_sldrAccuracy_valueChanged(int value);

    void on_sldrWorkability_valueChanged(int value);

    void on_sldrSpin_valueChanged(int value);

    void on_sldrRecovery_valueChanged(int value);

    void on_sldrPutting_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    TigerWoodsUserFile *m_userFile;
    TigerWoodsProgressFile *m_progressFile;

    template <typename T>
    static void setWidgetsEnabled(QWidget *parent, bool enabled, QString regex)
    {
        QList<T> widgets = parent->findChildren<T>(QRegularExpression(regex));
        for (auto widget : widgets)
            widget->setEnabled(enabled);
    }
};

#endif // MAINWINDOW_H
