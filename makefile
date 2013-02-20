CXX=g++
CXXFLAGS=-Wall -Wextra -g -O2
LDFLAGS=-lQtGui -lQtCore
INCLUDES=-I/usr/include/qt4 -I/usr/include/qt4/QtGui
EXEC=CharacterSheet

all: main.o mainWindow.o competences.o caracs.o dons.o equipement.o rolePlay.o sac.o moc_caracs.o moc_mainWindow.o moc_sac.o
	$(CXX) $^ $(LDFLAGS) -o $(EXEC)

mainWindow.o: mainWindow.h
	moc -o moc_mainWindow.cpp $<
	$(CXX) -c mainWindow.cpp $(CXXFLAGS) $(INCLUDES)
sac.o: sac.h
	moc -o moc_sac.cpp $<
	$(CXX) -c sac.cpp $(CXXFLAGS) $(INCLUDES)
caracs.o: caracs.h
	moc -o moc_caracs.cpp $<
	$(CXX) -c caracs.cpp $(CXXFLAGS) $(INCLUDES)
	
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) $(INCLUDES)
moc_caracs.o: moc_caracs.cpp
	$(CXX) -c $< $(CXXFLAGS) $(INCLUDES)
moc_mainWindow.o: moc_mainWindow.cpp
	$(CXX) -c $< $(CXXFLAGS) $(INCLUDES)
moc_sac.o: moc_sac.cpp
	$(CXX) -c $< $(CXXFLAGS) $(INCLUDES)

clean:
	rm -rf *.o *~ moc_*.cpp
completeClean: clean
	rm -rf $(EXEC)
	
