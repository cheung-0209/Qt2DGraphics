/********************************************************************************
** Form generated from reading UI file 'MoveDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVEDIALOG_H
#define UI_MOVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MoveDialog
{
public:
    QDialogButtonBox *buttonBox;
    QDoubleSpinBox *dxSpinBox;
    QDoubleSpinBox *dySpinBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *MoveDialog)
    {
        if (MoveDialog->objectName().isEmpty())
            MoveDialog->setObjectName("MoveDialog");
        MoveDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(MoveDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        dxSpinBox = new QDoubleSpinBox(MoveDialog);
        dxSpinBox->setObjectName("dxSpinBox");
        dxSpinBox->setGeometry(QRect(110, 100, 131, 22));
        dySpinBox = new QDoubleSpinBox(MoveDialog);
        dySpinBox->setObjectName("dySpinBox");
        dySpinBox->setGeometry(QRect(110, 170, 131, 22));
        label = new QLabel(MoveDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 100, 71, 16));
        label_2 = new QLabel(MoveDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 170, 71, 16));

        retranslateUi(MoveDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MoveDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MoveDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MoveDialog);
    } // setupUi

    void retranslateUi(QDialog *MoveDialog)
    {
        MoveDialog->setWindowTitle(QCoreApplication::translate("MoveDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MoveDialog", "X\346\226\271\345\220\221\347\247\273\345\212\250\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MoveDialog", "y\346\226\271\345\220\221\347\247\273\345\212\250\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoveDialog: public Ui_MoveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVEDIALOG_H
