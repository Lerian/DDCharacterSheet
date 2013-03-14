#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class LineEdit: public QLineEdit
{
	Q_OBJECT

private:
	QString nom;

public:
	LineEdit(QWidget * parent = 0);
	LineEdit(const QString & nom, QWidget * parent = 0);
	LineEdit(const QString & nom, const QString & contents, QWidget * parent = 0);

signals:
	void infosToDisplay(QString champ);
	void finAffichageInfos();

protected:
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);
};
#endif	// LINEEDIT_H
