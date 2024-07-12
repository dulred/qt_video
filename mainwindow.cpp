#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalhelper.h"
#include <QSettings>
#include <QDir>
#include <QTextEdit>
#include <QDockWidget>
#include <QListWidget>
const int FULLSCREEN_MOUSE_DETECT_TIME = 500;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_nShadowWidth(0),
      m_stMenu(this),
      m_stPlaylist(this),
      m_stTitle(this),
      m_bMoveDrag(false),
      m_stActFullscreen(this)

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

bool MainWindow::Init()
{
    QWidget *em = new QWidget(this);
    ui->PlaylistWid->setTitleBarWidget(em);
    ui->PlaylistWid->setWidget(&m_stPlaylist);
    ui->PlaylistWid->setFixedWidth(100);

    QWidget *emTitle = new QWidget(this);
    ui->TitleWid->setTitleBarWidget(emTitle);
    ui->TitleWid->setWidget(&m_stTitle);

//    //连接自定义信号与槽
//    if (ConnectSignalSlots() == false)
//    {
//        return false;
//    }

//    if (ui->CtrlBarWid->Init() == false ||
//        m_stPlaylist.Init() == false ||
//        ui->ShowWid->Init() == false ||
//        m_stTitle.Init() == false)
//    {
//        return false;
//    }


//    m_stCtrlbarAnimationShow = new QPropertyAnimation(ui->CtrlBarWid, "geometry");
//    m_stCtrlbarAnimationHide = new QPropertyAnimation(ui->CtrlBarWid, "geometry");

//    if (m_stAboutWidget.Init() == false)
//    {
//        return false;
//    }

//    //{
//    //    QMenu* menu = AddMenuFun(tr("屏幕"), &m_stMenu);
//    //    m_stActFullscreen.setText(tr("全屏"));
//    //    m_stActFullscreen.setCheckable(true);
//    //    menu->addAction(&m_stActFullscreen);
//    //}
//    //{
//    //    QMenu* menu = AddMenuFun(tr("声音"), &m_stMenu);
//    //    AddActionFun(tr("音量 +"), menu, &MainWid::SigAddVolume);
//    //    AddActionFun(tr("音量 -"), menu, &MainWid::SigSubVolume);
//    //}

//    //{
//    //    QMenu* menu = AddMenuFun(tr("打开"), &m_stMenu);
//    //    AddActionFun(tr("打开文件"), menu, &MainWid::OpenFile);
//    //}

//    //AddActionFun(tr("关于"), &m_stMenu, &MainWid::OnShowAbout);
//    //AddActionFun(tr("退出"), &m_stMenu, &MainWid::OnCloseBtnClicked);


//    InitMenu();


    return true;
}

