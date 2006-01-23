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
#include <qsettings.h>
#include <qtextcodec.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qpaintdevicemetrics.h>
#include <qsimplerichtext.h>
#include <qimage.h>

#include <qpicture.h>

#include <qdatetime.h>
#include <qdir.h>
#include <qdom.h>
#include <qfont.h>

#include <qapplication.h>


#include "preview.h"

#include "slownie.h"

QString progDir2;
// QString fileName;

QStringList p_Px;
QStringList p_Wx;

void
Form6::readData ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  QDomDocument doc ("przelewy");
  QDomElement root;
  QDomElement nadawca;
  QDomElement odbiorca;

  QFile file (progDir2 + "/przelewy/" + fileName);

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
  qDebug ("fileName " + fileName);
  root = doc.documentElement ();
  // root.attribute("date", "");
  comboBox1->setCurrentText (root.attribute ("typ", ""));
  kwotaEdit->setText (root.attribute ("kwota", ""));
  lineEdit17->setText (root.attribute ("title", ""));

  nadawca = root.firstChild ().toElement ();
  odbiorca = root.lastChild ().toElement ();
  // nadawca.attribute("name", "NULL"));

  nameEdit->setText (nadawca.attribute ("name", ""));
  codeEdit->setText (nadawca.attribute ("code", ""));
  placeEdit->setText (nadawca.attribute ("place", ""));
  addressEdit->setText (nadawca.attribute ("address", ""));
  accountEdit->setText (nadawca.attribute ("account", ""));

  nameEdit2->setText (odbiorca.attribute ("name", ""));
  codeEdit2->setText (odbiorca.attribute ("code", ""));
  placeEdit2->setText (odbiorca.attribute ("place", ""));
  addressEdit2->setText (odbiorca.attribute ("address", ""));
  accountEdit2->setText (odbiorca.attribute ("account", ""));
  qDebug ("fileName " + fileName);
}


void
Form6::init ()
{
  QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("ISO8859-2"));
  QTextCodec::setCodecForTr (QTextCodec::codecForName ("ISO8859-2"));

  QSettings settings;
  nameEdit->setText (settings.readEntry ("przelewy/user/nazwa"));
  placeEdit->setText (settings.readEntry ("przelewy/user/miejscowosc"));
  codeEdit->setText (settings.readEntry ("przelewy/user/kod"));
  addressEdit->setText (settings.readEntry ("przelewy/user/adres"));
  accountEdit->setText (settings.readEntry ("przelewy/user/konto"));
  progDir2 = QDir::homeDirPath () + "/elinux";
}

void
Form6::slownieBtnClick()
{
    slownieLbl->setText ( slownie(kwotaEdit->text ()) );
}

/*!
  *    Special Method for account display
  !*/
QString
Form6::rozstrzel (QString in)
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

void
Form6::kwotaKeyDown ()
{
  if (comboBox1->currentItem () == 1)
    {
    slownieLbl->setText ( slownie(kwotaEdit->text ()) );
}
}

void
Form6::makeWplata ()
{
    slownieLbl->setText ( slownie(kwotaEdit->text ()) );
    
/*  
  // nie zawsze jest wplata wlasna!!!
  nameEdit2->setText (nameEdit->text ());
  codeEdit2->setText (codeEdit->text ());
  placeEdit2->setText (placeEdit->text ());
  addressEdit2->setText (addressEdit->text ());
  accountEdit2->setText (accountEdit->text ());
  */
}

int
Form6::getXSett (QString in)
{
  int x = in.find (',');
  // int y = in.length();
  // qDebug( in.left(x) );
  // qDebug( in.right(y - (x + 1)) );
  return in.left (x).toInt ();
}

int
Form6::getYSett (QString in)
{
  int x = in.find (',');
  int y = in.length ();
  // qDebug( in.left(x) );
  // qDebug( in.right(y - (x + 1)) );
  return in.right (y - (x + 1)).toInt ();
}

void
Form6::readSettings ()
{
  QSettings settings;
  
  font.fromString (settings.readEntry ("przelewy/czcionka"));
  rozSp = settings.readEntry ("przelewy/przerwy").toInt();
  
  /*
     // checkboxy
     if ( settings.readEntry( "przelewy/przelew_wbud" ) == "true" )
     checkBox1->setChecked( TRUE );
     if (  settings.readEntry( "przelewy/zus_wbud" ) == "true" )
     checkBox2->setChecked(  TRUE );
     if (   settings.readEntry( "przelewy/us_wbud" ) == "true" )
     checkBox3->setChecked( TRUE  );
   */
  // looop for przelew
  pOdb1 =
    QStringList::split (";", settings.readEntry ("przelewy/p_odbiorca1"));
  pOdb2 =
    QStringList::split (";", settings.readEntry ("przelewy/p_odbiorca2"));
  pWal = QStringList::split (";", settings.readEntry ("przelewy/p_waluta"));
  p_Px =  QStringList::split (";", settings.readEntry ("przelewy/p_px"));
  p_Wx =  QStringList::split (";", settings.readEntry ("przelewy/p_wx"));
  pNrrach =
    QStringList::split (";", settings.readEntry ("przelewy/p_nrrach"));
  pKwota = QStringList::split (";", settings.readEntry ("przelewy/p_kwota"));
  pKsw = QStringList::split (";", settings.readEntry ("przelewy/p_ksw"));
  pZlec1 = QStringList::split (";", settings.readEntry ("przelewy/p_zlec1"));
  pZlec2 = QStringList::split (";", settings.readEntry ("przelewy/p_zlec2"));
  pTyt1 = QStringList::split (";", settings.readEntry ("przelewy/p_tyt1"));
  pTyt2 = QStringList::split (";", settings.readEntry ("przelewy/p_tyt2"));
  pages = settings.readEntry ("przelewy/przelew_strony").toInt ();
  if (settings.readEntry ("przelewy/przelew_widok").compare ("poziomy") == 0)
    poziom = true;
  else
    poziom = false;
  if (settings.readEntry ("przelewy/przelew_wbud").compare ("true") == 0)
    own = false;
  else
    own = true;

  /*
     // loop for zus
     z1->setText(  settings.readEntry( "przelewy/z_konto") );
     z2->setText(   settings.readEntry( "przelewy/z_kwota") );
     z3->setText(   settings.readEntry( "przelewy/z_ksw") );
     z4->setText(   settings.readEntry( "przelewy/z_nazwa1") );
     z5->setText(   settings.readEntry( "przelewy/z_nazwa2") );
     z6->setText(   settings.readEntry( "przelewy/z_nip") );
     z7->setText(   settings.readEntry( "przelewy/z_typid") );
     z8->setText(   settings.readEntry( "przelewy/z_id") );
     z9->setText(   settings.readEntry( "przelewy/z_typwp") );
     z10->setText(   settings.readEntry( "przelewy/z_nrdek") );
     z11->setText(   settings.readEntry( "przelewy/z_dek") );
     z12->setText(   settings.readEntry( "przelewy/z_nrdec") );

     // loop for us
     u1->setText( settings.readEntry( "przelewy/u_nazwa1") );
     u2->setText(  settings.readEntry( "przelewy/u_nazwa2") );
     u3->setText(  settings.readEntry( "przelewy/u_nrrach") );
     u4->setText(  settings.readEntry( "przelewy/u_kwota") );
     u5->setText(  settings.readEntry( "przelewy/u_ksw") );
     u6->setText(  settings.readEntry( "przelewy/u_zlec1") );
     u7->setText(  settings.readEntry( "przelewy/u_zlec2") );
     u8->setText(  settings.readEntry( "przelewy/u_nip") );
     u9->setText(  settings.readEntry( "przelewy/u_id") );
     u10->setText(  settings.readEntry( "przelewy/u_okres") );
     u11->setText(  settings.readEntry( "przelewy/u_symbol") );
     u12->setText(  settings.readEntry( "przelewy/u_idzob") ); 
   */
/* 
 settings.writeEntry( "user/kod", codeEdit->text() );
 settings.writeEntry( "user/adres", addressEdit->text() );
 settings.writeEntry( "user/konto", accountEdit->text() );
 */
/*
pDruki->setCurrentText( settings.readEntry( "przelewy/przelew_strony") );
pUklad->setCurrentText(  settings.readEntry( "przelewy/przelew_widok") );

zDruki->setCurrentText(  settings.readEntry( "przelewy/zus_strony") );
zUklad->setCurrentText(  settings.readEntry( "przelewy/zus_widok") );
 
uDruki->setCurrentText(  settings.readEntry( "przelewy/us_strony") );
uUklad->setCurrentText(  settings.readEntry( "przelewy/us_widok") );
  */
}


void
Form6::saveXML ()
{

  QDomDocument doc ("przelewy");
  QDomElement root;
  QDomElement nadawca;  // urzad    
  QDomElement odbiorca;  // firma;    
  QString fileName, fn2;
  fileName = QDate::currentDate ().toString ("dd-MM-yyyy");

  qDebug (fileName);

  int pNumber = 0;
  fn2 = "h" + fileName + "_" + QString::number (pNumber) +  ".xml";
  QFile file (progDir2 + "/przelewy/h" + fileName + "_" + QString::number (pNumber) +
       ".xml");
  pNumber += 1;

  while (file.exists ())
    {
      fn2 = "h" + fileName + "_" + QString::number (pNumber) +  ".xml";
      file.setName (progDir2 + "/przelewy/h" + fileName + "_" +
      QString::number (pNumber) + ".xml");
      pNumber += 1;
    }

  if (!file.open (IO_ReadOnly))
    {
      root = doc.createElement ("przelew");
      root.setAttribute ("typ", comboBox1->currentText ());
      root.setAttribute ("date",
    QDate::currentDate ().toString ("dd-MM-yyyy"));
      root.setAttribute ("kwota", kwotaEdit->text ());
      root.setAttribute ("title", lineEdit17->text ());


      doc.appendChild (root);

      qDebug ("can not open ");
      nadawca = doc.createElement ("nadawca");
      nadawca.setAttribute ("name", nameEdit->text ());
      nadawca.setAttribute ("place", placeEdit->text ());
      nadawca.setAttribute ("code", codeEdit->text ());
      nadawca.setAttribute ("address", addressEdit->text ());
      nadawca.setAttribute ("account", accountEdit->text ());
      root.appendChild (nadawca);

      odbiorca = doc.createElement ("odbiorca");
      odbiorca.setAttribute ("name", nameEdit2->text ());
      odbiorca.setAttribute ("place", placeEdit2->text ());
      odbiorca.setAttribute ("code", codeEdit2->text ());
      odbiorca.setAttribute ("address", addressEdit2->text ());
      odbiorca.setAttribute ("account", accountEdit2->text ());
      root.appendChild (odbiorca);

    }



  QString xml = doc.toString ();
  file.close ();
  file.open (IO_WriteOnly);
  QTextStream ts (&file);
  ts << xml;
  file.close ();

 QString tmp1 = nameEdit2->text();
 if (tmp1 == "") tmp1 = "-";
 QString kwt = kwotaEdit->text();
 if ( kwt == "" ) kwt = "-";
  
    ret = fn2 + "|" + QDate::currentDate ().toString ("dd-MM-yyyy") + "|" +
	comboBox1->currentText() + "|" + tmp1 + "|" + kwt;
  

}

QPixmap
Form6::getPrzelew ()
{

  readSettings ();
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
  /*
     QFont font(textEdit1->font());
     QSimpleRichText richText(textEdit1->text(), font, 
     textEdit1->context(),
     textEdit1->styleSheet(),
     textEdit1->mimeSourceFactory(),
     body.height());
     richText.setWidth(&p, body.width());
   */
  QRect view (body);
  // int page = 1;


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

  if (comboBox1->currentItem () == 0)
    {
      // przelew 1
      if (poziom)
 p.rotate (-90);
      int i, j;
      for (i = 1; i <= pages; ++i)
 {
   j = i - 1;
   p.drawText (getXSett (pOdb1[j]), getYSett (pOdb1[j]), nameEdit2->text ()); // nazwa odb1.
   p.drawText (getXSett (pOdb2[j]), getYSett (pOdb2[j]), codeEdit2->text () + " " + placeEdit2->text () + ", " + addressEdit2->text ()); // adres miasto odb1.
   p.drawText (getXSett (pNrrach[j]), getYSett (pNrrach[j]),
        rozstrzel (accountEdit2->text ()));
             p.drawText (getXSett (p_Px[j]), getYSett (p_Px[j]), "X");
   p.drawText (getXSett (pWal[j]), getYSett (pWal[j]), "PLN");
   p.drawText (getXSett (pKwota[j]), getYSett (pKwota[j]),
        kwotaEdit->text ());
   p.drawText (getXSett (pKsw[j]), getYSett (pKsw[j]), rozstrzel (accountEdit->text ())); // nazwa odb1.
   p.drawText (getXSett (pZlec1[j]), getYSett (pZlec1[j]), nameEdit->text ()); // nazwa odb1.
   p.drawText (getXSett (pZlec2[j]), getYSett (pZlec2[j]), codeEdit->text () + " " + placeEdit->text () + ", " + addressEdit->text ()); // nazwa odb1.
   p.drawText (getXSett (pTyt1[j]), getYSett (pTyt1[j]), lineEdit17->text ()); // nazwa odb1.
 }
/* 
// przelew2 
 p.drawText(-1030, 70, nameEdit2->text()); // nazwa odb1.
 p.drawText(-1030, 98, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-1030, 133, rozstrzel(accountEdit2->text())); 
 p.drawText(-830, 163, "PLN");
 p.drawText(-770, 163,  kwotaEdit->text());
 p.drawText(-1030, 192, rozstrzel(accountEdit->text())); // nazwa odb1.
 p.drawText(-1030, 222, nameEdit->text()); // nazwa odb1.
 p.drawText(-1030, 252, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-1030, 282, lineEdit17->text()); // nazwa odb1.
 
// przelew3
 p.drawText(-535, 423, nameEdit2->text()); // nazwa odb1.
 p.drawText(-535, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-535, 488, rozstrzel(accountEdit2->text())); 
 p.drawText(-335, 516, "PLN");
 p.drawText(-275, 516,  kwotaEdit->text());
 p.drawText(-535, 547, rozstrzel(accountEdit->text())); // nazwa odb1.
 p.drawText(-535, 575, nameEdit->text()); // nazwa odb1.
 p.drawText(-535, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-535, 635, lineEdit17->text()); // nazwa odb1.
 
 
 // przelew4
 p.drawText(-1030, 423, nameEdit2->text()); // nazwa odb1.
 p.drawText(-1030, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-1030, 488, rozstrzel(accountEdit2->text())); 
 p.drawText(-830, 516, "PLN");
 p.drawText(-770, 516,  kwotaEdit->text());
 p.drawText(-1030, 547, rozstrzel(accountEdit->text())); // nazwa odb1.
 p.drawText(-1030, 575, nameEdit->text()); // nazwa odb1.
 p.drawText(-1030, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-1030, 635, lineEdit17->text()); // nazwa odb1.
 */
    }

  if (comboBox1->currentItem () == 1)
    {
      makeWplata ();
      // przelew 1
      if (poziom)
 p.rotate (-90);
      int i, j;
      for (i = 1; i <= pages; ++i)
 {
   j = i - 1;

   p.drawText (getXSett (pOdb1[j]), getYSett (pOdb1[j]), nameEdit2->text ()); // nazwa odb1.
   p.drawText (getXSett (pOdb2[j]), getYSett (pOdb2[j]), codeEdit2->text () + " " + placeEdit2->text () + ", " + addressEdit2->text ()); // adres miasto odb1.
   p.drawText (getXSett (pNrrach[j]), getYSett (pNrrach[j]),
        rozstrzel (accountEdit2->text ()));
             p.drawText (getXSett (p_Wx[j]), getYSett (p_Wx[j]), "X");
   p.drawText (getXSett (pWal[j]), getYSett (pWal[j]), "PLN");
   p.drawText (getXSett (pKwota[j]), getYSett (pKwota[j]),
        kwotaEdit->text ());
   p.drawText (getXSett (pKsw[j]), getYSett (pKsw[j]), slownieLbl->text ()); // nazwa odb1.
   p.drawText (getXSett (pZlec1[j]), getYSett (pZlec1[j]), nameEdit->text ()); // nazwa odb1.
   p.drawText (getXSett (pZlec2[j]), getYSett (pZlec2[j]), codeEdit->text () + " " + placeEdit->text () + ", " + addressEdit->text ()); // nazwa odb1.
   p.drawText (getXSett (pTyt1[j]), getYSett (pTyt1[j]), lineEdit17->text ()); // nazwa odb1.
 }
/* 
 p.drawText(-535, 70, nameEdit2->text()); // nazwa odb1.
 p.drawText(-535, 98, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-535, 133, rozstrzel(accountEdit->text())); 
 p.drawText(-335, 163, "PLN");
 p.drawText(-275, 163,  kwotaEdit->text());
 p.drawText(-535, 192, slownieLbl->text()); // nazwa odb1.
 p.drawText(-535, 222, nameEdit->text()); // nazwa odb1.
 p.drawText(-535, 252, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-535, 282, lineEdit17->text()); // nazwa odb1.
 */
      /*
         // przelew2 
         p.drawText(-1030, 70, nameEdit2->text()); // nazwa odb1.
         p.drawText(-1030, 98, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
         p.drawText(-1030, 133, rozstrzel(accountEdit->text())); 
         p.drawText(-830, 163, "PLN");
         p.drawText(-770, 163,  kwotaEdit->text());
         p.drawText(-1030, 192, slownieLbl->text()); // nazwa odb1.
         p.drawText(-1030, 222, nameEdit->text()); // nazwa odb1.
         p.drawText(-1030, 252, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
         p.drawText(-1030, 282, lineEdit17->text()); // nazwa odb1.

         // przelew3
         p.drawText(-535, 423, nameEdit2->text()); // nazwa odb1.
         p.drawText(-535, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
         p.drawText(-535, 488, rozstrzel(accountEdit->text())); 
         p.drawText(-335, 516, "PLN");
         p.drawText(-275, 516,  kwotaEdit->text());
         p.drawText(-535, 547, slownieLbl->text()); // nazwa odb1.
         p.drawText(-535, 575, nameEdit->text()); // nazwa odb1.
         p.drawText(-535, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
         p.drawText(-535, 635, lineEdit17->text()); // nazwa odb1.


         // przelew4
         p.drawText(-1030, 423, nameEdit2->text()); // nazwa odb1.
         p.drawText(-1030, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
         p.drawText(-1030, 488, rozstrzel(accountEdit->text())); 
         p.drawText(-830, 516, "PLN");
         p.drawText(-770, 516,  kwotaEdit->text());
         p.drawText(-1030, 547, slownieLbl->text()); // nazwa odb1.
         p.drawText(-1030, 575, nameEdit->text()); // nazwa odb1.
         p.drawText(-1030, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
         p.drawText(-1030, 635, lineEdit17->text()); // nazwa odb1.
       */
    }

  p.translate (0, -body.height ());

  /* 
     QPixmap *px = new QPixmap();
     QPainter p2(px);
     p2.drawRect(100, 200, 30, 40);
     p2.drawText(100, 100, 200, 200, Qt::AlignHorizontal_Mask, "Hello world");
     p.drawPixmap(view, *px);
   */

  // view.moveBy(0, body.height());
  // p.translate(0 , -body.height());
  // printer.newPage();
  /*
     do {
     richText.draw(&p, body.left(), body.top(), view, colorGroup());
     view.moveBy(0, body.height());
     p.translate(0 , -body.height());
     p.setFont(font);
     p.drawText(view.right() - p.fontMetrics().width(QString::number(page)),
     view.bottom() + p.fontMetrics().ascent() + 5,
     QString::number(page));
     if (view.top()  >= richText.height())
     break;
     printer.newPage();
     page++;
     } while (TRUE);
   */
  //}
  p.end ();
  pix.save ("/tmp/przelew.png", "PNG");
  return pix;
}

void
Form6::print_dlg ()
{
  QPrinter printer;
  printer.setFullPage (TRUE);
  if (printer.setup (this))
    {
      QPainter p (&printer);
      if (!p.device ())
 return;
      QPaintDeviceMetrics metrics (p.device ());
      int dpix = metrics.logicalDpiX ();
      int dpiy = metrics.logicalDpiY ();
      const int margin = 0; // pt
      QRect body (margin * dpix / 72, margin * dpiy / 72,
    metrics.width () - margin * dpix / 72 * 2,
    metrics.height () - margin * dpiy / 72 * 2);
      /*
         QFont font(textEdit1->font());
         QSimpleRichText richText(textEdit1->text(), font, 
         textEdit1->context(),
         textEdit1->styleSheet(),
         textEdit1->mimeSourceFactory(),
         body.height());
         richText.setWidth(&p, body.width());
       */
      QRect view (body);
      p.drawPixmap (view, getPrzelew ());

      // int page = 1;
      /*
         QImage *img = new QImage("druki/standard.png");
         p.drawImage(view, *img); 
       */
/* 
 QFont serifFont( "Arial", 12, 75 );
 QFont sansFont( "Helvetica [Cronyx]", 12 ); 
 p.setFont(serifFont);

 if (comboBox1->currentItem() == 0) {
 // przelew 1
 p.rotate(-90);
 p.drawText(-535, 70, nameEdit2->text()); // nazwa odb1.
 p.drawText(-535, 98, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-535, 133, rozstrzel(accountEdit2->text())); 
 p.drawText(-335, 163, "PLN");
 p.drawText(-275, 163,  kwotaEdit->text());
 p.drawText(-535, 192, rozstrzel(accountEdit->text())); // nazwa odb1.
 p.drawText(-535, 222, nameEdit->text()); // nazwa odb1.
 p.drawText(-535, 252, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-535, 282, lineEdit17->text()); // nazwa odb1.
 
// przelew2 
 p.drawText(-1030, 70, nameEdit2->text()); // nazwa odb1.
 p.drawText(-1030, 98, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-1030, 133, rozstrzel(accountEdit2->text())); 
 p.drawText(-830, 163, "PLN");
 p.drawText(-770, 163,  kwotaEdit->text());
 p.drawText(-1030, 192, rozstrzel(accountEdit->text())); // nazwa odb1.
 p.drawText(-1030, 222, nameEdit->text()); // nazwa odb1.
 p.drawText(-1030, 252, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-1030, 282, lineEdit17->text()); // nazwa odb1.
 
// przelew3
 p.drawText(-535, 423, nameEdit2->text()); // nazwa odb1.
 p.drawText(-535, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-535, 488, rozstrzel(accountEdit2->text())); 
 p.drawText(-335, 516, "PLN");
 p.drawText(-275, 516,  kwotaEdit->text());
 p.drawText(-535, 547, rozstrzel(accountEdit->text())); // nazwa odb1.
 p.drawText(-535, 575, nameEdit->text()); // nazwa odb1.
 p.drawText(-535, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-535, 635, lineEdit17->text()); // nazwa odb1.
 
 
 // przelew4
 p.drawText(-1030, 423, nameEdit2->text()); // nazwa odb1.
 p.drawText(-1030, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-1030, 488, rozstrzel(accountEdit2->text())); 
 p.drawText(-830, 516, "PLN");
 p.drawText(-770, 516,  kwotaEdit->text());
 p.drawText(-1030, 547, rozstrzel(accountEdit->text())); // nazwa odb1.
 p.drawText(-1030, 575, nameEdit->text()); // nazwa odb1.
 p.drawText(-1030, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-1030, 635, lineEdit17->text()); // nazwa odb1.
}
 
  if (comboBox1->currentItem() == 1) {
      makeWplata();
      // przelew 1
 p.rotate(-90);
 p.drawText(-535, 70, nameEdit2->text()); // nazwa odb1.
 p.drawText(-535, 98, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-535, 133, rozstrzel(accountEdit->text())); 
 p.drawText(-335, 163, "PLN");
 p.drawText(-275, 163,  kwotaEdit->text());
 
 p.drawText(-535, 192, slownieLbl->text()); // nazwa odb1.
 p.drawText(-535, 222, nameEdit->text()); // nazwa odb1.
 p.drawText(-535, 252, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-535, 282, lineEdit17->text()); // nazwa odb1.
 
// przelew2 
 p.drawText(-1030, 70, nameEdit2->text()); // nazwa odb1.
 p.drawText(-1030, 98, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-1030, 133, rozstrzel(accountEdit->text())); 
 p.drawText(-830, 163, "PLN");
 p.drawText(-770, 163,  kwotaEdit->text());
 p.drawText(-1030, 192, slownieLbl->text()); // nazwa odb1.
 p.drawText(-1030, 222, nameEdit->text()); // nazwa odb1.
 p.drawText(-1030, 252, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-1030, 282, lineEdit17->text()); // nazwa odb1.
 
// przelew3
 p.drawText(-535, 423, nameEdit2->text()); // nazwa odb1.
 p.drawText(-535, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-535, 488, rozstrzel(accountEdit->text())); 
 p.drawText(-335, 516, "PLN");
 p.drawText(-275, 516,  kwotaEdit->text());
 p.drawText(-535, 547, slownieLbl->text()); // nazwa odb1.
 p.drawText(-535, 575, nameEdit->text()); // nazwa odb1.
 p.drawText(-535, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-535, 635, lineEdit17->text()); // nazwa odb1.
 
 
 // przelew4
 p.drawText(-1030, 423, nameEdit2->text()); // nazwa odb1.
 p.drawText(-1030, 451, codeEdit2->text()  + placeEdit2->text() + ", " + addressEdit2->text()); // adres miasto odb1.
 p.drawText(-1030, 488, rozstrzel(accountEdit->text())); 
 p.drawText(-830, 516, "PLN");
 p.drawText(-770, 516,  kwotaEdit->text());
 p.drawText(-1030, 547, slownieLbl->text()); // nazwa odb1.
 p.drawText(-1030, 575, nameEdit->text()); // nazwa odb1.
 p.drawText(-1030, 605, codeEdit->text()  + placeEdit->text() + ", " + addressEdit->text()); // nazwa odb1.
 p.drawText(-1030, 635, lineEdit17->text()); // nazwa odb1.
  }
  
 p.translate(0 , -body.height());
*/
      /* 
         QPixmap *px = new QPixmap();
         QPainter p2(px);
         p2.drawRect(100, 200, 30, 40);
         p2.drawText(100, 100, 200, 200, Qt::AlignHorizontal_Mask, "Hello world");
         p.drawPixmap(view, *px);
       */

      // view.moveBy(0, body.height());
      // p.translate(0 , -body.height());
      // printer.newPage();
      /*
         do {
         richText.draw(&p, body.left(), body.top(), view, colorGroup());
         view.moveBy(0, body.height());
         p.translate(0 , -body.height());
         p.setFont(font);
         p.drawText(view.right() - p.fontMetrics().width(QString::number(page)),
         view.bottom() + p.fontMetrics().ascent() + 5,
         QString::number(page));
         if (view.top()  >= richText.height())
         break;
         printer.newPage();
         page++;
         } while (TRUE);
       */

    }
  saveXML ();
  accept ();
}

void
Form6::ppriview ()
{
  qDebug ("%s %s:%d", __FUNCTION__, __FILE__, __LINE__);
  getPrzelew ();
  preview *ppp = new preview ();
  ppp->exec ();
// saveXML();
// close();
}


void
Form6::newFunction ()
{

}
