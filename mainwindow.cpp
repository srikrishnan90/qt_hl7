#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <hl7mllp.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
  // HL7MLLP sock( "192.168.29.35", "2500" );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    /*std::string hl7Message="MSH|^~\\&|AccMgr|1|||20050110045504||ADT^A08|599102|P|2.3|||\r"
                           "EVN|A01|20050110045502|||||\r"
                           "PID|1||10006579^^^1^MRN^1||DUCK^DONALD^D||19241010|M||1|111 DUCK ST^^FOWL^CA^999990000^^M|1|8885551212|8885551212|1|2||40007716^^^AccMgr^VN^1|123121234|||||||||||NO\r"
                           "NK1|1|DUCK^HUEY|SO|3583 DUCK RD^^FOWL^CA^999990000|8885552222||Y||||||||||||||\r"
                           "PV1|1|I|PREOP^101^1^1^^^S|3|||37^DISNEY^WALT^^^^^^AccMgr^^^^CI|||01||||1|||37^DISNEY^WALT^^^^^^AccMgr^^^^CI|2|40007716^^^AccMgr^VN|4|||||||||||||||||||1||G|||20050110045253||||||\r";
*/
    std::string message="MSH|^~\&|LAB|ADX CHENNAI|LAB||201909251014||ORU^R01|||2.3"
                    "PID|||Daniel"
                    "OBR|1|||^HBsAg|||201909181732|||||||201909181732||||||||Jim||LAB"
                    "OBX|1|NM|Test Line 1^HBsAg||T|89.6|(+Ve)|+||T: 89.6 (+Ve)||||201909181732|^";
    std::string hl7received;

    HL7MLLP sock( "192.168.100.44", "2500" ); //IP , Port

    sock.send_msg_mllp( message );
    sock.read_msg_mllp( hl7received );
    qDebug()<<hl7received.data();
}
