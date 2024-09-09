#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawWidget = new DrawWidget(this);
    setCentralWidget(drawWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLine_triggered() {
    drawWidget->setShape(Line);
}

void MainWindow::on_actionRectangle_triggered() {
    drawWidget->setShape(Rectangle);
}

void MainWindow::on_actionEllipse_triggered() {
    drawWidget->setShape(Ellipse);
}

void MainWindow::on_actionPolygon_triggered() {
    drawWidget->setShape(Polygon);
}

void MainWindow::on_actionSelect_triggered() {
    drawWidget->setShape(None);
}

void MainWindow::on_actionDelete_triggered() {
    drawWidget->deleteSelectedElement();
}

void MainWindow::on_actionMove_triggered() {
    MoveDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int dx = dialog.getDx();
        int dy = dialog.getDy();
        drawWidget->moveSelectedElement(dx, dy);
    }
}

void MainWindow::on_actionChangeColor_triggered() {
    QColor color = QColorDialog::getColor(Qt::black, this, "选择颜色");
    if (color.isValid()) {
        drawWidget->setColor(color);
    }
}

void MainWindow::on_actionCalculateArea_triggered() {
    double area = drawWidget->calculateSelectedElementArea();
    QMessageBox::information(this, "面积", QString("选中图形的面积: %1").arg(area));
}

void MainWindow::on_actionCalculateLength_triggered() {
    double length = drawWidget->calculateSelectedElementLength();
    QMessageBox::information(this, "长度", QString("选中线段或图形的周长: %1").arg(length));
}

void MainWindow::on_actionNewCanvas_triggered() {
    drawWidget->newCanvas();
}

void MainWindow::on_actionOpenCanvas_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "打开画布", "", "Canvas Files (*.canvas);;All Files (*)");
    if (!fileName.isEmpty()) {
        if (!drawWidget->openCanvas(fileName)) {
            QMessageBox::warning(this, "打开失败", "无法打开画布文件。");
        }
    }
}

void MainWindow::on_actionSaveCanvas_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, "保存画布", "", "Canvas Files (*.canvas);;All Files (*)");
    if (!fileName.isEmpty()) {
        if (!drawWidget->saveCanvas(fileName)) {
            QMessageBox::warning(this, "保存失败", "无法保存画布文件。");
        }
    }
}
