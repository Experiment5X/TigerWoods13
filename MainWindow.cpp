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
        ui->spnLongestDrive->setValue(m_userFile->longestDrive());
        ui->spnLongestPutt->setValue(m_userFile->longestPutt());
        ui->spnDoubleEagles->setValue(m_userFile->doubleEagles());
        ui->spnEagles->setValue(m_userFile->eagles());
        ui->spnBirdies->setValue(m_userFile->birdies());
        ui->spnPars->setValue(m_userFile->pars());
        ui->spnBogeys->setValue(m_userFile->bogeys());
        ui->spnDoubleBogeys->setValue(m_userFile->doubleBogeys());

        // enable the GUI elements
        ui->spnXpEarned->setEnabled(true);
        ui->spnXpSpent->setEnabled(true);
        ui->spnXpBalance->setEnabled(true);
        ui->spnLongestDrive->setEnabled(true);
        ui->spnLongestPutt->setEnabled(true);
        ui->spnDoubleEagles->setEnabled(true);
        ui->spnEagles->setEnabled(true);
        ui->spnBirdies->setEnabled(true);
        ui->spnPars->setEnabled(true);
        ui->spnBogeys->setEnabled(true);
        ui->spnDoubleBogeys->setEnabled(true);
        ui->tabWidget->setEnabled(true);
        ui->tabWidget->setCurrentIndex(0);

    }
    catch (std::string s)
    {
        QMessageBox::critical(this, "Error", QString("An error occurred while reading the user file.\n") + QString::fromStdString(s));
    }
}

void MainWindow::on_actionOpen_Progress_File_triggered()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Find your 13-Progress file");
        if (filePath.length() == 0)
            return;

        // parse the user file
        std::shared_ptr<FileIO> userFileIO = std::make_shared<FileIO>(filePath.toStdString());
        m_progressFile = new TigerWoodsProgressFile(userFileIO, this);

        // populate the tree widget with the legacy progress
        QString prevChallengeSection = "";
        QTreeWidgetItem *curSectionItem = nullptr;
        for (TigerWoodsTigerLegacyChallenge *challenge : m_progressFile->legacyChallenges())
        {
            // check to see if we need to create another section item
            if (challenge->section() != prevChallengeSection)
            {
                prevChallengeSection = challenge->section();

                // create a tree widget item for the legacy challenge section
                curSectionItem = new QTreeWidgetItem(ui->treeLegacyChallenges);
                curSectionItem->setText(0, challenge->section());
                curSectionItem->setExpanded(true);
                ui->treeLegacyChallenges->addTopLevelItem(curSectionItem);
            }

            // create a tree widget item for the challenge
            QTreeWidgetItem *challengeItem = new QTreeWidgetItem(curSectionItem);
            challengeItem->setText(0, challenge->name());
            challengeItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);

            // the item should be checked if the challenge is fully completed
            Qt::CheckState checkState = (challenge->fullyComplete()) ? Qt::Checked : Qt::Unchecked;
            challengeItem->setCheckState(0, checkState);
        }

        // enable the necessary widgets
        ui->treeLegacyChallenges->setEnabled(true);
        ui->tabWidget->setEnabled(true);
        ui->tabWidget->setCurrentIndex(1);
    }
    catch (std::string s)
    {
        QMessageBox::critical(this, "Error", QString("An error occurred while reading the progress file.\n") + QString::fromStdString(s));
    }
}
