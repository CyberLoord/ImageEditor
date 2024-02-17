/********************************************************************************
** Form generated from reading UI file 'camerawindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWINDOW_H
#define UI_CAMERAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <camviewer.h>

QT_BEGIN_NAMESPACE

class Ui_cameraWindow
{
public:
    QPushButton *recordButton;
    camViewer *cam;
    QPushButton *closeWindowButton;
    QPushButton *openImageButton;
    QPushButton *applyFilterButton;

    void setupUi(QWidget *cameraWindow)
    {
        if (cameraWindow->objectName().isEmpty())
            cameraWindow->setObjectName("cameraWindow");
        cameraWindow->resize(851, 538);
        recordButton = new QPushButton(cameraWindow);
        recordButton->setObjectName("recordButton");
        recordButton->setGeometry(QRect(110, 430, 100, 32));
        cam = new camViewer(cameraWindow);
        cam->setObjectName("cam");
        cam->setGeometry(QRect(80, 60, 631, 351));
        closeWindowButton = new QPushButton(cameraWindow);
        closeWindowButton->setObjectName("closeWindowButton");
        closeWindowButton->setGeometry(QRect(20, 10, 51, 32));
        openImageButton = new QPushButton(cameraWindow);
        openImageButton->setObjectName("openImageButton");
        openImageButton->setGeometry(QRect(580, 430, 100, 32));
        applyFilterButton = new QPushButton(cameraWindow);
        applyFilterButton->setObjectName("applyFilterButton");
        applyFilterButton->setGeometry(QRect(740, 50, 100, 32));

        retranslateUi(cameraWindow);

        QMetaObject::connectSlotsByName(cameraWindow);
    } // setupUi

    void retranslateUi(QWidget *cameraWindow)
    {
        cameraWindow->setWindowTitle(QCoreApplication::translate("cameraWindow", "Form", nullptr));
        recordButton->setText(QCoreApplication::translate("cameraWindow", "Start", nullptr));
        closeWindowButton->setText(QCoreApplication::translate("cameraWindow", "Back", nullptr));
        openImageButton->setText(QCoreApplication::translate("cameraWindow", "Open Image", nullptr));
        applyFilterButton->setText(QCoreApplication::translate("cameraWindow", "Apply...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cameraWindow: public Ui_cameraWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWINDOW_H
