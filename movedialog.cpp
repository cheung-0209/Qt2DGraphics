#include "movedialog.h"
#include "ui_movedialog.h"

MoveDialog::MoveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoveDialog)
{
    ui->setupUi(this);
    ui->dxSpinBox->setRange(-1000, 1000);
    ui->dxSpinBox->setSingleStep(0.1);
    ui->dySpinBox->setRange(-1000, 1000);
    ui->dySpinBox->setSingleStep(0.1);
}

MoveDialog::~MoveDialog() {
    delete ui;
}

int MoveDialog::getDx() const {
    return ui->dxSpinBox->value();
}

int MoveDialog::getDy() const {
    return ui->dySpinBox->value();
}
