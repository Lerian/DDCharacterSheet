#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

#define TEXTE 0
#define NOMBRE 1

class LineEdit: public QLineEdit
{
	Q_OBJECT

private:
	QString nom;

public:
	LineEdit(int mode = NOMBRE, QWidget * parent = 0);
	LineEdit(const QString & nom, int mode = NOMBRE, QWidget * parent = 0);
	LineEdit(const QString & nom, const QString & contents, int mode = NOMBRE, QWidget * parent = 0);

signals:
	void infosToDisplay(QString champ);
	void finAffichageInfos();

protected:
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);
};
#endif	// LINEEDIT_H
