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

    m_quickWidget = new QQuickWidget();
    m_quickWidget->setSource(QUrl("qrc:/main.qml"));
    m_quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_quickWidget->setClearColor(Qt::transparent);

    QMetaObject::invokeMethod(m_quickWidget->rootObject(), "setSize",
        Q_ARG(QVariant, ui->stackedLayoutWidget->size()));

    ui->stackedLayout->setStackingMode(QStackedLayout::StackAll);

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
