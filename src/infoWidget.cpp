#include "infoWidget.h"

InfoWidget::InfoWidget(QWidget * parent)
: QWidget(parent)
{
	layoutInfos = new QGridLayout();
	layout = new QVBoxLayout(this);
	
	layout->addStretch();
	layout->addLayout(layoutInfos);
	layout->addStretch();
}

void InfoWidget::afficheInfos(std::vector<QString> champs, std::vector<int> vals)
{
	for(unsigned int i=0, j=0; i < champs.size();i++,j+=2)
	{
		QLabel* champ = new QLabel(champs[i]);
		champ->setAlignment(Qt::AlignCenter);
		layoutInfos->addWidget(champ,j,0);
		
		labels.push_back(champ);
	}
	
	for(unsigned int i=0, j=0; i < vals.size();i++,j+=2)
	{
		QLabel* val = new QLabel(QString::number(vals[i]));
		val->setAlignment(Qt::AlignCenter);
		layoutInfos->addWidget(val,j,1);
		
		labels.push_back(val);
	}
	
	QLabel* egal = new QLabel("=");
	egal->setAlignment(Qt::AlignCenter);
	layoutInfos->addWidget(egal,1,1);
	
	labels.push_back(egal);
	
	for(unsigned int i=2, j=3; i < vals.size(); i++, j+=2)
	{
		QLabel* plus = new QLabel("+");
		plus->setAlignment(Qt::AlignCenter);
		layoutInfos->addWidget(plus,j,1);
		
		labels.push_back(plus);
	}
}

void InfoWidget::finAffichageInfos()
{
	while(labels.size() > 0)
	{
		layoutInfos->removeWidget(labels[labels.size()-1]);
		
		labels[labels.size()-1]->deleteLater();
		
		labels.pop_back();
	}
}
