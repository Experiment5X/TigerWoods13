#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), m_userFile(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Find your 13-User-XXX file");
        if (filePath.length() == 0)
            return;

        // parse the user file
        std::shared_ptr<FileIO> userFileIO = std::make_shared<FileIO>(filePath.toStdString());
        m_userFile = new TigerWoodsUserFile(userFileIO, this);

        // update the GUI
        setWindowTitle(m_userFile->name() + "'s User Info");
        ui->spnXpEarned->setValue(m_userFile->xpEarned());
        ui->spnXpSpent->setValue(m_userFile->xpSpent());
        ui->spnXpBalance->setValue(m_userFile->xpEarned() - m_userFile->xpSpent());
        ui->spnDoubleEagles->setValue(m_userFile->doubleEagles());
        ui->spnEagles->setValue(m_userFile->eagles());
        ui->spnBirdies->setValue(m_userFile->birdies());
        ui->spnPars->setValue(m_userFile->pars());
        ui->spnBogeys->setValue(m_userFile->bogeys());
        ui->spnDoubleBogeys->setValue(m_userFile->doubleBogeys());
    }
    catch (std::string s)
    {
        QMessageBox::critical(this, "Error", QString("An error occurred while reading the user file.\n") + QString::fromStdString(s));
    }
}
