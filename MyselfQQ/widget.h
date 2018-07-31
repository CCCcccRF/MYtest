#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextCharFormat>
class QUdpSocket;
class Server;
namespace Ui {
class Widget;
}
enum MsgType{Msg, UsrEnter, UsrLeft, FileName, Refuse};
class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent,QString usrname);
    ~Widget();
protected:
    void usrEnter(QString usrname,QString ipaddr);//新用户进入
    void usrLeft(QString usrname,QString time);//用户离开
    void sndMsg(MsgType type, QString srvaddr="");//发送消息类型

    QString getIP();
    QString getUsr();
    QString getMsg();

    void hasPendingFile(QString usrname, QString srvaddr,QString clntaddr, QString filename);//接收文件

    bool saveFile(const QString& filename);//保存文件

    void closeEvent(QCloseEvent *);//跨窗口关闭事件防止窗口重复打开

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QString uName;

    QString fileName;
    Server *srv;

    QColor color;
private slots:
    void processPendingDatagrams();//获取数据报大小
    void on_sendBtn_clicked();//动作槽函数


    void getFileName(QString);//获得文件名

    //按钮动作
    void on_sendTBtn_clicked();//发送文件按钮
    void on_fontCbx_currentFontChanged(const QFont &f);//设置输入框字体
    void on_sizeCbx_currentIndexChanged(const QString &arg1);//设置输入框字号
    void on_boldTBtn_clicked(bool checked);//加粗
    void on_italicTBtn_clicked(bool checked);//添加下划线按钮
    void on_underlineTBtn_clicked(bool checked);//添加下划线按钮
    void on_colorTBtn_clicked();//颜色改变按钮

    void curFmtChanged(const QTextCharFormat &fmt);//字体选择下拉菜单
    void on_saveTBtn_clicked();//保存聊天记录按钮
    void on_clearTBtn_clicked();//清除聊天记录按钮
    void on_exitBtn_clicked();//退出按钮
};

#endif // WIDGET_H
