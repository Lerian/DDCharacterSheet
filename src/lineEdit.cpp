#include "lineEdit.h"

LineEdit::LineEdit(int mode, QWidget * parent)
: QLineEdit(parent)
{
	switch(mode)
	{
		case NOMBRE:
			setText("0");
			break;
		case TEXTE:
			setText("");
			break;
		default:
			break;
	}
}

LineEdit::LineEdit(const QString & nom, int mode, QWidget * parent)
: QLineEdit(parent)
{
	switch(mode)
	{
		case NOMBRE:
			setText("0");
			break;
		case TEXTE:
			setText("");
			break;
		default:
			break;
	}

	this->nom = nom;
}

LineEdit::LineEdit(const QString & nom, const QString & contents, int mode, QWidget * parent)
: QLineEdit(contents, parent)
{
	this->nom = nom;
	this->setText(contents);
}

void LineEdit::enterEvent(QEvent * event)
{
	emit infosToDisplay(nom);
}

void LineEdit::leaveEvent(QEvent * event)
{
	emit finAffichageInfos();
}
