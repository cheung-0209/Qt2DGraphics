#ifndef MOVEDIALOG_H
#define MOVEDIALOG_H

#include <QDialog>
#include "ui_movedialog.h"

namespace Ui {
class MoveDialog;
}

class MoveDialog : public QDialog {
    Q_OBJECT

public:
    explicit MoveDialog(QWidget *parent = nullptr);
    ~MoveDialog();

    int getDx() const;
    int getDy() const;

private:
    Ui::MoveDialog *ui;
};

#endif // MOVEDIALOG_H
