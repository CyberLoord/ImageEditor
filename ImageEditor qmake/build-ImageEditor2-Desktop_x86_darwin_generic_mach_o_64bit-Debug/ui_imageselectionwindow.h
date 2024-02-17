/********************************************************************************
** Form generated from reading UI file 'imageselectionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESELECTIONWINDOW_H
#define UI_IMAGESELECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_imageselectionwindow
{
public:

    void setupUi(QDialog *imageselectionwindow)
    {
        if (imageselectionwindow->objectName().isEmpty())
            imageselectionwindow->setObjectName("imageselectionwindow");
        imageselectionwindow->resize(400, 300);

        retranslateUi(imageselectionwindow);

        QMetaObject::connectSlotsByName(imageselectionwindow);
    } // setupUi

    void retranslateUi(QDialog *imageselectionwindow)
    {
        imageselectionwindow->setWindowTitle(QCoreApplication::translate("imageselectionwindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imageselectionwindow: public Ui_imageselectionwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESELECTIONWINDOW_H
