#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalhelper.h"
const int FULLSCREEN_MOUSE_DETECT_TIME = 500;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_nShadowWidth(0)

{
    ui->setupUi(this);

    //无边框、无系统菜单、 任务栏点击最小化
//    setWindowFlags(Qt::FramelessWindowHint /*| Qt::WindowSystemMenuHint*/ | Qt::WindowMinimizeButtonHint);
    //设置任务栏图标
    this->setWindowIcon(QIcon("://res/player.png"));
    //加载样式
    QString qss = GlobalHelper::GetQssStr("://res/qss/mainwid.css");
    setStyleSheet(qss);

    // 追踪鼠标 用于播放时隐藏鼠标
    this->setMouseTracking(true);

    //ui->ShowWid->setMouseTracking(true);

    //保证窗口不被绘制上的部分透明
    //setAttribute(Qt::WA_TranslucentBackground);

    //接受放下事件
    //setAcceptDrops(true);
    //可以清晰地看到放下过程中的图标指示
    //setDropIndicatorShown(true);

//    setAcceptDrops(true);
//    setDragDropMode(QAbstractItemView::DragDrop);
//    setDragEnabled(true);
//    setDropIndicatorShown(true);

    //窗口大小调节
//    QSizeGrip   *pSizeGrip = new QSizeGrip(this);
//    pSizeGrip->setMinimumSize(10, 10);
//    pSizeGrip->setMaximumSize(10, 10);
//    ui->verticalLayout->addWidget(pSizeGrip, 0, Qt::AlignBottom | Qt::AlignRight);

    m_bPlaying = false;

    m_bFullScreenPlay = false;

    m_stCtrlBarAnimationTimer.setInterval(2000);
    m_stFullscreenMouseDetectTimer.setInterval(FULLSCREEN_MOUSE_DETECT_TIME);

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::Init(){
    return true;
}
