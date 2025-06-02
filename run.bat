del %1.o
del %1.exe
g++ -o %1 %1.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
%1.exe