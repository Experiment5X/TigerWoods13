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

void MainWindow::on_sldrPower_valueChanged(int value)
{
    ui->lblPower->setText(QString::number(value));
}

void MainWindow::on_sldrAccuracy_valueChanged(int value)
{
    ui->lblAccuracy->setText(QString::number(value));
}
void MainWindow::on_sldrWorkability_valueChanged(int value)
{
    ui->lblWorkability->setText(QString::number(value));
}

void MainWindow::on_sldrSpin_valueChanged(int value)
{
    ui->lblSpin->setText(QString::number(value));
}

void MainWindow::on_sldrRecovery_valueChanged(int value)
{
    ui->lblRecovery->setText(QString::number(value));
}

void MainWindow::on_sldrPutting_valueChanged(int value)
{
    ui->lblPutting->setText(QString::number(value));
}

void MainWindow::on_actionOpen_2_triggered()
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
        ui->spnXpEarned->setValue(m_userFile->xpEarned());
        ui->spnXpSpent->setValue(m_userFile->xpSpent());
        ui->spnXpBalance->setValue(m_userFile->xpEarned() - m_userFile->xpSpent());
        ui->sldrPower->setValue(m_userFile->power());
        ui->sldrAccuracy->setValue(m_userFile->accuracy());
        ui->sldrWorkability->setValue(m_userFile->workability());
        ui->sldrSpin->setValue(m_userFile->spin());
        ui->sldrRecovery->setValue(m_userFile->recovery());
        ui->sldrPutting->setValue(m_userFile->putting());
        ui->spnRoundsPlayed->setValue(m_userFile->roundsPlayed());
        ui->spnTotalScore->setValue(m_userFile->totalScore());
        ui->spnAverageScore->setValue(m_userFile->averageScore());
        ui->spnPuttsMade->setValue(m_userFile->madePutts());
        ui->spnPuttsTotal->setValue(m_userFile->totalPutts());
        ui->spnTotalDrives->setValue(m_userFile->totalDrives());
        ui->spnTotalYardsDriven->setValue(m_userFile->totalYardsDriven());
        ui->spnFIROpportunities->setValue(m_userFile->totalFIRAttempts());
        ui->spnFIRs->setValue(m_userFile->totalFIRs());
        ui->spnGIROpportunities->setValue(m_userFile->totalGIRAttempts());
        ui->spnGIRs->setValue(m_userFile->totalGIRs());
        ui->spnLongestDrive->setValue(m_userFile->longestDrive());
        ui->spnLongestPutt->setValue(m_userFile->longestPutt());
        ui->spnHolesInOne->setValue(m_userFile->holesInOne());
        ui->spnDoubleEagles->setValue(m_userFile->doubleEagles());
        ui->spnEagles->setValue(m_userFile->eagles());
        ui->spnBirdies->setValue(m_userFile->birdies());
        ui->spnPars->setValue(m_userFile->pars());
        ui->spnBogeys->setValue(m_userFile->bogeys());
        ui->spnDoubleBogeys->setValue(m_userFile->doubleBogeys());

        // enable the GUI elements
        setWidgetsEnabled<QSpinBox*>(ui->tabUser, true, "spn.+");
        setWidgetsEnabled<QDoubleSpinBox*>(ui->tabUser, true, "spn.+");
        setWidgetsEnabled<QSlider*>(ui->tabUser, true, "sldr.+");

        // display the user file tab
        ui->tabWidget->setCurrentIndex(0);

        ui->statusBar->showMessage("Loaded user file", 5000);

    }
    catch (std::string s)
    {
        QMessageBox::critical(this, "Error", QString("An error occurred while reading the user file.\n") + QString::fromStdString(s));
    }
}

void MainWindow::on_actionOpen_3_triggered()
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
        ui->tabWidget->setCurrentIndex(1);

        ui->statusBar->showMessage("Loaded progress file", 5000);
    }
    catch (std::string s)
    {
        QMessageBox::critical(this, "Error", QString("An error occurred while reading the progress file.\n") + QString::fromStdString(s));
    }
}

void MainWindow::on_actionClose_triggered()
{
    // free all the progress file resources
    delete m_progressFile;
    m_progressFile = nullptr;

    // remove all items from the tree widget and disable it
    while (ui->treeLegacyChallenges->topLevelItemCount() > 0)
        delete ui->treeLegacyChallenges->takeTopLevelItem(0);
    ui->treeLegacyChallenges->setEnabled(false);
}

void MainWindow::on_actionClose_2_triggered()
{
    delete m_userFile;
    m_userFile = nullptr;

    // reset all the widgets
    QList<QSpinBox*> spinboxes = ui->tabUser->findChildren<QSpinBox*>(QRegularExpression("spn.+"));
    for (QSpinBox *box : spinboxes)
        box->setValue(0);

    QList<QSlider*> sliders = ui->tabUser->findChildren<QSlider*>(QRegularExpression("sldr.+"));
    for (QSlider *slider : sliders)
        slider->setValue(35);
    ui->spnAverageScore->setValue(0);

    // disable all the widgets
    setWidgetsEnabled<QSpinBox*>(ui->tabUser, false, "spn.+");
    setWidgetsEnabled<QDoubleSpinBox*>(ui->tabUser, false, "spn.+");
    setWidgetsEnabled<QSlider*>(ui->tabUser, false, "sldr.+");
}
