 all: CImg.h svm.cpp  svm.h 
	g++ svm.cpp -o svm -lX11 -ljpeg -lpthread -I. -I/usr/local/include -L/usr/local/lib -I/usr/X11/include -L/usr/X11/lib -lX11 -Isiftpp -O3 siftpp/sift.cpp


clean:
	rm svm
