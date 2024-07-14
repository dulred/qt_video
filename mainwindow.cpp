#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalhelper.h"
#include <QSettings>
#include <QDir>
#include <QTextEdit>
#include <QDockWidget>
#include <QListWidget>
#include <QMessageBox>
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
    setWindowFlags(Qt::FramelessWindowHint /*| Qt::WindowSystemMenuHint*/ | Qt::WindowMinimizeButtonHint);
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

   //连接自定义信号与槽
    if (ConnectSignalSlots() == false)
    {
        return false;
    }

    if (/*ui->CtrlBarWid->Init() == false ||*/
        m_stPlaylist.Init() == false ||
        ui->ShowWid->Init() == false ||
        m_stTitle.Init() == false)
    {
        return false;
    }


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
//    //    AddActionFun(tr("音量 +"), menu, &MainWindow::SigAddVolume);
//    //    AddActionFun(tr("音量 -"), menu, &MainWindow::SigSubVolume);
//    //}

//    //{
//    //    QMenu* menu = AddMenuFun(tr("打开"), &m_stMenu);
//    //    AddActionFun(tr("打开文件"), menu, &MainWindow::OpenFile);
//    //}

//    //AddActionFun(tr("关于"), &m_stMenu, &MainWindow::OnShowAbout);
//    //AddActionFun(tr("退出"), &m_stMenu, &MainWindow::OnCloseBtnClicked);


//    InitMenu();
    return true;
}

bool MainWindow::ConnectSignalSlots()
{
    //连接信号与槽
    connect(&m_stTitle, &Title::SigCloseBtnClicked, this, &MainWindow::OnCloseBtnClicked);
    connect(&m_stTitle, &Title::SigMaxBtnClicked, this, &MainWindow::OnMaxBtnClicked);
    connect(&m_stTitle, &Title::SigMinBtnClicked, this, &MainWindow::OnMinBtnClicked);
    connect(&m_stTitle, &Title::SigDoubleClicked, this, &MainWindow::OnMaxBtnClicked);
//    connect(&m_stTitle, &Title::SigFullScreenBtnClicked, this, &MainWindow::OnFullScreenPlay);
//    connect(&m_stTitle, &Title::SigOpenFile, &m_stPlaylist, &Playlist::OnAddFileAndPlay);
    connect(&m_stTitle, &Title::SigShowMenu, this, &MainWindow::OnShowMenu);


//    connect(&m_stPlaylist, &Playlist::SigPlay, ui->ShowWid, &Show::SigPlay);

//    connect(ui->ShowWid, &Show::SigOpenFile, &m_stPlaylist, &Playlist::OnAddFileAndPlay);
//    connect(ui->ShowWid, &Show::SigFullScreen, this, &MainWindow::OnFullScreenPlay);
//    connect(ui->ShowWid, &Show::SigPlayOrPause, VideoCtl::GetInstance(), &VideoCtl::OnPause);
//    connect(ui->ShowWid, &Show::SigStop, VideoCtl::GetInstance(), &VideoCtl::OnStop);
//    connect(ui->ShowWid, &Show::SigShowMenu, this, &MainWindow::OnShowMenu);
//    connect(ui->ShowWid, &Show::SigSeekForward, VideoCtl::GetInstance(), &VideoCtl::OnSeekForward);
//    connect(ui->ShowWid, &Show::SigSeekBack, VideoCtl::GetInstance(), &VideoCtl::OnSeekBack);
//    connect(ui->ShowWid, &Show::SigAddVolume, VideoCtl::GetInstance(), &VideoCtl::OnAddVolume);
//    connect(ui->ShowWid, &Show::SigSubVolume, VideoCtl::GetInstance(), &VideoCtl::OnSubVolume);

//    connect(ui->CtrlBarWid, &CtrlBar::SigShowOrHidePlaylist, this, &MainWindow::OnShowOrHidePlaylist);
//    connect(ui->CtrlBarWid, &CtrlBar::SigPlaySeek, VideoCtl::GetInstance(), &VideoCtl::OnPlaySeek);
//    connect(ui->CtrlBarWid, &CtrlBar::SigPlayVolume, VideoCtl::GetInstance(), &VideoCtl::OnPlayVolume);
//    connect(ui->CtrlBarWid, &CtrlBar::SigPlayOrPause, VideoCtl::GetInstance(), &VideoCtl::OnPause);
//    connect(ui->CtrlBarWid, &CtrlBar::SigStop, VideoCtl::GetInstance(), &VideoCtl::OnStop);
//    connect(ui->CtrlBarWid, &CtrlBar::SigBackwardPlay, &m_stPlaylist, &Playlist::OnBackwardPlay);
//    connect(ui->CtrlBarWid, &CtrlBar::SigForwardPlay, &m_stPlaylist, &Playlist::OnForwardPlay);
//    connect(ui->CtrlBarWid, &CtrlBar::SigShowMenu, this, &MainWindow::OnShowMenu);
//    connect(ui->CtrlBarWid, &CtrlBar::SigShowSetting, this, &MainWindow::OnShowSettingWid);

//    connect(this, &MainWindow::SigShowMax, &m_stTitle, &Title::OnChangeMaxBtnStyle);
//    connect(this, &MainWindow::SigSeekForward, VideoCtl::GetInstance(), &VideoCtl::OnSeekForward);
//    connect(this, &MainWindow::SigSeekBack, VideoCtl::GetInstance(), &VideoCtl::OnSeekBack);
//    connect(this, &MainWindow::SigAddVolume, VideoCtl::GetInstance(), &VideoCtl::OnAddVolume);
//    connect(this, &MainWindow::SigSubVolume, VideoCtl::GetInstance(), &VideoCtl::OnSubVolume);
//    connect(this, &MainWindow::SigOpenFile, &m_stPlaylist, &Playlist::OnAddFileAndPlay);


//    connect(VideoCtl::GetInstance(), &VideoCtl::SigVideoTotalSeconds, ui->CtrlBarWid, &CtrlBar::OnVideoTotalSeconds);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigVideoPlaySeconds, ui->CtrlBarWid, &CtrlBar::OnVideoPlaySeconds);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigVideoVolume, ui->CtrlBarWid, &CtrlBar::OnVideopVolume);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigPauseStat, ui->CtrlBarWid, &CtrlBar::OnPauseStat, Qt::QueuedConnection);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigStopFinished, ui->CtrlBarWid, &CtrlBar::OnStopFinished, Qt::QueuedConnection);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigStopFinished, ui->ShowWid, &Show::OnStopFinished, Qt::QueuedConnection);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigFrameDimensionsChanged, ui->ShowWid, &Show::OnFrameDimensionsChanged, Qt::QueuedConnection);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigStopFinished, &m_stTitle, &Title::OnStopFinished, Qt::DirectConnection);
//    connect(VideoCtl::GetInstance(), &VideoCtl::SigStartPlay, &m_stTitle, &Title::OnPlay, Qt::DirectConnection);

//    connect(&m_stCtrlBarAnimationTimer, &QTimer::timeout, this, &MainWindow::OnCtrlBarAnimationTimeOut);

//    connect(&m_stFullscreenMouseDetectTimer, &QTimer::timeout, this, &MainWindow::OnFullscreenMouseDetectTimeOut);


//    connect(&m_stActFullscreen, &QAction::triggered, this, &MainWindow::OnFullScreenPlay);



    return true;
}

void MainWindow::OnCloseBtnClicked()
{
    this->close();
}

void MainWindow::OnMaxBtnClicked()
{
    if (isMaximized())
    {
        showNormal();
        emit SigShowMax(false);
    }
    else
    {
        showMaximized();
        emit SigShowMax(true);
    }
}

void MainWindow::OnMinBtnClicked()
{
    this->showMinimized();
}

void MainWindow::OnShowMenu()
{
    m_stMenu.exec(cursor().pos());
}

