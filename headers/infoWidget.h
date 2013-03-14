#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QtGui>
#include <vector>

class InfoWidget : public QWidget
{
	Q_OBJECT

private:
	QGridLayout * layoutInfos;
	QVBoxLayout * layout;
	
	std::vector<QLabel *> labels;

public:
	InfoWidget(QWidget * parent = 0);

private slots:
	void afficheInfos(std::vector<QString> champs, std::vector<int> vals);
	void finAffichageInfos();
};
#endif	// INFOWIDGET_H
