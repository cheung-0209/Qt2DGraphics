#include "drawwidget.h"
#include <cmath>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent), currentShape(None), selectedElementIndex(-1), currentColor(Qt::black) {
    setMouseTracking(true);
}

void DrawWidget::setShape(Shape shape) {
    currentShape = shape;
    selectedElementIndex = -1; // 取消选中状态
    update();
}

void DrawWidget::setColor(const QColor &color) {
    currentColor = color;
    if (selectedElementIndex != -1) {
        elements[selectedElementIndex].color = color;
        update();
    }
}

void DrawWidget::selectElement(const QPoint &pos) {
    selectedElementIndex = -1;
    for (int i = 0; i < elements.size(); ++i) {
        DrawElement &element = elements[i];
        QRect boundingRect;
        if (element.shape == Line) {
            boundingRect = QRect(element.startPoint, element.endPoint).normalized();
        } else if (element.shape == Rectangle || element.shape == Fill) {
            boundingRect = QRect(element.startPoint, element.endPoint).normalized();
        } else if (element.shape == Ellipse) {
            boundingRect = QRect(element.startPoint, element.endPoint).normalized();
        } else if (element.shape == Polygon) {
            boundingRect = QPolygon(element.points).boundingRect();
        }
        if (boundingRect.contains(pos)) {
            selectedElementIndex = i;
            break;
        }
    }
    update();
}

void DrawWidget::deleteSelectedElement() {
    if (selectedElementIndex != -1) {
        elements.removeAt(selectedElementIndex);
        selectedElementIndex = -1;
        update();
    }
}

void DrawWidget::moveSelectedElement(int dx, int dy) {
    if (selectedElementIndex != -1) {
        DrawElement &element = elements[selectedElementIndex];
        element.startPoint += QPoint(dx, dy);
        element.endPoint += QPoint(dx, dy);
        for (QPoint &point : element.points) {
            point += QPoint(dx, dy);
        }
        update();
    }
}

double DrawWidget::calculateSelectedElementArea() const {
    if (selectedElementIndex == -1) {
        return 0.0;
    }
    const DrawElement &element = elements[selectedElementIndex];
    double area = 0.0;
    if (element.shape == Rectangle || element.shape == Fill) {
        area = std::abs((element.endPoint.x() - element.startPoint.x()) * (element.endPoint.y() - element.startPoint.y()));
    } else if (element.shape == Ellipse) {
        area = M_PI * std::abs((element.endPoint.x() - element.startPoint.x()) / 2.0) * std::abs((element.endPoint.y() - element.startPoint.y()) / 2.0);
    } else if (element.shape == Polygon) {
        int n = element.points.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            area += element.points[i].x() * element.points[j].y();
            area -= element.points[j].x() * element.points[i].y();
        }
        area = std::abs(area) / 2.0;
    }
    return area;
}

double DrawWidget::calculateSelectedElementLength() const {
    if (selectedElementIndex == -1) {
        return 0.0;
    }
    const DrawElement &element = elements[selectedElementIndex];
    double length = 0.0;
    if (element.shape == Line) {
        length = std::sqrt(std::pow(element.endPoint.x() - element.startPoint.x(), 2) + std::pow(element.endPoint.y() - element.startPoint.y(), 2));
    } else if (element.shape == Polygon) {
        int n = element.points.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            length += std::sqrt(std::pow(element.points[j].x() - element.points[i].x(), 2) + std::pow(element.points[j].y() - element.points[i].y(), 2));
        }
    }
    return length;
}

bool DrawWidget::saveCanvas(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    QDataStream out(&file);
    out << elements.size();
    for (const DrawElement &element : elements) {
        out << static_cast<int>(element.shape) << element.startPoint << element.endPoint << element.points << element.color;
    }
    return true;
}

bool DrawWidget::openCanvas(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    QDataStream in(&file);
    int size;
    in >> size;
    elements.clear();
    for (int i = 0; i < size; ++i) {
        DrawElement element;
        int shape;
        in >> shape >> element.startPoint >> element.endPoint >> element.points >> element.color;
        element.shape = static_cast<Shape>(shape);
        elements.append(element);
    }
    update();
    return true;
}

void DrawWidget::newCanvas() {
    elements.clear();
    update();
}


void DrawWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const DrawElement &element : elements) {
        painter.setPen(element.color);
        if (element.shape == Line) {
            painter.drawLine(element.startPoint, element.endPoint);
        } else if (element.shape == Rectangle || element.shape == Fill) {
            if (element.shape == Fill) {
                painter.setBrush(element.color);
            }
            painter.drawRect(QRect(element.startPoint, element.endPoint));
        } else if (element.shape == Ellipse) {
            painter.drawEllipse(QRect(element.startPoint, element.endPoint));
        } else if (element.shape == Polygon) {
            QPolygon poly;
            for (const QPoint &point : element.points) {
                poly << point;
            }
            painter.drawPolygon(poly);
        }
    }

    if (currentShape == Line) {
        painter.setPen(currentColor);
        painter.drawLine(startPoint, endPoint);
    } else if (currentShape == Rectangle) {
        painter.setPen(currentColor);
        painter.drawRect(QRect(startPoint, endPoint));
    } else if (currentShape == Ellipse) {
        painter.setPen(currentColor);
        painter.drawEllipse(QRect(startPoint, endPoint));
    } else if (currentShape == Polygon) {
        painter.setPen(currentColor);
        QPolygon poly;
        for (const QPoint &point : points) {
            poly << point;
        }
        painter.drawPolygon(poly);
    } else if (currentShape == Fill) {
        painter.setBrush(currentColor);
        painter.drawRect(QRect(startPoint, endPoint));
    }

    if (selectedElementIndex != -1) {
        const DrawElement &element = elements[selectedElementIndex];
        QRect boundingRect;
        if (element.shape == Line) {
            boundingRect = QRect(element.startPoint, element.endPoint).normalized();
        } else if (element.shape == Rectangle || element.shape == Fill) {
            boundingRect = QRect(element.startPoint, element.endPoint).normalized();
        } else if (element.shape == Ellipse) {
            boundingRect = QRect(element.startPoint, element.endPoint).normalized();
        } else if (element.shape == Polygon) {
            boundingRect = QPolygon(element.points).boundingRect();
        }
        painter.setPen(Qt::DashLine);
        painter.drawRect(boundingRect);
        painter.setPen(Qt::SolidLine);
    }
}

void DrawWidget::mousePressEvent(QMouseEvent *event) {
    if (currentShape != None) {
        startPoint = event->pos();
        if (currentShape == Polygon) {
            points << startPoint;
        }
    } else {
        selectElement(event->pos());
    }
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event) {
    if (currentShape != None && currentShape != Polygon) {
        endPoint = event->pos();
        update();
    }
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (currentShape != None) {
        endPoint = event->pos();
        if (currentShape != Polygon) {
            DrawElement element;
            element.shape = currentShape;
            element.startPoint = startPoint;
            element.endPoint = endPoint;
            element.color = currentColor;  // 设置颜色
            if (currentShape == Polygon) {
                element.points = points;
            }
            elements.append(element);
            update();
        }
    }
}
