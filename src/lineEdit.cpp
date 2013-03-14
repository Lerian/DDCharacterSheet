#include "lineEdit.h"

LineEdit::LineEdit(QWidget * parent)
: QLineEdit(parent)
{}

LineEdit::LineEdit(const QString & nom, QWidget * parent)
: QLineEdit(parent)
{
	this->nom = nom;
}

LineEdit::LineEdit(const QString & nom, const QString & contents, QWidget * parent)
: QLineEdit(contents, parent)
{
	this->nom = nom;
}

void LineEdit::enterEvent(QEvent * event)
{
	emit infosToDisplay(nom);
}

void LineEdit::leaveEvent(QEvent * event)
{
	emit finAffichageInfos();
}
