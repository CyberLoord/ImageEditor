/********************************************************************************
** Form generated from reading UI file 'imageslist.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESLIST_H
#define UI_IMAGESLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imagesList
{
public:
    QLabel *picLabel;
    QTableView *tableView;
    QPushButton *backButton;
    QPushButton *openImageButton;
    QPushButton *deleteImageButton;

    void setupUi(QWidget *imagesList)
    {
        if (imagesList->objectName().isEmpty())
            imagesList->setObjectName("imagesList");
        imagesList->resize(836, 459);
        picLabel = new QLabel(imagesList);
        picLabel->setObjectName("picLabel");
        picLabel->setGeometry(QRect(320, 40, 500, 350));
        tableView = new QTableView(imagesList);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 60, 291, 301));
        backButton = new QPushButton(imagesList);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 10, 51, 32));
        openImageButton = new QPushButton(imagesList);
        openImageButton->setObjectName("openImageButton");
        openImageButton->setGeometry(QRect(710, 400, 100, 32));
        deleteImageButton = new QPushButton(imagesList);
        deleteImageButton->setObjectName("deleteImageButton");
        deleteImageButton->setGeometry(QRect(590, 400, 100, 32));

        retranslateUi(imagesList);

        QMetaObject::connectSlotsByName(imagesList);
    } // setupUi

    void retranslateUi(QWidget *imagesList)
    {
        imagesList->setWindowTitle(QCoreApplication::translate("imagesList", "Form", nullptr));
        picLabel->setText(QString());
        backButton->setText(QCoreApplication::translate("imagesList", "Back", nullptr));
        openImageButton->setText(QCoreApplication::translate("imagesList", "Open Image", nullptr));
        deleteImageButton->setText(QCoreApplication::translate("imagesList", "Delete Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imagesList: public Ui_imagesList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESLIST_H
