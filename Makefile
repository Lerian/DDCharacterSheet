INCLUDES=-I/usr/include/qt4 -I/usr/include/qt4/QtGui
WAR_OPT=-Wall -Wextra -g -O2

all: moc
	g++ -c $(WAR_OPT) $(INCLUDES) main.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) mainWindow.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) competences.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) caracs.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) dons.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) equipement.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) rolePlay.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) sac.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) moc_caracs.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) moc_mainWindow.cpp
	g++ -c $(WAR_OPT) $(INCLUDES) moc_sac.cpp
	g++ -o CharacterSheet main.o mainWindow.o competences.o caracs.o dons.o equipement.o rolePlay.o sac.o moc_caracs.o moc_mainWindow.o moc_sac.o -lQtGui -lQtCore
	rm -rf *.o moc_*.cpp

moc:
	moc -o moc_caracs.cpp caracs.h
	moc -o moc_mainWindow.cpp mainWindow.h
	moc -o moc_sac.cpp sac.h

clean:
	rm -rf *.o CharacterSheet moc_*.cpp
