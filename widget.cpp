#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->showQuickViewButton, SIGNAL(clicked()),
            this, SLOT(showQuickView()));
    connect(ui->hideQuickViewButton, SIGNAL(clicked()),
            this, SLOT(hideQuickView()));

    QQuickView *view = new QQuickView();
    view->setColor(Qt::transparent);
    view->setSource(QUrl("qrc:/main.qml"));
    m_quickWidget = QWidget::createWindowContainer(view, this);

    ui->stackedLayout->setStackingMode(QStackedLayout::StackAll);
    ui->stackedLayout->addWidget(new QOpenGLWidget(this));
    ui->stackedLayout->addWidget(m_quickWidget);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showQuickView()
{
    m_quickWidget->setVisible(true);
}

void Widget::hideQuickView()
{
    m_quickWidget->setVisible(false);
}
