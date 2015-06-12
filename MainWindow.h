#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDoubleSpinBox>
#include <memory>

#include "IO/FileIO.h"
#include "IO/BaseIO.h"
#include "TigerWoods13/UserFile.h"
#include "TigerWoods13/ProgressFile.h"
#include "TigerWoods13/TournamentFile.h"

#include "QTreeWidgetItemSorted.h"

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
    void on_sldrPower_valueChanged(int value);

    void on_sldrAccuracy_valueChanged(int value);

    void on_sldrWorkability_valueChanged(int value);

    void on_sldrSpin_valueChanged(int value);

    void on_sldrRecovery_valueChanged(int value);

    void on_sldrPutting_valueChanged(int value);

    void on_actionOpen_2_triggered();

    void on_actionOpen_3_triggered();

    void on_actionClose_triggered();

    void on_actionClose_2_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    TigerWoods13::UserFile *m_userFile;
    TigerWoods13::ProgressFile *m_progressFile;
    TigerWoods13::TournamentFile *m_tournamentFile;

    template <typename T>
    static void setWidgetsEnabled(QWidget *parent, bool enabled, QString regex)
    {
        QList<T> widgets = parent->findChildren<T>(QRegularExpression(regex));
        for (auto widget : widgets)
            widget->setEnabled(enabled);
    }
};

#endif // MAINWINDOW_H
