#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QVector>
#include <QList>
#include <QColor>

enum Shape { None, Line, Rectangle, Ellipse, Polygon, Fill };

struct DrawElement {
    Shape shape;
    QPoint startPoint;
    QPoint endPoint;
    QVector<QPoint> points;
    QColor color;  // 添加颜色属性
};

class DrawWidget : public QWidget {
    Q_OBJECT

public:
    explicit DrawWidget(QWidget *parent = nullptr);

    void setShape(Shape shape);
    void setColor(const QColor &color);  // 添加设置颜色的方法
    void selectElement(const QPoint &pos);
    void deleteSelectedElement();
    void moveSelectedElement(int dx, int dy);
    double calculateSelectedElementArea() const;  // 添加计算面积的方法
    double calculateSelectedElementLength() const;  // 添加计算长度的方法
    bool saveCanvas(const QString &fileName);  // 保存画布
    bool openCanvas(const QString &fileName);  // 打开画布
    void newCanvas();  // 新建画布

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Shape currentShape;
    QPoint startPoint, endPoint;
    QVector<QPoint> points;
    QList<DrawElement> elements;
    int selectedElementIndex;
    QColor currentColor;  // 当前颜色
};

#endif // DRAWWIDGET_H
