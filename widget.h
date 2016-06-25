#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include <QQuickWidget>
#include <QQuickItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void showQuickView();
    void hideQuickView();

private:
    Ui::Widget *ui;
    QQuickWidget *m_quickWidget;

};

#endif // WIDGET_H
