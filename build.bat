cd src/lib/
del *.dll *.exe
g++ -shared -o eigen.dll eigen.cpp rayleigh_quotient.cpp utils.cpp von_mises.cpp logger.cpp
cd ../../
