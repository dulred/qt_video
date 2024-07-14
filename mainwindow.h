#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QMenu>
#include <QAction>
#include <QPropertyAnimation>
#include <QTimer>
#include <QMainWindow>
#include <QDebug>
#include "playlist.h"
#include "title.h"
//#include "settingwid.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //初始化
    bool Init();
private:
    //连接信号槽
    bool ConnectSignalSlots();

    //关闭、最小化、最大化按钮响应
    void OnCloseBtnClicked();
    void OnMinBtnClicked();
    void OnMaxBtnClicked();
    //显示、隐藏播放列表
//    void OnShowOrHidePlaylist();



//    /**
//    * @brief	全屏播放
//    */
//    void OnFullScreenPlay();

//    void OnCtrlBarAnimationTimeOut();
//    void OnFullscreenMouseDetectTimeOut();

//    void OnCtrlBarHideTimeOut();
    void OnShowMenu();
//    void OnShowAbout();
//    void OpenFile();

//    void OnShowSettingWid();


//    //添加菜单
//    void InitMenu();
//    void MenuJsonParser(QJsonObject& json_obj, QMenu* menu);
//    QMenu* AddMenuFun(QString menu_title, QMenu* menu);
//    void AddActionFun(QString action_title, QMenu* menu, void(MainWindow::* slot_addr)());

signals:
    //最大化信号
    void SigShowMax(bool bIfMax);
    void SigSeekForward();
    void SigSeekBack();
    void SigAddVolume();
    void SigSubVolume();
    void SigPlayOrPause();
    void SigOpenFile(QString strFilename);
private:
    Ui::MainWindow *ui;
    bool m_bPlaying; ///< 正在播放

//     CtrlBar     *m_pCtrlBar;    ///< 播放控制面板
//     Playlist    *m_pPlaylist;   ///< 播放列表面板
//     Title       *m_pTitle;      ///< 标题栏面板
//     DisplayWid  *m_pDisplay;    ///< 显示区域
//     PlaylistCtrlBar *m_pPlaylistCtrlBar; ///< 播放列表控制按钮

    const int m_nShadowWidth; ///< 阴影宽度

    bool m_bFullScreenPlay; ///< 全屏播放标志

    QPropertyAnimation *m_stCtrlbarAnimationShow; //全屏时控制面板浮动显示
    QPropertyAnimation *m_stCtrlbarAnimationHide; //全屏时控制面板浮动显示
    QRect m_stCtrlBarAnimationShow;//控制面板显示区域
    QRect m_stCtrlBarAnimationHide;//控制面板隐藏区域

    QTimer m_stCtrlBarAnimationTimer;
    QTimer m_stFullscreenMouseDetectTimer;//全屏时鼠标位置监测时钟
    bool m_bFullscreenCtrlBarShow;
    QTimer stCtrlBarHideTimer;
    QMenu m_stMenu;
    Playlist m_stPlaylist;
    Title m_stTitle;

    bool m_bMoveDrag;//移动窗口标志
    QPoint m_DragPosition;

    About m_stAboutWidget;
//    SettingWid m_stSettingWid;


    QAction m_stActFullscreen;
    QMap<QString, void(MainWindow::*)()> map_act_;
};


#endif // MAINWINDOW_H
