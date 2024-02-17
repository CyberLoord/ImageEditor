#include "imageslist.h"
#include "ui_imageslist.h"

imagesList::imagesList(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::imagesList)
{
    ui->setupUi(this);
    setWindowTitle("Images List");

    db = new dataBase();

    db->connectToDB();
    this->setupModel("ImagesTable",
                     QStringList() << QString("id")
                                   << QString("FileName")
                                   << QString("Image")
    );

    this->createUI();
}

imagesList::~imagesList()
{
    delete ui;
}

void imagesList::saveImageToDB(QPixmap inPixmap)
{
    QByteArray inByteArray;
    QBuffer inBuffer(&inByteArray);

    inBuffer.open(QIODevice::WriteOnly);
    inPixmap.save(&inBuffer, "PNG");
    db->insertIntoTable(QDateTime::currentDateTime().toString("dd.MM.yyyy_hh:mm:ss.png"), inByteArray);
    model->select();
}

void imagesList::setupModel(const QString &tablename, const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tablename);

    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
}

void imagesList::createUI()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(slotCurrentImage(QModelIndex)));

    model->select();
}

void imagesList::slotCurrentImage(QModelIndex index)
{
    dedicatedImage.loadFromData(model->data(model->index(index.row(), 2)).toByteArray());
    ui->picLabel->setPixmap(dedicatedImage.scaled(500, 350));
}

void imagesList::closeWindow()
{
    this->close();
}

void imagesList::on_backButton_clicked()
{
    closeWindow();
}

void imagesList::on_openImageButton_clicked()
{
    closeWindow();
    emit signalOpenImage(dedicatedImage);
}

void imagesList::on_deleteImageButton_clicked()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("Delete Image"));
    msgBox.setText(tr("Do you want to delete image from database?"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setIcon(QMessageBox::Question);

    int answer = msgBox.exec();

    if (answer == QMessageBox::Yes) {
        QSqlRecord record;
        int i = ui->tableView->currentIndex().row();
        record = model->record(i);
        db->removeImage(record.value("id").toInt());
        ui->tableView->reset();
        model->select();
        ui->picLabel->clear();
    }
}
