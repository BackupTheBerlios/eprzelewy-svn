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
#include <qtextcodec.h>
#include <qsettings.h>
#include <qfontdialog.h>


#include <qprinter.h>
#include <qpainter.h>
#include <qpaintdevicemetrics.h>
#include <qimage.h>
#include <qpicture.h>

#include <qdatetime.h>
#include <qdir.h>
#include <qdom.h>
#include <qfont.h>

#include <qmessagebox.h>
#include <qapplication.h>

#include "preview.h"
/*
 QStringList  pOdb1;
 QStringList   pOdb2;
 QStringList   pWal;
 QStringList   pNrrach;
 QStringList   pKwota;
 QStringList   pKsw;
 QStringList   pZlec1;
 QStringList   pZlec2;
 QStringList   pTyt1;
 QStringList   pTyt2;
 int pages;
 bool poziom;
 bool own;
 QFont font;
*/


void
Form7::init ()
{
  QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("ISO8859-2"));
  QTextCodec::setCodecForTr (QTextCodec::codecForName ("ISO8859-2"));
  zastButton->setEnabled (FALSE);
  readSettings ();
}

void
Form7::cosChanged ()
{
  zastButton->setEnabled (TRUE);
}

void
Form7::apply ()
{
  zastButton->setEnabled (FALSE);
  saveSettings ();
}

void
Form7::okButtonClick ()
{
  saveSettings ();
  accept ();
}

void
Form7::saveSettings ()
{
  QSettings settings;
  settings.beginGroup ("przelewy");
  settings.writeEntry ("firstrun", "nie");
 
  settings.writeEntry ("przerwy", spacesSpin->text ()); // zapis String
  settings.writeEntry ("czcionka", fontEdit->text ()); // zapis String
  // checkboxy
  settings.writeEntry ("przelew_wbud", checkBox1->isChecked ());
  settings.writeEntry ("zus_wbud", checkBox2->isChecked ());
  settings.writeEntry ("us_wbud", checkBox3->isChecked ());

  // looop for przelew
  settings.writeEntry ("p_odbiorca1", p1->text ());
  settings.writeEntry ("p_odbiorca2", p2->text ());
  settings.writeEntry ("p_waluta", p3->text ());
  settings.writeEntry ("p_nrrach", p4->text ());
  settings.writeEntry ("p_kwota", p5->text ());
  settings.writeEntry ("p_ksw", p6->text ());
  settings.writeEntry ("p_zlec1", p7->text ());
  settings.writeEntry ("p_zlec2", p8->text ());
  settings.writeEntry ("p_tyt1", p9->text ());
  settings.writeEntry ("p_tyt2", p10->text ());
  settings.writeEntry ("p_wx", p11->text ());
  settings.writeEntry ("p_px", p12->text ());

  // loop for zus
  settings.writeEntry ("z_konto", z1->text ());
  settings.writeEntry ("z_kwota", z2->text ());
  settings.writeEntry ("z_ksw", z3->text ());
  settings.writeEntry ("z_nazwa1", z4->text ());
  settings.writeEntry ("z_nazwa2", z5->text ());
  settings.writeEntry ("z_nip", z6->text ());
  settings.writeEntry ("z_typid", z7->text ());
  settings.writeEntry ("z_id", z8->text ());
  settings.writeEntry ("z_typwp", z9->text ());
  settings.writeEntry ("z_nrdek", z10->text ());
  settings.writeEntry ("z_dek", z11->text ());
  settings.writeEntry ("z_nrdec", z12->text ());
  settings.writeEntry ("z_wx", z13->text ());
  settings.writeEntry ("z_px", z14->text ());  
  
  // loop for us
  settings.writeEntry ("u_nazwa1", u1->text ());
  settings.writeEntry ("u_nazwa2", u2->text ());
  settings.writeEntry ("u_nrrach", u3->text ());
  settings.writeEntry ("u_kwota", u4->text ());
  settings.writeEntry ("u_ksw", u5->text ());
  settings.writeEntry ("u_zlec1", u6->text ());
  settings.writeEntry ("u_zlec2", u7->text ());
  settings.writeEntry ("u_nip", u8->text ());
  settings.writeEntry ("u_id", u9->text ());
  settings.writeEntry ("u_okres", u10->text ());
  settings.writeEntry ("u_symbol", u11->text ());
  settings.writeEntry ("u_idzob", u12->text ());
  settings.writeEntry ("u_wx", u13->text ());
  settings.writeEntry ("u_px", u14->text ());
 /* 
 settings.writeEntry( "user/kod", codeEdit->text() );
 settings.writeEntry( "user/adres", addressEdit->text() );
 settings.writeEntry( "user/konto", accountEdit->text() );
 */
  settings.writeEntry ("przelew_strony", pDruki->currentText ());
  settings.writeEntry ("przelew_widok", pUklad->currentText ());

  settings.writeEntry ("zus_strony", zDruki->currentText ());
  settings.writeEntry ("zus_widok", zUklad->currentText ());

  settings.writeEntry ("us_strony", uDruki->currentText ());
  settings.writeEntry ("us_widok", uUklad->currentText ());

  settings.endGroup ();
}

void
Form7::readSettings ()
{
  QSettings settings;
  /*
     nameEdit->setText( settings.readEntry( "przelewy/user/nazwa" ) );
     placeEdit->setText( settings.readEntry( "przelewy/user/miejscowosc" ) );
     codeEdit->setText( settings.readEntry( "przelewy/user/kod" ) );
     addressEdit->setText( settings.readEntry( "przelewy/user/adres" ) );
     accountEdit->setText( settings.readEntry( "przelewy/user/konto" ) );    
   */
  bool ok;
  settings.readEntry ("przelewy/firstrun", "", &ok);
  if (ok == 0)
    {
      return;
    }

  fontEdit->setText (settings.readEntry ("przelewy/czcionka")); // zapis String

  // checkboxy
  if (settings.readEntry ("przelewy/przelew_wbud") == "true")
    checkBox1->setChecked (TRUE);
  else
    checkBox1->setChecked (FALSE);
  if (settings.readEntry ("przelewy/zus_wbud") == "true")
    checkBox2->setChecked (TRUE);
  else
    checkBox2->setChecked (FALSE);
  if (settings.readEntry ("przelewy/us_wbud") == "true")
    checkBox3->setChecked (TRUE);
  else
    checkBox3->setChecked (FALSE);
  
  spacesSpin->setValue (settings.readEntry ("przelewy/przerwy").toInt());
  rozSp = spacesSpin->text().toInt();
  

  // looop for przelew
  p1->setText (settings.readEntry ("przelewy/p_odbiorca1"));
  p2->setText (settings.readEntry ("przelewy/p_odbiorca2"));
  p3->setText (settings.readEntry ("przelewy/p_waluta"));
  p4->setText (settings.readEntry ("przelewy/p_nrrach"));
  p5->setText (settings.readEntry ("przelewy/p_kwota"));
  p6->setText (settings.readEntry ("przelewy/p_ksw"));
  p7->setText (settings.readEntry ("przelewy/p_zlec1"));
  p8->setText (settings.readEntry ("przelewy/p_zlec2"));
  p9->setText (settings.readEntry ("przelewy/p_tyt1"));
  p10->setText (settings.readEntry ("przelewy/p_tyt2"));
  p11->setText (settings.readEntry ("przelewy/p_wx"));
  p12->setText (settings.readEntry ("przelewy/p_px"));
  

  // loop for zus
  z1->setText (settings.readEntry ("przelewy/z_konto"));
  z2->setText (settings.readEntry ("przelewy/z_kwota"));
  z3->setText (settings.readEntry ("przelewy/z_ksw"));
  z4->setText (settings.readEntry ("przelewy/z_nazwa1"));
  z5->setText (settings.readEntry ("przelewy/z_nazwa2"));
  z6->setText (settings.readEntry ("przelewy/z_nip"));
  z7->setText (settings.readEntry ("przelewy/z_typid"));
  z8->setText (settings.readEntry ("przelewy/z_id"));
  z9->setText (settings.readEntry ("przelewy/z_typwp"));
  z10->setText (settings.readEntry ("przelewy/z_nrdek"));
  z11->setText (settings.readEntry ("przelewy/z_dek"));
  z12->setText (settings.readEntry ("przelewy/z_nrdec"));
  z13->setText (settings.readEntry ("przelewy/z_wx"));
  z14->setText (settings.readEntry ("przelewy/z_px"));

  // loop for us
  u1->setText (settings.readEntry ("przelewy/u_nazwa1"));
  u2->setText (settings.readEntry ("przelewy/u_nazwa2"));
  u3->setText (settings.readEntry ("przelewy/u_nrrach"));
  u4->setText (settings.readEntry ("przelewy/u_kwota"));
  u5->setText (settings.readEntry ("przelewy/u_ksw"));
  u6->setText (settings.readEntry ("przelewy/u_zlec1"));
  u7->setText (settings.readEntry ("przelewy/u_zlec2"));
  u8->setText (settings.readEntry ("przelewy/u_nip"));
  u9->setText (settings.readEntry ("przelewy/u_id"));
  u10->setText (settings.readEntry ("przelewy/u_okres"));
  u11->setText (settings.readEntry ("przelewy/u_symbol"));
  u12->setText (settings.readEntry ("przelewy/u_idzob"));
  u13->setText (settings.readEntry ("przelewy/u_wx"));
  u14->setText (settings.readEntry ("przelewy/u_px"));
/* 
 settings.writeEntry( "user/kod", codeEdit->text() );
 settings.writeEntry( "user/adres", addressEdit->text() );
 settings.writeEntry( "user/konto", accountEdit->text() );
 */
  pDruki->setCurrentText (settings.readEntry ("przelewy/przelew_strony"));
  pUklad->setCurrentText (settings.readEntry ("przelewy/przelew_widok"));

  zDruki->setCurrentText (settings.readEntry ("przelewy/zus_strony"));
  zUklad->setCurrentText (settings.readEntry ("przelewy/zus_widok"));

  uDruki->setCurrentText (settings.readEntry ("przelewy/us_strony"));
  uUklad->setCurrentText (settings.readEntry ("przelewy/us_widok"));

}

void
Form7::getFontDlg ()
{
  bool ok;
  QFont font =
    QFontDialog::getFont (&ok, QFont ("Helvetica [Cronyx]", 12), this);
  if (ok)
    {
      // name mozna parsowac ! :)
      fontEdit->setText (font.toString ());
    }
  else
    {

    }
}

void Form7::pDefaultClick()
{
    p1->setText("-505, 40;-1000, 40;-505, 390;-1000, 390");
    p2->setText("-505, 70;-1000, 70;-505, 420;-1000, 420");
    p4->setText("-505, 105;-1000, 105;-505, 460;-1000, 460"); 
    p11->setText("-380, 135;-875, 135;-380, 490;-875, 490");
    p12->setText("-360, 135;-855, 135;-360, 490;-855, 490");
    p3->setText("-305, 135;-800, 135;-335, 490;-800, 490");
    p5->setText("-250, 135;-730, 135;-245, 490;-740, 490");
    p6->setText("-505, 170;-1000, 170;-505, 520;-1000, 520");
    p7->setText("-505, 200;-1000, 200;-505, 550;-1000, 550");
    p8->setText("-505, 230;-1000, 230;-505, 580;-1000, 580");
    p9->setText("-505, 260;-1000, 260;-505, 610;-1000, 610");
    p10->setText(" ");
    pDruki->setCurrentText("4");
    pUklad->setCurrentText("poziomy");
    checkBox1->setChecked(TRUE);
    cosChanged();
}

void Form7::pDefaultClick2()
{
p1->setText("35,31;160,650;");
p2->setText("35,68;160,685;");
p4->setText("35,105;160,715;");
p11->setText("210,140;325,745");
p12->setText("230,140;345,745;");
p3->setText("298,140;413,745;");
p5->setText("355,140;463,745;");
p6->setText("35,175;160,780;");
p7->setText("35,205;160,815;");
p8->setText("35,240;160,850;");
p9->setText("35,300;160,885;");

    p10->setText(" ");
    pDruki->setCurrentText("2");
    // pUklad->setCurrentText("poionowy");
    checkBox1->setChecked(FALSE);
    cosChanged();
}


void Form7::zDefaultClick()
{
    z1->setText("130,230;130,695;");
    z13->setText("265,263;265,730;");
    z14->setText("285,263;285,730;");
    z2->setText("390,265;390,730;");
    z3->setText("130,295;130,765;");
    z4->setText("130,325;130,800;");
    z5->setText("130,363;130,835;");
    z6->setText("130,398;130,865;");
    z7->setText("322,398;322,865;");
    z8->setText("430,398;430,865;");
    z9->setText("130,432;130,895;");
    z10->setText("170,432;170,895;");
    z11->setText("230,432;230,895;");
    z12->setText("340,432;340,895;");
    zDruki->setCurrentText("2");
    zUklad->setCurrentText("pionowy");
    checkBox2->setChecked(TRUE);
    cosChanged();
}

void Form7::uDefaultClick()
{
    u1->setText("140,135;140,660;");
    u2->setText("140,170;140,700;");
    u3->setText("135,200;140,730;");
    u13->setText("268,240;268,768;");
    u14->setText("288,240;288,768;");
    u4->setText("400,240;400,763;");
    u5->setText("140,270;140,800;");
    u6->setText("140,310;140,835;");
    u7->setText("140,340;140,870;");
    u8->setText("140,380;140,905;");
    u9->setText("392,380;392,905;");
    u10->setText("468,380;468,905;");
    u11->setText("140,410;140,940;");
    u12->setText("260,410;260,940;");
    uDruki->setCurrentText("2");
    uUklad->setCurrentText("pionowy");
    checkBox3->setChecked(TRUE);
    cosChanged();
}


void
Form7::abcDefaultClick()
{
    if (tabWidget2->currentPageIndex() == 0) {
    }
    
    if (tabWidget2->currentPageIndex() == 1) {
 if ( pUklad->currentItem() == 0)
     // qDebug("poziom");
 pDefaultClick();
 else
//     qDebug("pion");
     pDefaultClick2();
     
 
 if (checkBox1->isChecked()) {
     pDruki->setEnabled(false);
     pUklad->setEnabled(false);
 } else {
     pDruki->setEnabled(true);
     pUklad->setEnabled(true);
 }
    }
    
    if (tabWidget2->currentPageIndex() == 2) {
 zDefaultClick();
 if (checkBox2->isChecked()) {
     zDruki->setEnabled(false);
     zUklad->setEnabled(false);
 } else {
     zDruki->setEnabled(true);
     zUklad->setEnabled(true);
 }
    }
    
    if (tabWidget2->currentPageIndex() == 3) {
 uDefaultClick();
 if (checkBox3->isChecked()) {
     uDruki->setEnabled(false);
     uUklad->setEnabled(false);
 } else {
     uDruki->setEnabled(true);
     uUklad->setEnabled(true);
 }
    }
    
}


int
Form7::getXSett (QString in)
{
  int x = in.find (',');
  // int y = in.length();
  // qDebug( in.left(x) );
  // qDebug( in.right(y - (x + 1)) );
  return in.left (x).toInt ();
}

int
Form7::getYSett (QString in)
{
  int x = in.find (',');
  int y = in.length ();
  // qDebug( in.left(x) );
  // qDebug( in.right(y - (x + 1)) );
  return in.right (y - (x + 1)).toInt ();
}



void
Form7::readSettingsPrzelew ()
{
  QSettings settings;
  rozSp = settings.readEntry ("przelewy/przerwy").toInt();
  
  font.fromString (settings.readEntry ("przelewy/czcionka"));
  pOdb1 =
    QStringList::split (";", settings.readEntry ("przelewy/p_odbiorca1"));
  pOdb2 =
    QStringList::split (";", settings.readEntry ("przelewy/p_odbiorca2"));
  pWal = QStringList::split (";", settings.readEntry ("przelewy/p_waluta"));
  pNrrach =
    QStringList::split (";", settings.readEntry ("przelewy/p_nrrach"));
  pKwota = QStringList::split (";", settings.readEntry ("przelewy/p_kwota"));
  pKsw = QStringList::split (";", settings.readEntry ("przelewy/p_ksw"));
  pZlec1 = QStringList::split (";", settings.readEntry ("przelewy/p_zlec1"));
  pZlec2 = QStringList::split (";", settings.readEntry ("przelewy/p_zlec2"));
  pTyt1 = QStringList::split (";", settings.readEntry ("przelewy/p_tyt1"));
  pTyt2 = QStringList::split (";", settings.readEntry ("przelewy/p_tyt2"));
  pWx =  QStringList::split (";", settings.readEntry ("przelewy/p_wx"));
  pPx =  QStringList::split (";", settings.readEntry ("przelewy/p_px"));
  pages = settings.readEntry ("przelewy/przelew_strony").toInt ();
  if (settings.readEntry ("przelewy/przelew_widok").compare ("poziomy") == 0)
    poziom = true;
  else
    poziom = false;
  if (settings.readEntry ("przelewy/przelew_wbud").compare ("true") == 0)
    own = false;
  else
    own = true;

}


QString
Form7::rozstrzel (QString in)
{
  QString tmp, out;
  switch ( rozSp ) {
  case 0: 
      tmp = in.replace ("-", "");
      break; 
  case 1: 
      tmp = in.replace ("-", " ");
      break; 
  case 2: 
      tmp = in.replace ("-", "  ");
      break; 
  case 3: 
      tmp = in.replace ("-", "   ");
      break; 
  case 4: 
      tmp = in.replace ("-", "    ");
      break; 
  case 5: 
      tmp = in.replace ("-", "     ");
      break; 
  }
  
  int x = tmp.length ();
  for (int i = 0; i < x; ++i)
    out += tmp[i] + " ";
  return out;
}


QPixmap
Form7::getPrzelewP ()
{

  readSettingsPrzelew ();
  QPixmap pix;
  QPrinter printer;
  printer.setFullPage (TRUE);
  // if (printer.setup(this)) {

  QPainter a (&printer);
  if (!a.device ())
    return NULL;
  QPaintDeviceMetrics metrics1 (a.device ());
  int dpix1 = metrics1.logicalDpiX ();
  int dpiy1 = metrics1.logicalDpiY ();
  const int margin1 = 0; // pt
  QRect body1 (margin1 * dpix1 / 72, margin1 * dpiy1 / 72,
        metrics1.width () - margin1 * dpix1 / 72 * 2,
        metrics1.height () - margin1 * dpiy1 / 72 * 2);
  pix.resize (body1.width (), body1.height ());
  //    = new QPixmap
//}

  QPainter p (&pix);
  if (!p.device ())
    return NULL;
  QPaintDeviceMetrics metrics (p.device ());
  int dpix = metrics.logicalDpiX ();
  int dpiy = metrics.logicalDpiY ();
  const int margin = 0;  // pt
  QRect body (margin * dpix / 72, margin * dpiy / 72,
       metrics.width () - margin * dpix / 72 * 2,
       metrics.height () - margin * dpiy / 72 * 2);
  QRect view (body);

  if (!own)
    {
     QDir abs(qApp->argv()[0]);
     QString graphDir;
      if ( QString(qApp->argv()[0]).left(2) == "./" )
            graphDir = abs.absPath();
           else
             graphDir = "/usr/bin/eprzelewy";
      

      graphDir = graphDir.replace( "bin/eprzelewy", "share/eprzelewy");
      QImage *img = new QImage (graphDir + "/druki/standard.png");
      p.drawImage (view, *img);
    }
  else
    {
      p.setBrush (QBrush (white, Qt::SolidPattern));
      p.setPen( Qt::white );
      p.drawRect (view);
      p.setPen( Qt::black );
    }


  p.setBrush (QBrush (white, Qt::SolidPattern));

  QFont serifFont ("Arial", 12, 75);
  QFont sansFont ("Helvetica [Cronyx]", 12);
  p.setFont (font);

      // przelew 1
      if (poziom)
 p.rotate (-90);
      int i, j;
      for (i = 1; i <= pages; ++i)
 {
   j = i - 1;
   p.drawText (getXSett (pOdb1[j]), getYSett (pOdb1[j]), "Jan Kowalski"); // nazwa odb1.
   p.drawText (getXSett (pOdb2[j]), getYSett (pOdb2[j]), "00-000 Warszawa, Burakowska 1/100"); // adres miasto odb1.
   p.drawText (getXSett (pNrrach[j]), getYSett (pNrrach[j]), rozstrzel ("11-1111-1111-1111-1111-1111-1111"));
   p.drawText (getXSett (pPx[j]), getYSett (pPx[j]), "X"); // robimy przelew na podglad
   p.drawText (getXSett (pWx[j]), getYSett (pWx[j]), "X"); // robimy przelew na podglad
   p.drawText (getXSett (pWal[j]), getYSett (pWal[j]), "PLN");
   p.drawText (getXSett (pKwota[j]), getYSett (pKwota[j]), "5500,00");
   p.drawText (getXSett (pKsw[j]), getYSett (pKsw[j]), rozstrzel ("22-222-2222-2222-2222-2222-2222")); // nazwa odb1.
   p.drawText (getXSett (pZlec1[j]), getYSett (pZlec1[j]), "Artur Nowak sp. z o.o."); // nazwa odb1.
   p.drawText (getXSett (pZlec2[j]), getYSett (pZlec2[j]), "11-111 Krakow, Piastowska 100/1"); // nazwa odb1.
   p.drawText (getXSett (pTyt1[j]), getYSett (pTyt1[j]), "Op³ata za t³umik"); // nazwa odb1.
 }

  p.translate (0, -body.height ());

  p.end ();
  pix.save ("/tmp/przelew.png", "PNG");
  return pix;
}


/*
QStringList  z_dek
QStringList  z_id;
QStringList  z_konto;
QStringList  z_ksw;
QStringList  z_kwota;
QStringList  z_nazwa1;
QStringList  z_nazwa2;
QStringList  z_nip;
QStringList  z_nrdec;
QStringList  z_nrdek;
QStringList  z_typid;
QStringList  z_typwp;
*/

void
Form7::readSettingsZ ()
{
  QSettings settings;
  font.fromString (settings.readEntry ("przelewy/czcionka"));
  rozSp = settings.readEntry ("przelewy/przerwy").toInt();

  z_dek = QStringList::split (";", settings.readEntry ("przelewy/z_dek"));
  z_id = QStringList::split (";", settings.readEntry ("przelewy/z_id"));
  z_konto = QStringList::split (";", settings.readEntry ("przelewy/z_konto"));
  z_ksw = QStringList::split (";", settings.readEntry ("przelewy/z_ksw"));
  zWx = QStringList::split (";", settings.readEntry ("przelewy/z_wx"));
  zPx = QStringList::split (";", settings.readEntry ("przelewy/z_px"));
  z_kwota = QStringList::split (";", settings.readEntry ("przelewy/z_kwota"));
  z_nazwa1 =
    QStringList::split (";", settings.readEntry ("przelewy/z_nazwa1"));
  z_nazwa2 =
    QStringList::split (";", settings.readEntry ("przelewy/z_nazwa2"));
  z_nip = QStringList::split (";", settings.readEntry ("przelewy/z_nip"));
  z_nrdec = QStringList::split (";", settings.readEntry ("przelewy/z_nrdec"));
  z_nrdek = QStringList::split (";", settings.readEntry ("przelewy/z_nrdek"));
  z_typid = QStringList::split (";", settings.readEntry ("przelewy/z_typid"));
  z_typwp = QStringList::split (";", settings.readEntry ("przelewy/z_typwp"));

  pages = settings.readEntry ("przelewy/zus_strony").toInt ();
  if (settings.readEntry ("przelewy/zus_widok").compare ("poziomy") == 0)
    poziom = true;
  else
    poziom = false;

  if (settings.readEntry ("przelewy/zus_wbud").compare ("true") == 0)
    own = false;
  else
    own = true;

}


QPixmap
Form7::getPrzelewZ ()
{

  readSettingsZ ();
  QPixmap pix;
  QPrinter printer;
  printer.setFullPage (TRUE);
  // if (printer.setup(this)) {

  QPainter a (&printer);
  if (!a.device ())
    return NULL;
  QPaintDeviceMetrics metrics1 (a.device ());
  int dpix1 = metrics1.logicalDpiX ();
  int dpiy1 = metrics1.logicalDpiY ();
  const int margin1 = 0; // pt
  QRect body1 (margin1 * dpix1 / 72, margin1 * dpiy1 / 72,
        metrics1.width () - margin1 * dpix1 / 72 * 2,
        metrics1.height () - margin1 * dpiy1 / 72 * 2);
  pix.resize (body1.width (), body1.height ());
  //    = new QPixmap
//}

  QPainter p (&pix);
  if (!p.device ())
    return NULL;
  QPaintDeviceMetrics metrics (p.device ());
  int dpix = metrics.logicalDpiX ();
  int dpiy = metrics.logicalDpiY ();
  const int margin = 0;  // pt
  QRect body (margin * dpix / 72, margin * dpiy / 72,
       metrics.width () - margin * dpix / 72 * 2,
       metrics.height () - margin * dpiy / 72 * 2);
  QRect view (body);

  if (!own)
    {
      QDir abs(qApp->argv()[0]);
       QString graphDir;
          if ( QString(qApp->argv()[0]).left(2) == "./" )
            graphDir = abs.absPath();
                 else
             graphDir = "/usr/bin/eprzelewy";
      

      graphDir = graphDir.replace( "bin/eprzelewy", "share/eprzelewy");
      QImage *img = new QImage ( graphDir + "/druki/zus.png");
      p.drawImage (view, *img);
    }
  else
    {
      p.setBrush (QBrush (white, Qt::SolidPattern));
      p.setPen( Qt::white );
      p.drawRect (view);
      p.setPen( Qt::black );
    }


  p.setBrush (QBrush (white, Qt::SolidPattern));

  QFont serifFont ("Arial", 12, 75);
  QFont sansFont ("Helvetica [Cronyx]", 12);
  p.setFont (font);

      // przelew 1
      if (poziom)
 p.rotate (-90);
      int i, j;
      for (i = 1; i <= pages; ++i)
 {
   j = i - 1;
   p.drawText (getXSett (z_konto[j]), getYSett (z_konto[j]),  rozstrzel ("11-1111-1111-1111-1111-1111-1111"));
   p.drawText (getXSett (zPx[j]), getYSett (zPx[j]), "X");
   p.drawText (getXSett (zWx[j]), getYSett (zWx[j]), "X");
   p.drawText (getXSett (z_kwota[j]), getYSett (z_kwota[j]), "5500,00");
   p.drawText (getXSett (z_ksw[j]), getYSett (z_ksw[j]), rozstrzel ("22-2222-2222-2222-2222-2222-2222")); 
   p.drawText (getXSett (z_nazwa1[j]), getYSett (z_nazwa1[j]), "Jan Kowalski sp. z o.o."); 
   p.drawText (getXSett (z_nazwa2[j]), getYSett (z_nazwa2[j]), "00-000 Warszawa, ul. Burakowska 1/100");
   p.drawText (getXSett (z_nip[j]), getYSett (z_nip[j]), "000-00-00-000"); 
   p.drawText (getXSett (z_typid[j]), getYSett (z_typid[j]), "N");
   p.drawText (getXSett (z_id[j]), getYSett (z_id[j]),  "000000000");
   p.drawText (getXSett (z_typwp[j]), getYSett (z_typwp[j]),  "S");
   p.drawText (getXSett (z_nrdek[j]), getYSett (z_nrdek[j]),  "01");
   p.drawText (getXSett (z_dek[j]), getYSett (z_dek[j]), "01 2000");
   p.drawText (getXSett (z_nrdec[j]), getYSett (z_nrdec[j]),  "AA/BB/CC/2005");
 }

  p.translate (0, -body.height ());

  p.end ();
  pix.save ("/tmp/przelew.png", "PNG");
  return pix;
}

/*
QStringList    u_id;
QStringList    u_idzob;
QStringList    u_ksw;
QStringList    u_kwota;
QStringList    u_nazwa1;
QStringList    u_nazwa2;
QStringList    u_nip;
QStringList    u_nrrach;
QStringList    u_okres;
QStringList    u_symbol;
QStringList    u_zlec1;
QStringList    u_zlec2;
*/

void Form7::readSettingsU ()
{
  QSettings settings;
  font.fromString (settings.readEntry ("przelewy/czcionka"));
  rozSp = settings.readEntry ("przelewy/przerwy").toInt();
  
  u_id = QStringList::split (";", settings.readEntry ("przelewy/u_id"));
  u_idzob = QStringList::split (";", settings.readEntry ("przelewy/u_idzob"));
  u_ksw = QStringList::split (";", settings.readEntry ("przelewy/u_ksw"));
  uWx = QStringList::split (";", settings.readEntry ("przelewy/u_wx"));
  uPx = QStringList::split (";", settings.readEntry ("przelewy/u_px"));
  u_kwota = QStringList::split (";", settings.readEntry ("przelewy/u_kwota"));
  u_nazwa1 =
    QStringList::split (";", settings.readEntry ("przelewy/u_nazwa1"));
  u_nazwa2 =
    QStringList::split (";", settings.readEntry ("przelewy/u_nazwa2"));
  u_nip = QStringList::split (";", settings.readEntry ("przelewy/u_nip"));
  u_nrrach =
    QStringList::split (";", settings.readEntry ("przelewy/u_nrrach"));
  u_okres = QStringList::split (";", settings.readEntry ("przelewy/u_okres"));
  u_symbol =
    QStringList::split (";", settings.readEntry ("przelewy/u_symbol"));
  u_zlec1 = QStringList::split (";", settings.readEntry ("przelewy/u_zlec1"));
  u_zlec2 = QStringList::split (";", settings.readEntry ("przelewy/u_zlec2"));

  pages = settings.readEntry ("przelewy/us_strony").toInt ();
  if (settings.readEntry ("przelewy/us_widok").compare ("poziomy") == 0)
    poziom = true;
  else
    poziom = false;

  if (settings.readEntry ("przelewy/us_wbud").compare ("true") == 0)
    own = false;
  else
    own = true;
}



QPixmap Form7::getPrzelewU ()
{

  readSettingsU ();
  QPixmap pix;
  QPrinter printer;
  printer.setFullPage (TRUE);
  // if (printer.setup(this)) {

  QPainter a (&printer);
  if (!a.device ())
    return NULL;
  QPaintDeviceMetrics metrics1 (a.device ());
  int dpix1 = metrics1.logicalDpiX ();
  int dpiy1 = metrics1.logicalDpiY ();
  const int margin1 = 0; // pt
  QRect body1 (margin1 * dpix1 / 72, margin1 * dpiy1 / 72,
        metrics1.width () - margin1 * dpix1 / 72 * 2,
        metrics1.height () - margin1 * dpiy1 / 72 * 2);
  pix.resize (body1.width (), body1.height ());
  //    = new QPixmap
//}

  QPainter p (&pix);
  if (!p.device ())
    return NULL;
  QPaintDeviceMetrics metrics (p.device ());
  int dpix = metrics.logicalDpiX ();
  int dpiy = metrics.logicalDpiY ();
  const int margin = 0;  // pt
  QRect body (margin * dpix / 72, margin * dpiy / 72,
       metrics.width () - margin * dpix / 72 * 2,
       metrics.height () - margin * dpiy / 72 * 2);
  QRect view (body);


  if (!own)
    {
      QDir abs(qApp->argv()[0]);
      QString graphDir;
      if ( QString(qApp->argv()[0]).left(2) == "./" )
            graphDir = abs.absPath();
                 else
                 graphDir = "/usr/bin/eprzelewy";
      
      graphDir = graphDir.replace( "bin/eprzelewy", "share/eprzelewy");
      QImage *img = new QImage (graphDir + "/druki/us.png");
      p.drawImage (view, *img);
    }
  else
    {
      p.setBrush (QBrush (white, Qt::SolidPattern));
      p.setPen( Qt::white );
      p.drawRect (view);
      p.setPen( Qt::black );
    }


  p.setFont (font);

      // przelew 1
      if (poziom)
 p.rotate (-90);
      int i, j;
      for (i = 1; i <= pages; ++i)
 {
   j = i - 1;
   p.drawText (getXSett (u_nrrach[j]), getYSett (u_nrrach[j]), rozstrzel ("11-1111-1111-1111-1111-1111-1111"));
   p.drawText (getXSett (u_nazwa1[j]), getYSett (u_nazwa1[j]), "Urz±d Skarbowy w Warszawie");
   p.drawText (getXSett (u_nazwa2[j]), getYSett (u_nazwa2[j]), "00-000 Warszawa, ul. Zamkowa 10");
   p.drawText (getXSett (uPx[j]), getYSett (uPx[j]), "X"); // przelew
   p.drawText (getXSett (uWx[j]), getYSett (uWx[j]), "X"); // wplata
   p.drawText (getXSett (u_kwota[j]), getYSett (u_kwota[j]), "5500,00");
   p.drawText (getXSett (u_ksw[j]), getYSett (u_ksw[j]),  rozstrzel ("22-2222-2222-2222-2222-2222-2222"));
   p.drawText (getXSett (u_zlec1[j]), getYSett (u_zlec1[j]), "Jan Kowalski sp. z o.o.");
   p.drawText (getXSett (u_zlec2[j]), getYSett (u_zlec2[j]), "11-111 Krakow, ul. Zakamarkowa 10");
   p.drawText (getXSett (u_nip[j]), getYSett (u_nip[j]), "000-00-00-000");
   p.drawText (getXSett (u_id[j]), getYSett (u_id[j]), "N");
   p.drawText (getXSett (u_okres[j]), getYSett (u_okres[j]),  "05   M   02   02");
   p.drawText (getXSett (u_symbol[j]), getYSett (u_symbol[j]), "PIT 35");
   p.drawText (getXSett (u_idzob[j]), getYSett (u_idzob[j]),  "AA/BB/CC/2005");

 }
  p.translate (0, -body.height ());

  p.end ();
  pix.save ("/tmp/przelew.png", "PNG");
  return pix;
}


void Form7::pPriviewClick()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  getPrzelewP ();
  preview *ppp = new preview ();
  ppp->exec ();
}

void Form7::zPriviewClick()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  getPrzelewZ ();
  preview *ppp = new preview ();
  ppp->exec ();
}

void Form7::uPriviewClick()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  getPrzelewU();
  preview *ppp = new preview ();
  ppp->exec ();
}

void Form7::abcPreviewClick()
{
    if (tabWidget2->currentPageIndex() == 0) {
 QMessageBox::information(0, "e-Przelewy",
           "Aby obejrzeæ pogl±d musisz zmieniæ zak³adkê np. Przelew.");
    }
    
    if (tabWidget2->currentPageIndex() == 1) {
 pPriviewClick();
    }
    
    if (tabWidget2->currentPageIndex() == 2) {
 zPriviewClick();
    }
    
    if (tabWidget2->currentPageIndex() == 3) {
 uPriviewClick();
    }
}

void 
Form7::tabChanged(QWidget *aaa)
{
    
    if (tabWidget2->indexOf(aaa) == 0) {
 
    }
    
    if (tabWidget2->indexOf(aaa) == 1) {
 if (checkBox1->isChecked()) {
     pDruki->setEnabled(false);
     pUklad->setEnabled(false);
 } else {
     pDruki->setEnabled(true);
     pUklad->setEnabled(true);
 }
    }
    
    if (tabWidget2->indexOf(aaa) == 2) {
 if (checkBox2->isChecked()) {
     zDruki->setEnabled(false);
     zUklad->setEnabled(false);
 } else {
     zDruki->setEnabled(true);
     zUklad->setEnabled(true);
 }
    }
    
    if (tabWidget2->indexOf(aaa) == 3) {
 if (checkBox3->isChecked()) {
     uDruki->setEnabled(false);
     uUklad->setEnabled(false);
 } else {
     uDruki->setEnabled(true);
     uUklad->setEnabled(true);
 }
    }
    
}
