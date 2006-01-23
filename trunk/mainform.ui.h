/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

// eprzelewy


#include <qtextcodec.h>
#include <qdir.h>
#include <qmessagebox.h>
#include <qsettings.h>
#include <qapplication.h>
#include <qevent.h> 
#include <qprocess.h>
#include <qdom.h>

#include "kontr.h"
#include "kreator.h"
#include "mainform.h"  
#include "preview.h"
#include "przelew.h" 
#include "sett.h"
#include "user.h" 
#include "us.h"
#include "zus.h"


QString pdGlob;

void
Form1::init ()
{
  QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("ISO8859-2"));

  //  create local user directory for store xml files
  // works only on Linux -> see also licence Qt 3
  QDir tmp;
  QString progDir = tmp.homeDirPath () + "/elinux";
  pdGlob = progDir;
  // qDebug(progDir);
  if (!tmp.exists (progDir))
    tmp.mkdir (progDir, TRUE);

  if (!tmp.exists (progDir + "/przelewy"))
    tmp.mkdir (progDir + "/przelewy", TRUE);

  // first run
  if (firstRun ())
    settClick ();
  // first run

  readKontr (progDir);
  readHist (progDir);
}



bool
Form1::firstRun ()
{
  qDebug (__FUNCTION__);
  QSettings settings;
  bool ok;
  settings.readEntry ("przelewy/firstrun", "", &ok);
  if (ok == 0)
    {
      return true;
    }
  else
    return false;
}

void
Form1::tableClear (QTable * tab)
{
  int x = tab->numRows ();
  for (int i = x; i >= 0; --i)
    tab->removeRow (i);
}

void 
Form1::tabChanged(QWidget *aaa)
{
    if (tabWidget2->indexOf(aaa) == 0) {
 kontrahenciDodajAction->setEnabled( false);
  kontrahenciEdycjaAction->setEnabled( false);
  kontrahenciUsunAction->setEnabled( false);
  przelewyEdAction->setEnabled( true );
  przelewUsunAction->setEnabled( true );
// qDebug("Historia");
}
    if (tabWidget2->indexOf(aaa) == 1) {
 kontrahenciDodajAction->setEnabled( true );
  kontrahenciEdycjaAction->setEnabled( true );
  kontrahenciUsunAction->setEnabled( true );
  przelewyEdAction->setEnabled( false);
  przelewUsunAction->setEnabled( false);
//   qDebug("Osobki");
}

}

void
Form1::readHist (QString progDir)
{
  /*!
   * step one: get list of files from directory
   */
  QDir allFiles;
  QString text;

  QDomDocument doc ("przelewy");
  QDomElement root;
  QDomElement nadawca;
  QDomElement odbiorca;

  allFiles.setPath (progDir + "/przelewy");
  allFiles.setFilter (QDir::Files);
  allFiles.setNameFilter ("h*.xml");
  QStringList pliczki = allFiles.entryList ();
  int i, max = pliczki.count ();
  for (i = 0; i < max; ++i)
    {
      // qDebug(pliczki[i]);
      tableH->insertRows (tableH->numRows (), 1);
      text = pliczki[i];
      tableH->setText (tableH->numRows () - 1, 0, text);

      QFile file (progDir + "/przelewy/" + pliczki[i]);

      if (!file.open (IO_ReadOnly))
 {
   qDebug ("file doesn't exists");
   return;
 }
      else
 {
   QTextStream stream (&file);

   if (!doc.setContent (stream.read ()))
     {
       // qDebug ("can not set content ");
       // qDebug( file.name() );
       file.close ();
       // return;
     }
 }

      root = doc.documentElement ();
      tableH->setText (tableH->numRows () - 1, 1,
         root.attribute ("date", "NULL"));
      tableH->setText (tableH->numRows () - 1, 2,
         root.attribute ("typ", "NULL"));
      tableH->setText (tableH->numRows () - 1, 4,
         root.attribute ("kwota", "NULL"));
      nadawca = root.firstChild ().toElement ();
      odbiorca = root.lastChild ().toElement ();
      QString odb = odbiorca.attribute ("name", "NULL");
      if (odb == "NULL")
	  odb = root.attribute ("typZ", "NULL");
      tableH->setText (tableH->numRows () - 1, 3, odb);
    }

}

void
Form1::aboutQt ()
{
  QMessageBox::aboutQt (this, "e-przelewy");
}

void
Form1::oProg ()
{
  QMessageBox::about (this, "e-Przelewy v1.0.1 beta",
        "Program do drukowania przelewów. \n Koordynator projektu: \n\tGrzegorz Rêkawek www.e-linux.pl \n Programista:\n\tTomasz 'moux' Pielech \nGrafika:\n\tDariusz Arciszewski \n\nSupport: info@e-linux.pl");
}

void
Form1::editFHist ()
{
  int row, max = tableH->numRows ();
  for (row = 0; row < max; ++row)
    {
      if (tableH->isRowSelected (row))
 break;
    }
  qDebug (__FUNCTION__);
  if ((tableH->text (row, 2).left (2) == "Wp")
      || (tableH->text (row, 2) == "Przelew"))
    {
      Form6 *pWindow = new Form6;
      pWindow->fileName = tableH->text (row, 0);
      pWindow->readData ();
      if (pWindow->exec () == QDialog::Accepted)
 {
	  
      tableH->insertRows (tableH->numRows (), 1);
     QStringList row = QStringList::split( "|",  pWindow->ret );
     tableH->setText (tableH->numRows () - 1, 0, row[0]); // file name
     tableH->setText (tableH->numRows () - 1, 1, row[1]); // date
     tableH->setText (tableH->numRows () - 1, 2, row[2]); // type
     tableH->setText (tableH->numRows () - 1, 3, row[3]); // for 
     tableH->setText (tableH->numRows () - 1, 4, row[4]); // price
/*	  
  tableClear (tableH);
   readHist (pdGlob);
   */
 }
    }

  if ((tableH->text (row, 2).left (5) == "ZUSWp")
      || (tableH->text (row, 2) == "ZUSPrzelew"))
    {
      pZUS *pWindow = new pZUS;
      pWindow->fileName = tableH->text (row, 0);
      pWindow->readData ();
      if (pWindow->exec () == QDialog::Accepted)
 {
	  /*
   tableClear (tableH);
   QDir tmp;
   QString progDir = tmp.homeDirPath () + "/elinux";
   tmp.mkdir (progDir, TRUE);
   readHist (progDir);
   */
      tableH->insertRows (tableH->numRows (), 1);
     QStringList row = QStringList::split( "|",  pWindow->ret );
     tableH->setText (tableH->numRows () - 1, 0, row[0]); // file name
     tableH->setText (tableH->numRows () - 1, 1, row[1]); // date
     tableH->setText (tableH->numRows () - 1, 2, row[2]); // type
     tableH->setText (tableH->numRows () - 1, 3, row[3]); // for 
     tableH->setText (tableH->numRows () - 1, 4, row[4]); // price
	  
 }
    }

  if ((tableH->text (row, 2).left (4) == "USWp")
      || (tableH->text (row, 2) == "USPrzelew"))
    {
      pUS *pWindow = new pUS;
      pWindow->fileName = tableH->text (row, 0);
      pWindow->readData ();
      if (pWindow->exec () == QDialog::Accepted)
 {
	  /*
   tableClear (tableH);
   QDir tmp;
   QString progDir = tmp.homeDirPath () + "/elinux";
   tmp.mkdir (progDir, TRUE);
   readHist (progDir);
   */
     tableH->insertRows (tableH->numRows (), 1);
     QStringList row = QStringList::split( "|",  pWindow->ret );
     tableH->setText (tableH->numRows () - 1, 0, row[0]); // file name
     tableH->setText (tableH->numRows () - 1, 1, row[1]); // date
     tableH->setText (tableH->numRows () - 1, 2, row[2]); // type
     tableH->setText (tableH->numRows () - 1, 3, row[3]); // for 
     tableH->setText (tableH->numRows () - 1, 4, row[4]); // price

 }
    }
}

void
Form1::delFHist ()
{
  if (QMessageBox::
      warning (this, "e-przelewy",
        "Czy napewno chcesz usun±æ ten przelew z historii?", "Tak",
        "Nie", 0, 0, 1) == 0)
    {

      int row, max = tableH->numRows ();
      for (row = 0; row < max; ++row)
 {
   if (tableH->isRowSelected (row))
     break;
 }
      qDebug (tableH->text (row, 0) + pdGlob);

      QFile file (pdGlob + "/przelewy/" + tableH->text (row, 0));
      if (file.exists ())
 file.remove ();
      tableH->removeRow(row);
      
/*      
      tableClear (tableH);
      readHist (pdGlob);
      */
    }

}

void
Form1::readKontr (QString progDir)
{
  QDomDocument doc ("kontrahenci");
  QDomElement root;
  QDomElement urzad;
  QDomElement firma;

  QFile file (progDir + "/kontrah.xml");
  if (!file.open (IO_ReadOnly))
    {
      qDebug ("file doesn't exists");
      return;

    }
  else
    {
      QTextStream stream (&file);
      if (!doc.setContent (stream.read ()))
 {
   qDebug ("can not set content ");
   file.close ();
   return;
 }
      else
 {
   root = doc.documentElement ();
   urzad = root.firstChild ().toElement ();
   firma = root.lastChild ().toElement ();
 }
      QString text;

      for (QDomNode n = firma.firstChild (); !n.isNull ();
    n = n.nextSibling ())
 {
   tableK->insertRows (tableK->numRows (), 1);
   text = n.toElement ().attribute ("name");
   tableK->setText (tableK->numRows () - 1, 0, text);
   text = "firma";
   tableK->setText (tableK->numRows () - 1, 1, text);
   text = n.toElement ().attribute ("place");
   tableK->setText (tableK->numRows () - 1, 2, text);
   text = n.toElement ().attribute ("address");
   tableK->setText (tableK->numRows () - 1, 3, text);
   text = n.toElement ().attribute ("telefon");
   tableK->setText (tableK->numRows () - 1, 4, text);
 }

      for (QDomNode n = urzad.firstChild (); !n.isNull ();
    n = n.nextSibling ())
 {
   tableK->insertRows (tableK->numRows (), 1);
   text = n.toElement ().attribute ("name");
   tableK->setText (tableK->numRows () - 1, 0, text);
   text = "urzad";
   tableK->setText (tableK->numRows () - 1, 1, text);
   text = n.toElement ().attribute ("place");
   tableK->setText (tableK->numRows () - 1, 2, text);
   text = n.toElement ().attribute ("address");
   tableK->setText (tableK->numRows () - 1, 3, text);
   text = n.toElement ().attribute ("telefon");
   tableK->setText (tableK->numRows () - 1, 4, text);
 }
    }
}

void
Form1::daneFirmyClick ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  Form2 *daneFirmyWindow = new Form2;
  daneFirmyWindow->show ();
}

void
Form1::settClick ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  Form7 *settWindow = new Form7;
  settWindow->show ();
}

void
Form1::kretorClick ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
//     QMessageBox::information( this, "e-przelewy", "Funkcja jeszcze nie gotowa. Uzyj menu Przelewy->Nowy", QMessageBox::Ok );
  Form3 *kreatorWindow = new Form3;
  if (kreatorWindow->exec () == QDialog::Accepted)
    {
      kreatorWindow->print ();
     QStringList row = QStringList::split( "|",  kreatorWindow->ret );
     if (row[0] == "") return;
      
      tableH->insertRows (tableH->numRows (), 1);
     tableH->setText (tableH->numRows () - 1, 0, row[0]); // file name
     tableH->setText (tableH->numRows () - 1, 1, row[1]); // date
     tableH->setText (tableH->numRows () - 1, 2, row[2]); // type
     tableH->setText (tableH->numRows () - 1, 3, row[3]); // for 
     tableH->setText (tableH->numRows () - 1, 4, row[4]); // price
      // tableClear (tableH);
      // readHist (pdGlob);
    }
  // delete kreatorWindow;
}

void
Form1::kontrClick ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  Form4 *kontrWindow = new Form4;
  if (kontrWindow->exec () == QDialog::Accepted)
    {
      // tableClear (tableK);
      /*
      QDir tmp;
      QString progDir = tmp.homeDirPath () + "/elinux";
      qDebug (progDir);
      tmp.mkdir (progDir, TRUE);
*/
      // readKontr (progDir);
     tableK->insertRows (tableK->numRows (), 1);
     QStringList row = QStringList::split( "|",  kontrWindow->ret );
     tableK->setText (tableK->numRows () - 1, 0, row[0]); // name
     tableK->setText (tableK->numRows () - 1, 1, row[1]); // type
     tableK->setText (tableK->numRows () - 1, 2, row[2]); // place
     tableK->setText (tableK->numRows () - 1, 3, row[3]); // address
     tableK->setText (tableK->numRows () - 1, 4, row[4]); // telefon
    }
}

void
Form1::kontrDel ()
{
      int row, max = tableK->numRows ();
      for (row = 0; row < max; ++row)
 {
   if (tableK->isRowSelected (row))
     break;
 }
    
    
  if (QMessageBox::
      warning (this, "e-przelewy",
        "Czy napewno chcesz usun±æ kontrahenta " +
	tableK->text (row, 0) + "?", "Tak", "Nie", 0,
        0, 1) == 0)
    {

      QDomDocument doc ("kontrahenci");
      QDomElement root;
      QDomElement urzad;
      QDomElement firma;

      QFile file (pdGlob + "/kontrah.xml");
      if (!file.open (IO_ReadOnly))
 {
   qDebug ("file doesn't exists");
   return;

 }
      else
 {
   QTextStream stream (&file);
   if (!doc.setContent (stream.read ()))
     {
       qDebug ("can not set content ");
       file.close ();
       return;
     }
   else
     {
       root = doc.documentElement ();
       urzad = root.firstChild ().toElement ();
       firma = root.lastChild ().toElement ();
     }
   QString text;

   for (QDomNode n = firma.firstChild (); !n.isNull ();
        n = n.nextSibling ())
     {
       // qDebug("aaa");
       if (n.toElement ().attribute ("name").
    compare (tableK->text (row, 0)) == 0)
  {
    firma.removeChild (n);
    break;
  }
     }

   for (QDomNode n = urzad.firstChild (); !n.isNull ();
        n = n.nextSibling ())
     {
       // qDebug("aaa");
       if (n.toElement ().attribute ("name").
    compare (tableK->text (row, 0)) == 0)
  {
    urzad.removeChild (n);
    break;
  }
     }


   QString xml = doc.toString ();
   file.close ();
   file.open (IO_WriteOnly);
   QTextStream ts (&file);
   ts << xml;

   file.close ();
   tableK->removeRow(row);
   // 
   // tableClear (tableK);
   // QDir tmp;
   // QString progDir = tmp.homeDirPath () + "/elinux";
   // qDebug (progDir);
   // readKontr (progDir);
 }

    }
}

void
Form1::kontrEd ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  int row, max = tableK->numRows ();

  for (row = 0; row < max; ++row)
    {
      if (tableK->isRowSelected (row))
 break;
    }
  qDebug (tableK->text (row, 0));

  Form4 *kontrWindow = new Form4;
  kontrWindow->readData (tableK->text (row, 0), tableK->text (row, 1));
  if (kontrWindow->exec () == QDialog::Accepted)
    {
      /*
      tableClear (tableK);
       QDir tmp;
       QString progDir = tmp.homeDirPath () + "/elinux";
       qDebug (progDir);
       readKontr (progDir);
       */
       QStringList rowTxt = QStringList::split( "|",  kontrWindow->ret );
       tableK->setText (row, 0, rowTxt[0]); // name
       tableK->setText (row, 1, rowTxt[1]); // type
       tableK->setText (row, 2, rowTxt[2]); // place
       tableK->setText (row, 3, rowTxt[3]); // address
       tableK->setText (row, 4, rowTxt[4]); // telefon
    }
}


void
Form1::newPrzwl ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  Form6 *pWindow = new Form6;
  if (pWindow->exec () == QDialog::Accepted)
    {
      /*
      tableClear (tableH);
      QDir tmp;
      QString progDir = tmp.homeDirPath () + "/elinux";
      tmp.mkdir (progDir, TRUE);
      readHist (progDir);
      */
      // kreatorWindow->print ();
     tableH->insertRows (tableH->numRows (), 1);
     QStringList row = QStringList::split( "|",  pWindow->ret );
     tableH->setText (tableH->numRows () - 1, 0, row[0]); // file name
     tableH->setText (tableH->numRows () - 1, 1, row[1]); // date
     tableH->setText (tableH->numRows () - 1, 2, row[2]); // type
     tableH->setText (tableH->numRows () - 1, 3, row[3]); // for 
     tableH->setText (tableH->numRows () - 1, 4, row[4]); // price
      
    }
}

void
Form1::newZus ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  pZUS *pWindow = new pZUS;
  if (pWindow->exec () == QDialog::Accepted)
    {
      /*
      tableClear (tableH);
      QDir tmp;
      QString progDir = tmp.homeDirPath () + "/elinux";
      tmp.mkdir (progDir, TRUE);
      readHist (progDir);
      */
      tableH->insertRows (tableH->numRows (), 1);
     QStringList row = QStringList::split( "|",  pWindow->ret );
     tableH->setText (tableH->numRows () - 1, 0, row[0]); // file name
     tableH->setText (tableH->numRows () - 1, 1, row[1]); // date
     tableH->setText (tableH->numRows () - 1, 2, row[2]); // type
     tableH->setText (tableH->numRows () - 1, 3, row[3]); // for 
     tableH->setText (tableH->numRows () - 1, 4, row[4]); // price
      
    }
}

void
Form1::newUs ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  pUS *pWindow = new pUS;
  if (pWindow->exec () == QDialog::Accepted)
    {
      tableH->insertRows (tableH->numRows (), 1);
     QStringList row = QStringList::split( "|",  pWindow->ret );
     tableH->setText (tableH->numRows () - 1, 0, row[0]); // file name
     tableH->setText (tableH->numRows () - 1, 1, row[1]); // date
     tableH->setText (tableH->numRows () - 1, 2, row[2]); // type
     tableH->setText (tableH->numRows () - 1, 3, row[3]); // for 
     tableH->setText (tableH->numRows () - 1, 4, row[4]); // price
    }
}

void Form1::closeEvent (QCloseEvent *e)
{
    if (QMessageBox::
 warning (this, "e-przelewy",
   "Czy chcesz wyj¶æ z programu?", "Tak",
   "Nie", 0, 0, 1) == 0)
    {
 e->accept();
    }
}

void Form1::pomoc()
{
   // KDE
//                if(option.browser == 0) {
                        QStringList args;
                        args += "kfmclient";
                        args += "exec";
   args += "http://www.e-linux.pl/modules/e-przelewy/";
                        QProcess cmd(args);
                        if(!cmd.start()) {
   
   args.clear();
                        args += "gnome-open";
  args += "http://www.e-linux.pl/modules/e-przelewy/";
                        QProcess cmd2(args);
   cmd2.start();
      }
   
   /*
                        if(!cmd.start()) {
                                QMessageBox::critical(0, CAP(QObject::tr("URL error")), QObject::tr( "a" ));                       
       }
                }
                // GNOME 2
                else if(option.browser == 2) {
                        QStringList args;
                        args += "gnome-open";
                        args += url;
                        QProcess cmd(args);
                        if(!cmd.start()) {
                                QMessageBox::critical(0, CAP(QObject::tr("URL error")), QObject::tr("b"));
       }
                }
*/

}
