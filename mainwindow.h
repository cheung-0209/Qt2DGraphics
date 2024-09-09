#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawwidget.h"
#include "movedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLine_triggered();
    void on_actionRectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionPolygon_triggered();
    void on_actionSelect_triggered();
    void on_actionDelete_triggered();
    void on_actionMove_triggered();
    void on_actionChangeColor_triggered();
    void on_actionCalculateArea_triggered();
    void on_actionCalculateLength_triggered();
    void on_actionNewCanvas_triggered();  // 新建画布
    void on_actionOpenCanvas_triggered();  // 打开画布
    void on_actionSaveCanvas_triggered();  // 保存画布

private:
    Ui::MainWindow *ui;
    DrawWidget *drawWidget;
};
#endif // MAINWINDOW_H
